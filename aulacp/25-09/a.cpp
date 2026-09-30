#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
  vector<ll> pontos;
  for (int i = 0; i < 3; i++) {
    ll num;
    cin >> num;
    pontos.push_back(num);
  }

  sort(pontos.begin(), pontos.end());
  ll menor = pontos[0];
  ll maior = pontos[2];
  ll meio = pontos[1];

  ll total = 0;

  total = (abs(maior - meio) + abs(menor - meio));

  cout << total << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  //: whilecin >> t;
  while (t--)
    solve();

  return 0;
}
