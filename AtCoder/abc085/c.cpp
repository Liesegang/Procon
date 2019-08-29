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
	int N, Y;
	cin >> N >> Y;
	for(int i = 0; i < N+1; i++){
		for(int j = 0; j < N+1; j++){
			int k = N - i - j;
			if(10000 * i + 5000 * j + 1000 * k == Y && k >= 0){
				printf("%d %d %d\n", i, j, k);
				return;
			}
			if(10000 * i + 5000 * j > Y)
				break;
		}
		if(10000 * i > Y)
			break;
	}
	printf("-1 -1 -1\n");
}

int main(){
	solve();
	return 0;
}