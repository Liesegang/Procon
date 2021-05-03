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
#define REP(i,a,b) for(int i=int(a);i<int(b);++i)
#define SHOW(a) cout << #a << " = " << a << endl
#define ARR(a,i,n) for(int i=0;i<int(n);++i) cout << #a << "[" << i << "]" << " = " << a[i] << endl

void solve(){
	int n,m;
	cin >> n >> m;

	bool r[13][13] = {false};

	rep(i,m){
    int t, u;
		cin >> t >> u;
    t--;u--;
    r[t][u] = true;
	}

  int ans = 0;
  for(int i = 0; i < (1 << n);i++){
    int t = bitset<32>(i).count();
    if(t <= ans)
      continue;

    for(int a = 0; a < n; a++){
      for(int b = a+1; b < n; b++){
        if(i & (1 << a) && i & (1 << b) && !r[a][b]){
          goto dbr;
        }
      }
    }

    ans = t;
    dbr:;
  }

  cout << ans << endl;
}

int main(){
	solve();
	return 0;
}