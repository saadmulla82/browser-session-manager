# Browser Session Management — Undo Navigation System
### Case Study 164 | DSA-I Using C++ | ITM Skills University

---

## 2.1 Project Title
**Browser Session Management (Undo Navigation System)**

---

## 2.2 Problem Statement

Modern web browsers let users navigate between pages using Back and Forward buttons. This project simulates that exact behaviour in C++. A custom Stack class is built from scratch using arrays (no STL), and a BrowserSession class uses two stacks to handle Back and Forward navigation across visited URLs.

---

## 2.3 Objectives

- Build a custom array-based Stack class with push, pop, peek, overflow and underflow handling
- Use two stacks (backStack and forwardStack) for dual-direction navigation
- Encapsulate all browser logic inside a BrowserSession class
- Clear forwardStack when a new URL is visited — exactly like a real browser
- Demonstrate LIFO principle in a real-world context

---

## 2.4 System Overview / Architecture

| Component | Type | Purpose |
|-----------|------|---------|
| `Stack` class | Class | Custom array-based stack with all operations |
| `backStack` | Stack | Stores previously visited URLs |
| `forwardStack` | Stack | Stores URLs navigated back from |
| `currentPage` | string | The page currently being viewed |
| `BrowserSession` | Class | Combines stacks + currentPage with navigation methods |
| `main()` | Function | Menu-driven entry point |

---

## 2.5 Data Structures and Algorithms Used

- **Stack** — Custom implementation using `string elements[100]` array and `topIndex` integer
- **LIFO Principle** — Last In, First Out; core logic for Back navigation
- **Dual-Stack Design** — Two stacks mirror each other for bidirectional navigation

**Stack Operations:**

| Method | What it Does | Time Complexity |
|--------|-------------|-----------------|
| `push(url)` | Adds URL to top | O(1) |
| `pop()` | Removes and returns top URL | O(1) |
| `peek()` | Returns top without removing | O(1) |
| `isEmpty()` | Checks if topIndex == -1 | O(1) |
| `isFull()` | Checks if topIndex == MAX-1 | O(1) |
| `clearStack()` | Resets topIndex to -1 | O(1) |
| `displayStack()` | Prints all elements | O(n) |

---

## 2.6 Implementation Approach

1. `Stack` class uses `string elements[100]` and `topIndex = -1` initially
2. `push()` checks `isFull()` first, then increments topIndex and assigns value
3. `pop()` checks `isEmpty()` first, saves top value, decrements topIndex, returns value
4. `clearStack()` resets topIndex to -1 — no loop needed, O(1)
5. `BrowserSession::visitNewPage()` pushes current to backStack, clears forwardStack, sets new page
6. `goBack()` pushes current to forwardStack, pops backStack into currentPage
7. `goForward()` pushes current to backStack, pops forwardStack into currentPage
8. `main()` uses `do-while` loop with `switch-case` for the menu

---

## 2.7 Time and Space Complexity Analysis

| Operation | Time | Reason |
|-----------|------|--------|
| `visitNewPage()` | O(1) | push + clearStack both O(1) |
| `goBack()` | O(1) | One push + one pop |
| `goForward()` | O(1) | One push + one pop |
| `showCurrentPage()` | O(1) | Just reads one string |
| `showHistory()` | O(n) | Loops through stack elements |
| Space | O(n) | n = total URLs stored in both stacks |

---

## 2.8 Execution Steps

### Compile
```bash
g++ browser_session.cpp -o browser_session
```

### Run
```bash
# Linux / Mac
./browser_session

# Windows
browser_session.exe
```

### Menu Options
```
1. Visit New Page
2. Go Back
3. Go Forward
4. Show Current Page
5. Show History Stacks
6. Exit
```

---

## 2.9 Sample Inputs and Outputs

```
Enter choice: 1
Enter URL: www.google.com
Visited: www.google.com

Enter choice: 1
Enter URL: www.youtube.com
Visited: www.youtube.com

Enter choice: 1
Enter URL: www.github.com
Visited: www.github.com

Enter choice: 5
--- Back Stack ---
- www.youtube.com
- www.google.com
--- Forward Stack ---
Empty

Enter choice: 2
Went back to: www.youtube.com

Enter choice: 2
Went back to: www.google.com

Enter choice: 3
Went forward to: www.youtube.com

Enter choice: 5
--- Back Stack ---
- www.google.com
--- Forward Stack ---
- www.github.com

Enter choice: 6
Exiting Browser...
```

---

## 2.10 Screenshots

<img width="474" height="342" alt="Screenshot 2026-06-18 at 4 39 36 AM" src="https://github.com/user-attachments/assets/6b956c5c-65dc-4034-b84b-1332be272a3e" />


<img width="283" height="293" alt="Screenshot 2026-06-18 at 4 39 59 AM" src="https://github.com/user-attachments/assets/52a227ce-7a8d-4d46-8950-24c2ac26d376" />


<img width="311" height="160" alt="Screenshot 2026-06-18 at 4 40 15 AM" src="https://github.com/user-attachments/assets/12bf7630-d064-445e-b918-360a710b061f" />


<img width="271" height="150" alt="Screenshot 2026-06-18 at 4 40 22 AM" src="https://github.com/user-attachments/assets/1208ec5e-fa8b-4816-92c1-1d26da832421" />


<img width="250" height="203" alt="Screenshot 2026-06-18 at 4 40 30 AM" src="https://github.com/user-attachments/assets/805a46a0-cc31-4384-8174-6bd4812b3383" />


<img width="252" height="227" alt="Screenshot 2026-06-18 at 4 40 45 AM" src="https://github.com/user-attachments/assets/f4813c32-008f-4858-8782-65a822aef54a" />


<img width="479" height="168" alt="Screenshot 2026-06-18 at 4 40 53 AM" src="https://github.com/user-attachments/assets/183b95c0-d76d-4d64-b137-7ae2fda0242b" />

---

## 2.11 Results and Observations

- Custom Stack class worked correctly — all operations behaved as expected
- Dual-stack design supported both Back and Forward navigation independently
- Visiting a new URL correctly cleared forwardStack, matching real browser behaviour
- Stack Overflow message appeared correctly when push limit was reached
- Empty stack checks prevented crashes when Back/Forward pressed with no history
- All core operations ran in O(1) time — stacks are the ideal structure for this problem

---

## 2.12 Conclusion

This project showed how a Stack data structure built from scratch using arrays can solve a real-world problem — browser history navigation. The LIFO rule aligns perfectly with the Back button because the most recently visited page is always the first one returned to. Using two stacks allowed both Back and Forward to work independently and cleanly. Building the Stack manually (without STL) gave a deep understanding of topIndex, overflow, underflow, push, and pop at the code level.

---

## Student Details

| Field | Details |
|-------|---------|
| Name | Mohammed Saad Mulla |
| Roll Number | 150096725112 |
| GitHub | [github.com/saadmulla82](https://github.com/saadmulla82) |
| Cohort | Sam Altman |
| Batch | 2025-29 |
| Course | B.Tech CSE |
| Semester | II |
| Subject | Data Structures and Algorithms - I (C++) |
| University | ITM Skills University, Mumbai |

---

## Repository Link

**https://github.com/saadmulla82/browser-session-manager**
