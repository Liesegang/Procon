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
const int infinity = numeric_limits<int>::max();

#define rep(i,n) for(int i=0;i<int(n);++i)
#define REP(i,a,b) for(int i=int(a);i<int(b);++i)
#define SHOW(a) cout << #a << " = " << a << endl
#define ARR(a,i,n) for(int i=0;i<int(n);++i) cout << #a << "[" << i << "]" << " = " << a[i] << endl

void solve(){
	int H, W;
	int n[4] = {infinity,infinity,infinity,infinity};
	cin >> H >> W;
	//横三分割
	if(H >= 3){
		if(H % 3){
			n[0] = W;
		}else{
			n[0] = 0;
		}
	}
	//縦三分割
	if(W >= 3){
		if(W % 3){
			n[1] = H;
		}else{
			n[1] = 0;
		}
	}

	//縦横
	if(W % 3 == 1){
		if(H % 2){
			n[2] = max(W / 3 * 2, W / 3 + H / 2) + 1;
		}else{
			n[2] = H / 2;
		}
	}else if(W % 3 == 2){
		if(H % 2){
			n[2] = max(W / 3 * 2, W / 3 + H / 2) + 1;
		}else{
			n[2] = H / 2;
		}
	}

	//縦横
	if(H % 3 == 1){
		if(W % 2){
			n[3] = max(H / 3 * 2, H / 3 + W / 2) + 1;
		}else{
			n[3] = W / 2;
		}
	}else if(H % 3 == 2){
		if(W % 2){
			n[3] = max(H / 3 * 2, H / 3 + W / 2) + 1;
		}else{
			n[3] = W / 2;
		}
	}

	cout << *min_element(n, n+4) << endl;
}

int main(){
	solve();
	return 0;
}