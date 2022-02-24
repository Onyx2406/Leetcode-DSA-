// class Solution {
// public:
//     bool checkIfExist(vector<int>& arr) {
        
//         int n = arr.size();
        
//         sort(arr.begin(),arr.end());
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(arr[i] == 0 && arr[j] == 0)
//                 {
//                     return true;
//                 }
//                 else if(arr[i] < 0 && arr[j] < 0 || arr[i] > 0 && arr[j] > 0){
//                 if(arr[i]*2 == arr[j] || arr[j]*2 == arr[i])
//                 {
//                     return true;
//                 }
//                 }
//             }
//         }
//         return false;
        
//     }
// };
class Solution {
public:
    int bs(vector<int>& arr, int val){
        int l=0,r=arr.size()-1, m;
        while(l<=r){
            m=l+(r-l)/2;
            if(arr[m]==(val*2))return m;
            if(arr[m]>(val*2))r=m-1;
            else l=m+1;
        }
        return -1;
    }
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            int srch=bs(arr,arr[i]);
            if(srch!=-1 && srch!=i)
                return true;
        }
        return false;
    }
    
};