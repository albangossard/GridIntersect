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

class Grid{
private:
    int Nx, Ny;
    double Dx, Dy;
    Point * grid;
    struct ProjectionPoint{
        double val;
        double t;
    };
public:
    Grid(int Nx, int Ny);
    void intersect(Point* pt1, Point* pt2, list<Point>& intersectPt);
};