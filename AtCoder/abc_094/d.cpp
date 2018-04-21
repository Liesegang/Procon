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

ll combination(unsigned int n, unsigned int r) {
  if ( r * 2 > n ) r = n - r;
  ll dividend = 1;
  ll divisor  = 1;
  for ( unsigned int i = 1; i <= r; ++i ) {
    dividend *= (n-i+1);
    divisor  *= i;
  }
  return dividend / divisor;
}

void solve(){
	int n;
	cin >> n;

	int a[100005];
	rep(i,n) cin >> a[i];
	sort(a, a+n);

	int mm = a[n-1];
	double target = mm / 2.0;

	if(n == 2){
		cout << mm << " " << a[0] << endl;
		return;
	}

	auto l = lower_bound(a, a+n, target);

	if(*l == mm){
		l--;
	}

	cout << mm << " ";

	if(abs(*l - target) > abs(*(--l) - target)){
		cout << *l << endl;
	}else{
		cout << *(++l) << endl;
	}

}

int main(){
	solve();
	return 0;
}



