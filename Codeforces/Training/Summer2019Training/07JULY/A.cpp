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

int rolshift(int a,int n,int dig){
    int res=0;
    for (int i=0;i<n;i++){
        if ((a&(1 << i))>0) res+=(1 << i);
    }

    res=(res << (dig-n));
    res+=(a >> n);
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

 //   int now=0;
    int digit=4;
    for (int i=0;i<(1 << digit);i++){
        int xx=(1 << (digit-1));
        for (xx;xx>0;xx/=2){
            if ((i&xx)>0) cout << 1;
            else cout << 0;
        }cout << " ";
        int cnt=0;
        for (int j=0;j<digit;j++){
            bool udh=0;
            for (int an=0;an<=i;an++){
                if ((rolshift(an,j,digit)^an)==i){
                    udh=1;
                    break;
                }
            }
            if (udh) cnt++;
        }

        cout << cnt << el;
    }

    return 0;
}