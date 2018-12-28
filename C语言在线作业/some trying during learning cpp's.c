#include <stdio.h>                      //说明vs是支持复合文字的！
double rect_area(struct rect r);
struct rect
{
	double x;
	double y;
};
double rect_area(struct rect r)
{
	return(r.x*r.y);
}
int main(void)
{
	double area;
	area = rect_area((struct rect) { 10.5, 20.0 });
	printf("%f", area);
	return 0;
}                              
