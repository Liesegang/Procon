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
	ll N, C;
	cin >> N >> C;
	ll x[100000+5] = {}, v[100000+5] = {};
	rep(i, N)
	  cin >> x[i] >> v[i];

	ll r[100000+5] = {}, l[100000+5] = {};

	r[0] = v[0] - x[0];
	REP(i, 1, N){
		r[i] = r[i-1] - x[i] + x[i-1] + v[i];
	}

	l[0] = v[N-1] - (C - x[N-1]);
	REP(i, 1, N){
		l[i] = l[i-1] - (C - x[N-i-1]) + (C - x[N-i]) + v[N-i-1];
	}

	ll rm[100000+5] = {}, lm[100000+5] = {};
	rm[0] = r[0];
	REP(i, 1, N){
		rm[i] = max(rm[i-1], r[i]);
	}

	lm[0] = l[0];
	REP(i, 1, N){
		lm[i] = max(lm[i-1], l[i]);
	}

	ll rr[100000+5] = {}, rl[100000+5] = {};
	REP(i,0,N-1){
		rr[i] = r[i] + lm[N-i-2] - x[i];
	}
	REP(i,0,N-1){
		rl[i] = l[i] + rm[N-i-2] - (C - x[N-i-1]);
	}

	ll maxs[5] = {};
	maxs[1] = *max_element(r,r+N);
	maxs[2] = *max_element(l,l+N);
	maxs[3] = *max_element(rr,rr+N-1);
	maxs[4] = *max_element(rl,rl+N-1);

	ll ans = *max_element(maxs, maxs+5);

	cout << ans << endl;

}

int main(){
	solve();
	return 0;
}