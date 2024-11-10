#include<stdio.h>
int main(){
    int num1=1,num2=2;
    int num3;
    if(num1>num2){
        printf("number 1 is greater ");
    }
    else if(num1<num2){
        printf("num2 is greater");
    }
    else if(num1==num2)
    {
        printf("both are equal");
    }
    else{
        printf("input not given //// wrong input");
    }
    return 0;
}