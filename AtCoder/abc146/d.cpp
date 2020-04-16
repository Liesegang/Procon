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
  int N;
  cin >> N;

  vector<vector<int>> graph(N);
  vector<pi> edges;

  rep(i, N-1){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
    edges.emplace_back(make_pair(a,b));
  }

  int max = 0;
  rep(i, N){
    int t = graph[i].size();
    chmax(max, t);
  }

  map<pi, int> ce;
  vector<int> cp(N, 0);
  vector<bool> used(N, false);
  used[0] = true;

  queue<int> que;
  que.emplace(0);
  while(!que.empty()){
    int v = que.front(); que.pop();
    int color = 1;
    for(auto u : graph[v]){
      if(used[u]) continue;
      if(cp[v] == color) color++;
      cp[u] = color;
      ce[make_pair(u, v)] = color;
      ce[make_pair(v, u)] = color;
      color++;
      used[u] = true;
      que.emplace(u);
    }
  }

  cout << max << endl;
  rep(i, N-1){
    cout << ce[edges[i]] << endl;
  }
}

int main(){
// FastIO
//ios_base::sync_with_stdio(false);
cin.tie(NULL);
  solve();
  return 0;
}