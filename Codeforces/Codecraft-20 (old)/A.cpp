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
int n, m;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> m;
        int cur = 0;
        for (int i=1;i<=n;i++){
            if (i == 1) cin >> cur;
            else{
                int a;
                cin >> a;
                cur += a;
            } 
        }

        cout << min(cur, m) << el;
    }

    return 0;
}