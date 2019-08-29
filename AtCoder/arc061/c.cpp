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
	string s;
	cin >> s;
	int n;
	n = s.size();

	int i = 1 << (n-1);
	ll res = 0;
	while(!(i & (1 << n))){
		ll tmp = 0;
		rep(j, n){
			tmp += s[j] - '0';
			if(i & (1 << j)){
				res += tmp;
				tmp = 0;
			}else{
				tmp *= 10;
			}
		}
		i++;
	}

	cout << res << endl;
}

int main(){
	solve();
	return 0;
}