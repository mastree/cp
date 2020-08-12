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
const int INF = 1e9;

int q;
int n;
int cnt[N];
vector<int> vec;

bool bisa(int mn){
    vector<int> slot;
    int npmn = n / (mn + 1);
    int sis = n % (mn + 1);

    set<pii> setdah;
    for (int i=0;i<vec.size();i++) setdah.insert(mp(vec[i], i));
    vector<pii> pus;
    while (!setdah.empty() && sis){
        pus.pb(*setdah.rbegin());    
        setdah.erase(pus.back());
        sis--;
    }
    if (sis) return 0;
    for (auto x : pus){
        if (x.fi - 1 > 0) setdah.insert(mp(x.fi - 1, x.se));
    }
    vector<int> temp;
    for (auto x : setdah) temp.pb(x.fi);
    for (auto x : temp) if (x > npmn) return 0;
    return 1;
}

void solve(){
    cin >> n;
    fill(cnt, cnt + n + 2, 0);
    vec.clear();
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        cnt[a]++;
    }
    for (int i=1;i<=n;i++){
        if (cnt[i]) vec.pb(cnt[i]);
    }
    sort(vec.begin(), vec.end(), greater<int>());
    int l = 0, r = n - 1;
    while (l < r){
        int m = (l + r + 1) / 2;
        if (bisa(m)){
            l = m;
        } else{
            r = m - 1;
        }
    }
    cout << l << el;
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