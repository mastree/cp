#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 3e5 + 10;

int q;
int n, m;
int ar[N];

void solve(){
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        ar[a] = i;
    }
    vector<int> cnt(n + 1, 0);
    for (int i=1;i<=n;i++){
        cnt[(n + ar[i] - i) % n]++;
    }
    vector<int> ans;
    vector<int> udh(n + 1, 0);
    for (int i=0;i<n;i++){
        int sisa = n - cnt[i];
        if (sisa > m + m) continue;
        int saik = 0;
        fill(udh.begin(), udh.end(), 0);
        {
            int tam = (n - i) % n;
            for (int i=1;i<=n;i++){
                if (udh[i]) continue;
                saik++;
                int cur = i;
                while (!udh[cur]){
                    udh[cur] = 1;
                    cur = ar[cur] + tam;
                    if (cur > n) cur -= n;
                }
            }
        }
        if (n - saik <= m) ans.pb(i);
    }
    cout << ans.size() << ' ';
    for (auto& x : ans) cout << x << ' ';
    cout << el;
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