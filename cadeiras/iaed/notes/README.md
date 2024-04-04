# Intro
```c
//This is a single-line comment
/*
This is a multi-line
comment
*/

//These are libraries/dependencies
#include <stdio.h>
#include "intro.h"

//This is the main function, it exists in every c program.
int main() {
  printf("message");
  return 0;
}
```
## Data types and sizes (64 bit CPU)
```
type    bytes   bits
text
char    1       8
decimal numbers/values
short   2       16
int     4       32
long    8       64
floating numbers/values
float   4       32
double  8       64
other
pointer 8       64
```
There is also unsigned that foregoes negative values (ex: unsigned int).  

To get actual size in c:  
```c
sizeof(char);
```
You can cast a type to another:  
```c
float x;
(double) x;
```
## Variables  
```c
/* Sequence of declarations */
int superior, inferior, step;
char c, name[1000];

/* Declaration by line */
int superior;
int inferior;
int step;
char c;
char name[1000];
```
## Constants  
You can define constants as such:  
```c
#define MAX 100
enum months = {NO,YES}; //NO = 0, YES = 1.
const int x = 1;
```
Constants cannot be changed.  
## Declaration and Scope
Where you declare a variable matters.  
```c
int global; //Global variable
void example() {
  int local = 0; //Local variable
}
```
Remember that it matters if a variable is initialized with a value to prevent odd behaviour.  
In c global and static variables are initialized to 0 automatically, unless you give it another value.  
Static variables get defined once and future definitions are ignored and the value is kept.  
```c
int a, b, c;
int count() {
  static int i; //i = 0
  return ++i;
}
a = count() //a = 1
b = count() //b = 2
c = count() //c = 3
```
# Input/Output
## scanf()
Will read the first value that matches the type (decimal number in this case), from stdin, until it finds a whitespace and assigns it to a variable 
Returns how many values were read.  
```c
int x;
scanf("%d", &x);
```
## printf()
Will print into stdout.  
```c
printf("%d", x);
```
```
%02d    print decimal with at least 2 numbers and fill left with 0's
%.2f    print float with 2 floating points
%99s    read/print string with max 99 chars
%ld     long decimal
%sd     short decimal
```
## getchar()
Reads a character.
```c
char ch;
ch = getchar();
```
## Special characters
```
Character           Result
\n                  New Line
\t                  Tab
\0                  Null terminator
\\                  \
```
# Operators
```
sign        functionality
=           assignment
==          relation (equal)
!=          relation (not equal)
<           relation (smaller)
>           relation (greater)
||          or
&&          and
i++         post-increment i + 1
++i         pre-increment i + 1
```
Operators follow the general precedence rule:  
() >> Unary >> Arithmetics >> Relational >> Logic
# Vectors
## Uni-dimensional
```c
#define MAX = 10;
int vec[MAX] = {0};
vec[0] = 10;
printf("%d", vec[0]); 
//Will print 10;
```
## Bi-dimensional
```c
#define LIN 10
#define COL 10

int vec[LIN][COL];
vec[0][0] = 10;
printf("%d", vec[0][0]);
//Will print 10;
```
## Vector Initialization
```c
int example[] = {1, 2, 3}; //Length 3 with set values.
char example[][4] = {"AAA", "BBB"}; //Room for '\0' 
int example[10] = {1, 2, 3}; //Length 10 with 3 set values, rest is set to 0.
```
## Copy vectors
Vectors need to be copied position by position.  
```c
int vec1[SIZE], vec2[SIZE];
for(int i = 0; i < SIZE; i++)
  vec2[i] = vec1[i];
```
## Strings
In c strings are vectors that terminate with the char '\0'.  
```c
#define SIZE 100

char string[SIZE];
scanf("%99s", string);
//scanf doesn't null terminate a string, you need to do it.
string[SIZE - 1] = '\0';
printf("%s", string);
```
Note string doesn't need & for assignment and that the scanf size is 1 smaller than SIZE because you need to make sure there is space for '\0'.  
Also note that scanf only reads until it finds a whitespace (' ', '\t', '\n', etc).  
### String library (string.h)
You can check function docs with:  
```man <name-of-function>```
```c
#include <string.h>
```
```
function              functionality       return
strcmp(str1, str2)    compare strings     int
strcpy(str1, str2)    copy str2 to str1   char *
strdup(str)           duplicate str       char *
strlen(str)           size of str         int
```
# Conditionals and Cycles
## Conditionals
### If
```c
int val = MAX;
//executes instruction if condition is true
if(val == MAX) //val == MAX is true (1)
  printf("%d", val); //happens
```
### Switch
```c
//lets pretend getchar() returns 'q'
char c = getchar();
switch(c) {
  case 'a':
    printf("a");
    break;
  case 'q': //this is the case
    printf("q"); //this happens
    break; //this happens 
  default:
    printf("Didn't input 'a' or 'q'.");
    break;
}

```
## Cycles
### While
```c
int val = 0;
while(val < MAX) {
  printf("%d", val++);
}
```
### For
```c
for(int val = 0; val < MAX; val++) {
  printf("%d", val);
}
```
### Do-While
```c
int val = 0;
do {
  printf("%d", val++);
}
while(val < MAX);
```
## Break and Continue
The instruction 'break' terminates a cycle.  
The instruction 'continue' skips to the next iteration of the cycle.  
# Functions
Functions need to be declared before being called.   
```c
//Function declaration
void example(int x);
//Function gets called
int main() {
  example(1);
  return 0;
}
//Function definition
void example(int x) {
  function body
}
```
A function always has a return type, void means it returns nothing.  
For example main() returns an int.  
## Parameters: Value vs Reference
All arguments are copied to local variables when used.  
You never alter the original values unless you use pointers to the argument's adress.  
Note that vectors are in the general sense a pointer so any change alters the original vector. To avoid this make copies.  
# Structures
```c
#define LIC_SIZ

//Structure definition
typedef struct _car_ {
  char licence[LIC_SIZ];
  float miles;
  float price;
} Car;

//Structure declaration, all values set to 0
Car car1 = {0};

//Strucuture manipulation
car1.miles = 100.20;
printf("%.2f", car1.miles); //100.20
```
## Structure operations
```c
//Structures have to be compared per value, you can't do car1 == car2
car1.price == car2.price;

//You can copy a whole structure
car2 = car1;
//Or just a value
car2.price = car1.price;

//Functions can use and return structures
Car example(Car car1) {
  car1.price = 0;
  return car1;
}
```
# Pointers and Addresses
As the name implies pointers point at something in memory.  
```c
int x = 0;
int *p_x = &x;
*p_x == 0; //true
```
int * signifies a pointer to an integer.  
& signifies the memory address of something.  
Pointers are normally named pX or p_x or xPtr (for x).  
In the example above the pointer p_x that points to an integer (int *), is pointing at the address of x (&x).  
*p_x is called dereferencing a pointer. It allows us to get/set the values of what it is pointing at.
## Pointers and functions
```c
int x = 1, y = 2;
swap(x, y);
void swap(int a, int b) {
  int tmp;
  tmp = a;
  a = b;
  b = tmp;
}
```
The above example won't do anything. x == 1 and y == 2. But with pointers and addresses this changes.  
```c
int x = 1, y = 2;
swap(&x, &y);
void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
```
Now the values will swap. x == 2, y == 1.  
## NULL pointer
```c
#include <stdlib.h>
int *ptr = NULL;
```
Special pointer that means this pointer points at nothing.  
## Pointer declaration
As seen before vectors are similar (not exactly the same) to pointers. As such a pointer can be declared as such.  
```c
char *ex1 = "hello";
char ex2[] = "hello";
```
Both allocate 5 bytes for 'h', 'e', 'l', 'l', 'o', '\0'.  
Main diference being that you can´t change where ex2 points to since it's a fixed vector, but you can still change values like ex2[0] = 'H'.  
## Pointer aritmethics
```c
int vec[3] = {1, 2, 3};
int *p_vec = vec;
vec[1] == *(vec + 1); //True, value is 2
*(p_vec + 1) == 2; //True
```
# Dinamic Memory Allocation
Up to now we've been using static memory, for example:
```c
Car vec[100];
```
This will allocate a block of memory with 100 sizeof(Car).  
But we could also use dinamic allocation to alocate Car blocks as we need them.  
## malloc(quantity * size)
Allocates memory.  
```c
#include <stdlib.h>
Car *car1 = malloc(sizeof(Car)); //for 1 Car, note Car is a struct
Car *car_block = malloc(100 * sizeof(Car)); //allocate a block of 100 Car
```
### Malloc verification
A malloc can change for many reasons such as memory fragmentation or lack of memory, so we need to check if it worked.
```c
if(car1 == NULL)
  exit(-1); //Exit program, or handle the error in any way you want
if(!car_block) { //Can evaluate with the ! operator
  free(car1); //Don't forget to free other mallocs
  exit(-1);
}
```
## free(pointer)
Frees allocated memory so it can be re-used. This is very important because allocated memory with malloc that is not free will cause memory leaks.  
This is the reason why it's important to not lose or reasign a pointer to a malloc before freeing it.  
```c
#include <stdlib.h>
free(car1);
car1 = NULL;
free(car_block);
car_block = NULL;
```
IMPORTANT: Every malloc will need it's respective free at some point in the program's run.  
## realloc(pointer, quantity * size)
Resize the malloc. It can be smaller or bigger than the size of the original malloc.  
Just like malloc you need to check if a realloc failed.  
```c
#include <stdlib.h>
Car *car_block = malloc(100 * sizeof(Car));
Car *temp = realloc(car_block, 50 * sizeof(Car));
if(!temp) {
  free(car_block);
  exit(-1);
} else 
  car_black = temp;
```
As seen above, if the realloc succeeded we don't need to free car_block because realloc will do the free itself.  
## calloc(quantity, size)
Calloc is a malloc that is initiated to 0.  
It is equivalent to doing a memset after a malloc.  
```c
Car *car_block = calloc(100, sizeof(Car));
```
## memset(pointer, value, size)
Set the memory pointed by pointer to value for the size in bytes.  
```c
#include <string.h>
memset(car_block, 0, 50 * sizeof(Car)) //Set the first 50 cars to 0 in memory
```
## Pointers and Structures
This is the car structure:  
```c
typedef struct _car_ {
  char licence[9];
  float price;
} Car;
```
You can use a pointer to point at a structure and change/use it's values.  
```c
Car car1 = {0};
Car *p_car1 = &car1;
(*p_car1).price = 10.10; //using * dereferencing anotation
p_car1->price = 10.10; //using -> dereferencing anotation
```
One of the reasons why this is so important is the before mentioned passing of arguments to functions.  
```c
void changeCarPrice(Car car, int new_price);

Car car1 = {0};
float price = 10.10;
changeCarPrice(&car1, price);

void changeCarPrice(Car *p_car, int new_price) {
  p_car->price = new_price;
}
```
This way you can change the price of the car, while without pointers (*) and addresses (&) you would just be passing values and wouldn't be able to change the price of car1.  
# Linked Lists
## Advantages & Disadvantages
Advantages  
- Don't need to reserve big blocks of continuous memory like in arrays.  
- Can be as long as you want. 
- Can be as short as you need.   
Disadvantages  
- Have to go through the whole list to reach the Nth element.  
- To know how many elements a list has you either have to keep count or count it every time.

