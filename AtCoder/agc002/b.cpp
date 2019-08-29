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
	const int MAX_N = 1e5+5;
	int N, M;
	int num[MAX_N];
	bool mark[MAX_N] = {};

	cin >> N >> M;
	rep(i,N){
		num[i] = 1;
	}
	mark[0] = true;

	rep(i, M){
		int x, y;
		cin >> x >> y; x--; y--;
		if(mark[x]){
			mark[y] = true;
			if(num[x] == 1){
				mark[x] = false;
			}
		}
		num[x]--;
		num[y]++;
	}

	int ans = 0;
	rep(i,N){
		ans += mark[i];
	}
	cout << ans << endl;
}

int main(){
	solve();
	return 0;
}