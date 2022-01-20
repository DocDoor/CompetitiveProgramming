namespace number_theory {  
	long long gcd(long long x, long long y) {
	  if (x == 0) return y;
	  if (y == 0) return x;
	  return gcd(y, x % y);
	}

	bool isprime(long long n) { 
	  if(n <= 1) return false; 
	  if(n <= 3) return true; 
	 
	  if (n % 2 == 0 || n % 3 == 0) return false; 
	  
	  for (long long i = 5; i * i <= n; i += 6) {
		  if (n % i == 0 || n % (i + 2) == 0) {
		    return false; 
      } 
    }
	  
	  return true; 
	} 
	 
	bool prime[1500105]; 
	void sieve(int n) { 
	  for (long long i = 0; i <= n; ++i) prime[i] = 1;
	  for (long long p = 2; p * p <= n; ++p) { 
		  if (prime[p] == true) { 
		    for (long long i = p * p; i <= n; i += p) {
			    prime[i] = false; 
        }
		  } 
	  } 
	  prime[1] = prime[0] = 0;
	} 
	
	vector<long long> getprimes(int n) {
    vector<long long> primelist;
	  sieve(n + 1);
	  for(long long i = 2; i <= n; ++i) {
      if(prime[i]) {
        primelist.push_back(i);
      }
    }
    return primelist;
	}
	
	vector<long long> getdivs(long long n) {
    vector<long long> divs;
    for (long long i = 1; i * i <= n; ++i) {
      if (i * i == n) {
        divs.push_back(i);
      } else if (n % i == 0) {
        divs.push_back(i);
        divs.push_back(n/i);
      }
    }
    // maybe sort
    return divs;
  }
};

using namespace number_theory;
