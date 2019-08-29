#include <iostream>
using namespace std;

int main(){
	int a, t;
	cin >> a;
	cin >> t;
	a -= t;
	cin >> t;
	a %= t;
	cout << a << endl;
	return 0;
}