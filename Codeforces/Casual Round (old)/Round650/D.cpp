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

const int N = 60;

int q;
string s;
int n;
int br[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        int hur[26];
        fill(hur, hur + 26, 0);

        cin >> s;
        cin >> n;
        for (int i=1;i<=n;i++){
            cin >> br[i];
        }
        for (auto x : s){
            hur[(int)(x - 'a')]++;
        }

        int lv[n + 10];
        fill(lv, lv + n + 10, MOD);
        vector<int> done;
        int last = 0;

        vector<int> idlev[N];

        for (int i=1;i<=n;i++){
            if (done.empty()){
                for (int j=1;j<=n;j++){
                    if (br[j] == 0){
                        done.pb(j);
                        lv[j] = last;
                        idlev[last].pb(j);
                        break;
                    }
                }
                continue;
            }
            int len = done.size();
            int mn = MOD, pos = -1;
            for (int j=1;j<=n;j++){
                if (lv[j] != MOD) continue;
                int cur = br[j];
                int cnt;
                int id = 0;
                while (cur){
                    cur -= abs(j - done[id++]);
                    if (id >= len) break;
                }
                if (id == len) cnt = last + 1;
                else cnt = last;
                if (cur == 0 && mn > cnt){
                    mn = cnt;
                    pos = j;
                }
            }
            done.pb(pos);
            if (mn != last){
                lv[pos] = ++last;
            } else{
                lv[pos] = last;
            }
            idlev[last].pb(pos);
        }
        int id = 25;
        int ans[n + 2];
        for (int i=0;i<26;i++){
            if (idlev[i].empty()) continue;
            while (hur[id] < idlev[i].size()){
                id--;
                if (id < 0) break;
            }
            for (auto x : idlev[i]){
                ans[x] = id;
            }
            id--;
            if (id < 0) break;
        }
        for (int i=1;i<=n;i++){
            cout << char(ans[i] + 'a');
        }
        cout << el;
    }

    return 0;
}