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

struct hue{
    int fi,se; // left,right
    int tot;

    bool operator<(const hue& rhs) const
    {
        return (tot < rhs.tot);
    }
    bool operator>(const hue& rhs) const
    {
        return (tot > rhs.tot);
    }
};

pii ans[2005][2005];
bool zone[2005][2005];
bool vis[2005][2005];
int n,m,b,k,x,y;

priority_queue <hue,vector<hue>,greater<hue>> qu;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> b >> k >> x >> y;

    for (int i=1;i<=n;i++){
        string s;
        cin >> s;

        for (int j=1;j<=m;j++){
            zone[i][j]=(s[j-1]=='.');
        }
    }

    hue tm;
    tm.fi=b;
    tm.se=k;
    tm.tot=0;
    qu.push(tm);
    vis[b][k]=1;
    while (!qu.empty()){
        
        int a=qu.top().fi;
        int b=qu.top().se;
        int tt=qu.top().tot;
        qu.pop();
        //cout << a << " " << b << " " << tt << el;

        if (zone[a+1][b]&&(!vis[a+1][b])){
            tm.fi=a+1;
            tm.se=b;
            tm.tot=tt;
            qu.push(tm);
            ans[a+1][b]=ans[a][b];
            vis[a+1][b]=1;
        }

        if (zone[a-1][b]&&(!vis[a-1][b])){
            tm.fi=a-1;
            tm.se=b;
            tm.tot=tt;
            qu.push(tm);
            ans[a-1][b]=ans[a][b];
            vis[a-1][b]=1;
        }

        if (zone[a][b+1]&&(!vis[a][b+1])){
            tm.fi=a;
            tm.se=b+1;
            tm.tot=tt+1;
            qu.push(tm);
            ans[a][b+1]=ans[a][b];
            ans[a][b+1].se++;
            vis[a][b+1]=1;
        }

        if (zone[a][b-1]&&(!vis[a][b-1])){
            tm.fi=a;
            tm.se=b-1;
            tm.tot=tt+1;
            qu.push(tm);
            ans[a][b-1]=ans[a][b];
            ans[a][b-1].fi++;
            vis[a][b-1]=1;
        }

        
    }

    int cnt=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
         //   cerr << vis[i][j] << " " << ans[i][j].fi << " " << ans[i][j].se << "  ";
            if (vis[i][j]){
                if (ans[i][j].fi<=x && ans[i][j].se<=y){
                    cnt++;
                }
            }
        }//cerr << el;
    }

    cout << cnt << el;

    return 0;
}