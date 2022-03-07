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
int n, k;
pii ar[N];

void solve(){
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi;
        ar[i].se = i;
    }
    sort(ar + 1, ar + n + 1);
    int cnt = 1;
    for (int i=2;i<=n;i++){
        if (ar[i].se == ar[i - 1].se + 1) continue;
        cnt++;
    }
    if (cnt > k) cout << "NO" << el;
    else cout << "YES" << el;
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