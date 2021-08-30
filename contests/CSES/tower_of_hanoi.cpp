// problem link -> https://cses.fi/problemset/task/2165/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
using namespace std;
 
void f(int n, int a, int b, int c) {
  if(n==1) {
    cout << a << " " << c << '\n';
    return;
  } else {
    f(n-1, a, c, b);
    cout << a << " " << c << '\n';
    f(n-1, b, a, c);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  cout << (1<<n)-1 << '\n';
  f(n, 1, 2, 3);
}
