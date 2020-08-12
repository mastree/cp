#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 100, M = 7;

string t = "abacaba";

bool is_ok(const string& s){
    int n = s.length();
    int cnt = 0;
    for (int i=0;i<n;i++){
        bool sama = 1;
        for (int j=0;j<M;j++){
            if (i + j >= n){
                sama = 0;
                break;
            }
            if (s[i + j] != t[j]){
                sama = 0;
                break;
            }
        }
        if (sama) cnt++;
    }
    return cnt == 1;
}

int q;
int n;
string s;

void solve(){
    cin >> n >> s;
    int cnt = 0;
    for (int i=0;i<n;i++){
        bool sama = 1;
        for (int j=0;j<M;j++){
            if (i + j >= n){
                sama = 0;
                break;
            }
            if (s[i + j] != t[j]){
                sama = 0;
                break;
            }
        }
        if (sama) cnt++;
    }
    if (cnt > 1){
        cout << "No" << el;
        return;
    }
    if (cnt == 1){
        cout << "Yes" << el;
        for (int i=0;i<n;i++){
            if (s[i] == '?') cout << "z";
            else cout << s[i];
        }
        cout << el;
        return;
    }
    bool ok = 0;
    for (int i=0;i<n;i++){
        vector<pair<int, char>> pos;
        bool mungkin = 1;
        for (int j=0;j<M;j++){
            if (i + j >= n){
                mungkin = 0;
                break;
            }
            if (s[i + j] != t[j]){
                if (s[i + j] == '?'){
                    pos.pb(mp(i + j, t[j]));
                } else{
                    mungkin = 0;
                    break;
                }
            }
        }
        if (mungkin){
            // for (auto x : pos){
            //     s[x.fi] = x.se;
            // }
            string temp = s;
            for (auto x : pos) temp[x.fi] = x.se;
            if (is_ok(temp)){
                s = temp;
                ok = 1;
                break;
            }
        }
    }
    if (ok){
        cout << "Yes" << el;
        for (int i=0;i<n;i++){
            if (s[i] == '?') cout << "z";
            else cout << s[i];
        }
        cout << el;
    } else cout << "No" << el;
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