#include <stdio.h>
#define C 20
typedef struct car
{
	int price;
	char name[20];
}CAR;

CAR model(CAR pt);

int main(void)
{
	CAR mod={12,};
	model(mod);
}
CAR model(CAR pt)
{
	printf("%d, %s",pt.price,pt.name);
}
