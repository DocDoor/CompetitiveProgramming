#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN=1e9+7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  multiset<int> ms;
  for(int i=0; i<n; ++i) {
    int x;
    cin >> x;
    ms.insert(x);
  }
  for(int i=0; i<m; ++i) {
    int x;
    cin >> x;
    auto pos=ms.lower_bound(x);
    if(*pos==x) {
      cout << x << '\n';
      ms.erase(ms.find(x));
    } else if(ms.begin()==pos) {
      cout << -1 << '\n';
    } else {
      cout << *(--pos)  << '\n';
      ms.erase(ms.find(*pos));
    }
  }
}
