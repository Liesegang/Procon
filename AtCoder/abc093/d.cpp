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

#define rep(i,n) for(ll i=0;i<ll(n);++i)
#define rrep(i,n) for(int i=int(n-1);i>=0;--i)
#define REP(i,a,b) for(int i=int(a);i<int(b);++i)
#define RREP(i,a,b) for(int i=int(b-1);i>=int(a);--i)
#define SHOW(a) cout << #a << " = " << a << endl
#define ARR(a,n) for(int i=0;i<int(n);++i) cout << #a << "[" << i << "]" << " = " << a[i] << endl

ll num(ll A, ll B){
	if(A > B){
		ll tmp = A;
		A = B;
		B = tmp;
	}
	if(A == B || A + 1 == B){
		return 2 * A - 2;
	}
	ll C = sqrt(A * B);
	if(C * C == A * B){
		C--;
	}
	if(C * (C + 1) >= A * B){
		return 2 * C - 2;
	}
	return 2 * C - 1;
}

void solve(){
	int Q;
	cin >> Q;
	int A[105], B[105];
	rep(i, Q){
		cin >> A[i] >> B[i];
	}

	rep(i, Q){
		cout << num(A[i], B[i]) << endl;
	}
}

int main(){
	solve();
	return 0;
}