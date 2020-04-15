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


void solve(){
  string S;
  cin >> S;

  int Q;
  cin >> Q;

  string pre = "";
  string post = "";

  bool direction = false;
  rep(i, Q){
    int t, f;
    char c;

    cin >> t;
    switch(t){
      case 1:
        direction ^= 1;
        break;

      case 2:
        cin >> f >> c;
        if(f == 1 && direction == false || f == 2 && direction == true){
          pre += c;
        }else if(f == 1 && direction == true || f == 2 && direction == false){
          post += c;
        }
        break;

      default:
        break;
    }
  }
  if(direction == false){
    reverse(ALL(pre));
    cout << pre << S << post << endl;
  }else{
    reverse(ALL(S));
    reverse(ALL(post));
    cout << post << S << pre << endl;
  }
}

int main(){
// FastIO
//ios_base::sync_with_stdio(false);
cin.tie(NULL);
  solve();
  return 0;
}