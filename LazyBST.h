#ifndef LazyBST_H
#define LazyBST_H

#include <iostream>
#include <array>
using namespace std;

template <class T>
class TreeNode{
    public:
        TreeNode();
        TreeNode(T k);
        ~TreeNode();

        T key;
        TreeNode<T> *left;
        TreeNode<T> *right;

        int leftDepth;
        int rightDepth;
};

template <class T>
TreeNode<T>::TreeNode(){
    left = NULL;
    right = NULL;
    key = NULL;
    leftDepth = 0;
    rightDepth = 0;
}

template <class T>
TreeNode<T>::TreeNode(T k){
    left = NULL;
    right = NULL;
    key = k;
    leftDepth = 0;
    rightDepth = 0;
}

template < class T>
TreeNode<T>::~TreeNode(){
    left = NULL;
    right = NULL;
}

template <class T>
class LazyBST{
    public:
        LazyBST();
        virtual ~LazyBST();

        void insert(T value);
        bool contains (T value); //search method
        bool deleteNode(T k);
        TreeNode<T> *getSuccessor(TreeNode<T> *d);
        void updateSubtreesDepths(TreeNode<T>* node);
        int calculateDepth(TreeNode<T>* node);
        void reBalance();
        void insertMedianValues(TreeNode<T>*& node, T* values, int start, int end);

        bool isEmpty();
        T* getMin();
        T* getMax();

        void printTree();
        void printTreeToFile(ostream &out);
        void recPrint(TreeNode<T> *node, T* &array, int& index);
        T* getInOrderValuesArray();
        int getLeftDepth(T value);
        int getRightDepth(T value);
        void clearTree(TreeNode<T> *node);

    private:
        TreeNode<T> *root;
        int size;

};

template <class T>
LazyBST<T>::LazyBST(){
    root = NULL;
    size = 0;
}

template <class T>
LazyBST<T>::~LazyBST(){
    clearTree(root);
}

template <class T>
void LazyBST<T>::recPrint(TreeNode<T> *node, T* &array, int& index){
    if(node == nullptr){
        return;
    }
    
    // In-order traversal
    recPrint(node->left, array, index);
    array[index++] = node->key; // Collect the value
    recPrint(node->right, array, index);
}

template <class T>
T* LazyBST<T>::getInOrderValuesArray(){
    T* values = new T[size];
    int index = 0;
    recPrint(root, values, index);
    return values;
}

template <class T>
void LazyBST<T>::printTree() {
    T* values = getInOrderValuesArray();
    for (int i = 0; i < size; ++i) {
        cout << values[i] << endl;
    }
    delete[] values; 
}

template <class T>
void LazyBST<T>::printTreeToFile(ostream &out) {
    T* values = getInOrderValuesArray();
    for (int i = 0; i < size; ++i) {
        out << values[i] << std::endl;
    }
    delete[] values;
}

template <class T>
bool LazyBST<T>::isEmpty(){
    return (root == NULL);
}

template <class T>
T* LazyBST<T>::getMin(){
    if(isEmpty())
        return NULL;

    TreeNode<T> *current = root;
    while(current->left != NULL){
        current = current->left;
    }

    return &(current->key);      
}

template <class T>
T* LazyBST<T>::getMax(){
    if(isEmpty())
        return NULL;

    TreeNode<T> *current = root;
    while(current->right != NULL){
        current = current->right;
    }

    return &(current->key);    
}

template <class T>
void LazyBST<T>::insert(T value){
    TreeNode<T> *node = new TreeNode<T>(value);
    
    if(isEmpty()){
        root = node;
        size++;
    }
    else{
        //tree has more then 1 node, let's go find where is goes 
        TreeNode<T> *current = root;
        TreeNode<T> *parent = NULL;
        
        while(true){
            parent = current;

            if(value < current->key){
                //we go left
                current = current->left;
                parent->leftDepth++;

                if(current == NULL){
                    //we reached a leaf and found the insertion node 
                    parent->left = node;
                    break;
                }
            }
            else{
                //we go rght 
                current = current->right;
                parent->rightDepth++;
                if (current == NULL){
                    parent->right = node;
                    break;
                }
            }
        }
        size++;
        // Update depth values after insertion
        updateSubtreesDepths(root);

        cout << "root: " << root->key << endl;
        printTree();
        cout << "diff:" << (root->leftDepth - root->rightDepth) << endl;
        // Check if rebalancing is needed after insertion
        if (abs(root->leftDepth - root->rightDepth) > 1.5){
            reBalance();

            updateSubtreesDepths(root);

            cout << "-----------------" << endl;
            cout << "New size: " << size << endl;
            cout << "new root: " << root->key << endl;
            cout << "root left depth: " << root->leftDepth << endl;
            cout << "root right depth: " << root->rightDepth << endl;
        printTree();
        }

    }
}

//search function O(log n)
template <class T>
bool LazyBST<T>::contains(T value){
    
    if(isEmpty()){
        return false;
    }

    TreeNode<T> *current = root;
    while(current->key != value){

        if(value < current->key){
            current = current->left;
        }
        else{
            current= current->right;
        }
        if(current = NULL){
            return false;
        }
    }
    return true;
}

