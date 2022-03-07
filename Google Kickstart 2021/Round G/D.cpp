#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string NO = "IMPOSSIBLE";
string YES = "POSSIBLE";

int q;
int n, a;

int area(vector<pii>& vec){
    int ret = 0;
    int n = vec.size();
    for (int i=0;i<n;i++){
        int ni = (i + 1) % n;
        ret += vec[i].fi * vec[ni].se;
        ret -= vec[i].se * vec[ni].fi;
    }
    return abs(ret);
}

void solve(){
    cin >> n >> a;
    vector<pii> ans;
    if (n == 3){
        ans = {
            {0, 0},
            {a, 0},
            {0, 1}
        };
    } else if (n == 4){
        if (a <= 1){
            cout << NO << el;
            return;
        }
        int atas = a / 2;
        int bawah = a - atas;
        ans = {
            {0, 0},
            {bawah, 0},
            {atas, 1},
            {0, 1}
        };
    } else{
        if (a <= 2){
            cout << NO << el;
            return;
        }
        ans = {
            {0, 0},
            {1, 0},
            {1, 1},
            {2, a - 1},
            {0, 1}
        };
    }
    assert(area(ans) == a);
    cout << YES << el;
    for (auto& x : ans){
        cout << x.fi << " " << x.se << el;
    }
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