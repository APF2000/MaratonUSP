#include <iostream>

using namespace std;

#define EPS 0.1

// z = x^2 + y^2
double parabola_3d(double x, double y)
{
	return (x * x) + (y * y) + 2;
}

// ( f(x + delta) - f(x) ) / ( delta )
double dx_parabola(double x, double y)
{
	double del_f = parabola_3d(x + EPS, y) - parabola_3d(x, y);
	return del_f / EPS;
}

double dy_parabola(double x, double y)
{
	double del_f = parabola_3d(x, y + EPS) - parabola_3d(x, y);
	return del_f / EPS;
}

void estimate_next_vector(double *xi, double *yi)
{
	double xip1 = *xi, yip1 = *yi; 
	double dx = dx_parabola(xip1, yip1);
	double dy = dy_parabola(xip1, yip1);

	cout << "gradiente: (" << dx << ", " << dy << ")" << endl;
	(*xi) = (*xi) - dx * EPS;//(dx > 0 ? -dx : dx);
	(*yi) = (*yi) - dy * EPS;//(dy > 0 ? -dy : dy);
}

int main()
{
	double xi = 4, yi = -20;

	for (int i = 0; i < 20; i++)
	{
		estimate_next_vector(&xi, &yi);

		cout << "xiyi: (" << xi << ", " << yi << ")" << endl;
	
	}
	
	cout << "valor final: " << parabola_3d(xi, yi) << endl;
	cout << EPS << endl;

	return 0;
}