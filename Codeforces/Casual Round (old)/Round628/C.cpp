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

const int N = 1e5 + 10;

int n;
vector <int> adl[N];
pii edl[N];
int ans[N];
int now = 0;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(ans, ans + N, -1);

    cin >> n;
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
        edl[i] = mp(a, b);
    }

    for (int i=1;i<n;i++){
        if (adl[edl[i].fi].size() == 1 || adl[edl[i].se].size() == 1){
            ans[i] = now;
            now++;
        }
    }

    for (int i=1;i<n;i++){
        if (ans[i] == -1){
            ans[i] = now;
            now++;
        }
    }
    for (int i=1;i<n;i++){
        cout << ans[i] << el;
    }

    return 0;
}