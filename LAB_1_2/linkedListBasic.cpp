#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Node{
    public:
        int val;
        Node* next;
    Node(int val){
        this->val = val;
        this->next = nullptr;
    }

    Node(int val,Node * next){
        this->val = val;
        this->next = next;
    }
};

//1//
void append(Node* &head, int ele){
    Node* addedEle = new Node(ele);
    if(head==nullptr){
        head = addedEle;
        return;
    }
    Node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = addedEle;
}

//2//
void prepend(Node* &head,int ele){
    Node* addedEle = new Node(ele);
    addedEle->next = head;
    head = addedEle;
}

//3//
void reverse(Node* &head){
    if(head==nullptr){
        cout<<"It's an empty list.";
        return;
    }

    Node* curr = head;
    Node* prev = nullptr;
    while(curr->next!=nullptr){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    curr->next = prev;
    head = curr;
}

//4//
void dltDupes(Node* &head,int ele){
    while(head!=nullptr && head->val==ele){
        head = head->next;
    }
    Node* prev = head;
    Node* curr = prev->next;

    while(curr!=nullptr){
        if(curr->val==ele){
            prev->next = curr->next;
            curr = prev->next;
        }
        else{
            prev = prev->next;
            curr = curr->next;
        }
    }
}

//5//
void interleave(Node* &headA, Node* &headB){
    Node* aptr = headA;
    Node* bptr = headB;

    while(aptr!=nullptr && bptr!=nullptr){
        Node* nexta = aptr->next;
        Node* nextb = bptr->next;
        aptr->next = bptr;
        bptr->next = nexta;
        aptr = nexta;
        bptr = nextb;
    }
}

//6//
int kthToLast(Node* &head,int k){
    int sz = 0;
    Node* temp = head;
    while(temp!=nullptr){
        temp = temp->next;
        sz++;
    }
    int idx = sz-k;
    cerr<<sz;
    temp = head;
    while(idx>0){
        temp = temp->next;
        idx--;
    }
    return (temp->val);
}

void printList(Node* head){
    if(head==nullptr){
        cout<<endl;
        return;
    }
    cout<<(head->val)<<" ";
    printList(head->next);
}

int main(){

    Node* head=nullptr;

    //1//appending a number examples
    
    append(head,55);
    append(head,23);
    append(head,55);
    append(head,12);
    append(head,55);

    //2//prepending a number examples
    prepend(head,69);
    prepend(head,420);
    prepend(head,55);
    
    printList(head); //outputs 55 420 69 55 23 55 12 55

    //3//reversing linked list example
    //time complexity is O(n) since we do a single traversal of the linked list
    //space complexity is O(1) or constant as all we store are the current and previous Node pointers
    
    printList(head);  //outputs 55 420 69 55 23 55 12 55
    reverse(head);
    printList(head);  //outputs 55 12 55 23 55 69 420 55


    //4//deleting duplicates from linked list
    //time complexity O(n) since it traverses linked list once
    //space complexity constatn since we only use current and previous Node pointers
    dltDupes(head,55);
    printList(head); //outputs 12 23 69 420

    //5//interleaving example
    //headA is interleaved with headB, and the new interleaved linked list can be accessed using headA
    Node* headA = nullptr;
    Node* headB = nullptr;

    append(headA,1);
    append(headA,2);
    append(headA,3);

    append(headB,-1);
    append(headB,-2);
    append(headB,-3);

    interleave(headA,headB);

    printList(headA); //outputs 1 -1 2 -2 3 -3 
    

    //6//kth element to last example
    //takes O(n) time as the list is traversed once to determine it's size, then using this size, the index
    //from the beginning is calculated. Hence, another traversal is performed to go to that index
    //We can also use an idea of having two pointers such that the pointer with smaller index always differs
    //the other one by k indices. This would require a single traversal
    //Space complexity is O(1) 
    cout<<kthToLast(head,3)<<endl; //outputs 23

    return 0;
}