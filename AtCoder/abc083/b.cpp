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

using namespace std;
using ll=long long;
using vint=vector<int>;
using pint=pair<int,int>;

const double EPS = 1e-9;

#define rep(i,n) for(int i=0;i<int(n);++i)
#define REP(i,a,b) for(int i=int(a);i<int(b);++i)
#define SHOW(a) cout << #a << " = " << a << endl;

void solve(){
	int n, a, b, ans = 0;
	cin >> n >> a >> b;
	rep(i,n+1){
		string str = to_string(i);
		int sum = 0;
		for(char t : str){
			sum += t - '0';
		}
		if(a <= sum && sum <= b){
			ans += i;
		}
	}

	cout << ans << endl;
}

int main(){
	solve();
	return 0;
}