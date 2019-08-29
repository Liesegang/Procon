#include <bits/stdc++.h>
using namespace std;

void solve(){
  int a, b;
  cin >> a >> b;
  cout << b / a + bool(b % a) << endl;
}

int main() {
  solve();
  return 0;
}