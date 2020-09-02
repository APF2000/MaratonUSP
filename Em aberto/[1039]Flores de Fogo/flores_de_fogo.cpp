#include<iostream>
#include <cmath>

using namespace std;

class Circle
{
	public:
		int r, x, y;

		Circle(int r, int xc, int yc)
		{
			this->r = r;
			this->x = xc;
			this->y = yc;
		}

		double distance_to(Circle *other)
		{
			double t1, t2;
			t1 = this->x - other->x;
			t2 = this->y - other->y;

			return sqrt(t1 * t1 + t2 * t2);
		}

		bool is_inside(Circle *other)
		{
			if(this->r < other->r 
					&& this->distance_to(other) <= other->r - this->r) return true;
			else return false;
		}	
};

int main()
{
	Circle *c1 = new Circle(2, 0, 0), *c2 = new Circle(3, 0, 0);

	cout << "C1 inside C2? : " << c1->is_inside(c2) << "\n";
	cout << "C2 inside C1? : " << c2->is_inside(c1) << "\n";

	return 0;
}
