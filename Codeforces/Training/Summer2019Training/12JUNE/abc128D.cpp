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

vector <int> presort1[51],presort2[51];
int le[51][101],ri[51][101]; // [pernah di-ambil][langkah]

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin >> n >> k;
    int ar[n+1],minus=0,tot=0;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        if (ar[i]<0){
            minus++;
        } else tot+=ar[i];
    }

    if (n+minus<=k){
        cout << tot << el;
        return 0;
    }
    
    for (int i=1;i<=n;i++){
        for (int j=1;j<=i;j++) presort1[i].pb(ar[j]);

        sort(presort1[i].begin(),presort1[i].end(),greater<int>());
    }

    for (int i=n;i>=1;i--){
        for (int j=i;j<=n;j++) presort2[n-i+1].pb(ar[j]);

        sort(presort2[n-i+1].begin(),presort2[n-i+1].end(),greater<int>());
    }

    for (int i=0;i<=n;i++){
        int total=0;
        for (auto x : presort1[i]) total+=x;
        
        int id=i;
        le[i][id]=total;
        for (int j=i-1;j>=0;j--){
            id++;
            total-=presort1[i][j];
            le[i][id]=total;
        }
    }    

    for (int i=0;i<=n;i++){
        int total=0;
        for (auto x : presort2[i]) total+=x;

        int id=i;
        ri[i][id]=total;
        for (int j=i-1;j>=0;j--){
            id++;
            total-=presort2[i][j];
            ri[i][id]=total;
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=k;j++){
            le[i][j]=max(le[i][j],max(le[i-1][j],le[i][j-1]));
            ri[i][j]=max(ri[i][j],max(ri[i-1][j],ri[i][j-1]));
        }
    }

    int ans=0;
    for (int i=0;i<=n;i++){
        for (int j=0;j<=k;j++){
            ans=max(ans,le[i][j]+ri[n-i][k-j]);
        }
    }

    cout << ans << el;

    return 0;
} 