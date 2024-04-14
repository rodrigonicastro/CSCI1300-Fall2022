#include <iostream>
using namespace std;

class point2D{
    private:
        double x;
        double y;
        string label;
    
    public:
        point2D();
        point2D(double, double);
        point2D(double, double, string);
        string getLabel();
        double getX();
        double getY();
        void setLabel(string);
        void setX(double);
        void setY(double);

        void print();
        double distance(point2D);
};