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
const int inf = numeric_limits<int>::max() / 8;

#define rep(i,n) for(int i=0;i<int(n);++i)
#define REP(i,a,b) for(int i=int(a);i<int(b);++i)
#define SHOW(a) cout << #a << " = " << a << endl
#define ARR(a,n) for(int i=0;i<int(n);++i) cout << #a << "[" << i << "]" << " = " << a[i] << endl

class edge{
public:
	int a, b; //a -> b
	edge(int a, int b):a(a), b(b){}

	bool operator < (const edge& other) const {
		return b < other.b;
	}

	bool operator > (const edge& other) const {
		return b > other.b;
	}
};

void solve(){
	const int MAX_N = 1e5 + 5;
	int N, K, a[MAX_N], t[MAX_N];
	priority_queue<edge, vector<edge>, greater<edge> > es;
	cin >> N >> K; rep(i,N) {cin >> a[i]; --a[i];}

	int ans = 0;
	if(a[0] != 0) ans++;
	a[0] = 0;
	REP(i,1,N) es.push(edge(i, a[i]));

	rep(i,N) t[i] = inf;
	t[0] = 0;

	while(!es.empty()){
		edge e = es.top(); es.pop();
		if(t[e.b] + 1 > K){
			t[e.a] = 1;
			ans++;
		}else{
			t[e.a] = t[e.b] + 1;
		}
	}
	
	cout << ans << endl;
}

int main(){
	solve();
	return 0;
}