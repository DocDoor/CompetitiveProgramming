// problem link -> https://cses.fi/problemset/task/1137/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
using namespace std;
 
const int mxN=2e5+5;
vector<int> graph[mxN];
int sz[mxN], timer=1, et[mxN], v[mxN];
ll bit[mxN];

void dfs(int src, int p) {
  et[src]=timer++;
  sz[src]=1;
  for(auto u : graph[src]) {
    if(u!=p) {
      dfs(u, src);
      sz[src]+=sz[u];
    }
  }
}

void update(int s, int x) {
  for(; s<mxN; s+=s&-s) {
    bit[s]+=x;
  }
}

ll query(int s) {
  ll sum=0;
  for(; s>0; s-=s&-s) {
    sum+=bit[s];
  }
  return sum;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for(int i=1; i<=n; ++i) cin >> v[i];
  for(int i=1; i<n; ++i) {
    int u, v;
    cin >> u >> v;
    graph[u].pb(v);
    graph[v].pb(u);
  }
  dfs(1, 0);
  for(int i=1; i<=n; ++i) {
    update(et[i], v[i]);
  }
  for(int i=0; i<q; ++i) {
    int type;
    cin >> type;
    if(type==1) {
      int s, x;
      cin >> s >> x;
      x-=v[s]; 
      v[s]+=x;
      update(et[s],x);
    } else {
      int x;
      cin >> x;
      cout << query(et[x]+sz[x]-1)-query(et[x]-1) << '\n';
    }
  }
}
