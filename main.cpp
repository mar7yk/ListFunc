/*!
 * \mainpage ListFunc documentation
 * \author Martin Kostov
 * \version 1.0.0
 * \date 2022-08-11
 * \section intro_sec Introduction
 * The project is an interpreter of the ListFunc functional language.
 * \section p1 Definition of ListFunc
 * <real-number> ::= <all valid entries of double>\n
 * <list-literal> ::= [ [<expression0>, <expression1>, ...] ]\n
 * <expression> ::= <list-literal> | <real-number> | <function-call>\n
 * <function-name> ::= <valid identifier in C++>\n
 * <function-call> ::= <function-name>( [<expression>, ...] )\n
 * <param-expression> ::= <expression> | #integer |\n
 * <function-name>([<param-expression>,...])\n
 * <function-declaration>::= <function-name> -> <param-expression>\n
 * \section p2 Built-in functions
 * - eq(#0, #1) returns the boolean value of #0 == #1 \n
 * \- two numbers are equal when their values are equal\n
 * \- two lists are equal when their corresponding elements are equal\n
 * \- a number and a list are equal if the list has 1 element and it is equal to the number
 * - le(#0, #1) returns the boolean value of #0 < #1
 * - nand(#0, #1) returns the boolean value of !#0 || !#1
 * - length(#0) returns the number of elements in the given list, or -1 if the argument is a number
 * - head(#0) returns the first element of a list
 * - tail(#0) returns a list of all but the first element of the input list
 * - list(#0) returns an infinite list with starting element #0 and step 1
 * - list(#0, #1) returns an infinite list with starting element #0 and step #1
 * - list(#0, #1, #2) returns a list with start element #0, step #1, and number of elements #2
 * - concat(#0, #1) returns a list, the concatenation of the two arguments, which are lists
 * - if(#0, #1, #2) evaluates to #0 as a boolean and returns #1 if it evaluates to true or #2 if it evaluates to false
 * - read() returns a number read from standard input
 * - write(#0) writes #0 to standard output and returns 0 on success and a non-0 number on failure
 * - int(#0) returns #0 without the fractional part
 * - add(#0, #1) returns value of #0 + #1
 * - sub(#0, #1) returns value of #0 - #1
 * - mul(#0, #1) returns value of #0 * #1
 * - div(#0, #1) returns value of #0 / #1
 * - mod(#0, #1) returns value of #0 % #1
 * - sqrt(#0) returns root of #0
 * \section p3 Examples
 * > //enter number\n
 * > \> 32\n
 * > 32\n
 * > \n
 * > //enter list\n
 * > \> [1 2 3]\n
 * > [1 2 3]\n
 * > \n
 * > //use custom\n
 * > \> myList -> [3 4 5 7 9 10]\n
 * > 0\n
 * > \> head(myList())\n
 * > 3\n
 * > \> tail(myList())\n
 * > [4 5 7 9 10]\n
 */

#include "src/Engine.hpp"

int main() {
    Engine engine;
    engine.run();
}

