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
int ar[N], tar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=n;i++){
        cin >> tar[i];
    }
    if (ar[1] != tar[1] || ar[n] != tar[n]){
        cout << "No" << el;
        return 0;
    }
    map<int, int> cnt;
    for (int i=1;i<n;i++){
        cnt[ar[i + 1] - ar[i]]++;
        cnt[tar[i + 1] - tar[i]]--;
    }
    for (auto x : cnt){
        if (x.se){
            cout << "No" << el;
            return 0;
        }
    }
    cout << "Yes" << el;

    return 0;
}