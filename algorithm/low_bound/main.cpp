#include <iostream>
#include <vector>

using namespace std;

// when v exists, return the first position v come out.

int Lower_bound(vector<int> &A,int x,int y,int v){
    int m;
    while(x<y){
        m = x + (y-x)/2;
        if(v <= A[m]){
            y = m;
        }
        else{
            x =m+1;
        }
    }
    return x;
}

int main()
{
    vector<int> A={0,1,2,3,5,5,5,5,6,7,8};
    int len = A.size();
    cout << Lower_bound(A,0,len,4) << endl;
    return 0;
}
