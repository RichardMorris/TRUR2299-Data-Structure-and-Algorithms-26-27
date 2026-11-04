# Lesson 5 Arrays 

## Arrays 1D

In C an array is just a block of memory, elements in the array are stored in multiple bytes. The size of the block
of memory depends on the number of elements
and the size of the element.

### Recap on Integer data types 
* `char`/`signed char`   - 1 byte¹, -128 to 127
* `unsigned char` - 1 byte , 0:255
* `short`/`short int` - 2 bytes¹, 16 bit, 
-32768 to 32767
* `unsigned short` - 2 bytes¹, 16 bit, 
0 to 65536 
* `long`/`long int`  - 4 byte¹, 32-bit, -2147483648 to 2147483647
* `unsigned long`  - 4 byte¹, 32-bit, 0 to 4294967296
* `long long`/`long long int` - 8 byte, 64-bit, -9223372036854775808 to 9223372036854775807
* `unsigned long long` - 8 byte¹, 64 bit, 0 to 18446744073709551616
* `int` - size is implementation defined, at least 16-bit, a source of bugs
* `int32_t`, `int64_t` - defined by macros to have exactly this size.

The size of the data type can be found with `sizeof(int)` etc.

Notes
* ¹ - technically these a minimum sizes

### Memory allocation

Arrays can be stored in different areas of memory, 
* in the global memory allocated when the the program starts, 
* on the stack, allocated as a local varable in a function, only usable in that function's scope, so can't be used by the parent function
* on the heap, allocated using `malloc` avaliable until a manual call to `free`.

### Array decleration 

* fixed size array with initial values
`int32_t arr1[6] = {1, 2, 3, 4, 5, 6};` 
* fixed size array with values uninitialised
`int32_t arr1[6];`
* Dynamically created, stored as a pointer to first element
`int32_t *heap = (int32_t*)malloc(6 * sizeof(int32_t));`
* Dynamically created, stored as a pointer to first element, initialised to zero
`int32_t *zeros = (int32_t*)calloc(6, sizeof(int32_t));`

### Acessing elements

Both array subscript notation `stack[i]`, and pointer notation `*(stack + i)` can be used to access elements. The compiler is clever enough to use the size of the data type to find the memory location.

## Arrays 2D

I received message from a friend with an interview question.

"You have an array of 10,000 x 10,000 32-bit signed integers. For whatever reason, you want to produce a 64-bit sum. Do you:
1. Write a pair of nested loops of the form "for (x = 0, sum = 0; x < 9999; x++) for (y = 0; y <= 9999; y++) sum += array[x][y];"
2. Write a pair of nested loops of the form "for (y = 0, sum = 0; y < 9999; y++) for (x = 0; x <= 9999; x++) sum += array[x][y];"
3. Something else...

Is there any difference in speed between 1. and 2.? Explain your answer.
If 3., explain your answer, and justify in terms of whether or not there is any difference in speed between 1. and 2., and how that affects your answer.
