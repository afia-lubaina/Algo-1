#include <iostream>
#include <string>
using namespace std;

void LCS(string X, string Y) {
    int m = X.length();
    int n = Y.length();

    int c[100][100];
    string b[100][100];

    for (int i = 0; i <= m; i++)
        c[i][0] = 0;

    for (int j = 0; j <= n; j++)
        c[0][j] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = "c";  // Diagonal arrow
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = "u";  // Up arrow
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = "l";  // Left arrow
            }
        }
    }

    // Printing the LCS
    int i = m;
    int j = n;
    string lcs = "";
    while (i > 0 && j > 0) {
        if (b[i][j] == "c") {
            lcs = X[i - 1] + lcs;
            i--;
            j--;
        } else if (b[i][j] == "u") {
            i--;
        } else {
            j--;
        }
    }

    cout << "Longest Common Subsequence: " << lcs << endl;
}

int main() {
    string X = "abba";
    string Y = "ababababa";

    LCS(X, Y);

    return 0;
}
