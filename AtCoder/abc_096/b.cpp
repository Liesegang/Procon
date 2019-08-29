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
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  int k;
  cin >> k;
 
  sort(a,a+3);
 
  cout << a[0] + a[1] + pow(2,k) * a[2] << endl;
}
 
int main(){
  solve();
  return 0;
}