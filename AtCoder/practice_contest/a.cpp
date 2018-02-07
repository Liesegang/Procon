#include <iostream>
#include <string>
using namespace std;

void solve(){
	int a, b, c;
	string str;
	cin >> a >> b >> c;
	a = a + b + c;
	cin >> str;
	cout << a << " " << str << endl;

}

int main(){
	solve();
	return 0;
}