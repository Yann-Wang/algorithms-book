#include <stdio.h>
#include <stdlib.h>

int FindOneNumber(int *a,int length){
    int candidate = a[0];
    int nTimes = 1;
    int i;

    for(i=1;i<length;++i){
        if(nTimes == 0){
            candidate = a[i];
            nTimes = 1;
        }
        else{
            if(candidate == a[i]){
                ++nTimes;
            }
            else{
                --nTimes;
            }
        }
    }
    return candidate;
}

int main()
{
    int a[5] = {0,1,2,1,1};
    int res = FindOneNumber(a,5);
    printf("%d\n",res);
    return 0;
}
