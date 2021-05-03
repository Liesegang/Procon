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

const int MX = 5010;
ll dp[MX][MX][2];

void solve(){
  int N, K;
  cin >> N >> K;
  vector<int> a(N), t(K);
  rep(i, N) cin >> a[i];
  sort(a.begin(), a.end());
  rep(i, K) cin >> t[i];

  set<int> st;
  rep(i, K) st.insert(t[i]);

  rep(i, N) {
    if(st.count(a[i])) {
      st.erase(a[i]);
    } else {
      st.insert(a[i]);
    }
  }

  vector<int> b;
  for(int x : st) b.push_back(x);

  int b_sz = b.size();

  if (b_sz > N || b_sz % 2 != N % 2) {
    cout << -1 << endl;
    return;
  }

  rep(i, MX) rep(j, MX) rep(k, 2) dp[i][j][k] = 1ll << 60;
  dp[0][0][0] = 0;

  rep(i, N) rep(j, b_sz + 1) rep(k, 2) {
    if(dp[i][j][k] == 1ll << 60) continue;
    if(k) {
      chmin(dp[i + 1][j][0], dp[i][j][1] + a[i]);
    } else {
      chmin(dp[i + 1][j][1], dp[i][j][0] - a[i]);
      if(j < b_sz) {
        chmin(dp[i + 1][j + 1][0], dp[i][j][0] + abs(a[i] - b[j]));
      }
    }

  }
  cout << dp[N][b_sz][0] << endl;
}

int main(){
// FastIO
//ios_base::sync_with_stdio(false);
cin.tie(NULL);
  solve();
  return 0;
}