class Solution {
public:

vector<long long> maximumEvenSplit(long long finalSum) {
   vector<long long> v;
    long long int temp;
    if(finalSum%2==1)
        return v;
    for(int i=1;i<=finalSum/2;++i){
        temp+=2*i;
        if(temp==finalSum)
        {v.push_back(2*i);
        return v;}
        else if(temp>finalSum)
        {v.pop_back(); 
        v.push_back(2*(i-1)+(finalSum+2*i-temp));
         return v;}
        v.push_back(2*i);
    }return v;
}
};