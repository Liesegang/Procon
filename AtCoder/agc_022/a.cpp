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

string next(string s){
	bool list[26] = {};

	if(s.size() < 26){
		for(auto t : s){
			list[t-'a'] = true;
		}
		rep(i,26){
			if(!list[i]){
				return s + char(i+'a');
			}
		}
	}else{
		for(int i = 25; i >= 0; i--){
			list[s[i] - 'a'] = true;
			for(int j = s[i] - 'a' + 1; j <= 25; j++){
				if(list[j]){
					return s.substr(0,i) + char(j + 'a');
				}
			}
		}
	}

	cout << "ERROR:ERROR" << endl;
	return "-2";
}


void solve(){
	string S;
	cin >> S;
	bool list[26] = {};

	if(S == "zyxwvutsrqponmlkjihgfedcba"){
		cout << -1 << endl;
		return;
	}

	cout << next(S) << endl;
	return;
}

int main(){
	solve();
	return 0;
}