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

ll score(vector<ll>& t, ll n) {
  ll d[10] = {};
  for(auto i : t) d[i]++;
  d[n]++;
  ll ret = 0;
  REP(i, 1, 10) {
    ret += i * pow(10, d[i]);
  }
  return ret;
}

void solve(){
  ll k;
  cin >> k;
  string s, t;
  cin >> s >> t;

  vector<ll> left(10, k);
  vector<ll> tt, ss;
  rep(i, 4) {
    left[s[i] - '0']--; ss.push_back(s[i] - '0');
    left[t[i] - '0']--; tt.push_back(t[i] - '0');
  }

  ll all = 0, win = 0;
  REP(i, 1, 10) {
    REP(j, 1, 10) {
      if(i == j && left[i] < 2) continue;
      if(left[i] < 1 || left[j] < 1) continue;
      ll count = 0;
      if(i == j) {
        count = left[i] * (left[j] - 1);
      } else {
        count = left[i] * left[j];
      }
      all += count;
      if(score(ss, i) > score(tt, j)) {
        win += count;
      }
    }
  }

  cout << fixed << setprecision(10);
  cout << double(win) / all << endl;
}

int main(){
// FastIO
//ios_base::sync_with_stdio(false);
cin.tie(NULL);
  solve();
  return 0;
}