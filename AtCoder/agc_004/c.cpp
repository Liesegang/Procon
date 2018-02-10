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
	int H, W;
	bool r[505][505] = {};
	bool b[505][505] = {};
	cin >> H >> W;

	rep(i, H)
		rep(j,W){
			if(i == 0){
				r[i][j] = true;
			}else if(i == H-1){
				b[i][j] = true;
			}else{
				if(j % 2){
					r[i][j] = true;
				}else{
					b[i][j] = true;
				}
			}
		}

	rep(i, H)
		rep(j,W){
			char t;
			cin >> t;
			if(t == '#'){
				r[i][j] = true;
				b[i][j] = true;
			}
		}

	rep(i, H){
		rep(j,W){
			if(r[i][j])
				cout << '#';
			else
				cout << '.';
		}
		cout << endl;
	}

	cout << endl;

	rep(i, H){
		rep(j,W){
			if(b[i][j])
				cout << '#';
			else
				cout << '.';
		}
		cout << endl;
	}
}

int main(){
	solve();
	return 0;
}