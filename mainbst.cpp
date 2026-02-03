#include <iostream>

#include "bst.cpp"

using namespace std;

int main(){
    int search_input, delete_input;
    int data_values[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 ,13, 14, 15, 16};
    int adversial[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
                        31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
                        61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
                        91, 92, 93, 94, 95, 96, 97, 98, 99, 100};
    int friendly[100] = {50, 25, 75, 12, 37, 62, 87, 6, 18, 31, 43, 56, 68, 81, 93,
3, 9, 15, 21, 28, 34, 40, 46, 53, 59, 65, 71, 78, 84, 90, 96,
1, 4, 7, 10, 13, 16, 19, 22, 26, 29, 32, 35, 38, 41, 44, 47, 51, 54, 57, 60,
63, 66, 69, 72, 76, 79, 82, 85, 88, 91, 94, 97, 2, 5, 8, 11, 14, 17, 20, 23,
27, 30, 33, 36, 39, 42, 45, 48, 52, 55, 58, 61, 64, 67, 70, 73, 77, 80, 83, 86,
89, 92, 95, 98, 24, 49, 74, 99, 100};

    BST tree;
    //print_inorder
    cout << "Printing the tree in order\nBefore adding numbers\n";

    tree.print_inorder();

    for( int i = 0; i < 100; i++)
    {
        tree.insert(friendly[i]);
    }

    tree.insert(17);

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
    
    while(delete_input != -1)
    {
        cout << "Enter the number you want to delete(-1 to end): ";
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