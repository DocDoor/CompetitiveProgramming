// author : DocDoor
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define ins insert
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define FOR(i, n) for(int i=0; i<n; ++i)
#define trav(a, x) for(auto &a : x) 

const ll INF=1e17, M=1e9+7;
const int mxN=2e5+6;

struct DSU {
  int par[mxN];
  DSU() {FOR(i, mxN) par[i]=i;}
  int find(int x) {
    if(par[x]==x) return x;
    return par[x]=find(par[x]);
  }
  void merge(int u, int v) {
    u=find(u);
    v=find(v);
    if(u!=v){
      par[u]=par[v];
    }
  }
};

bool compare(pair<ll, pair<int, int>> x, pair<ll, pair<int, int>> y) {
  return x.first<y.first;
}

vector<pair<ll, pair<int, int>>> edges;
ll a[mxN];
DSU dsu;

void solve() {
  int n, m;
  cin >> n >> m;
  ll mn=INF, mnnode;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
    if(a[i]<mn) {
      mnnode=i;
      mn=a[i];
    }
  }
  for(int i=1; i<=n; ++i) {
    if(i^mnnode) {
      edges.push_back(mp(mn+a[i], mp(mnnode, i)));
    }
  }
  FOR(i, m) {
    int u, v; ll w;
    cin >> u >> v >> w;
    edges.push_back(mp(w, mp(u, v)));
  }
  sort(edges.begin(), edges.end(), compare);
  // trav(i, edges) cout << i.second.first << " " << i.second.second << " " << i.first << '\n';
  ll ans=0;
  for(auto u : edges) {
    if(dsu.find(u.second.first)!=dsu.find(u.second.second)) {
      ans+=u.first;
      dsu.merge(u.second.first, u.second.second);
    }
  }
  cout << ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t=1;
  // cin >> t;
  while(t--) {
    solve();
  }
} 
