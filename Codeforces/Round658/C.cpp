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
int n, x, y;
int ar[N], ans[N];
int cnt[N];

vector<int> pos[N];

void solve(){
    cin >> n >> x >> y;
    fill(cnt, cnt + n + 3, 0);
    fill(ans, ans + n + 3, 0);
    for (int i=1;i<=n + 1;i++){
        pos[i].clear();
    }

    int none = -1;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        cnt[ar[i]]++;
        pos[ar[i]].pb(i);
    }

    set<pii> setdah;
    for (int i=1;i<=n + 1;i++){
        if (cnt[i] == 0) none = i;
        setdah.insert(mp(cnt[i], i));
    }

    int slot = n;
    while (x){
        auto temp = *setdah.rbegin();
        setdah.erase(temp);

        cnt[temp.se]--;
        x--;
        y--;
        slot--;
        ans[pos[temp.se].back()] = temp.se;
        pos[temp.se].pop_back();

        setdah.insert(mp(cnt[temp.se], temp.se));
    }
    bool ok = 1;
    vector<int> ambil;
    vector<pii> vsisa;
    for (int i=1;i<=n + 1;i++){
        if (cnt[i]) vsisa.pb(mp(cnt[i], i));
    }
    sort(vsisa.begin(), vsisa.end());
    
    int len = vsisa.size();
    int sisaambil = len;
    int alt = -1, mnalt = N;
    int lastid;
    for (int i=0;i<len && y;i++){
        int avg = (sisaambil + y - 1) / sisaambil;
        int cur = min(avg, vsisa[i].fi);

        sisaambil--;
        y -= cur;
        for (int j=0;j<cur;j++){
            ambil.pb(vsisa[i].se);
        }
        vsisa[i].fi -= cur;
        lastid = i;
    }
    int butuh = ambil.size();
    deque<pii> slots;
    for (auto x : ambil){
        slots.push_back(mp(pos[x].back(), x));
        pos[x].pop_back();
    }
    for (int i=len - 1;i>=0;i--){
        if (vsisa[i].fi){
            alt = vsisa[i].se;
            break;
        }
    }
    int extra = -1;
    if (alt != -1){
        extra = pos[alt].back();
    }
    while (butuh){
        int cur = ambil.back();
        if (slots.front().se != cur){
            ans[slots.front().fi] = cur;
            slots.pop_front();
        } else if (slots.back().se != cur){
            ans[slots.back().fi] = cur;
            slots.pop_back();
        } else{
            if (extra != -1 && cur != alt){
                ans[extra] = cur;
                extra = -1;
            } else {
                cout << "NO" << el;
                return;
            }
        }
        ambil.pop_back();
        butuh--;
    }

    for (int i=1;i<=n;i++){
        if (ans[i] == 0){
            ans[i] = none;
        }
    }
    cout << "YES" << el;
    for (int i=1;i<=n;i++) cout << ans[i] << " ";
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