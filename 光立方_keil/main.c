#include "reg52.h"
#include "dian.h"
#include "intrins.h"
u8 ceng[]={0x01,0x02,0x04,0x08};//0,1,2,3²ã
u8 shu[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};

void main()
{
	//u8 j;
	//j=0;
	start_init();
	while(1)
	{
		 donghua6_xiaoyin();
		 donghua5();
		 donghua6();
		 donghua3();
	}
}