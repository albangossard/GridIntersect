#include <iostream>
#include <list>
#include <math.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>


struct Point{
    double x,y;
};

class Grid{
private:
    int Nx, Ny;
    double Dx, Dy;
    Point * grid;
public:
    Grid(int Nx, int Ny);
    // std::list<Point>* intersect(Point* pt1, Point* pt2);
    void intersect(Point* pt1, Point* pt2, std::list<Point>& intersectPt);
};