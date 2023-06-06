//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> A, int n) {
        // int n=A.size();
        vector<int>ans;
        
        for(int i=0;i<n;i++){
          int index=abs(A[i])-1;
          if(A[index]<0) ans.push_back(abs(A[i]));
          else A[index]=A[index]*-1;
        }
        
        for(int i=0;i<n;i++){
            if(A[i]>0) ans.push_back(i+1);
        }
        
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends