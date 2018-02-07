#include <iostream>
using namespace std;

void solve(){
	int A, B, C, X;
	int count = 0;
	cin >> A >> B >> C >> X;

	for(int i = 0; i <= A; i++){
		for(int j = 0; j <= B; j++){
			for(int k = 0; k <= C; k++){
				if(i * 500 + j * 100 + k * 50 == X){
					count++;
					//cout << i << "," << j << "," << k << endl;
				}
				else if(i * 500 + j * 100 + k * 50 > X)
					break;
			}
			if(i * 500 + j * 100 > X)
				break;
		}
		if(i * 500 > X)
				break;
	}
	cout << count << endl;
}

int main(){
	solve();
	return 0;
}