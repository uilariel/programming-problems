#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define ll long long
ll MOD = 1000000000 + 7;
void solve() {
  ll n, x;
  cin >> n >> x;
  vector<ll> coins;
  for (int i = 0; i < n; i++) {
    ll num;
    cin >> num;
    coins.push_back(num);
  }

  vector<ll> dp(x + 1, 0);
  dp[0] = 1;
  for (int i = 0; i <= x; i++) {
    ll sum = 0;
    for (ll j = 0; j < coins.size(); j++) {
      ll c = coins[j];
      if (i >= c) {
        dp[i] = (dp[i] + dp[i - c]);
      }

      if (dp[i] >= MOD)
        dp[i] = dp[i] - MOD;
    }
  }

  cout << dp[x] << endl;
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
