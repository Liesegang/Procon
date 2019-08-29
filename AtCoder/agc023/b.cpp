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
  int N;
  cin >> N;

  char S[305][305];
  rep(i,N) rep(j,N) cin >> S[i][j];

  int ans = 0;
  int j=0;
  rep(i,N){
      rep(k,N){
        REP(l,k+1,N){
          if(S[(i+k)%N][(j+l)%N] != S[(i+l)%N][(j+k)%N])
            goto dbreak;
        }
      }
      ans++;
      dbreak:
        ;
  }

  cout << ans * N << endl;
}

int main(){
  solve();
  return 0;
}