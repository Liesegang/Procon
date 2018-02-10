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
	string a, b;
	cin >> a >> b;
	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());
	if(a < b){
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