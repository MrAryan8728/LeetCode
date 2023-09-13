//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int n, int s){
        // code here
        if(s == 0 and n > 1) return "-1";
        if(s > 9 and n == 1) return "-1";
        
        string ans = "";
        
        for(int i = 0;i < n;i++){
            if(s >= 9){
                ans += '9';
                s  -= 9;
            }else{
                ans +=  s + '0';
                s = 0;
            }
        }
        
        if(s != 0) return "-1";
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends