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
const int INF = 1e9 + 10;

int n;
int ar[N];

vector<int> vec[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    ar[0] = 0;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        vec[ar[i]].pb(ar[i] - i);
    }
    for (int i=1;i<=n;i++){
        sort(vec[i].begin(), vec[i].end());
    }
    set<pii> setdah; // val, ans / asc, asc
    setdah.insert(mp(-INF, -INF));
    setdah.insert(mp(0, 0));

    for (int i=1;i<=n;i++){
        for (auto& x : vec[i]){
            auto it = setdah.lower_bound(mp(x, -INF));
            if (it == setdah.end()) continue;
            pii baru = mp(x, it->se - 1);
            it--;
            vector<pii> pus;
            while (it->se >= baru.se){
                pus.pb(*it);
                it--;
            }
            for (auto& x : pus) setdah.erase(x);
            setdah.insert(baru);
        }
    }
    int ans = 0;
    for (auto& x : setdah){
        if (x.se != -INF) ans = max(ans, -x.se);
    }
    cout << ans << el;

    return 0;
}