#include <iostream>
#define ROW 4
#define COLUMN 4


using namespace std;
/*
unfinished
*/
int getYoungMatrixMedian(int arr[][COLUMN],int m){
    int i=0,j=COLUMN-1;


    while(true){
        if((ROW-i)*(COLUMN-j)<m){
            --j;
            count += ROW-i;
        }
        else if(count+1<m){
            ++i;
            ++count;
        }
        else if(count+1 == m){

        }
    }
}

int main()
{
    int arr[][COLUMN] = {1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
    int len = ROW*COLUMN;
    int m = len/2+1;
    int median = getYoungMatrixMedian(arr,m);
    cout << "Hello world!" << endl;
    return 0;
}
