#include <stdio.h>

int main()
{
	int x1 = 6;
	int x2 = x1*2-4;
	int x3 = x2/3;
	int x4 = x3-x1;
	int x5 = x4*x4;
	float y1 = x2/3;
	float y2 = x2/3.0;
	float y3 = (float)x2/3;
	float y4 = y2*y3;
	float y5 = y4*y3*y2*y1;
	(void)printf("x1=%d x2=%d x3=%d x4=%d x5=%4d\n",x1,x2,x3,x4,x5);
	(void)printf("y1=%f y2=%f y3=%4.2f\n",y1,y2,y3);
	(void)printf("y4=%5.1f y5=%3.1f\n",y4,y5);
}