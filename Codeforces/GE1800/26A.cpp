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

const int N = 3e3 + 7;

int n;
int ans;

bool cek(int a){
    int cnt = 0;
    for (int i=2;i*i<=a;i++){
        if (a%i==0){
            cnt++;
            while (a % i == 0){
                a/=i;
            }
        }
    }
    if (a!=1) cnt++;
    return (cnt==2);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        if (cek(i)){
            ans++;
        }
    }

    cout << ans << el;

    return 0;
}