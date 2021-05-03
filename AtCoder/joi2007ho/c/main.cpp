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

pll rot90(pll p1, pll p2) {
  pll ret;
  ret.first = p2.first + (p1.second - p2.second);
  ret.second = p2.second - (p1.first - p2.first);
  return ret;
}

pll rot270(pll p1, pll p2) {
  pll ret;
  ret.first = p2.first - (p1.second - p2.second);
  ret.second = p2.second + (p1.first - p2.first);
  return ret;
}

void solve() {
  int n;
  cin >> n;
  vector<pll> a(n);
  set<pll> b;
  rep(i, n) {
    int s, t;
    cin >> s >> t;
    a[i] = {s, t};
    b.insert({s, t});
  }
  ll ans = 0;
  rep(i, n) {
    rep(j, i + 1) {
      auto p1 = a[i];
      auto p2 = a[j];
      pll p3;
      if (b.count(p3 = rot90(p1, p2)) > 0 && b.count(rot90(p2, p3)) > 0) {
        ans = max(ans, (p1.first - p2.first) * (p1.first - p2.first) +
                           (p1.second - p2.second) * (p1.second - p2.second));
      }
      if (b.count(p3 = rot270(p1, p2)) > 0 && b.count(rot270(p2, p3)) > 0) {
        ans = max(ans, (p1.first - p2.first) * (p1.first - p2.first) +
                           (p1.second - p2.second) * (p1.second - p2.second));
      }
    }
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