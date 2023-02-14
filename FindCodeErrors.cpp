//QUESTION 8.11
a) The pointer variable 'number' is declared but not initialized, so it points to an unknown location. Attempting to access the value at this location is undefined behavior. To correct this, initialize the pointer variable to point to a valid object before using it.

b) The assignment of the pointer of type double to a pointer of type long is invalid, as a pointer of type double can only point to objects of type double.

c) The declaration of x as an int pointer and y as an int variable is incorrect. To correct this, either declare both x and y as int pointers or both as int variables.

d) This code is correct and does not contain any errors.

e) The assignment of the short pointer 'numPtr' to a void pointer 'genericPtr' is invalid. A void pointer can be assigned to a pointer of any data type, but a pointer of a specific data type cannot be assigned to a void pointer.

f) The assignment of the address of the double variable x to a double variable xPtr is invalid. xPtr is not a pointer, so it cannot store the address of x. To correct this, declare xPtr as a double pointer and assign the address of x to it using the address-of operator '&'.
