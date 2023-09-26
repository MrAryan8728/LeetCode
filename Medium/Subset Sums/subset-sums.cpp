//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        int calcu_value = 0;
        vector<int> ans;
        solve(ans,arr,calcu_value,N);
        return ans;
    }
    void solve(vector<int> &ans,vector<int> arr,int val,int N){
        if(N == 0){
            ans.push_back(val);
            return;
        }
        int val1 = val + arr[N-1];
        int val2 = val;
        solve(ans,arr,val1,N-1);
        solve(ans,arr,val2,N-1);
        return;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends