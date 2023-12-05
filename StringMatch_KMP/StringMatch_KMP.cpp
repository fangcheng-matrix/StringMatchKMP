// StringMatch_KMP.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include <iostream>
using namespace std;

void KMP_Matcher(const char* target, const char* pattern);
int* ComputePrefixFunction(const char* pattern);

int main(int argc, char* argv[]) {
    cout << "Target string: " << argv[1] << endl;
    cout << "Pattern string: " << argv[2] << endl;
    KMP_Matcher(argv[1], argv[2]);
}

void KMP_Matcher(const char* target, const char* pattern){
    int n = strlen(target);
    int m = strlen(pattern);
    int* match = ComputePrefixFunction(pattern);
    int p = -1;  // index of characters matched
    // scan the text from left to right
    for (int t = 0; t < n; t++) {
        while ((p >= 0) && (pattern[p + 1] != target[t])) {
            p = match[p];  // next character does not match
        }
        if (pattern[p + 1] == target[t]) {
            p = p + 1;  // next character matches
        }
        // Is all of pattern matched
        if (p == (m - 1)) {
            cout << "Pattern occurs with shift " << t - p << endl;
            p = match[p];
        }
    }
}

int* ComputePrefixFunction(const char* pattern){
    int m = strlen(pattern);
    int* PI = new int[m];
    PI[0] = -1;
    int k = 0;
    for (int q = 1; q < m; q++) {
        k = PI[q - 1];
        while ((k >= 0) && (pattern[k + 1] != pattern[q])) {
            k = PI[k];
        }
        if (pattern[k + 1] == pattern[q]) {
            k = k + 1;
        }
        PI[q] = k;
    }
    return PI;
}
