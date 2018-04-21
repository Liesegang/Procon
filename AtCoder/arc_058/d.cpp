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
#define SHOW(a) cout << #a << " = " << a << endl

const int mod = 1e9 + 7;

ll extgcd(ll a, ll b, ll& x, ll& y){
	ll d = a;
	if(b!=0){
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	} else {
		x = 1; y = 0;
	}
	return d;
}

ll mod_inverse(ll a, ll m){
	ll x, y;
	extgcd(a, m, x, y);
	return (m + x%m) % m;
}

const int MAX_P = mod;

ll fact[MAX_P];
ll mod_fact(ll n, ll p, ll &e){
	e=0;
	if(n==0) return 1;
	ll res = mod_fact(n / p, p, e);
	e += n / p;
	if(n / p % 2 != 0) return res * (p- fact[n % p]) % p;
	return res * fact[n % p] % p;
}

ll mod_combination(ll n, ll k, ll p){
	if(n < 0 || k < 0 || n < k) return 0;
	ll e1, e2, e3;
	ll a1 = mod_fact(n, p, e1), a2 = mod_fact(n, p, e2), a3 = mod_fact(n, p, e3);
	if(e1 > e2 + e3) return 0;
	return a1 * mod_inverse(a2 * a3 % p, p) % p;
}

void solve(){
	int H, W, A, B;
	cout << mod_combination(5, 2, mod) << endl;
	cin >> H >> W >> A >> B;
	/*int res = 0;
	rep(i, H - A){
		cout << i+B-1 << " " <<  B-1 << endl;
		res += mod_combination(i+B-1, B-1, mod) * mod_combination(W-B+H-i-2, W-B-1, mod);
		res %= mod;
	}*/
	//cout << res << endl;
}

int main(){
	solve();
	return 0;
}