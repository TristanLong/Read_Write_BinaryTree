#include <iostream>
#include <fstream>

using namespace std;

struct maTrix {
    int n;
    int list[100][100];
};

void read(maTrix& m) {
    ifstream infile("Text.txt");
    if (!infile.is_open()) {
        cout << "Không thể mở tệp!" << endl;
        return;
    }

    infile >> m.n;
    for (int i = 0; i < m.n; i++) {
        for (int j = 0; j < m.n; j++) {
            infile >> m.list[i][j];
        }
    }

    infile.close(); // Đóng tệp sau khi đọc xong.
}

void write(maTrix m) {
    ofstream outfile("Output.txt");
    if (!outfile.is_open()) {
        cout << "Không thể mở tệp đầu ra!" << endl;
        return;
    }

    outfile << m.n << endl;
    for (int i = 0; i < m.n; i++) {
        for (int j = 0; j < m.n; j++) {
            outfile << m.list[i][j] << " ";
        }
        outfile << endl;
    }

    outfile.close(); // Đóng tệp sau khi ghi xong.
}

//int main() {
//    maTrix myMatrix;
//
//    // Đọc dữ liệu từ tệp "Text.txt"
//    read(myMatrix);
//
//    // In dữ liệu ra màn hình
//    cout << "Ma trận doc duoc:" << endl;
//    for (int i = 0; i < myMatrix.n; i++) {
//        for (int j = 0; j < myMatrix.n; j++) {
//            cout << myMatrix.list[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    // Ghi dữ liệu vào tệp "Output.txt"
//    write(myMatrix);
//
//    return 0;
//}
