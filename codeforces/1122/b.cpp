#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
using namespace std;

void solve() {

  ll a;
  ll b;
  ll c;
  cin >> a >> b >> c;
  ll ac = a + c;

  ll amaiscmenosb = ac - b;
  ll bmenosa = b - a;

  if (a == b) {
    cout << c << endl;
    return;
  } else if (a < b) {
    if (amaiscmenosb > bmenosa) {
      cout << amaiscmenosb << endl;
      return;
    } else {
      cout << bmenosa << endl;
      return;
    }
  } else if (a > b) {
    cout << amaiscmenosb << endl;
    return;
  }
}

int main() {
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}
