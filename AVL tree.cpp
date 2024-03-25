#include <iostream>
#include <sstream>


using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;
};

int height(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* newNode(int key) {//новий вузол з заданим ключем
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

Node* rightRotate(Node* y) { //правий поворот вузла y та повертає посилання на новий корінь піддерева, який був піддеревом y.
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {//лівий поворот вузла x та повертає посилання на новий корінь піддерева, який був піддеревом x.
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(Node* node) {//Функція отримує вузол node та повертає різницю між висотою лівого та правого піддерева
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

Node* insert(Node* node, int key) {//Функція вставляє новий вузол з ключем key в піддерево з коренем node та повертає посилання на корінь цього піддерева після вставки
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));//обчислює нову висоту піддерева node, в якому було вставлено новий вузол. Функція отримує різницю висот між лівим і правим піддеревами

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)//Якщо різниця висот між лівим і правим піддеревами є більшою за 1 і ключ key менший за ключ в лівому піддереві, то виконується права ротація
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)//Якщо різниця висот між лівим і правим піддеревами є меншою за -1 і ключ key більший за ключ у правому піддереві, то виконується ліва ротація 
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {//Якщо баланс вузла більше 1 та ключ, що вставляється, більше, ніж ключ у лівому піддереві, то виконується поверхнева права ротація
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {//Якщо баланс менше -1 та ключ, що вставляється, менше, ніж ключ у правому піддереві, то виконується поверхнева ліва ротація
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(Node* root, ostream& os) {//обходить дерево у порядку префіксного обходу та записує ключі вузлів у потік os.
    if (root != NULL) {
        os << root->key << " ";
        preOrder(root->left, os);
        preOrder(root->right, os);
    }
}


int main() {
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    
    ostringstream os;
    preOrder(root,os);
    string result = os.str();
    cout << "Preorder traversal of the constructed AVL tree is: "<<result;

    return 0;
}
/*#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "x64/Debug/AVL tree.tlog/doctest.h"

TEST_CASE("Testing max function") {
    CHECK(max(1, 2) == 2);
    CHECK(max(2, 1) == 2);
    CHECK(max(-1, -2) == -1);
    CHECK(max(-2, -1) == -1);
    CHECK(max(0, 0) == 0);
    CHECK(max(2147483647, -2147483648) == 2147483647);
    CHECK(max(-2147483648, 2147483647) == 2147483647);
}
TEST_CASE("Testing AVL tree insertion and traversal") {
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    SUBCASE("Testing preorder traversal") {
        std::ostringstream os;
        preOrder(root, os);
        CHECK(os.str() == "30 20 10 25 40 50 ");
    }

   

 
}

TEST_CASE("Testing AVL tree rotations") {
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);

    SUBCASE("Testing left rotation") {
        root = insert(root, 5);
        ostringstream os;
        preOrder(root, os);
        CHECK(os.str() == "20 10 5 40 30 50 ");
    }

    SUBCASE("Testing right rotation") {
        root = insert(root, 60);
        ostringstream os;
        preOrder(root, os);
        CHECK(os.str() == "40 20 10 30 50 60 ");
    }

    SUBCASE("Testing left-right rotation") {
        root = insert(root, 35);
        ostringstream os;
        preOrder(root, os);
        CHECK(os.str() == "30 20 10 40 35 50 ");
    }

    SUBCASE("Testing right-left rotation") {
        root = insert(root, 15);
        ostringstream os;
        preOrder(root, os);
        CHECK(os.str() == "20 10 15 40 30 50 ");
    }
}*/











