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
#define REP(i,a,b) for(int i=int(a);i<int(b);++i)
#define SHOW(a) cout << #a << " = " << a << endl
#define ARR(a,i,n) for(int i=0;i<int(n);++i) cout << #a << "[" << i << "]" << " = " << a[i] << endl

void solve(){
	int res = 1000;
	int n,t[4];
	cin >> n;
	rep(i,n){
		cin >> t[i];
	}

	int i = 0;
	for(;!(i & (1<<n));i++){
		int a=0, b=0;
		rep(j,n){
			if(i & (1 << j)){
				a += t[j];
			}else{
				b += t[j];
			}
		}
		res = min(max(a,b),res);
	}

	cout << res << endl;
}

int main(){
	solve();
	return 0;
}