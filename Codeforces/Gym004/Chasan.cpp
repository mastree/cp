#include <bits/stdc++.h>

using namespace std;

// #define mp make_pair

const int N = 1e3 + 5;
const int INF = 1e9;

struct canvas {
  int l, r;
};

int n, p;
int dp[N][3];
pair<> par[N][3];
int cnt[N];
canvas c[N];
map<int, int> mp;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c[i].l >> c[i].r;
  }
  cin >> p;
  for (int i = 1; i <= p; i++) {
    int x;
    cin >> x;
    mp[x]++;
    for (int j = 1; j <= n; j++) {
      if (c[j].l <= x && x <= c[j].r) cnt[j]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (cnt[i] > 2) {
      cout << "Impossible" << '\n';
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      dp[i][j] = INF;
    }
  }
  c[0].r = -1;
  for (int i = 1; i <= n; i++) {
    for (int j = cnt[i]; j <= 2; j++) {
      dp[i][j] = j - cnt[i] + dp[i - 1][2];
      par[i][j] = mp(i-1, 2);
    }
    int j = cnt[i];
    if (c[i - 1].r == c[i].l && !mp.count(c[i].l) && j < 2) {
        if (dp[i][j + 1] > dp[i - 1][1] + 1){
            par[i][j + 1] = mp(i - 1, 1);
        }
      dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][1] + 1);
    }
    dp[i][2] = min(dp[i][2], dp[i][1] + 1);
    // cout << i << " => " << dp[i][1] << " => " << dp[i][2] << '\n';
  }
  cout << dp[n][2] << '\n';
}