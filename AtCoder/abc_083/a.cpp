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
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	A += B;
	C += D;
	if(A>C){
		cout << "Left";
	}else if(A<C){
		cout << "Right";
	}else{
		cout << "Balanced";
	}
	cout << endl;
}

int main(){
	solve();
	return 0;
}