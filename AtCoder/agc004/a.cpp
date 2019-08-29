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
	ll n[3];
	cin >> n[0] >> n[1] >> n[2];

	if(!(n[0] % 2 && n[1] % 2 && n[2] % 2)){
		cout << 0;
	}else{
		sort(n, n+3);
		cout << n[0] * n[1];
	}
	cout << endl;
}

int main(){
	solve();
	return 0;
}