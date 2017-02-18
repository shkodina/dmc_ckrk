//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "comport.h"
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>

#include <cstring>
#include <fstream>
#include <vector>

//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TButton *Button1;
	TMemo *Memo1;
	TButton *Button2;
	TLabel *Label1;
	TChart *Chart1;
	TLineSeries *Series1;
	TButton *Button3;
	TTimer *Timer1;
	TButton *Button4;
	TButton *Button5;
	TCheckBox *CheckBox1;
	TButton *Button6;
	TPanel *Panel1;
	TLabel *Label2;
	TButton *Button7;
	TComboBox *ComboBox1;
	TPanel *Panel2;
	TPanel *Panel3;
	TEdit *Edit1;
	TLabel *Label3;
	TLineSeries *Series2;
	TEdit *Edit2;
	TLabel *Label4;
	TOpenTextFileDialog *OpenTextFileDialog1;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TPanel *Panel4;
	TPanel *Panel5;
	TPanel *Panel6;
	TProgressBar *ProgressBar1;
	TLabel *Label5;
	TEdit *Edit3;
	TLabel *Label6;
	TLabel *Label7;
	TEdit *Edit4;
	TCheckBox *CheckBox2;
	TLabel *Label8;
	TEdit *Edit5;
	TButton *Button11;
	TLineSeries *Series3;
	TEdit *Edit6;
	TLabel *Label9;
	TLabel *Label10;
	TEdit *Edit7;
	TButton *Button12;
	TLabel *Label11;
	TLabel *Label12;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Edit2Change(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
private:	// User declarations
	class MyCBuf {

	public:
		char init (DWORD size){
		   len = size;
		   data = new char[len];
		   pos = 0;
		   pos_for_get = 0;
		}

		char add (char * buf_from, DWORD count){

			if (count < len - pos) {
				memcpy (data + pos, buf_from, count);
				pos += count;
				pos_for_get = pos;
			}else{
				DWORD dif = len - pos;
				memcpy (data + pos, buf_from, dif);
				pos = 0;
				memcpy (data + pos, buf_from + dif, count - dif);
				pos = count - dif;
				pos_for_get = pos;
			}

		}

		char get_left (char * buf_to, DWORD count){
			if (count < pos_for_get) {
				memcpy (buf_to, data + pos_for_get - count, count);
				pos_for_get = pos_for_get - count;
			}else{
				DWORD dif = pos_for_get;
				memcpy (buf_to + count - dif, data, dif);
				pos_for_get = len - count + dif;
				memcpy (buf_to, data + pos_for_get, count - dif);
			}
		}

		char get_right (char * buf_to, DWORD count){
			if (count < len - pos_for_get) {
				memcpy (buf_to, data + pos_for_get, count);
				pos_for_get = pos_for_get + count;
			}else{
				DWORD dif = len - pos_for_get;
				memcpy (buf_to, data + pos_for_get, dif);
				pos_for_get = 0;
				memcpy (buf_to + dif, data + pos_for_get, count - dif);
				pos_for_get = count - dif;
			}
		}

		~MyCBuf(){
			delete (data);
		}

	private:

		char * data;
		DWORD pos;
		DWORD len;
		DWORD pos_for_get;

    };
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
	MyCom *comport;
	const DWORD BUFSIZE;
	char * buf;

	MyCBuf * mycbuf;

	DWORD getDataToShow (char * buf, DWORD len);
	void showBufOnForm(DWORD readed);

	void printTics();

	ofstream fout;
	ifstream fromfile;

	std::vector<unsigned char> buffer;
	DWORD buffer_cur_pos;
	void TForm3::deleteFFFF();
	DWORD ShowBlockFromFile(int shift);

	unsigned char * write_buffer;
	DWORD write_buffer_pos;
	DWORD write_buffer_iterations;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
