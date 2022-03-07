#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 22;

int n;
map<string, vector<string>> all;

bool is_suff(string a, string b){
    if (b.size() < a.size()) return 0;
    int n = a.size();
    int m = b.size();
    for (int i=1;i<=n;i++){
        if (a[n - i] != b[m - i]) return 0;
    }
    return 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        string name;
        int len;
        cin >> name >> len;
        for (int j=0;j<len;j++){
            string num;
            cin >> num;
            all[name].pb(num);
        }
    }
    cout << all.size() << el;
    for (auto& x : all){
        cout << x.fi << " ";
        auto vec = x.se;
        sort(vec.begin(), vec.end(), [&](string a, string b) -> bool {
            return a.size() < b.size();
        });
        vector<string> ans;
        int len = vec.size();
        for (int i=0;i<len;i++){
            bool ok = 1;
            for (int j=i + 1;j<len;j++){
                if (is_suff(vec[i], vec[j])){
                    ok = 0;
                    break;
                }
            }
            if (ok) ans.pb(vec[i]);
        }
        cout << ans.size() << " ";
        for (auto& y : ans) cout << y << " "; cout << el;
    }

    return 0;
}