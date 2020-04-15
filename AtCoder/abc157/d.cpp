#include <bits/stdc++.h>
using namespace std;

// Type alias
using ll=long long;
using ld=double;

using pi=pair<int,int>;
using pll=pair<ll,ll>;
using pld=pair<ld,ld>;
using ti3=tuple<int, int, int>;

using vi=vector<int>;
using vll=vector<ll>;
using vld=vector<ld>;
using vpi=vector<pi>;
using vpll=vector<ll>;
using vpld=vector<ld>;
using vti3=vector<ti3>;

// Constants
const double EPS = 1e-9;
const int inf = numeric_limits<int>::max();

// Macro
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rrep(i,n) for(int i=int(n-1);i>=0;--i)
#define REP(i,a,b) for(int i=int(a);i<int(b);++i)
#define RREP(i,a,b) for(int i=int(b-1);i>=int(a);--i)
#define SHOW(a) cout << #a << " = " << a << endl
#define ARR(a,n) for(int i=0;i<int(n);++i) cout << #a << "[" << i << "]" << " = " << a[i] << endl

#define ALL(a) a.begin(),a.end()

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

// Funtcions
ll pow(ll base, ll i, ll mod){
  ll a = 1;
  while(i){
    if (i & 1) {
      a *= base;
      a %= mod;
    }
    base *= base;
    base %= mod;
    i >>= 1;
  }
  return a;
}
ll gcd(ll a, ll b){
  while(b){
    ll c = a % b;
    a = b;
    b = c;
  }
  return a;
}
ll lcm(ll a, ll b){
  return a / gcd(a, b) * b;
}


void solve(){
  int N, M, K;
  cin >> N >> M >> K;
  UnionFind uf(N);
  int A[100000+5], B[100000+5];
  int count[100000+5] = {};

  rep(i, M){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    A[i] = a;
    B[i] = b;
    uf.unite(a, b);
  }

  rep(i, M){
    int a, b;
    a = A[i];
    b = B[i];
    if(uf.same(a, b)){
      count[a]++;
      count[b]++;
    }
  }

  rep(i, K){
    int c, d;
    cin >> c >> d;
    c--;
    d--;
    if(uf.same(c, d)){
      count[c]++;
      count[d]++;
    }
  }

  rep(i, N){
    cout << uf.size(i) - count[i] - 1 << " ";
  }
}

int main(){
// FastIO
//ios_base::sync_with_stdio(false);
cin.tie(NULL);
  solve();
  return 0;
}