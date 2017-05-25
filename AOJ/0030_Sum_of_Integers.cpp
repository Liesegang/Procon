#include <iostream>
using namespace std;

int dfs(int n, int s, int i){
  if(!n && !s)
    return 1;
  if(n <= 0 || s < 0 || i > 9 || i > s)
    return 0;
  return dfs(n-1, s-i, i+1) + dfs(n, s, i+1);
}

int main(){
  int n, s;
  while(cin >> n >> s, n || s){
    cout << dfs(n, s, 0) << endl;
  }
}
