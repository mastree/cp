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

const int N = 100007;

int q;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        int a,b,c;
        cin >> a >> b >> c;
        int ans=0;

        while ((b*2>c) && a>0 && b>1){
            a--;
            b-=2;
            ans+=3;
        }

        while (b>0 && c>1){
            b--;
            c-=2;
            ans+=3;
        }

        cout << ans << el;
    }

    return 0;
}