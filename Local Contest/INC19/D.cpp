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

const int N = 100008;

int n,m,q;
int par[N];
int sz[N];
vector <int> adl[N];
stack<pii> st; // node, asal
bool vis[N];

int find(int a){
    if (par[a]==a) return a;
    return par[a] = find(par[a]);
}

void make(int a, int b){
    a=find(a);
    b=find(b);

    if (sz[a]<sz[b]){
        swap(a,b);
    }

    sz[a]+=sz[b];
    par[b]=a;
}

void dfs(int a, int par){

}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;

    for (int i=1;i<=n;i++){
        par[i]=i;
        sz[i]=1;
    }

    for (int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
    }

    
    st.push(mp(1,1));
//    cout << st.top().fi << " " << st.top().se << el;
//    cout << "tes" << el;

    while (!st.empty()){
        int node=st.top().fi;
        int asal=st.top().se;

        if (vis[node]){
            stack <pii> tmp;
            st.pop();
            tmp.push(st.top());
            
            while (find(st.top().fi)!=find(node)){
                tmp.push(st.top());
                make(tmp.top().fi,node);
                st.pop();
            }

            while (!tmp.empty()){
                st.push(tmp.top());
                tmp.pop();
            }
            continue;
        }
        vis[node]=1;

        for (auto x : adl[node]){
            if (x!=asal){
                st.push(mp(x,node));
            }
        }

        st.pop();
    }

    for (int i=1;i<=n;i++){
        cout << "node :" << i << " ,size :" << sz[i] << el; 
    }

    while (q--){
        int a,b;
        cin >> a >> b;
        a=find(a);
        b=find(b);
        if (a==b) cout << "YES" << el;
        else cout << "NO" << el;
    }

    return 0;
}