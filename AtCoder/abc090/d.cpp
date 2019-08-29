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
	int N, K;
	cin >> N >> K;

	ll res = 0;
	if(K == 0){
		res = N * N;
	}else{
		REP(i, K+1, N){
			int tmp = (i-K) * ((N+1)/i);
			if(N%i >= K && N%i){
				tmp += (N%i) - K + 1;
			}
			res += tmp;
		}
	}

	cout << res << endl;
}

int main(){
	solve();
	return 0;
}