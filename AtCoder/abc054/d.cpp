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

int dp[41][401][401];

void solve(){
  int N, Ma, Mb;
  cin >> N >> Ma >> Mb;

  int A[45], B[45], C[45];
  rep(i, N) cin >> A[i] >> B[i] >> C[i];

  rep(i, 41) rep(j, 401) rep(k, 401) dp[i][j][k] = inf / 2;
  dp[0][0][0] = 0;

  rep(i, N) rep(ca, 401) rep(cb, 401){
    if(dp[i][ca][cb] == inf / 2) continue;
    dp[i+1][ca][cb] = min(dp[i+1][ca][cb], dp[i][ca][cb]);
    dp[i+1][ca + A[i]][cb + B[i]] = min(dp[i+1][ca + A[i]][cb + B[i]], dp[i][ca][cb] + C[i]);
  }

  int ans = inf / 2;
  REP(ca, 1, 401) REP(cb, 1, 401){
    if(ca * Mb == cb * Ma)
      ans = min(ans, dp[N][ca][cb]);
  }

  if(ans == inf / 2){
    cout << -1 << endl;
    return;
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