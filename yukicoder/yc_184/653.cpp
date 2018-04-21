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
#include <regex>

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

bool judge(){
	std::regex re1(R"(^1[345]*[234]$)");
	std::regex re2(R"(^[67]*[78][345]*[234]$)");

	string s;
	cin >> s;
	return std::regex_match(s, re1) || std::regex_match(s, re2);
}

void solve(){
	if(judge()){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
}

int main(){
	solve();
	return 0;
}