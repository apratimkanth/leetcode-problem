class StockSpanner {
public:
    vector<pair<int,int>>s;
    StockSpanner() {
        s.clear();
    }
    
    int next(int price) {
        if(s.empty()==true){
            s.push_back({price,1});
            return 1;
        }
        else{
            if(s.back().first>price) s.push_back({price,1});
            else{
                int ans=1;
                while(s.empty()==false){
                    if(s.back().first>price) break;
                    ans+=s.back().second;
                    s.pop_back();
                }
                s.push_back({price,ans});
            }
            
            return s.back().second;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */