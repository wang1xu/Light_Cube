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
void delay500ms(void);   //误差 0us
void start_init(void);
void init(void);
void liecon(u8 lie);
void cengcon(u8 cen);
void zuobiao(u8 x,u8 y);
void dian(u8 x,u8 y,u8 cen);
void donghua1(void);//斜杠闪
void donghua2(void);//层闪
void donghua3(void);//全亮
void donghua4(void);//方框
void donghua4_shanshuo(void);//方框闪烁
void donghua5(void);//流星坠
void donghua6(void);//正方形绕行（不消隐）
void donghua6_xiaoyin(void);//正方形绕行（消隐）

#endif