# NOTES

This file contains all my notes for this program. I feel comments is inefficient for anything other than 'TODO's and such.

1. All functions except addition do not work. Addition works - to an extent. I am still finding bugs and errors which I have to fix before I transfer the code of addition to everything else. This is getting super complex ngl.

2. As a reminder, we changed some code in the while loop on line 278 (currently) to fix a problem with it. We also changed a lot of code in the addition function in which you have to transfer most changes to the other functions. One thing I remember is you just returned the 'linearEquationN' when there is one variable. This was because you cannot add a variable and a normal number. The same should be done for subtraction.

3. There is an error when operating on variables and normal numbers in one side. Ex: `4x + 3 + 5x` will return with an infinite loop. This is because when operating on `4x + 3` it returns the same, and when operating on `3 + 5x` it returns the same. We have to make it so that the each variable is added with all the other variables in the expression, except the ones before it. Only the ones after.

# IDEAS

1. For Notes #3 a solution could be where in the function itself you loop the program to continuously find new second numbers to add with and you do that till you reach the end of the expression. When replacing the original numbers with the new number, you have to delete the second variable and replace the first with the new variable, or if you are adding a non variable number and a variable number you have to return the equation itself
