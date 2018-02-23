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

void solve(int N, int M){
	vector<int> p;
	p.push_back(0);
	rep(i,N){
		int t;
		cin >> t;
		p.push_back(t);
	}
	sort(p.begin(), p.end());

	vector<int> q;
	rep(i, p.size()){
		rep(j, p.size()){
			if(p[i] + p[j] > M){
				break;
			}
			q.push_back(p[i] + p[j]);
		}
	}

	sort(q.begin(), q.end());

	int ans = 0;
	rep(i, q.size()){
		ans = max(ans, q[i] + *--lower_bound(q.begin(), q.end(), M - q[i]));
	}

	cout << ans << endl;
}

int main(){
	while(true){
		int N, M;
		cin >> N >> M;
		if(N == 0 && M == 0)
			break;
		solve(N,M);
	}
	return 0;
}