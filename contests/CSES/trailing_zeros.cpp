// problem link -> https://cses.fi/problemset/task/1618/

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
  int n, ans=0;
  cin >> n;
  for(int i=5; n/i>=1; i*=5) {
    ans+=n/i;
  }
  cout << ans;
}
