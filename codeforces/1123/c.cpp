#include <bits/stdc++.h>
#include <climits>
#include <functional>
using namespace std;

#define ll long long

void solve() {
  ll n, x;
  cin >> n;
  cin >> x;
  vector<ll> nums(n);
  ll sum = 0;
  for (ll i = 0; i < n; i++) {
    cin >> nums[i];
  }
  vector<ll> divs;
  for (int i = 1; i * i <= x; i++) {

    if (x % i == 0) {
      divs.push_back(i);

      if (i != x) {
        divs.push_back(x / i);
      }
    }
  }

  ll resposta = 0;
  for (int i = 0; i < divs.size(); i++) {
    for (int j = 0; j < n; j++) {
      if (nums[j] % divs[i] == 0 && divs[i] != 1) {
        sum = sum + nums[j];
      }
    }
    resposta = max(resposta, sum);
    sum = 0;
  }

  cout << resposta << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
