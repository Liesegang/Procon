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
template<typename T> bool chmin(T& a, const T& b){
  if (a > b) return a = b, true; else return false;
}

template<typename T> bool chmax(T& a, const T& b){
  if (a < b) return a = b, true; else return false;
}

std::vector<int> Eratosthenes(const int N){
  std::vector<bool> is_prime(N + 1);
  for(int i = 0; i <= N; i++) is_prime[i] = true;
  std::vector<int> P;
  for(int i = 2; i <= N; i++){
    if(is_prime[i]){
      for(int j = 2 * i; j <= N; j += i) is_prime[j] = false;
      P.emplace_back(i);
    }
  }
  return P;
}

bool IsPrime(int num){
  if (num < 2) return false;
  else if (num == 2) return true;
  else if (num % 2 == 0) return false;

  double sqrtNum = sqrt(num);
  for (int i = 3; i <= sqrtNum; i += 2) if (num % i == 0) return false;
  return true;
}

void solve(){
  ll A, B;
  cin >> A >> B;

  ll gcdab = gcd(A, B);
  vector<int> primes = Eratosthenes(ceil(sqrt(gcdab)));

  int ans = 1;
  for(int p : primes){
    if(gcdab % p == 0){
      ans++;
    }
    while(gcdab % p == 0){
      gcdab /= p;
    }
  }

  if(gcdab != 1)
    ans++;

  cout << ans << endl;
}

int main(){
// FastIO
//ios_base::sync_with_stdio(false);
cin.tie(NULL);
  solve();
  return 0;
}