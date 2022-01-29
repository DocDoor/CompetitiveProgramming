struct ft {
  vector<long long> bit;
  int n;
  ft(int x) {
    n = x;
    bit.resize(x + 1, 0);
  }
	
  void add(int ind, int val) {
    for (ind; ind <= n; ind += ind & -ind) {
      bit[ind] += val;
    }
  }

  long long sum(int ind) {
    long long ret = 0;
    for (; ind > 0; ind -= ind & -ind) {
      ret += bit[ind];
    }
    return ret;
  }
	
  long long query(int l, int r) {
    return sum(r) - sum(l - 1);
  }
};
