#include <iostream>
#include <cmath>
using namespace std;

double pos(int p, int q){
	return 1.0 / (1.0 + pow(10.0, (q - p) / 400.0));
}

void solve(){
	int K, N;
	double dp[1024+5][10+5] = {};
	int R[1024+5];

	cin >> K;
	N = 1 << K;

	for(int i = 0; i < N; i++)
		cin >> R[i];

	for(int i = 0; i < N; i++)
		dp[i][0] = 1;

	for(int j = 1; j <= K; j++)
		for(int i = 0; i < N; i++){
			double sum = 0;
			int begin = (i & (0xffffffff << (j-1))) ^ (0x1 << (j-1));
			int end = begin + (1 << (j-1));

			for(int k = begin; k < end; k++){
				sum += dp[k][j-1] * pos(R[i], R[k]);
				//printf("%d, %d, %lf, %lf\n", i, k, sum, pos(0, 1));
			}
			dp[i][j] = dp[i][j-1] * sum;
		}

	for(int i = 0; i < N; i++)
		printf("%.9lf\n", dp[i][K]);
}

int main(){
	solve();
	return 0;
}