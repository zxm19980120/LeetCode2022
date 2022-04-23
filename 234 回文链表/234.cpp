/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome2(ListNode* head){
        //如果是数组 回文首先要判断 长度为奇数还是偶数
        //但这题是链表无法判断
        //暴力法 先新建一个反转链表 再使用双指针按顺序比较 
        //哭了 反转链表只能原地反转，反转之后head的值就会改变 无法进行比较
        //时间O(2n) 空间O(n)

        //先进行边界考虑
        if(head==NULL){
            return false;
        }
        if(head->next==NULL){
            return true;
        }
        ListNode* pa = nullptr;
        ListNode* pb = head;
        //注意 反转链表的边界怎么处理
        while(pb!=NULL){
                ListNode *pNext=pb->next;
                pb->next=pa;
                pa=pb;
                pb=pNext;
 
        }
        ListNode *pA=head;
        ListNode *pB=pa;
        while(pA!=NULL){
            cout<<pa->val;
            pA=pA->next;
        }
        cout<<endl;
        while(pB!=NULL){
            cout<<pB->val;
            pB=pB->next;
        }
        while(pA!=NULL && pB!=NULL){
            if(pA->val==pB->val){
                cout<<pA->val<<endl;
                pA=pA->next;
                pB=pB->next;
            }
            else{
                return false;
            }
        }
        return true;

    }
    bool isPalindrome3(ListNode* head) {
        //如果是数组 回文首先要判断 长度为奇数还是偶数
        //但这题是链表无法判断
        //暴力法 先新建一个数组 将值存放在数组里面 再使用双指针按顺序比较
        //时间O(2n) 空间O(n)
        if(head==NULL){
            return false;
        }
        if(head->next==NULL){
            return true;
        }
        ListNode *pB=head;
        vector<int> A;
        while(pB!=NULL){
            A.push_back(pB->val);
            pB=pB->next;
        }
        int pA=A.size()-1;
        for(int i=0;i<A.size();i++){
            cout<<A[i]<<endl;
        }
        pB=head;
        while(pA>=0 && pB!=NULL){
            if(A[pA]==pB->val){
                pA--;
                pB=pB->next;
            }
            else{
                return false;
            }
        }
        return true;
    }

    //反转链表
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        //快慢指针+反转链表
        //利用快慢指针找到链表中间位置
        //边界
        if(head==NULL){
            return false;
        }
        if(head->next==NULL){
            return true;
        }
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            //走到最后一个有效位置

            slow=slow->next;
            fast=fast->next->next;

        } 
        //最后slow位置即为链表中间位置
        //但是 如果直接这样还要考虑奇数偶数问题
        ListNode* p1 = head;
        ListNode* p2 = reverseList(slow->next);
        bool result = true;
        while (result && p2 != nullptr) {
            if (p1->val != p2->val) {
                result = false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return result;
    }
};
