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

void solve(){
	int n;
	cin >> n;

	int x[200005];
	rep(i,n) cin >> x[i];

	int y[200005];
	rep(i,n) y[i] = x[i];

	sort(y, y+n);

	int mid = y[n/2 - 1];
	int mid2 = y[n/2];
	rep(i,n){
		if(x[i] <= mid){
			cout << mid2 << endl;
		}else{
			cout << mid << endl;
		}
	}
}

int main(){
	solve();
	return 0;
}