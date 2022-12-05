#include <iostream>
#include <cmath>

using namespace std;

bool isInside(double x1,double y1,double x4,double y4,double x,double y){
    if(x<=x1){
        return false;
    }
    if(x>=x4){
        return false;
    }
    if(y>=y1){
        return false;
    }
    if(y<=y4){
        return false;
    }
    return true;
}

bool pointIsInsideMatrix(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4,double x,double y){
    if(y1==y2){
        return isInside(x1,y1,x4,y4,x,y);
    }
    double l = fabs(y4-y3);
    double k = fabs(x4-x3);
    double s = sqrt(k*k+l*l);
    double sin = l/s;
    double cos = k/s;

    double x1R = x1*cos + y1*sin;
    double y1R = -x1*sin + y1*cos;

    double x4R = x4*cos + y4*sin;
    double y4R = -x4*sin + y4*cos;

    double xR = x*cos + y*sin;
    double yR = -x*sin + y*cos;
    cout << x1R << " "<< y1R << " "<< x4R << " "<<y4R<< " " <<xR << " "<< yR << endl;

    return isInside(x1R,y1R,x4R,y4R,xR,yR);
}

int main()
{

    cout << pointIsInsideMatrix(-3,2,4,2,-3,-3,4,-3,1,-1) << endl;
    cout << pointIsInsideMatrix(-3,2,4,2,-3,-3,4,-3,9,-9) << endl;
    cout << pointIsInsideMatrix(-1,0,0,1,0,-1,1,0,0.5,0.5) << endl;
    return 0;
}
