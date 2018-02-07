/* Union Find木 */
/* 合同条件を定められる木 */

const int MAX_N = /* TODO */;
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