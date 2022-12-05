#include <iostream>
#include <vector>

using namespace std;

void adjust(vector<int>& v,int low,int high){
    int i=low,j=2*i+1;
    int temp = v[i];
    while(j<=high){
        if(j<high && v[j]<v[j+1]){
            ++j;
        }
        if( temp<v[j]){
            v[i] = v[j];
            i = j;
            j = 2*i+1;
        }
        else
            break;
    }
    v[i] = temp;
}



int getMedian(vector<int>& v){
    int len = v.size();
    int heapLen = (len-1)/2;  //中位数下标
    int start = (heapLen-1)/2;

    for(int i=start;i>=0;--i){
        adjust(v,i,heapLen);
    }




    for(int i=heapLen+1;i<=len-1;++i){

        if(v[0] > v[i]){
            v[0] = v[i];
            adjust(v,0,heapLen);

        }
    }

    return v[0];




}

int main()
{
    vector<int> T = {10,9,8,7,6,5,4,3,2,1,12};
    int median = getMedian(T);

    cout << median << endl;
    return 0;
}
