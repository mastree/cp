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

const int N = 110;

int n, q;
int ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
        }
        sort(ar + 1, ar + n + 1, greater<int>());

        for (int i=1;i<=n;i++){
            cout << ar[i] << " ";
        }
        cout << el;
    }

    return 0;
}