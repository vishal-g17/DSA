#include<iostream>
#include<map>
using namespace std;
struct Node
{
  int data;
  Node* left;
  Node* right;

  Node(int val) : data(val), left(nullptr), right(nullptr) {}  //constructor for node
};

void flatten(Node* root){
    Node* curr = root;
    while(curr != NULL){
        if(curr->left){
            Node* pred = curr ->left;
            while(pred ->right){
                pred = pred ->right;
                curr->right = curr ->left;
                // curr->left = NULL;
            }
            curr = curr->right;
        }


        //iske baad jo hai agr vo nhi krna to uper comment vali line ko uncomment krdo or isse comment krdo
        //hm isme baad me null kr rhe hai usme saath saath hi kr rhe hai , left part ko null 
        curr = root;
        while(curr != NULL){
            curr ->left = NULL;
            curr= curr->right;
        }
    }
}