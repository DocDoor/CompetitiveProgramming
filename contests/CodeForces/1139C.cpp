// problem link -> https://codeforces.com/contest/1139/problem/C

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

namespace modop { 
  ll mod=M;
  ll madd(ll a, ll b) {
    return (a+b)%mod;
  }
  ll msub(ll a, ll b) {
    return (((a-b)%mod)+mod)%mod;
  }
  ll mmul(ll a, ll b) {
    return ((a%mod)*(b%mod))%mod;
  }
  ll mpow(ll base, ll exp) {
    ll res=1;
    while(exp) {
      if(exp%2==1) res=(res*base)%mod;
      exp>>=1;
      base=(base*base)%mod;
    }
    return res;
  }
  ll minv(ll base) {
    return mpow(base, mod-2);
  }
  ll mdiv(ll a, ll b) {
    return mmul(a, minv(b));
  }
  ll gcd(ll x, ll y) {
    if(x==0) return y;
    if(y==0) return x;
    return gcd(y, x%y);
  }
  ll lcm(ll x, ll y) {
    return x*y/gcd(x, y);
  }
}

using namespace modop;

vector<int> g[mxN];
vector<bool> vis(mxN, false);

int dfs(int src) {
  vis[src]=1;
  int r=1;
  for(auto u : g[src]) {
    if(vis[u]^1) {
      r+=dfs(u);
    }
  }
  return r;
}

void solve() {
  ll n, k;
  cin >> n >> k;
  FOR(i, n-1) {
    int u, v, x;
    cin >> u >> v >> x;
    if(!x) {
      g[u].push_back(v);
      g[v].push_back(u);
    }
  }
  ll ans=mpow(n, k);
  for(int i=1; i<=n; ++i) {
    if(!vis[i]) {
      ans=msub(ans, mpow(dfs(i), k));
    }
  }
  cout << ans << '\n';
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
