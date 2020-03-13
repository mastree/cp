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

int q;
int n;
ll b, tot;
vector <ll> cost[11];
vector <int> len;
vector <int> dpid;
map <vector<int>,bool> cek;

void reset_vector(){
    tot=0;
    len.clear();
    len.shrink_to_fit();
    dpid.clear();
    dpid.shrink_to_fit();
    for (int i=0;i<n;i++){
        dpid.pb(0);
    }
    for (int i=0;i<11;i++){
        cost[i].clear();
        cost[i].shrink_to_fit();
    }
}

void dp(){
    if (cek[dpid]) return;
    cek[dpid]=1;
    for (int i=0;i<n;i++){
    //    cout << dpid[i] << " ";
        if (dpid[i]>=len[i]){
            return;
        }
    }

    ll res=0;
    for (int i=0;i<n;i++){
        res+=cost[i][dpid[i]];
    }
    //cout << res << " " << b << el;
    if (res>b) return;
    tot=max(tot,res);
    for (int i=0;i<n;i++){
        dpid[i]++;
        dp();
        dpid[i]--;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cek.clear();
        cin >> b >> n;

        bool udah[n+1];
        for (int i=0;i<n+1;i++){
            udah[i]=0;
        }

        reset_vector();

        for (int i=0;i<n;i++){
            int a;
            cin >> a;
            len.pb(a);
        }

    //    vector <pli> v;
        for (int i=0;i<n;i++){
            for (int j=0;j<len[i];j++){
                ll c;
                cin >> c;
                cost[i].pb(c);
            }
            sort(cost[i].begin(), cost[i].end());
            // for (int j=1;j<len[i];j++){
            //     v.pb(mp(cost[i][j]-cost[i][0],i));
            // }
        }
        dp();
        cout << tot << el;

    }

    return 0;
}