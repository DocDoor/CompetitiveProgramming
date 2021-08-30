// problem link -> https://cses.fi/problemset/task/1070/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  if(n==2||n==3) {
    cout << "NO SOLUTION";
    return 0;
  } if(n&1) {
    int cnt=1;
    for(int i=n/2+1; i<n; ++i) {
      cout << i << " " << cnt << " ";
      ++cnt;
    }
    cout << n;
  } else {
    int cnt=1;
    for(int i=n/2+1; i<=n; ++i) {
      cout << i << " " << cnt << " ";
      ++cnt;
    }
  }
}
