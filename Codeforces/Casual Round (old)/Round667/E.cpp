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

int q;
int n, k;
int ar[N];

int cnt[N];

void solve(){
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=n;i++){
        int temp;
        cin >> temp; // dummy;
    }
    sort(ar + 1, ar + n + 1);
    fill(cnt, cnt + n + 2, 0);
    {
        int r = 1;
        for (int l=1;l<=n;l++){
            r = max(r, l);
            while (r < n && ar[r + 1] - ar[l] <= k) r++;
            cnt[l] = r - l + 1;
        }
    }
    set<pii> setdah;
    for (int i=1;i<=n;i++){
        setdah.insert(mp(cnt[i], i));
    }
    int last = 0;
    int ans = 0;
    for (int l=1;l<=n;l++){
        int r = l + cnt[l] - 1;
        while (last < r){
            last++;
            setdah.erase(mp(cnt[last], last));
        }
        int cur = cnt[l];
        if (!setdah.empty()) cur += setdah.rbegin()->fi;
        ans = max(ans, cur);
    }
    cout << ans << el;
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