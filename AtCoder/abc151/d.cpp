#include <bits/stdc++.h>
using namespace std;

// Type alias
using ll=long long;
using ld=double;

using pi=pair<int,int>;
using pll=pair<ll,ll>;
using pld=pair<ld,ld>;
using ti3=tuple<int, int, int>;

using vi=vector<int>;
using vll=vector<ll>;
using vld=vector<ld>;
using vpi=vector<pi>;
using vpll=vector<ll>;
using vpld=vector<ld>;
using vti3=vector<ti3>;

// Constants
const double EPS = 1e-9;
const int inf = numeric_limits<int>::max();

// Macro
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rrep(i,n) for(int i=int(n-1);i>=0;--i)
#define REP(i,a,b) for(int i=int(a);i<int(b);++i)
#define RREP(i,a,b) for(int i=int(b-1);i>=int(a);--i)
#define SHOW(a) cout << #a << " = " << a << endl
#define ARR(a,n) for(int i=0;i<int(n);++i) cout << #a << "[" << i << "]" << " = " << a[i] << endl

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int bfs(int i, int j, char S[21][21], int H, int W){
  if(S[i][j] == '#')
    return 0;
  int dist[21][21];
  memset(dist, -1, 21*21*sizeof(int));
  dist[i][j] = 0;
  std::queue<pi> que;
  que.push(make_pair(i, j));

  int ret = 0;
  while(!que.empty()){
    auto p = que.front();
    que.pop();
    int i = p.first;
    int j = p.second;
    rep(k, 4){
      int x = i + dx[k];
      int y = j + dy[k];

      if(0 <= x && x < H && 0 <= y && y < W && S[x][y] != '#' && dist[x][y] == -1){
        int t = dist[i][j] + 1;
        dist[x][y] = t;
        if(t > ret)
          ret = t;
        que.push(make_pair(x, y));
      }
    }
  }

  return ret;
}

void solve(){
  int H, W;
  cin >> H >> W;
  char S[21][21];
  rep(i, H) rep(j, W) cin >> S[i][j];

  int max = 0;
  rep(i, H){
    rep(j, W){
      int d = bfs(i, j, S, H, W);
      if(d > max)
        max = d;
    }
  }

  cout << max << endl;
}

int main(){
// FastIO
//ios_base::sync_with_stdio(false);
cin.tie(NULL);
  solve();
  return 0;
}