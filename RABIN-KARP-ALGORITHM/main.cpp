#include<bits/stdc++.h>
#define ll long long int
#define prime 7
using namespace std;

ll createHashValue(string str, int n){
    ll result =0;
    for(int i=0;i<n;i++){
        result+= (ll)(str[i]*(ll)pow(prime,i));
    }
    return result;
}

ll recalculateHash(string str, int oldIndex, int newIndex, ll oldHash, int patLength){
    ll newHash=oldHash-str[oldIndex];
    newHash/=prime;
    newHash+=(ll)(str[newIndex]*(ll)(pow(prime,patLength-1)));
    return newHash;
}

bool equalHash(string str1, string str2, int start1, int end1, int start2, int end2){
    if(end1-start1!=end2-start2){
        return false;
    }
    while(start1<=end1 && start2<=end2){
        if(str1[start1]!=str2[start2]){
            return false;
        }
        start1++;
        start2++;
    }
    return true;
}

int main()
{
    string s="ababcabdabdcabd";
    string pattern="abd";
    int size=pattern.size();
    ll patHash=createHashValue(pattern, size);
    ll startHash= createHashValue(s,size);
    vector<int>ans;
    for(int i=0;i<=s.size()-size;i++){
        if(patHash==startHash && equalHash(s,pattern, i, i+size-1, 0, size-1)){
            ans.push_back(i);
        }
        else{
            startHash=recalculateHash(s, i, i+size, startHash,size);
        }
    }

    cout<<"answer"<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" --- ";
    }

}