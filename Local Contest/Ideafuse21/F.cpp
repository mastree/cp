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
const int INF = 1e9 + 10;

int tc;
int n, q;
vector<pii> pts;
// vector<pii> quers;

void solve(){
    cin >> n >> q;
    pts.clear();
    pts.emplace_back(-INF, 2);
    for (int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        pts.emplace_back(a, b);
    }
    sort(pts.begin(), pts.end());
    pts.emplace_back(INF + INF, 2);
    while (q--){
        int pos, k;
        cin >> pos >> k;
        int l = 0, r = n + 1;
        while (l < r){
            int m = (l + r) / 2;
            if (pts[m].fi >= pos){
                r = m;
            } else{
                l = m + 1;
            }
        }
        l--;
        int cnt[2] = {0, 0}, cur = 0;
        while (cur < k){
            if (pts[r].fi - pos <= pos - pts[l].fi){
                cnt[pts[r].se]++;
                r++;
            } else{
                cnt[pts[l].se]++;
                l--;
            }
            cur++;
        }
        if (cnt[1] > cnt[0]) cout << 1 << el;
        else cout << 0 << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int i=1;i<=tc;i++){
        cout << "Case #" << i << ":\n";
        solve();
    }

    return 0;
}