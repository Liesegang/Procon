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
	bool map[9][9] = {};
	rep(i,8)
		rep(j,8){
			char t;
			cin >> t;
			if(t == '0'){
				map[i][j] = false;
			}else{
				map[i][j] = true;
			}
		}

	bool flag = false;
	rep(i,8){
		rep(j,8){
			if(map[i][j]){
				flag = true;
				if(map[i][j+1]){ // A C E G
					if(map[i+1][j]){ // A G
						if(map[i+1][j+1]){ // A
							cout << "A";
						}else{
							cout << "G";
						}
					}else{ // C E
						if(map[i+1][j+1]){
							cout << "E";
						}else{
							cout << "C";
						}
					}
				}else{
					if(map[i+1][j+1]){
						cout << "F";
					}else{
						if(map[i+2][j]){
							cout << "B";
						}else{
							cout << "D";
						}
					}
				}
			}
			if(flag) break;
		}
		if(flag) break;
	}
	cout << endl;
}

int main(){
	char buf[2];
	while(cin.read(buf,2)){
		cin.unget();
		cin.unget();
		solve();
	}

	return 0;
}