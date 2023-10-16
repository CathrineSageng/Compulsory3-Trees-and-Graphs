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

    TreeNode::GeneralTree tree(1);
    tree.insertNode(1,2);
    tree.insertNode(1, 3);
    tree.insertNode(1, 4);
    tree.insertNode(2, 5);
    tree.insertNode(2, 6);
    tree.insertNode(2, 7);
    tree.insertNode(3, 8);
    tree.insertNode(3, 9);
    tree.insertNode(4, 10);
    tree.insertNode(10, 11);
    tree.insertNode(10, 12);
    tree.insertNode(11, 13);

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


