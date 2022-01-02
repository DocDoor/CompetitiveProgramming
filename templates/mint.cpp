struct mint {
    int val = 0;
 
    mint(long long a = 0) : val(a % MOD) {if (val < 0) val += MOD;}
    mint(long long a, long long b) {*this += a; *this /= b;}
 
    mint &operator += (const mint &b) {val += b.val; if(val >= MOD) val -= MOD; return *this;}
    mint &operator -= (const mint &b) {val -= b.val; if(val < 0) val += MOD; return *this;}
    mint &operator *= (const mint &b) {val = (1ll * val * b.val) % MOD; return *this;}
 
    mint mexp(mint a, long long b) {
        mint c(1);
        for(; b > 0; b /= 2, a *= a) if (b & 1) c *= a;
        return c;
    }
 
    mint minv(const mint &a) {return mexp(a, MOD - 2);};
 
    mint &operator /= (const mint &b) {*this *= minv(b); return *this;}
 
    friend mint operator + (mint a, const mint &b) {return a += b;}
    friend mint operator - (mint a, const mint &b) {return a -= b;}
    friend mint operator - (const mint &a) {return 0 - a; }
    friend mint operator * (mint a, const mint &b) {return a *= b;}
    friend mint operator / (mint a, const mint &b) {return a /= b;}
 
    friend bool operator == (const mint &a, const mint &b) {return a.val == b.val;}
    friend bool operator != (const mint &a, const mint &b) {return a.val != b.val;}
 
    friend istream &operator >> (istream &is, mint &a) {long long b; is >> b; a = b; return is;}
    friend ostream &operator << (ostream &os, const mint &a) {return os << a.val;}
};
