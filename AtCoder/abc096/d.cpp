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

bool p[55565]={};

bool is_prime(int n){
  bool ans = true;
  for(int j=2;j<=sqrt(n);j++){
    if(n%j==0){
      ans = false;
      break;
    }
  }

  return ans;
}

void solve(){
  int n;
  vector<int> ans;
  cin >> n;

  for(int i=2;i<55565;i++)
  {
    p[i] = is_prime(i);
  }

  int c=0;

  for(int i = 3; c != n; i++){
    if(p[i] && i % 5 == 1){
      cout << i;
      c++;
      if(c!= n){
        cout << " ";
      }
    }
  }
  cout << endl;
}

int main(){
  solve();
  return 0;
}