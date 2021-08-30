#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN=1e9+7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n, ans=0;
    cin >> n;
    for(int i=1; i*i<=n; ++i) {
      if(i*i==n) ++ans;
      else if(n%i==0) ans+=2;
    }
    cout << ans << '\n';
  }
}
