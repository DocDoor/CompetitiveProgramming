#include <bits/stdc++.h>
using namespace std;
const int mxN = 3e5;
vector<int> g[mxN];
long long mark[mxN], ans[mxN];
void dfs(int src, int p, long long f) {
	ans[src] = f + mark[src];
	for (auto e : g[src]) {
		if (e ^ p) {
			dfs(e, src, f + mark[src]);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 0; i < q; ++i) {
		int u;
		long long x;
		cin >> u >> x;
		mark[u] += x;
	}
	dfs(1, 0, 0);
	for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
}
