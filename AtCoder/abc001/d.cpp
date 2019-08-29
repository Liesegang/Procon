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

struct Span{
public:
  int start;
  int end;

  void print(){
    printf("%04d-%04d\n", start, end);
  }
};

void solve(){
  int N;
  cin >> N;
  vector<Span> span; 
  rep(i, N){
    int S, E;
    scanf("%d-%d", &S, &E);
    Span t;
    t.start = (S / 5) * 5;
    t.end = ((E+4) / 5) * 5;
    if(t.end % 100 == 60){
      t.end += (100 - 60);
    }
    span.push_back(t);
  }
  
  sort(span.begin(), span.end(), [](const Span& a, const Span& b){return a.start < b.start;});

  vector<Span> merged;
  int end = span.begin()->end;
  int start = span.begin()->start;
  for(auto t : span){
    if(t.start <= end){
      end = max(t.end,end);
    }else{
      Span u;
      u.start = start;
      u.end = end;
      merged.push_back(u);
      start = t.start;
      end = t.end;
    }
  }
  Span u;
  u.start = start;
  u.end = end;
  merged.push_back(u);

  for(auto t : merged){
    t.print();
  }
}

int main(){
  solve();
  return 0;
}