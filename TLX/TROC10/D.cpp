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

const int N = 1007;

int n, m, p;
int mat[N][N], ar[N][N];
bool bisa = 1;

int curmat[N];
int cur;
vector <pii> del[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> p;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> mat[i][j];
        }
    }

    for (int i=1;i<=n;i++){
        for (auto x : del[i]){
            curmat[x.fi] -= x.se;
            curmat[x.fi + p] += x.se;
        }
        for (int j=1;j<=m;j++){
            cur += curmat[j]; 
            ar[i][j] = cur;
            if (ar[i][j] > mat[i][j]){
                bisa = 0;
                break;
            }
            if ((i > n-p+1) || (j > m-p+1)){
                continue;
            }
            int plus = mat[i][j] - ar[i][j];
            curmat[j] += plus;
            curmat[j+p] -=plus;
            cur+=plus;
            ar[i][j] = cur;
            del[i+p].pb(mp(j, plus));
        }
        if (bisa == 0){
            break;
        }
        cur += curmat[m+1];
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (ar[i][j] != mat[i][j]){
                bisa = 0;
                break;
            }
        }
    }

    if (bisa){
        cout << "YA" << el;
    } else{
        cout << "TIDAK" << el;
    }

    return 0;
}