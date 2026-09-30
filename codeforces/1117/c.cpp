#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<ll>> filhos;
vector<bool> cameras;
vector<bool> visited;
ll maior = 0;
// 1-> encontrar o ponto mais fundo com dfs, subir de forma progressiva;
ll dfs(ll raiz) {
  visited[raiz] = true;
  ll nivel = 0;
  for (ll pais = 1; pais <= filhos.size(); pais++) {
    for (ll j = 0; j < filhos[pais].size(); j++) {

      if (visited[filhos[pais][j]] == true) {
        continue;
      }
      if (filhos[pais].empty()) {

        return;
      }
      raiz = filhos[pais][j];
      dfs(raiz);
    }
  }
}

void solve() {
  ll n;
  cin >> n;
  cameras.assign(n + 1, false);
  filhos.assign(n + 1, vector<ll>());
  visited.assign(n + 1);
  for (ll i = 1; i <= n; i++) {
    ll num;
    cin >> num;
    filhos[num].push_back(i + 1);
  }
  ll m;
  cin >> m;
  for (ll i = 1; i <= m; i++) {
    cameras[i] = true;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
