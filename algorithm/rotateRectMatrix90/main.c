#include<stdio.h>
#include "spiralPrintMatrix.c"
#define len 4

void rotateRectMatrix90(int arr[][len]){
    int ltR=0,ltC=0,rbR=len-1,rbC=len-1;
    while(ltR<=rbR && ltC<=rbC){
        rotate90(arr,ltR++,ltC++,rbR--,rbC--);
    }
}

void rotate90(int arr[][len],int ltR,int ltC,int rbR,int rbC){
    int temp,i;
    for(i=0;i<rbC-ltC;++i){
        temp = arr[ltR][ltC+i];
        arr[ltR][ltC+i] = arr[rbR-i][ltC];
        arr[rbR-i][ltC] = arr[rbR][rbC-i];
        arr[rbR][rbC-i] = arr[ltR+i][rbC];
        arr[ltR+i][rbC] = temp;
    }
}

void main(){
    int arr[][len] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    spiralOrderPrint(arr,len,len);
    rotateRectMatrix90(arr);
    spiralOrderPrint(arr,len,len);


}
