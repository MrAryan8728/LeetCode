//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        //Let's use moore voting algorithm.
        
        int vote = 0,candid = -1;
        for(int i = 0;i < size;i++){
            if(vote == 0){
                candid = a[i];
                vote = 1;
            }
            else if(a[i] == candid) vote++;
            else vote--;
        }
        int check = 0;
        for(int i = 0;i < size;i++){
            if(a[i] == candid) check++;
        }
        return (check > size/2)?candid:-1;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends