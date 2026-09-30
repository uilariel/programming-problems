#include <bits/stdc++.h>
#include <execution>
using namespace std;

#define ll long long
ll n, m;
vector<vector<ll>> adj;
vector<bool> visitado;
vector<ll> parents;
vector<ll> nivel;

void dfs(ll inicio, ll destino) {
  queue<ll> q;
  q.push(inicio);
  visitado[inicio] = true;
  parents[inicio] = -1;
  while (q.size() > 0) {
    int v = q.front();
    q.pop();
    for (ll i = 0; i < adj[v].size(); i++) {
      ll u = adj[v][i];
      if (adj[v].empty() || visitado[u] == true) {
        continue;
      }
      visitado[u] = true;
      q.push(u);
      nivel[u] = nivel[v] + 1;
      parents[u] = v;
    }
  }

  if (visitado[destino] == true) {
    cout << nivel[destino] + 1 << endl;
    vector<ll> s;
    ll path = destino;
    while (parents[path] != -1) {
      s.push_back(path);
      path = parents[path];
      if (parents[path] == -1) {
        s.push_back(1);
      }
    }
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++) {
      cout << s[i] << " ";
    }
    cout << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}
void solve() {
  cin >> n >> m;
  adj.assign(n + 1, vector<ll>());
  visitado.assign(n + 1, false);
  parents.assign(n + 1, -1);
  nivel.assign(n + 1, 0);
  for (ll i = 0; i < m; i++) {
    ll c1;
    cin >> c1;
    ll c2;
    cin >> c2;
    adj[c1].push_back(c2);
    adj[c2].push_back(c1);
  }
  dfs(1, n);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  //   cin >> t;
  while (t--)
    solve();

  return 0;
}
