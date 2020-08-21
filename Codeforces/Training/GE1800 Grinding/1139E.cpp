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

const int N = 5e3 + 10;

int n, m;
int pot[N], mem[N];
int day, k[N];
bool queried[N];

vector<int> adl[N + N];
bool vis[N + N];
int match[N + N];

bool findnext(int node){
    if (vis[node]) return 0;
    vis[node] = 1;
    for (auto x : adl[node]){
        if (match[x] == -1){
            match[node] = x;
            match[x] = node;
            return 1;
        } else if (findnext(match[x])){
            match[node] = x;
            match[x] = node;    
            return 1;
        }
    }
    return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> pot[i];
    }
    for (int i=1;i<=n;i++){
        cin >> mem[i];
    }
    cin >> day;
    for (int i=1;i<=day;i++){
        cin >> k[i];
        queried[k[i]] = 1;
    }
    for (int i=1;i<=n;i++){
        if (queried[i]) continue;
        adl[pot[i]].pb(mem[i] + N);
        adl[mem[i] + N].pb(pot[i]);
    }

    int ans = 0;
    fill(match, match + N + N, -1);
    while (findnext(ans)){
        ans++;
        fill(vis, vis + N + N, 0);
    }
    vector<int> v(day + 1);
    for (int i=day;i>=1;i--){
        v[i] = ans;
        adl[pot[k[i]]].pb(mem[k[i]] + N);
        adl[mem[k[i]] + N].pb(pot[k[i]]);
        fill(vis, vis + N + N, 0);
        while (findnext(ans)){
            ans++;
            fill(vis, vis + N + N, 0);
        }
    }
    for (int i=1;i<=day;i++){
        cout << v[i] << el;
    }

    return 0;
}