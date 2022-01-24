#include <bits/stdc++.h>
using namespace std;
const long long mxN = 3e5;
long long dist[mxN], par[mxN][25], depth[mxN];
vector<pair<long long, long long>> g[mxN];
void dfs(long long src, long long p, long long f) {
	par[src][0] = p;
	dist[src] = f;
	for (long long i = 1; i < 25; ++i) {
		par[src][i] = par[par[src][i - 1]][i - 1];
	}
	for (auto e : g[src]) {
		if (e.first ^ p) {
			depth[e.first] = depth[src] + 1;
			dfs(e.first, src, f + e.second);
		}
	}
}
long long lca(int x, int y) {
	if (depth[y] > depth[x]) swap(x, y);
 	long long mesafe = depth[x] - depth[y], say = 0;
  while (mesafe) {
    if (mesafe & 1) x = par[x][say];
    mesafe >>= 1;
    say++;
  }
  if (x == y) return x;
  for (long long i = 24; i >= 0; --i) {
    if (par[x][i] != par[y][i]) {
      x = par[x][i];
      y = par[y][i];
    }
  }
  return par[x][0];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n;
	cin >> n;
	for (long long i = 1; i < n; ++i) {
		long long u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	dfs(1, 0, 0);
	long long q, k;
	cin >> q >> k;
	for (long long i = 0; i < q; ++i) {
		long long u, v;
		cin >> u >> v;
		cout << (dist[u] + dist[k] - 2 * dist[lca(u, k)]) + (dist[v] + dist[k] - 2 * dist[lca(v, k)]) << '\n';
	}
}
