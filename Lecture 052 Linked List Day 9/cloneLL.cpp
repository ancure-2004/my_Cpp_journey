#include <iostream>
using namespace std;

class Solution
{
private:
    void insertAttail(Node *&head, Node *&tail, int data)
    {

        Node *newNode = new Node(data);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

public:
    Node *copyList(Node *head)
    {

        // step1: create a clone list

        Node *clonehead = NULL;
        Node *clonetail = NULL;

        Node *temp = head;
        while (temp != NULL)
        {
            insertAttail(clonehead, clonetail, temp->data);
            temp = temp->next;
        }

        // step2: cloneNodes add in between Original List
        Node *originalNode = head;
        Node *cloneNode = clonehead;

        while (originalNode != NULL && cloneNode != NULL)
        {

            Node *next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = next;

            next = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next;
        }

        // step3: random pointer copy

        temp = head;

        while (temp != NULL)
        {
            if (temp->next != NULL)
            {

                temp->next->random = temp->random
                                         ? temp->random->next
                                         : temp->random;
            }

            temp = temp->next->next;
        }

        // step4: revert changes in step 2

        originalNode = head;
        cloneNode = clonehead;

        while (originalNode != NULL && cloneNode != NULL)
        {
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;

            if (originalNode != NULL)
            {
                cloneNode->next = originalNode->next;
            }

            cloneNode = cloneNode->next;
        }

        // step5: return ans
        return clonehead;
    }
};

int main()
{

    return 0;
}