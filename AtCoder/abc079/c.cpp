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

char sign(int i, int n){
	return (i & (1 << n)) ? '+' : '-';
}

void solve(){
	char a[4];
	cin >> a[0] >> a[1] >> a[2] >> a[3];

	int i = 0;
	while(!(i & (1 << 3))){
		int tmp = a[0] - '0';
		rep(j,3){
			if(i & (1 << j)){
				tmp += a[j+1] - '0';
			}else{
				tmp -= a[j+1] - '0';
			}
		}
		if(tmp == 7){
			break;
		}
		i++;
	}

	cout << a[0] << sign(i,0) << a[1] << sign(i,1) << a[2] << sign(i,2) << a[3] << "=7" << endl;
}

int main(){
	solve();
	return 0;
}