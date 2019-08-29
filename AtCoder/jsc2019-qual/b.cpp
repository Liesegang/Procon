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
const int mod = 1000000000 + 7;

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


void solve(){
  int n, k; cin >> n >> k;
  int a[2005]; rep(i, n) cin >> a[i];
  ll ans = 0;
  ll sub1 = 0, sub2 = 0;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i == j)
        continue;

      if(a[i] > a[j]){
        if(i < j){
          sub1++;
          sub2++;
        }else
        {
          sub2++;
        }
      }
    }
  }
  int t = k, u = k-1;
  if(t % 2 == 0) t /= 2;
  if(u % 2 == 0) u /= 2;

  ans = (k * sub1 % mod + (sub2 * t % mod) * u % mod) % mod;

  cout << ans << endl;
}

int main(){
// FastIO
  //ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}