#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ll long long
#define el '\n'

using namespace std;

ll n,k,Ntype=0;
vector <pll> ar;
vector <ll> yetpicked,already;
vector <ll> v[100009];
ll cnt[100009],tot=0,picked=0; // cnt[type];

bool cmp(pll a, pll b){
    return a.fi>=b.fi;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (ll i=0;i<n;i++){
        ll t,d;
        cin >> t >> d;
        ar.pb(mp(d,t));
        v[t].pb(d);
        Ntype=max(Ntype,t);
    } 

    for (ll i=0;i<=Ntype;i++){
        cnt[i]=0;
    }

    sort(ar.begin(),ar.end(),cmp);
    for (ll i=1;i<=Ntype;i++){
        if (!v[i].empty()) sort(v[i].begin(),v[i].end(),greater<ll>());
    }

    for (ll i=0;i<k;i++){
        tot+=ar[i].fi;
    //    cerr << ar[i].fi << " " << ar[i].se << ;
        if (cnt[ar[i].se]==0) picked++;
        cnt[ar[i].se]++;
    }

    for (ll i=0;i<=Ntype;i++){
        if (cnt[i]==0 && !v[i].empty()){
            yetpicked.pb(v[i][0]);
        }
        if (cnt[i]>1){
            for (ll j=1;j<cnt[i];j++) already.pb(v[i][j]);
        }
    }
    if (yetpicked.empty() || already.empty()){
        cout << tot+picked*picked << el;
        return 0;
    }
    sort(yetpicked.begin(),yetpicked.end(),greater<ll>());
    sort(already.begin(),already.end());

    ll allen=already.size(),yetlen=yetpicked.size();
    ll ans=tot+picked*picked;
    for (ll i=0;i<min(allen,yetlen);i++){
        tot+=yetpicked[i]-already[i];
        picked++;
        ans=max(ans,tot+picked*picked);
    }


/* 
    ll ans=tot+picked*picked,id=k-1,yet=0,yetlen=yetpicked.size();
    while (id>=0 && yet<yetlen && picked<Ntype){
        while (id>0 && cnt[ar[id].se]<=1){
            id--;
        }
        if (cnt[ar[id].se]<=1) break;

        tot-=ar[id].fi;
        tot+=yetpicked[yet];yet++;picked++;
        cnt[ar[id].se]--;id--;
        ans=max(ans,tot+picked*picked);
    }
*/
    cout << ans << el;

    return 0;
}