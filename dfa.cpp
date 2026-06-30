#include <iostream>
using namespace std;

int main() {

    int n, m;

    // Number of states
    cout << "Enter number of states: ";
    cin >> n;

    char states[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter state " << i + 1 << ": ";
        cin >> states[i];
    }

    // Number of input symbols
    cout << "\nEnter number of input symbols: ";
    cin >> m;

    char symbols[m];
    for (int i = 0; i < m; i++) {
        cout << "Enter symbol " << i + 1 << ": ";
        cin >> symbols[i];
    }

    // Transition table
    char transition[n][m];

    cout << "\nEnter transition table:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "From " << states[i]
                 << " with input " << symbols[j]
                 << " go to: ";
            cin >> transition[i][j];
        }
    }

    // Initial state
    char currentState;
    cout << "\nEnter initial state: ";
    cin >> currentState;

    // Final state (only one final state for simplicity)
    char finalState;
    cout << "Enter final state: ";
    cin >> finalState;

    // Input string
    string str;
    cout << "\nEnter string: ";
    cin >> str;

    // Process the string
    for (int i = 0; i < str.length(); i++) {

        int row = -1, col = -1;

        // Find current state's row
        for (int j = 0; j < n; j++) {
            if (states[j] == currentState) {
                row = j;
                break;
            }
        }

        // Find input symbol's column
        for (int j = 0; j < m; j++) {
            if (symbols[j] == str[i]) {
                col = j;
                break;
            }
        }

        // Invalid symbol check
        if (col == -1) {
            cout << "Invalid input symbol!" << endl;
            return 0;
        }

        // Move to next state
        currentState = transition[row][col];
    }

    // Check final state
    if (currentState == finalState)
        cout << "\nString Accepted";
    else
        cout << "\nString Rejected";

    return 0;
}