// problem link -> https://cses.fi/problemset/task/1716/

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define ar array
 
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
 
#define FOR(i, n) for(ll i=0; i<n; ++i)
#define trav(a, x) for(auto &a : x) 
 
const ll INF=2e15, mod=1e9+7;
 
ll fact[2000000];
 
ll mpow(ll a, ll b) {
  ll ret=1;
  while(b) {
    if(b&1) ret=(ret*a)%mod;
    a=(a*a)%mod;
    b>>=1;
  }
  return ret;
}
 
ll mult(ll a, ll b) {
  return ((a%mod)*(b%mod))%mod;
}
 
ll mdiv(ll a, ll b) {
  return mult(a, mpow(b, mod-2));
}
 
void solve() { 
  ll n, m;
  cin >> n >> m;
  --n;
  cout << mdiv(fact[n+m], mult(fact[n], fact[m]));
}
 
int main() { 
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  // cin >> tc;
  fact[0]=1;
  FOR(i, 2000000) {
    if(i!=0) {
      fact[i]=(fact[i-1]*i)%mod;
    }
  }
  while(tc--) {
    solve();
  }
}
