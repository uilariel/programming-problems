#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define ll long long

void solve() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  vector<ll> prefix1;
  vector<ll> sufix0;
  ll c1 = 0;
  ll c0 = 0;
  ll f1 = -1;
  // encontrar primeiro 1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      f1 = i;
      break;
    }
  }

  for (ll i = 0; i < n; i++) {
    if (s[i] == '1') {
      c1++;
    }
    prefix1.push_back(c1);
  }

  for (ll i = n - 1; i >= 0; i--) {
    if (s[i] == '0') {
      c0++;
    }

    sufix0.push_back(c0);
  }

  reverse(sufix0.begin(), sufix0.end());

  sufix0.push_back(0);

  ll r0;
  if (f1 != -1) {
    r0 = sufix0[f1];
  } else {
    r0 = n;
  }
  ll r1 = LLONG_MAX;
  for (ll i = 0; i < n; i++) {
    r1 = min(prefix1[i] + sufix0[(i + 1)], r1);
  }

  if (s[0] == '1') {
    cout << c0 << endl;
    return;
  }

  cout << min(r0, r1) << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
