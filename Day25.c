/*Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)

Output:
- Print the number of times the key appears in the linked list

Example:
Input:
6
10 20 30 20 40 20
20

Output:
3

Explanation:
Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter.
After traversal, print the final count
*/

#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* createNode(int value){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode -> data = value;
    newnode -> next = NULL;
    return newnode;
}
void traverselist(struct Node* head){
    struct Node* temp = head;
    while(temp!=NULL)
    {
        printf("%d ",temp ->data);
        temp=temp->next;
    }
    printf("NULL \n");
}
int countOCCurance(struct Node* head,int key)
{int count=0;
    struct Node* temp = head;
    while(temp!=NULL){
        if(temp->data == key){
        count++;
        }
        temp = temp -> next;
    }
    return count;
}
int main()
{
    struct Node* head = NULL , *tail= NULL;
    int n, value ,key;
    printf("Enter nummber of nodes: \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        struct Node* newNode= createNode(value);
        if(head==NULL){
        head = newNode;
        tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
    }printf("Enter a key: \n");
    scanf("%d",&key);
printf("OUTPUT \n");
   printf("%d " ,countOCCurance(head,key));
    return 0;
}