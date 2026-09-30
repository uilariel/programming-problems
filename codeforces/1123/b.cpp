#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
  ll n;
  cin >> n;
  vector<ll> pool(100 + 1, 0);

  for (int i = 1; i <= n; i++) {
    ll num;
    cin >> num;
    pool[num]++;
  }
  bool zerou = true;
  while (zerou) {
    zerou = false;
    for (int i = 100; i >= 1; i--) {
      if (pool[i] > 0) {
        cout << i << " ";
        pool[i]--;
        zerou = true;
      }
    }
  }

  cout << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
