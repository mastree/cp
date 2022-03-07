#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 60;
const int INF = 1e9 + 7;

int q;
int n;
int ar[N][N];
void solve(){
    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            char c;
            cin >> c;
            if (c == '.') ar[i][j] = 0;
            else if (c == 'X') ar[i][j] = 1;
            else ar[i][j] = 2;
        }
    }
    int cnt = 0;
    int mn = INF;
    for (int i=1;i<=n;i++){
        int non = 0;
        bool skip = 0;
        for (int j=1;j<=n;j++){
            if (ar[i][j] != 1) non++;
            if (ar[i][j] == 2){
                skip = 1;
                break;
            }
        }
        if (skip) continue;
        if (non < mn){
            cnt = 0;
            mn = non;   
        }
        if (non == mn) cnt++;
    }
    for (int j=1;j<=n;j++){
        int non = 0;
        bool skip = 0;
        for (int i=1;i<=n;i++){
            if (ar[i][j] != 1) non++;
            if (ar[i][j] == 2){
                skip = 1;
                break;
            }
        }
        if (skip) continue;
        if (non < mn){
            cnt = 0;
            mn = non;
        }
        if (non == mn) cnt++;
    }
    if (mn == 1){
        int ans = 0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (ar[i][j] != 0) continue;
                bool bisa = 0;
                int non = 0;
                for (int k=1;k<=n;k++){
                    if (ar[i][k] != 1) non++;
                }
                if (non == 1) bisa = 1;
                else{
                    non = 0;
                    for (int k=1;k<=n;k++){
                        if (ar[k][j] != 1) non++;
                    }
                    if (non == 1) bisa = 1;
                }
                ans += bisa;
            }
        }
        cout << 1 << " " << ans << el;
        return;
    }
    if (mn == INF){
        cout << "Impossible" << el;
    } else{
        cout << mn << " " << cnt << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}