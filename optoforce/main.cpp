#include "optoforce.h"
#include <Windows.h>
#include <iostream>

int main()
{
	optoforce leftForce(0x27);
	//optoforce rightForce(0x37);
	
	leftForce.zero();
	leftForce.setFilter(0x06);
	//rightForce.zero();
	
	for (int i=0;i<200000;i++)
	{
		leftForce.getForce();
		//rightForce.getForce();

		std::cout<<"Fx:"<<leftForce.Fx<<"  Fy:"<<leftForce.Fy<<"  Fz:"<<leftForce.Fz<<"  Tx:"<<leftForce.Tx<<"  Ty:"<<leftForce.Ty<<"  Tz:"<<leftForce.Tz<<std::endl;
		//std::cout<<"Fx:"<<rightForce.Fx<<"  Fy:"<<rightForce.Fy<<"  Fz:"<<rightForce.Fz<<"  Tx:"<<rightForce.Tx<<"  Ty:"<<rightForce.Ty<<"  Tz:"<<rightForce.Tz<<std::endl;
		std::cout<<std::endl;
		Sleep(100);
	}

	return 0;
}