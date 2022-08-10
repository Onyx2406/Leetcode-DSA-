class MedianFinder {
public:
    
    //make 2 priority queues
    priority_queue<double> left;
    priority_queue<double,vector<double>,greater<double>> right;
        
    MedianFinder() {
        
    }
    
    
    void addNum(int num) {
        //initially add the first number in left PQ
        if(left.size()==0 && right.size()==0)
        {
            left.push(num);
        }else if(num < left.top())  //from next time, if num is less than the top of "left" PQ, then add the num in "left PQ" else add it in "right PQ"
        {
            left.push(num);
        }
        else{
            right.push(num);
        }
        
        //if at any point of time the size difference becomes 2, then we need to shift elements from one PQ to another PQ
        if(left.size() - right.size() == 2)
        {
            right.push(left.top());
            left.pop();
        }else if(-left.size() + right.size() == 2)
        {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() 
    {
        if((left.size() + right.size())%2==0)   
        {
            return (left.top() + right.top())/2;   
        }else
        {
            if(left.size() > right.size())  return left.top();
            else return right.top();
        }
    }
};