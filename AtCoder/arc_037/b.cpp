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

const int MAX_N = 100+5;
const int MAX_M = 5000+5;
class UnionFind{
private:
	vector<int> rank; // 木の深さ
	int count_;

public:
	vector<int> data; // 親>0, サイズ<0

	UnionFind(int n):data(n,-1), rank(n,0), count_(n){}

	int root(int x){
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}

	void unite(int x, int y){
		x = root(x);
		y = root(y);
		if(x == y) return;

		count_--;
		if(rank[x] < rank[y]){
			data[y] += data[x];
			data[x] = y;
		} else {
			data[x] += data[y];
			data[y] = x;
			if(rank[x] == rank[y])
				rank[x]++;
		}
	}

	bool same(int x, int y){
		return root(x) == root(y);
	}

	int size(int x){
		return -data[root(x)];
	}

	int groups(){
		return count_;
	}
};




void solve(){
	int N, M;
	int edge[MAX_M], count[MAX_N]={};
	set<int> loop;
	cin >> N >> M;

	UnionFind u(N);
	
	rep(i,M){
		int a, b;
		cin >> a >> b;
		u.unite(a-1,b-1);

		edge[i] = a-1;
	}

	rep(i,M){
		count[u.root(edge[i])]++;
	}

	rep(i, N){
		//SHOW(count[u.root(i)]);
		//SHOW(u.size(i));
		if(count[u.root(i)] >= u.size(i))
			loop.insert(u.root(i));
	}

	cout << u.groups() - loop.size() << endl;
}

int main(){
	solve();
	return 0;
}