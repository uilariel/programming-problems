#include <bits/stdc++.h>
#include <climits>
typedef long long ll;
using namespace std;

void solve() {

  ll n;
  cin >> n;
  ll mini = LONG_LONG_MAX;
  for (int i = 0; i < 3; i++) {
    ll num;
    cin >> num;
    mini = min(mini, num);
  }

  cout << n - mini << endl;
}

int main() {
  ll t;

  cin >> t;
  while (t--) {
    solve();
  }
}
