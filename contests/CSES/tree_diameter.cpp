// problem link -> https://cses.fi/problemset/task/1131/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
using namespace std;
 
const int mxN=2e5+5;
vector<int> graph[mxN];
int mxd, node;
 
void dfs(int src, int p, int d) {
  for(auto u : graph[src]) {
    if(p!=u) {
      dfs(u, src, d+1);
    }
  }
  if(d>mxd) {
    mxd=d;
    node=src;
  }
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i=1; i<n; ++i) {
    int u, v;
    cin >> u >> v;
    graph[u].pb(v);
    graph[v].pb(u);
  }
  dfs(1, 0, 0);
  dfs(node, 0, 0);
  cout << mxd;
}
