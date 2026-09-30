#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll MOD = 1000000000 + 7;
void solve() {
  ll n;
  cin >> n;
  char vetor[n][n];

  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      cin >> vetor[i][j];
    }
  }
  ll dp[n + 1][n + 1];
  for (int i = 0; i <= n; i++) {
    dp[0][i] = 0;
  }
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }
  if (vetor[0][0] == '*') {
    cout << 0;
    return;
  }
  dp[1][1] = 1;

  for (ll i = 1; i <= n; i++) {

    for (ll j = 1; j <= n; j++) {
      if (i == 1 && j == 1) {
        continue;
      }
      if (vetor[i - 1][j - 1] == '*') {
        dp[i][j] = 0;
        continue;
      } else {
        dp[i][j] = ((dp[i - 1][j] % MOD) + (dp[i][j - 1]) % MOD) % MOD;
      }
    }
  }

  cout << dp[n][n];
  /*
    for (ll i = 0; i <= n; i++) {
      for (ll j = 0; j <= n; j++) {
        cout << dp[i][j] << " ";
      }
      cout << endl;
    }
    */
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
