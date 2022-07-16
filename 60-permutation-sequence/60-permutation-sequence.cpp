class Solution {
public:

string getPermutation(int n, int k) {
    int fact =1;
    // declaring vector to store numsbers from range 1 to n
    vector<int>nums; 
    
    for(int i=1;i<n;i++){
        fact =fact*i;  // Calculating n-1 factorial
        nums.push_back(i); // pushing int from 1 to (n-1) in vector nums
    }
    
    nums.push_back(n); // pushing n in nums to include all numbers from range 1 to n
    
    string ans=""; // For Storing ans
    k = k-1;    // Zero based indexing logic
    
    while(true){
        ans = ans + to_string(nums[k/fact]);
        nums.erase(nums.begin()+k/fact);
        if(nums.size()==0){
            break;
        }
        k = k%fact;
        fact = fact/nums.size();
    }
    
    return ans;
}
};