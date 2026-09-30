#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
  string s;
  ll n;
  cin >> n >> s;
  vector<ll> dp(n + 1, 0);
  dp[0] = 0;

  for (ll i = 1; i < n; i++) {
    char last = s[i - 1];
    char current = s[i];

    if (current != last) {
      dp[i] = dp[i - 1] + 1;
    } else {
      dp[i] = dp[i - 1];
    }
  }

  cout << dp[n] << endl;
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
