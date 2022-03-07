#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e5 + 10;
const int LOWN = 1e3;
const ll INF = 1e18;

int n;
vector<pair<pair<ll, ll>, int>> vec;
bool sama = 1;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vec.resize(n);
    pair<ll, ll> md = mp(0LL, 0LL);
    for (int i=0;i<n;i++){
        cin >> vec[i].fi.fi >> vec[i].fi.se;
        vec[i].se = i + 1;
        if (vec[i].fi.fi != vec[i].fi.se) sama = 0;
        md.fi += vec[i].fi.fi;
        md.se += vec[i].fi.se;
    }
    sort(vec.begin(), vec.end());
    if (n <= LOWN){
        pair<ll, int> ans = mp(INF, -1);
        for (int i=0;i<n;i++){
            pair<ll, int> cur = mp(0LL, vec[i].se);
            for (int j=0;j<n;j++){
                cur.fi += max(abs(vec[i].fi.fi - vec[j].fi.fi), abs(vec[i].fi.se - vec[j].fi.se));
            }
            ans = min(ans, cur);
        }
        cout << ans.se << el;
        return 0;
    } else if (sama){
        pair<ll, int> ans = mp(INF, -1);
        ll curtot = 0;
        ll tot = 0;
        for (auto x : vec){
            tot += x.fi.fi;
        }
        ll cnt = 0;
        for (auto x : vec){
            cnt++;
            curtot += x.fi.fi;
            tot -= x.fi.fi;
            pair<ll, int> cur = mp(x.fi.fi * cnt - curtot + tot - x.fi.fi * (n - cnt), x.se);
            ans = min(ans, cur);
        }
        cout << ans.se << el;
        return 0;
    } else{
        pair<ll, int> ans = mp(INF, -1);
        priority_queue<pair<ll, int>> temp;
        for (auto& x : vec){
            pair<ll, int> cur = mp(abs(md.fi - x.fi.fi * n) + abs(md.se - x.fi.se * n), x.se);
            // ans = min(ans, cur);
            temp.push(cur);
            if (temp.size() > 200) temp.pop();
        }
        while (temp.size()){
            int tp = temp.top().se;
            temp.pop();
            pair<ll, int> cur = mp(0, tp);
            for (auto x : vec){
                cur.fi += max(abs(x.fi.fi - vec[tp].fi.fi), abs(x.fi.se - vec[tp].fi.se));
            }
            ans = min(ans, cur);
        }
        cout << ans.se << el;
    }

    return 0;
}