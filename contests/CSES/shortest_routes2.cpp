// problem link -> https://cses.fi/problemset/task/1672/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
using namespace std;
 
const int mxN=5e2+5;
const ll INF=1e17;
ll dist[mxN][mxN];
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=n; ++j) {
      dist[i][j]=INF;
    }
  }
  for(int i=0; i<m; ++i) {
    ll u, v, w;
    cin >> u >> v >> w;
    dist[u][u]=0;
    dist[v][v]=0;
    dist[u][v]=min(dist[u][v],w);
    dist[v][u]=min(dist[u][v],w);
  } 
  for(int k=1; k<=n; ++k) { 
    for(int i=1; i<=n; ++i) {
      for(int j=1; j<=n; ++j) {
        dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);       
      }
    }
  } 
  for(int i=0; i<q; ++i) {
    int l, r;
    cin >> l >> r;
    if(dist[l][r]<INF) cout << dist[l][r] << '\n';
    else cout << -1 << '\n';
  }
}
