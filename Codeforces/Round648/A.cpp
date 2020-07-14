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

const int N = 1e2 + 10;

int q;
int n, m;
int ar[N][N];

int r[N], c[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> m;
        fill(r, r + n + 2, 0);
        fill(c, c + m + 2, 0);
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cin >> ar[i][j];
                if (ar[i][j]){
                    r[i] = 1;
                    c[j] = 1;
                }
            }
        }
        int crow = 0, ccol = 0;
        for (int i=1;i<=n;i++){
            if (!r[i]) crow++;
        }
        for (int i=1;i<=m;i++){
            if (!c[i]) ccol++;
        }
        int mn = min(crow, ccol);
        if (mn % 2 == 0){
            cout << "Vivek" << el;
        } else{
            cout << "Ashish" << el;
        }
    }

    return 0;
}