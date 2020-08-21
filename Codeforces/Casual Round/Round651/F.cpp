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

const int N = 1e3 + 10;

int q, n;
vector<int> adl[N];
vector<int> vj;

void init(){
    for (int i=0;i<N;i++){
        adl[i].clear();
    }
}
pii ask(vector<int>& v){
    cout << "? " << v.size() << " "; for (auto x : v) cout << x << " "; cout << endl;
    int a, b;
    cin >> a >> b;
    return mp(a, b);
}
void dfs_get(int node, int p, int dep){
    if (dep == 0){
        vj.pb(node);return;
    }
    for (auto x : adl[node]){
        if (x == p) continue;
        dfs_get(x, node, dep - 1);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        init();
        for (int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adl[a].pb(b);
            adl[b].pb(a);
        }
        vector<int> tanya;
        for (int i=1;i<=n;i++) tanya.pb(i);
        pii temp, feed;
        temp = ask(tanya);
        tanya.clear();

        int node1, node2;
        int low = 0, high = n - 1;
        while (low <= high){
            int mid = (low + high) / 2;
            vj.clear();
            dfs_get(temp.fi, temp.fi, mid);
            if (vj.empty()){
                high = mid - 1;
                continue;
            }
            feed = ask(vj);
            if (feed.se <= temp.se){
                low = mid + 1;
                node1 = feed.fi;
            } else{
                high = mid - 1;
            }
        }
        vj.clear();
        dfs_get(node1, node1, temp.se);
        feed = ask(vj);
        node2 = feed.fi;
        cout << "! " << node1 << " " << node2 << endl;
        string eval;
        cin >> eval;
        if (eval == "Incorrect") return 0;
    }

    return 0;
}