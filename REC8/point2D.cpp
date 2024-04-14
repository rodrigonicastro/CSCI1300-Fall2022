#include <iostream>
#include <cmath>
#include "point2D.h"
using namespace std;

point2D::point2D(){
    x = 0.0;
    y = 0.0;
    label = "";
}

point2D::point2D(double inputX, double inputY){
    x = inputX;
    y = inputY;
}

point2D::point2D(double inputX, double inputY, string inputLabel){
    x = inputX;
    y = inputY;
    label = inputLabel;
}

string point2D::getLabel(){
    return label;
}

double point2D::getX(){
    return x;
}

double point2D::getY(){
    return y;
}

void point2D::setLabel(string inputLabel){
    label = inputLabel;
}

void point2D::setX(double inputX){
    x = inputX;
}

void point2D::setY(double inputY){
    y = inputY;
}

void point2D::print(){
    getLabel();
    getX();
    getY();

    cout << label << ": " << "(" << x << "," << y << ")";
}

double point2D::distance(point2D){
    double x1 = getX();
    double y1 = getY();
    double x2 = point2D.getX();
    double y2 = point2D.getY();

    double distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

    return distance;
}

int main(){
    point2D def;
    def.print();

    point2D a(1, 2);
    a.print();
    a.setLabel("A");
    a.print();

    point2D b(3, 4, "B");
    b.print();

    cout << "a.distance(b): " << a.distance(b) << endl;
}