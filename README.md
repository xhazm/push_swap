# push_swap - 42 Heilbronn (December 2021)
Because swap_push isn’t as natural<br>

The program push_swap will sort random integers on a stack, with a limited set of instructions, trying to use the least stack operations to get an ascending sorted stack.<br>

## Usage:
1. Clone it like this:<br>
`git clone`
2. Compile the program:<br>
`make all`
3. Execute the program:<br>
`./push_swap [Numbers to sort separated by space]`
You can put in any amount of numbers. The programm will then print the actions needed to sort the numbers.
4. Check if right actions were used<br>
`./push_swap [Numbers to sort separated by space] | ./checker [Numbers to sort separated by space]`
If it displays OK everything worked fine!


## "Game Rules"

<b>The game is composed of 2 stacks named A and B.</b>

<b>Starting Point:</b>
- Stack_A contains random numbers of either positive or negative numbers without any duplicates.
- Stack_B is empty

<b>The goal is to sort in ascending order numbers into stack.</b>

<b>The operations the program can do, are limited to the following set:</b>

| Operations    | Description                                                                           |
| ------------- | --------------------------------------------------------------------------------------|
| <b>sa</b>     | swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements) |
| <b>sb</b>     | swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements) |
| <b>ss</b>     | sa and sb at the same time |
| <b>pa</b>     | push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty |
| <b>pb</b>     | push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty |
| <b>ra</b>     | rotate a - shift up all elements of stack a by 1. The first element becomes the last one |
| <b>rb</b>     | rotate b - shift up all elements of stack b by 1. The first element becomes the last one |
| <b>rr</b>     | ra and rb at the same time |
| <b>rra</b>    | reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one |
| <b>rrb</b>    | reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one |
| <b>rrr</b>    | rra and rrb at the same time |


## How does it work?
The algorithm starts by first using the LIS-Algorithm [LIS-Algorithm](https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/) on the aStack, if the Stack has <50 numbers.<br>
After the LIS-Check the non-LIS numbers will be pushed to bStack, pre-sorted in 3-4 chunks.<br>
The last Algorithm is an [Insertion-Sort](https://www.geeksforgeeks.org/insertion-sort/). The algorithm loops through the numbers of bStack and looks for the least needed operations to push a number from bStack to the right place on the aStack.<br>



###### For more information look into the [subject pdf](docs/push_swap_subject.pdf)

<b>*All 42 projects must be written in C (later C++) in accordance to the 42 School Norm.<br></b>
<br>

> #### Sample restrictions:
> - All variables have to be declared and aligned at the top of each function
> - Each function can not have more then 25 lines
> - Projects should be created with allowed std functions otherwise it is cheating
