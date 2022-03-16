#include <iostream>
#include <iomanip>

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

        }

        static Line* mediatriz(Point *a, Point *b)
        {
            double xm = (a->x + b->x) / 2, ym = (a->y + b->y) / 2;
            Point *med = new Point(xm, ym);
            Point *aux;

            if(a->y == b->y)
            {
                // Vertical line
                aux = new Point(xm, ym + 1);
            }
            else{
                // Angular coef
                double m = - (a->x - b->x) / (a->y - b->y) ;
                aux = new Point(xm + 1, ym + m);
            }

            return new Line(med, aux);
        }


        bool isParallel(Line* other){
            if(other->a == this->a) return true;
            return false;
        }

        /*
            y = a1 * x + b1
            y = a2 * x + b2

            x * (a1 - a2) + (b1 - b2) = 0
            x = (b2 - b1) / (a1 - a2)
        */
        Point* intersection(Line* other)
        {
            if(this->vert)
            {
                return new Point(this->xis, other->a * this->xis + other->b);
            }
            else if(other->vert)
            {
                return new Point(other->xis, this->a * other->xis + this->b);
            }

            double x = (other->b - this->b) / (this->a - other->a);
            double y = this->a * x + this->b;

            return new Point(x, y);
        }
};


int main(){

    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        double x1a, x1d, y1a, y1d;
        double x2a, x2d, y2a, y2d;

        cin >> x1a >> y1a>> x2a >> y2a;
        cin >> x1d >> y1d >> x2d >> y2d;

        Point* umA = new Point(x1a, y1a);
        Point* umD = new Point(x1d, y1d);

        Point* doisA = new Point(x2a, y2a);
        Point* doisD = new Point(x2d, y2d);

        Line *la = Line::mediatriz(umA, umD);
        Line *lb = Line::mediatriz(doisA, doisD);

        if(!(la->isParallel(lb)))
        {
            Point *inter = la->intersection(lb);

            cout.precision(2);
            
            cout << "Caso #" << (i + 1) << ": ";
            cout << setprecision(2) << fixed << (double)inter->x << " " << (double)inter->y << "\n";
        }
    }

    return 0;
}