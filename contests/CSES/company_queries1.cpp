// problem link -> https://cses.fi/problemset/task/1687/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
using namespace std;
 
const int mxN=2e5+3, k=25;
vector<int> graph[mxN];
int anc[mxN][k];
 
void dfs(int src, int p) {
  anc[src][0]=p;
  for(int i=1; i<25; ++i) {
    anc[src][i]=anc[anc[src][i-1]][i-1];
  }
  for(auto u : graph[src]) {
    if(u!=p) {
      dfs(u, src);
    }
  }
}
 
int main() {
  int n, q;
  cin >> n >> q;
  for(int i=2; i<=n; ++i) {
    int x;
    cin >> x;
    graph[x].pb(i);
    graph[i].pb(x);
  }
  dfs(1, 0);
  for(int i=0; i<q; ++i) {
    int u, v, cnt=0;
    cin >> u >> v;
    while(v) {
      if(v&1) u=anc[u][cnt];
      v>>=1;
      ++cnt;
    }
    cout << (u?u:-1) << '\n';
  }
}
