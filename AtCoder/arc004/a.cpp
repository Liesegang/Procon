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
	int N;
	cin >> N;
	vector<pair<int,int> > p;
	rep(i,N){
		int x, y;
		cin >> x >> y;
		p.push_back(make_pair(x,y));
	}

	vector<double> d;
	for(auto a : p){
		for(auto b : p){
			d.push_back(sqrt(pow(a.first - b.first,2) + pow(a.second - b.second,2)));
		}
	}

	printf("%.6lf\n", *max_element(d.begin(), d.end()));
}

int main(){
	solve();
	return 0;
}