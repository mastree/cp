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

int n;
vector <string> v;
int la=(int)('a');

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    n*=3;
    int sisa=n%9;
    n-=sisa;
    string s,t;
    cin >> s >> t;
    
    if (n){
        for (int a=0;a<3;a++){
            for (int b=0;b<3;b++){
                for (int c=0;c<3;c++){
                    for (int d=0;d<3;d++){
                        for (int e=0;e<3;e++){
                            for (int f=0;f<3;f++){
                                for (int g=0;g<3;g++){
                                    for (int h=0;h<3;h++){
                                        for (int i=0;i<3;i++){
                                            string tm="";
                                            char ch=a+la;
                                            tm.pb(ch);
                                            ch=b+la;
                                            tm.pb(ch);
                                            ch=c+la;
                                            tm.pb(ch);
                                            ch=d+la;
                                            tm.pb(ch);
                                            ch=e+la;
                                            tm.pb(ch);
                                            ch=f+la;
                                            tm.pb(ch);
                                            ch=g+la;
                                            tm.pb(ch);
                                            ch=h+la;
                                            tm.pb(ch);
                                            ch=i+la;
                                            tm.pb(ch);

                                            int ar[3]={0,0,0};
                                            for (int id=0;id<min(9,n);id++){
                                                ar[tm[id]-'a']++;
                                            }

                                            if (ar[0]!=ar[1] || ar[1]!=ar[2]) continue;

                                            bool cek=1;

                                            if (n<9){
                                                for (int id=0;id<n-1;id++){
                                                    string cmp="";
                                                    cmp.pb(tm[id]);
                                                    cmp.pb(tm[id+1]);
                                                    if (cmp!=s && cmp!=t) continue;
                                                    cek=0;break;
                                                }

                                                if (cek){
                                                    cout << "YES" << el;
                                                    for (int id=0;id<n;id++){
                                                        cout << tm[id];
                                                    }cout << el;
                                                    return 0;
                                                }

                                                continue;
                                            }

                                            for (int id=0;id<8;id++){
                                                string cmp="";
                                                cmp.pb(tm[id]);
                                                cmp.pb(tm[id+1]);
                                                if (cmp!=s && cmp!=t) continue;
                                                cek=0;break;
                                            }

                                            if (cek) v.pb(tm);
                                        }
                                    }
                                }   
                            }
                        }
                    }
                }    
            }    
        }
    }

    if (v.empty() && (n)){
        cout << "NO" << el;
        return 0;
    }

    int id1,id2,len=v.size();
    bool nemu=0;
    for (id1=0;id1<len;id1++){
        for (id2=0;id2<len;id2++){
            string cm1="",cm2="";
            cm1.pb(v[id1][8]);
            cm1.pb(v[id2][0]);
            
            cm2.pb(v[id2][8]);
            cm2.pb(v[id1][0]);
            if (cm1!=s && cm1!=t){
                if (n<=18){
                    nemu=1;break;
                }
                if (cm2!=s && cm2!=t){
                    nemu=1;break;
                }
            }
        }
        if (nemu) break;
    }

    if (!nemu && (n)){
        cout << "NO" << el;
        return 0;
    }

    string ss="";
    bool bisa=0;
    if (sisa){
        for (int a=0;a<3;a++){
            for (int b=0;b<3;b++){
                for (int c=0;c<3;c++){
                    for (int d=0;d<3;d++){
                        for (int e=0;e<3;e++){
                            for (int f=0;f<3;f++){
                                for (int g=0;g<3;g++){
                                    for (int h=0;h<3;h++){
                                        for (int i=0;i<3;i++){
                                            string tm="";
                                            char ch=a+la;
                                            tm.pb(ch);
                                            ch=b+la;
                                            tm.pb(ch);
                                            ch=c+la;
                                            tm.pb(ch);
                                            ch=d+la;
                                            tm.pb(ch);
                                            ch=e+la;
                                            tm.pb(ch);
                                            ch=f+la;
                                            tm.pb(ch);
                                            ch=g+la;
                                            tm.pb(ch);
                                            ch=h+la;
                                            tm.pb(ch);
                                            ch=i+la;
                                            tm.pb(ch);

                                            int ar[3]={0,0,0};
                                            for (int id=0;id<min(9,sisa);id++){
                                                ar[tm[id]-'a']++;
                                            }

                                            if (ar[0]!=ar[1] || ar[1]!=ar[2]) continue;

                                            bool cek=1;

                                            for (int id=0;id<sisa-1;id++){
                                                string cmp="";
                                                cmp.pb(tm[id]);
                                                cmp.pb(tm[id+1]);
                                                if (cmp!=s && cmp!=t) continue;
                                                cek=0;break;
                                            }

                                            if (cek){
                                                ss=tm;
                                                bisa=1;
                                            }
                                        }
                                    }
                                }   
                            }
                        }
                    }
                }    
            }    
        }
    }
    

    if (!(bisa || sisa==0)){
        cout << "NO" << el;
        return 0;
    }

    cout << "YES" << el;
    string hasil=""; 
    if (nemu) hasil=v[id1]+v[id2];
    for (int i=0;i<n/18;i++){
        cout << hasil;
    }
//cerr << 11 << el;
    for (int i=0;i<n%18;i++){
        cout << hasil[i];
    }
    cout << ss;

    cout << el;

    return 0;
}