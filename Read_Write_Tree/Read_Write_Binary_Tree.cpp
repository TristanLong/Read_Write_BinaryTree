#include <iostream>
#include <fstream>

using namespace std;

// Định nghĩa cấu trúc của một nút trong cây nhị phân
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Hàm để chèn một giá trị vào cây nhị phân
void insertIntoBST(TreeNode*& root, int value) {
    if (root == nullptr) {
        root = new TreeNode(value);
    }
    else {
        if (value < root->data) 
            insertIntoBST(root->left, value);
        else 
            insertIntoBST(root->right, value);
    }
}

// Hàm để đọc dữ liệu từ tệp và xây dựng cây nhị phân
void readBinaryTreeFromFile(TreeNode*& root, ifstream& inFile) {
    if (!inFile.is_open()) {
        cout << "Không thể mở tệp " << endl;
        return;
    }

    //Biểu thức inFile >> value sẽ trả về giá trị true nếu việc đọc thành công, và false nếu đọc đã kết thúc hoặc xảy ra lỗi.
    int value;
    while (inFile >> value) {
        insertIntoBST(root, value);
    }

    inFile.close();
}

// Hàm để ghi dữ liệu của cây nhị phân vào tệp
void writeBinaryTree(TreeNode* root, ofstream& outFile) {
    if (root) {
        outFile << root->data << " "; // Ghi dữ liệu của nút hiện tại
        writeBinaryTree(root->left, outFile); // Ghi cây con trái
        writeBinaryTree(root->right, outFile); // Ghi cây con phải
    }
}

int main() {
    // Tạo cây nhị phân từ dữ liệu trong tệp văn bản
    TreeNode* root = nullptr;
    ifstream inFile("input.txt");
    readBinaryTreeFromFile(root, inFile);

    // Ghi cây nhị phân vào tệp
    ofstream outFile("BinaryTree.txt");
    writeBinaryTree(root, outFile);
    outFile.close();

    // Giải phóng bộ nhớ của cây nhị phân
    delete root;

    return 0;
}
