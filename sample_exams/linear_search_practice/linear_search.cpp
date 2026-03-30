// linear_search.cpp

//
// The following is a series of questions and about linear search.
//

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

// 1. The Basic Search Question: Write a function linearSearch that takes an
//    integer array, its size, and a target value. Return the index of the
//    target if it exists, or -1 if it doesn't.

// ...

// void test_linearSearch()
// {
//     int a1[] = {3, 1, 4, 1, 5};
//     assert(linearSearch(a1, 5, 4) == 2);
//     assert(linearSearch(a1, 5, 3) == 0);
//     assert(linearSearch(a1, 5, 99) == -1);

//     int single[] = {42};
//     assert(linearSearch(single, 1, 42) == 0);
//     assert(linearSearch(single, 1, 0) == -1);

//     int empty[] = {};
//     assert(linearSearch(empty, 0, 5) == -1);
// }

// 2. Searching for Strings Question: Adapt the previous logic to search for a
//    specific std::string within a std::vector<string>. Return a boolean (true
//    or false) indicating if the name exists in the list.

// ...

// void test_isNameInList()
// {
//     const std::vector<std::string> names = {"Ada", "Grace", "Alan"};
//     assert(isNameInList(names, "Grace") == true);
//     assert(isNameInList(names, "Ada") == true);
//     assert(isNameInList(names, "Nobody") == false);

//     const std::vector<std::string> empty;
//     assert(isNameInList(empty, "Ada") == false);
// }

// 3. Finding Multiple Occurrences Question: Sometimes a value appears more than
//    once. Write a function that finds a target integer and returns a
//    std::vector<int> containing all indices where that target was found. If
//    not found, the vector should be empty.

// ...

// void test_findAllIndices()
// {
//     int dup[] = {1, 2, 1, 3, 1};
//     assert(findAllIndices(dup, 5, 1) == std::vector<int>({0, 2, 4}));
//     assert(findAllIndices(dup, 5, 3) == std::vector<int>({3}));
//     assert(findAllIndices(dup, 5, 9).empty());

//     int empty[] = {};
//     assert(findAllIndices(empty, 0, 1).empty());
// }

// 4. Searching Objects (Structs) Question: Create a Student struct with a name
//    and an id. Write a function that searches an array of Student objects by
//    id and returns the name of the student. Return "Not Found" if the ID
//    doesn't exist.

// ...

// void test_findStudentById()
// {
//     Student roster[] = {{101, "Alice"}, {202, "Bob"}, {303, "Carol"}};
//     assert(findStudentById(roster, 3, 202) == "Bob");
//     assert(findStudentById(roster, 3, 101) == "Alice");
//     assert(findStudentById(roster, 3, 999) == "Not Found");

//     Student none[] = {};
//     assert(findStudentById(none, 0, 1) == "Not Found");
// }

// 5. The "Last Occurrence" Variation Question: In some cases, you need the most
//    recent entry. Write a function that performs a linear search but returns
//    the index of the last occurrence of the target value instead of the first.
//    Hint: Think about which direction you should loop.

// ...

// void test_findLastOccurrence()
// {
//     int dup[] = {1, 2, 1, 3, 1};
//     assert(findLastOccurrence(dup, 5, 1) == 4);
//     assert(findLastOccurrence(dup, 5, 2) == 1);
//     assert(findLastOccurrence(dup, 5, 3) == 3);
//     assert(findLastOccurrence(dup, 5, 99) == -1);

//     int single[] = {7};
//     assert(findLastOccurrence(single, 1, 7) == 0);

//     int empty[] = {};
//     assert(findLastOccurrence(empty, 0, 1) == -1);
// }

int main()
{
    // test_linearSearch();
    // test_isNameInList();
    // test_findAllIndices();
    // test_findStudentById();
    // test_findLastOccurrence();
    // std::cout << "All linear search tests passed.\n";
}
