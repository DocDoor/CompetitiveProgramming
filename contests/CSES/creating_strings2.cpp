// problem link -> https://cses.fi/problemset/task/1715/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second

#define FOR(i, n) for(ll i=0; i<n; ++i)
#define trav(a, x) for(auto &a : x) 

const ll INF=2e15, mod=1e9+7;

ll fact[1000005];

ll mpow(ll a, ll b) {
  ll ret=1;
  while(b) {
    if(b&1) ret=(ret*a)%mod;
    a=(a*a)%mod;
    b>>=1;
  }
  return ret;
}

ll mmul(ll a, ll b) {
  return ((a%mod)*(b%mod))%mod;
}

ll mdiv(ll a, ll b) {
  return mmul(a, mpow(b, mod-2));
}

void solve() {  
  string s;
  cin >> s;
  vt<int> cnt(26, 0);
  ll ans=fact[sz(s)];
  FOR(i, sz(s)) {
    ++cnt[s[i]-'a'];
  }
  FOR(i, 26) {
    if(cnt[i]!=0) {
      ans=mdiv(ans, fact[cnt[i]]);
    }
  } 
  cout << ans;
} 
 
int main() { 
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  // cin >> tc;
  fact[0]=1;
  FOR(i, 1000001) {
    (fact[i+1]=fact[i]*(i+1))%=mod;
  }
  while(tc--) {
    solve();
  }
}
