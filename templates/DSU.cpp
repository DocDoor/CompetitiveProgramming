struct DSU {
  vector<int> par, sz;
  DSU(int n) {
    par.resize(n);
    sz.resize(n, 1);
    iota(par.begin(), par.end(), 0);
  }
  inline int find(int v) {
    return par[v] = (v == par[v] ? v : find(par[v]));
  }
  inline bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    sz[x] += sz[y];
    par[y] = x;
    return true;
  }
  int size(int v) {
    return sz[find(v)];
  }
  bool same(int x, int y) {
    return find(x) == find(y);
  }
};
