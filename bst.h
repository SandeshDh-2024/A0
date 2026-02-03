#include "customErrorClass.h"

class BST{
    private:
        struct node{
            int data;
            node* left;
            node* right;
        };

        node* root;
        void insert_priv(int data, node* ptr);
        void print_inorder_priv(node* ptr);
        bool search_priv(int data, node* ptr);
        int findSmallest_priv(node* ptr);
        void delete_priv(int data, node* parent);
        void delete_root_match();
        void delete_match(node* parent, node* match, bool left);
        void print_preorder_priv(node* ptr);
        void print_postorder_priv(node* ptr);
        int height_priv(node* ptr);
        bool isbalanced_priv(node* ptr);
    public:
        BST();
        node* create(int data);
        void insert(int data);
        void print_inorder();
        bool search(int data);
        int findSmallest();
        void delt(int data);
        void print_preorder();   
        void print_postorder();
        int height();
        bool isbalanced();
};