#include <iostream>
#include <cstdio>
#include <bitset>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <utility>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;
using ll=long long;
using vint=vector<int>;
using pint=pair<int,int>;

const double EPS = 1e-9;
const int inf = numeric_limits<int>::max();

const int mod = 1000000000 + 7;

#define rep(i,n) for(int i=0;i<int(n);++i)
#define rrep(i,n) for(int i=int(n-1);i>=0;--i)
#define REP(i,a,b) for(int i=int(a);i<int(b);++i)
#define RREP(i,a,b) for(int i=int(b-1);i>=int(a);--i)
#define SHOW(a) cout << #a << " = " << a << endl
#define ARR(a,n) for(int i=0;i<int(n);++i) cout << #a << "[" << i << "]" << " = " << a[i] << endl

ll nCr(int n, int k){
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    ll result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
        result %= mod;
    }
    return result;
}

ll fact(int x){
  ll ans = 1;
  for (int i = 1; i <= x; ++i)
  {
      ans *= i;
      ans %= mod;
  }

  return ans;
}

void solve(){
  int N;
  cin >> N;

  ll ans = 0;

  if(N % 2 == 0){
    ll last = 0;
    ans += N/2 % mod;
    last = 1;
    REP(i, N/2+1, N){
      ll n = (fact(i) - last);
      for(int j = 1; j < 2 * N - 1; j++){
        n += fact(i) * nCr(N/2 - 2, j);
      }
      ans += n * i % mod;
      ans %= mod;
      last = n;
    }
  }else{
    ans = 0;
  }

  cout << ans << endl;
}

int main(){
  solve();
  return 0;
}