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
  st[si]=st[si*2]+st[si*2+1];
}

void update(int si, int ss, int se, int ind, int val) {
  if(ss==se) {
    st[si]=val;
    a[ind]=val;
    return;
  }
  int mid=(ss+se)>>1;
  if(ind<=mid) update(si*2, ss, mid, ind, val);
  else update(si*2+1, mid+1, se, ind, val);
  st[si]=st[si*2]+st[si*2+1];
}

long long query(int si, int ss, int se, int ql, int qr) {
  if(qr<ss||ql>se) return 0;
  if(ql<=ss&&qr>=se) return st[si];
  int mid=(ss+se)>>1;
  return query(si*2, ss, mid, ql, qr)+query(si*2+1, mid+1, se, ql, qr);
}

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for(int i=1; i<=n; ++i) cin >> a[i];
  build(1, 1, n);
  for(int i=0; i<q; ++i) {
    int t, l, r;
    cin >> t >> l >> r;
    if(t==1) {
      update(1, 1, n, l, r);
    } else {
      cout << query(1, 1, n, l, r) << '\n';
    }
  }
}
