#include <iostream>

using namespace std;

int factorial(int n){
    if(n<0){
        return 0;
    }

    int res=0,num=n;

    while(num!=0){
        res += num/5;
        num /= 5;
    }
    return res;
}

int main()
{

    cout << factorial(100) << endl;
    return 0;
}
