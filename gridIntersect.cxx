#include "gridIntersect.h"

using namespace std;

Grid::Grid(int Nx, int Ny){
    this->Nx=Nx;
    this->Ny=Ny;
    this->Dx=1.0/((double)(Nx-1));
    this->Dy=1.0/((double)(Ny-1));
    this->grid=(Point*)malloc(sizeof(Point)*Nx*Ny);
}
struct ProjectionPoint{
    double val;
    double t;
};
// void printProjectionPoint(list<ProjectionPoint>* l){
//     list<ProjectionPoint>::iterator i;
//     for (i=l->begin(); i!=l->end(); ++i){
//         cout<<"t="<<i->t<<" val="<<i->val<<endl;
//     }
//     cout<<endl;
// }
void Grid::intersect(Point* pt1, Point* pt2, std::list<Point>& intersectPt){
    std::list<ProjectionPoint> listX;
    std::list<ProjectionPoint> listY;
    int floorX1 = floor(pt1->x*(this->Nx-1));
    int floorX2 = floor(pt2->x*(this->Nx-1));
    int floorY1 = floor(pt1->y*(this->Ny-1));
    int floorY2 = floor(pt2->y*(this->Ny-1));
    // cout<<"floorX1 "<<floorX1<<endl;
    // cout<<"floorX2 "<<floorX2<<endl;
    // cout<<"floorY1 "<<floorY1<<endl;
    // cout<<"floorY2 "<<floorY2<<endl;
    // cout<<endl;
    double lenX = abs(pt1->x-pt2->x);
    double lenY = abs(pt1->y-pt2->y);
    ProjectionPoint tmp;
    if (floorX1<floorX2){
        for (int indX=floorX1+1; indX<=floorX2; indX++){
            tmp.val=indX*this->Dx;
            tmp.t=abs(tmp.val-pt1->x)/lenX;
            listX.push_back(tmp);
        }
    }else{
        for (int indX=floorX1; indX>=floorX2+1; indX--){
            tmp.val=indX*this->Dx;
            tmp.t=abs(tmp.val-pt1->x)/lenX;
            listX.push_back(tmp);
        }
    }
    // cout<<"### listX ###"<<endl;
    // printProjectionPoint(&listX);
    if (floorY1<floorY2){
        for (int indY=floorY1+1; indY<=floorY2; indY++){
            tmp.val=indY*this->Dy;
            tmp.t=abs(tmp.val-pt1->y)/lenY;
            listY.push_back(tmp);
        }
    }else{
        for (int indY=floorY1; indY>=floorY2+1; indY--){
            tmp.val=indY*this->Dy;
            tmp.t=abs(tmp.val-pt1->y)/lenY;
            listY.push_back(tmp);
        }
    }
    // cout<<"### listY ###"<<endl;
    // printProjectionPoint(&listY);

    double t;
    Point tmpPt;
    tmpPt.x=pt1->x;
    tmpPt.y=pt1->y;
    intersectPt.push_back(tmpPt);
    while (!listX.empty() || !listY.empty()){
        if (!listX.empty() && !listY.empty()){
            if (listX.front().t==listY.front().t){
                tmpPt.x=listX.front().val;
                tmpPt.y=listY.front().val;
                cout<<"corner : "<<tmpPt.x<<" "<<tmpPt.y<<endl;
                listX.pop_front();
                listY.pop_front();
            }else if (listX.front().t<listY.front().t){
                tmpPt.x=listX.front().val;
                t=listX.front().t;
                tmpPt.y=(1.0-t)*pt1->y+t*pt2->y;
                listX.pop_front();
            }else{
                tmpPt.y=listY.front().val;
                t=listY.front().t;
                tmpPt.x=(1.0-t)*pt1->x+t*pt2->x;
                listY.pop_front();
            }
        }else if(!listX.empty()){
            tmpPt.x=listX.front().val;
            t=listX.front().t;
            tmpPt.y=(1.0-t)*pt1->y+t*pt2->y;
            listX.pop_front();
        }else{
            tmpPt.y=listY.front().val;
            t=listY.front().t;
            tmpPt.x=(1.0-t)*pt1->x+t*pt2->x;
            listY.pop_front();
        }
        intersectPt.push_back(tmpPt);
    }
    tmpPt.x=pt2->x;
    tmpPt.y=pt2->y;
    intersectPt.push_back(tmpPt);
    // cout<<"t="<<t<<endl;
}

int main(){
    Grid Map(5,5);
    Point pt1;
    Point pt2;
    pt1.x=0.8/4.0; pt1.y=0.2/4.0;
    pt2.x=2.1/4.0; pt2.y=3.7/4.0;
    std::list<Point> intersectPt;
    Map.intersect(&pt1,&pt2,intersectPt);
    while (!intersectPt.empty()){
        cout<<intersectPt.front().x<<" "<<intersectPt.front().y<<endl;
        intersectPt.pop_front();
    }
    return 0;
}