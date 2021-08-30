#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> g[n+1];
  for(int i=2; i<=n; ++i) {
    int a;
    cin >> a;
    g[i].push_back(a);
    g[a].push_back(i);
  }
  vector<int> sz(n+1);
  function<void(int, int)>dfs=[&](int src, int p) {
    sz[src]=1;
    for(auto u: g[src]) {
      if(u!=p) {
        dfs(u, src);
        sz[src]+=sz[u];
      }
    }
  };
  dfs(1, -1);
  for(int i=1; i<=n; ++i) cout << sz[i]-1 << " ";
}
