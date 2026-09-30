#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define ll long long

void solve() {
  ll n;
  cin >> n;

  vector<ll> dp(n + 1, LLONG_MAX / 2);

  dp[0] = 0;

  for (ll i = 1; i <= n; i++) {
    string numero = to_string(i);

    if (numero.size() == 1) {
      dp[i] = 1;
    } else {
      for (ll j = 0; j < numero.size(); j++) {
        ll num = numero[j] - '0';
        dp[i] = min(dp[i - num] + 1, dp[i]);
      }
    }
  }

  cout << dp[n] << endl;
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
