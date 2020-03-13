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

ll n,k,Mtipe=0;
vector <pair<ll,ll>> as; // jumlah,tipe
vector <ll> tp[100005]; // sushi pertipe

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i=0;i<n;i++){
        ll t,d;
        cin >> t >> d;
        as.pb(mp(d,t));
        tp[t].pb(d);
        Mtipe=max(Mtipe,t);
    }

    sort(as.begin(),as.end(),greater<pair<ll,ll>>());
    ll cek[Mtipe+1];
    ll tot=0,picked=0;
    for (int i=0;i<=Mtipe;i++) cek[i]=0;
    for (int i=0;i<k;i++){
        if (cek[as[i].se]==0){
            picked++;
        }
        cek[as[i].se]++;
        tot+=as[i].fi;
    }

    vector <ll> alt;
    for (int i=1;i<=Mtipe;i++){
        if (cek[i]==0 && !tp[i].empty()){
            ll maks=0;
            for (auto x : tp[i]){
                maks=max(maks,x);
            }
            alt.pb(maks);
        }
    }

    sort(alt.begin(),alt.end(),greater<ll>());

    auto ite=alt.begin();
    ll id=k-1,ans=tot+picked*picked;

    while (id>=0 && ite!=alt.end()){
        while (cek[as[id].se]==1 && id>0) id--;
        if (cek[as[id].se]<=1) break;

        cek[as[id].se]--;
        tot-=as[id].fi;
        tot+=*ite;
        picked++;
        ans=max(ans,tot+picked*picked);

        ite++;
        id--;
    }

    cout << ans << el;

    return 0;
}