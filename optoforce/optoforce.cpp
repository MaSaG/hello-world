#include "optoforce.h"

optoforce::optoforce(unsigned long a)
{
    pAddr = new AmsAddr;
    Rxadd0 = 0x11002;//need to check the adderess in TwinCAT
    Txadd0 = 0x12002;//need to check the adderess in TwinCAT
    port = 300;
	dwData=0;
	Data=0;
	add2=0x02;  //©T©wªº
	offset=a;   

	int nErr = 0;
    AdsPortOpen();
    nErr = AdsGetLocalAddress(pAddr);
	if(nErr)
	{
		std::cerr << "Error: AdsGetLocalAddress: " << nErr << std::endl;
	}
    pAddr->port = port;

    
}


void optoforce::zero()   
{
	add1=offset;
	dwData = 0x0000;  //unzero
    AdsSyncWriteReq(pAddr,Rxadd0,add1,add2,&dwData);
	Sleep(10);
    dwData = 0xFF00;  //zero
    AdsSyncWriteReq(pAddr,Rxadd0,add1,add2,&dwData);

}

void optoforce::setFilter(DWORD filter)
{
	//000 = No filter 
	//001 = 500 Hz 
	//010 = 150 Hz 
	//011 = 50 Hz 
	//100 = 15 Hz 
	//101 = 5 Hz 
	//110 = 1.5 Hz
	add1=offset;
    dwData = 0xFF00 | filter;  //zero
    AdsSyncWriteReq(pAddr,Rxadd0,add1,add2,&dwData);

}

unsigned long optoforce::getError()
{
	add1= offset+0x0C;
	Data=0x0;
	AdsSyncReadReq(pAddr,Txadd0,add1,add2,&Data);
	return Data;	
}

void optoforce::getForce()
{
	add1= offset;
	AdsSyncReadReq(pAddr,Txadd0,add1,add2,&dwData);
	Fx=dwData;

	add1=offset+0x02; 
	AdsSyncReadReq(pAddr,Txadd0,add1,add2,&dwData);
	Fy=dwData;

	add1= offset+0x04; 
	AdsSyncReadReq(pAddr,Txadd0,add1,add2,&dwData);
	Fz=dwData;

	add1= offset+0x06; 
	AdsSyncReadReq(pAddr,Txadd0,add1,add2,&dwData);
	Tx=dwData;

	add1= offset+0x08; 
	AdsSyncReadReq(pAddr,Txadd0,add1,add2,&dwData);
	Ty=dwData;

	add1= offset+0x0A; 
	AdsSyncReadReq(pAddr,Txadd0,add1,add2,&dwData);
	Tz=dwData;

}


