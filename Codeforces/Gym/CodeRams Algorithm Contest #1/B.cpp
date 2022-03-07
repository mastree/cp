#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 110;

int n, k;
int ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    int ans = 0;
    for (int i=1;i<=n;i++){
        int mn = ar[i];
        int mx = ar[i];
        for (int j=i;j<=n;j++){
            mn = min(mn, ar[j]);
            mx = max(mx, ar[j]);
            if (mx - mn == k) ans++;
        }
    }
    cout << ans << el;

    return 0;
}