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

int q;
int n, k;
int arsub[N];
vector<int> sub[N];

int askrange(int l, int r){
    cout << "? " << r - l + 1 << " ";
    for (int i=l;i<=r;i++){
        cout << i << " ";
    }
    cout << endl;
    int ret;
    cin >> ret;
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cout << flush;
        cin >> n >> k;
        fill(arsub, arsub + N, 0);
        for (int i=1;i<=k;i++){
            sub[i].clear();
            int len;
            cin >> len;
            for (int j=0;j<len;j++){
                int a;
                cin >> a;
                sub[i].pb(a);
                arsub[a] = i;
            }
        }

        int mx = 0, pos = -1;
        mx = askrange(1, n);
        int low = 1, high = n;
        while (low < high){
            int mid = (low + high) / 2;
            int res = askrange(1, mid);

            if (res != mx){
                low = mid + 1;
            } else{
                high = mid;
            }
        }
        pos = high;
        int subpos = arsub[pos];
        int atsubpos = 0;

        vector<int> temp;
        for (int i=1;i<=n;i++){
            if (arsub[i] == subpos) continue;
            temp.pb(i);
        }
        cout << "? " << temp.size() << " ";
        for (auto x : temp){
            cout << x << " ";
        }
        cout << endl;
        cin >> atsubpos;

        cout << "! ";
        for (int i=1;i<=k;i++){
            if (i != subpos){
                cout << mx << " "; 
            } else{
                cout << atsubpos << " ";
            }
        }
        cout << endl;

        string dummy;
        cin >> dummy;
        cout << flush;
        if (dummy != "Correct") return 0;
    }

    return 0;
}