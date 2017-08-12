# ELUM Technical Test


Subject: 
 
 Create a program which takes in a series of up to 8 strictly positive integers followed by an expected result. Ex:
 
./lceb 42 2 87 3 1 10  1337

The program must use all the numbers and basic operators ( + ,  - ,  \* ,  / ) and determine the expression which gives the last number as a result. It will be displayed as follows:

87 + (42 x 3 - 1) x 10 = 1337

* Each number may only be used once.
* Division is only authorized when there are no leftovers.
* Inform the user when no solution exists.
* Only one solution is required.
* Single thread.

My methodology:

Use Reverse Polish Notation (RPN) and backtacking to determine a valid solution if one exists.
Transform the RPN expression using a binary tree into a normal mathematical expression.

Please note: I am using an older version of gcc at school, error flags may not find all the errors that are found in more recent versions.
