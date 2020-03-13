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

const int N = 5e2 + 10;

int n, m;
string s[N];

bool bisa;
pii start, fin;

bool vis[N][N];

void sol(int a, int b){
    if (bisa) return;

    if (fin == mp(a, b)){
        int cnt = 0;
        for (int i=-1;i<=1;i+=2){
            int na = a + i;
            int nb = b;
            if (s[na][nb] == '.' || vis[na][nb]){
                cnt++;
            }   
        }
        for (int i=-1;i<=1;i+=2){
            int na = a;
            int nb = b + i;
            if (s[na][nb] == '.' || vis[na][nb]){
                cnt++;
            }   
        }
        if (cnt >= 2){
            bisa = 1;
            return;
        }
    }

    vis[a][b] = 1;
    for (int i=-1;i<=1;i+=2){
        int na = a + i;
        int nb = b;
        if (fin == mp(na, nb) && s[na][nb] == 'X'){
            bisa = 1;
            return;
        }
        if (!vis[na][nb] && s[na][nb] == '.'){
            s[na][nb] = 'X';
            sol(na, nb);
            s[na][nb] = '.';
        }
    }

    for (int i=-1;i<=1;i+=2){
        int na = a;
        int nb = b + i;
        if (fin == mp(na, nb) && s[na][nb] == 'X'){
            bisa = 1;
            return;
        }
        if (!vis[na][nb] && s[na][nb] == '.'){
            s[na][nb] = 'X';
            sol(na, nb);
            s[na][nb] = '.';
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=0;i<=m+1;i++){
        s[0].pb('X');
        s[n+1].pb('X');
    }
    for (int i=1;i<=n;i++){
        string tm;
        cin >> tm;
        s[i] = "X" + tm + "X";
    }

    cin >> start.fi >> start.se >> fin.fi >> fin.se;
    sol(start.fi, start.se);

    if (bisa){
        cout << "YES" << el;
    } else{
        cout << "NO" << el;
    }

    return 0;
}