#include <iostream>
using namespace std;

class elem{
public:
	int two;
	int three;
	int five;
	bool divisible;
};

elem factorization(long n){
	int rest = n;
	elem ret;
	while(n != 1){
		bool flag = false;
		if(n % 2 == 0){
			ret.two += 1;
			flag = true;
		}
		if(n % 3 == 0){
			ret.two += 1;
			flag = true;
		}
		if(n % 5 == 0){
			ret.two += 1;
			flag = true;
		}
		if(!flag){
			ret.divisible = false;
			return ret;
		}
	}
	ret.divisible = true;
	return ret;
}

void solve(){
	
}

int main(){
	solve();
	return 0;
}