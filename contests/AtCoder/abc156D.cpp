#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, mxN = 3e5;
long long mpow(long long a, long long b) {
	long long ret = 1;
	while (b) {
		if (b & 1) (ret *= a) %= mod;
		(a *= a) %= mod;
		b >>= 1;
	}
	return ret;
}
long long mmul(long long a, long long b) {
	return ((a % mod) * (b % mod)) % mod; 
}
long long msub(long long a, long long b) {
	return (((a % mod) - (b % mod)) + mod) % mod;
}
long long madd(long long a, long long b) {
	return ((a % mod) + (b % mod)) % mod;
}
long long minv(long long b) {
	return mpow(b, mod - 2);
}
long long mbinom(long long n, long long r){
	long long res = 1;
  for (int i = 0; i < r; ++i) {
  	res = res * (n - i) % mod;
    res = res * minv(i + 1) % mod;
  }
  return res;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, a, b;
	cin >> n >> a >> b;
	cout << msub(mpow(2, n) - 1, mbinom(n, a) + mbinom(n, b));
}	
