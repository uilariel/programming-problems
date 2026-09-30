#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll MOD = 1000000007;
void solve() {
  ll x, n;
  cin >> n;
  cin >> x;

  vector<ll> coins(n);
  vector<ll> dp(x + 1, 0);
  dp[0] = 1;
  for (ll i = 0; i < n; i++) {
    cin >> coins[i];
  }
  sort(coins.begin(), coins.end());
  for (ll moedas = 0; moedas < n; moedas++) {
    ll c = coins[moedas];
    for (ll num = 0; num <= x; num++) {

      if (num >= c) {
        dp[num] = dp[num] + dp[num - c];
      }

      if (dp[num] >= MOD)
        dp[num] -= MOD;
    }
  }

  cout << dp[x] << endl;
}
signed main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);

  int t = 1;
  // cin >> t;
  while (t--)
    solve();

  return 0;
}
