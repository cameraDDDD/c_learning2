//#include<stdio.h>
//int main(void){
//    double a,b;
//    scanf("%.7lf %.7lf",&a,&b);
//    if(a-b>=0.000001||b-a>=0.000001)
//        printf("NO");
//    else
//        printf("YES");
//
//
//}
#include<stdio.h>
int main(void){
    double a,b;
    scanf("%lf %lf",&a,&b);
    a*=1000000;b*=1000000;
    int c=a;int d=b;
    if(c==d)
        printf("YES");
    else
        printf("NO");
    return 0;


}
