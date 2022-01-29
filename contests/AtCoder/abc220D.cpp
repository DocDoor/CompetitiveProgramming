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

const ll INF = 2e18, mod = 998244353, mxN = 2e5+5;

ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6+37;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

ll dp[mxN][10];

void solve() {
  cin >> n;
  for (ll i = 1; i <= n; ++i) cin >> a[i];
  dp[1][a[1]]++;
  for (ll i = 1; i <= n - 1; ++i) {
    for (ll j = 0; j <= 9; ++j) {
      dp[i + 1][(j + a[i + 1]) % 10] += dp[i][j];
      dp[i + 1][(j * a[i + 1]) % 10] += dp[i][j];
      dp[i + 1][(j + a[i + 1]) % 10] %= mod;
      dp[i + 1][(j * a[i + 1]) % 10] %= mod;
    }
  }
  for (int i = 0; i < 10; ++i) {
    cout << dp[n][i] << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  // cin >> tc;
  while (tc--) {
    solve();
  }
}
