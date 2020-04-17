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


void solve(){
  int N, X, Y;
  cin >> N >> X >> Y;

  int count[2*1000 + 5] = {};

  X--;
  Y--;

  rep(i, N){
    int dist[2*1000 + 5];
    memset(dist, -1, (2 * 1000 + 5) * sizeof(int));
    dist[i] = 0;

    queue<int> que;
    que.push(i);
    while(!que.empty()){
      int p = que.front(); que.pop();

      if(p-1 >= 0 && dist[p-1] == -1){
        dist[p-1] = dist[p] + 1;
        que.push(p-1);
      }
      if(p+1 < N && dist[p+1] == -1){
        dist[p+1] = dist[p] + 1;
        que.push(p+1);
      }
      if(p == X && dist[Y] == -1){
        dist[Y] = dist[p] + 1;
        que.push(Y);
      }
      if(p == Y && dist[X] == -1){
        dist[X] = dist[p] + 1;
        que.push(X);
      }
    }

    rep(j, N){
      count[dist[j]]++;
    }
  }

  REP(i, 1, N){
    cout << count[i] / 2 << endl;
  }
}

int main(){
// FastIO
//ios_base::sync_with_stdio(false);
cin.tie(NULL);
  solve();
  return 0;
}