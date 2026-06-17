#include <iostream>
#include <string>

using namespace std;

#define MAX_HISTORY 100

class Stack {
    int topIndex;
    string elements[MAX_HISTORY];
public:
    Stack() {
        topIndex = -1;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    bool isFull() {
        return topIndex == MAX_HISTORY - 1;
    }

    void push(string url) {
        if (!isFull()) {
            topIndex++;
            elements[topIndex] = url;
        } else {
            cout << "Stack Overflow\n";
        }
    }

    string pop() {
        if (!isEmpty()) {
            string val = elements[topIndex];
            topIndex--;
            return val;
        } else {
            return "";
        }
    }

    string peek() {
        if (!isEmpty()) {
            return elements[topIndex];
        }
        return "";
    }

    void clearStack() {
        topIndex = -1;
    }

    void displayStack() {
        if (isEmpty()) {
            cout << "Empty\n";
            return;
        }
        for (int i = topIndex; i >= 0; i--) {
            cout << "- " << elements[i] << "\n";
        }
    }
};

class BrowserSession {
    Stack backStack;
    Stack forwardStack;
    string currentPage;

public:
    BrowserSession() {
        currentPage = "about:blank";
    }

    void visitNewPage(string url) {
        if (currentPage != "about:blank") {
            backStack.push(currentPage);
        }
        currentPage = url;
        forwardStack.clearStack();
        cout << "Visited: " << currentPage << "\n";
    }

    void goBack() {
        if (backStack.isEmpty()) {
            cout << "Cannot go back. No history.\n";
            return;
        }
        forwardStack.push(currentPage);
        currentPage = backStack.pop();
        cout << "Went back to: " << currentPage << "\n";
    }

    void goForward() {
        if (forwardStack.isEmpty()) {
            cout << "Cannot go forward. No history.\n";
            return;
        }
        backStack.push(currentPage);
        currentPage = forwardStack.pop();
        cout << "Went forward to: " << currentPage << "\n";
    }

    void showCurrentPage() {
        cout << "\n=== Current Page ===\n";
        cout << currentPage << "\n";
        cout << "====================\n";
    }

    void showHistory() {
        cout << "\n--- Back Stack ---\n";
        backStack.displayStack();
        cout << "--- Forward Stack ---\n";
        forwardStack.displayStack();
        cout << "--------------------\n";
    }
};

int main() {
    BrowserSession browser;
    int choice;
    string url;

    do {
        cout << "\n1. Visit New Page\n";
        cout << "2. Go Back\n";
        cout << "3. Go Forward\n";
        cout << "4. Show Current Page\n";
        cout << "5. Show History Stacks\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter URL: ";
                cin >> url;
                browser.visitNewPage(url);
                break;
            case 2:
                browser.goBack();
                break;
            case 3:
                browser.goForward();
                break;
            case 4:
                browser.showCurrentPage();
                break;
            case 5:
                browser.showHistory();
                break;
            case 6:
                cout << "Exiting Browser...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}
