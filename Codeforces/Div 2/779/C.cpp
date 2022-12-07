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

int c[N];

void solve(){
    int n;
    cin >> n;
    int pos = -1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        if (c[i] == 1) {
            cnt++;
            pos = i;
        }
    }
    if (cnt != 1) {
        cout << "NO\n";
        return;
    }
    bool ok = 1;
    int last = 1;
    for (int offset = 1; offset < n; offset++) {
        int i = (pos + offset) % n;
        if (1 < c[i] && c[i] <= last + 1) {
            last = c[i];
        } else {
            ok = 0;
            break;
        }
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        solve();
    }    

    return 0;
}