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
const int MX = 1e6;

int n;
int ar[N];
int br[N];

set<int> avai;
int cek[N];

int bit[MX + 10];

void update(int x, int add){
    x++;
    while (x < N){
        bit[x] += add;
        x = x + (x & (-x));
    }
}

int ask(int x){
    int ret = 0;
    x++;
    while (x){
        ret += bit[x];
        x = x - (x & (-x));
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int mx = 0;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        cek[ar[i]] = i;
        mx = max(mx, ar[i]);
        if (i > 1){
            if (ar[i] < ar[i - 1]){
                cout << -1 << el;
                return 0;
            }
        }
    }
    for (int i=0;i<mx;i++){
        if (cek[i] == 0){
            avai.insert(i);
        }
    }
    for (int i=1;i<=n;i++){
        avai.insert(MX - i);
    }
    for (int i=1;i<=n;i++){
        auto it = avai.begin();
        int temp = *it;
        avai.erase(temp);
        br[i] = temp;
        if (i == cek[ar[i]]){
            avai.insert(ar[i]);
        }
    }
    bool ok = 1;
    for (int i=1;i<=n;i++){
        update(br[i], 1);
        int temp = ask(ar[i] - 1);
        if (temp != ar[i]){
            ok = 0;
        }
    }
    if (!ok){
        cout << -1 << el;
        return 0;
    }
    for (int i=1;i<=n;i++){
        cout << br[i] << " ";
    }
    cout << el;

    return 0;
}