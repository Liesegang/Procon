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
template<typename T> bool chmin(T& a, const T& b) {
  if (a > b) return a = b, true; else return false;
}

template<typename T> bool chmax(T& a, const T& b) {
  if (a < b) return a = b, true; else return false;
}


void solve(){
  int N, M;
  cin >> N >> M;

  int dist[105][105] = {};

  rep(i, N)rep(j, N) dist[i][j] = inf / 2;
  rep(i, N) dist[i][i] = 0;

  int A[1005], B[1005], C[1005];
  rep(i, M){
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    dist[a][b] = c;
    dist[b][a] = c;
    A[i] = a; B[i] = b, C[i] = c;
  }

  rep(k, N){
    rep(i, N){
      rep(j, N){
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  int ans = M;

  rep(i, M){
    bool flag = false;
    rep(j, N) if(dist[j][A[i]] + C[i] == dist[j][B[i]]) flag = true;
    if(flag) ans--;
  }

  cout << ans << endl;
}

int main(){
// FastIO
//ios_base::sync_with_stdio(false);
cin.tie(NULL);
  solve();
  return 0;
}