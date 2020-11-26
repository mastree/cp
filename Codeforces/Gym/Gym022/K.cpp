#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;
const int INF = 1e9;

int q;
int n, k;
int ar[N];
int cnt[N];

void solve(){
    cin >> n >> k;
    fill(cnt, cnt + n + 2, 0);
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        cnt[ar[i]]++;
    }
    int ans = INF;
    for (int i=1;i<=n;i++){
        cnt[ar[i]]--;
        if (ar[i] == 0) continue;
        if (k % ar[i] == 0){
            int temp = k / ar[i];
            if (cnt[temp]){
                ans = min(ans, min(ar[i], temp));
            }
        }
    }
    if (ans == INF) cout << -1 << el;
    else cout << ans << " " << k / ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}