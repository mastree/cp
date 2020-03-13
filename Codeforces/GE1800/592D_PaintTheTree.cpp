#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1000000000000000000
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 100009;

int n;
int color[N];
ll cost[N][3];
vector <int> adl[N];
int permute[3] = {0,1,2};
int permen[3] = {0,1,2};
ll tot=INF;

void dfs(int a, int col){
    int cur=0;
    if (col==cur || color[a]==cur) cur++;
    if (col==cur || color[a]==cur) cur++;
    for (auto dest : adl[a]){
        if (color[dest]==-1){
            color[dest]=cur;
            dfs(dest, color[a]);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<N;i++){
        color[i]=-1;
    }

    cin >> n;
    for (int j=0;j<3;j++){
        for (int i=1;i<=n;i++){
            cin >> cost[i][j];
        }
    }

    for (int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
    }

    int mulai=-1;
    for (int i=1;i<=n;i++){
        if (adl[i].size()>2){
            cout << -1 << el;
            return 0;
        } else if (adl[i].size()==1){
            mulai=i;
        }
    }

    color[mulai]=0;
    dfs(mulai,2);

    int id;
    for (int i=0;i<6;i++){
        ll tm=0;
        for (int i=1;i<=n;i++){
            tm+=cost[i][permute[color[i]]];
        }

        if (tot>tm){
            tot=tm;
            id=i;
        }

        next_permutation(permute,permute+3);
    }

    for (int i=0;i<id;i++) next_permutation(permen,permen+3);

    cout << tot << el;
    for (int i=1;i<=n;i++){
        cout << permen[color[i]]+1 << " ";
    }
    cout << el;

    return 0;
}