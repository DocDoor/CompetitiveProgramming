// problem link -> https://cses.fi/problemset/task/1079/

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
#define fi first
#define se second
#define ins insert
#define all(c) (c).begin(), (c).end()
#define sz(x) (x).size()
 
#define FOR(i, n) for(int i=0; i<n; ++i)
#define trav(a, x) for(auto &a : x) 
 
const ll INF=1e17, M=1e6+7;
const int mxN=1e6+5;
 
namespace modop { 
  ll mod=1e9+7;
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
 
ll fact[mxN];
 
void solve() {
  ll a, b;
  cin >> a >> b;
  cout << mdiv(fact[a], mmul(fact[b],fact[a-b])) << '\n';
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t=1;
  cin >> t;
  fact[0]=1;
  for(int i=1; i<=mxN; ++i) {
    fact[i]=(fact[i-1]*i)%mod;
  }
  while(t--) {
    solve();
  }
} 
