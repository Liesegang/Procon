
/* Union Find木 */
/* グループ分けする木 */
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