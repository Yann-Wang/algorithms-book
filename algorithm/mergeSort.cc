#include <iostream>
#include <vector>

using namespace std;

void Merge(vector<int> &vv,int low,int mid,int high){
    int i=low,j=mid+1;
    int k=0;
    vector<int> v2(high-low+1);
    while(i<=low && j<=high){
        if(vv[i]<=vv[j])
            v2[k++] = vv[i];
        else
            v2[k++] = vv[j];
    }

    while(i<=low)
        v2[k++] = vv[i];
    while(j<=high)
        v2[k++] = vv[j];

    for(i=low,k=0;k<v2.size();++i,++k)
        vv[i] = v2[k];


}

void MergeSort(vector<int> & vv){
    int intvl=1,low,mid,high;
    int len = vv.size();

    while(intvl<=len-1){
        low = 0;
        while(high<=len-1){
            mid = low+intvl-1;
            high = mid + intvl;
            Merge(vv,low,mid,high);

        }
        intvl *= 2;

    }
}

int main(){

    vector<int> vv={2,3,1,4,8,6,7,5,9};
    MergeSort(vv);
    for(int i=0;i<vv.size();++i)
        cout << vv[i] << " ";
    cout << endl;

    return 0;
}
