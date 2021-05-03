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

void solve() {
  int n, k;
  cin >> n >> k;
  int w[1005], p[1005];
  rep(i, n) { cin >> w[i] >> p[i]; }

  double left = 0.0f;
  double right = 100.0f;
  rep(i, 100) {
    double mid = (left + right) / 2.0f;
    double diff[1005];
    rep(j, n) diff[j] = double(w[j]) * (mid - double(p[j])) / 100.0f;
    sort(diff, diff + n);
    double s = 0.0;
    rep(j, k) s += diff[j];

    if (s <= 0) {
      left = mid;
    } else {
      right = mid;
    }
  }

  cout << fixed << setprecision(10);
  cout << left << endl;
}

int main() {
  // FastIO
  // ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}