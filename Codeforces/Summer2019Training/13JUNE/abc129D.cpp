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

bool ar[2005][2005];
vector <int> row[2005],col[2005];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int h,w;
    cin >> h >> w;

    for (int i=0;i<2005;i++){
        ar[0][i]=1;
        ar[i][0]=1;
        ar[h+1][i]=1;
        ar[i][w+1]=1;
    }

    for (int i=1;i<=h;i++){
        string s;
        cin >> s;

        for (int j=1;j<=w;j++){
            ar[i][j]=(s[j-1]=='#');
        }
    }

    for (int i=0;i<=h+1;i++){
        for (int j=0;j<=w+1;j++){
            if (ar[i][j]) row[i].pb(j);
        }
    }

    for (int j=0;j<=w+1;j++){
        for (int i=0;i<=h+1;i++){
            if (ar[i][j]) col[j].pb(i);
        }
    }

    int ans=0;
    for (int i=1;i<=h;i++){
        for (int j=1;j<=w;j++){
            if (!ar[i][j]){
                auto rlow=upper_bound(row[i].begin(),row[i].end(),j);
                auto rupp=rlow--;
                auto clow=upper_bound(col[j].begin(),col[j].end(),i);
                auto cupp=clow--;

                ans=max(ans,*rupp-*rlow+*cupp-*clow-3);
            //    cerr << *rupp - *rlow + *cupp - *clow - 1 << " "; 
            }
        }
        //cerr << el;
    }

    cout << ans << el;

    return 0;
}