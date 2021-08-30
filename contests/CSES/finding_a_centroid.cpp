#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0);
	int n;
	cin >> n;
	vector<int> g[n+5];
	for(int i=0; i<n-1; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
  vector<int> centroid;
  vector<int> sz(n+1);
  function<void(int, int)>dfs=[&](int u, int prev) {
    sz[u]=1;
    bool is_centroid=true;
    for(auto v: g[u]) {
      if(v!=prev) {
        dfs(v, u);
        sz[u]+=sz[v];
        if(sz[v]>n/2) is_centroid=false;
      }
    }
    if(n-sz[u]>n/2) is_centroid=false;
    if(is_centroid) centroid.push_back(u);
  };
  dfs(1, -1);
  cout << centroid[0];
}
