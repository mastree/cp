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

const int N = 2e5 + 10;

int n;
string ar[N];
int par[N];
int sz[N];
vector <int> v[26];

int find(int a){
    if (par[a] == a){
        return a;
    }
    return par[a] = find(par[a]);
}

void make(int a, int b){
    a = find(a);
    b = find(b);

    if (a==b) return;

    if (sz[b]>sz[a]) swap(a,b);

    sz[a]+=b;
    par[b]=a;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }

    for (int i=1;i<=n;i++){
        cin >> ar[i];
        int len = ar[i].length();
        bool udh[26];
        for (int j=0;j<26;j++){
            udh[j] = 0;
        }

        for (int j=0;j<len;j++){
            int id = (int)(ar[i][j] - 'a');
            // cout << id << " ";
            if (udh[id]) continue;

            udh[id]=1;
            v[id].pb(i);
            // cout << i << " ";
        }
        // cout << el;
    }

    // for (int i=0;i<26;i++){
    //     cout << v[i].size() << " ";
    // }cout << el;

    for (int i=0;i<26;i++){
        // cout << v[i].size() << el;
        if (v[i].empty()) continue;
        int idawal = v[i][0];
        // cout << i << " => ";
        for (auto x : v[i]){
            // cout << x << " ";
            make(idawal, x);
        }
        // cout << el;
    }

    int cnt=0;
    for (int i=1;i<=n;i++){
        if (par[i] == i){
            cnt++;
        }
    }

    cout << cnt << el;

    return 0;
}