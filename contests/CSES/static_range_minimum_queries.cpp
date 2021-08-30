#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mxN=2e5+1;
int a[mxN], st[mxN*4];

void build(int si, int ss, int se) {
  if(ss==se) {
    st[si]=a[ss];
    return;
  }
  int mid=(ss+se)>>1;
  build(si*2, ss, mid);
  build(si*2+1, mid+1, se);
  st[si]=min(st[si*2], st[si*2+1]);
}

int query(int si, int ss, int se, int ql, int qr) {
  if(ss>qr||se<ql) return 1e9+1;
  if(ql<=ss&&qr>=se) return st[si];
  int mid=(ss+se)>>1;
  return min(query(si*2, ss, mid, ql, qr), query(si*2+1, mid+1, se, ql, qr));
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
