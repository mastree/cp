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

const int N=300007;

int n,m;
vector <pii> edl;
map<pii,bool> cek;
int head[4];
ll sz[4];
int par[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
 //   for (int i=0;i<4;i++) head[i]=-1;

    for (int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        edl.pb(mp(a,b));
        cek[mp(a,b)]=1;
        cek[mp(b,a)]=1;
    }

    for (int i=1;i<=n;i++){
        if (i==1){
            par[i]=1;
            head[1]=i;
            sz[1]++;
            continue;
        } 
        
        for (int j=1;j<=3;j++){
            if (head[j]){
                if (!cek[mp(i,head[j])]){
                    par[i]=j;
                    sz[j]++;
                    break;
                }
            }
        }

        if (!par[i]){
            for (int j=1;j<=3;j++){
                if (!head[j]){
                    head[j]=i;
                    par[i]=j;
                    sz[j]++;
                    break;
                }
            }
            if (!par[i]){
                cout << -1 << el;
                return 0;
            }
        }

    }

    bool valid=1;
    ll tot=sz[1]*(sz[2]+sz[3])+sz[2]*sz[3];
    for (auto x : edl){
        if (par[x.fi]==par[x.se]){
            if (cek[mp(x.fi,x.se)]){
                valid=0;break;
            //    return 0;
            }
        } else{
            if (!cek[mp(x.fi,x.se)]){
                valid=0;break;
            //    return 0;
            }   
        }
    }

    for (int i=1;i<=3;i++){
        if (sz[i]==0) valid=0;
    }
    if (valid && tot==m){
        for (int i=1;i<=n;i++) cout << par[i] << " ";cout << el;
    } else{
        cout << -1 << el;
    }

    return 0;
}