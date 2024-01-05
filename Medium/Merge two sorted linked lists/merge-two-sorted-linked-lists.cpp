//{ Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
#include<bits/stdc++.h>
Node* sortedMerge(Node* head1, Node* head2)  
{  
   vector<int>v1;
    vector<int>v2;
    Node*temp1 = head1;
    Node*temp2 = head2;
    while(temp1){
        v1.push_back(temp1->data);
        temp1 = temp1->next;
    }
    while(temp2){
        v2.push_back(temp2->data);
        temp2 = temp2->next;
    }
    vector<int>v;
    for(auto val : v1) v.push_back(val);
    for(auto val : v2) v.push_back(val);
    sort(v.begin(), v.end());
    Node*head = new Node(v[0]);
    Node*temp = head;
    int i = 1;
    while(temp && i<v.size()){
        temp->next = new Node(v[i++]);
        temp = temp->next;
    }
    return head;
}  