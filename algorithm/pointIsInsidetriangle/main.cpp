#include <iostream>

using namespace std;

double crossProduct(double x1,double y1,double x2,double y2){
    return x1*y2-x2*y1;
}

bool isInside(double x1,double y1,double x2,double y2,double x3,double y3,double x,double y){
    if(crossProduct(x2-x1,y2-y1,x3-x1,y3-y1)<0){
        double tmpx=x2;
        double tmpy=y2;
        x2 = x3;
        y2 = y3;
        x3 = tmpx;
        y3 = tmpy;
    }
    if(crossProduct(x-x1,y-y1,x2-x1,y2-y1)>=0){
        return false;
    }
    if(crossProduct(x-x2,y-y2,x3-x2,y3-y2)>=0){
        return false;
    }
    if(crossProduct(x-x3,y-y3,x1-x3,y1-y3)>=0){
        return false;
    }
    return true;
}

int main()
{

    cout << isInside(-2,0,0,2,2,0,0,0) << endl;
    return 0;
}
