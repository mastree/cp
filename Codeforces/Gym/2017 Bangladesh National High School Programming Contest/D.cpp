#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e4 + 10;

int n, q;
int ar[N];

void solve() {
    cin >> n;

    int x = 0;
    for (int i=1;i<=n;i++) {
        cin >> ar[i];
        x ^= ar[i];
    }
    int cnt = 0;
    for (int i=1;i<=n;i++) {
        if ((ar[i] ^ x) < ar[i]) {
            cnt++;
        }
    }
    cout << cnt << '\n';
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int i=1;i<=q;i++) {
        cout << "Case " << i << ": ";
        solve();
    }    

    return 0;
}