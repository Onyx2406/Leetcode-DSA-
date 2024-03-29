class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return 0;
        }
        vector<int> nums;
        ListNode* node=head;
        while(node){
            nums.push_back(node->val);
            node=node->next;
        }
        k=k%nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        node=head;
        int i=0;
        while(node){
            node->val=nums[i++];
            node=node->next;
        }
        return head;
    }
};