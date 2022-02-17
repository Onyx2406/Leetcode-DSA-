class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int idx=0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i+1]<arr[i])
            {
                idx=i;
                break;
            }
        }
        return idx;
    }
};