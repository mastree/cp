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

const int N = 4000;

int n;
int ar[N][N];
vector<pii> ans;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int r = 1, c = 1;
    for (int i=1;i<=n;i++){
        if (i == 1){
            for (int j=0;j<3;j++){
                ar[r + j][c] = 1;
                ar[r][c + j] = 1;
                ar[r + j][c + 2] = 1;
                ar[r + 2][c + j] = 1;
            }
            r += 2;
            c += 2;
        } 
        for (int j=0;j<3;j++){
            ar[r + j][c] = 1;
            ar[r][c + j] = 1;
            ar[r + j][c + 2] = 1;
            ar[r + 2][c + j] = 1;
        }
        r += 2;
        c += 2;
    }
    for (int i=1;i<N;i++){
        for (int j=1;j<N;j++){
            if (ar[i][j]){
                ans.pb(mp(i, j));
            }
        }
    }
    // for (int i=1;i<=20;i++){
    //     for (int j=1;j<=20;j++){
    //         cout << ar[i][j] << " ";
    //     }
    //     cout << el;
    // }
    cout << ans.size() << el;
    for (auto x : ans){
        cout << x.fi << " " << x.se << el;
    }

    return 0;
}