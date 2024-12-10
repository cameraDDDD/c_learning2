#include<stdio.h>
int main(void){
	enum Gay{
		ATTACK=1,
		ACCEPT=0
	};
	enum Gay kevin=0;
	enum Gay liuyupeng=3;//为什么能运行
	switch (kevin) {
	case ATTACK:
		printf("Kiss my dick");
		break;
	case ACCEPT:
		printf("Fuck my ass");
		break;

	}
	printf("%d",liuyupeng);
}
