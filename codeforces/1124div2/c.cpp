#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<ll> prefixsum(vector<ll> v) {
  vector<ll> psum;
  ll sum = 0;
  for (ll i = 0; i < v.size(); i++) {
    sum = sum + v[i];
    psum.push_back(sum);
  }
  return psum;
}
void solve() {
  ll n;
  ll k;
  cin >> n >> k;
  ll sum = 0;
  ll counter = n - k + 1;
  vector<ll> v(n + 1, 0);
  vector<ll> p1;
  vector<ll> p2;
  for (ll i = 1; i <= n; i++) {
    cin >> v[i];
  }
  if (n == k) {
    cout << max(v[1], v[k]) << endl;
    return;
  }
  if (k < n / 2) {
    for (ll i = 2; i <= n; i++) {
      sum = sum + v[i];
    }
  } else {

    for (ll i = k; i < counter; i++) {
      p1.push_back(v[i]);
    }
    vector<ll> p1sum = prefixsum(p1);
    for (ll i = n - k + 1; i <= n; i++) {
      p2.push_back(v[i]);
    }
    vector<ll> p2sum = prefixsum(p2);
    for (int i = 0; i < p1sum.size(); i++) {
      sum = max(sum, p1sum[i] + p2sum[p2sum.size() - 1 - i]);
    }
  }

  cout << sum << endl;
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
