#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 20;

int q, n, m;
string s[N];

vector<string> find(string st){
    vector<string> ret;
    ret.pb(st);
    for (int i=0;i<m;i++){
        string temp = st;
        temp[i] = '?';
        ret.pb(temp);
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> m;
        for (int i=1;i<=n;i++){
            cin >> s[i];
        }
        unordered_map<string, bool> ada;
        for (int i=1;i<=n;i++){
            vector<string> v = find(s[i]);
            // cout << i << " => ";for(auto x : v) cout << x << " "; cout << el;
            if (i == 1){
                for (auto x : v){
                    ada[x] = 1;
                }
                continue;
            }
            vector<string> baru;
            for (auto x : v){
                for (auto yy : ada){
                    string y = yy.fi;
                    string temp;
                    bool yes = 1;
                    for (int id=0;id<m;id++){
                        if (x[id] == y[id]){
                            temp.pb(x[id]);
                        } else if (x[id] == '?'){
                            temp.pb(y[id]);
                        } else if (y[id] == '?'){
                            temp.pb(x[id]);
                        } else{
                            yes = 0;
                            break;
                        }
                    }
                    if (yes) baru.pb(temp);
                }
            }
            ada.clear();
            for (auto x : baru){
                // cout << x << " ";
                ada[x] = 1;
            }
            // cout << el;
        }
        string ans;
        for (auto x : ada){
            ans = x.fi;
            break;
        }
        if (ans.empty()){
            cout << -1 << el;
            continue;
        }
        for (int i=0;i<m;i++){
            if (ans[i] == '?') ans[i] = 'a';
        }
        cout << ans << el;
    }

    return 0;
}