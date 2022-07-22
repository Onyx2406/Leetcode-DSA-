// Approach
// We will use a hash array to update the number of passengers in each trip.
// At any point if the number of passengers exceeds the capacity, we will return false.
// Instead of updating the entire range from starting point to ending point of trip, we will keep a sum variable that will keep track of the number of passengers at every stop.
// Suppose 2 passengers get up at point 1, and get down at point 5. Our sum variable will store 2 from point 1 upto point 5 and then it will be reset to 0. To achieve this, in our array, we will be adding the number of passengers in the start point, and subtract the number of passengers at the end point.
// In this way using our sum variable we will be able to keep track of total no of passengers at any point.

// C++ Solution
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int mp[1001] = {};
        for(int i = 0; i < trips.size(); i ++){
            mp[trips[i][1]] += trips[i][0];
            mp[trips[i][2]] -= trips[i][0];
        }
        int sum = 0;
        for(auto it : mp){
            sum += it;
            if(sum > capacity)return false;
        }
        return true;
    }
};
