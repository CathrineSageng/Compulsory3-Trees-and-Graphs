#include <iostream>
#include "TreeNode.h"

using namespace std;

int main()
{ 
 
 // The GenreralTree class is nested in the TreeNode class. 
 //Inside the TreeNode constructor a new TreeNode is created with the value of 4, and is the root of the tree.
    TreeNode::GeneralTree tree(4);

 //Prints out the adress of the root
    cout << "The adress of the root of the tree is: " << tree.getRoot()<<endl;
 // This -> is accessing the member variable 'Data' of the root node in the GeneralTree object 'tree'
 // the value will be printed out.
    cout << "The value of the root of the tree is: " << tree.getRoot()->Data << endl;

 //Now four new 'TreeNode' objects is created with the 'new' keyword. 
 //The 'TreeNode' constructor is called, and the nodes are assigned new values. 
    TreeNode* node2 = new TreeNode(14);
    TreeNode* node3 = new TreeNode(20);
    TreeNode* node4 = new TreeNode(40);
    TreeNode* node5 = new TreeNode(59);
    TreeNode* node6 = new TreeNode(88);
 //The root is assigned two new children, node2 and node3   
    tree.getRoot()->addChild(node2);
    tree.getRoot()->addChild(node3);
 //node2 are now parents to node 4 and node 3 are parents to node5
    node2->addChild(node4);
    node2->addChild(node6);
    node3->addChild(node5);
 // Declares new 'Treenode' objects and the 'getParents()' function is called. 
    TreeNode* parentNode2 = tree.getParent(node4);
    TreeNode* parentNode3 = tree.getParent(node5);
 // Declares a list called children and calls the getchildren function with node 2 as an argument
    list<TreeNode*> children = tree.getChildren(node2);
 //Prints out the value of the parentNode 2 and 3
    cout <<"The parents of node4 and node5 is: "<< parentNode2->Data <<", " <<parentNode3->Data << endl;
 //Prints out the children of node2.
    cout << "The children of node2 is:";
 //Declares a iterator to a list with a pointer count to the beginning of the children list.
 //Then the loop interates trough the list until it is at the end of the list. 
 //count++ points to the next element in the list
    for (list<TreeNode*>::iterator count = children.begin(); count!= children.end(); count++)
    {
        TreeNode* child = *count;
        cout << child->Data <<" ";
    }
    cout << endl;
 //Prints out the size of the tree
    cout << "The size of the tree is: " << tree.getSize(tree.getRoot())<<endl;
 //Prints out the depth of the tree. 
    cout << "The depth of the tree is: " << tree.getDepth(tree.getRoot()) << endl;
 //Prints out if the tree is empty
    cout << "Is the tree empty? " << tree.isEmpty() << endl;
 //Prints out if a node is the root or not
    cout << "Is node2 the root of the tree? " << tree.isRoot(node2)<<endl;
    cout << "Is the root really the root of the tree? " << tree.isRoot(tree.getRoot())<<endl;
//Prints out if a node has any children or not
    cout << "Is node2 a leaf? " << tree.isLeaf(node2) << endl;
    cout << "Is node6 a leaf? " << tree.isLeaf(node6) << endl;
 //Prints out the depthFirst traversal
    cout << "Depth first Traversal: ";
    tree.depthFirstTraversal(tree.getRoot());
    cout << endl;

 //Deleting a child from the tree
    TreeNode* deleteChild = tree.findNode(tree.getRoot(),88);
    if (deleteChild != nullptr) 
    {
        tree.deleteNode(deleteChild);
        cout << "Tree after deleting child with value 88: ";
        tree.depthFirstTraversal(tree.getRoot());
        cout << endl;
    }
    else {
        cout << "Parent node not found." <<endl;
    }
 //Deleting a parent from the tree
    TreeNode* parent = tree.findNode(tree.getRoot(), 14);
    if (parent != nullptr) {
        tree.deleteNode(parent);
        std::cout << "Tree after deleting a parent with value 14: ";
        tree.depthFirstTraversal(tree.getRoot());
        std::cout << std::endl;
    }
    else {
        std::cout << "Parent node not found." << std::endl;
    }
   //Deleting the tree
    tree.deleteRoot();
    std::cout << "Tree after deleting the root: ";
    tree.depthFirstTraversal(tree.getRoot());
    std::cout << std::endl;

//Create a new Treenode with the value of 1 at the root. 
    //               (1)
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
    TreeNode::GeneralTree treeNumber2(1);
    treeNumber2.insertNode(1,2);
    treeNumber2.insertNode(1, 3);
    treeNumber2.insertNode(1, 4);
    treeNumber2.insertNode(2, 5);
    treeNumber2.insertNode(2, 6);
    treeNumber2.insertNode(2, 7);
    treeNumber2.insertNode(3, 8);
    treeNumber2.insertNode(3, 9);
    treeNumber2.insertNode(4, 10);
    treeNumber2.insertNode(10, 11);
    treeNumber2.insertNode(10, 12);
    treeNumber2.insertNode(11, 13);

    //Prints out the depthFirst traversal
    cout << "Depth first Traversal of the second tree: ";
    treeNumber2.depthFirstTraversal(treeNumber2.getRoot());
    cout << endl;

    TreeNode* findChild = treeNumber2.findNode(treeNumber2.getRoot(), 2);
    cout << "I found the child with the value of " << findChild->Data;

    return 0;
}


