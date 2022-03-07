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
        int ar[3];
        for (int i=0;i<3;i++){
            cin >> ar[i];
        }

        sort(ar, ar+3);
        int ans=0;
        ans=ar[0];
        int sel = ar[2] - ar[1];
        int kur = min(sel, ar[0]);
        ar[2]-=kur;
        ar[0]-=kur;
        kur = (ar[0]+1)/2;
        ar[1]-=kur;
        ar[2]-=kur;
        ans+=ar[1];

        cout << ans << el;
    }

    return 0;
}