#include "gridIntersect.h"
#include <iostream>
#include <list>
using namespace std;

int main(){
    int Nx=5;
    int Ny=5;
    double* density=(double*)calloc((Nx-1)*(Ny-1), sizeof(double));
    density[1*(Nx-1)+1]=1.0;
    Grid Map(Nx,Ny,density);
    // Map.print_r0();
    list<Point> pts;
    Point tmp;
    tmp.x=0.2; tmp.y=0.2; pts.push_back(tmp);
    tmp.x=0.4; tmp.y=0.85; pts.push_back(tmp);
    tmp.x=0.8; tmp.y=0.55; pts.push_back(tmp);
    tmp.x=0.6; tmp.y=0.0; pts.push_back(tmp);
    // double eps=1e-7;
    // tmp.x=0; tmp.y=0; pts.push_back(tmp);
    // tmp.x=0; tmp.y=1-eps; pts.push_back(tmp);
    // tmp.x=1-eps; tmp.y=1-eps; pts.push_back(tmp);
    // tmp.x=1-eps; tmp.y=0; pts.push_back(tmp);
    double cost = Map.computeCost(pts);
    cout<<"cost="<<cost<<endl;
    return 0;
}

// int main2(){
//     Grid Map(5,5);
//     Point pt1;
//     Point pt2;
//     pt1.x=0.8/4.0; pt1.y=0.2/4.0;
//     pt2.x=2.1/4.0; pt2.y=3.7/4.0;
//     // list<Point> intersectPt;
//     list<PointPos> intersectPt;
//     Map.intersectSegment(&pt1,&pt2,intersectPt);
//     list<Point>::iterator it;
//     for (it=intersectPt.begin(); it!=intersectPt.end(); ++it){
//         cout<<it->x<<" "<<it->y<<endl;
//     }
//     return 0;
// }