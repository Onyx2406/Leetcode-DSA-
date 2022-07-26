class Solution {
  public:
    int minEatingSpeed(vector<int>& piles, int h){
      //r is the maximum of the input pile vector
      int r=*max_element(piles.begin(), piles.end());
      int l=1;

      while(l<r){
        int mid=(r-l)/2+l;
        int temp=h;
          
        //check if she can finish eating in h hours
        //if not --> temp < 0
        //if yes --> temp > 0
        for(int bananas:piles){
          temp = temp-(bananas/mid + bool(bananas % mid));
          //no need to calculate the remaining elements
          if(temp<0)
            break;
        }
          
        //temp<0 --> the current speed is too slow --> choose a faster speed
        if(temp<0)
          l=mid+1;
          
        //temp>0 --> the current speed is fast enough --> check if she can eat at a slower speed
        else
          r=mid;
      }
      return l;
    }
};