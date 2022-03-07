#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 998244353;
const int N = 1e6 + 10;

int n, m, k;
map<int, int> rboard[N], cboard[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    vector<set<pii>> rr(2), cc(2), kot(2); // offender
    for (int i=0;i<k;i++){
        int r, c, x;
        cin >> r >> c >> x;
        // rboard[r][c] = x;
        // cboard[c][r] = x;
        if (x == 1){
            // r
            rr[(r & 1)].erase(mp(r, c));
            rr[(r & 1 ^ 1)].insert(mp(r, c));

            // c
            cc[(c & 1)].erase(mp(r, c));
            cc[(c & 1 ^ 1)].insert(mp(r, c));

            // kot
            kot[((r + c) & 1)].erase(mp(r, c));
            kot[((r + c) & 1 ^ 1)].insert(mp(r, c));
        } else if (x == 0){
            // r
            rr[(r & 1 ^ 1)].erase(mp(r, c));
            rr[(r & 1)].insert(mp(r, c));
            
            // c
            cc[(c & 1 ^ 1)].erase(mp(r, c));
            cc[(c & 1)].insert(mp(r, c));

            // kot
            kot[((r + c) & 1 ^ 1)].erase(mp(r, c));
            kot[((r + c) & 1)].insert(mp(r, c));
        } else{
            // r
            rr[(r & 1 ^ 1)].erase(mp(r, c));
            rr[(r & 1)].erase(mp(r, c));
            
            // c
            cc[(c & 1 ^ 1)].erase(mp(r, c));
            cc[(c & 1)].erase(mp(r, c));

            // kot
            kot[((r + c) & 1 ^ 1)].erase(mp(r, c));
            kot[((r + c) & 1)].erase(mp(r, c));
        }

        int ans = 0;
        for (auto& x : rr){
            if (x.empty()) ans++;
        }
        for (auto& x : cc){
            if (x.empty()) ans++;
        }
        for (auto& x : kot){
            if (x.empty()) ans++;
        }
        cout << ans << el;
    }

    return 0;
}