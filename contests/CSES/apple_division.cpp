// problem link -> https://cses.fi/problemset/task/1623/

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

const int INF=2e15, mxN=2e5+5;

void solve() {
  ll n; cin >> n;
  vt<ll> a(n);
  trav(i, a) cin >> i;
  ll sum=accumulate(all(a), 0ll), ans=INF;
  FOR(mask, (1<<n)) {
    ll k=0;
    FOR(i, 21) {
      if(mask&(1ll<<i)) {
        k+=a[i];
      }
    }
    ans=min(ans, abs(sum-k-k));
  }
  cout << ans;
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
