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
	cin >> n;
	int a[200000 + 5], b[200000 + 5];
	rep(i,n) cin >> a[i]; rep(i,n) cin >> b[i];

	int ans = 0;
	REP(i, 1, 29){
		printf("Culcurating %d bit...\n", i); 					//debug

		vector <int> v;
		rep(j,n){
			v.push_back(b[j] & (~(0xffffffff << i)));
		}
		sort(v.begin(), v.end());

		printf("  v is...\n"); 												//debug
		rep(j,n){ 																		//debug
			printf("    v[%d] = %d\n", j, v[j]); 				//debug
		} 																						//debug

		printf("  num is...\n"); 											//debug
		int tmp = 0;
		rep(j,n){
			printf("    a[%d] = %d ,", j, a[j] & (~(0xffffffff << i)));

			int u = (1 << i) - (a[j] & (~(0xffffffff << i)));
			int l = (1 << (i-1)) - (a[j] & (~(0xffffffff << i)));
			int w = (3 << (i-1)) - (a[j] & (~(0xffffffff << i)));

			if(a[j] & (1 << (i-1))){
				tmp ^= ((lower_bound(v.begin(), v.end(), u) - v.begin()) + (v.end() - lower_bound(v.begin(), v.end(), w))) & 1;
				printf("range = 0~%d, num = %ld\n", u, (lower_bound(v.begin(), v.end(), u) - v.begin()));
			}else{
				tmp ^= (lower_bound(v.begin(), v.end(), u) - lower_bound(v.begin(), v.end(), l)) & 1;
				printf("range = %d~%d, num = %ld\n", l, u, (lower_bound(v.begin(), v.end(), u) - lower_bound(v.begin(), v.end(), l)));
			}
		}

		printf("  bit %d is %d\n", i, tmp);

		ans += tmp << (i-1);
	}
	cout << ans << endl;
}

int main(){
	solve();
	return 0;
}