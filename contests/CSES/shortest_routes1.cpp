// problem link -> https://cses.fi/problemset/task/1671/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
using namespace std;
 
const int mxN=1e5+5;
const ll INF=1e17;
vector<pair<int, int>> graph[mxN];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for(int i=0; i<m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].pb({v, w});
  }  
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  vector<ll> dist(mxN, INF);
  vector<bool> vis(mxN, false);
  pq.push({0, 1});
  dist[1]=0;
  while(pq.size()) {
    int pos=pq.top().second;
    pq.pop();
    if(vis[pos]) continue;
    vis[pos]=1;
    for(auto [u, w] : graph[pos]) {
      if(dist[u]>dist[pos]+w) {
        dist[u]=dist[pos]+w;
        pq.push({dist[u], u});
      }
    }
  }
  for(int i=1; i<=n; ++i) cout << dist[i] << " ";
}
