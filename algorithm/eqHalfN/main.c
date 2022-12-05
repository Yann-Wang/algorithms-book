#include <stdio.h>
#include <stdlib.h>

int eqHalfN(int *a,int length){
    int candidate = a[0];
    int nTimes = 1;
    int i,count=1;

    for(i=1;i<length;++i){
        if(a[i-1]==a[length-1]){
            ++count;
        }
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
    if(count == length/2){
        return a[length-1];
    }
    return candidate;
}

int main()
{
    int a[4] = {0,1,2,1};
    int res = eqHalfN(a,4);
    printf("%d\n",res);
    return 0;
}
