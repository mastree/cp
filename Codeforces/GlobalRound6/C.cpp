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

const int N = 505;
const ll INF = 1e18 + 10;

int r,c;
ll ar1[N*N], mat1[N][N];
ll ar2[N*N], mat2[N][N];

ll res = INF;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;
    if (r==c && r==1){
        cout << 0 << el;
        return 0;
    }

    int len = r+c;
    for (int i=1;i<=len;i++){
        ar1[i]=i;
    }

    for (int i=1;i<=len;i++){
        ar2[i]=len-i+1;
    }


    // r => c dan c => r
    for (int i=1;i<=r;i++){
        for (int j=1;j<=c;j++){
            mat1[i][j] = ar1[i] * ar1[r+j] / __gcd(ar1[i], ar1[r+j]);
            mat2[i][j] = ar2[i] * ar2[r+j] / __gcd(ar2[i], ar2[r+j]);
            // cout << "(" << ar2[i] << "," << ar2[r+j] << ") ";
        }
        // cout << el;
    }

    // ll m1=-1, m2=-1;
    // for (int i=1;i<=r;i++){
    //     ll tm1 = 1, tm2 = 1;
    //     for (int j=1;j<=c;j++){
    //         tm1 = __gcd(tm1, mat1[i][j]);
    //         tm2 = __gcd(tm2, mat2[i][j]);
    //     }
    //     m1 = max(m1, tm1);
    //     m2 = max(m2, tm2);
    // }
    // for (int i=1;i<=c;i++){
    //     ll tm1 = 1, tm2 = 1;
    //     for (int j=1;j<=r;j++){
    //         tm1 = __gcd(tm1, mat1[j][i]);
    //         tm2 = __gcd(tm2, mat2[j][i]);
    //     }
    //     m1 = max(m1, tm1);
    //     m2 = max(m2, tm2);
    // }

    if (r<c){
        for (int i=1;i<=r;i++){
            for (int j=1;j<=c;j++){
                cout << mat1[i][j] << " ";
            }
            cout << el;
        }
    } else{
        for (int i=1;i<=r;i++){
            for (int j=1;j<=c;j++){
                cout << mat2[i][j] << " ";
            }
            cout << el;
        }
    }

    return 0;
}