#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'
#define pil pair<int,ll>

using namespace std;

int q;
int cnt[1001][1001][101];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;

    while (q--){
        int n,c,r;
        cin >> n >> c >> r;

        pii un[r];
        for (int i=0;i<r;i++){
            cin >> un[i].fi >> un[i].se;
        }
        
        pil ar[n+1];
        for (int i=1;i<=n;i++){
            cin >> ar[i].fi >> ar[i].se;
        }

        for (int i=1;i<=n;i++){
            for (int j=1;j<n;j++){
                int tm=i+j;
                if (tm>n) tm-=n;
                if (tm!=1) cnt[i][tm]=cnt[i][tm-1];
                else cnt[i][tm]=cnt[i][n];
                
            }
        }
    }

    return 0;
}