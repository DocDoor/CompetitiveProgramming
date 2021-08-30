#include <bits/stdc++.h>
using namespace std;
 
const int mxN=2e5+1;
long long a[mxN], st[mxN*4];
 
void build(int si, int ss, int se) {
  if(ss==se) {
    st[si]=a[ss];
    return;
  }
  int mid=(ss+se)>>1;
  build(si*2, ss, mid);
  build(si*2+1, mid+1, se);
  st[si]=st[si*2]^st[si*2+1];
}
 
int query(int si, int ss, int se, int l, int r) {
  if(ss>r||se<l) return 0;
  if(l<=ss&&r>=se) return st[si];
  int mid=(ss+se)>>1;
  return query(si*2, ss, mid, l, r)^query(si*2+1, mid+1, se, l, r);
}
 
int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for(int i=1; i<=n; ++i) cin >> a[i];
  build(1, 1, n);
  for(int i=0; i<q; ++i) {
    int l, r;
    cin >> l >> r;
    cout << query(1, 1, n, l, r) << '\n';
  }
}
