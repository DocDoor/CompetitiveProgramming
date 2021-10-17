// problem link -> https://atcoder.jp/contests/abc222/tasks/abc222_d

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
 
const ll INF=2e18, mxN=2e5+5, mod=998244353;
 
void solve() {
  int n;
  cin >> n;
  vt<ll> a(n), b(n);
  trav(i, a) cin >> i;
  trav(i, b) cin >> i;
  vt<vt<ll>> dp(n+1, vt<ll> (3001, 0));
  dp[0][0]=1;
  FOR(i, n+1) {
    FOR(j, 3000) {
      dp[i][j+1]+=dp[i][j];
      dp[i][j+1]%=mod;
    }
    if(i^n) {
      for(ll j=a[i]; j<=b[i]; ++j) {
        dp[i+1][j]+=dp[i][j];
        dp[i+1][j]%=mod;
      }
    }
  }
  cout << dp[n][3000];
} 
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  // cin >> tc;
  while(tc--) {
    solve();
  }
}
