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

const int N = 110;

int n, m;
int k;
char ar[N][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    int mn = (n + 1) / 2;
    int mm = (m - 1) / 2;
    int ujung = 0;
    if (n%2 == 0 || m%2 == 0){
        ujung = 1;
    }
    if (k >= mn + mm + ujung){
        cout << "YA" << el;
    } else{
        cout << "TIDAK" << el;
        return 0;
    }

    for (int i=1;i<=n;i++){
        if (i&1) ar[i][1] = 'X';
        else{
            ar[i][1] = '.';
        }
    }
    for (int i=1;i<=m;i++){
        if (i&1) ar[1][i] = 'X';
        else{
            ar[1][i] = '.';
        }
    }
    if (ujung) ar[n][m] = 'X';

    // cout << mn << el;
    // cout << mm << el;
    k -= mn + mm + ujung;

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (k > 0 && ar[i][j] != 'X'){
                k--;
                ar[i][j] = 'X';
            }
            else if (ar[i][j] != 'X') ar[i][j] = '.';
            cout << ar[i][j];
        }
        cout << el;
    }

    return 0;
}