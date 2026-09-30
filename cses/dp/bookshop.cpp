#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
  ll n, x;
  cin >> n >> x;

  vector<ll> custo(n);
  vector<ll> pag(n);
  for (ll i = 0; i < n; i++) {
    cin >> custo[i];
  }
  for (ll i = 0; i < n; i++) {
    cin >> pag[i];
  }

  // dp[livros][orçamento]
  vector<vector<ll>> dp(n + 1, vector<ll>(x + 1, 0));

  for (int i = 0; i < n; i++) {
    dp[0][i] = 0;
  }

  for (ll livros = 1; livros <= n; livros++) {

    for (ll dinheiro = 0; dinheiro <= x; dinheiro++) {
      ll preco = custo[livros - 1];
      ll paginas = custo[livros - 1];
      ll restante = dinheiro - preco;
      if (dinheiro >= preco) {
        ll total = dp[dinheiro - preco][livros] + dp[restante][livros];
        dp[livros][dinheiro] =
            max({total, dp[dinheiro][livros - 1], pag[livros - 1]});
      } else {
        dp[livros][dinheiro] = 0;
      }
    }
  }

  cout << dp[n][x];
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
