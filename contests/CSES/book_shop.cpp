#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN=2e5;

ll dp[mxN], h[mxN], c[mxN];

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  for(int i=0; i<n; ++i) cin >> h[i];
  for(int i=0; i<n; ++i) cin >> c[i];
  for(int i=0; i<n; ++i) {
    for(int j=x; j>=h[i]; --j) {
      dp[j]=max(dp[j], dp[j-h[i]]+c[i]);
    }
  }
  cout << dp[x];
}
