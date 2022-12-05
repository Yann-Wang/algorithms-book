#include <iostream>
#include <string>
using namespace std;

void rotate(string &s,int low,int high){
    char temp;
    while(low<high){
        temp = s[low];
        s[low++] = s[high];
        s[high--] = temp;
    }
}

void wordRotate(string &s){
    int len = s.size();
    if(len<1)
        return;

    rotate(s,0,len-1);

    int start=0,endd=0;

    while(start<len){
        if(s[start]==' '){
            ++start;
            ++endd;
        }
        else if(endd==len || s[endd]==' '){
            rotate(s,start,endd-1);
            ++endd;
            start = endd;
        }
        else{
            ++endd;
        }
    }
}

int main()
{
    string ss = "I am a student.";

    wordRotate(ss);
    cout << ss << endl;
    return 0;
}
