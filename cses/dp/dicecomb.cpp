#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007
void solve() {
  ll n;
  cin >> n;
  vector<ll> dp(n + 7);

  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  dp[4] = 8;
  dp[5] = 16;
  dp[6] = 32;

  if (n <= 6) {
    cout << dp[n] << endl;
    return;
  }
  for (int i = 7; i <= n; i++) {
    dp[i] = dp[i - 1] % MOD + dp[i - 2] % MOD + dp[i - 3] % MOD +
            dp[i - 4] % MOD + dp[i - 5] % MOD + dp[i - 6] % MOD;
  }

  cout << (dp[n]) % 1000000007 << endl;
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
