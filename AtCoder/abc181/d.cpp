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
  int count[10] = {};
  string s;
  cin >> s;
  if(s.length() == 1){
    if((s[0] - '0') % 8 == 0){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
    return;
  }
  if(s.length() == 2){
    if(((s[0] - '0') * 10 + (s[1] - '0')) % 8 == 0 || ((s[1] - '0') * 10 + (s[0] - '0')) % 8 == 0){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
    return;
  }
  rep(i, s.length()){
    char c = s[i];
    count[c - '0']++;
  }
  for(int i = 0; i < 1000; i+=8){
    char buf[4] = "000";
    sprintf(buf, "%03d", i);
    int count_div[10] = {};
    count_div[buf[0] - '0']++;
    count_div[buf[1] - '0']++;
    count_div[buf[2] - '0']++;
    bool flag = true;
    rep(j, 10){
      if(count[j] < count_div[j]){
        flag = false;
        break;
      }
    }
    if(flag){
      cout << "Yes" << endl;
      return;
    }
  }
  cout << "No" << endl;
}

int main(){
// FastIO
//ios_base::sync_with_stdio(false);
cin.tie(NULL);
  solve();
  return 0;
}