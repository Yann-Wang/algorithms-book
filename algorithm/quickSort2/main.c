#include<stdio.h>

int partition(int arr[], int m, int n){
    if(m<n){
        int temp = arr[m];
        int i=m,j=n;
        while(i<j){
            while(j>i && arr[j]>temp) --j;
            if(j>i){
                arr[i] = arr[j];
            }
            while(i<j && arr[i]<temp) ++i;
            if(i<j){
                arr[j] = arr[i];
            }
        }
        arr[i] = temp;
        return i;
    }
}

void main(){
    int arr[8] = {2,5,3,4,1,7,8,6};
    int stack[16];
    int top=-1;
    int p;
    stack[++top] = 0;
    stack[++top] = 7;
    int m,n,i;

    while(top!=-1){
        n=stack[top--];
        m=stack[top--];
        p = partition(arr,m,n);
        if(p-1>m){
            stack[++top] = m;
            stack[++top] = p-1;
        }
        if(p+1<n){
            stack[++top] = p+1;
            stack[++top] = n;
        }
    }

    for(i=0;i<8;++i){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