template <class T>
bool LazyBST<T>::deleteNode(T k){
    if(isEmpty()){
        return false;
    }
    
    TreeNode<T> *current = root;
    TreeNode<T> *parent = root;
    bool isLeft;

    while(current->key != k){
        parent = current;

        if(k < current->key){
            isLeft = true;
            current = current->left;
        }
        else{
            isLeft = false;
            current = current->right;
        }

        if(current == NULL)
            return false;
    }

    //we found the node to be deleted, lets delete it 

    /* node to be deleted is a leaf node */
    if(current->left == NULL && current->right == NULL){
        if (current == root){
            root = NULL;
        }
        else if(isLeft)
            parent->left = NULL;
        else 
            parent->right = NULL; 

        // Update subtree depths of parent and ancestors
            
    }

    //node to be delted has 1 child 
    else if (current->right == NULL){
        //node has 1 child and its a left child 
        if(current == root)
            root = current->left;
        else if (isLeft){
            parent->left = current->left;
        }
        else   
            parent->right = current->left;

        // Update subtree depths of parent and ancestors
       
    }

    else if (current->left == NULL){
        //node has 1 child and its a right child 
        if(current == root)
            root = current->right;
        else if (isLeft){
            parent->left = current->right;
        }
        else   
            parent->right = current->right;

        // Update subtree depths of parent and ancestors
        
    }
    else{
        //node to be delted has two children, at this point we begin to cry and take a 4 hour nap
        TreeNode<T> *successor = getSuccessor(current);

        if(current == root)
            root = successor;
        else if(isLeft)
            parent->left = successor;
        else
            parent->right = successor;

        successor->left = current->left;  //NULL out the current node 
        current->left = NULL;
        current->right = NULL;

        // Update subtree depths of parent and ancestors
        
    }   
    delete current;
    size--;
    updateSubtreesDepths(root);
    //check if tree needs to be rebalanced after deletion 
    T tempVal = root->key;
    // if (abs(getLeftDepth(tempVal) - getRightDepth(tempVal)) > 1.5){
    //     reBalance();
    // }
    // return true;
}

template <class T>
//d is th enode to be deleted 
TreeNode<T>* LazyBST<T>:: getSuccessor(TreeNode<T> *d){
    TreeNode<T> *sp = d;
    TreeNode<T> *successor = d;
    TreeNode<T> *current = d->right;

    while(current != NULL){
        sp = successor;
        successor = current;
        current = current->left;
    }
    //once we get here, we found the successor
    //now we need to check if the successor is the descendant of the right child 
    if(successor != d->right){
        sp->left = successor->right;
        successor->right = d->right;
    }
    return successor;
}

template <class T>
int LazyBST<T>::getLeftDepth(T value){
   if(isEmpty()){
        return false;
    }

    TreeNode<T> *current = root;
    while(current->key != value){

        if(value < current->key){
            current = current->left;
        }
        else{
            current= current->right;
        }
        if(current == NULL){
            return 0; //-l means it doesnt exist
        }
    }
    return current->leftDepth;
}

template <class T>
int LazyBST<T>::getRightDepth(T value){
   if(isEmpty()){
        return false;
    }

    TreeNode<T> *current = root;
    while(current->key != value){

        if(value < current->key){
            current = current->left;
        }
        else{
            current= current->right;
        }
        if(current == NULL){
            return 0; //-l means it doesnt exist
        }
    }
    return current->rightDepth;
}


template <class T>
void LazyBST<T>::updateSubtreesDepths(TreeNode<T>* node) {
    if (node == nullptr)
        return;

    node->leftDepth = calculateDepth(node->left);
    node->rightDepth = calculateDepth(node->right);

    // Recursively update depths for left and right subtrees
    updateSubtreesDepths(node->left);
    updateSubtreesDepths(node->right);
}

template <class T>
int LazyBST<T>::calculateDepth(TreeNode<T>* node) {
    if (node == nullptr)
        return 0;

    int leftDepth = calculateDepth(node->left);
    int rightDepth = calculateDepth(node->right);

    return 1 + max(leftDepth, rightDepth);
}

template <class T>
void LazyBST<T>::reBalance(){
     cout << "starting rebalance" << endl;

    // Step 1: Get sorted values
    T* inOrderArray = getInOrderValuesArray();

    // Step 2: Clear the current tree
    clearTree(root); // Assuming you have a clear function that properly deallocates nodes

    // Step 3: Rebuild the tree from sorted values
    insertMedianValues(root, inOrderArray, 0, size - 1);

    // Step 4: Deallocate the dynamically allocated array
    delete[] inOrderArray;
    cout << "successful rebalance" << endl;

}

template <class T>
void LazyBST<T>::insertMedianValues(TreeNode<T>*& node, T* values, int start, int end) {
    if (start > end)
        return;

    int medianIndex = (start + end) / 2;
    T median = values[medianIndex];

    // Insert median at the current node position
    node = new TreeNode<T>(median);

    // Recursively insert into left and right subtrees
    insertMedianValues(node->left, values, start, medianIndex - 1);
    insertMedianValues(node->right, values, medianIndex + 1, end);
}


template <class T>
void LazyBST<T>::clearTree(TreeNode<T> *node){
    if (node == nullptr) {
        return;  // Base case: if the node is null, return
    }

    clearTree(node->left);   // Recursively clear the left subtree
    clearTree(node->right);  // Recursively clear the right subtree

    delete node;  // Delete the current node
    node = nullptr;  // Set the node pointer to nullptr to avoid dangling pointers
}




#endif