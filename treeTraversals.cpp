/*
    Program : Tree Traversals : Inorder, Preorder, Postorder
*/
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    
};
//Create tree and return the root node
class TreeBuild{
    public:
    Node* buildTree()
    {
        //Enter Data for Node
        int data;
        cout << "\nValue : ";
        cin >> data;

        //Base Condition : If we enter -1 means no further child and we return without creating a child node
        if(data == -1)
        {
            return NULL;
        }
        //Else we create a node and put value of data to root's data
        //Then we recursively call function again for left and right subchild of root
        Node* root = new Node(data);
        cout << "\nEnter left child of " << data;
        root->left = buildTree();
        cout << "\nEnter right child of " << data;
        root->right = buildTree();
        return root;
    }

    //Traversing the tree using preorder traversal
    void preorderTraversal(Node* root)
    {
        Node* temp = root;
        if(temp == NULL)
        {
            return;
        }
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }

    //Traversing the Tree using postorder traversal
    void postorderTraversal(Node* root)
    {
        Node* temp = root;
        if(temp == NULL)
        {
            return;
        }
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
    //Traversing the tree using inorder traversal
    void inorderTraversal(Node* root)
    {
        Node* temp = root;
        if(temp == NULL)
        {
            return;
        }
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);    
    }
};


int main()
{
    TreeBuild obj;
    Node* root = obj.buildTree();


    cout <<"\nRoot -> " << root->data;
    cout << "\nPreorder Traversal : ";
    obj.preorderTraversal(root);
    cout << "\nInorder Traversal : ";
    obj.inorderTraversal(root);
    cout << "\nPostorder Traversal : ";
    obj.postorderTraversal(root);
    return 0;
}