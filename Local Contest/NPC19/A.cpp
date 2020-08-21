#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

const int N = 1000007;

int n;
int ans;
int bit[31];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<n;i++){
        int tm;
        cin >> tm;
        for (int j=0;j<31;j++){
            if ((tm&(1 << j))){
                bit[j]++;
            }
        }
    }

    for (int i=0;i<31;i++){
        if (bit[i]>0 && bit[i]<n){
            ans+=(1 << i);
        }
    }

    cout << ans << el;

    return 0;
}