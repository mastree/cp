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
int total[200005][101];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;

    int ar[n+1];ar[0]=0;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }

    int cek[101];
    for (int i=0;i<=100;i++) cek[i]=0;
    
    for (int i=1;i<=n;i++){
        int cnt=0,j,total=0;
        bool bisa=1;
        
        m-=ar[i];
        for (j=1;j<=100;j++){
            cnt+=cek[j];
            total+=cek[j]*j;
            if (total>m){
                bisa=0;
                break;
            }
            
        }
    
        if (bisa){
            printf("%d ",i-cnt-1);
            m+=ar[i];
            cek[ar[i]]++;
            continue;
        }

        cnt-=cek[j];
        total-=cek[j]*j;

        int low=0,high=cek[j];
    
        while (low<high){
            int mid=(low+high+1)/2;
            if (total+mid*j<=m){
                low=mid;
            } else {
                high=mid-1;
            }
        }
        
        printf("%d ", i-cnt-low-1); 
        m+=ar[i];
        cek[ar[i]]++;
    }


    return 0;
}