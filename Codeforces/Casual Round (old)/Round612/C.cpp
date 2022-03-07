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
     
    const int N = 107;
     
    int n;
    int ar[N];
    int c[2];
    vector <int> sama[2], beda, ujung[2];
     
    int main () {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
     
        cin >> n;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
            if (ar[i]==0){
                ar[i] = -1;
            } else{
                ar[i]%=2;
                c[ar[i]]++;
            }
        }
        if (n==1){
            cout << 0 << el;
            return 0;
        }
        c[0] = n/2 - c[0];
        c[1] = (n+1)/2 - c[1]; 
     
        int mul, last;
        int bef = -1, gap = 0;
        for (mul=1;mul<=n;mul++){
            if (ar[mul]!=-1){
                bef = ar[mul];
                break;
            }
        }
        if (mul>n){
            cout << 1 << el;
            return 0;
        }
     
        last = mul;
        if (mul!=1){
            ujung[ar[mul]].pb(mul-1);
        }
        for (int i=mul+1;i<=n;i++){
            if (ar[i]==-1){
                gap++;
            } else{
                if (ar[i] == bef){
                    sama[ar[i]].pb(gap);
                } else{
                    beda.pb(gap);
                }
     
                gap=0;
                bef=ar[i];
                last = i;
            }
        }
     
        if (last!=n){
            ujung[ar[last]].pb(n-last);
        }
     
        sort(sama[0].begin(), sama[0].end());
        sort(sama[1].begin(), sama[1].end());
        sort(ujung[0].begin(), ujung[0].end());
        sort(ujung[1].begin(), ujung[1].end());
     
        // for (auto x : sama[0]) cout << x << " ";cout << el;
        // for (auto x : sama[1]) cout << x << " ";cout << el;
        // for (auto x : ujung[0]) cout << x << " ";cout << el;
        // for (auto x : ujung[1]) cout << x << " ";cout << el;
     
        int sisa = 0;
        for (auto x : sama[0]){
            if (c[0]>=x){
                c[0]-=x;
            } else{
                sisa+=2;
            }
        }
     
        for (auto x : sama[1]){
            if (c[1]>=x){
                c[1]-=x;
            } else{
                sisa+=2;
            }
        }
     
        for (auto x : ujung[0]){
            if (c[0]>=x){
                c[0]-=x;
            } else{
                sisa+=1;
            }
        }
     
        for (auto x : ujung[1]){
            if (c[1]>=x){
                c[1]-=x;
            } else{
                sisa+=1;
            }
        }
     
        sisa += beda.size();
        cout << sisa << el;
     
        return 0;
    }