#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;

// Type alias
using ll = long long;
using ld = double;

using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
using ti3 = tuple<int, int, int>;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpi = vector<pi>;
using vpll = vector<ll>;
using vpld = vector<ld>;
using vti3 = vector<ti3>;

// Constants
const double EPS = 1e-9;
const int inf = numeric_limits<int>::max() / 2;
const ll mod = 1e9 + 7;

// Macro
#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define rrep(i, n) for (int i = int(n - 1); i >= 0; --i)
#define REP(i, a, b) for (int i = int(a); i < int(b); ++i)
#define RREP(i, a, b) for (int i = int(b - 1); i >= int(a); --i)
#define SHOW(a) cout << #a << " = " << a << endl
#define ARR(a, n)                                                              \
  for (int i = 0; i < int(n); ++i)                                             \
  cout << #a << "[" << i << "]"                                                \
       << " = " << a[i] << endl

#define ALL(a) a.begin(), a.end()

// Funtcions
ll pow(ll base, ll i, ll mod) {
  ll a = 1;
  while (i) {
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
ll gcd(ll a, ll b) {
  while (b) {
    ll c = a % b;
    a = b;
    b = c;
  }
  return a;
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
template <typename T> bool chmin(T &a, const T &b) {
  if (a > b)
    return a = b, true;
  else
    return false;
}

template <typename T> bool chmax(T &a, const T &b) {
  if (a < b)
    return a = b, true;
  else
    return false;
}

int n, m;
vvi ma;

int dfs(int x, int y) {
  const vvi dd = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  ma[x][y] = 0;
  int tmp = 0;
  rep(i, 4) {
    int xx = x + dd[i][0];
    int yy = y + dd[i][1];
    if (xx < 0 || m <= xx || yy < 0 || n <= yy)
      continue;
    if (ma[xx][yy] == 0)
      continue;
    chmax(tmp, dfs(xx, yy));
  }
  ma[x][y] = 1;
  return tmp + 1;
}

void solve() {
  cin >> n >> m;
  ma = vvi(m, vi(n));
  rep(i, m) rep(j, n) cin >> ma[i][j];

  int ans = 0;
  rep(i, m) rep(j, n) {
    if (ma[i][j] == 1)
      chmax(ans, dfs(i, j));
  }

  cout << ans << endl;
}

int main() {
  // FastIO
  // ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}