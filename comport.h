//---------------------------------------------------------------------------

#ifndef comportH
#define comportH

#include <Windows.h>

class MyCom{
public:
    MyCom (LPCTSTR name, unsigned int boudrate);

	bool init();
	DWORD getdata(char * buf, unsigned int waitcount);

private:
	unsigned int boudrate_;
	LPCTSTR name_;
	HANDLE hSerial;
};
//---------------------------------------------------------------------------
#endif
