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
	int num[3];
	cin >> num[0] >> num[1] >> num[2];
	sort(num, num+3);

	int res = 0;
	int tmp = 0;

	tmp = num[2] - num[1];
	num[0] += tmp;
	num[1] += tmp;
	res += tmp;

	tmp = (num[2] - num[0]) / 2;
	num[0] += tmp * 2;
	res += tmp;

	if(num[0] != num[2]){
		res += 2;
	}

	cout << res << endl;
}

int main(){
	solve();
	return 0;
}