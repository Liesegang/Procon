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
	int n;
	pint p1[105], p2[105];
	bool used[105] = {};
	cin >> n;
	rep(i,n){
		cin >> p1[i].first >> p1[i].second;
	}
	rep(i,n){
		cin >> p2[i].first >> p2[i].second;
	}

	sort(p2, p2+n);

	int ans = 0;
	rep(i,n){
		int x = p2[i].first, y = p2[i].second;
		int index = -1, mm = -1;

		rep(j,n){
			if(p1[j].first < x && p1[j].second < y && !used[j]){
				if(p1[j].second > mm){
					index = j;
					mm = p1[j].second;
				}
			}
		}

		if(index != -1){
				ans++;
				used[index] = true;
		}
	}
	cout << ans << endl;
}

int main(){
	solve();
	return 0;
}