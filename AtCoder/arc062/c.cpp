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
	int n;
	cin >> n;
	int a,b;
	cin >> a >> b;
	int res = a + b;
	rep(i,n-1){
		int a,b;
		cin >> a >> b;
		a += b;
		if(res % a != 0)
			res = res + (a - res % a);
	}
	cout << res << endl;
}

int main(){
	solve();
	return 0;
}