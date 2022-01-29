// problem link -> https://atcoder.jp/contests/abc218/tasks/abc218_e

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ar array

#define vt vector
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second

#define FOR(i, n) for (int i = 0; i < n; ++i)
#define FORO(i, n) for (int i = 1; i <= n; ++i)
#define trav(a, x) for (auto &a : x) 

const ll INF = 2e18, M = 1e9;
const int mxN = 2e5 + 5;

struct DSU {
  vector<int> sz, par;
  DSU(int n) {
    par.resize(n + 1);
    sz.resize(n + 1, 1);
    iota(all(par), 0);
  }
  inline int find(int x) {
    return par[x] = (x == par[x] ? x : find(par[x]));
  }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    par[x] = y;
    return true;
  }
  bool same(int x, int y) {
    return find(x) == find(y);
  }
};

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
  return a.first < b.first;
}

void solve() {
  int n, m;
  cin >> n >> m;
  DSU a(n + 5);
  vector<pair<ll, pair<ll, ll>>> edges;
  FOR (i, m) {
    ll u, v, w;
    cin >> u >> v >> w;
    edges.pb({w, {u, v}});
  }
  sort(all(edges), compare);
  ll ans = 0;
  trav(i, edges) {
    if (i.fi <= 0) {
      a.unite(i.se.fi, i.se.se);
    } else if (!a.same(i.se.fi, i.se.se)) {
      a.unite(i.se.fi, i.se.se);
    } else {
      ans += i.fi;
    }
  }
  cout << ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
