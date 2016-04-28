#include <iostream>
#include <windows.h>
#include "C:\Twincat\AdsApi\TcAdsDll\Include\TcAdsDef.h"
#include "C:\Twincat\AdsApi\TcAdsDll\Include\TcAdsApi.h"

class optoforce
{
public:
    optoforce(unsigned long );
	void zero();
	void getForce();
	void setFilter(DWORD);
	unsigned long getError();
	short Fx,Fy,Fz,Tx,Ty,Tz;
	

private:
    AmsAddr* pAddr;
    unsigned long Rxadd0;
    unsigned long Txadd0;
    unsigned short port;
    unsigned long add1,add2,offset;
    DWORD dwData;
	WORD Data;
	
	
    

};