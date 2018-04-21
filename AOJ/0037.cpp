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
	bool map[11][6] = {};
	rep(i,11){
		rep(j,6){
			if(i == 0 || j == 0){
				map[i][j] = false;
				break;
			}
			if()
		}
	}

	}
	int x = 1, y = 0;
	int d = 1;
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	char dir[4] = {'U', 'R', 'D', 'L'};
	cout << dir[d];
	while(x != 0 && y != 0){

	}
}

int main(){
	solve();
	return 0;
}