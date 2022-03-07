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
int d, n, k;

void solve(){
    cin >> d >> n >> k;
    vector<pair<int, pii>> vec;
    vector<pii> add, del; // pos, id
    for (int i=0;i<n;i++){
        int h, a, b;
        cin >> h >> a >> b;
        vec.pb(mp(h, mp(a, b)));
        add.pb(mp(a, i));
        del.pb(mp(b + 1, i));
    }
    sort(add.begin(), add.end(), greater<pii>());
    sort(del.begin(), del.end(), greater<pii>());
    set<pii> take, ntake; // h, id

    ll tot = 0, ans = 0;
    int sz = 0;
    for (int i=1;i<=d;i++){
        while (del.size() && del.back().fi <= i){
            int id = del.back().se;
            del.pop_back();
            pii temp = mp(vec[id].fi, id);
            take.erase(temp);
            if (take.size() != sz){
                sz = take.size();
                tot -= temp.fi;
            }
            ntake.erase(temp);
        }
        while (take.size() < k && ntake.size()){
            auto temp = *ntake.rbegin();
            ntake.erase(temp);
            take.insert(temp);
            sz++;
            tot += temp.fi;
        }
        while (add.size() && add.back().fi <= i){
            int id = add.back().se;
            add.pop_back();
            pii temp = mp(vec[id].fi, id);
            take.insert(temp);
            sz++;
            tot += temp.fi;
        }
        while (take.size() > k){
            auto temp = *take.begin();
            take.erase(temp);
            sz--;
            tot -= temp.fi;
            ntake.insert(temp);
        }
        ans = max(ans, tot);
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}