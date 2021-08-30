const int mxN=2e5+3, k=25;
vector<int> graph[mxN];
int dist[mxN], anc[mxN][k];
 
void dfs(int src, int p) {
  dist[src]=dist[p]+1;
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
 
int lca(int x, int y) {
  if(dist[y]>dist[x]) swap(x, y);
  ll mesafe=dist[x]-dist[y], say=0;
  while(mesafe) {
    if(mesafe&1) x=anc[x][say];
    mesafe>>=1;
    say++;
  }
  if(x==y) return x;
  for(int i=24; i>=0; --i) {
    if(anc[x][i]!=anc[y][i]) {
      x=anc[x][i];
      y=anc[y][i];
    }
  }
  return anc[x][0];
}


// dist[1]=-1;
// dfs(1, 1);

// lca(a, b) -> returns lowest common ancestor of a and b
