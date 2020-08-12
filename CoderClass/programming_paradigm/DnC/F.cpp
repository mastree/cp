#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 110, MX = 3e4 + 100;

int n;
int ar[N];
unordered_map<ll, ll> cnt;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            for (int k=1;k<=n;k++){
                if (ar[k] == 0) continue;
                cnt[1LL * (ar[i] + ar[j]) * ar[k]]++;
            }
        }
    }
    ll ans = 0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            for (int k=1;k<=n;k++){
                ans += cnt[1LL * ar[i] * ar[j] + ar[k]];
            }
        }
    }
    cout << ans << el;

    return 0;
}