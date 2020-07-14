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
const ll PEM = 1e5;

int n;
ll ar[N], ans[N];

ll trans(string& s){
    string temp;
    for (auto kar : s){
        if (kar == '.') continue;
        temp.pb(kar);
    }
    return stoll(temp);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        ar[i] = trans(s);
    }
    vector<pair<ll, int>> change;
    ll tot = 0;
    for (int i=1;i<=n;i++){
        ll temp = ar[i] / PEM;
        if (ar[i] == temp * PEM){
            ans[i] = temp;
        } else{
            if (ar[i] < 0) temp--;
            change.pb(mp(temp, i));
        }
        tot += temp;
    }
    for (auto x : change){
        if (tot < 0){
            ans[x.se] = (int)x.fi + 1;
            tot++;
        } else ans[x.se] = (int)x.fi;
    }
    for (int i=1;i<=n;i++){
        cout << ans[i] << el;
    }

    return 0;
}