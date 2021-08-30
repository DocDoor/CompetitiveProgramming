struct DSU {
  vector<int> sz, par;
  DSU(int n) {
    par.resize(n+1);
    sz.resize(n+1, 1);
    iota(all(par), 0);
  }
  inline int find(int x) {
    return par[x]=(x==par[x]?x:find(par[x]));
  }
  void unite(int x, int y) {
    sz[x]+=sz[y];
    par[y]=x;
  }
  bool same(int x, int y) {
    return find(x)!=find(y);
  }
};

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
  return a.first<b.first;
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
