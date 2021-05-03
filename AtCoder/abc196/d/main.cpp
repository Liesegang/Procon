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
const int inf = numeric_limits<int>::max() / 2;
const ll mod = 1e9+7;

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

ll h, w, a, b;

void show(vector<vector<bool> >& used, int depth) {
  rep(i, h) {
    rep(i, depth) printf("  ");
    rep(j, w) {
      cout << (used[i][j] ? "#" : "_");
    }
    cout << endl;
  }
  cout << endl;
}

ll dfs(vector<vector<bool> >& used, ll k, ll left) {
  if(k >= h * w) return 0;
  if(left == 0) {
    return 1;
  }
  ll ans = 0;
  ll i = k / w;
  ll j = k % w;

  if(!used[i][j]) {
    used[i][j] = true;
    if(i + 1 < h && !used[i+1][j]) { //縦置きをする
      used[i+1][j] = true;
      ans += dfs(used, k + 1, left - 1);
      used[i+1][j] = false;
    }
    if(j + 1 < w && !used[i][j+1]) { // 横置き
      used[i][j+1] = true;
      ans += dfs(used, k + 1, left - 1);
      used[i][j+1] = false;
    }
    used[i][j] = false;
  }
  ans += dfs(used, k + 1, left);
  return ans;
}

void solve(){
  cin >> h >> w >> a >> b;
  vector<vector<bool> > used(h, vector<bool>(w, false));
  cout << dfs(used, 0, a) << endl;
}

int main(){
// FastIO
//ios_base::sync_with_stdio(false);
cin.tie(NULL);
  solve();
  return 0;
}