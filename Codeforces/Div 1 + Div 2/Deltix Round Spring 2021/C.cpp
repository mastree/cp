#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10;

int q;
int n;
int ar[N], diff[N];

void getstring(vector<int>& cur){
    for (int i=0;i<cur.size();i++){
        if (i == 0) cout << cur[i];
        else cout << '.' << cur[i];
    }
    cout << el;
}

void solve(){
    cin >> n;
    set<int> all;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        all.insert(i);
    }
    vector<int> inden(n + 1, 0); // 0 lanjut, 1 inden, 2 up
    inden[1] = 1;
    auto it = all.end();
    it--;
    while (1){
        vector<int> pus;
        if (ar[*it] == 1){
            inden[*it] = 1;
            int tar = 0;
            auto temp = it;
            while (temp != all.end()){
                tar++;
                if (ar[*temp] != tar){
                    // inden[*temp] = 2;
                    break;
                }
                pus.pb(*temp);
                temp++;
            }
        }
        if (it != all.begin()){
            it--;
            int nit = (*it);
            for (auto& x : pus){
                all.erase(x);
            }
            it = all.lower_bound(nit);
        } else{
            for (auto& x : pus){
                all.erase(x);
            }
            break;
        }
    }
    vector<int> cur;
    for (int i=1;i<=n;i++){
        if (inden[i] == 0){
            while (cur.back() != ar[i] - 1){
                cur.pop_back();
            }
            cur.back() = ar[i];
        } else if (inden[i] == 1){
            cur.pb(ar[i]);
        } else{
            cur.pop_back();
            cur.pop_back();
            cur.pb(ar[i]);
        }
        getstring(cur);
    }
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