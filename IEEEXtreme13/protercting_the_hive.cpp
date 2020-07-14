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

const int N = 107;

int n,m;
int ar[N][N];
pii par[N][N];
int sz[N][N], hsz[N][N];
int csisi[N][N];

void init(){
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            par[i][j]=mp(i,j);
            sz[i][j]=0;
        //    cntsisi[i][j][0]=1;
            hsz[i][j]=6;
        }
    }
}

pii find(pii a){
    if (par[a.fi][a.se]==a) return a;
    return par[a.fi][a.se] = find(par[a.fi][a.se]);
}

void make(pii a, pii b){
    pii olda=a, oldb=b;
    a=find(a);
    b=find(b);

    if (a==b) return;
    if (sz[a.fi][a.se]==0 || sz[b.fi][b.se]==0) return;

    if (sz[a.fi][a.se]<sz[b.fi][b.se]) swap(a,b);

    hsz[a.fi][a.se]+=hsz[b.fi][b.se];        
    sz[a.fi][a.se]+=sz[b.fi][b.se];
    par[b.fi][b.se]=a;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    init();

    for (int i=1;i<=n;i++){
        for (int j=1;j<m+(i&1);j++){
            cin >> ar[i][j];
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=1;(j<m+i%2);j++){
            if (ar[i][j]){
                sz[i][j]=1;
                
                if (i&1){
                    for (int plus=-1;plus<=0;plus++){
                        if (sz[i-1][j+plus]){
                            make(mp(i,j),mp(i-1,j+plus));
                            hsz[i][j]-=2;
                            
                        }
                    }
                }
            }
        }
    }

    for (int i=1;i<=m;i++){
        for (int j=1;(j<m+i%2);j++){
            cout << cntsisi[i][j][1] << " ";
        } 
        cout << el;
    }

    int q;
    cin >> q;
    cout << q << el;
    while (q--){
        int a, b;
        char c;
        cin >> c >> a >> b;
        if (c=='k'){
            pii pala=find(mp(a,b));
            int tot=0;

            if (sz[pala.fi][pala.se]){
                for (int i=1;i<6;i++){
                    tot+=(6-i)*cntsisi[pala.fi][pala.se][i];
                    cout << "sisi ke-" << i << " : " << cntsisi[pala.fi][pala.se][i] << el;
                }
                cout << tot << el;
            } else{
                cout << 0 << el;
            }
        } else{
            sz[a][b]=1;
            if (a&1){
                for (int plus=-1;plus<=0;plus++){
                    if (sz[a-1][b+plus]){
                        make(mp(a,b),mp(a-1,b+plus));
                        int i=a, j=b;
                        cntsisi[i][j][csisi[i-1][j+plus]+1]++;
                        cntsisi[i][j][csisi[i][j]+1]++;
                        cntsisi[i-1][j+plus][csisi[i][j]+1]++;
                        cntsisi[i-1][j+plus][csisi[i-1][j+plus]+1]++;
                        csisi[i-1][j+plus]++;
                        csisi[i][j+plus]++;
                    }
                    if (sz[a+1][b+plus]){
                        make(mp(a,b),mp(a+1,b+plus));
                        int i=a, j=b;
                        cntsisi[i][j][csisi[i+1][j+plus]+1]++;
                        cntsisi[i][j][csisi[i][j]+1]++;
                        cntsisi[i+1][j+plus][csisi[i][j]+1]++;
                        cntsisi[i+1][j+plus][csisi[i+1][j+plus]+1]++;
                        csisi[i+1][j+plus]++;
                        csisi[i][j+plus]++;
                    }
                }
                for (int plus=-1;plus<=1;plus+=2){
                    if (sz[a][b+plus]){
                        make(mp(a,b),mp(a,b+plus));
                        int i=a, j=b;
                        cntsisi[i][j][csisi[i][j+plus]+1]++;
                        cntsisi[i][j][csisi[i][j]+1]++;
                        cntsisi[i][j+plus][csisi[i][j]+1]++;
                        cntsisi[i][j+plus][csisi[i][j+plus]+1]++;
                        csisi[i][j+plus]++;
                        csisi[i][j+plus]++;
                    }
                }
            }
        }
    //cout << "NYAMPE" << el;
    }

    return 0;
}