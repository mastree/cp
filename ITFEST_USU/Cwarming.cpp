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

const int N = 20;

vector <int> ans;
int n, m;
int ar[N];
bool ada[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=0;i<m;i++){
        int a;
        cin >> a;
        ada[a] = 1;
    }

    int cur = 1;
    for (int i=1;i<=n;i++){
        if (ada[ar[i]]){
            ans.pb(ar[i]);
        }
    }
    int len = ans.size();
    for (int i=0;i<len;i++){
        if (i != len-1) cout << ans[i] << " ";
        else cout << ans[i] << el;
    }

    return 0;
}