#include <iostream>
#include <list>
#include <math.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


struct Point{
    double x,y;
};
struct PointPos{
    double x,y,t;
};

class Grid{
private:
    int Nx, Ny;
    double Dx, Dy;
    // Point * grid;
    struct ProjectionPoint{
        double val;
        double t;
    };
    double* u;
    double* r0;
public:
    Grid(int Nx, int Ny, double* density);
    // void intersectSegment(Point* pt1, Point* pt2, list<Point>& intersectPt);
    void intersectSegment(Point* pt1, Point* pt2, list<PointPos>& intersectPt);
    double computeCost(std::list<Point>& pts);
    void print_r0();
};