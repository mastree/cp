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

const int N=2005;

int n;
ll ar[N][N];
ll pc1[N+N],pc2[N+N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> ar[i][j];
            pc1[i+j]+=ar[i][j];
            pc2[i+(n-j+1)]+=ar[i][j];
        }
    }

    ll mx1=-1,mx2=-1;
    pii koor1,koor2;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            ll tot=pc1[i+j]+pc2[i+(n-j+1)]-ar[i][j];
        //    cout << i << ", " << j << " = " << tot << el;
            if ((i+j)&1){
                if (tot>mx1){
                    mx1=tot;
                    koor1=mp(i,j);
                }
            }
            else {
                if (tot>mx2){
                    mx2=tot;
                    koor2=mp(i,j);
                }
            }
        }
    }

    cout << mx1+mx2 << el;
    cout << koor1.fi << " " << koor1.se << " " << koor2.fi << " " << koor2.se << el;

    return 0;
}