#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> prefixsum(vector<ll> v) {
  ll sum = 0;
  vector<ll> p;
  for (ll i = 0; i < v.size(); i++) {
    sum = sum + v[i];
    p.push_back(sum);
  }

  return p;
}
void solve() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> eventos;
  vector<ll> inicio(1e9, 0);
  vector<ll> final(1e9, 0);

  for (int i = 0; i < n; i++) {
    ll in;
    ll f;
    cin >> in >> f;

    inicio[in]++;
    final[f]++;
  }

  bool valido = true;
  vector<ll> pinicio = prefixsum(inicio);
  vector<ll> pfinal = prefixsum(final);

  for (int i = 0; i < 1e9; i++) {
    ll ligados = pinicio[i];
    ll desligados = pfinal[i];

    if (ligados - desligados > 2) {
      valido = false;
      break;
    }
  }

  if (valido) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
