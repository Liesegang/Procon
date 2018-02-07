#include <iostream>
#include <map>
#include <utility>
using namespace std;

const int MAX_N = 2 * 100000 + 5;

class UF{
public:

	int par[MAX_N]; // 親
	int rank[MAX_N]; // 木の深さ 

	uni(int n){
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
	int N, K, L;
	map<pair<int, int>,int> count;
	cin >> N >> K >> L;

	UF a(N);
	UF b(N);

	for(int i = 0; i < K; i++){
		int p,q;
		cin >> p >> q;
		a.unite(p-1, q-1);
	}

	for(int i = 0; i < L; i++){
		int p,q;
		cin >> p >> q;
		b.unite(p-1, q-1);
	}

	for(int i = 0; i < N; i++){
		count[make_pair(a.find(i), b.find(i))]++;
	}

	for(int i = 0; i < N; i++){
		cout<< count[make_pair(a.find(i), b.find(i))];
		if(i != N-1){
			cout << " ";
		}else{
			cout << endl;
		}
	}
}

int main(){
	solve();
	return 0;
}