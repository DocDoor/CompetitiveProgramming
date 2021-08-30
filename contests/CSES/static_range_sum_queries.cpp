#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5+1;
long long a[mxN], pre[mxN];

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for(int i=1; i<=n; ++i) cin >> a[i];
  for(int i=1; i<=n; ++i) {
    pre[i]=a[i]+pre[i-1];
  }
  for(int i=0; i<q; ++i) {
    int l, r;
    cin >> l >> r;
    cout << pre[r]-pre[l-1] << '\n';
  }
}
