vector<pair<int, ll>> adj[200000]; // adjacency list
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq; // min heap
vector<ll> dist(n+1, INF); // nodes , distances

// init edges 

dist[1]=0;
pq.push({0, 1});
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

// for(int i=1; i<=n; ++i) cout << dist[i] << " ";
