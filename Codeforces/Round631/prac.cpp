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

const int N = 2e3 + 10;

pii nex[4] = {mp(1, 0), mp(-1, 0), mp(0, 1), mp(0, -1)};

int n, m;
string s[N];

int hitung(int r, int c){
    int ret = 0;
    for (int i=0;i<4;i++){
        if (s[r + nex[i].fi][c + nex[i].se] == '.') ret++;
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        string temp;
        cin >> temp;
        s[i] = "*" + temp + "*";
    }
    for (int i=0;i<m + 1;i++){
        s[0].pb('*');
        s[n + 1].pb('*');
    }

    queue <pii> qu;

    bool bisa = 1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (s[i][j] == '.' && hitung(i, j) == 1){
                qu.push(mp(i, j)); 
                // cout << i << " " << j << el;
            }
        }
    }

    while (!qu.empty()){
        auto temp = qu.front();
        qu.pop();
        if (s[temp.fi][temp.se] != '.') continue;
        // cout << temp.fi << " " << temp.se << el;

        pii dest = mp(-1, -1);
        for (int i=0;i<4;i++){
            if (s[temp.fi + nex[i].fi][temp.se + nex[i].se] == '.'){
                dest = mp(temp.fi + nex[i].fi, temp.se + nex[i].se);
                if (i == 0){
                    s[temp.fi][temp.se] = '^';
                    s[dest.fi][dest.se] = 'v';
                } else if (i == 1){
                    s[temp.fi][temp.se] = 'v';
                    s[dest.fi][dest.se] = '^';
                } else if (i == 2){
                    s[temp.fi][temp.se] = '<';
                    s[dest.fi][dest.se] = '>';
                } else{
                    s[temp.fi][temp.se] = '>';
                    s[dest.fi][dest.se] = '<';
                }
                break;
            }
        }

        if (dest == mp(-1, -1)){
            // cout << temp.fi << " " << temp.se << el;
            bisa = 0;
            break;
        }

        for (int i=0;i<4;i++){
            pii temp2 = mp(dest.fi + nex[i].fi, dest.se + nex[i].se);
            if (s[temp2.fi][temp2.se] == '.' && hitung(temp2.fi, temp2.se) == 1){
                qu.push(temp2);
            }
        }
    }

    if (!bisa){
        cout << "Not unique" << el;
        return 0;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (s[i][j] == '.'){
                bisa = 0;
                break;
            }
        }
    }

    if (bisa){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cout << s[i][j];
            }
            cout << el;
        }
    } else{
        cout << "Not unique" << el;
    }

    return 0;
}