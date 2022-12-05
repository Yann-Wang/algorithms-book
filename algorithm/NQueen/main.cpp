#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

bool isValid(vector<int>& record, int i, int j){
    for(int k=0; k<i; k++){
        if(j==record[k] || abs(record[k]-j)==abs(i-k)){
            return false;
        }
    }

    return true;
}

int process1(int i, vector<int>& record, int n){
    if(i == n){
        return 1;
    }

    int res = 0;
    for(int j=0;j<n;j++){
        if(isValid(record,i,j)){
            record[i] = j;
            res += process1(i+1, record, n);
        }
    }

    return res;
}

int num1(int n){
    if(n < 1){
        return 0;
    }

    vector<int> record(n,n);
    return process1(0,record,n);
}

int main()
{
    cout << num1(8) << endl;
    return 0;
}
