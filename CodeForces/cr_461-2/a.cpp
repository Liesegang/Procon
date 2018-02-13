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
	int x, y;
	cin >> x >> y;


	if(x >= 1 && y >= 2 && (x - y + 1) % 2 == 0 && x >= y - 1){
		cout << "Yes";
	}else if(x == 0 && y == 1){
		cout << "Yes";
	}else{
		cout << "No";
	}
	cout << endl;
}

int main(){
	solve();
	return 0;
}