#include "gridIntersect.h"
#include <iostream>
#include <list>
using namespace std;

int main(){
    Grid Map(5,5);
    Point pt1;
    Point pt2;
    pt1.x=0.8/4.0; pt1.y=0.2/4.0;
    pt2.x=2.1/4.0; pt2.y=3.7/4.0;
    list<Point> intersectPt;
    Map.intersect(&pt1,&pt2,intersectPt);
    list<Point>::iterator it;
    for (it=intersectPt.begin(); it!=intersectPt.end(); ++it){
        cout<<it->x<<" "<<it->y<<endl;
    }
    return 0;
}