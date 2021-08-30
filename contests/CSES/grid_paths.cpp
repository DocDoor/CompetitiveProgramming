#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

const int mxN=1e3+5;
const ll MOD=1e9+7;
string g[mxN];
ll dp[mxN][mxN];

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  for(int i=0; i<n; ++i) cin >> g[i];
  dp[0][0]=1;
  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      if(i) dp[i][j]+=dp[i-1][j];
      if(j) dp[i][j]+=dp[i][j-1];
      dp[i][j]%=MOD;
      if(g[i][j]=='*') dp[i][j]=0;
    }
  }
  cout << dp[n-1][n-1];
}
