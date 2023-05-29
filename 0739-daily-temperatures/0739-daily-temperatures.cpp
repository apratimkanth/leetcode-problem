class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack< pair<int,int> >s;
        int n=temp.size();
        vector<int>ans;
        for(int i=n-1;i>=0;i--){
            if(s.empty()==true){
                s.push({temp[i],i});
                ans.push_back(0);
            }
            else{
                if(s.top().first>temp[i]){
                    s.push({temp[i],i});
                    ans.push_back(1);
                }
                else{
                    while(s.empty()==false){
                        if(s.top().first>temp[i]) break;
                        s.pop();
                    }
                    if(s.empty()==true){
                        ans.push_back(0);
                    }
                    else{
                        ans.push_back(s.top().second-i);
                    }
                    s.push({temp[i],i});
                }
            }
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};