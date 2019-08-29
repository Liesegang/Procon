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
  int h, w;
  cin >> h >> w;

  char s[51][51];

  rep(i,h) rep(j,w) cin >> s[i][j];


  int dx[]={0,1,0,-1};
  int dy[]={1,0,-1,0};

  bool ok=true;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(s[i][j] == '#'){
        bool flag = false;
        for(int k=0; k < 4; k++){
          if(0 <= i+dx[k] && i+dx[k] < h && 0 <= j+dy[k] && j+dy[k] < w && s[i+dx[k]][j+dy[k]] == '#'){
            flag = true;
            break;
          }
        }
        if(!flag){
          ok=false;
          goto end;
        }
      }
    }
  }

  end:
  if(ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}

int main(){
  solve();
  return 0;
}