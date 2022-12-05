#include <iostream>
#include <string>
#include <vector>
using namespace std;

void quickSort(string &str,int low,int high){
    int i=low,j=high;
    char s = str[i];
    if(low<high){
        while(i<j){
            while(i<j&&str[j]>s){
                --j;
            }
            if(i<j){
                str[i] = str[j];
                ++i;
            }
            while(i<j && str[i]<s){
                ++i;
            }
            if(i<j){
                str[j] = str[i];
                --j;
            }
        }
        str[i] = s;
        quickSort(str,low,i-1);
        quickSort(str,i+1,high);

    }
}

vector<char>  mergeAndDedupString(string str1,string str2){
    int n = str1.size()+str2.size()-1;
    vector<char> vv;
    int i=0,j=0,k=0;
    quickSort(str1,0,str1.size()-1);
    quickSort(str2,0,str2.size()-1);
    if(str1[i]<str2[j]){
        vv.push_back(str1[i++]);
    }
    else{
        vv.push_back(str2[j++]);
    }

    while(i<str1.size() && j<str2.size()){
        if(str1[i]<str2[j]){
            if(str1[i]==vv[vv.size()-1]){
                ++i;
            }
            else{
                vv.push_back(str1[i++]);
            }

        }
        else{
            if(str2[j]==vv[vv.size()-1]){
                ++j;
            }
            else{
                vv.push_back(str2[j++]);
            }

        }
    }

    while(i<str1.size()){
        if(str1[i]==vv[vv.size()-1]){
            ++i;
        }
        else{
            vv.push_back(str1[i++]);
        }
    }

    while(j<str2.size()){
        if(str2[j]==vv[vv.size()-1]){
            ++j;
        }
        else{
            vv.push_back(str2[j++]);
        }
    }

    return vv;

}

int main()
{
    string str1 = "dojfs";
    string str2 = "dnljh";
    vector<char> vv = mergeAndDedupString(str1,str2);
    for(auto m : vv){
        cout << m;
    }
    cout << endl;
    return 0;
}
