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
#define rrep(i,n) for(int i=int(n-1);i>=0;--i)
#define REP(i,a,b) for(int i=int(a);i<int(b);++i)
#define RREP(i,a,b) for(int i=int(b-1);i>=int(a);--i)
#define SHOW(a) cout << #a << " = " << a << endl
#define ARR(a,n) for(int i=0;i<int(n);++i) cout << #a << "[" << i << "]" << " = " << a[i] << endl

void solve(){
  string a, b;
  cin >> a >> b;
  bool win = true;
  for(int i = 0; i < a.size(); i++){
    if(a[i] != '@' && b[i] != '@' && a[i] != b[i]){
      win = false;
      break;
    }else if(a[i] == '@' && b[i] != '@'){
      if(b[i] == 'a' || b[i] == 't' || b[i] == 'c' || b[i] == 'o' || b[i] == 'd' || b[i] == 'e' || b[i] == 'r'){
        ;
      }else{
        win = false;
        break;
      }
    }else if(a[i] != '@' && b[i] == '@'){
      if(a[i] == 'a' || a[i] == 't' || a[i] == 'c' || a[i] == 'o' || a[i] == 'd' || a[i] == 'e' || a[i] == 'r'){
        ;
      }else{
        win = false;
        break;
      }
    }else{
      ;
    }
  }

  if(win){
    cout << "You can win\n";
  }else{
    cout << "You will lose\n";
  }
}

int main(){
  solve();
  return 0;
}