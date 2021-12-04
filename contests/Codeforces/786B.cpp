// problem link -> https://codeforces.com/contest/786/problem/B

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

const ll mxN=5e5+5, INF=2e18+5;
vt<pair<ll, ll>> adj[2*mxN];
ll n, q, s, dist[mxN*2+1];
bool vis[mxN*2+1];

void build(ll cur, ll l, ll r) {
	if(l==r) {
		adj[cur+n].pb({l, 0});
		adj[l].pb({cur+n+mxN, 0});
	} else {
		ll mid=(l+r)/2;
		build(cur*2, l, mid);
		build(cur*2+1, mid+1, r);
		ll left=cur*2, right=cur*2+1;
		adj[cur+n].pb({left+n, 0});
		adj[n+left+mxN].pb({cur+mxN+n, 0});
		adj[cur+n].pb({right+n, 0});
		adj[n+right+mxN].pb({cur+mxN+n, 0});
	}
}

void update(ll from, ll to, ll type, ll weight, ll v, ll cur, ll l, ll r) {
	if(l>to||from>r) {
		return;
	} if(from<=l&&r<=to) {
		if(type==2) {
			adj[v].pb({cur+n, weight});
		} else {
			adj[cur+mxN+n].pb({v, weight});
		}
		return;
	}
	ll mid=(l+r)/2, left=cur*2, right=cur*2+1;
	update(from, to, type, weight, v, left, l, mid);
	update(from, to, type, weight, v, right, mid+1, r);
}

void solve() {
	cin >> n >> q >> s;
	build(1, 1, n);
	memset(dist, 0x3f, sizeof(dist));
	memset(vis, 0, sizeof(vis));
	while(q--) {
		ll type, v, from, to, weight;
		cin >> type;
		if(type==1) {
			cin >> from >> to >> weight;
			adj[from].pb({to, weight});
		} else {
			cin >> v >> from >> to >> weight;
			update(from, to, type, weight, v, 1, 1, n);
		}
	}
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq; // min heap
	dist[s]=0;
	pq.push({0, s});
	while(pq.size()) {
  		auto [d, u]=pq.top(); pq.pop();
  		if(d>dist[u]) continue;
  		for(auto [v, w] : adj[u]) {
    		if(dist[v]>dist[u]+w) {
      			dist[v]=dist[u]+w;
      			pq.push({dist[v], v});
    		}
  		}
	}
	for(int i=1; i<=n; ++i) cout << (dist[i]==dist[2*mxN]?-1:dist[i]) << " ";
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
