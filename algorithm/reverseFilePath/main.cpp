#include <iostream>
#include <string>
using namespace std;

void reversePathName(string & ss,int low,int high){
    if(low==high)
        return;
    char temp;
    while(low<high){
        temp = ss[low];
        ss[low++] = ss[high];
        ss[high--] = temp;
    }
}

void reversePath(string & ss){
    int start=0,endd=0;
    int len = ss.size();
    reversePathName(ss,0,len-1);

    while(start<len){
        if(ss[start]=='/'){
            ++start;
            ++endd;
        }
        else if(ss[endd]=='/' || endd==len){
            reversePathName(ss,start,endd-1);
            start=endd+1;
            ++endd;
        }
        else{
            ++endd;
        }
    }
}

int main()
{
    string ss="/make/ssdh/file.txt";
    reversePath(ss);
    cout << ss << endl;
    return 0;
}
