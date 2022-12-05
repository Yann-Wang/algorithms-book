#include<iostream>
#include<stdio.h>
using namespace std;

int main ()
{
  bool flag[20][20];
  memset(flag,0,sizeof(flag));

  for(int i=0;i<20;++i){
    for(int j=0;j<20;++j){
        cout<< flag[i][j];
    }
    cout << endl;
  }

  return 0;
}
