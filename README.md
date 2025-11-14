# DSA Assignments (Sorting, Data Structures, and Algorithms)

This workspace includes multiple C++ programs covering sorting, searching, STL containers, expression evaluation, queue-based ticket system, circular playlist, BST-based student database, social network (graph), and DP solutions (LCS & LIS).

Files and what they contain:
- `ass1.cpp` - Sorting algorithms (Bubble, Quick, Merge) and searching (Linear, Binary). Interactive menu.
- `ass2.cpp` - Demonstrates STL containers: `vector`, `list`, `stack`, `queue`, `set`, `map` with access/alter/loop ops.
- `ass3.cpp` - Infix expression evaluator (handles spaces, parentheses, precedence). Uses stacks.
- `aass4.cpp` - Ticket booking system using `queue` (enqueue, dequeue, show queue).
- `ass5.cpp` - Circular linked list music playlist (add, delete, next, display).
- `ass6.cpp` - Student database using BST (insert, delete, search, traversals, find highest/lowest marks, count).
- `ass7.cpp` - Simple social network modeled as graph; supports adding persons, friendships, BFS, DFS, display.
- `ass8.cpp` - DP for DNA sequence matching (LCS) and Stock Market Analysis (LIS).

Build & run each program (PowerShell / MinGW):

```powershell
# Build all
g++ -std=c++17 ass1.cpp -O2 -o ass1.exe
g++ -std=c++17 ass2.cpp -O2 -o ass2.exe
g++ -std=c++17 ass3.cpp -O2 -o ass3.exe
g++ -std=c++17 aass4.cpp -O2 -o aass4.exe
g++ -std=c++17 ass5.cpp -O2 -o ass5.exe
g++ -std=c++17 ass6.cpp -O2 -o ass6.exe
g++ -std=c++17 ass7.cpp -O2 -o ass7.exe
g++ -std=c++17 ass8.cpp -O2 -o ass8.exe

# Run an example
./ass3.exe    # evaluate a sample infix expression
./ass8.exe    # run LCS or LIS scenarios
```

Notes & suggestions:
- `ass1.cpp` uses a static array of max size 50. Consider converting to `vector<int>` and checking bounds.
- `ass3.cpp` supports multi-digit numbers and parentheses, but not unary minus or float numbers; you can extend it by handling `-` in unary context and decimal points.
- In `ass6.cpp`, highest/lowest marks are found via a full tree scan (since marks are not the BST key). That's correct; if you want faster queries, consider keeping a separate BST keyed by `marks` or use augmentations.
- `ass2.cpp` demonstrates basic STL operations; it prints non-ASCII characters for one mapping key — that may be encoding-dependent.

If you want, I can:
- Merge all programs into a single interactive menu.
- Add unit tests for each program.
- Extend infix evaluation to support unary minus and power operator `^`.

---
Let me know whether you want me to add improvements or automated tests.