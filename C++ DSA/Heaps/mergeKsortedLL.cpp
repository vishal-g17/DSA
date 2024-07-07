// // Following is the class structure of the Node<int> class:

// class Node<int>
// {
// public:
//     int data;
//     Node<int> *next;
//     Node<int>()
//     {
//         this->data = 0;
//         next = NULL;
//     }
//     Node<int>(int data)
//     {
//         this->data = data; 
//         this->next = NULL;
//     }
//     Node<int>(int data, Node<int>* next)
//     {
//         this->data = data;
//         this->next = next;
//     }
// };

// class compare {
//     bool operator() (Node<int>* a, Node<int>* b) {
//         return a->data > b->data;
//     }
// };


Node<int>* mergeKLists(vector<Node<int>*> &listArray){
     priority_queue<Node<int>* , vector<Node<int>*>, compare> minheap;
     int k = listArray.size();

     if(k==0){
         return NULL;
     }
     //step 1


     for(int i=0; i<k; i++){
         minheap.push(listArray[i]);
     }

    Node<int>* head = NULL;
    Node<int>* tail = NULL;

    while(minheap.size()>0){
        Node<int>* top= minheap.top();
        minheap.pop();

        if(top->next != NULL){
            minheap.push(top->next);
        }

        if(head == NULL){
            //answer LL is empty
            head = top;
            tail = top;
        }
        else{
            //insert at ans LL
            tail->next = top;
            tail= top;
        }
    }
        return head;

}





//ptani code compile error dikha rha hai