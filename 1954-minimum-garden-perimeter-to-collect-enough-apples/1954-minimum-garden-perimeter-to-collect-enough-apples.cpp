// class Solution {
// public:
//     long long minimumPerimeter(long long neededApples) {
        
//         if(neededApples <= 12)
//         {
//             return 8;
//         }
//         long long aa = 0;
//         aa = neededApples/12;
//         double n = neededApples/12;
//         if(n > aa)
//         {
//             aa++;
//         }
            
//         long long ans = aa*8;
//         return ans;
        
//     }
// };
long long solve(long long x)
{
    long long currApples = 0, prevApples = 0;
    for(long long i=1;i<=1e5;i++)
    {
        currApples = (12 * i * i);
        
        currApples += prevApples;
        
        if(currApples >= x) return 4 * (2* i); 
        
        prevApples = currApples;
    }
    
    return -1;
}
class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        return solve(neededApples);
    }
};