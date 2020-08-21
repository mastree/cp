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

int n,m;
pii ar[500010];
int mr[500010];
vector <pii> v;

int up[20][500010];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    for (int i=0;i<500010;i++){mr[i]=i;}

    cin >> n >> m;
    for (int i=0;i<n;i++){
        cin >> ar[i].fi >> ar[i].se;
        mr[ar[i].fi]=max(mr[ar[i].fi],ar[i].se);
    }

    for (int i=1;i<500010;i++){
        mr[i]=max(mr[i],mr[i-1]);
    }

    for (int i=0;i<500010;i++){
        if (mr[i]<=i) continue;

        up[0][i]=mr[i];
    }

    for (int i=1;i<20;i++){
        for (int j=0;j<500010;j++){
            if (up[i-1][j]<=j) continue;
            
            up[i][j]=up[i-1][up[i-1][j]];
        }
    }

    /* 
    int bef=0;
    for (int i=0;i<500010;i++){
        if (bef!=mr[i]){
            v.pb(mp(i,mr[i]));
            bef=mr[i];
        }
    }
    */


    while (m--){
        int a,b;
        cin >> a >> b;

        int ans=0;
    //    cerr << "alur :" << a << " ";
        for (int i=19;i>=0;i--){
            if (up[i][a]<=a) continue;

            if (up[i][a]<=b){
    //            cerr << up[i][a] << " ";
                ans+=(1 << i);
                a=up[i][a];
            }
        }
    //    cerr << el;
        
        if (up[0][a]>=b && a<b) cout << ans+1 << el;
        else if (a<b) cout << -1 << el;
        else cout << ans << el;
    }


    return 0;
}