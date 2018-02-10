#include <iostream>
#include <cstdio>
#include <bitset>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <utility>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
using ll=long long;
using vint=vector<int>;
using pint=pair<int,int>;

const double EPS = 1e-9;

#define rep(i,n) for(int i=0;i<int(n);++i)
#define REP(i,a,b) for(int i=int(a);i<int(b);++i)
#define SHOW(a) cout << #a << " = " << a << endl;

void solve(){
	ll a, b;
	cin >> a >> b;


	if(a > 0 && b > 0){
		cout << "Positive";
	}else if(a < 0 && b < 0){
		if(abs(a - b) % 2){
			cout << "Positive";
		}else{
			cout << "Negative";
		}
	}else{
		cout << "Zero";
	}
	cout << endl;
}

int main(){
	solve();
	return 0;
}