## List Structures
Let's again revisit the Car structure but for use with linked lists.  
```c
//Single linked list
typedef struct _car_ {
  char licence[9];
  float price;
  //We need to use struct _car_ because the definition Caris only done at the end of the struct definition
  struct _car_ *next; //Added so we can point at the next car
} Car;

//Double linked list
typedef struct _car_ {
  char licence[9];
  float price;
  //We need to use struct _car_ because the definition Caris only done at the end of the struct definition
  struct _car_ *next; //Added so we can point at the next car
  struct _car_ *prev; //Added so we can point at the previous car
} Car;
```
To work with lists you would need a pointer normally called 'head' to point at the start of the list.  
Sometimes a 'tail' is also useful if you want to add elements to the end of the list.  
```c
typedef struct _car_list_ {
  Car *head; //Points to the first element of the list
  Car *tail; //Points to the last element of the list. Not required.
} Car_List;
```
## List operations
### Length
```c
int length(Car *head) {
  int count = 0;
  Car *car = head;
  while(car != NULL) {
    count++;
    car = car->next;
  }
  return count;
}
```
### Insertion
#### Tail Insertion
```c
//Single linked list
void insert(Car_List *car_list, Car *car) {
  if(!car_list->head)
    car_list->head = car; //Insertion at head on empty list
  else
    car_list->tail->next = car; //Add car after the previous tail
  car_list->tail = car; //Update tail
}
```
#### Head Insertion
```c
void insert(Car_List *car_list, Car *car) {
  car->next = car_list->head;
  car_list->head = car;
  if(car->next == NULL)
    car_list->tail = car;
}
```
### Print List
```c
void print(Car *head) {
  link t;
  for(t = head; t != NULL; t = t->next)
    printf("%s", t->licence);
}
```
### Delete 
```c
#include <string.h>
void delete(Car_List *car_list, char *licence) {
  Car *head = car_list->head;
  Car car, prev;
  for(car = head, prev = NULL; car != NULL; prev = car, car = car->next) {
    if(strcmp(car->licence, licence) == 0) {
      if(car == head)
        head = car->next;
      else
        prev->next = car->next;
      free(car);
      break;
    }
  }
  car_list->head = head;
}
```
# Hash Tables
Hash tables exist so we can access stored values at constant time.  
The value you want to store goes through a hashing algorithm to become a index on a table.  
## Hash function
Hash function:  
- fast to calculate.  
- include all bits of the key.  
- destribute the hashed information in a uniform almost random way. The ideal hash function would have 0 collisions.    
```c
int hash_func(int value, int M) {
  return value % M;
}
```
This is obviously a terrible hash function because it will create lots of collisions.  
'M' represents the size of the hash table and because you need an index between 0 and M, you have to always use the % operand.  
This example hashes an int, but you can hash any data by using a function that suits it.  
## Collisions
Collisions occur when 2 different values end up with the same index value after being hashed.
```c
int hash(int n, int size) {
  return n % size;
}
//For a hash table of size 100
int n = 100, m = 200;
int hash_n = hash(n, 100);
int hash_m = hash(m, 100); 
```
In the example, both hash_n and hash_m will be 0.  
This is a collision.  
### Collision resolution
We will see 3 ways:
- Seperate Chaining (Encadeamento Externo)  
- Linear Probing (Procura Linear)
- Double Hashing  
#### Seperate Chaining
With seperate chaining each index of the hash table holds a pointer that works as a linked list head. 
When there is a conflict you insert the new item in the linked list.  

