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

const int N = 2e5 + 10;

int q;
int ar[N];
int col[N];
int n;

int up[N][18];

int bisa(int times){
    int temp[n + 2];

    for (int i=1;i<=n;i++){
        temp[i] = i;
    }

    for (int i=1;i<=n;i++){
        int sisa = times;
        for (int j=17;j>=0;j--){
            if (sisa >= (1 << j)){
                temp[i] = up[temp[i]][j];
                sisa -= (1 << j);
            }
        }
    }

    bool vis[n + 2];
    fill(vis, vis + n + 2, 0);
    for (int i=1;i<=n;i++){
        if (vis[i]) continue;
        int awal = i;
        vis[i] = 1;
        int cur = temp[i];
        int color = col[i];
        bool masih = 1;
        while (cur != awal){
            if (col[cur] != color){
                masih = 0;
                break;
            } else{
                vis[cur] = 1;
                cur = temp[cur];
            }
        }
        if (masih) return 1;
    }
    return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
            up[i][0] = ar[i];
        }
        for (int i=1;i<=n;i++){
            cin >> col[i];
        }

        for (int i=1;i<18;i++){
            for (int j=1;j<=n;j++){
                up[j][i] = up[up[j][i - 1]][i - 1];
            }
        }
        if (bisa(1)){
            cout << 1 << el;
            continue;
        }

        int ans = n + 1;
        for (int i=1;i<=n*10;i++){
            cout << i << " " << bisa(i) << el;
            // if ((n + 1) % i == 0){
            //     // cout << "masuk" << el;
            //     if (bisa(i)){
            //         ans = i;
            //         // cout << ans << el;
            //         break;
            //     } else if (bisa((n + 1) / i)){
            //         ans = (n + 1) / i;
            //     }
            // }
        }
        cout << el;
        cout << ans << el;
    }

    return 0;
}