#ifndef _DIAN_
#define _DIAN_

#include"reg52.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit Shu12=P2^7;
sbit Shu34=P2^6;

extern u8 ceng[];
extern u8 shu[];

void delay(u16 i);
void delay500ms(void);   //��� 0us
void start_init(void);
void init(void);
void liecon(u8 lie);
void cengcon(u8 cen);
void zuobiao(u8 x,u8 y);
void dian(u8 x,u8 y,u8 cen);
void donghua1(void);//б����
void donghua2(void);//����
void donghua3(void);//ȫ��
void donghua4(void);//����
void donghua4_shanshuo(void);//������˸
void donghua5(void);//����׹
void donghua6(void);//���������У���������
void donghua6_xiaoyin(void);//���������У�������

#endif