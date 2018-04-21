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
	int n;
	cin >> n;
	char t;
	int x = 0, y = 0;
	int state = 0;
	int ans = 0;
	rep(i,n){
		cin >> t;
		if(t == 'U')
			y++;
		else
			x++;
		if(state * (x - y) == -1){
			ans++;
		}
		if(x != y){
			state = x - y;
		}
	}
	cout << ans << endl;
}

int main(){
	solve();
	return 0;
}