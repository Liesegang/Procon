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

struct compare_length {
    bool operator()(const std::vector<int> &l, const std::vector<int> &r) const {
        return l.size()<r.size();
    }
};

void solve(){
  int n;
  cin >> n;
  int a[60];

  int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
  int pn = 15;

  vector<vector<int> > table(n);
  rep(i, n) {
    cin >> a[i];
  }

  rep(i, n) {
    rep(j, pn) {
      if(a[i] % primes[j] == 0) table[i].push_back(primes[j]);
    }
  }

  ll ans = 1ll << 62;
  for(int i = 0; i < (1 << 15); i++) {
    bool check[n] = {};
    ll cand = 1;
    for(int j = 0; j < 15; j++) {
      if(!(i & (1 << j))) continue;
      cand *= primes[j];
      for(int k = 0; k < n; k++) {
        if(a[k] % primes[j] == 0) check[k] = true;
      }
    }
    bool flag = true;
    for(int j = 0; j < n; j++) {
      if(check[j] == false)
        flag = false;
    }
    if(flag) {
      ans = min(ans, cand);
    }
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