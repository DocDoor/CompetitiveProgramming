#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
using namespace std;
 
const int mxN=2e5+3;
ll a[mxN], lazy[4*mxN], ans;
 
void update(int si, int ss, int se, int l, int r, int val) {
  if(l<=ss&&r>=se) {
    lazy[si]+=val;
    return;
  } else if(ss>r||l>se) return;
  else {
    int mid=(ss+se)>>1;
    update(si*2, ss, mid, l, r, val);
    update(si*2+1, mid+1, se, l, r, val);
  }
}
 
void get(int si, int ss, int se, int pos) {
  if(ss==se) {
    ans+=(a[ss]+lazy[si]);
    return;
  } else {
    ans+=lazy[si];
    int mid=(ss+se)>>1;
    if(mid>=pos) {
      get(si*2, ss, mid, pos);
    } else {
      get(si*2+1, mid+1, se, pos);
    }
  }
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);  
  int n, q;
  cin >> n >> q;
  for(int i=1; i<=n; ++i) cin >> a[i];
  for(int i=0; i<q; ++i) {
    int type;
    cin >> type;
    if(type==1) {
      int l, r, x;
      cin >> l >> r >> x;
      update(1, 1, n, l, r, x);
    } else {  
      int pos;
      cin >> pos;
      ans=0;
      get(1, 1, n, pos);
      cout << ans << '\n';
    }
  }
}
