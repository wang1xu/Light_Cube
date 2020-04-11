#include "dian.h"

void delay(u16 i)
{
	while(i--);
}

void delay500ms(void)   //误差 0us
{
    unsigned char a,b,c;
    for(c=23;c>0;c--)
        for(b=152;b>0;b--)
            for(a=70;a>0;a--);
}

void start_init(void)
{
	P1=0xf0;
	P0=0;
	Shu34=1;
	Shu12=1;
	Shu34=0;
	Shu12=0;
}

void init()
{
	P1=0;
}
	
void liecon(u8 lie)
{
	if(lie<=7)
	{
		P0=shu[lie];
		Shu12=1;
	}
	else
	{
		lie=lie-8;
		P0=shu[lie];
		Shu34=1;
	}
	Shu12=0;
	Shu34=0;
}

void cengcon(u8 cen)
{
	P1=ceng[cen];
	delay(10);
}

void zuobiao(u8 x,u8 y)
{
	u8 con;
	con=4*x+y;
	liecon(con);
}

void dian(u8 x,u8 y,u8 cen)//竖，层
{
	cengcon(cen);
	zuobiao(x,y);
		
}
void donghua1(void)
{
	u8 i,j;
	u8 k=0;
	for(i=0;i<=3;i++)
	{
		while(1)
		{
			for(j=0;j<=3;j++)
			{
				dian(j,j,i);
				delay(2000);
				init();
			}
			k++;
			if(k<=500)
			{
				k=0;
				break;
			}
		}
		delay(50000);
	}
}
void donghua2(void)
{
	u8 j;
	j=0;
	while(1)
	{
		cengcon(j);
		P0=0xff;
		Shu12=1;
		Shu34=1;
		Shu12=0;
		Shu34=0;
		delay500ms();
		delay500ms();
		start_init();
		j++;
		if(j>=4)
		{
			j=0;
			break;
		}
  }
}
void donghua3(void)
{
	  u8 j;
	  u16 i;
	  for(i=0;i<=3000;i++)
	  {
			cengcon(j);
			P0=0xff;
			Shu12=1;
			Shu34=1;
			Shu12=0;
			Shu34=0;
			delay(100);
			j++;
			if(j>=4)
				j=0;
			start_init();
	  }
}
void donghua4(void)
{
	u8 zhuan1[]={0x9f,0x09,0x09,0x9f};
	u8 zhuan2[]={0xf9,0x90,0x90,0xf9};
	u8 i;
	for(i=0;i<=3;i++)
	{
		P0=zhuan1[i];
		Shu12=1;
		Shu12=0;
		cengcon(i);
		delay(200);
		start_init();
		P0=zhuan2[i];
		Shu34=1;
		Shu34=0;
		cengcon(i);
		delay(200);
		start_init();
	}
}
void donghua4_shanshuo(void)
{
	u8 j;
	j=0;
	while(1)
		{
			if(j>=30)
			{
				j=0;
				break;
			}
			donghua4();
			j++;
		}
		delay500ms();
	
}
void donghua5(void)
{
	u8 zhuan[]={0x01,0x07,0x11,0x04,0x81,0x42,0x03,0x44,0x88};
	u8 i,j;
	for(j=0;j<=8;j++)
	{
		for(i=0;i<=3;i++)
		{
			P0=zhuan[j];
			Shu12=1;
			Shu12=0;
			cengcon(3-i);
			delay(15000);
			start_init();
		}
		for(i=0;i<=3;i++)
		{
			P0=zhuan[8-j];
			Shu34=1;
			Shu34=0;
			cengcon(3-i);
			delay(15000);
			start_init();
		}
  }
	donghua2();
	start_init();
}
void donghua6(void)
{
	u8 zhuan[]={0,1,2,3,7,11,15,14,13,12,8,4,5,6,9,10};
	u8 i,j,k;
	for(k=0;k<=2;k++)
	{
		for(j=0;j<=3;j++)
		{
			for(i=0;i<=15;i++)
			{
				if(j%2==0)
					liecon(zhuan[i]);
				else
					liecon(zhuan[15-i]);
				cengcon(j);
				delay(5000);
				//start_init();//不消隐，视觉效果更好
			}
		}
	}
}
void donghua6_xiaoyin(void)
{
	u8 zhuan[]={0,1,2,3,7,11,15,14,13,12,8,4,5,6,9,10};
	u8 i,j,k;
	for(k=0;k<=2;k++)
	{
		for(j=0;j<=3;j++)
		{
			for(i=0;i<=15;i++)
			{
				if(j%2==0)
					liecon(zhuan[i]);
				else
					liecon(zhuan[15-i]);
				cengcon(j);
				delay(5000);
				start_init();//不消隐，视觉效果更好
			}
		}
	}
}