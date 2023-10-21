#include <iostream>
#include "TreeNode.h"

using namespace std;

int main()
{ //               (1)
  //             /  |  \
  //            /   |   \
  //          (2)  (3)   (4)
  //        / |\    / \    |
  //       /  | \  /   \   |
  //     (5)(6)(7) (8) (9) (10)
  //                       /\
  //                      /  \
  //                     (11)(12)
  //                       |
  //                       |
  //                      (13)
 
 // The GenreralTree class is nested in the TreeNode class. 
 //Inside the TreeNode constructor a new TreeNode is created with the value of 1, and is the root of the tree.
    TreeNode::GeneralTree tree(1);

 //Prints out the adress of the root
    cout << "The adress of the root of the tree is: " << tree.getRoot()<<endl;
 // This -> is accessing the member variable 'Data' of the root node in the GeneralTree object 'tree'
 // the value will be printed out.
    cout << "The value of the root of the tree is: " << tree.getRoot()->Data << endl;

 //Now four new 'TreeNode' objects is created with the 'new' keyword. 
 //The 'TreeNode' constructor is called, and the nodes are assigend new values. 
    TreeNode* node2 = new TreeNode(14);
    TreeNode* node3 = new TreeNode(20);
    TreeNode* node4 = new TreeNode(40);
    TreeNode* node5 = new TreeNode(59);
 //The root is assigned two new children, node2 and node3   
    tree.getRoot()->addChild(node2);
    tree.getRoot()->addChild(node3);
 //node2 are now parents to node 4 and node 3 are parents to node5
    node2->addChild(node4);
    node3->addChild(node5);
 //
    TreeNode* parentNode2 = tree.getParent(node4);
    TreeNode* parentNode3 = tree.getParent(node5);
 //Prints out the value of the parentNode 2 and 3
    cout <<"The parents of node4 and node5 is: "<< parentNode2->Data <<", " <<parentNode3->Data << endl;

 //Deleting the tree
    tree.deleteNode(tree.getRoot());
    cout << "Is the tree deleted? " << tree.isEmpty() << ". 0 means no and 1 means yes"<<endl;


//tree.insertNode(1,2);
//tree.insertNode(1, 3);
//tree.insertNode(1, 4);
//tree.insertNode(2, 5);
//tree.insertNode(2, 6);
//tree.insertNode(2, 7);
//tree.insertNode(3, 8);
//tree.insertNode(3, 9);
//tree.insertNode(4, 10);
//tree.insertNode(10, 11);
//tree.insertNode(10, 12);
//tree.insertNode(11, 13);
    cout << "Depth first Traversal: ";
    tree.depthFirstTraversal(tree.getRoot());
    cout << endl;

    cout << "The size of the tree is: " << tree.getSize(tree.getRoot()) << endl;
    cout << "The depth of the tree is: " << tree.getDepth(tree.getRoot()) << endl;
    cout << "Is the tree empty: " << tree.isEmpty() << endl;

    tree.deleteNode(tree.getRoot());
    cout << "Traversal after deleting the root: ";
    tree.depthFirstTraversal(tree.getRoot());
    cout << endl;

    cout << "The size of the tree is: " << tree.getSize(tree.getRoot()) << endl;
    cout << "The depth of the tree is: " << tree.getDepth(tree.getRoot()) << endl;
    cout << "Is the tree empty: " << tree.isEmpty() << endl;

    //tree.deleteNode(tree.getRoot());
    //std::cout << "Depth First Traversal after deleting root: ";
    //for (const auto& node : tree.getChildren(tree.getRoot())) {
    //    std::cout << node->Data << " ";
    //    for (const auto& child : tree.getChildren(node)) {
    //        std::cout << child->Data << " ";
    //    }
    //}
    //std::cout << std::endl;


    return 0;
}


