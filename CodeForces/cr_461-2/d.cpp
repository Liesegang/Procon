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

ll count(string a){
	ll s = 0, t = 0;
	for(char c : a){
		if(c == 's'){
			s++;
		}else{
			t+=s;
		}
	}
	return t;
}

bool cmp(string a, string b){
	return count(a+b) > count(b+a);
}

void solve(){
	int n;
	const int MAX_N=1e5+5;
	string s[MAX_N];
	cin >> n;
	rep(i,n) cin >> s[i];
	sort(s,s+n,cmp);
	string all="";
	rep(i,n) all += s[i];
	cout << count(all) << endl;
}

int main(){
	solve();
	return 0;
}