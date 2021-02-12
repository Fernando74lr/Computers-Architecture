/ Multiply calculator
/ Reference and Explanation:  https://marie.js.org/book.pdf (Page 20)
/ Prompt user to type in integers
INPUT
Store X
INPUT
Store Y

/ Loop for performing iterative addition
loop,  Load num
       Add X
       Store num / num+=X
       Load Y
       Subt one
       Store Y / Y--
       Skipcond 400 / have we completed the multiplication?
       Jump loop / no; repeat loop
       / yes, so exit the loop
       
/ Output result to user then halt program
Load num
Output
Halt

/ Declare labels here
X, DEC 0
Y, DEC 0
one, DEC 1
num, DEC 0
