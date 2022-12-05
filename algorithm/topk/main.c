#include<stdio.h>
/**<
Ð¡¶¥¶Ñ
 */
void adjust(int arr[],int low,int high){
    int i=low,j=2*i+1;
    int temp =arr[i];
    while(j<=high){
        if(j<high && arr[j]>arr[j+1]){
            ++j;
        }
        if(arr[i]>arr[j]){
            arr[i] = arr[j];
            i=j;
            j=2*i+1;
        }
        else{
            break;
        }
    }
    arr[i] = temp;
}

void topk(int arr[],int length,int k){
    int i;
    for(i=(k-1)/2;i>=0;--i){
        adjust(arr,i,k-1);
    }

    for(i=k;i<length;++i){
        if(arr[i]>arr[0]){
            arr[0] = arr[i];
            adjust(arr,0,k-1);
        }
    }
}

void main(){
    int arr[8] = {2,5,3,4,1,7,8,6};
    int k = 4;
    topk(arr,8,k);

    int i;
    for(i=k-1;i>=0;--i){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
