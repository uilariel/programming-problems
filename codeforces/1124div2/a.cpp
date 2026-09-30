#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
  ll n;
  ll k;

  cin >> n >> k;

  ll pot = n - k;

  if (pot != 1) {
    pot++;
  }

  ll num = pow(2, pot);
  ll restante = 2 * (n - pot);

  cout << num + restante << endl;
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
