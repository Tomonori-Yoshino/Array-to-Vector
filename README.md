# Array-to-Vector
Make array as functional as std::vector.




# Elastic Array
The class of "ElasticArray" has a dynamic array as a private attribute as well as its logical size and physical size. The array is dynamically allocated by users at runtime with/without given size and will be deallocated when the program ends. This calss is also copyable and assignable.


# Similar functionality as a vector
The object of ElasticArray does not need to know its physical size when created like a vecor. It can grow or shrink on demand ar runtime as using push_back() or pop_back() public method.


