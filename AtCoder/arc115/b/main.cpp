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


void solve(){
  ll n;
  cin >> n;
  ll c[505][505];
  rep(i, n) rep(j, n) cin >> c[i][j];

  ll y[505], t[505];
  rep(i, n - 1) {
    y[i] = c[0][i+1] - c[0][i];
    ll k = y[i];
    REP(j, 1, n) if(c[j][i+1] - c[j][i] != k) {
      cout << "No" << endl;
      return;
    }
  }

  rep(i, n - 1) {
    t[i] = c[i+1][0] - c[i][0];
    ll k = t[i];
    REP(j, 1, n) if(c[i+1][j] - c[i][j] != k) {
      cout << "No" << endl;
      return;
    }
  }

  ll a[505] = {};
  rep(i, n-1) a[i+1] = a[i] + y[i];

  ll b[505] = {};
  rep(i, n-1) b[i+1] = b[i] + t[i];

  ll mina = *min_element(a, a+n);

  ll inita = -mina;
  ll initb = c[0][0] - inita;

  rep(i, n) {
    a[i] += inita;
    b[i] += initb;
  }

  rep(i, n) {
    if(a[i] < 0 || b[i] < 0) {
      cout << "No" << endl;
      return;
    }
  }

  cout << "Yes" << endl;
  rep(i, n-1) cout << b[i] << " ";
  cout << b[n-1] << endl;
  rep(i, n-1) cout << a[i] << " ";
  cout << a[n-1] << endl;
}

int main(){
// FastIO
//ios_base::sync_with_stdio(false);
cin.tie(NULL);
  solve();
  return 0;
}