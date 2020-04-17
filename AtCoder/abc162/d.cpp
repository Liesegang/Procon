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
  int N;
  string S;
  cin >> N >> S;

  ll sum = 0;
  int r = 0, g = 0, b = 0;
  rep(i,N){
    if(S[i] == 'R'){
      r++;
      continue;
    }
    if(S[i] == 'G'){
      g++;
      continue;
    }
    if(S[i] == 'B'){
      b++;
      continue;
    }
  }

  rep(i, N){
    if(S[i] == 'R'){
      r--;
    }else if(S[i] == 'G'){
      g--;
    }else if(S[i] == 'B'){
      b--;
    }

    int rr = r;
    int gg = g;
    int bb = b;
    REP(j, i+1, N-1){
      if(S[j] == 'R'){
        rr--;
      }else if(S[j] == 'G'){
        gg--;
      }else if(S[j] == 'B'){
        bb--;
      }
      if(S[i] != S[j]){
        //cout << i << "," << j << endl;
        //cout << rr << ", " << gg << ", " << bb << endl << endl;
        if(S[i] != 'R' && S[j] != 'R')
          sum += rr;
        else if(S[i] != 'G' && S[j] != 'G')
          sum += gg;
        else if(S[i] != 'B' && S[j] != 'B')
          sum += bb;

        if(j - i + j < N && S[j - i + j] != S[i] && S[j - i + j] != S[j]){
          sum--;
        }
      }
    }
  }

  cout << sum << endl;
}

int main(){
  // FastIO
  //ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}