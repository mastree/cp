#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10;

int n, m;
int iar[N], ar[N];
int ibr[N], br[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=m;i++){
        cin >> br[i];
    }
    unordered_map<int, int> cnt;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cnt[ar[i] - br[j]]++;
        }
    }
    int ans = 0;
    for (auto& x : cnt) ans = max(ans, x.se);
    cout << ans << el;

    return 0;
}