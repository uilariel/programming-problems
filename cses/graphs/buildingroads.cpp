#include <bits/stdc++.h>
#include <iterator>
using namespace std;

#define ll long long
ll n, m;
vector<vector<ll>> adj;
vector<bool> visitado;

vector<ll> roads;
ll counter = 0;
void dfs(ll u) {
  visitado[u] = true;
  for (ll i = 0; i < adj[u].size(); i++) {
    ll num = adj[u][i];
    if (visitado[num] == true)
      continue;
    if (visitado[num] == false) {
      visitado[num] = true;
      dfs(num);
    }
  }
}
void solve() {
  cin >> n >> m;

  visitado.assign(n + 1, false);
  adj.assign(n + 1, vector<ll>());

  for (ll i = 0; i < m; i++) {
    ll rua1, rua2;
    cin >> rua1 >> rua2;
    adj[rua1].push_back(rua2);
    adj[rua2].push_back(rua1);
  }

  for (ll i = 1; i <= n; i++) {
    if (visitado[i] == false) {
      dfs(i);
      counter++;
      roads.push_back(i);
    }
  }
  cout << counter - 1 << endl;
  for (int i = 0; i < roads.size() - 1; i++) {
    cout << roads[i] << " " << roads[i + 1] << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  //: whilecin >> t;
  while (t--)
    solve();

  return 0;
}
