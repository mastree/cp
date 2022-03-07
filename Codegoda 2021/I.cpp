#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MX = 1e6 + 10;

int q;
int c, d;

vector<vector<int>> rot90(vector<vector<int>>& vec){
    int n = vec.size();
    int m = vec[0].size();
    vector<vector<int>> ret(m, vector<int>(n));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            ret[j][n - i - 1] = vec[i][j];
        }
    }
    return ret;
}
vector<vector<int>> rotm90(vector<vector<int>>& vec){
    int n = vec.size();
    int m = vec[0].size();
    vector<vector<int>> ret(m, vector<int>(n));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            ret[m - j - 1][i] = vec[i][j];
        }
    }
    return ret;
}
bool check12(vector<vector<int>>& vec){
    int n = vec.size();
    int m = vec[0].size();
    if (m == 1) return 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m/2;j++){
            if (vec[i][j] != vec[i][m - j - 1]) return 0;
        }
    }
    return 1;
}
bool check13(vector<vector<int>>& vec){
    int n = vec.size();
    int m = vec[0].size();
    if (n != m) return 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (vec[i][j] != vec[n - j - 1][m - i - 1]) return 0;
        }
    }
    return 1;
}
bool check(vector<vector<int>>& vec){
    if (c == 1 && d == 2) return check12(vec);
    if (c == 2 && d == 1) return check12(vec);
    if (c == 1 && d == 3) return check13(vec);
    if (c == 3 && d == 1) return check13(vec);
    if (c == 1 && d == 4){
        auto temp = rot90(vec);
        return check12(temp);
    }
    if (c == 4 && d == 1){
        auto temp = rot90(vec);
        return check12(temp);
    }
    if (c == 2 && d == 3){
        auto temp = rotm90(vec);
        return check12(temp);
    }
    if (c == 3 && d == 2){
        auto temp = rotm90(vec);
        return check12(temp);
    }
    if (c == 2 && d == 4){
        auto temp = rot90(vec);
        return check13(temp);
    }
    if (c == 4 && d == 2){
        auto temp = rot90(vec);
        return check13(temp);
    }
    if (c == 3 && d == 4) return check12(vec);
    if (c == 4 && d == 3) return check12(vec);
    return 0;
}
void fold12(vector<vector<int>>& vec, bool awal){
    int n = vec.size();
    int m = vec[0].size();
    for (int i=0;i<n;i++){
        for (int j=0;j<m/2;j++){
            // if (vec[i][j] != vec[i][m - j - 1]) return 0;
            if (awal) vec[i][m - j - 1] = -1;
            else vec[i][j] = -1;
        }
    }
}
void fold13(vector<vector<int>>& vec, bool awal){
    int n = vec.size();
    int m = vec[0].size();
    for (int i=0;i<n;i++){
        // for (int j=0;j<m;j++){
        //     if (vec[i][j] != vec[n - j - 1][m - i - 1]) return 0;
        // }
        if (awal){
            for (int j=m - i;j<m;j++){
                vec[i][j] = -1;
            }
        } else{
            for (int j=0;j<m - i - 1;j++){
                vec[i][j] = -1;
            }
        }
    }
}
void fold(vector<vector<int>>& vec){
    if (c == 1 && d == 2){
        fold12(vec, 0);
        return;
    }
    if (c == 2 && d == 1){
        fold12(vec, 1);
        return;
    }
    if (c == 1 && d == 3){
        fold13(vec, 0);
        return;
    }
    if (c == 3 && d == 1){
        fold13(vec, 1);
        return;
    }
    if (c == 1 && d == 4){
        auto temp = rot90(vec);
        fold12(temp, 1);
        vec = rotm90(temp);
        return;
    }
    if (c == 4 && d == 1){
        auto temp = rot90(vec);
        fold12(temp, 0);
        vec = rotm90(temp);
        return;
    }
    if (c == 2 && d == 3){
        auto temp = rotm90(vec);
        fold12(temp, 0);
        vec = rot90(temp);
        return;
    }
    if (c == 3 && d == 2){
        auto temp = rotm90(vec);
        fold12(temp, 1);
        vec = rot90(temp);
        return;
    }
    if (c == 2 && d == 4) {
        auto temp = rot90(vec);
        fold13(temp, 1);
        vec = rotm90(temp);
        return;
    }
    if (c == 4 && d == 2) {
        auto temp = rot90(vec);
        fold13(temp, 0);
        vec = rotm90(temp);
        return;
    }
    if (c == 3 && d == 4) {
        fold12(vec, 1);
        return;
    }
    if (c == 4 && d == 3) {
        fold12(vec, 0);
        return;
    }
}

void print_mat(vector<vector<int>>& vec){
    int n = vec.size();
    int m = vec[0].size();
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (vec[i][j] >= 0) cout << vec[i][j];
            else cout << '-';
        }
        cout << el;
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    cin >> c >> d;
    vector<vector<int>> vec(n, vector<int>(m));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> vec[i][j];
        }
    }
    if (!check(vec)){
        cout << "error" << el;
        return;
    }
    // cout << c << " " << d << el;
    fold(vec);
    print_mat(vec);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << i << el;
        solve();
    }

    return 0;
}