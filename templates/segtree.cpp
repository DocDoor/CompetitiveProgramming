// just range sum queries
struct SegTree {
  vector<int> seg, a; // use long long 
  int n;
  SegTree(int n) {
    a.push_back(1); // for one-indexed
    this->n=n+1;
    seg.assign(n+1, 0);
  }
  void add(int val) {
    a.push_back(val);
  }
  void build(int si, int ss, int se) {
    if(ss==se) {
      seg[si]=a[ss];
      return;
    } else {
      int mid=(ss+se)>>1;
      build(si*2, ss, mid);
      build(si*2+1, mid+1, se);
      seg[si]=seg[si*2]+seg[si*2+1];
    }
  }
  long long query(int si, int ss, int se, int l, int r) {
    if(l<=ss&&r>=se) return seg[si];
    else if(se<l||ss>r) return 0;
    else {
      int mid=(ss+se)>>1;
      return query(si*2, ss, mid, l, r)+query(si*2+1, mid+1, se, l, r);
    }
  }
};
