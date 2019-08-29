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

bool judge(int c[3][3]){
	if(c[0][0] - c[0][1] != c[1][0] - c[1][1])
		return false;
	if(c[1][0] - c[1][1] != c[2][0] - c[2][1])
		return false;

	if(c[0][1] - c[0][2] != c[1][1] - c[1][2])
		return false;
	if(c[1][1] - c[1][2] != c[2][1] - c[2][2])
		return false;

	if(c[0][0] - c[1][0] != c[0][1] - c[1][1])
		return false;
	if(c[0][1] - c[1][1] != c[0][2] - c[1][2])
		return false;

	if(c[1][0] - c[2][0] != c[1][1] - c[2][1])
		return false;
	if(c[1][1] - c[2][1] != c[1][2] - c[2][2])
		return false;
	return true;
}

void solve(){
	int c[3][3];
	rep(i,3)
		rep(j,3)
			cin >> c[i][j];
	if(judge(c))
		cout << "Yes";
	else
		cout << "No";
	cout << endl;

}

int main(){
	solve();
	return 0;
}