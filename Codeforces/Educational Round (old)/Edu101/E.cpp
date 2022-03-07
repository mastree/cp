#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e6 + 10;

int q;
int n, k;
string s;
int ada[2][N];

void init(){
    for (int i=0;i<2;i++){
        fill(ada[i], ada[i] + n + 3, 0);
    }
}
string jawab_int(int x){
    string ans = "";
    for (int i=k - 1;i>=0;i--){
        if (x & (1 << i)) ans.pb('1');
        else ans.pb('0');
    }
    return ans;
}
string jawab_string(int x){
    string ans = "";
    for (int i=0;i<k - 20;i++){
        ans.pb('0');
    }
    for (int i=20 - 1;i>=0;i--){
        if (x & (1 << i)) ans.pb('1');
        else ans.pb('0');
    }
    return ans;
}

void solve(){
    cin >> n >> k;
    cin >> s;
    init();
    if (k <= 20){
        int tot = (1 << k);
        unordered_map<int, bool> ada;
        for (int i=0;i<n - k + 1;i++){
            int cur = 0;
            for (int j=0;j<k;j++){
                if (s[i + j] == '1'){
                    cur += (1 << (k - j - 1));
                }
            }
            ada[cur] = 1;
        }
        if (tot == ada.size()){
            cout << "NO" << el;
            return;
        }
        for (int i=0;i<tot;i++){
            if (ada.count((tot - 1) - i) == 0){
                cout << "YES" << el;
                cout << jawab_int(i) << el;
                return;
            }
        }
    }
    vector<int> pre(n + 2, 0);
    for (int i=1;i<=n;i++){
        pre[i] = pre[i - 1] + (s[i - 1] == '1');
    }
    int tot = (1 << 20);
    int butuh = k - 20;
    unordered_map<int, bool> ada;
    for (int i=k;i<=n;i++){
        if (pre[i - 20] - pre[i - k] == butuh){
            int cur = 0;
            for (int j=0;j<20;j++){
                if (s[i - j - 1] == '1'){
                    cur += (1 << j);
                }
            }
            ada[cur] = 1;
        }
    }
    for (int i=0;i<tot;i++){
        if (ada.count((tot - 1) - i) == 0){
            cout << "YES" << el;
            cout << jawab_string(i) << el;
            return;
        }
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