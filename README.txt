Date: 2/4/2026
Course: Advanced Data Structures
Assignment: A0 – BST Review

Description

This program implements a Binary Search Tree (BST) in C++. It supports core operations including insertion, searching, deletion, and tree traversals. The program also detects worst-case BST behavior by determining whether the tree becomes unbalanced after insert or delete operations. Custom exception handling is used to gracefully manage invalid operations and edge cases.

Files

bst.h
bst.cpp
mainbst.cpp
customErrorClass.h
customErrorClass.cpp
Makefile
A0.pdf

Program Experiments

The BST was tested using both adversarial and friendly insertion orders. Adversarial insertion sequences caused the tree to become unbalanced and successfully triggered worst-case detection logic. Runtime performance was measured using the time command. Due to the small input size, execution times are very short and are largely influenced by program startup overhead rather than algorithmic performance differences.

Screenshots are included to show program output for insertion operations and the print_inorder function. More accurate performance analysis could be achieved by increasing the input size, running multiple trials and averaging the results, or measuring only the insertion logic within the program. These approaches would reduce the effect of startup overhead and better demonstrate worst-case BST behavior.

Correctness and Edge Cases

The implementation correctly handles a variety of edge cases, including inserting duplicate values, searching for non-existent keys, deleting nodes from an empty tree, and deleting nodes with zero, one, or two children. Custom exceptions are used to report invalid operations without causing the program to terminate unexpectedly.

Functionality Verification

Program output and screenshots confirm the correct behavior of BST insertion, search, and deletion for all cases. Inorder, preorder, and postorder traversals function as expected, and height calculations for specified nodes are verified.

Running the Program

make : compiles all the cpp Files
./bst : runs the program