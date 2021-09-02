// problem link -> https://codeforces.com/problemset/problem/1559/D1

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
const int mxN=1005;

struct DSU {
  int par[mxN];
  DSU() {FOR(i, mxN) par[i]=i;}
  int find(int x) {
    if(par[x]==x) return x;
    else return par[x]=find(par[x]);
  }
  void merge(int x, int y) {
    x=find(x);
    y=find(y);
    if(x!=y) {
      par[x]=par[y];
    }
  }
};

vector<pi> v;
DSU ds1, ds2;

void solve() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  FOR(i, m1) {
    int u, v;
    cin >> u >> v;
    ds1.merge(u, v);
  }
  FOR(i, m2) {
    int u, v;
    cin >> u >> v;
    ds2.merge(u, v);
  }
  FOR(i, n+1) {
    FOR(j, n+1) {
      if(i==0||j==0) continue;
      v.pb({i, j});
    }
  }
  int ans=0;
  vector<pi> ans1;
  for(int i=0; i<v.size(); ++i) {
    if(ds1.find(v[i].f)!=ds1.find(v[i].s)&&ds2.find(v[i].f)!=ds2.find(v[i].s)) {
      ds1.merge(v[i].f, v[i].s);
      ds2.merge(v[i].f, v[i].s);
      ans1.push_back({v[i].f, v[i].s});
      ++ans;
    }
  }
  cout << ans << '\n';
  trav(i, ans1) {
    cout << i.f << " " << i.s << '\n';
  }
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
