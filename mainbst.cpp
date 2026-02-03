#include <iostream>

#include "bst.cpp"

using namespace std;

int main(){
    int search_input, delete_input;
    int data_values[16] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};

    BST tree;
    //print_inorder
    cout << "Printing the tree in order\nBefore adding numbers\n";

    tree.print_inorder();

    for( int i = 0; i < 16; i++)
    {
        tree.insert(data_values[i]);
    }

    cout << "Printing the tree in order\nAfter adding numbers\n";

    tree.print_inorder();
    cout << "\n";

    //search
    cout << "Enter the number you want to search: \n";
    scanf("%d", &search_input);
    if(tree.search(search_input))
    {
        cout << search_input << " is in the tree";
    }
    else
    {
        cout << search_input << " is NOT in the tree";
    }
    cout << "\n";

    //smallest value
    cout << "The smallest value in the tree is "<< tree.findSmallest() << endl;

    //delete
    cout << "Enter the number you want to delete: (-1 to end)\n";
    while(delete_input != -1)
    {
        cout << "Delete node: ";
        cin >> delete_input;
        {
            if(delete_input != -1)
            {
                cout << endl;
                tree.delt(delete_input);
                tree.print_inorder();
                cout <<"\n";
            }
        }
    }

    //preorder
    cout << "Preorder: ";
    tree.print_preorder();
    cout << "\n";

    //postorder
    cout <<"Postorder: ";
    tree.print_postorder();
    cout << "\n";

    //height
    int height_of_tree = tree.height();
    cout << "Tree height: " << height_of_tree<< endl;

    //balanced
    if(tree.isbalanced())
    {
        cout << "The tree is balanced";
    }
    else
    {
        cout << "The tree is NOT balanced";
    }

    return 0;
}