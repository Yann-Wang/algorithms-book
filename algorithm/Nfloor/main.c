#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;

    while(scanf("%d",&N) != EOF){

        long long n0=1;
        long long n1=1;
        long long sum=0;
        int i;
        if(N ==  1){
            printf("%lld\n",n1);
            //continue;
        }else{
        	for(i=2;i<=N;++i){
                sum = n0+n1;
                n0 = n1;
                n1 = sum;
            }
            printf("%lld\n",sum);
        }


    }

    return 0;
}
/*
#include<stdio.h>

int main(){
 int i,n;
 long long a[100]={0};

    a[1]=1;a[2]=2;

 for(i=3;i<99;i++)
  a[i]=a[i-1]+a[i-2];

 while(scanf("%d",&n)!=EOF){
  printf("%lld\n",a[n]);
 }
    return 0;
}
*/
