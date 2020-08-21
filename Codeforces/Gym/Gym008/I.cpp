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

int n, m, l;
bool on[N];
vector<int> trig[N];

bool eval(){
    for (int i=1;i<=m;i++) if (on[i]) return 0;
    return 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> l;
    for (int i=1;i<=l;i++){
        int a;
        cin >> a;
        on[a] = 1;
    }
    for (int i=1;i<=n;i++){
        int len;
        cin >> len;
        for (int j=0;j<len;j++){
            int a;
            cin >> a;
            trig[i].pb(a);
        }
    }
    int turn = 0;
    for (int lup=1;lup<=2;lup++){
        for (int i=1;i<=n;i++){
            turn++;
            for (auto x : trig[i]) on[x] = !on[x];
            if (eval()){
                cout << turn << el;
                return 0;
            }
        }
    }
    cout << -1 << el;

    return 0;
}