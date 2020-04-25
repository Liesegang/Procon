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

int dp[3001][3001];
void solve(){
  string s, t;
  cin >> s >> t;

  rep(i, s.size()+1) dp[i][0] = 0;
  rep(j, t.size()+1) dp[0][j] = 0;

  rep(i, s.size()){
    rep(j, t.size()){
      if(s[i] == t[j])
        dp[i+1][j+1] = dp[i][j] + 1;
      else
        dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
    }
  }

  int ss = s.size();
  int tt = t.size();
  int state = 0;
  string ans = "";
  while(ss != 0 && tt != 0){
    switch(state){
      case 0:
        if(dp[ss][tt] != dp[ss-1][tt]){
          state = 1;
          ans += s[ss-1];
        }
        ss--;
        break;
      case 1:
        if(dp[ss][tt] != dp[ss][tt-1]){
          state = 0;
          ans += t[tt-1];
        }
        tt--;
        break;
    }
  }
  reverse(ALL(ans));
  cout << ans << endl;
}

int main(){
// FastIO
//ios_base::sync_with_stdio(false);
cin.tie(NULL);
  solve();
  return 0;
}