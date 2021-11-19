#include <bits/stdc++.h> 
using namespace std;
 
#define ll long long
#define pb push_back
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
 
#define trav(i, x) for(auto &i : x)
#define FOR(i, n) for(int i=0; i<n; ++i)
 
void solve() {
	int n;
	cin >> n;
	map<int, int> mp;
	for(int i=0; i<n; ++i) {
		int x;
		cin >> x;
		mp[x]=i;
	}
	int ans=0;
	for(int i=n; i>0; --i) {
		if(mp[i]<mp[i-1]) ++ans;
	}
	cout << ++ans;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc=1;
	// cin >> tc;
	while(tc--) {
		solve();
	}
}
