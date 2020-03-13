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

vector <int> vx[100005],vy[100005];
int szx[100005],szy[100005];
map <pii,bool> cek;
int ans=0;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <pii> v;
    
    for (int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        vx[a].pb(b);
        vy[b].pb(a);
        szx[a]++;
        szy[b]++;

        cek[mp(a,b)]=1;
    }

    for (int i=0;i<100005;i++){
        sort(vx[i].begin(),vx[i].end());
        sort(vy[i].begin(),vy[i].end());
    }

    for (int i=1;i<100005;i++){
        for (auto x : vx[i]){
            for (auto y : vy[x]){
                if (y==i) continue;
                int a=i,b=x,c=y,d;
                int ida=0,idc=0;

                while (ida<szx[a] && idc<szx[c]){
                    if (vx[a][ida]==vx[c][idc]){
                        ida++;idc++;continue;
                    }
                    if (vx[a][ida]<vx[c][idc]){
                        ans++;
                        ida++;
                        vx[][idc]
                    }
                }
                
            }
        }
    }

    return 0;
}