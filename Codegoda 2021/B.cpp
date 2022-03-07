#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 4e4 + 10;

int n;
vector<pair<string, int>> vec;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        string a, b;
        cin >> a >> b;
        vec.pb(mp(a, 1));
        vec.pb(mp(b, -1));
    }
    sort(vec.begin(), vec.end());
    int cur = 0;
    pair<string, int> ans = {"", -1};
    for (auto& x : vec){
        if (x.se == 1){
            cur++;
            if (cur > ans.se) ans = mp(x.fi, cur);
        } else{
            cur--;
        }
    }
    cout << ans.fi << el;

    return 0;
}