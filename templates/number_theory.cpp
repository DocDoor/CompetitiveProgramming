namespace number_theory {  
	ll gcd(ll x, ll y) {
	  if(x==0) return y;
	  if (y==0) return x;
	  return gcd(y, x%y);
	}

	bool isprime(ll n) { 
	  if(n<=1) return false; 
	  if(n<=3) return true; 
	 
	  if(n%2==0||n%3==0) return false; 
	  
	  for(ll i=5; i*i<=n; i+=6) {
		  if(n%i==0||n%(i+2)==0) {
		    return false; 
      } 
    }
	  
	  return true; 
	} 
	 
	bool prime[15000105]; 
	void sieve(int n) { 
	  for(ll i=0; i<=n; ++i) prime[i]=1;
	  for(ll p=2; p*p<=n; ++p) { 
		  if(prime[p]==true) { 
		    for(ll i=p*p; i<=n; i+=p) {
			    prime[i]=false; 
        }
		  } 
	  } 
	  prime[1]=prime[0]=0;
	} 
	
	vector<ll> getprimes(int n) {
    vector<ll> primelist;
	  sieve(n+1);
	  for(ll i=2; i<=n; ++i) {
      if(prime[i]) {
        primelist.push_back(i);
      }
    }
    return primelist;
	}
	
	vector<ll> getdivs(ll n) {
    vector<ll> divs;
    for(ll i=1; i*i<=n; ++i) {
      if(i*i==n) {
        divs.pb(i);
      } else if(n%i==0) {
        divs.push_back(i);
        divs.push_back(n/i);
      }
    }
    // maybe sort
    return divs;
  }
}

using namespace number_theory;
