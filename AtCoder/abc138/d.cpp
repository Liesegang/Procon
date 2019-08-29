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

vector<int> edges[2 * 100000 + 5];
int value[2 * 100000 + 5];
int tmp[2 * 100000 + 5];

void dfs(int n, int sum, int from){
  value[n] = sum + tmp[n];
  for(int i : edges[n]){
    if(i != from){
      dfs(i, value[n], n);
    }
  }
}

void solve(){
  int n, q;
  cin >> n >> q;
  rep(i, n-1){
    int a, b;
    cin >> a >> b;
    a--;b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  rep(i, q){
    int p, x;
    cin >> p >> x;
    p--;
    tmp[p] += x;
  }

  dfs(0, 0, -1);

  rep(i, n){
    cout << value[i];
    if(i != n-1)
      cout << " ";
  }
  cout << endl;
}

int main(){
// FastIO
//ios_base::sync_with_stdio(false);
cin.tie(NULL);
  solve();
  return 0;
}