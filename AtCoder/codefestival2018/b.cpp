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

void solve(){
  int n,m,a,b;
  cin >> n >> m >> a >> b;

  bool A[105] = {};

  int l,r;
  rep(i,m){
    cin >> l >> r;
    l--;
    r--;
    for(int i = l; i <= r; i++)
      A[i] = true;
  }

  int sum = 0;
  rep(i,n){
    if(A[i]) sum++;
  }

  cout << a * sum + b * (n-sum) << endl;

}

int main(){
  solve();
  return 0;
}