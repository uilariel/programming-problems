#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define ll long long

void solve() {
  ll n;
  ll x;
  cin >> n >> x;
  vector<ll> coins(n, 0);

  for (ll i = 0; i < n; i++) {
    ll num;
    cin >> num;
    coins[i] = num;
  }

  vector<ll> dp(x + 1, LLONG_MAX / 2);
  dp[0] = 0;

  for (ll i = 1; i <= x; i++) {
    for (ll j = 0; j < n; j++) {
      if (i >= coins[j] && dp[i - coins[j]] != LLONG_MAX / 2) {
        dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
      }
    }
  }

  ll mincoins = dp[x];

  if (mincoins == LLONG_MAX / 2) {
    cout << -1 << endl;
  } else {
    cout << dp[x] << endl;
  }
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
