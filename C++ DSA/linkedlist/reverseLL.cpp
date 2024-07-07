#include <bits/stdc++.h>

Node* reversell(Node* head){
//     if(head== NULL || head ->next == NULL){
//         return head;
//     }
//     Node* curr = head;
//     Node* prev = NULL;
//     Node* forward = NULL;
//     while(curr != NULL){
//         forward = curr->next;
//         curr-> next = prev;
//         prev = curr;
//         curr= forward;
//     }
//     return prev;

//code 2 
    // Node* curr = head;
    // Node* prev = NULL;
    // reverse(head, curr, prev);
    // return head;
}

//it willl give head of reverse list
//code 3 easiest simple
void reverse1(Node* head){
    if(head== NULL || head->next ==NULL){
        return head;
    }
    Node* chotahead = reverse1(head->next);
    head->next ->next = head;
    head ->next = NULL;
    return chotahead;
}

// void reverse(Node* &head, Node* curr, Node* prev ){
//     if (curr == NULL) {
//       // base case
//       head = prev;
//       return;
//     }
//     Node* forward = curr->next;
//     reverse(head,forward,curr);
//     curr->next = prev;
// }

Node *reverseLinkedList(Node *head) 
{
    // reversell(head);
    reverse1(head);

}



