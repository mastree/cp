#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int INF = 1e9 + 10;

int q;
int w, h;
int x[2], y[2];
int w2, h2;

void solve(){
    cin >> w >> h;
    for (int i=0;i<2;i++){
        cin >> x[i] >> y[i];
    }
    cin >> w2 >> h2;
    int w1 = x[1] - x[0];
    int h1 = y[1] - y[0];
    if (w1 > w || w2 > w || h1 > h || h2 > h || (w1 + w2 > w && h1 + h2 > h)){
        cout << -1 << el;
        return;
    }
    int ans = INF;
    // atas
    if (h1 + h2 <= h){
        int gap = h - y[1];
        int kur = max(0, h2 - gap);
        ans = min(ans, kur);
    }
    // bawah
    if (h1 + h2 <= h){
        int gap = y[0];
        int kur = max(0, h2 - gap);
        ans = min(ans, kur);
    }
    // kanan
    if (w1 + w2 <= w){
        int gap = w - x[1];
        int kur = max(0, w2 - gap);
        ans = min(ans, kur);
    }
    // kiri
    if (w1 + w2 <= w){
        int gap = x[0];
        int kur = max(0, w2 - gap);
        ans = min(ans, kur);
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