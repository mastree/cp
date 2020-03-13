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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;

    while (q--){
        int n;
        cin >> n;

        int ar1[n+4], ar2[n+4];
        for (int i=1;i<=n;i++){
            cin >> ar1[i];
        }

        for (int i=1;i<=n;i++){
            cin >> ar2[i];
        }

        int beda[n+4];
        for (int i=1;i<=n;i++){
            beda[i] = ar2[i]-ar1[i];
        }

        int bef=0;
        int cnt=0;
        bool bisa=1;
        for (int i=1;i<=n;i++){
            // cout << beda[i] << " ";
            if (beda[i]<0){
                bisa=0;
            }
            if (beda[i]==bef){
            } else{
                if (beda[i]==0){
                    bef=0;
                } else{
                    bef = beda[i];
                    cnt++;
                }
            }
        } //cout << el;

        if (bisa && cnt<=1){
            cout << "YES" << el;
        } else{
            cout << "NO" << el;
        }
    }

    return 0;
}