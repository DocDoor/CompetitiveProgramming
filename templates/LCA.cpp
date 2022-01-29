const int mxN = 2e5 + 3, k = 25;
vector<int> graph[mxN];
int dist[mxN], anc[mxN][k];
 
void dfs(int src, int p) {
  par[src][0] = p;
  for (int i = 1; i < 25; ++i) {
    par[src][i] = par[par[src][i - 1]][i - 1];
  }
  for (auto e : g[src]) {
    if (e != p) {
      depth[e] = depth[src] + 1;
      dfs(e, src);
    }
  }
}

 
int lca(int x, int y) {
  if (depth[y] > depth[x]) swap(x, y);
  long long mesafe = depth[x] - depth[y], say = 0;
  while (mesafe) {
    if (mesafe & 1) x = par[x][say];
    mesafe >>= 1;
    say++;
  }
  if (x == y) return x;
  for (int i = 24; i >= 0; --i) {
    if (par[x][i] != par[y][i]) {
      x = par[x][i];
      y = par[y][i];
    }
  }
  return par[x][0];
}

// dist[1]=-1;
// dfs(1, 1);

// lca(a, b) -> returns lowest common ancestor of a and b
