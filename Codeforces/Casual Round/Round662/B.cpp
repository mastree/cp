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

int n, q;
int cnt[N];
set<pii> setdah;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int size = n;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        cnt[a]++;
    }
    for (int i=1;i<=n;i++){
        setdah.insert(mp(cnt[i], i));
    }
    cin >> q;
    while (q--){
        char tipe;
        int a;
        cin >> tipe >> a;
        if (tipe == '+'){
            size++;
            setdah.erase(mp(cnt[a], a));
            cnt[a]++;
            setdah.insert(mp(cnt[a], a));
        } else{
            size--;
            setdah.erase(mp(cnt[a], a));
            cnt[a]--;
            setdah.insert(mp(cnt[a], a));
        }
        if (size < 8){
            cout << "NO" << el;
            continue;
        }
        auto it = setdah.rbegin();
        vector<int> but{2, 2, 4};
        int tot = 0;
        while (!but.empty() && tot + but.back() <= it->fi){
            tot += but.back();
            but.pop_back();
        }
        if (!but.empty()){
            it++;
            if (it != setdah.rend()){
                tot = 0;
                while (!but.empty() && tot + but.back() <= it->fi){
                    tot += but.back();
                    but.pop_back();
                }
            }
        }
        if (!but.empty()){
            it++;
            if (it != setdah.rend()){
                tot = 0;
                while (!but.empty() && tot + but.back() <= it->fi){
                    tot += but.back();
                    but.pop_back();
                }
            }
        }
        if (but.empty()) cout << "YES" << el;
        else cout << "NO" << el;
    }

    return 0;
}