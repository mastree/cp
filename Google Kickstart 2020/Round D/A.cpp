#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;

int n, q;
int ar[N], le[N];

void solve(){
    cin >> n;
    le[0] = -1;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        le[i] = max(ar[i], le[i - 1]);
    }
    ar[n + 1] = -1;
    int ans = 0;
    for (int i=1;i<=n;i++){
        if (ar[i] > le[i - 1] && ar[i] > ar[i + 1]) ans++;
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int cas=1;cas<=q;cas++){
        cout << "Case #" << cas << ": ";
        solve();
    }

    return 0;
}