//you can define md with template or inside the struct for other uses 
constexpr int md = int(1e9) + 7;
struct Mint {
  int val = 0;  
  Mint() : val{} {}
  template<typename T> Mint(T x) {
    if (x >= -md && x < md) {
      val = x;
    } else {
      val = x % md;
    }
    if (val < 0) {
      val += x;
    }
  }
 
  int& operator()() { return val; }
  Mint& operator+=(Mint x) {
    if ((val += x.val) > md) {
      val -= md;
    }
    return *this;
  }
  Mint& operator-=(Mint x) {
    if ((val -= x.val) < 0) {
      val += md;
    }
    return *this;
  }
  Mint& operator*=(Mint x) {
    val = int((1LL * val * x.val) % md);      
    return *this;
  }
 
  Mint inv(Mint x) {
    int m = md - 2;
    Mint res = 1; 
    while (m > 0) {
      if (m & 1) {
        res *= x;
      }
      x *= x;
      m >>= 1;
    }  
    return res;
  }
 
  Mint& operator/=(Mint x) {
    return *this *= inv(x);
  }
};
 
Mint operator+(Mint x, Mint y) {
  return x += y;
}
Mint operator-(Mint x, Mint y) {
  return x -= y;
}
Mint operator*(Mint x, Mint y) {
  return x *= y;
}
Mint operator/(Mint x, Mint y) {
  return x /= y;
}
string to_string(Mint x) {
  return to_string(x());
}
template<typename T> Mint power(Mint x, T p) {
  Mint res = 1;
  while (p > 0) {
    if (p & 1) {
      res *= x;
    }
    x *= x;
    p >>= 1;
  }
  return res;
}
 
vector<Mint> fac(1, 1), inv_fac(1, 1);
 
void fill_fac(int n) {
  while ((int) fac.size() <= n) {
    fac.push_back(fac.back() * (int) fac.size());
    inv_fac.push_back(1 / fac.back());
  }
}
 
Mint fact(int x) {
  assert(x >= 0);
  fill_fac(x);
  return fac[x];
}
 
bool reserve_fact(int n) {
  if (int(fac.size()) > n) {
   return false;
  }
  inv_fac.resize(n + 1);
  fac.resize(n + 1, 1);
  for (int i = 1; i <= n; ++i) {
    fac[i] = fac[i - 1] * i;
  }
  inv_fac[n] = 1 / fac[n];
  for (int i = n; i > 0; --i) {
    inv_fac[i - 1] = inv_fac[i] * i;
  }
  return false;
}
 
Mint C(int x, int y) {
  if (x < 0 || y > x) {
    return 0;
  }
  assert(y >= 0);
  fill_fac(x);
  return fac[x] * inv_fac[y] * inv_fac[x - y];
}
 
Mint P(int x, int y) {
  if (x < 0 || y > x) {
    return 0;
  }
  assert(y >= 0);
  fill_fac(x);
  return fac[x] * inv_fac[x - y];
}
 
Mint inverse_C(int x, int y) {
  if (x < 0 || y > x) {
    return 0;
  }
  assert(y >= 0);
  fill_fac(x);
  return inv_fac[x] * fac[y] * fac[x - y];
}
 
Mint inverse_P(int x, int y) {
  if (x < 0 || y > x) {
    return 0;
  }
  assert(y >= 0);
  fill_fac(x);
  return inv_fac[x] * fac[x - y];
}
