# Binary-Search-Tree-Self-Organizing-
Self-Organizing BST based on search frequency

Statement of Work: Implement a generic self organizing binary search tree, which supports element insertion, deletion,
search (and self-restructuring), and in-order and level-order traversals. Analyze the time complexity of one of the member
functions of the binary search tree.

Project Requirements:

In this project you are asked to develop a generic self organizing binary search tree. A self organizing binary search 
tree can restructure itself depending on the search frequency of the elements in the tree. In particular, a threshold 
value is maintained by the tree and a search count is maintained by each node in the tree. The search count is increased 
by 1 each time there is a search of the value stored in the corresponding node. When the search count reaches the threshold,
the corresponding node will move up in the tree by one level, which is achieved by a single rotation: rotate the position of
the current node with that of the corresponding parent node. Let t denote the node whose search count is equal to the threshold,
and p the parent node. First, let us assume that t is the left child of the parent node p. Then the rotation occurs as follows: 
1) node t will occupy the position of p (that is, the parent of p will point to t instead of p); 
2) the right child of node t becomes the left child of p; and 
3) node p becomes the right child of node t. The following figure shows the single rotation.
The case that t is the right child of the parent node p is analogous to the one we just discussed: 
1) node t will occupy the position of p (that is, the parent of p will point to t instead of p);
2) the left child of node t becomes the right child of p; and 
3) node p becomes the left child of node t.

After the single rotation, search count of node t is re-set to 0. When a node is already at the root (top) of the tree, 
no rotation should be performed even if the search count equals the specified threshold. For this case, you also need 
to re-set the search count to 0.
