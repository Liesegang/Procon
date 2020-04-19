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

char S[2005][2005];
int l[2005][2005], r[2005][2005], u[2005][2005], d[2005][2005];

void solve(){
  int H, W;
  cin >> H >> W;

  rep(y, H){
    rep(x, W) cin >> S[x][y];
  }

  rep(y, H){
    REP(x, 1, W){
      if(S[x][y] == '#' || S[x-1][y] == '#'){
        l[x][y] = 0;
        continue;
      }
      l[x][y] = l[x-1][y] + 1;
    }
  }

  rep(y, H){
    RREP(x, 0, W-1){
      if(S[x][y] == '#' || S[x+1][y] == '#'){
        r[x][y] = 0;
        continue;
      }
      r[x][y] = r[x+1][y] + 1;
    }
  }

  rep(x, W){
    REP(y, 1, H){
      if(S[x][y] == '#' || S[x][y-1] == '#'){
        d[x][y] = 0;
        continue;
      }
      d[x][y] = d[x][y-1] + 1;
    }
  }


  rep(x, W){
    RREP(y, 0, H-1){
      if(S[x][y] == '#' || S[x][y+1] == '#'){
        u[x][y] = 0;
        continue;
      }
      u[x][y] = u[x][y+1] + 1;
    }
  }

  int ans = 0;
  rep(y, H) rep(x, W){
    if(S[x][y] != '#') ans = max(ans, l[x][y] + r[x][y] + u[x][y] + d[x][y] + 1);
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