#include <bits/stdc++.h>
#include<string>
using namespace std;

class unordered_Map{
    static const int sz = 1e4;
    pair<string,int> s[sz];
    int v[sz]={0};
public:
    int hash_m(string s){
        int n=s.size();
        long long sum=0,mul=1;
        for(int i=0;i<n;i++){
            sum += int(s[i]-'a')*mul;
            mul*=26;
        }
        return sum%sz;
    }
    // d -> -1 , v -> 1 , nv -> 0

    void Insert(string key,int x){
        int h = hash_m(key);
        while(v[h]==1){
            if(s[h].first == key) return;
            h= (h+1)%sz;
        }
        s[h]={key,x};
        v[h]=1;
    }
    void Erase(string key){
        int h = hash_m(key);
        while(v[h]!=0){
             if(s[h].first == key) break;
            h= (h+1)%sz;
        }
        if(s[h].first == key)
        {
        s[h]={"",0};
        v[h]=-1;
        }

    }
    int At(string key){
        int h = hash_m(key);
        while(v[h]!=0){
            if(s[h].first == key) break;
            h= (h+1)%sz;
        }
        if(s[h].first == key)
        {
        return s[h].second;
        }
    }

    int Count(string key){
        int cnt=0;
        int h = hash_m(key);
        while(v[h]!=0){
            if(s[h].first == key) cnt++;
            h= (h+1)%sz;
        }
        return cnt;
    }
    int &operator[] (string key){
        int h = hash_m(key);
        while(v[h]!=0){
            if(s[h].first == key) break;
            h= (h+1)%sz;
        }
        if(s[h].first == key)
        {
        return s[h].second;
        }
    }
};

int main(){
    unordered_Map u_m ;
    u_m.Insert("abc",10);
    u_m.Insert("abcdd",1000);
    u_m.Insert("aan",1234);
    u_m.Insert("menna",1203);
    u_m.Erase("aan");
    cout << u_m["abc"] << '\n';
    u_m["abc"] = 11111;
    cout << u_m["abc"] << '\n';
    cout << u_m.Count("abcdd") << '\n';
    cout << u_m.At("menna") << '\n';
    cout << u_m.At("abc") << '\n';
    cout << u_m.Count("aan") << '\n';
}