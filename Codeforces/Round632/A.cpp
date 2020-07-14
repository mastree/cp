#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

const int N = 110;

int q, n, m;
char ans[N][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> m;
        int cw = 0, cb = 0;

        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if ((i + j) & 1){
                    ans[i][j] = 'W';
                    cw++;
                }
                else{
                    ans[i][j] = 'B';
                    cb++;
                }
            }
        }
        if (cw == cb) ans[1][2] = 'B';

        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cout << ans[i][j];
            }
            cout << el;
        }
    }

    return 0;
}