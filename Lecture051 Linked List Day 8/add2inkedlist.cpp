#include <iostream>
using namespace std;

class Solution {
  private:
    Node *reverse(Node *head){
        
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL){
            
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    void insertAttail(Node* &Head, Node* &Tail, int val){
        
        Node* temp = new Node(val);
        
        if(Head == NULL){
            Head = temp;
            Tail = temp;
            return;
        }
        
        else{
            Tail -> next = temp;
            Tail = temp;
        }
    }
    
    Node *add(Node *num1, Node *num2){
        
        int carry = 0;
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        while(num1 != NULL || num2 != NULL || carry != 0){
            
            int val1 = 0;
            if(num1 != NULL){
                val1 = num1 -> data;
            }
            
            int val2 = 0;
            if(num2 != NULL){
                val2 = num2 -> data;
            }
            
            int sum = carry + val1 + val2;
            int digit = sum%10;
            
            //Create node and add in answer linked list
            insertAttail(ansHead, ansTail, digit);
            
            carry = sum/10;
            
            if(num1 != NULL){
                num1 = num1 -> next;
            }
            
            if(num2 != NULL){
                num2 = num2 -> next;
            }
        }
        
        return ansHead;
    }
    
  public:
    // Function to add two numbers represented by linked list.
    Node* addTwoLists(Node* num1, Node* num2) {
        
        num1 = reverse(num1);
        num2 = reverse(num2);
        
        Node* ans = add(num1, num2);
        
        ans = reverse(ans);
        
        return ans;
    }
};

int main()
{

    return 0;
}