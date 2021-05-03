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

unordered_set<string> exist;

void solve() {
  int n, m;
  cin >> n;
  int zax[205], zay[205];
  rep(i, n) cin >> zax[i] >> zay[i];
  cin >> m;
  int alx[1005], aly[1005];
  rep(i, m) cin >> alx[i] >> aly[i];
  rep(i, m) exist.insert(to_string(alx[i]) + "," + to_string(aly[i]));

  rep(i, m) {
    int dx = alx[i] - zax[0];
    int dy = aly[i] - zay[0];
    int ok = true;
    REP(j, 1, n) {
      if (exist.count(to_string(zax[j] + dx) + "," + to_string(zay[j] + dy)) !=
          1) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << dx << " " << dy << endl;
      return;
    }
  }
}

int main() {
  // FastIO
  // ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}