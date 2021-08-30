#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN=1e5+5;
vector<int> graph[mxN];
bool vis[mxN];
int dist[mxN], par[mxN];
queue<int> q;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for(int i=0; i<m; ++i) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  vis[1]=true;
  dist[1]=0;
  q.push(1);
  while(q.size()) {
    int e=q.front();
    q.pop();
    for(auto u : graph[e]) {
      if(vis[u]==0) {
        vis[u]=true;
        dist[u]=dist[e]+1;
        par[u]=e;
        q.push(u);
      }
    }
  }
  if(dist[n]==0) {
    cout << "IMPOSSIBLE" << '\n';
  } else {
    cout << dist[n]+1 << '\n';
    vector<int> ans;
    while(n!=1) {
      ans.push_back(n);
      n=par[n];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); ++i) {
      cout << ans[i] << " ";
    }
  }
} 
