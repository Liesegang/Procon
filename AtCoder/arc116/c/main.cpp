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

const ll mod = 998244353;

template <typename T> vector<pair<T, T>> prime_factor(T n) {
  vector<pair<T, T>> ret;
  for (T i = 2; i * i <= n; i++) {
    if (n % i != 0)
      continue;
    T tmp = 0;
    while (n % i == 0) {
      tmp++;
      n /= i;
    }
    ret.push_back(make_pair(i, tmp));
  }
  if (n != 1)
    ret.push_back(make_pair(n, 1));
  return ret;
}

vector<long long> fact_inv, inv;
/*  init_nCk :二項係数のための前処理
    計算量:O(k)
*/
void init_nCk(int SIZE) {
  fact_inv.resize(SIZE + 5);
  inv.resize(SIZE + 5);
  fact_inv[0] = fact_inv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < SIZE + 5; i++) {
    inv[i] = mod - inv[mod % i] * (mod / i) % mod;
    fact_inv[i] = fact_inv[i - 1] * inv[i] % mod;
  }
}
/*  nCk :modでの二項係数を求める(前処理 int_nCk が必要)
    計算量:O(k)
*/
long long nCk(int n, int k) {
  assert(!(n < k));
  assert(!(n < 0 || k < 0));
  long long ans = 1;
  for (int i = n; i >= n - k + 1; i--) {
    ans *= i;
    ans %= mod;
  }
  return ans * fact_inv[k] % mod;
}

ll f(ll k, ll n) {
  vector<pair<ll, ll>> fact = prime_factor(k);
  ll ans = 1;
  for (auto p : fact) {
    ans *= nCk(n + p.second - 1, p.second);
    ans %= mod;
  }
  return ans;
}

void solve() {
  ll n, m;
  cin >> n >> m;
  init_nCk(n + 100);
  ll ans = 0;
  REP(i, 1, m + 1) {
    ans += f(i, n);
    ans %= mod;
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