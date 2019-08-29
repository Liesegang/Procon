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

bool isBeki(int n){
  if(n==1){
    return true;
  }
  int so[1000]={};

  while(n!=1){
    for(int i = 2; i < n+1; i++){
      if(n % i == 0){
        so[i]++;
        n /= i;
        break;
      }
    }
  }

  int su=0, m=99999;
  for(int i = 0; i < 1000; i++){
    if(so[i] != 0)
      m = min(m,so[i]);
  }

  for(int i = 0; i < 1000; i++){
    if(so[i] % m != 0){
      return false;
    }
  }
  return m >= 2;
}

void solve(){
  int X;
  cin >> X;

  for(int i = X; i >= 1; i--){
    if(isBeki(i)){
      cout << i << endl;
      return;
    }
  }
}

int main(){
  solve();
  return 0;
}