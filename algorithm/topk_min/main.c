#include<stdio.h>

void adjust(int arr[],int low,int high){
    int i=low,j=2*i+1;
    int temp = arr[i];
    while(j<=high){
        if(j<high && arr[j]<arr[j+1]){
            ++j;
        }
        if(arr[i]<arr[j]){
            arr[i] = arr[j];
            i=j;
            j=2*i+1;
        }
        else
            break;
    }
    arr[i] = temp;
}

void topk_min(int arr[],int length, int k){
    int i;
    for(i=(k-1)/2;i>=0;--i){
        adjust(arr,i,k-1);
    }

    for(i=k;i<length;++i){
        if(arr[0]>arr[i]){
            arr[0] = arr[i];
            adjust(arr,0,k-1);
        }
    }
}
/**<
Ê±¼ä¸´ÔÓ¶È O(n*logk)
 */
void main(){
    int arr[8] = {2,5,3,4,1,7,8,6};

    int k=4;
    int i;
    topk_min(arr,8,4);

    for(i=0;i<=k-1;++i){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
