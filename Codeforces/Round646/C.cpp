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

string win[2] = {"Ayush",  "Ashish"};

int q;
int n, sp;
int deg[N];
vector<int> adl[N];

int cnt;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> sp;
        fill(deg, deg + n + 2, 0);
        for (int i=1;i<=n;i++){
            adl[i].clear();
        }
        for (int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adl[a].pb(b);
            adl[b].pb(a);
            deg[a]++;
            deg[b]++;
        }
        if (deg[sp] <= 1){
            cout << win[0] << el;
            continue;
        }

        cnt = n - 3;
        if (cnt & 1){
            cout << win[0] << el;
        } else{
            cout << win[1] << el;
        }
    }

    return 0;
}