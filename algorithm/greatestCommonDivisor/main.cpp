#include <iostream>

using namespace std;

int gcd(int m,int n){
    return n==0 ? m : gcd(n,m%n);
}

int main()
{

    cout << gcd(168,300) << endl;
    return 0;
}
