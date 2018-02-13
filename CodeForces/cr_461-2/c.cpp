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
#define REP(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define SHOW(a) cout << #a << " = " << a << endl
#define ARR(a,i,n) for(int i=0;i<int(n);++i) cout << #a << "[" << i << "]" << " = " << a[i] << endl

void solve(){
	ll n, k;
	cin >> n >> k;
	bool ans = true;
	set<ll> a;

	if(n !=1 && n <= k)
		ans = false;
	REP(i,1,k+1){
		//cout << i << " " << n%i << " " << a.count(n%i) << endl;
		if(a.count(n % i)){
			ans = false;
			break;
		}else{
			a.insert(n % i);
		}
	}
	if(ans){
		cout << "Yes";
	}else{
		cout << "No";
	}
	cout << endl;
}

int main(){
	solve();
	return 0;
}