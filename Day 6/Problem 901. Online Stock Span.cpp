class StockSpanner {
    public:
        stack<pair<int, int>> st; //Store increasing pairs from the top of the stack. Which are <price, spanOfStock>
    
        StockSpanner() {
            
        }
        
        int next(int price) {
            int span = 1;
            while (!st.empty() && price >= st.top().first) {
                pair<int, int> stock = st.top(); st.pop();
                span += stock.second;
            }
    
            st.push({price, span});
            return span;
        }
    };
    
    /**
     * Your StockSpanner object will be instantiated and called as such:
     * StockSpanner* obj = new StockSpanner();
     * int param_1 = obj->next(price);
     */