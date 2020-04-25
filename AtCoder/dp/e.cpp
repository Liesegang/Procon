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
const ll llinf = numeric_limits<ll>::max() / 2;
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

ll dp[105][100005];
void solve(){
  ll N, W; cin >> N >> W;
  ll w[105], v[105]; rep(i, N) cin >> w[i] >> v[i];
  dp[0][0] = 0;
  REP(j, 1, 100000+1) dp[0][j] = llinf;

  rep(i, N){
    rep(j, 100000+1){
      if(j-v[i] >= 0){
        dp[i+1][j] = min(dp[i][j], dp[i][j-v[i]] + w[i]);
      } else {
        dp[i+1][j] = dp[i][j];
      }
    }
  }

  rrep(i, 100000+1){
    if(dp[N][i] <= W){
      cout << i << endl;
      break;
    }
  }
}

int main(){
// FastIO
//ios_base::sync_with_stdio(false);
cin.tie(NULL);
  solve();
  return 0;
}