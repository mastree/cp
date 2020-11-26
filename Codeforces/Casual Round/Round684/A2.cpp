#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 110;

int q, n, m;
bool ar[N][N];

vector<pii> ans;

int selesai(){
    int ret = 0;
    for (int i=n - 1;i<=n;i++){
        for (int j=m - 1;j<=m;j++){
            ret += ar[i][j];
        }
    }
    return ret;
}
void kerja(){
    int cur = selesai();
    if (cur == 1){
        int kos = 2;
        for (int i=n - 1;i<=n;i++){
            for (int j=m - 1;j<=m;j++){
                if (ar[i][j]){
                    ar[i][j] = 0;
                    ans.pb(mp(i, j));
                } else if (kos){
                    ar[i][j] = 1;
                    kos--;
                    ans.pb(mp(i, j));
                }
            }
        }
    } else if (cur == 2){
        int isi = 1;
        for (int i=n - 1;i<=n;i++){
            for (int j=m - 1;j<=m;j++){
                if (!ar[i][j]){
                    ar[i][j] = 1;
                    ans.pb(mp(i, j));
                } else if (isi){
                    ar[i][j] = 0;
                    isi--;
                    ans.pb(mp(i, j));
                }
            }
        }
    } else if (cur == 3){
        for (int i=n - 1;i<=n;i++){
            for (int j=m - 1;j<=m;j++){
                if (ar[i][j]){
                    ar[i][j] = 0;
                    ans.pb(mp(i, j));
                } 
            }
        }
    } else if (cur == 4){
        int isi = 3;
        for (int i=n - 1;i<=n;i++){
            for (int j=m - 1;j<=m;j++){
                if (!ar[i][j]){
                    ar[i][j] = 1;
                    ans.pb(mp(i, j));
                } else if (isi){
                    ar[i][j] = 0;
                    isi--;
                    ans.pb(mp(i, j));
                }
            }
        }
    }
}

void solve(){
    ans.clear();
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;
            cin >> c;
            ar[i][j] = (c == '1');
        }
    }
    for (int i=1;i<=n - 2;i++){
        for (int j=1;j<=m - 1;j++){
            if (ar[i][j]) ans.pb(mp(i, j));
            if (ar[i][j + 1]) ans.pb(mp(i, j + 1));
            ar[i][j] = ar[i][j + 1] = 0;
            for (int p=0;p<2;p++){
                if (((int)ans.size()) % 3 != 0){
                    ans.pb(mp(i + 1, j + p));
                    ar[i + 1][j + p] = !ar[i + 1][j + p];
                }
            }
        }
    }
    int r = n - 1;
    for (int i=1;i<=m - 2;i++){
        if (ar[r][i]) ans.pb(mp(r, i));
        if (ar[r + 1][i]) ans.pb(mp(r + 1, i));
        ar[r][i] = ar[r + 1][i] = 0;
        for (int p=0;p<2;p++){
            if (((int)ans.size()) % 3 != 0){
                ans.pb(mp(r + p, i + 1));
                ar[r + p][i + 1] = !ar[r + p][i + 1];
            }
        }
    }
    while (selesai()){
        kerja();
    }
    int len = ans.size();
    cout << len / 3 << el;
    for (int i=0;i<len;i++){
        cout << ans[i].fi << " " << ans[i].se << " ";
        if ((i + 1) % 3 == 0) cout << el;
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