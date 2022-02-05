class Solution {
public:

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *head=NULL;
    
    stack<int>st1,st2;
    int m=0,n=0;
    while(l1!=NULL)
    {
        st1.push(l1->val);
        l1=l1->next;
        m++;
    }
    while(l2!=NULL)
    {
        st2.push(l2->val);
        l2=l2->next;
        n++;
    }
    int carry=0,ans=0;
    while(!st1.empty() || !st2.empty())
    {
        if(!st1.empty() && !st2.empty())
        {
            ans=carry+st1.top()+st2.top();
            st1.pop();
            st2.pop();
        }
        else if(!st1.empty())
        {
            ans=carry+st1.top();
            st1.pop();
        }
        else if(!st2.empty())
        {
            ans=carry+st2.top();
            st2.pop();
        }
        if(ans>9)
        {
            carry=1;
            ans=ans%10;
        }
        else
        {
            carry=0;
        }
        ListNode *curr=new ListNode(ans);
        curr->next=head;
        head=curr;
        
        
    }
    if(carry==1)
    {
        ListNode *curr=new ListNode(carry);
        curr->next=head;
        head=curr;
    }
    
    return head;
}
};