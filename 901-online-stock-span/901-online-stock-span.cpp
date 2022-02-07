class StockSpanner {
public:
    stack<pair<int,int>> s;
	//pair.first denotes the price 
	//pair.second denotes the number of stocks less than equal to the current price
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count=1; //since current stock is also counted
		
		//get the previous stocks which are less than or equal to the  current price 
        while(!s.empty() && s.top().first<=price )
        {
            count+=s.top().second;
            s.pop();
        }
        s.push({price,count});
        return count;
    }
};