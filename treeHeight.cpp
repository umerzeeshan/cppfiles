
// C++ program to find height of tree 
#include <iostream> 
#include <queue>
using namespace std; 

  
  
/* A binary tree node has data, pointer to left child 
and a pointer to right child */
class node  
{  
    public: 
    int data;  
    node* left;  
    node* right;  
};  
  
/* Compute the "maxDepth" of a tree -- the number of  
    nodes along the longest path from the root node  
    down to the farthest leaf node.*/
int maxDepth(node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);  
        int rDepth = maxDepth(node->right);  
      
        /* use the larger one */
        if (lDepth < rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
}  
  
/* Helper function that allocates a new node with the  
given data and NULL left and right pointers. */
node* newNode(int data)  
{  
    node* Node = new node(); 
    Node->data = data;  
    Node->left = NULL;  
    Node->right = NULL;  
      
    return(Node);  
}  
int maxLevelSum(node* n)
{
    int count;
    int levelsum;
    queue <node*> q;
    if(n== NULL)
        return 0;
    q.push(n);
    int result = n->data;
    while(!q.empty())
    {
        levelsum = 0;
        count = q.size();
        while(count--)
        {
            node* tmp = q.front();
            levelsum = levelsum + tmp->data;
            q.pop();
            if(tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
            
        }

        result = max(result, levelsum);
    }
    return result;

}

// Driver code     
int main()  
{  
    node *root = newNode(1);  
  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
    root->right->left = newNode(8);  
    root->right->right = newNode(10); 
    root->right->right->right = newNode(12); 
      
    cout << "Height of tree is " << maxDepth(root)<<endl;  
    cout << "max level sum is: " <<maxLevelSum(root)<<endl;
    return 0;  
}  