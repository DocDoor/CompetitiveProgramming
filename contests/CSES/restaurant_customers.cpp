#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, ans=-1, cnt=0;
  cin >> n;
  multiset<pair<int, int>> ms;
  for(int i=0; i<n; ++i) {
    int a, b;
    cin >> a >> b;
    ms.insert({a, 1});
    ms.insert({b, 0});
  }
  for(pair<int, int> e : ms) {
    if(e.second==1) {
      ++cnt;
    } else --cnt;
    ans=max(ans, cnt);
  }
  cout << ans << '\n';
}
