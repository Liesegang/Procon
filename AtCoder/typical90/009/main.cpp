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

const double PI = 3.1415926535897932384626433832795028;

double reg(double x) {
  if(x < 0) x += 2 * PI;
  if(x > PI) {
    return 2 * PI - x;
  }
  return x;
}

void solve(){
  int n; cin >> n;
  vector<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];

  double ans = 0.0;

  rep(i, n) {
    int xx = x[i], yy = y[i];
    vector<double> angls;
    rep(j, n) {
      if(i == j) continue;
      angls.push_back(atan2(y[j] - yy, x[j] - xx));
    }
    sort(ALL(angls));
    int m = angls.size();
    for(auto a : angls) {
      double b = a + PI;
      if(b > 2 * PI) b -= 2 * PI;
      int idx = lower_bound(ALL(angls), b) - angls.begin();
      ans = max(ans, reg(angls[idx % m] - a));
      ans = max(ans, reg(angls[(idx - 1) % m] - a));
    }
  }

  cout << fixed << setprecision(15);
  cout << ans / PI * 180.0 << endl;
}

int main(){
// FastIO
//ios_base::sync_with_stdio(false);
cin.tie(NULL);
  solve();
  return 0;
}