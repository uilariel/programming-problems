#include <bits/stdc++.h>
#include <memory>
using namespace std;

#define ll long long

ll n, m;

vector<vector<char>> matriz;
vector<vector<bool>> visitado;
ll counter = 0;

void dfs(ll i, ll j) {
  if (i >= n)
    return;
  if (i < 0)
    return;
  if (j >= m)
    return;
  if (j < 0)
    return;
  if (matriz[i][j] == '#')
    return;
  if (visitado[i][j] == true)
    return;
  visitado[i][j] = true;
  dfs(i + 1, j);
  dfs(i - 1, j);
  dfs(i, j + 1);
  dfs(i, j - 1);
}

void solve() {
  cin >> n >> m;

  matriz.assign(n, vector<char>(m));
  visitado.assign(n, vector<bool>(m, false));
  for (ll i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> matriz[i][j];
    }
  }

  for (ll i = 0; i < n; i++) {

    for (int j = 0; j < m; j++) {
      if (visitado[i][j] == false && matriz[i][j] != '#') {
        dfs(i, j);
        counter++;
      }
    }
  }

  cout << counter << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t;
  while (t--)
    solve();

  return 0;
}
