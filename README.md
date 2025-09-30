# 📘 DSA Lab Programs – 3rd Semester (Ordered)

This repository contains **Data Structures & Algorithms (DSA)** lab programs in **C**, organized exactly according to the 3rd Semester lab questions question paper. Each program is implemented as a separate `.c` file (or small group of files) and uses dynamic memory where the question requires it.


---

## 🔹 Table of Contents (Programs)

### 1. Structures & Time
**1(a)** `01a_student.c` —  
Define a `Student` structure: `Name`, `Reg_no`, marks in 3 tests, `average_marks`.  
Menu-driven with functions to:
- read info of N students (dynamic allocation),
- display student info,
- calculate average of best two test marks for each student.

**Notes:** Use pointer-to-array-of-structures and `malloc` / `realloc`.

**1(b)** `01b_time.c` —  
Define `Time { hour, minute, second }`. Menu-driven functions:
- `Read(T)`  
- `Display(T)`  
- `Update(T)` — increments by 1 second (normalize: 60s -> +1 minute, 60m -> +1 hour, 24h -> 0).  
- `Add(T1, T2)` — add two times and normalize.

**Notes:** Pass `Time *` to functions.

---

### 2. Dynamic array — position/key/pos/search/reverse  
`02_array_ops_pos_del_search_reverse.c`  
Menu:
- Insert by position  
- Delete by key  
- Search by position  
- Reverse array  
**Notes:** Use `malloc`/`realloc`, print array after every operation.

---

### 3. Dynamic array — ordered insert/delete/search/reverse  
`03_array_ops_order_insert_delete_search_reverse.c`  
Menu:
- Insert maintaining order  
- Delete by position  
- Search by key  
- Reverse array  
**Notes:** Maintain sorted order where required; dynamic memory.

---

### 4. Circular Single Linked List — ordered insert & others  
`04_circular_singly_order.c`  
Operations:
- Insert by order  
- Delete by position  
- Search by key  
- Delete by key  
Display after each operation.

---

### 5. Circular Doubly Linked List — ordered insert & others  
`05_circular_doubly_order.c`  
Operations:
- Insert by order  
- Delete by position  
- Delete by key  
- Search by position  
Display after each operation.

---

### 6. Circular Single Linked List — front/rear/delete/search  
`06_circular_singly_front_rear.c`  
Operations:
- Insert front  
- Insert rear  
- Delete node with given key  
- Search by position  
Display after each operation.

---

### 7. Circular Doubly Linked List — front/rear/delete/search  
`07_circular_doubly_front_rear.c`  
Operations:
- Insert front  
- Insert rear  
- Delete by position  
- Search by key  
Display after each operation.

---

### 8. Circular Single Linked List — pos/rear/front/search(value)  
`08_circular_singly_pos_del_front_search_value.c`  
Operations:
- Insert by position  
- Delete rear  
- Delete front  
- Search for value  
Display after each operation.

---

### 9. Circular Doubly Linked List — order/rear/front/search(pos)  
`09_circular_doubly_pos_del_front_search_pos.c`  
Operations:
- Insert by order  
- Delete rear  
- Delete front  
- Search by position  
Display after each operation.

---

### 10. Infix → Postfix, then Evaluate  
`10_infix_to_postfix_eval.c`  
- Convert infix expressions (with nested parentheses) to postfix using a stack structure.  
- Evaluate the resulting postfix expression using stack.  
**Notes:** Implement a `Stack` struct and use separate stacks for conversion & evaluation.

---

### 11. Infix → Prefix, then Evaluate  
`11_infix_to_prefix_eval.c`  
- Convert infix (nested parentheses supported) to prefix using stack(s).  
- Evaluate the prefix expression.  
**Notes:** Use `Stack` struct; separate stack(s) for conversion & evaluation.

---

### 12. Dynamic Queues (Array) — Circular Queue & Deque  
`12_circular_and_deque_array_queue.c`  
- Implement Circular Queue (dynamic array)  
- Implement Double Ended Queue (Deque) (dynamic array)  
**Notes:** Define `Queue` structure and operations.

---

### 13. Dynamic Queues (Array) — Circular Queue & Priority Queue  
`13_circular_and_priority_queue_array.c`  
- Circular Queue (dynamic array)  
- Priority Queue (array-based)  
**Notes:** Define `Queue`/`PriorityQueue` structures and operations.

---

### 14. Binary Search Tree (BST) — many ops  
`14_bst_operations_count_height_maxnode.c`  
Operations:
- Construction (insert)  
- Traversals: Pre, In, Post  
- Search by key and display node + parent (if exists)  
- Count all nodes  
- Find height  
- Find node with maximum key and print node details + parent

---

### 15. BST — delete variants  
`15_bst_delete_variants.c`  
Operations:
- Construction (insert)  
- Traversals: Pre, In, Post  
- Search by key and **delete** node (handle leaf, one child, two children cases)  
**Notes:** Show correct replacement (inorder successor/predecessor) logic.

---

## ▶ How to compile and run (general)
From the program's folder or repo root:

```bash
# compile
gcc filename.c 

# run
./a.out
