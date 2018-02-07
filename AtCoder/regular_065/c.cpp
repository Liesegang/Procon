#include <iostream>
#include <string>
using namespace std;

void solve(){
	string S;
	cin >> S;

	int k = 0;
	while(k < S.length()){
		if(S.substr(k, 11) == "dreameraser"){
			k += 11;
		}else if(S.substr(k, 10) == "dreamerase"){
			k += 10;
		}else if(S.substr(k, 7) == "dreamer"){
			k += 7;
		}else if(S.substr(k, 5) == "dream"){
			k += 5;
		}else if(S.substr(k, 6) == "eraser"){
			k += 6;
		}else if(S.substr(k, 5) == "erase"){
			k += 5;
		}else{
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	return;
}

int main(){
	solve();
	return 0;
}