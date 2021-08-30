struct FenwickTree {  
  vector<int> bit;  // binary indexed tree
  int n;

  FenwickTree(int n) {
    this->n=n+1;
    bit.assign(n+1, 0);
  }

  ll sum(int idx) {
    int ret=0;
    for(++idx; idx>0; idx-=idx&-idx)
      ret+=bit[idx];
    return ret;
  }

  int query(int l, int r) {
    return sum(r)-sum(l-1);
  }

  void add(int idx, int delta) {
    for(++idx; idx<n; idx+=idx&-idx)
      bit[idx]+=delta;
  }
};
