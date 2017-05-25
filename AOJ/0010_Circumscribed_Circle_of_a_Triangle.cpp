#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Point{
public:
  double x, y;

  Point operator+(Point other){
    Point a;
    a.x = this->x + other.x;
    a.y = this->y + other.y;
    return a;
  }

  Point operator-(Point other){
    Point a;
    a.x = this->x - other.x;
    a.y = this->y - other.y;
    return a;
  }

  Point operator*(double other){
    Point a;
    a.x = other * this->x;
    a.y = other * this->y;
    return a;
  }

  Point operator/(double other){
    Point a;
    a.x = this->x / other;
    a.y = this->y / other;
    return a;
  }

  double dot(Point other){
    return this->x * other.x + this->y * other.y;
  }

  double norm(){
    return sqrt(this->x * this->x + this->y * this->y);
  }
};

double vcos(Point a, Point b){
  return a.dot(b) / a.norm() / b.norm();
}

double vsin(Point a, Point b){
  return sqrt(1 - pow(vcos(a, b), 2));
}

double arg(Point a, Point b){
  return acos(vcos(a, b));
}

int main(){
  Point a, b, c;
  int n;
  cout << fixed << setprecision(3);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    double A = sin(2 * arg(b - a, c - a));
    double B = sin(2 * arg(a - b, c - b));
    double C = sin(2 * arg(a - c, b - c));
    Point O = (a * A + b * B + c * C) / (A + B + C);
    cout << O.x << " " << O.y << " " << (O - a).norm() << endl;
  }
  return 0;
}
