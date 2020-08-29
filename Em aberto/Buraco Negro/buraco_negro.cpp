#include <iostream>

using namespace std;

class Point {  

    public:
        Point(double x, double y){
            this->x = x;
            this->y = y;
        }
        double x, y;
};

class Line{
    public: 
        double a, b;
        double xis;

        bool vert;

        Line(Point* p1, Point* p2){
            if(p1->x == p2->x){
                vert = true;
                xis = p1->x;
                return;
            }
            this->a = (p1->y - p2->y) / (p1->x - p2->x);
            this->b = p1->y - this->a * p1->x;   

            cout << "OI\n a=" << this->a << ", b=" << this->b << "\n"; 
        }

        bool isParallel(Line* other){
            cout << "other=" << other->a <<  ", this=" << this->a << "\n";
            if(other->a == this->a) return true;
            return false;
        }

        /*
            y = a1 * x + b1
            y = a2 * x + b2

            x * (a1 - a2) + (b1 - b2) = 0
            x = (b2 - b1) / (a1 - a2)
        */
        Point intersection(Line* other){
            double x = (other->b - this->b) / (this->a - other->a);
            double y = this->a * x + this->b;

            return Point(x, y);
        }
};


int main(){

    Point* x1 = new Point(2, 0);
    Point* x2 = new Point(0, 3);

    Point* y1 = new Point(0, -2);
    Point* y2 = new Point(2, 0);

    Line* l1 = new Line(x1, x2);
    Line* l2 = new Line(y1, y2);

    cout << "Sao paralelas? " << l1->isParallel(l2) << "\n";
    if(!(l1->isParallel(l2))){
        Point aux = l1->intersection(l2);
        cout << "Interseccao: (" << aux.x  << "," << aux.y << ")\n";
    }

    return 0;
}