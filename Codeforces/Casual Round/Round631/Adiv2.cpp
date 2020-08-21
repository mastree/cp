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

const int N = 1000;

int q;
int n, x;

bool ada[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> x;
        fill(ada, ada + 300, 0);
        for (int i=1;i<=n;i++){
            int a;
            cin >> a;
            ada[a] = 1;
        }

        int cnt = 0;
        int last = 0;
        for (int i=1;i<300;i++){
            if (!ada[i] && cnt < x){
                cnt++;
                ada[i] = 1;
            } else if (!ada[i]){
                last = i - 1;
                break;
            }
        }

        cout << last << el;
    }

    return 0;
}