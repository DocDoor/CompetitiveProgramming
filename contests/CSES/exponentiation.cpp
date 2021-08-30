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
    ll a, b;
    cin >> a >> b;
    ll ans=1;
    while(b) {
      if(b&1) ans=(ans*a)%mxN;
      a=(a*a)%mxN;
      b>>=1;
    }
    cout << ans << '\n';
  }
}
