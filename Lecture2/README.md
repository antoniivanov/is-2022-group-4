
## Полезни материали: 

* https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/ 
* https://www.geeksforgeeks.org/linked-list-set-3-deleting-node/

## Function/Complexity matrix

|   Function    | Array (Time) | Linked List (Time) |
| ----------- | -----------     |----------- |
| insertFirst      | O(n)       |  **O(1)**       | 
| insertLast   | O(n)          |  **O(1)**       | 
| insertAfter   | O(n)          |  **O(1)**       | 
| insertAtIndex      | O(n)       | O(n)       | 
||||
| deleteFirst      | O(n)       |  **O(1)**       | 
| deleteLast   | O(n)          |  **O(1)**       |  
| deleteAfter   | O(n)          |  **O(1)**       | 
| deleteAtIndex      | O(n)       | O(n)       |
|||| 
| updateAtIndex   |  **O(1)**      | O(n)       | 
||||
| getFirst   |  **O(1)**           |  **O(1)**       | 
| getLast   |  **O(1)**              |  **O(1)**       | 
| getAtIndex   |  **O(1)**           | O(n)       | 

NB: ^ Не амортизирани сложности


## Домашно 

* Имплементирайте `deleteLast`  
   * Ако има време имплементирайте вариант с линейна (O(n)) сложност и вариант с константна сложност. 
* Бонус - Имплементирайте `deleteAfter` 
* Бонус - Имплементирайте деструктура 


