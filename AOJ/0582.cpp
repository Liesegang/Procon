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
	int a[3];
	int e=0, t=0, d=0;
	while(true){
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a+3);
		if(a[2] >= a[0] + a[1]){
			printf("%d %d %d %d\n", e+t+d, t, e, d);
			break;
		}
		if(abs(a[2] * a[2] - a[1] * a[1] - a[0] * a[0]) < EPS)
			t++;
		else if(a[2] * a[2] - a[1] * a[1] - a[0] * a[0] < 0)
			e++;
		else
			d++;
	}
}

int main(){
	solve();
	return 0;
}