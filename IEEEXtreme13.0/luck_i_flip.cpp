#include <bits/stdc++.h>

using namespace std;

#define el '\n'

int n,b,m;
int cnt[4500000], id[4500000], ans[101];
bool ada[4500000];
string s[101];
int len;

bitset<22>bs[101];

int main() {
    scanf("%d", &b);
    for (int i=0;i<b;i++){
        cin >> s[i];
        len=s[i].length();
        reverse(s[i].begin(),s[i].end());
        for (int j=0;j<len;j++){
            bs[i][j]=(s[i][j]=='1');
        }
    //    cout << bs[i] << el;
    }
    
    int end = 1 << len;
    for (int i=0;i<end;i++){
        bitset<22> bit(i);
        
        bit=~bit;
    //    cout << bit << el;
        
        for (int j=0;j<b;j++){
            int tm=22-(bit^bs[j]).count();
        //    cout << tm << " ";
            if (tm>cnt[i]){
                cnt[i]=tm;
                ada[i]=1;
                id[i]=j;
            } else if (tm==cnt[i]){
                ada[i]=0;
            }
        }
    }
    
    int mn=100000000;
    for (int i=0;i<end;i++){
        if (ada[i]){
            ans[id[i]]++;
            
        }
    }
    for (int i=0;i<b;i++){
        mn=min(ans[i],mn);
    }
    
    printf("%d\n", mn);
    
    return 0;
}