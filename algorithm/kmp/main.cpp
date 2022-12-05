#include <iostream>
#include <string>
#include <vector>
#include "kmp.cc"

using namespace std;



int main()
{
    string ss = "abcdabc";
    string subs = "cda";
    int i = getIndex(ss,subs);

    cout << i << endl;
    return 0;
}
