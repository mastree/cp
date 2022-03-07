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

const int N = 1e3 + 10;

int n;
pii last[N][N];
pii trav[4];
char ans[N][N];

void dfs(int r, int c){
    for (int i=0;i<4;i++){
        pii dest = mp(r + trav[i].fi, c + trav[i].se);
        if (ans[dest.fi][dest.se] == '*'){
            if (last[dest.fi][dest.se] == last[r][c]){
                if (i == 0) ans[dest.fi][dest.se] = 'D';
                else if (i == 1) ans[dest.fi][dest.se] = 'L';
                else if (i == 2) ans[dest.fi][dest.se] = 'U';
                else ans[dest.fi][dest.se] = 'R';

                dfs(dest.fi, dest.se);
            }
        }
    }
}

void dfs2(int r, int c){
    for (int i=0;i<4;i++){
        pii dest = mp(r + trav[i].fi, c + trav[i].se);
        if (last[dest.fi][dest.se] == mp(-1, -1)){
            if (i == 0) ans[r][c] = 'U';
            else if (i == 1) ans[r][c] = 'R';
            else if (i == 2) ans[r][c] = 'D';
            else ans[r][c] = 'L';
            break;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    trav[0] = mp(-1, 0); // atas
    trav[1] = mp(0, 1); // kanan
    trav[2] = mp(1, 0); // bawah
    trav[3] = mp(0, -1); // kiri
    cin >> n;
    for (int i=0;i<=n+1;i++){
        fill(ans[i], ans[i] + n + 2, '*');
    }
    for (int i=0;i<=n+1;i++){
        ans[0][i] = 'X';
        ans[i][0] = 'X';
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            int r, c;
            cin >> r >> c;
            last[i][j] = mp(r, c);
            if (last[i][j] == mp(i, j)) ans[i][j] = 'X';
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (ans[i][j] == 'X'){
                dfs(i, j);
            }
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (ans[i][j] == '*' && last[i][j] == mp(-1, -1)){
                dfs2(i, j);
            }
        }
    }

    bool valid = 1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (ans[i][j] == '*') valid = 0;
        }
    }
    if (valid){
        cout << "VALID" << el;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                cout << ans[i][j];
            }
            cout << el;
        }
    } else{
        cout << "INVALID" << el;
    }

    return 0;
}