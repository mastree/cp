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

const int N=100010;

int n;
pii ar[N];
vector <pii> vx,vy;
int par[N],sz[N];
ll tot=0;

priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> pq;

int find(int a){
    if (par[a]!=a)
        return par[a] = find(par[a]);
    else return a;  
}

void make(int a,int b){
    int pa=find(a);
    int pb=find(b);

    if (pa==pb) return;

    if (sz[pa]<sz[pb]){
        swap(pa,pb);
    }

    sz[pa]+=sz[pb];
    par[pb]=pa;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<N;i++){
        par[i]=i;
        sz[i]=1;
    }

    cin >> n;
    for (int i=0;i<n;i++){
        cin >> ar[i].fi >> ar[i].se;
        vx.pb(mp(ar[i].fi,i));
        vy.pb(mp(ar[i].se,i));
    }

    sort(vx.begin(),vx.end());
    sort(vy.begin(),vy.end());

    for (int i=0;i<vx.size()-1;i++){
        pair<int,pii> tm;
        tm.fi=vx[i+1].fi-vx[i].fi;
        tm.se.fi=vx[i].se;
        tm.se.se=vx[i+1].se;

        pq.push(tm);
    }

    for (int i=0;i<vy.size()-1;i++){
        pair<int,pii> tm;
        tm.fi=vy[i+1].fi-vy[i].fi;
        tm.se.fi=vy[i].se;
        tm.se.se=vy[i+1].se;

        pq.push(tm);
    }

    while (!pq.empty()){
        int del=pq.top().fi;
        int a=pq.top().se.fi;
        int b=pq.top().se.se;

     //   cerr << del << " " << a << " " << b << el;

        pq.pop();
        a=find(a);
        b=find(b);
        if (a==b){
            continue;
        }

        tot+=del;
        make(a,b);
    }

    cout << tot << el; 

    return 0;
}