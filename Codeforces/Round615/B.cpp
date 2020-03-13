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

int t;
pii ar[N];
int n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--){
        cin >> n;
        for (int i=1;i<=n;i++){
            cin >> ar[i].fi >> ar[i].se;
        }
        sort(ar + 1, ar + n + 1);
        string ans = "";
        bool bisa = 1;
        for (int i=1;i<=n;i++){
            if (ar[i].fi >= ar[i-1].fi && ar[i].se >= ar[i-1].se){
                for (int j=0;j<ar[i].fi-ar[i-1].fi;j++){
                    ans.pb('R');
                }
                for (int j=0;j<ar[i].se-ar[i-1].se;j++){
                    ans.pb('U');
                }
            } else{
                bisa = 0;
                break;
            }
        }
        if (bisa){
            cout << "YES" << el;
            cout << ans << el;
        } else{
            cout << "NO" << el;
            continue;
        }
    }

    return 0;
}