/**
 *******************************************************************************
 * @file    test.cpp
 *
 * This file is designed to test the functionality of "ElasticArray" class.
 *
 * @remarks
 *      Course:        Computer Science nnnn, Spring 2018
 *      Assignment #:  03
 *      Due Date:      Tuesday, Feb 13
 *      Instructor:    Dr. Causey
 *
 * @author        Tomonori Yoshino
 * @date          February, 11
 *******************************************************************************
 */
#include "ElasticArray.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;





void test_ElasticArray_copy_ctor(ElasticArray a)
{
    for(int i = 0; i < a.size(); ++i)
    {
        a.at(i) = 999;  // just a value that will be easy to notice when printed.
    }
}





int main()
{
    
    ElasticArray testArray{5};
    
    cout << "Assign all elements to be 10 and display the array: \n";
    for (int i = 0; i < 5; i++)
    {
        testArray.push_back(10);
    }
    
    
    for (int i = 0; i < testArray.size(); i++)
    {
        cout << endl << testArray.at(i) << endl;
    }
    
    cout << "current size: "
         << testArray.size();
    
    cout << "\n20 is added to the endl of the array.\n";
    testArray.push_back(20);
    
    for (int i = 0; i < testArray.size(); i++)
    {
        cout << endl << testArray.at(i) << endl;
    }
    
    cout << "current size: "
         << testArray.size();
    
    cout << "\nAssign 30 elements and display the array: \n";
    for (int i = 0; i < 30; i++)
    {
        testArray.push_back(30);
    }
    
    for (int i = 0; i < testArray.size(); i++)
    {
        cout << endl << testArray.at(i) << endl;
    }
    
    cout << "current size: "
         << testArray.size();
    
    cout << "\nThe first element: " << testArray.front();
    cout << "\nThe last element: " << testArray.back();
    
    cout << endl << "pop_back method is uded...\n"
         << testArray.pop_back() << "\ncurrent size: " << testArray.size();
    
    
    
    
    
    ElasticArray source_array{5};
    ElasticArray destination_array{5};
    
    for(int i = 0; i < 5; ++i)
    {
        source_array.push_back(i + 1); // fills with {1,2,3,4,5}
    }
    

    
    // Try to copy:
    destination_array = source_array;    // doesn't do what you want it to do...
    

    
    // change the supposed "copy":
    for(int i = 0; i < destination_array.size(); ++i)
    {
        destination_array.at(i) *= 2;      // double all the values in the "copy"
    }
    
    // Now let's have a look at the original array. (It *should* be the same
    // as before... but is it?)
    cout << "Original array should be:\n";
    cout << "1\t2\t3\t4\t5\n";
    cout << "It is:\n";
    for(int i = 0; i < source_array.size(); ++i)
    {
        cout << source_array.at(i) << '\t';
    }
    cout << endl << "Test the copy constructor.\n";
    
    
    
    test_ElasticArray_copy_ctor(source_array);
    
    for(int i = 0; i < source_array.size(); ++i)
    {
        cout << source_array.at(i) << '\t';
    }
    cout << endl;
    
    
    ElasticArray test1{5};
    ElasticArray test2{5};
    
    for (int i = 0; i < 5; i++)
    {
        test2.push_back(i+1);
    }
    
    test1 = test2;
    
    for (int i = 0; i < 5; i++)
    {
        test1.at(i) = (i+1)*2;
    }
    
    cout << endl << "test1: \n"; //2,4,6,8,10
    
    for (int i = 0; i < 5; i++)
    {
        cout << '\t' << test1.at(i);
    }
    
    cout << endl << "test2: \n"; //1,2,3,4,5
    for (int i = 0; i < 5; i++)
    {
        cout << '\t' << test2.at(i);
    }
    
    ElasticArray test3;
    ElasticArray test4;

    test3 = test4 = test1;
    
    
    for (int i = 0; i < 5; i++)
    {
        test3.at(i) = (i+1)*5;
    }
    
    cout << endl << "test3: \n"; //10,20,30,40,50
    for (int i = 0; i < 5; i++)
    {
        cout << '\t' << test3.at(i);
    }
    
    test_ElasticArray_copy_ctor(test4);
    test4.shrink_to_fit();
    cout << endl << "test4: \n"; //2,4,6,8,10
    for (int i = 0; i < 5; i++)
    {
        cout << '\t' << test4.at(i);
    }
    
    ElasticArray test5{100};
    
    for (int i = 0; i < 50; i++)
    {
        test5.push_back(i+1);
    }
        
    cout << endl << "the logical size: " << test5.size();
    cout << endl << "the physical size: " << test5.max_size();
    
    cout << endl << "Shrink method is used....";
    test5.shrink_to_fit();
    
    cout << endl << "the logical size: " << test5.size();
    cout << endl << "the physical size: " << test5.max_size();
    return 0;
}











