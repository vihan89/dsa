#include <bits/stdc++.h>
using namespace std;

// ---------------- DNA LCS -----------------
int LCS(string a, string b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

// --------------- STOCK LIS ----------------
int LIS(vector<int> &arr) {
    int n = arr.size();
    vector<int> dp(n, 1);

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    return *max_element(dp.begin(), dp.end());
}

// ---------------- MAIN MENU ----------------
int main() {
    int choice;
    while(true) {
        cout << "\n--- REAL WORLD APPLICATIONS USING DP ---\n";
        cout << "1. DNA Sequence Matching (LCS)\n";
        cout << "2. Stock Market Analysis (LIS)\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1) {
            string s1, s2;
            cout << "Enter DNA Sequence 1: ";
            cin >> s1;
            cout << "Enter DNA Sequence 2: ";
            cin >> s2;
            cout << "Similarity (LCS length) = " << LCS(s1, s2) << "\n";
        }

        else if(choice == 2) {
            int n;
            cout << "Enter number of days: ";
            cin >> n;
            vector<int> prices(n);

            cout << "Enter stock prices: ";
            for(int i=0; i<n; i++) cin >> prices[i];

            cout << "Longest period of increasing prices = "
                 << LIS(prices) << " days\n";
        }

        else if(choice == 3) {
            break;
        }

        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
