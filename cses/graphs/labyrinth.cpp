#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<vector<char>> lab;
vector<vector<bool>> visitados;
vector<vector<ll>> dist;
vector<vector<char>> paths;
ll ia;
ll ja;
ll jb;
ll ib;
ll n, m;
ll nivel = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char d[4] = {'D', 'U', 'R', 'L'};
queue<pair<ll, ll>> q;

bool bfs(ll i, ll j) {
  q.push({i, j});
  visitados[i][j] = true;
  nivel = 0;
  dist[ia][ja] = 0;
  while (q.size() > 0) {
    pair<ll, ll> cord = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      /*
       baixo = i + 1 | j
       cima = i - 1 | j
       direita =  i | j + 1
       esquerda = i | j - 1
       */
      ll ni = cord.first + dx[i];
      ll nj = cord.second + dy[i];

      if (ni < 0 || ni >= n || nj < 0 || nj >= m)
        continue;

      if (lab[ni][nj] == '#' || visitados[ni][nj] == true)
        continue;
      visitados[ni][nj] = true;
      paths[ni][nj] = d[i];
      dist[ni][nj] = dist[cord.first][cord.second] + 1;
      q.push({ni, nj});
    }
  }

  if (visitados[ib][jb] == true) {
    cout << "YES" << "\n" << dist[ib][jb] << "\n";

    ll c1 = ib;
    ll c2 = jb;
    string seq;
    while (lab[c1][c2] != 'A') {
      if (paths[c1][c2] == 'D') {
        seq.push_back('D');
        c1--;
      } else if (paths[c1][c2] == 'L') {
        seq.push_back('L');
        c2++;
      } else if (paths[c1][c2] == 'R') {
        seq.push_back('R');
        c2--;
      } else if (paths[c1][c2] == 'U') {
        seq.push_back('U');
        c1++;
      }
    }
    reverse(seq.begin(), seq.end());
    cout << seq << endl;
    return true;

  } else {
    cout << "NO" << endl;
    return false;
  }
}
void solve() {
  cin >> n >> m;
  lab.assign(n, vector<char>(m));
  visitados.assign(n, vector<bool>(m, false));
  dist.assign(n, vector<ll>(m, 0));
  paths.assign(n, vector<char>(m));
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      cin >> lab[i][j];
      if (lab[i][j] == 'A') {
        ia = i;
        ja = j;
      } else if (lab[i][j] == 'B') {
        ib = i;
        jb = j;
      }
    }
  }

  bfs(ia, ja);
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
