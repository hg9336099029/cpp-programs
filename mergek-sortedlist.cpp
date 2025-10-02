class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        int  n=lists.size();
        for(int i=0;  i<n; i++){
           if(lists[i]!=NULL) pq.push({lists[i]->val,lists[i]});
        }

        ListNode* dummyNode=new ListNode(-1);
        ListNode* temp=dummyNode;
        while(!pq.empty()){
            ListNode* node=pq.top().second;
            pq.pop();
            temp->next=node;
            temp=temp->next;
            if(node->next!=NULL) pq.push({node->next->val,node->next});
        }
        return  dummyNode->next;
    }
};
