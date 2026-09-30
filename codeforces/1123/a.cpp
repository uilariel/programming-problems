#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
  ll n;
  char c;
  string s;
  cin >> n;
  cin >> c;
  cin >> s;

  ll low = 0;
  ll high = n - 1;
  ll counter = 0;
  while (low < high) {

    if (s[low] == s[high]) {
      low++;
      high--;
      continue;
    } else {
      if (s[low] != c) {
        counter++;
      }
      if (s[high] != c) {
        counter++;
      }

      low++;
      high--;
      continue;
    }
  }

  cout << counter << endl;
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
