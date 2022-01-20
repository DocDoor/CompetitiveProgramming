struct DSU {
  vector<int> par, sz;
  DSU(int n) {
    par.resize(n);
    sz.resize(n, 1);
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

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
  return a.first < b.first;
}

/* sort edges by weights then iterate all edges and if u and v is in disjoint sets, add this edge into your tree */
/* 
sort(edges.begin(), edges.end(), compare);
trav(i, edges) {
  if(a.same(i.second.first, i.second.second)) {
    a.unite(i.second.first, i.second.second);
    // cout << i.second.first << " " << i.second.second << '\n';
  }
} */
