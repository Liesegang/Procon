#include <iostream>
using namespace std;

void solve(){
	int dp[1005][1005] = {}; //[a][b]
	int a[1005], b[1005];
	int A, B;

	cin >> A >> B;

	for(int i = 0; i < A; i++)
		cin >> a[A-i];

	for(int i = 0; i < B; i++)
		cin >> b[B-i];

	for(int i = 0; i <= A; i++){
		for(int j = 0; j <= B; j++){
			int turn = (A + B - i - j + 1) % 2; // 1: mine, 0: the other's
			if(i == 0 && j == 0)
				continue;

			if(i == 0){
				dp[i][j] = dp[i][j-1] + b[j] * turn;
				continue;
			}

			if(j == 0){
				dp[i][j] = dp[i-1][j] + a[i] * turn;
				continue;
			}

			if(turn){
				dp[i][j] = max(dp[i-1][j] + a[i], dp[i][j-1] + b[j]);
			}else{
				dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	cout << dp[A][B] << endl;
}

int main(){
	solve();
	return 0;
}