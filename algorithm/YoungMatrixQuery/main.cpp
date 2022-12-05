#include <iostream>
#define ROW 4
#define COLUMN 4
using namespace std;

bool YoungMatrix(int arr[][COLUMN],int key,int *c){
    int i=0,j=COLUMN-1;
    *c = 0;
    while(true){
        ++*c;
        if(key<arr[i][j] && j>0){
            --j;
        }
        else if(key>arr[i][j] && i<ROW-1){
            ++i;
        }
        else if(key == arr[i][j]){
            return true;
        }
        else{
            return false;
        }
    }


}


int main()
{
    int arr[][COLUMN] = {1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
    int key = 6;
    int count;
    bool b = YoungMatrix(arr,key,&count);

    cout << b << " "<< count << endl;
    return 0;
}
