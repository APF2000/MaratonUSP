#include <bits/stdc++.h>

#define G 9.80665
#define PI 3.14159

using namespace std;

void duckNuck(int p1, int p2, double x){
    cout << x << " -> ";
    puts((x >= p1 && x <= p2) ? "DUCK" : "NUCK");
}

long double bhaskara(double a, double b, double c){
    long double delta = b * b - 4 * a * c;
    long double res;
    if(delta < 0){
        return -1;
    }
    res = (-b - sqrt(delta)) / (2 * a);
    return res;
}

// 0 = h + v * t - G * t^2 / 2

int main(){

     double tempoQueda, h;
     int p1, p2;
     double alpha, v, vx, vy;
     double deltaX;
    int n;
    
  cout << fixed << setprecision(5);
    while(cin >> h >> p1 >> p2 >> n){

        for(int i = 0; i < n; i++){
            cin >> alpha >> v;
            alpha = alpha * PI / 180.0;
            vx = v * cos(alpha);
            vy = v * sin(alpha);
            tempoQueda = bhaskara(-G/2, vy, h);

            deltaX = tempoQueda * vx;
            
            duckNuck(p1, p2, deltaX);
        }
    }
    return 0;
}