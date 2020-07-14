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

vector <int> adlist[100100];

void make(int a,int b){
    int pa=parent(a),pb=parent(b);
    if (sz[pa]>=sz[pb]){
        sz[pa]+=sz[pb];
        par[pb]=pa;
    } else{
        sz[pb]+=sz[pb];
        par[pa]=pb;
    }
}

int parent(int a){
    while (par[a]!=a){
        a=par[a];
    }
    return a;
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;

    for (int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;

        adlist[a].pb(b);
    }

    cout << n/2 << el;

    return 0;
}  