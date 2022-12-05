#include <stdio.h>
#include <stdlib.h>

void adjust(int *arr, int low, int high){
    int tmp = arr[low];
    int i = low;
    int j = 2*i+1;

    if(low<high){

        while(j<=high){
            if(j<high && arr[j]>arr[j+1])
                ++j;

            if(tmp>arr[j]){
                arr[i] = arr[j];
                i = j;
                j = 2*i+1;
            }else{
                break;
            }
        }

        arr[i] = tmp;
    }
}

void topk(int *arr, int k, int len){
    int i,tmp;

    adjust(arr, 0, k-1);

    for(i=k;i<len;++i){
        if(arr[0]<arr[i]){
            tmp = arr[0];
            arr[0] = arr[i];
            arr[i] = tmp;
            adjust(arr, 0, k-1);
        }
    }

    for(i=0;i<k;++i){
        printf("%d ",arr[i]);
    }
}

int main()
{
    int arr[8] = {3,4,2,1,8,7,5,6};
    topk(arr, 4, 8);

    return 0;
}
