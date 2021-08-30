#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN=1e5+5;
vector<int> graph[mxN];
bool vis[mxN];
vector<int> comp;

void dfs(int src) {
  vis[src]=true;
  for(auto u: graph[src]) {
    if(!vis[u]) {
      dfs(u);
    }
  }
}

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
  for(int i=1; i<=n; ++i) {
    if(!vis[i]) {
      dfs(i);
      comp.push_back(i);
    }
  }
  cout << comp.size()-1 << '\n';
  if(comp.size()!=1) {
    for(int i=0; i<comp.size()-2; ++i) {
      cout << comp[i] << " " << comp[i+1] << '\n';
    }
    cout << comp.back() << " " << comp[0] << '\n';
  }
}
