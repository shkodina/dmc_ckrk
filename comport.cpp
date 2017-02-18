//---------------------------------------------------------------------------

#pragma hdrstop

#include <vcl.h>
#include "comport.h"
//---------------------------------------------------------------------------
MyCom::MyCom (LPCTSTR name, unsigned int boudrate){
	this->name_ = name;
	this->boudrate_ = boudrate;
	};

bool MyCom::init(){
	LPCTSTR sPortName = name_;

	hSerial = ::CreateFile(sPortName,GENERIC_READ | GENERIC_WRITE,
	0,
	0,
	OPEN_EXISTING,
	FILE_ATTRIBUTE_NORMAL,
	0);

	if(hSerial==INVALID_HANDLE_VALUE)
	{
		if(GetLastError()==ERROR_FILE_NOT_FOUND)
		{
			ShowMessage("serial port does not exist");
			return -1;
		}
		ShowMessage("some other error occurred");
		return -1;
	}


	DCB dcbSerialParams = {0};
	dcbSerialParams.DCBlength=sizeof(dcbSerialParams);
	if (!GetCommState(hSerial, &dcbSerialParams))
	{
		ShowMessage("getting state error");
		return -1;

	}
	dcbSerialParams.BaudRate=this->boudrate_;
	dcbSerialParams.ByteSize=8;
	dcbSerialParams.StopBits=ONESTOPBIT;
	dcbSerialParams.Parity=NOPARITY;
	if(!SetCommState(hSerial, &dcbSerialParams))
	{
		ShowMessage("error setting serial port state");
		return -1;
	}

	/*
	char data[] = "Hello from Visual Part C++";
	DWORD dwSize = sizeof(data);
	DWORD dwBytesWritten;
	LPOVERLAPPED ov;
	BOOL iRet = WriteFile (hSerial,data,dwSize,&dwBytesWritten ,NULL);
	*/

}

DWORD MyCom::getdata(char * buf, unsigned int waitcount){
	DWORD iSize;
	ReadFile(hSerial, buf, waitcount, &iSize, 0);
	return iSize;
}
#pragma package(smart_init)
