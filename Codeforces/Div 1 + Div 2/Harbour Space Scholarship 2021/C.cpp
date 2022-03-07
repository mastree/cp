#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int LEN = 10;
const int MASK = (1 << LEN); 

int q;

void solve(){
    string s;
    cin >> s;
    int ans = 10;
    for (int i=0;i<MASK;i++){
        int cnt[2] = {0, 0};
        int sisa[2] = {5, 5};
        for (int j=0;j<LEN;j++){
            if (s[j] == '?'){
                bool on = ((i & (1 << j)) > 0);
                cnt[(j & 1)] += on;
            } else{
                cnt[(j & 1)] += (s[j] == '1');
            }
            sisa[(j & 1)]--;
            if (cnt[0] > cnt[1] + sisa[1] || cnt[1] > cnt[0] + sisa[0]) ans = min(ans, j + 1);
        }
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