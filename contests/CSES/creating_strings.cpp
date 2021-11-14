// problem link -> https://cses.fi/problemset/task/1622/

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
 
void solve() {  
  string s;
  cin >> s;
  sort(all(s));
  vector<string> ans;
  do {
    ans.pb(s);
  } while(next_permutation(all(s)));
  cout << sz(ans) << endl;
  trav(i, ans) {
    cout << i << '\n';
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
