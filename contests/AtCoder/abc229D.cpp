// problem link -> https://atcoder.jp/contests/abc229/tasks/abc229_d

#include <bits/stdc++.h> 
using namespace std;

#define ll long long
#define pb push_back
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second

#define FOR(i, n) for(ll i=0; i<n; ++i)
#define trav(i, a) for(auto &i : a)

const int mxN=2e5+5;

void solve() {
	string s;
	cin >> s;
	int k, n=sz(s);
	cin >> k;
	vector<int> seg(n+1, 0);
	for(int i=0; i<n; ++i) {
		if(s[i]=='.') seg[i+1]=seg[i]+1;
		else seg[i+1]=seg[i];
	}
	ll ans=0, r=0;
	for(int l=0; l<n; ++l) {
		while(r<n&&seg[r+1]-seg[l]<=k){
        	r=r+1;
        }
        ans=max(ans, r-l);
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	// cin >> t;
	while(t--) {
		solve();
	}
}
