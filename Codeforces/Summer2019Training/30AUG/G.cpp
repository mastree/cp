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
map<pii,bool> cek;
vector <pair<int,ll>> adlist[200005];
priority_queue <hue> pq;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i=0;i<n;i++){
        int a,b;
        ll w;
        cin >> a >> b >> w;

        adlist[a].pb(mp(b,w));
        adlist[b].pb(mp(a,w));

        if (a>b) swap(a,b);
        cek[mp(a,b)]=1;

        hue tm;
        tm.w=w;
        tm.node.fi=a;
        tm.node.se=b;
        pq.push(hue);

        if (pq.size()>)
    }



    return 0;
}