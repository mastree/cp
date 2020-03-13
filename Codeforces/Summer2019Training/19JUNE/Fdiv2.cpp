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

int pow2[10];
bool ada[512][512];
int ar[512];
vector <pii> vv[512];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<10;i++) pow2[i]=(1 << i);

    int n,m;
    cin >> n >> m;

    for (int i=0;i<n;i++){
        int tm,tot=0;
        cin >> tm;
        for (int j=0;j<tm;j++){
            int tm2;
            cin >> tm2;
            tot+=pow2[tm2-1];
        }

        ar[tot]++;
    }

    map <int,pair<int,int>> piz;
    for (int i=0;i<m;i++){
        int tm,tot=0,cost;
        cin >> cost >> tm;
        for (int j=0;j<tm;j++){
            int tm2;
            cin >> tm2;
            tot+=pow2[tm2-1];
        }

        vv[tot].pb(mp(cost,i+1));
        if (piz[tot]==mp(0,0)) piz[tot]=mp(cost,i+1);
        else if (piz[tot].fi > cost) piz[tot]=mp(cost,i+1);
    }


    vector <int> v;
    int cek[512];
    for (int i=0;i<512;i++){
        cek[i]=0;
        sort(vv[i].begin(),vv[i].end());
    }
    for (auto x : piz){
        v.pb(x.fi);
        cek[x.fi]=x.se.fi;
    }

    pair <int,int> ans={-1,-1}; // bit1,bit2;
    int total=-1,cost=-1;

    for (int i=0;i<511;i++){
        for (int j=i+1;j<512;j++){
            if (cek[i]==0 || cek[j]==0) continue;int tot=0;
            int tm=(i|j);
            
            for (int z=1;z<512;z++){
                if ((tm&z)==z){
                    tot+=ar[z];
                }
            }

            if (total<tot){
                total=tot;
                ans=mp(i,j);
                cost=cek[i]+cek[j];
            } else if (total==tot){
                if (cost>cek[i]+cek[j]){
                    cost=cek[i]+cek[j];
                    ans=mp(i,j);
                }
            }
        }
    }

    if (ans==mp(-1,-1)){
        cout << 1 << " " << 2 << el;
        return 0;
    }

    int tm1=0,tm2=0,cmin=0;
    for (int i=1;i<512;i++){
        if ((ans.fi&i)==i) tm1+=ar[i];
        if ((ans.se&i)==i) tm2+=ar[i];
    }
    if (tm1==total && vv[ans.fi].size()>1){
        cmin=vv[ans.fi][0].fi+vv[ans.fi][1].fi;
        if (cmin<cost){
            cout << vv[ans.fi][0].se << " " << vv[ans.fi][1].se << el;
            return 0;
        }
    }

    if (tm2==total && vv[ans.se].size()>1){
        cmin=vv[ans.se][0].fi+vv[ans.se][1].fi;
        if (cmin<cost){
            cout << vv[ans.se][0].se << " " << vv[ans.fi][1].se << el;
            return 0;
        }
    }

    cout << piz[ans.fi].se << " " << piz[ans.se].se << el;

    return 0;
}