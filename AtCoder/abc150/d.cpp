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

int cnt(int a){
  int ret = 0;
  while(a % 2 == 0){
    a /= 2;
    ret++;
  }

  return ret;
}

void solve(){
  ll N, M;
  cin >> N >> M;
  ll a[100000 + 5] = {};
  rep(i, N){
    ll t;
    cin >> t;
    a[i] = t / 2;
  }

  ll count[100000 + 5] = {};
  rep(i, N){
    count[i] = cnt(a[i]);
  }

  rep(i, N){
    if(count[i] != count[0]){
      cout << "0" << endl;
      exit(0);
    }
  }

  ll glcm = a[0];
  rep(i, N){
    glcm = lcm(glcm, a[i]);
  }

  cout << fixed << setprecision(0) << ceil(M / glcm / 2.0) << endl;

}

int main(){
// FastIO
//ios_base::sync_with_stdio(false);
cin.tie(NULL);
  solve();
  return 0;
}