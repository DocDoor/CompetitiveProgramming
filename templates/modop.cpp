namespace modop { 
  long long mod = 1e9 + 7;
  long long madd(long long a, long long b) {
    return (a + b) % mod;
  }
  long long msub(long long a, long long b) {
    return (((a - b) % mod) + mod) % mod;
  }
  long long mmul(long long a, long long b) {
    return ((a % mod) * (b % mod)) % mod;
  }
  long long mpow(long long base, long long exp) {
    long long res = 1;
    while(exp) {
      if(exp % 2 == 1) res = (res * base) % mod;
      exp >>= 1;
      base = (base * base) % mod;
    }
    return res;
  }
  long long minv(long long base) {
    return mpow(base, mod - 2);
  }
  long long mdiv(long long a, long long b) {
    return mmul(a, minv(b));
  }
  long long gcd(long long x, long long y) {
    if (x == 0) return y;
    if (y == 0) return x;
    return gcd(y, x % y);
  }
  long long lcm(ll x, ll y) {
    return x * y / gcd(x, y);
  }
}

using namespace modop;
