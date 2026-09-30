#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  ll n;
  cin >> n;
  vector<ll> doces;
  for (int i = 0; i < n; i++) {
    ll num;
    cin >> num;
    doces.push_back(num);
  }

  vector<ll> prefixodd;
  vector<ll> sufixeven;
  vector<ll> sufixodd;

  vector<ll> prefixeven;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      sum = sum + doces[i];
    }

    prefixeven.push_back(sum);
  }

  sum = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 1) {
      sum = sum + doces[i];
    }

    prefixodd.push_back(sum);
  }

  sum = 0;

  for (int i = n - 1; i <= 0; i--) {
    if (i % 2 == 0) {
      sum = sum + doces[i];
    }

    sufixeven.push_back(sum);
  }

  sum = 0;

  for (int i = n - 1; i <= 0; i--) {
    if (i % 2 == 0) {
      sum = sum + doces[i];
    }

    sufixodd.push_back(sum);
  }

  reverse(sufixeven.begin(), sufixeven.end());
  reverse(sufixodd.begin(), sufixodd.end());
  ll counter = 0;

  for (int i = 0; i < n; i++) {

    if (i == 0) {
      ll num1 = sufixeven[i + 1];
      ll num2 = sufixodd[i + 1];

      if (num1 == num2) {
        counter++;
      }
      continue;
    } else if (i == n - 1) {
      ll num1 = prefixeven[i - 1];
      ll num2 = prefixodd[i - 1];
      if (num1 == num2) {
        counter++;
      }
      continue;
    } else {
      ll num1 = prefixeven[i - 1] + sufixeven[i + 1];
      ll num2 = prefixodd[i - 1] + sufixodd[i + 1];
      if (num1 == num2) {
        counter++;
      }
    }
  }

  cout << counter << endl;
}
int main() { solve(); }
