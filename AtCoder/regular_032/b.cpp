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
#define SHOW(a) cout << #a << " = " << a << endl;

const int MAX_N = 100000;
class UF{
public:

	int par[MAX_N]; // 親
	int rank[MAX_N]; // 木の深さ 

	UF(int n){
		for(int i = 0; i < n; i++){
			par[i] = i;
			rank[i] = 0;
		}
	}

	int find(int x){
		if (par[x] == x){
			return x;
		} else {
			return par[x] = find(par[x]);
		}
	}

	void unite(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y) return;

		if(rank[x] < rank[y]){
			par[x] = y;
		} else {
			par[y] = x;
			if(rank[x] == rank[y])
				rank[x]++;
		}
	}

	bool same(int x, int y){
		return find(x) == find(y);
	}
};


void solve(){
	int N, M;

	cin >> N >> M;
	UF u(N);

	rep(i,M){
		int a, b;
		cin >> a >> b;
		u.unite(a-1, b-1);
	}

	set<int> count;
	rep(i,N){
		count.insert(u.find(i));
	}

	cout << count.size() - 1 << endl;
}

int main(){
	solve();
	return 0;
}