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
  int m;
  cin >> m;

  if(m < 100){
    printf("00");
  }else if(m <= 5000){
    printf("%02d", m / 100);
  }else if(m <= 30000){
    printf("%d", 50 + m / 1000);
  }else if(m <= 70000){
    printf("%d",(m / 1000 - 30) / 5 + 80);
  }else{
    printf("89");
  }
  printf("\n");
}

int main(){
  solve();
  return 0;
}