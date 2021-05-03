#include <bits/stdc++.h>
using namespace std;

int main() {
  int v, e, r;
  cin >> v >> e >> r;

  vector<vector<pair<int, int>>> edge(v);
  for(int i = 0; i < e; i++) {
    int s, t, d;
    cin >> s >> t >> d;
    edge[s].push_back(make_pair(t, d));
  }

  const int inf = 1 << 30;
  vector<int> dist(v, inf);
  vector<bool> determined(v, false);

  dist[r] = 0;
  determined[r] = true;
  priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
  for(int i = 0; i < edge[r].size(); i++) {
    dist[edge[r][i].first] = edge[r][i].second;
    q.push(make_pair(edge[r][i].second, edge[r][i].first));
  }

  while(!q.empty()) {
    auto p = q.top(); q.pop();
    if(!determined[p.second]) {
      determined[p.second] = true;
      dist[p.second] = p.first;
      for(int i = 0; i < edge[p.second].size(); i++) {
        if(!determined[edge[p.second][i].first]) {
          q.push(make_pair(dist[p.second] + edge[p.second][i].second, edge[p.second][i].first));
        }
      }
    }
  }

  for(int i = 0; i < v; i++) {
    if(dist[i] == inf) {
      printf("INF\n");
    } else {
      printf("%d\n", dist[i]);
    }
  }
}