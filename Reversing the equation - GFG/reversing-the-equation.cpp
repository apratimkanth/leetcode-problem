//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            int i=s.size();
            string ans="";
            while(i>=0){
                string temp="";
                while(i>=0){
                    if(!isdigit(s[i])){
                        break;
                    }
                    temp+=s[i];
                    i--;
                }
                reverse(temp.begin(),temp.end());
                ans.append(temp);
                if(i>=0 && !isdigit(s[i]))
                    ans+=s[i];
                i--;
            }
            
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends