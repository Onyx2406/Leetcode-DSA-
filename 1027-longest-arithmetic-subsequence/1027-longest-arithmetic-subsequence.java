class Solution {
    public int longestArithSeqLength(int[] A) 
    {
        int n=A.length;
        if(n<=2)
        {
            return n;
        }
        int max=1;
        HashMap<Integer,Integer> dp[]=new HashMap[n];
        for(int i=0;i<n;i++)
        {
            dp[i]=new HashMap<>(); // new Empty hashMap
            int currentElement=A[i];
            HashMap<Integer,Integer> currentMap=dp[i]; // For processing the currentMap.
            for(int j=0;j<i;j++)
            {
                int difference=currentElement-A[j]; // we get our difference with the previous element
              
			  int newValue=dp[j].getOrDefault(difference,0)+1; // we will look for this difference in its table if it exists we will add 1 to previous value and store it in out current map.
                
				currentMap.put(difference,newValue);
               
			   max=Math.max(max,newValue); //storing the count of difference that has the maximum value 
            }
        }
        return max+1;
    }
}