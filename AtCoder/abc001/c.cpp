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
  int deg, dis;
  string deg_name[] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"};
  cin >> deg >> dis;

  dis = round(dis / 6.0);
  deg = (deg * 10 + 1125) / 2250 % 16;

  if(dis <= 2){
    dis = 0;
  }else if(dis <= 15){
    dis = 1;
  }else if(dis <= 33){
    dis = 2;
  }else if(dis <= 54){
    dis = 3;
  }else if(dis <= 79){
    dis = 4;
  }else if(dis <= 107){
    dis = 5;
  }else if(dis <= 138){
    dis = 6;
  }else if(dis <= 171){
    dis = 7;
  }else if(dis <= 207){
    dis = 8;
  }else if(dis <= 244){
    dis = 9;
  }else if(dis <= 284){
    dis = 10;
  }else if(dis <= 326){
    dis = 11;
  }else{
    dis = 12;
  }

  if(dis == 0){
    printf("C 0");
  }else{
    printf("%s %d", deg_name[deg].c_str(), dis);
  }
  printf("\n");
}

int main(){
  solve();
  return 0;
}