To find a value on the table you get the hash value and go through the linked list.  

To remove a value from the table it's the same as finding a value but instead you remove it from the linked list.  

So, after hashing, you use linked list operations to manipulate it's elements.  
#### Linear Probing
With linear probing each index of the hash table holds an element.  
If there is a conflict we move to the next index (i++) and if it is empty we insert the element at that index.  

To search for a value, you go to the hash index and then check every index after that until you find the element or an empty table index.  

To remove a value it's much like searching except you remove that value from the index if you find it. Remember to set that table's value to NULL or similar values.
After removing the value you have to re-hash all the values after the removed values until you find an empty index.  
#### Double Hashing
Double hashing uses more less the same way of inserting values into the table but instead of checking the next index after a collision, it uses a second hashing function to calculate the step.  
This step is calculated using the index value so every element that collided will have the same step value.  
It then checks the index of the original hash function plus the step from the second hashing until it finds an empty index. This step should always be obtained using a prime and never match the size of the table.  
To check a value you use the first hash result and then the step.  
When you remove a value you have to rehash all elements from the list that are x steps from the index until you find an empty step.  
### Advantages & Disadvantages
Seperate Chaining 
- Advantages
  - Easier to use linked list operations
  - No need to recalculate hash values on removal
- Disadvantages
  - More memory usage due to linked lists  

Linear Probing
- Advantages
  - Less memory usage
  - Simple implementation
- Disadvantages
  - Clustering, indexes tend tobe filled in clusters  

Double Hashing
- Advantages
  - Less memory usage
  - Most efficient of the 3 at finding a value
  - Less clustering than linear probing  
- Disadvantages
  - More complex implementation
In general
- Advantages
  - In general element search/insertion is done at constant complexity, but in extreme edge cases it'll still be linear
- Disadvantages
  - Hashing can be computationally heavy
  - It uses much more memory than other methods like linked lists

## Efficiency - Dinamic tables
As the table fills the amount of misses increases as more and more conflicts happen. This decreases the efficiency of the table.  
For this reason when the table reaches a certain threshhold (normally 50%), the table is resized to double it's current size.  
When we do this we have to re-hash all the elements of the table using the new table size for the % operation.  
```
Linear Probing
occupancy       0.5       0.667     0.75      0.9
hit             1.5       2.0       3.0       5.5
misses          2.5       5.0       8.5       55.5
```
```
Double hashing
occupancy       0.5       0.667     0.75      0.9
hit             1.4       1.6       2.8       2.5
misses          1.5       2.0       3.0       5.5
```