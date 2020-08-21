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
int ar[N];
int le[N], ri[N];
int ans = -1, id;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=n;i++){
        le[i] = (le[i-1] | ar[i]);
    }
    for (int i=n;i>=1;i--){
        ri[i] = (ri[i+1] | ar[i]);
    }

    for (int i=1;i<=n;i++){
        int l = le[i-1];
        int r = ri[i+1];
        int temp = (l | r);
        if (ans < (ar[i] | temp) - temp){
            ans = (ar[i] | temp) - temp;
            id = i;
        }
    }

    cout << ar[id] << " ";
    for (int i=1;i<=n;i++){
        if (i == id) continue;
        cout << ar[i] << " ";
    }
    cout << el;

    return 0;
}