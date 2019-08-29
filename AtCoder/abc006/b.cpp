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
#include <limits>

using namespace std;
using ll=long long;
using vint=vector<int>;
using pint=pair<int,int>;

const double EPS = 1e-9;
const int inf = numeric_limits<int>::max();

#define rep(i,n) for(int i=0;i<int(n);++i)
#define rrep(i,n) for(int i=int(n-1);i>=0;--i)
#define REP(i,a,b) for(int i=int(a);i<int(b);++i)
#define RREP(i,a,b) for(int i=int(b-1);i>=int(a);--i)
#define SHOW(a) cout << #a << " = " << a << endl
#define ARR(a,n) for(int i=0;i<int(n);++i) cout << #a << "[" << i << "]" << " = " << a[i] << endl

const int mod = 10007;

int tri(int n){
	int a = 0, b = 0, c = 1;
	if(n == 1)
		return a;
	if(n == 2)
		return b;
	if(n == 3)
		return c;

	rep(i, n-3){
		int x = (a + b + c) % mod;
		a = b; b = c; c = x;
	}

	return c % mod;
}

void solve(){
	int n;
	cin >> n;
	cout << tri(n) << endl;
}

int main(){
	solve();
	return 0;
}