vector<pair<int, long long>> adj[200000]; // adjacency list
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; // min heap
vector<long long> dist(2e5 + 5, 2e17); // nodes , distances

// init edges 

dist[1] = 0;
pq.push({0, 1});
while (pq.size()) {
  auto [d, u] = pq.top(); pq.pop();
  if (d > dist[u]) continue;
  for (auto [v, w] : adj[u]) {
    if (dist[v] > dist[u] + w) {
      dist[v] = dist[u] + w;
      pq.push({dist[v], v});
    }
  }
}

// for (int i = 1; i <= n; ++i) cout << dist[i] << " ";
