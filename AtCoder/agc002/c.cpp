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
#define ARR(a,n) for(int i=0;i<int(n);++i) cout << #a << "[" << i << "]" << " = " << a[i] << endl

void solve(){
	int N, L; cin >> N >> L; vector<int> a(N); rep(i,N) cin >> a[i];
	int pos = -1;
	rep(i, N-1){
		if(a[i] + a[i+1] >= L){
			pos = i;
			break;
		}
	}

	if(pos + 1){
		cout << "Possible" << endl;
		rep(i, pos){
			cout << i+1 << endl;
		}
		for(int i = N-1; i > pos; i--)
			cout << i << endl;
	}else{
		cout << "Impossible" << endl;
	}
}

int main(){
	solve();
	return 0;
}