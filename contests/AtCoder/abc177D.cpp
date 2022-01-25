#include <bits/stdc++.h>
using namespace std;
const int mxN = 3e5;

struct DSU {
  vector<int> par, sz;
  DSU(int n) {
    par.resize(n + 5);
    sz.resize(n + 5, 1);
    iota(par.begin(), par.end(), 0);
  }
  inline int get(int v) {
    return par[v] = (v == par[v] ? v : get(par[v]));
  }
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    sz[x] += sz[y];
    par[y] = x;
    return true;
  }
  int size(int v) {
    return sz[get(v)];
  }
  bool same(int x, int y) {
    return get(x) == get(y);
  }
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	DSU dsu(n);	
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		dsu.unite(u, v);
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, dsu.size(dsu.get(i)));
	}
	cout << ans;
}
