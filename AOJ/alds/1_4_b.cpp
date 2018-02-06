#include <iostream>

using namespace std;

bool bin_search(int S[], int n, int t){
	int l, r, m;
	
	l = 0;
	r = n;
	m = (l + r) / 2;

	while(r - l > 0){
		if(S[m] > t){
			r = m;
		}else if(S[m] < t){
			l = m + 1;
		}else{
			return true;
		}
		m = (l + r) / 2;
	}

	return false;
}

int main(){
	int S[100005];
	int n, q, t;
	int ans = 0;

	cin >> n;
	for(int i=0; i < n; i++)
		cin >> S[i];

	cin >> q;
	for(int i = 0; i < q; i++){
		cin >> t;
		if(bin_search(S, n, t))
			++ans;
	}

	cout << ans << endl;

	return 0;
}

