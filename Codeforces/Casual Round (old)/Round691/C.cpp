#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

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

int tc;
int n, q;
int mat[N][N];

void solve(){
    bool flipr = 0, flipc = 0;
    int D = 0, R = 0;
    cin >> n >> q;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> mat[i][j];
            mat[i][j]--;
        }
    }
    string s;
    cin >> s;
    int add = 0;
    for (auto x : s){
        if (x == 'L'){
            // if (!flipr) R--;
            // if (flipr ^ flipc){
            //     add--;
            // }
            if (flipr && flipc){
                add--;
                D--;
            } else if (flipr && !flipc){
                add--;
            } else if (!flipr && flipc){
                R--;
            } else if (!flipr && !flipc){
                R--;
            }
        } else if (x == 'R'){
            // if (!flipr) R++;
            // if (flipr ^ flipc){
            //     add++;
            // }
            if (flipr && flipc){
                add++;
                D++;
            } else if (flipr && !flipc){
                add++;
            } else if (!flipr && flipc){
                R++;
            } else if (!flipr && !flipc){
                R++;
            }
        } else if (x == 'I'){
            flipr = !flipr;
        } else if (x == 'U'){
            // if (!flipc) D--;
            // if (flipr ^ flipc){
            //     add--;
            // }
            if (flipr && flipc){
                add--;
                R--;
            } else if (flipr && !flipc){
                D--;
            } else if (!flipr && flipc){
                add--;
            } else if (!flipr && !flipc){
                D--;
            }
        } else if (x == 'D'){
            // if (!flipc) D++;
            // if (flipr ^ flipc){
            //     add++;
            // }
            if (flipr && flipc){
                add++;
                R++;
            } else if (flipr && !flipc){
                D++;
            } else if (!flipr && flipc){
                add++;
            } else if (!flipr && !flipc){
                D++;
            }
        } else if (x == 'C'){
            flipc = !flipc;
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            mat[i][j] = (mat[i][j] + add % n + n) % n;
        }
    }
    for (int i=0;i<n;i++){
        int temp[n];
        for (int j=0;j<n;j++){
            temp[(j + R % n + n) % n] = mat[i][j];
        }
        for (int j=0;j<n;j++){
            mat[i][j] = temp[j];
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            mat[i][j] = (mat[i][j] + add % n + n) % n;
        }
    }
    for (int i=0;i<n;i++){
        int temp[n];
        for (int j=0;j<n;j++){
            temp[(j + R % n + n) % n] = mat[j][i];
        }
        for (int j=0;j<n;j++){
            mat[j][i] = temp[j];
        }
    }
    if (flipr){
        for (int i=0;i<n;i++){
            int temp[n];
            for (int j=0;j<n;j++){
                temp[mat[i][j]] = j;
            }
            for (int j=0;j<n;j++){
                mat[i][j] = temp[j];
            }
        }
    }
    if (flipc){
        for (int i=0;i<n;i++){
            int temp[n];
            for (int j=0;j<n;j++){
                temp[mat[j][i]] = j;
            }
            for (int j=0;j<n;j++){
                mat[j][i] = temp[j];
            }
        }
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout << mat[i][j] + 1 << ' ';
        }
        cout << el;
    }
    cout << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--){
        solve();
    }

    return 0;
}