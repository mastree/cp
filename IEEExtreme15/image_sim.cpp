#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using matrix = vector<vector<int>>;

const int N = 40;

int q;
matrix rot90(const matrix& mat){
    int n = mat.size();
    int m = mat[0].size();
    matrix ret(m, vector<int>(n, 0));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            ret[j][n - i - 1] = mat[i][j];
        }
    }
    return ret;
}
matrix reflect(const matrix& mat, bool vert){
    int n = mat.size();
    int m = mat[0].size();
    matrix ret(n, vector<int>(m, 0));
    
    if (vert){
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                ret[n - i - 1][j] = mat[i][j];
            }
        }
    } else{
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                ret[i][m - j - 1] = mat[i][j];
            }
        }
    }
    return ret;
}
void printmat(const matrix& a){
    int n = a.size();
    int m = a[0].size();
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout << a[i][j];
        }
        cout << el;
    }
}

void solve(){
    int na, ma;
    cin >> na >> ma;
    matrix a(na, vector<int>(ma));
    for (int i=0;i<na;i++){
        for (int j=0;j<ma;j++){
            char c;
            cin >> c;
            a[i][j] = (c == '#');
        }
    }
    int nb, mb;
    cin >> nb >> mb;
    int mxa = max(na, ma);
    matrix b(mxa + mxa + nb, vector<int>(mxa + mxa + mb, 0));
    for (int i=0;i<nb;i++){
        for (int j=0;j<mb;j++){
            char c;
            cin >> c;
            b[mxa + i][mxa + j] = (c == '#');
        }
    }
    nb += mxa + mxa;
    mb += mxa + mxa;

    // printmat(a);
    // cout << el;
    // printmat(rot90(a));
    // cout << el;
    // printmat(reflect(a, 0));
    // cout << el;
    // printmat(reflect(a, 1));

    int ans = 0;
    for (int rot=0;rot<4;rot++){
        for (int ref=0;ref<2;ref++){
            for (int vert=0;vert<2;vert++){
                na = a.size();
                ma = a[0].size();
                for (int si=0;si + na - 1<nb;si++){
                    for (int sj=0;sj + ma - 1<mb;sj++){
                        int cur = 0;
                        for (int i=0;i<na;i++){
                            for (int j=0;j<ma;j++){
                                if (a[i][j] == b[si + i][sj + j]) cur += a[i][j];
                            }
                        }
                        ans = max(ans, cur);
                    }
                }
                a = reflect(a, 1);
            }
            a = reflect(a, 0);
        }
        a = rot90(a);
    }
    cout << ans << el;
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