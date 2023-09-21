//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int first = -1, last = -1, l = 0,h = n - 1;
        
        //for first occurence
        while(l <= h){
            int m = l + (h - l)/2;
            if(arr[m] == x){
                first = m;
                h = m - 1;
            }else if(arr[m] < x){
                l = m + 1;
            }else{
                h = m - 1;
            }
        }
        
        l = 0,h = n - 1;
        //for last Occurence
        while(l <= h){
            int m = l + (h - l)/2;
            if(arr[m] == x){
                last = m;
                l = m + 1;
            }else if(arr[m] < x){
                l = m + 1;
            }else{
                h = m - 1;
            }
        }
        
        return {first, last};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends