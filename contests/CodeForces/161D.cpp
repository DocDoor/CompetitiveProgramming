#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=5e4+1, mxX=5e2+5;
vector<int> tree[mxN];
int n, k, ans;
int dp[mxN][mxX];

void dfs(int src, int p) {
  dp[src][0]=1;
  for(auto u: tree[src]) {
    if(u==p) continue;
    dfs(u, src);
    for(int i=0; i<k; ++i) ans+=dp[src][i]*dp[u][k-i-1];
    for(int i=0; i<=k; ++i) dp[src][i+1]+=dp[u][i];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for(int i=1; i<n; ++i) {
    int u, v;
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  dfs(1, 0);
  cout << ans;
}
