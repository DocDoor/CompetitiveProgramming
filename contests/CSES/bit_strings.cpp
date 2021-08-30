// problem link -> https://cses.fi/problemset/task/1617/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
using namespace std;

const ll mxN=1e9+7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  ll ans=2;
  for(int i=1; i<n; ++i) {
    ans=(ans*2)%mxN;
  }
  cout << ans;
}
