// problem link -> https://atcoder.jp/contests/abc214/tasks/abc214_d
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
const int mxN=1e5+6;

struct Edge {
  ll a, b, w;
  bool operator < (Edge scnd) const {
    return w < scnd.w;
  }
};

struct DSU {
  ll par[mxN], setsize[mxN];
  DSU() {for (int i = 1; i < mxN; ++i) par[i] = i, setsize[i] = 1;}
  ll find(int x) {
    if (par[x] == x) return x;
    else return par[x] = find(par[x]);
  } 
  void setunion(ll a, ll b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      if (setsize[b] > setsize[a]) swap(a, b);
      par[b] = par[a];
      setsize[a] += setsize[b]; 
    }
  }
};

Edge Edges[mxN];
DSU dsu;

void solve() {
  int n;
  cin >> n;
  FOR (i, n - 1) {
    cin >> Edges[i].a >> Edges[i].b >> Edges[i].w;
  }
  sort(Edges, Edges + n - 1);
  ll ans = 0;
  FOR (i, n - 1) {
    ans += dsu.setsize[dsu.find(Edges[i].a)] * dsu.setsize[dsu.find(Edges[i].b)] * Edges[i].w;
    dsu.setunion(Edges[i].a, Edges[i].b);
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
