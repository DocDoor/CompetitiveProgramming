// problem link -> https://codeforces.com/problemset/problem/1184/B1

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

const ll INF=2e17, M=1e9;
const int mxN=2e5+5;

bool cmp(const pair<int, int> &l, const pair<int, int> &r) {
  return l.first<r.first;
}

ll pre[mxN];

void solve() {
  int n, s;
  cin >> n >> s;
  vt<int> pow(n);
  FOR(i, n) {
    cin >> pow[i];
  }
  vt<pair<int, int>> v(s);
  trav(i, v) {
    cin >> i.fi >> i.se;
  }
  sort(all(v), cmp);
  pre[0]=v[0].se;
  for(int i=1; i<s; ++i) {
    pre[i]=pre[i-1]+v[i].se;
  }
  FOR(i, n) {
    int id=upper_bound(v.begin(), v.end(), pair<int, int> (pow[i], 0), cmp)-v.begin();
    --id;
    if(id<0) {
      cout << 0 << " ";
    } else {
      cout << pre[id] << " ";
    }
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
