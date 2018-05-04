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
    }
    return result;
}

void solve(){
  int N;
  cin >> N;
  int a[2 * 100000 + 5];
  ll sum[2 * 100000 + 5];
  rep(i,N) cin >> a[i];

  ll s = 0;
  rep(i,N){
    s += a[i];
    sum[i] = s;
  }

  map<ll,ll> mm;
  rep(i,N){
    mm[sum[i]]++;
  }

  ll ans = mm[0];
  for(auto t : mm){
    int i = t.second;
    if(i >= 2)
      ans += nCr(i, 2);
  }

  cout << ans << endl;
}

int main(){
  solve();
  return 0;
}