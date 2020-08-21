#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 25;

int tc;
int n, m, q;
int ar[N][N];

vector<vector<int>> rotcw(const vector<vector<int>>& v){
    int len = v.size();
    vector<vector<int>> ret(len, vector<int>(len));

    for (int i=0;i<len;i++){
        for (int j=0;j<len;j++){
            ret[j][len - i - 1] = v[i][j];
        }
    }
    return ret;
}
vector<vector<int>> rotccw(const vector<vector<int>>& v){
    int len = v.size();
    vector<vector<int>> ret(len, vector<int>(len));

    for (int i=0;i<len;i++){
        for (int j=0;j<len;j++){
            ret[len - j - 1][i] = v[i][j];
        }
    }
    return ret;
}
void refx(vector<vector<int>>& v){
    int rlen = v.size();
    int clen = v[0].size();

    for (int i=0;i<rlen / 2;i++){
        for (int j=0;j<clen;j++){
            swap(v[i][j], v[rlen - i - 1][j]);
        }
    }
}
void refy(vector<vector<int>>& v){
    int rlen = v.size();
    int clen = v[0].size();

    for (int i=0;i<rlen;i++){
        for (int j=0;j<clen / 2;j++){
            swap(v[i][j], v[i][clen - j - 1]);
        }
    }
}

void solve(){
    cin >> n >> m >> q;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> ar[i][j];
        }
    }
    while (q--){
        string tipe, tipe2;
        cin >> tipe >> tipe2;
        if (tipe == "rotate"){
            int r, c, s;
            cin >> r >> c >> s;

            vector<vector<int>> v(s + 1, vector<int>(s + 1));
            for (int i=0;i<=s;i++){
                for (int j=0;j<=s;j++){
                    v[i][j] = ar[r + i][c + j];
                }
            }
            if (tipe2 == "cw"){
                v = rotcw(v);
            } else{
                v = rotccw(v);
            }
            for (int i=0;i<=s;i++){
                for (int j=0;j<=s;j++){
                    ar[r + i][c + j] = v[i][j];
                }
            }
        } else{
            int r1, r2, c1, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            int rlen = r2 - r1 + 1;
            int clen = c2 - c1 + 1;

            vector<vector<int>> v(rlen, vector<int>(clen));
            for (int i=0;i<rlen;i++){
                for (int j=0;j<clen;j++){
                    v[i][j] = ar[r1 + i][c1 + j];
                }
            }
            if (tipe2 == "x"){
                refx(v);
            } else{
                refy(v);
            }
            for (int i=0;i<rlen;i++){
                for (int j=0;j<clen;j++){
                    ar[r1 + i][c1 + j] = v[i][j];
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cout << ar[i][j];
            if (j != m) cout << " ";
        }
        cout << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int cas=1;cas<=tc;cas++){
        cout << "Case #" << cas << ":\n";
        solve();
    }

    return 0;
}