#include <iostream>
#include <queue>
#include "FileOps.h"
#include "SequenceST.h"

using namespace std;


template <typename Key, typename Value>
class BST{
private:
    struct Node{
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key key, Value value){
            this->key = key;
            this->value = value;
            this->left = this->right = nullptr;
        }

        Node(Node* node){
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
        }
    };

    Node *root;
    int count;

public:
    BST(){
        root = nullptr;
        count = 0;
    }

    void destroy(Node *pNode) {
        if(pNode != nullptr){
            destroy(pNode->left);
            destroy(pNode->right);
            delete pNode;
            count--;
        }
    }

    ~BST(){
        destroy(root);
    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }

    void insert(Key key, Value value){
        root = insert(root, key, value);
    }

    bool contain(Key key){
        return contain(root, key);
    }

    Value* search(Key key){
        return search(root, key);
    }

private:
    // 删除掉以node为根的二分搜索树中键值为key的节点
    // 返回删除节点后新的二分搜索树的个
    Node* remove(Node* node, Key key){
        if(node == nullptr)
            return nullptr;

        if(key < node->key){
            node->left = remove(node->left, key);
            return node;
        }
        else if(key > node->key){
            node->right = remove(node->right, key);
            return node;
        }
        else{ // key == node->key
            if(node->left == nullptr){
                Node* rightNode = node->right;
                delete node;
                count--;
                return rightNode;
            }
            if(node->right == nullptr){
                Node* leftNode = node->left;
                delete node;
                count--;
                return leftNode;
            }

            // node->left != nullptr && node->right != nullptr
            Node* delNode = node;
            Node* successor = new Node(minimum(node->right));
            count++;

            successor->right = removeMin(node->right);
            successor->left = node->left;
            delete delNode;
            count--;

            return successor;

        }
    }

    // 删除掉以node为根的二分搜索树中的最小节点
    // 返回删除节点后新的二分搜索树的根
    Node* removeMin(Node* node){
        if(node->left == nullptr){
            Node* rightNode = node->right;
            delete node;
            count--;
            return rightNode;
        }
        node->left = removeMin(node->left);
        return node;
    }

    // 删除掉以node为根的二分搜索树中的最大节点
    // 返回删除节点后新的二分搜索树的根
    Node* removeMax(Node* node){
        if(node->right == nullptr){
            Node* leftNode = node->left;
            delete node;
            count--;
            return leftNode;
        }
        node->right = removeMax(node->right);
        return node;
    }

    // 在以node为根的二叉搜索树中，返回最小键值的节点
    Node* maximum(Node* node){
        if(node->right == nullptr)
            return node;
        minimum(node->right);
    }

    // 在以node为根的二叉搜索树中，返回最大键值的节点
    Node* minimum(Node* node){
        if(node->left == nullptr)
            return node;
        minimum(node->left);
    }


    // 向以node为根的二叉搜索树中，插入节点(key, value)
    // 返回插入新节点后的二叉搜索树的根
    Node* insert(Node *node, Key key, Value value){

        if(node == nullptr){
            count ++;
            return new Node(key, value);
        }

        if(key == node->key)
            node->value = value;
        else if(key < node->key)
            node->left = insert(node->left, key, value);
        else
            node->right = insert(node->right, key, value);

        return node;
    }

    // 查看以node为根的二叉搜索树中是否包含键值为key的节点
    bool contain(Node* node, Key key){
        if (node == nullptr)
            return false;

        if (key == node->key)
            return true;
        else if(key < node->key)
            return contain(node->left, key);
        else // key > node->key
            return contain(node->right, key);
    }

    // 在以node为根的二叉搜索树中查找key所对应的value
    Value* search(Node* node, Key key){
        if(node == nullptr)
            return nullptr;

        if(key == node->key)
            return &(node->value);
        else if(key < node->key)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

    // 对以node为根得二叉搜索树进行前序遍历
    void preOrder(Node* node){
        if(node != nullptr){
            cout << node->key << endl;
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    // 对以node为根的二叉搜索树进行中序遍历
    void inOrder(Node* node){
        if(node != nullptr){
            inOrder(node->left);
            cout << node->key << endl;
            inOrder(node->right);
        }
    }


    // 对以node为根的二叉搜索树进行后序遍历
    void postOrder(Node* node){
        if(node != nullptr){
            inOrder(node->left);
            inOrder(node->right);
            cout << node->key << endl;
        }
    }

    // 中序遍历
    void inOrder(){
        inOrder(root);
    }

    // 前序遍历
    void preOrder(){
        preOrder(root);
    }

    // 后序遍历
    void postOrder(){
        postOrder(root);
    }

    // 层序遍历
    void levelOrder(){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node *node = q.front();
            q.pop();

            cout << node->key << endl;

            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
    }

    // 寻找最小值的键值
    Key minimum(){
        assert(count != 0);
        Node* minNode = minimum(root);
        return minNode->key;
    }

    // 寻找最大值的键值
    Key maximum(){
        assert(count != 0);
        Node* maxNode = maximum(root);
        return maxNode->key;
    }

    // 从二叉树中删除最小值所在节点
    void removeMin(){
        if(root)
            root = removeMin(root);
    }

    // 从二叉树中删除最大值所在节点
    void removeMax(){
        if(root)
            root = removeMax(root);
    }

    // 从二叉树中删除键值为key的节点
    void remove(Key key){
        root = remove(root, key);
    }
};


int main(){

    string filename = "../../BST/bible.txt";
    vector<string> words;
    if(FileOps::readFile(filename, words)){
        cout << "There are totally " << words.size() << " words in " << filename << endl;
        cout << endl;

        // 测试 BST
        time_t startTime = clock();

        BST<string, int> bst = BST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++){
            int *res = bst.search(*iter);
            if(res == nullptr)
                bst.insert(*iter, 1);
            else
                (*res)++;
        }

        if(bst.contain("god"))
            cout << "'god' : " << *bst.search("god") << endl;
        else
            cout << "No word 'god' in " << filename << endl;

        time_t endTime = clock();

        cout << "BST, time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;

        startTime = clock();

        SequenceST<string, int> sst = SequenceST<string, int>();
        for(vector<string>::iterator iter = words.begin(); iter != words.end(); iter++){
            int *res = sst.search(*iter);
            if(res == nullptr)
                sst.insert(*iter, 1);
            else
                (*res)++;
        }

        if(sst.contain("god"))
            cout << "'god' : " << *sst.search("god") << endl;
        else
            cout << "No word 'god' in " << filename << endl;

        endTime = clock();

        cout << "SST, time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;

    }

    return 0;
}