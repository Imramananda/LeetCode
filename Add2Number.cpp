#include<iostream>
using namespace std;
struct listNode{
    int val;
    listNode* next;
    listNode(): val(0), next(NULL){}
    listNode(int x): val(x), next(NULL){}
    listNode(int x, listNode* next): val(x), next(next){}
    ~listNode(){delete next;}
};

listNode* addTwoNumbers(listNode* l1, listNode* l2)
{
    listNode dummy;
    listNode* tail = &dummy;
    int carry = 0;
    while(l1 || l2 || carry)
    {
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;
        int sum = n1 + n2 + carry;
        carry = sum / 10;
        tail->next = new listNode(sum % 10);
        tail = tail->next;
        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }
    return dummy.next;
}

int main()
{
listNode* l1 = new listNode(2);
l1->next = new listNode(4); 
l1->next->next = new listNode(3);
listNode* l2 = new listNode(5);
l2->next = new listNode(6);
l2->next->next = new listNode(4);
while(l1 != NULL)
{
    cout<<l1->val<<" ";
    l1 = l1->next;  
}
cout<<endl;
while(l2 != NULL)
{
    cout<<l2->val<<" ";
    l2 = l2->next;  
}
cout<<endl;

listNode* result = addTwoNumbers(l1, l2);
// while(result->next != NULL)
// {
//     cout<<result->val<<" ";
//     result = result->next;  
// }
// cout<<endl;
return 0;
}