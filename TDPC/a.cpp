#include <iostream>
#include <bitset>

using namespace std;

void solve(){
	int n;
	int sum = 0;

	bitset<100*100 + 5> dp;
	dp[0] = true;

	cin >> n;

	for(int i = 0; i < n; i++){
		int p;
		cin >> p;
		sum +=p;

		for(int j = sum - 1; j >=0; --j){
			if(dp[j])
				dp[j+p] = true;
		}
	}
	cout << dp.count() << endl;
}

int main(){
	solve();
	return 0;
}