class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        map<int,int> m;

        if(n % groupSize != 0) return false;

        for(int i=0; i<n; i++)
            m[hand[i]]++;

        for(int i=0; i<n; i++)            
            if(m[hand[i]] > (n/groupSize)) return false;

       for(auto i: m){

           if(i.second < 0) return false;

           if(i.second == 0) continue;

           int count = i.second;

           for(int j=i.first; j< i.first + groupSize; j++)
               m[j] -= count;

       }

    return true;
    }
};