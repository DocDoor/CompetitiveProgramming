// problem link -> https://cses.fi/problemset/task/1092/

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

#define FOR(i, n) for(int i=0; i<n; ++i)
#define trav(a, x) for(auto &a : x) 

const ll INF=2e15, mxN=2e5+5;

void solve() { 
  ll n;
  cin >> n;
  if((n*(n+1)/2)%2==0) {
    cout << "YES" << '\n';  
    vt<int> a, b;
    ll ans=n*(n+1)/4;
    for(int i=n; i>=1; --i) {
      if(i<=ans) {
        a.pb(i);
        ans-=i;
      } else {
        b.pb(i);
      }
    }
    cout << sz(a) << '\n';
    FOR(i, sz(a)) {
      cout << a[i] << " ";
    }
    cout << '\n' << sz(b) << '\n';
    FOR(i, sz(b)) {
      cout << b[i] << " ";
    }
  } else {
    cout << "NO" << '\n';
  }
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
