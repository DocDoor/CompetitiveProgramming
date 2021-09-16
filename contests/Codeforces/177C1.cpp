// problem link -> https://codeforces.com/problemset/problem/177/C1

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ar array

#define vt vector
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FORO(i, n) for(int i=1; i<=n; ++i)
#define trav(a, x) for(auto &a : x) 

const ll INF=2e18, M=1e9;
const int mxN=2e3+5;

vt<int> g[mxN];
bool vis[mxN];
vt<int> q;
int a[mxN][mxN];

void dfs(int src) {
  vis[src]=1;
  q.pb(src);
  for(auto e : g[src]) {
    if(!vis[e]) {
      dfs(e);
    }
  }
}

void solve() {
  int n, m, k;
  cin >> n >> m;
  FOR(i, m) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }  
  cin >> k;
  FOR(i, k) {
    int u, v;
    cin >> u >> v;
    a[u][v]=a[v][u]=1;
  }
  int ans=0;
  for(int i=1; i<=n; ++i) {
    if(vis[i]^1) {
      q.clear();
      dfs(i);
      bool f=1;
      for(int j=0; j<sz(q)&&f; ++j) {
        for(int k=j+1; k<sz(q)&&f; ++k) {
          if(a[q[j]][q[k]]) {
            f=0;
          }
        }
      }
      if(f) {
        ans=max(ans, sz(q));
      }
    }
  }
  cout << ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t=1;
  // cin >> t;
  while(t--) {
    solve();
  }
}
