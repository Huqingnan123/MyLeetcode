#include <stdio.h>
struct ISR_BITS
{
	unsigned int bit0 : 1;
	unsigned int bit1 : 1;
	unsigned int bit2 : 1;
	unsigned int bit3 : 1;
	unsigned int bit4 : 1;
	unsigned int bit5 : 1;
	unsigned int bit6 : 1;
	unsigned int bit7 : 1;
	unsigned int rsv : 8;
};
union ISR_RSG
{
	unsigned short all;        //对isg_rsg赋值相当于对联合中的第一个成员unsigned short all赋值
	struct ISR_BITS bit;
}isr_rsg;
void f0(void);
void f1(void);
void f2(void);
void f3(void);
void f4(void);
void f5(void);
void f6(void);
void f7(void);
void f0(void)
{
	printf("The Interrupt Service Routine isr0 is called!\n");
}
void f1(void)
{
	printf("The Interrupt Service Routine isr1 is called!\n");
}
void f2(void)
{
	printf("The Interrupt Service Routine isr2 is called!\n");
}
void f3(void)
{
	printf("The Interrupt Service Routine isr3 is called!\n");
}
void f4(void)
{
	printf("The Interrupt Service Routine isr4 is called!\n");
}
void f5(void)
{
	printf("The Interrupt Service Routine isr5 is called!\n");
}
void f6(void)
{
	printf("The Interrupt Service Routine isr6 is called!\n");
}
void f7(void)
{
	printf("The Interrupt Service Routine isr7 is called!\n");
}
int main(void)
{
	int N,i;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%hu", &isr_rsg.all);
		void (*p_fun[8])();
		p_fun[0] = f0;
		p_fun[1] = f1;
		p_fun[2] = f2;
		p_fun[3] = f3;
		p_fun[4] = f4;
		p_fun[5] = f5;
		p_fun[6] = f6;
		p_fun[7] = f7;
		printf("%d:\n", isr_rsg.all);
		if (isr_rsg.bit.bit0)
			p_fun[0]();   //number.biti是unsigned int型
		if (isr_rsg.bit.bit1)
			p_fun[1]();
		if (isr_rsg.bit.bit2)
			p_fun[2]();
		if (isr_rsg.bit.bit3)
			p_fun[3]();
		if (isr_rsg.bit.bit4)
			p_fun[4]();
		if (isr_rsg.bit.bit5)
			p_fun[5]();
		if (isr_rsg.bit.bit6)
			p_fun[6]();
		if (isr_rsg.bit.bit7)
			p_fun[7]();
		putchar('\n');
	}
	return 0;
}
