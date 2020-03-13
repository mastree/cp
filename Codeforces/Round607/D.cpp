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

int q;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        int r,c;
        cin >> r >> c;

        int ar[r+4][c+4];
        int pre[r+4][c+4];
        for (int i=0;i<=r;i++){
            for (int j=0;j<=c;j++){
                pre[i][j]=0;
            }
        }
        for (int i=1;i<=r;i++){
            for (int j=1;j<=c;j++){
                char c;
                cin >> c;
                if (c=='A') ar[i][j]=1;
                else ar[i][j]=0; 
                pre[i][j]=pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + ar[i][j];
            }
        }

        if (pre[r][c] == 0){
            cout << "MORTAL" << el;
            continue;
        }

        if (pre[r][c] == r*c){
            cout << 0 << el;
            continue;
        } else{
            bool gar=0;
            gar = (pre[1][c]==c || (pre[r][c]-pre[r-1][c]==c) || pre[r][1]==r || (pre[r][c]-pre[r][c-1]==r));

            if (gar){
                cout << 1 << el;
                continue;
            } 

            for (int i=1;i<=r;i++){
                if (pre[i][c]-pre[i-1][c]==c){
                    gar=1;
                }
            }

            for (int i=1;i<=c;i++){
                if (pre[r][i]-pre[r][i-1]==r){
                    gar=1;
                }
            }

            if (ar[1][1] || ar[r][1] || ar[1][c] || ar[r][c]) gar=1;
            if (gar){
                cout << 2 << el;
                continue;
            }

            for (int i=1;i<=r;i++){
                if (ar[i][c] || ar[i][1]){
                    gar=1;
                }
            }

            for (int i=1;i<=c;i++){
                if (ar[r][i] || ar[1][i]){
                    gar=1;
                }
            }

            if (gar){
                cout << 3 << el;
                continue;
            }

            cout << 4 << el;
        }

    }

    return 0;
}