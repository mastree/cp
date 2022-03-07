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

int q;
int n;
string s;
int ans[N];

void solve(){
    cin >> n;
    cin >> s;
    set<int> setdah[2];
    for (int i=0;i<n;i++){
        int dig = (int)(s[i] - '0');
        setdah[dig].insert(i + 1);
    }
    int lup = 0;
    while (!setdah[0].empty() && !setdah[1].empty()){
        lup++;
        bool stat;
        int last = 0;
        if (*setdah[0].begin() < *setdah[1].begin()) stat = 0;
        else stat = 1;

        while (1){
            auto it = setdah[stat].upper_bound(last);
            if (it == setdah[stat].end()) break;

            ans[*it] = lup;
            last = *it;
            setdah[stat].erase(last);
            stat ^= 1;
        }
    }
    if (!setdah[0].empty()){
        for (auto x : setdah[0]){
            lup++;
            ans[x] = lup;
        }
    }
    if (!setdah[1].empty()){
        for (auto x : setdah[1]){
            lup++;
            ans[x] = lup;
        }
    }
    cout << lup << el;
    for (int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
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