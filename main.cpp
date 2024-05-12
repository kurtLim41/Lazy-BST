#include "LazyBST.h"
#include <iostream> 
using namespace std;

int main(int argc , char **argv){
    LazyBST<int> *test = new LazyBST<int>;

    test->insert(50);
    test->insert(30);
    test->insert(20);
    test->insert(25);
    test->insert(22);
    
    test->insert(60);
    test->insert(55);
    test->insert(61);
    //test->insert(26);

    test->printTree();
    cout << "left depth of root: " << test->getLeftDepth(50) <<endl;
    cout << "right depth of root: " << test->getRightDepth(50) << endl;

    cout << "left depth of 30: " << test->getLeftDepth(30) <<endl;
    cout << "right depth of 30: " << test->getRightDepth(30) << endl;

    cout << "left depth of 20: " << test->getLeftDepth(20) <<endl;
    cout << "right depth of 20: " << test->getRightDepth(20) << endl;

    cout << "left depth of 25: " << test->getLeftDepth(25) <<endl;
    cout << "right depth of 25: " << test->getRightDepth(25) << endl;

    cout << "left depth of 22: " << test->getLeftDepth(22) <<endl;
    cout << "right depth of 22: " << test->getRightDepth(22) << endl;

    cout << "left depth of 60: " << test->getLeftDepth(60) <<endl;
    cout << "right depth of 60: " << test->getRightDepth(60) << endl;

    cout << "left depth of 55: " << test->getLeftDepth(55) <<endl;
    cout << "right depth of 55: " << test->getRightDepth(55) << endl;

    cout << "======================" << endl;

    //test->deleteNode(25);
    test->printTree();

    cout << "left depth of 30: " << test->getLeftDepth(30) <<endl;
    cout << "right depth of 30: " << test->getRightDepth(30) << endl;
    


}