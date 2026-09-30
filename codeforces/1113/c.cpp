#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
  ll n;
  cin >> n;
  vector<ll> v((2 * n) + 1);
  for (int i = 1; i <= 2 * n; i++) {
    cin >> v[i];
  }
  vector<ll> dp(2 * n + 1, 0);
  vector<ll> first(n + 1);
  vector<ll> second(n + 1, false);
  vector<ll> segundo(n + 1, 0);
  for (ll i = 1; i <= 2 * n; i++) {

    ll numero = v[i];
    if (second[numero] == false) {
      first[numero] = i;
      second[numero] = true;

    } else {
      segundo[numero] = i;
    }
  }

  dp[0] = 0;
  for (ll i = 1; i <= 2 * n; i++) {
    ll numero = v[i];
    if (first[numero] == i) {
      dp[i] = dp[i - 1] + 1;
    } else {
      ll total = (segundo[numero] - first[numero] + 1);
      total = total * total;
      dp[i] = max(dp[i - 1] + 1, dp[first[numero] - 1] + total);
    }
  }

  cout << dp[2 * n] << endl;
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
