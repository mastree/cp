#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1e18
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

vector <pii> adl[200010]; 
vector <pair<pii,int>> inp;
map <int,bool> cek;
map <int,int> conv;
ll ans[900][900];

bool cmp(pair<pii,int> a, pair<pii,int> b){
    return (a.se<b.se);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m,ke;
    cin >> n >> m >> ke;

    for (int i=0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        inp.pb(mp(mp(a,b),w));
    }

    sort(inp.begin(),inp.end(),cmp);
    
    int cnt=0;
    for (int i=0;i<min(ke,m);i++){
        int a=inp[i].fi.fi,b=inp[i].fi.se,w=inp[i].se;
        if (!cek[a]){
            cek[a]=1;
            conv[a]=cnt;
            cnt++;
        }
        if (!cek[b]){
            cek[b]=1;
            conv[b]=cnt;
            cnt++;
        }
    }

    for (int i=0;i<900;i++){
        for (int j=0;j<900;j++){
            ans[i][j]=INF;
        }
    }

    for (int i=0;i<min(ke,m);i++){
        int a=inp[i].fi.fi,b=inp[i].fi.se,w=inp[i].se;

        a=conv[a];b=conv[b];

        ans[a][b]=min(ans[a][b],(ll)w);
        ans[b][a]=min(ans[b][a],(ll)w);
    }

    for (int k=0;k<cnt;k++){
        for (int i=0;i<cnt;i++){
            for (int j=0;j<cnt;j++){
                ans[i][j]=min(ans[i][j],ans[i][k]+ans[k][j]);
            }n
        }
    }

    vector <ll> v;
    for (int i=0;i<cnt;i++){
        for (int j=i+1;j<cnt;j++){
            v.pb(ans[i][j]);
        }
    }
    sort(v.begin(),v.end());

    cout << v[ke-1] << el;

    return 0;
}