namespace modop { 
  ll mod=998244353;
  ll madd(ll a, ll b) {
    return (a+b)%mod;
  }
  ll msub(ll a, ll b) {
    return (((a-b)%mod)+mod)%mod;
  }
  ll mmul(ll a, ll b) {
    return ((a%mod)*(b%mod))%mod;
  }
  ll mpow(ll base, ll exp) {
    ll res=1;
    while(exp) {
      if(exp%2==1) res=(res*base)%mod;
      exp>>=1;
      base=(base*base)%mod;
    }
    return res;
  }
  ll minv(ll base) {
    return mpow(base, mod-2);
  }
  ll mdiv(ll a, ll b) {
    return mmul(a, minv(b));
  }
  ll gcd(ll x, ll y) {
    if(x==0) return y;
    if(y==0) return x;
    return gcd(y, x%y);
  }
  ll lcm(ll x, ll y) {
    return x*y/gcd(x, y);
  }
}

using namespace modop;
