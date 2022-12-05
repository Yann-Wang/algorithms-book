#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> & vv, int low, int high){
    int i=low,j=high;
    int temp;
    while(i<j){
        temp = vv[i];
        vv[i] = vv[j];
        vv[j] = temp;
        ++i;
        --j;
    }
}

//int Find

void merge(vector<int> & vv, int low,int mid,int high){

}

void pnsort(vector<int> & vv,int low,int high){

    if(low<high){
        int mid = (low+high)/2;
        pnsort(vv,low,mid);
        pnsort(vv,mid+1,high);
        merge(vv,low,mid,high);
    }
}

void swap(int a,int b){
    int t=a;a=b;b=t;
}

int main()
{
    int a=3,b=4;
    swap(a,b);
    cout << "Hello world!" << endl;
    return 0;
}
