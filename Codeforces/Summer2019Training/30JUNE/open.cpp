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

bool cek[51][51];
bool b[51][7];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m,q;
    
    
    cin >> n >> m >> q;

    int lg=log2(n+n-1);
    int bates=63-n+1;
    
    for (int i=0;i<lg;i++){ //cerr << i << el;
        
        bool iy[64];
        for(int j=0;j<64;j++) iy[j]=0;
        for (int bit=63;bit>=bates;bit-=(1 << (i+1))){
            for (int mn=0;mn<(1 << i);mn++){
                int tm=bit-mn-bates;
                iy[tm]=1;
                if (tm==0){
                    cout << tm;
                    break;
                }
                cout << tm << " ";
            }
        }
    //    for (int j=0;j<n;j++) cerr << iy[j];
    //    cout << el;
        int cnt=0;
        for (int j=0;j<n;j++) cnt+=iy[j];
        cout << "? " << cnt << " "; 
        for (int j=0;j<n;j++) if (iy[j]) cout << j+1 << " ";
        cout << el;cout << flush;

        int len=0;
        cin >> len;
        for (int j=0;j<len;j++){
            int tm;
            cin >> tm;
            b[tm][j]=1;
        }cout << flush;

    }

    for (int i=n+1;i<=n+m;i++){
        int sum=1;
        for (int j=0;j<7;j++){
            if (b[i][j]) sum+=(1 << j);
        }
        sum-=bates;
        if (sum!=1){
            cek[i][sum]=1;
            cek[sum][i]=1;
        }
    }

    cout << "? 1 1" << el;cout << flush;
    int len;cin >> len;
    for (int i=0;i<len;i++){
        int tm;
        cin >> tm;
        cek[tm][1]=1;
        cek[1][tm]=1;
    }cout << flush;

    int ans=-1;
    for (int i=1;i<51;i++){
        int cnt=0;
        for (int j=1;j<51;j++){
            if (cek[i][j]) cnt++;
        }
        if (cnt==0 || cnt>1) ans=i;
    }

    cout << "! " << ans << el;cout << flush;

    return 0;
}