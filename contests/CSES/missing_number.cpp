// problem link -> https://cses.fi/problemset/task/1083/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, sum=0;;
  cin >> n;
  for(int i=1; i<n; ++i) {
    int x;
    cin >> x;
    sum+=x;
  }
  cout << n*(n+1)/2-sum;
}
