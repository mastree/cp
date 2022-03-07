// Author: https://codeforces.com/profile/Mastre

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e3 + 10;
const ll INF = 1e18;

int n, m;
ll s, t;
ll ar[N], br[N];
ll ans;
ll dp[N * 2];
ll ndp[N * 2];

vector<vector<ll>> vec;

void proc(){
  int id = 1;

  for (int i=1;i<m;i++){
    vector<ll> temp;
    temp.push_back(br[i]);
    while (id <= n && ar[id] <= br[i + 1]){
      temp.push_back(ar[id]);
      id++;
    }
    temp.push_back(br[i + 1]);
    vector<ll> temp2;
    int len = temp.size();
    for (int j=0;j<len - 1;j++){
      temp2.push_back(temp[j + 1] - temp[j]);
    }
    if (temp2.size() >= 2){
      vec.push_back(temp2);
    }
  }
}
void solve(vector<ll>& vec){
  int len = (int) vec.size();
  vector<pair<ll, int>> choice; // length, added
  ll tot = 0;
  vector<ll> pre(len + 1);
  pre[0] = 0;
  for (int i=0;i<len;i++){
    pre[i + 1] = pre[i] + vec[i];
    tot += vec[i];
  }
  choice.push_back({tot, len - 1});

  for (int i=1;i<=len - 1;i++){ // choosen count
    ll mincost = INF;
    for (int le=0;le<=i;le++){
      int ri = i - le;
      ll cost = pre[le] + (pre[len] - pre[len - ri]);
      mincost = min(mincost, 2LL * cost);
    }
    choice.push_back({mincost, i});
  }
  for (int i=0;i<N;i++){
    ndp[i] = dp[i];
  }
  for (int i=0;i<N;i++){
    if (ndp[i] >= INF) break;
    for (auto x : choice){
      dp[i + x.second] = min(dp[i + x.second], ndp[i] + x.first + (ll)x.second);
    }
  }
}

int main(){
  cin >> n >> m >> s >> t;
  for (int i=1;i<=n;i++){
    cin >> ar[i]; // shop
  }
  for (int i=1;i<=m;i++){
    cin >> br[i]; // teleport
  }
  ans = br[1] + s - br[m]; // base
  fill(dp + 1, dp + N, INF);
  proc();
  for (auto x : vec){
    solve(x);
  }
  for (int i=N - 1;i>=0;i--){
    if (ans + dp[i] <= t){
      cout << i << " " << ans + dp[i] << '\n';
      break;
    }
  }

  return 0;
}

/*
Explanation of Code:

The idea of this problem is you first compute the distance 
to the first teleportation device(from start) and the distance 
to the last teleportation device(from finish) since you will need 
to travel that no matter what you do.

And now you can consider yourself always in the teleportation 
device. So if you want to go to some shops, you need to go back 
to any teleportation device immediately after that. This problem 
seems familiar right? yeah, this is now basically becoming a 
knapsack problem. The differences is that you can have many 
combination on how you can go to shops on a certain range (shops 
that have same teleportation device on its left-side and same 
teleportation device on its right-side). Notice that if there are 
N shops on the same range, then you can take 0..N shops on that 
range. And if you take i shops (0 <= i <= N) you will only consider 
the best one right (the one that gives you minimum distance to travel)? 

In that case, you can first pre-compute these distances and then 
perform dynamic programming on all range just like doing regular 
knapsack problem in O(N^2) time complexity.
*/