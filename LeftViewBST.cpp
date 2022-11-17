#include<bits/stdc++.h>
#include<conio.h>
#include<queue>
using namespace std;

struct Node 
{
    int data;
    Node *left=NULL;
    Node *right=NULL;

    Node(int data) : data(data){}
};

void leftView(Node *root)
{
    if (root == NULL)
        return;
 
    queue<Node *> q;
    q.push(root);

    Node *ptr = NULL;
    
    while (!q.empty())
    {
        
        int size = q.size();
        int i = 0;
        while (i < size)
        {
            ptr = q.front();
            q.pop();
 
            if (i == 0)
                cout << ptr->data <<" ";
 
            if (ptr->left) 
                q.push(ptr->left);
 
            if (ptr->right) 
                q.push(ptr->right);

            i++;
        }

        cout<<endl;
    }
}

void sample_testcase()
{
    system("cls");
    Node *root = new Node(1);
    root->left = new Node(8);
    root->right = new Node(7);
    root->right->left = new Node(9);
    root->right->right = new Node(10);
    root->right->right->right = new Node(11);
    leftView(root);
    getch();
    system("cls");
}

main()
{
    sample_testcase();
}