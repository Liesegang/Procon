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

	ll mvall[100000+5] = {}, mvalr[100000+5] = {};
	mvall[0] = 0;
	mvalr[0] = 0;

	ll pre = 0;
	REP(i, 0, N){
		mvall[i+1] = mvall[i] - x[i] + pre + v[i];
		pre = x[i];
	}


	pre = 0;
	REP(i, 1, N+1){
		mvalr[i] = mvalr[i-1] - (C - x[N-i]) + pre + v[N-i];
		pre = C - x[N-i];
	}
	ARR(mvall, N+1);
	ARR(mvalr, N+1);

  ll rvall[100000+5] = {}, rvalr[100000+5] = {};


	ll rhmax = 0, rhmax_c = -1;
	REP(i, 1, N+1){
		if(C - x[N-i] > C/2)
			break;
		if(rhmax < mvalr[i]){
			rhmax = mvalr[i];
			rhmax_c = 1;
		}
	}

	ll l_i = 0;
	if(rhmax != -1){
		REP(i, 0, N){
			if(x[i] > C/2)
				break;
			l_i = i+2;
			rvall[i+1] = mvall[i+1] - x[i] + rhmax;
		}
	}
	ll max3 = *max_element(rvall, rvall + l_i);
	ARR(rvall, l_i);

	


	ll lhmax = 0, lhmax_c = -1;
	REP(i, 1, N+1){
		if(C - x[N-i] > C/2)
			break;
		if(lhmax < mvall[i]){
			lhmax = mvall[i];
			lhmax_c = 1;
		}
	}

	ll r_i = 0;
	if(lhmax != -1){
		REP(i, 1, N+1){
			if((C - x[N-i]) > C/2)
				break;
			r_i = i+1;
			rvalr[i] = mvalr[i] - (C - x[N-i]) + lhmax;
		}
	}
	ll max4 = *max_element(rvalr, rvalr + r_i);
	ARR(rvalr, r_i);


  
	ll ans = max(*max_element(mvall, mvall+N+1), *max_element(mvalr, mvalr+N+1));
	ans = max(ans, max3);
	ans = max(ans, max4);
	cout << ans << endl;
}

int main(){
	solve();
	return 0;
}