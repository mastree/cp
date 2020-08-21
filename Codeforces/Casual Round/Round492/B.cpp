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

const int N = 300;

int n;
int ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    n = n + n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    int ans = 0;
    for (int i=1;i<=n;i += 2){
        if (ar[i] != ar[i + 1]){
            int per = i + 1;
            while (ar[per] != ar[i]) per++;

            while (per != i + 1){
                ans++;
                swap(ar[per], ar[per - 1]);
                per--;
            }
        }
    }
    cout << ans << el;

    return 0;
}