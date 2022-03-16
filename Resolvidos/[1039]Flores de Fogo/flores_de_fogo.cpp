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
	Circle *c1, *c2;
	int r1, x1, y1, r2, x2, y2;

	while(cin >> r1 >> x1 >> y1 >> r2 >> x2 >> y2)
	{
		c1 = new Circle(r1, x1, y1);
		c2 = new Circle(r2, x2, y2);

		cout << (c2->is_inside(c1) ? "RICO" : "MORTO") << "\n";

		delete [] c1;
		delete [] c2;
	}

	return 0;
}
