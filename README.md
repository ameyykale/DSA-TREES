#Student Record Management System using Binary Search Tree (BST)

## Scenario in Brief
A large university maintains records of thousands of students from different departments such as Computer Science, Electronics, Mechanical, Civil, and Electrical Engineering. Every semester, administrators need to add new student records, search student details, update information, and remove inactive student records.

If all student records are stored in arrays or linked lists, searching for a particular student using Student ID becomes slow because the system may need to check records one by one.

To improve efficiency, the university uses a Binary Search Tree (BST) to organize student records.

In this tree:

* Each node stores:
  * Student ID
  * Student Name
  * Department
  * CGPA
* Left subtree contains smaller Student IDs
* Right subtree contains larger Student IDs
Whenever a new student joins the university, the record is inserted into the proper position in the BST. When administrators search for a student, the BST helps locate the record quickly.

### Example
Searching Student ID 1025:
1. Compare with root
2. Move left or right
3. Reach the required student quickly
The administration can also:
* Display all student records in sorted order
* Delete graduated students
* Update student information
Thus, the BST provides efficient storage and faster searching operations.
---

# Justification
Trees are suitable here because:
* BST automatically maintains records in sorted order
* Searching is faster compared to linked lists
* Insertion and deletion operations are efficient
* Large numbers of student records can be managed easily
* Inorder traversal displays students in ascending order of Student ID
Without trees:
* Searching time becomes very high
* Managing records becomes difficult
Hence, BST is ideal for student record management systems.
---

# Algorithm

## Insertion Algorithm
1. Create a new node
2. If tree is empty:
   * Make node as root
3. Otherwise:
   * Compare Student ID with current node
   * If smaller:
     * Move left
   * Else:
     * Move right
4. Repeat until correct position is found
5. Insert node

---

## Search Algorithm
1. Start from root
2. Compare target Student ID
3. If equal:
   * Student record found
4. If smaller:
   * Move left
5. If greater:
   * Move right
6. Repeat until found or NULL
---

# Time Complexity
| Operation | Time Complexity  |
| --------- | ---------------- |
| Insertion | O(log n) average |
| Searching | O(log n) average |
| Deletion  | O(log n) average |
| Traversal | O(n)             |

---
# Conclusion
The Student Record Management System using Binary Search Tree (BST) provides an efficient method for storing and managing large numbers of student records. 
BST allows faster searching, insertion, and deletion compared to linear data structures such as arrays and linked lists.

By maintaining records in sorted order automatically, the system becomes easier to manage and retrieve information quickly. Inorder traversal also helps display records in ascending order of Student ID.

Therefore, Binary Search Tree is a suitable and efficient data structure for student record management applications in universities and colleges.
