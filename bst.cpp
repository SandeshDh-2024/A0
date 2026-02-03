#include <iostream>
#include <cmath>

#include "bst.h"

using namespace std;


BST::BST(){
    root = NULL;
}

BST::node* BST::create(int data){
    node* n = new node;
    n -> data = data;

    n->left = NULL;
    n->right = NULL;

    return n;
}

void BST::insert(int data){
    if(root == NULL)
    {
        root = create(data);
    }
    else
    {
        insert_priv(data, root);
    }

    if(!isbalanced())
    {
        cout <<"The tree is UNBALANCED after inserting value: " << data << "\n"<< endl;
    }
}

void BST::insert_priv(int data, node* ptr){
    if(root == NULL)
    {
        root = create(data);
    } 
    else if( data < ptr->data)
    {
        if(ptr -> left != NULL)
        {
            insert_priv(data , ptr -> left);
        }
        else
        {
            ptr -> left = create(data);
        }
    }
    else if( data > ptr->data)
    {
        if(ptr -> right != NULL)
        {
            insert_priv(data , ptr -> right);
        }
        else
        {
            ptr -> right = create(data);
        }
    }
    else
    {
        cout << "The number " << data << " has already been added to the tree\n";
    }
}

void BST::print_inorder(){
    print_inorder_priv(root);
}

void BST::print_inorder_priv(node *ptr){
    if(root != NULL){
        if(ptr -> left != NULL)
        {
            print_inorder_priv(ptr -> left);
        }
        cout << ptr -> data <<" ";
        if(ptr -> right != NULL)
        {
            print_inorder_priv(ptr -> right);
        }
    }
    else{
        cout << "The tree is empty\n";
    }
}

bool BST::search(int data)
{
    return search_priv(data, root);
}

bool BST::search_priv(int data, node* ptr)
{
    if (ptr == NULL)
        return false;

    if (ptr->data == data)
    {
        return true;
    }
    else if (data < ptr->data)
    {
        return search_priv(data, ptr->left);
    }
    else
    {
        return search_priv(data, ptr->right);
    }
}

int BST::findSmallest()
{
    return findSmallest_priv(root);
}

int BST::findSmallest_priv(node* ptr)
{
    if(root == NULL)
    {
        cout << "The tree is empty\n";
        return -1;
    }
    else
    {
        if(ptr -> left != NULL)
        {
            return findSmallest_priv(ptr -> left);
        }
        else
        {
            return ptr -> data;
        }
    }
}


void BST::delt(int data)
{
    delete_priv(data, root);

    if(!isbalanced())
    {
        cout <<"The tree is UNBALANCED after deleting value: " << data << "\n"<< endl;
    }
}

void BST::delete_priv(int data, node* parent)
{
    if(root != NULL)
    {
        if(root -> data == data)
        {
            delete_root_match();
        }
        else
        {
            if(data < parent -> data && parent -> left != NULL)
            {
                if(parent -> left -> data == data)
                {
                    delete_match(parent, parent -> left, true);
                }
                else
                {
                    delete_priv(data, parent -> left);
                }
            }
            else if(data > parent -> data && parent -> right != NULL)
            {
                if(parent -> right -> data == data)
                {
                    delete_match(parent, parent -> right, false);
                }
                else
                {
                    delete_priv(data, parent -> right);
                }
            }
            else
            {
                cout <<"The data " << data << " was not in the tree\n";
            }
        }
    }
    else
    {
        cout <<"The tree is empty\n";
    }
}

void BST::delete_root_match()
{
    if(root != NULL)
    {
        node* delptr = root;
        int root_data = root -> data;
        int smallestInRightSubTree;

        //Case 0
        if(root -> left == NULL && root -> right == NULL)
        {
            root = NULL;
            delete delptr;
        }
        //Case 1 - 1 child
        else if(root -> left == NULL && root -> right != NULL)
        {
            root = root -> right;
            delptr -> right = NULL;
            delete delptr;
            cout << "The root node with data " << root_data << " was deleted."<<
                    "The new root contains data " << root -> data << endl;
        }
        else if(root -> left != NULL && root -> right == NULL)
        {
            root = root -> left;
            delptr -> left = NULL;
            delete delptr;
            cout << "The root node with data " << root_data << " was deleted."<<
                    "THe new root contains data " << root -> data << endl;
        }
        // Case 2 - 2 children
        else
        {
            smallestInRightSubTree = findSmallest_priv(root -> right);
            delete_priv(smallestInRightSubTree, root);
            root -> data = smallestInRightSubTree;
            cout << "The root data containing value " << root_data <<
                    " was overwritten with value " << root -> data << endl;
        }
    }
    else
    {
        cout << "Can not remove. Tree is empty\n";
    }
}

void BST::delete_match(node* parent, node* match, bool left)
{
    if(root != NULL)
    {
        node* delptr;
        int match_data = match -> data;
        int smallestInRightSubTree;

        //Case 0 - 0 children
        if(match -> left == NULL && match -> right == NULL)
        {
            delptr = match;
            if(left == true)
            {
                parent -> left = NULL;
            }
            else
            {
                parent -> right = NULL;
            }
            delete delptr;
            cout << "The node containing value " << match_data << " was removed\n";
        }
        //Case 1 - 1 child
        else if( match -> left == NULL && match -> right != NULL)
        {
            if(left == true)
            {
                parent -> left = match -> right;
            }
            else
            {
                parent -> right = match -> right;
            }
            match -> right = NULL;
            delptr = match;
            delete delptr;
            cout << "The node containing value" << match_data << " was removed\n";
        }
        else if( match -> left != NULL && match -> right == NULL)
        {
            if(left == true)
            {
                parent -> left = match -> left;
            }
            else
            {
                parent -> right = match -> left;
            }
            match -> left = NULL;
            delptr = match;
            delete delptr;
            cout << "The node containing value" << match_data << " was removed\n";
        }
        //Case 2 - 2 children
        else
        {
            smallestInRightSubTree = findSmallest_priv(match -> right);
            delete_priv(smallestInRightSubTree, match);
            match -> data = smallestInRightSubTree;
        }
    }
    else
    {
        cout << "Can not remove. Tree is empty";
    }
}

void BST::print_preorder(){
    print_preorder_priv(root);
}

void BST::print_preorder_priv(node *ptr){
    if(ptr == NULL)
    {
        return;
    }
    cout << ptr -> data << " ";
    print_preorder_priv(ptr -> left);
    print_preorder_priv(ptr -> right);
    
}

void BST::print_postorder(){
    print_postorder_priv(root);
}

void BST::print_postorder_priv(node *ptr){
    if(ptr == NULL)
    {
        return;
    }
    print_preorder_priv(ptr -> left);
    print_preorder_priv(ptr -> right);
    cout << ptr -> data << " ";
}

int BST::height()
{
    return height_priv(root);
}

int BST::height_priv(node* ptr)
{
    if(ptr == NULL)
    {
        return -1;
    }
    return max(height_priv(ptr -> left), height_priv(ptr -> right)) + 1;
    
}

bool BST::isbalanced()
{
    return isbalanced_priv(root);
}

bool BST::isbalanced_priv(node* ptr)
{
    if(ptr == NULL)
    {
        return true;
    }
    int leftHeight = height_priv(ptr -> left);
    int rightHeight = height_priv(ptr -> right);

    if(abs(leftHeight - rightHeight) > 1)
    {
        return false;
    }

    return isbalanced_priv(ptr -> left) && isbalanced_priv(ptr -> right);

}