//---------------------------------------------------------------------------

#include <vcl.h>

#include <windows.h>

#pragma hdrstop

#include "Unit3.h"

#include <sstream>


#define SSTR( x ) static_cast< std::ostringstream & >( \
		( std::ostringstream() << std::dec << x ) ).str()
		
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner), BUFSIZE(2048)
{
	this->buf = new char [this->BUFSIZE];

	this->mycbuf = new MyCBuf();
	this->mycbuf->init(BUFSIZE * Edit5->Text.ToInt());



}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender)
{
	Form3->Memo1->Clear();
}
//---------------------------------------------------------------------------
DWORD TForm3::getDataToShow(char * buf, DWORD len){

	if(this->comport == 0)
		return 0;

	DWORD readed = this->comport->getdata(buf, len);

	if (!readed) return readed;

	this->mycbuf->add(buf, len);

	if (this->CheckBox1->Checked){
		if (write_buffer_iterations != Edit3->Text.ToInt()) {
          	memcpy(write_buffer + write_buffer_pos, buf, len);
			write_buffer_pos += len;
			write_buffer_iterations++;
		}
	}


	return  readed;
}
//---------------------------------------------------------------------------
void TForm3::printTics(){
	this->Series2->Clear();
    this->Series2->RefreshSeries();

	int start = this->Edit1->Text.ToInt();
	int len = this->Edit2->Text.ToInt();

	double max_x = Series1->MaxXValue();
	double max_y = Series1->MaxYValue();

	if (max_x == 0.0){
		max_x = start + len * 1000;
	}
	if (max_y == 0.0){
		max_y = 1;
	}

	for (int x = start; x < max_x; x += len ){
		this->Series2->AddXY(x,0);
		this->Series2->AddXY(x,max_y);
		x += len;
		this->Series2->AddXY(x,max_y);
		this->Series2->AddXY(x,0);

	}
}
//---------------------------------------------------------------------------
void TForm3::showBufOnForm(DWORD readed){

	this->Label1->Caption = SSTR(readed).c_str();

	Memo1->Clear();
	UnicodeString Str;
	int pos = -255;
	for (int i = 0; i < readed;) {
		Str += IntToStr((unsigned char)this->buf[i++]);
		Str += ":";
		Str += IntToStr((unsigned char)this->buf[i++]);
		Str += "\t";

		pos += (unsigned char)this->buf[i-1];
		if (i % 16 == 0) {
			Str += IntToStr(pos);
			Memo1->Lines->Add(Str);
			Str = "";
		}
	}
	//Memo1->Text = Str;


	this->Series1->Clear();
	this->Series1->RefreshSeries();

	DWORD x = 0;
	this->Series1->AddXY(x++,0);

	for (int i = 2; i < readed; i += 2) {
		this->Series1->AddXY(x,(unsigned char)this->buf[i]);
		x += (unsigned char)this->buf[i+1];
		this->Series1->AddXY(x,(unsigned char)this->buf[i]);
	}

	this->Series1->RefreshSeries();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
	DWORD readed = getDataToShow(this->buf, this->BUFSIZE);

	if (!readed) return;
	
	showBufOnForm(readed);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormClose(TObject *Sender, TCloseAction &Action)
{
	delete(this->buf);
	delete(this->comport);

	if( fout.is_open())
		fout.close();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button3Click(TObject *Sender)
{
	if (this->Timer1->Enabled) { // time to STOP
		this->Timer1->Enabled = false;
		this->Button3->Caption = "Start";

		if (this->CheckBox1->Checked){
			fout.write(write_buffer, write_buffer_pos);
            fout.close();
			delete write_buffer;

//			Label6->Caption = "iterations: " + IntToStr((int)write_buffer_iterations);
			Label6->Caption = "buffered: " + IntToStr((int)write_buffer_pos);
		}

		this->CheckBox1->Enabled = true;
	}else{ // Lets START
		this->CheckBox1->Enabled = false;

		if (this->CheckBox1->Checked){
			String filename = Edit4->Text.c_str();
			filename += ".txt";
			if (this->CheckBox2->Checked) {
				fout.open(filename.c_str(), std::ofstream::binary | std::ofstream::out);
			}else{
				fout.open(filename.c_str(), std::ofstream::binary | std::fstream::app);
			}

			write_buffer = new unsigned char [BUFSIZE * Edit3->Text.ToInt()];
			write_buffer_pos = 0;
			write_buffer_iterations = 0;
		}

		this->Timer1->Enabled = true;
		this->Button3->Caption = "Stop";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button4Click(TObject *Sender)
{
	this->mycbuf->get_left(this->buf, this->BUFSIZE);
	showBufOnForm(this->BUFSIZE);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button5Click(TObject *Sender)
{
	this->mycbuf->get_right(this->buf, this->BUFSIZE);
	showBufOnForm(this->BUFSIZE);
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Button6Click(TObject *Sender)
{
	this->comport = new MyCom(this->ComboBox1->Text.w_str(), 115200);
//	this->comport = new MyCom(L"COM5", 115200);
	this->comport->init();
}
//---------------------------------------------------------------------------

#include <Registry.hpp>

void __fastcall TForm3::Button7Click(TObject *Sender)
{
/*
	Form3->ComboBox1->Items->Add("COM1");
	Form3->ComboBox1->Items->Add("COM2");
	Form3->ComboBox1->Items->Add("COM3");
  */

  TRegistry *regKey = new TRegistry;
	regKey->RootKey = HKEY_LOCAL_MACHINE;
	if(!regKey->OpenKey("Hardware\\DeviceMap\\SerialComm", true)){
		ShowMessage("Open Register Error");
	};



	TStringList * strings = new TStringList();

	regKey->GetValueNames(strings);

	for(int i = 0; i <  strings->Count; i++){
		Form3->ComboBox1->Items->Add(regKey->ReadString((*strings)[i]));
	}
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------

void __fastcall TForm3::Edit2Change(TObject *Sender)
{
     this->printTics();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Edit1Change(TObject *Sender)
{
	this->printTics();
}
//---------------------------------------------------------------------------

void TForm3::deleteFFFF(){
	std::vector<unsigned char>::iterator mbufit = buffer.begin() ;
	while (mbufit < (buffer.end())){
		//this->Memo1->Lines->Add("" + IntToStr(*mbufit) + ":" + IntToStr(*(mbufit + 1)));


		if( (*mbufit == *(mbufit + 1)) && (*mbufit == 0xFF)){
			mbufit += 2;
			buffer.erase(mbufit - 2, mbufit);

			this->Memo1->Lines->Add("found FF group");
		} else {
			mbufit += 2;
		}
	}

}

void __fastcall TForm3::Button8Click(TObject *Sender)
{
	OpenTextFileDialog1->Filter = "Text files (*.txt)|*.TXT|XML files (*.xml)|*.XML|Any file (*.*)|*.*";
	if (OpenTextFileDialog1->Execute(this->Handle)) {
        // selecting the filename and encoding selected by the user
		String filename = OpenTextFileDialog1->FileName;

		// checking if the file exists
		if (FileExists(filename))
        {
			// display the contents in a memo based on the selected encoding
			Memo1->Lines->Add("chosen file: " + filename);

			fromfile.open(filename.w_str(), std::ifstream::in | std::ifstream::binary);

			fromfile.seekg(0, std::ios::end);
			std::streampos length(fromfile.tellg());
			if (length){
				fromfile.seekg(0, std::ios::beg);
				buffer.resize(static_cast<std::size_t>(length));
				fromfile.read(&buffer.front(), static_cast<std::size_t>(length));
			}

			Memo1->Lines->Add("bufreaded: " + IntToStr((int)buffer.size()));

			deleteFFFF();

			Memo1->Lines->Add("bufreaded after clear: " + IntToStr((int)buffer.size()));

            ShowBlockFromFile(0);

			this->Button9->Enabled = true;
			this->Button10->Enabled = true;

		} else {
            MessageDlg("File does not exist", mtError,
                TMsgDlgButtons() << mbOK, 0);
		}
	}
}
//---------------------------------------------------------------------------

 DWORD TForm3::ShowBlockFromFile(int shift){

	//Memo1->Clear();

	Memo1->Lines->Add("");

	UnicodeString Str;

	this->buffer.size();

	for (int i = 0; i < this->buffer.size();) {
		Str += IntToStr((unsigned char)this->buffer[i++]);
		Str += ":";
		Str += IntToStr((unsigned char)this->buffer[i++]);
		Str += "\t";

		if (i % 16 == 0) {
			Memo1->Lines->Add(Str);
			Str = "";
		}
	}
	return 0;
 }

void __fastcall TForm3::Button11Click(TObject *Sender)
{
	delete (this->mycbuf);
	this->mycbuf = new MyCBuf();
	this->mycbuf->init(BUFSIZE * Edit5->Text.ToInt());
}
//---------------------------------------------------------------------------

