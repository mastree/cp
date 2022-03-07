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

int q;
int n;
ll x, ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> x;
        for (int i=1;i<=n;i++) cin >> ar[i];
        sort(ar + 1, ar + n + 1, greater<ll>());
        ll ans = 0, cnt = 0;
        for (int i=1;i<=n;i++){
            cnt++;
            if (ar[i] * cnt >= x){
                ans++;
                cnt = 0;
            }
        }
        cout << ans << el;
    }

    return 0;
}