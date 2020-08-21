#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10, M = 3, DEG = 400;

int n;
int deg[N][M], id[N];
unordered_map<int, int> getpos;

set<int> vid[M][DEG];

int cnt[M][DEG];

set<int> setdah[M];
set<pii> urut;

int dp[N];

int hitung(int pos){
    int ret = 0;
    for (int i=0;i<M;i++){
        if (cnt[i][deg[pos][i]] > 1) continue;
        auto it = setdah[i].lower_bound(deg[pos][i]);
        auto ita = it;
        auto itb = it;
        itb++;
        if (itb == setdah[i].end()) itb = setdah[i].begin();
        if (ita == setdah[i].begin()) ita = setdah[i].end();
        ita--;
        
        if (*itb > *ita) ret += *itb - *ita;
        else ret += *itb - *ita + 360;
    }
    return ret;
}
void hapus(int pos){
    for (int i=0;i<M;i++){
        cnt[i][deg[pos][i]]--;
        vid[i][deg[pos][i]].erase(pos);

        if (cnt[i][deg[pos][i]] == 1){
            int cpos = *vid[i][deg[pos][i]].begin();
            int temp = hitung(cpos);
            urut.erase(mp(dp[cpos], -id[cpos]));
            dp[cpos] = temp;
            urut.insert(mp(dp[cpos], -id[cpos]));
        } else if (cnt[i][deg[pos][i]] == 0){
            auto it = setdah[i].lower_bound(deg[pos][i]);
            auto ita = it;
            auto itb = it;
            itb++;
            if (itb == setdah[i].end()) itb = setdah[i].begin();
            if (ita == setdah[i].begin()) ita = setdah[i].end();
            ita--;

            vector<int> upd;
            for (auto x : vid[i][*ita]){
                upd.pb(x);
            }
            for (auto x : vid[i][*itb]){
                upd.pb(x);
            }
            setdah[i].erase(deg[pos][i]);

            for (auto cpos : upd){
                int temp = hitung(cpos);
                urut.erase(mp(dp[cpos], -id[cpos]));
                dp[cpos] = temp;
                urut.insert(mp(dp[cpos], -id[cpos]));
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=0;j<3;j++){
            cin >> deg[i][j];
            cnt[j][deg[i][j]]++;
        }
        cin >> id[i];
        for (int j=0;j<3;j++){
            vid[j][deg[i][j]].insert(i);
        }
        getpos[id[i]] = i;

    }
    for (int i=0;i<M;i++){
        for (int j=0;j<DEG;j++){
            if (cnt[i][j]){
                setdah[i].insert(j);
            }
        }
    }
    for (int i=1;i<=n;i++){
        int temp = hitung(i);
        dp[i] = temp;
        urut.insert(mp(temp, -id[i]));
    }
    for (int i=1;i<=n;i++){
        auto tp = *urut.begin();
        urut.erase(tp);
        int pos = getpos[-tp.se];
        cout << id[pos] << el;
        hapus(pos);
    }

    return 0;
}