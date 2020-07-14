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

int q;
int ar[3];

// int perm[3] = {0, 1, 2};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> ar[0] >> ar[1] >> ar[2];
        string ans[3];
        if (!ar[0] || !ar[1] || !ar[2]){
            if (!ar[0]){
                if (ar[2]){
                    for (int i=1;i<=ar[2] + 1;i++) ans[2].pb('1');
                    for (int i=1;i<=ar[1];i++){
                        if (i & 1) ans[1].pb('0');
                        else ans[1].pb('1');
                    }
                    cout << ans[2] << ans[1] << el;
                } else{
                    ans[1].pb('0');
                    for (int i=1;i<=ar[1];i++){
                        if (i & 1) ans[1].pb('1');
                        else ans[1].pb('0');
                    }
                    cout << ans[1] << el;
                }
                continue;
            } else if (!ar[1]){
                for (int i=1;i<=ar[0] + 1;i++) ans[0].pb('0');
                for (int i=1;i<=ar[2] + 1;i++) ans[2].pb('1');
                if (ar[0]) cout << ans[0] << el;
                else cout << ans[2] << el;
                continue;
            } else{
                for (int i=1;i<=ar[0] + 1;i++) ans[0].pb('0');
                for (int i=1;i<=ar[1];i++){
                    if (i & 1) ans[1].pb('1');
                    else ans[1].pb('0');
                }
                cout << ans[0] << ans[1] << el;
                continue;
            }
        } else{
            if (ar[1] & 1){
                ans[0].pb('0');
                for (int i=1;i<=ar[0];i++){
                    ans[0].pb('0');
                }
                for (int i=1;i<=ar[1];i++){
                    if (i & 1){
                        ans[1].pb('1');
                    } else{
                        ans[1].pb('0');
                    }
                }
                for (int i=1;i<=ar[2];i++){
                    ans[2].pb('1');
                }
                cout << ans[0] << ans[1] << ans[2] << el;
            } else {
                for (int i=1;i<=ar[0] + 1;i++) ans[0].pb('0');
                for (int i=1;i<=ar[2] + 1;i++) ans[2].pb('1');
                ar[1]--;
                for (int i=1;i<=ar[1];i++){
                    if (i & 1) ans[1].pb('1');
                    else ans[1].pb('0');
                }
                cout << ans[2] << ans[0] << ans[1] << el;
            }
        }
    }

    return 0;
}