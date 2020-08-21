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
int cost[10]={0,2,5,5,4,5,6,3,7,6};
vector <pii> v; // (cost,digit)
vector <int> ans;
vector <pii> dp[2005];

bool cmp(pii a, pii b){
    if (a.fi!=b.fi) return (a.fi<b.fi);
    
    return (a.se>=b.se);
}

int kpk(int a,int b){
    int tm=a,fpb=b;

    while (tm%fpb!=0){
        int c=fpb;
        fpb=tm%fpb;
        tm=c;
    }

    return (a*b)/fpb;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=0;i<m;i++){
        int tm;
        cin >> tm;
        v.pb(mp(cost[tm],tm));
    }

    sort(v.begin(),v.end(),cmp);
    int lcm=v[0].fi;
    for (auto x : v){
        lcm=kpk(lcm,x.fi);
    }
     
    int exact=n/lcm;
    if (exact>0){
        exact--;
        n-=lcm*exact;
    }
    
    for (int i=0;i<exact*(lcm/v[0].fi);i++){
        ans.pb(v[0].se);
    }

    vector <pii> rek;
    bool cek[10];
    for (int i=0;i<10;i++) cek[i]=0;
    for (auto x : v){
        if (cek[x.fi]) continue;
        if (x.fi==4 && cek[2]) continue;
        if (x.fi==6 && (cek[3] || cek[2])) continue;

        cek[x.fi]=1;
        rek.pb(x); 
    }    

    priority_queue <int,vector<int>,greater<int>> pq;
    pq.push(0);

    while (!pq.empty()){
        int id=pq.top();
        pq.pop();
        for (auto x : rek){
            if (id+x.fi>n) break;
            int a=dp[id].size()+1,b=dp[id+x.fi].size();
            if (b==0) pq.push(id+x.fi);
            if (a>b){
                for (int i=0;i<a-1;i++){
                    if (i<b){
                        dp[id+x.fi][i]=dp[id][i];
                    }else dp[id+x.fi].pb(dp[id][i]);
                }
                dp[id+x.fi].pb(mp(x.se,x.fi));
                sort(dp[id+x.fi].begin(),dp[id+x.fi].end(),greater<pii>());
            } else if (a==b){
                vector <pii> tm;
                for (auto z : dp[id]) tm.pb(z);
                tm.pb(mp(x.se,x.fi));
                sort(tm.begin(),tm.end(),greater<pii>());
                bool tuker=0;
                for (int i=0;i<a;i++){
                    if (tm[i]>dp[id+x.fi][i]){
                        tuker=1;break;
                    } else if (tm[i]<dp[id+x.fi][i]) break;
                }
                if (tuker){
                    for (int i=0;i<a;i++){
                        dp[id+x.fi][i]=tm[i];
                    }
                }
            }
        }

    }

    for (auto x : dp[n]) ans.pb(x.fi);
    

    sort(ans.begin(),ans.end(),greater<int>());
    for (auto x : ans) cout << x;
    cout << el;

    return 0;
}