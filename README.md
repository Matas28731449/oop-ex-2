# oop ex. 1

**v0.4**

Key functions have been developed such as:

- Random data `file generator` has been created ;

- The data is `sorted` into two categories (fail, when `final mark < 5`, pass, when `final mark >= 5`) when reading from file ;

- Sorted data is `outputted` into two `separate files` (fail.txt, pass.txt) ;

- `Performance analysis` of the program was `performed` with randomly generated data :

| Size / Time | Generating | Program  | Reading  | Sorting  | Splitting | Writting `fail.txt` | Writting `pass.txt` |
|-------------|------------|----------|----------|----------|-----------|---------------------|---------------------|
| 1000        | 0.008479   | 0.015679 | 0.008904 | 0.000831 | 0.000393  | 0.000965            | 0.001039            |
| 10000       | 0.059719   | 0.079423 | 0.056246 | 0.009038 | 0.002437  | 0.006754            | 0.004946            |
| 100000      | 0.819158   | 0.737159 | 0.539071 | 0.079809 | 0.020125  | 0.048631            | 0.049521            |
| 1000000     | 5.41331    | 6.914894 | 4.99238  | 0.882479 | 0.171598  | 0.424164            | 0.444273            |
| 10000000    | 44.9806    | 75.81039 | 54.6486  | 11.4163  | 2.76528   | 3.53575             | 3.44446             |

**v0.3**

Updates from previous version:

- `Refactored` the `code`: created `separate headers` for functions and references ;

- `Makefile` has been created for easier multiple file compiling ;

- Applied `exception handling` when trying to read from file .

**v0.2**

Key functions have been developed such as:

- `Reading` from a `file` (the user can indicate which file to read from) ;

- Students are `sorted` by name (or surname) when reading from a `file` ;

- Added a `timer to track the work` of various functions when reading from a file ;

- `Optimized` other `functions` from the previous version .

**v0.1.1**

Updates from previous version:

- `Dynamism applied` in *v0.1 with arrays* when entering students (it is no longer necessary to specify the initial number of students to be entered) ;

- Standard `sort()` function and `? :` operator `applied` when calculating the median ;

- `Improved randomization` function to generate appropriately distributed grades .

**v0.1**

Key functions have been developed such as:

- The user can `enter` the data `manually` or let the system `randomly` select the required input ;

- The user can `select` to calculate the final mark using either `the mean` or `median` .
