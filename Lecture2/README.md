
## Полезни материали: 

* https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/ 
* https://www.geeksforgeeks.org/linked-list-set-3-deleting-node/

## Function/Complexity matrix

|   Function    | Array (Time) | Linked List (Time) |
| ----------- | -----------     |----------- |
| insertFirst      | O(n)       |  O(1)       | 
| insertLast   | O(n)          | O(1)       | 
| insertAtIndex      | O(n)       | O(n)       | 
| insertAfter   | O(n)          | O(1)       | 
||||
| deleteFirst      | O(n)       | O(1)       | 
| deleteLast   | O(n)          | O(1)       | 
| deleteAtIndex      | O(n)       | O(n)       | 
| deleteAfter   | O(n)          | O(1)       | 
|||| 
| updateAtIndex   | O(1)         | O(n)       | 
||||
| getFirst   | O(1)             | O(1)       | 
| getLast   | O(1)              | O(1)       | 
| getAtIndex   | O(1)           | O(n)       | 

NB: ^ Не амортизирани сложности


## Домашно 

* Имплементирайте `deleteLast`  
   * Ако има време имплементирайте вариант със линейна (O(n)) сложност и вариант с константна сложност. 
* Имплементирайте `deleteAfter` 
* Имплементирайте деструктура 


