# oop ex. 1

**Installation process:**

Clone my GitHub repository: `git clone https://github.com/Matas28731449/oop-ex-2.git` ;

Navigate to cloned repository: `cd {folder name}/oop-ex-2/vector` ;

Compile the files via Makefile: `make` ;

Run the program: `./main` ;

Follow the instructions, <b style="color: blue">happy using!</b>

**v1.2**

Updates from previous version:

- Expanded main class capabilities, initialized `"rule of five"` .

**v1.1**

Updates from previous version:

- `Applied classes` throughout the code (removed structs) ;

- `Performance analysis` of the program was `performed` with `std::vector` container and the `fastest strategy` :

*3rd strategy, std::vector container, -O3 flag (1.000.000 students):*

| Type / Time | Program   |
|-------------|-----------|
| *class*     | 6.1236323 |
| *struct*    | 5.6552146 |

*3rd strategy, std::vector container, -O3 flag (10.000.000 students):*

| Type / Time | Program   |
|-------------|-----------|
| *class*     | 61.342183 |
| *struct*    | 59.114327 |

- `Experimental analysis` was `performed` depending on compiler `optimization flags`:

*Optimization flags analysis (10.000.000 students):*

| Flag / Time | Program    | / .exe size |
|-------------|------------|-------------|
|             | 209.304579 | 215KB       |
| -O1         | 113.836258 | 145KB       |
| -O2         | 62.164601  | 118KB       |
| -O3         | 61.414359  | 118KB       |

**v1.0.1**

Updates from previous version:

- Strategy 3 has been added with the `specified algorithms` ;

*3rd strategy (10.000.000 students):*

| Type / Time   | Splitting |
|---------------|-----------|
| *std::deque*  | 0.700288  |
| *std::list*   | 3.86502   |
| *std::vector* | 0.845625  |

- The `3rd strategy` is `faster using std::vector` compared to the previous two .

**v1.0**

Splitting into two containers uses 2 new strategies:

- Strategy 1 creates `two` independent `containers` and splits students between them (memory consuming) ;

- Strategy 2 `reuses` the `main container` for unsuccessful students and `creates a single container` for successful students ;

*2nd strategy (10.000.000 students):*

| Type / Time   | Splitting |
|---------------|-----------|
| *std::deque*  | 0.273107  |
| *std::list*   | 1.88668   |
| *std::vector* | 2.16433   |

*1st strategy (10.000.000 students):*

| Type / Time   | Splitting |
|---------------|-----------|
| *std::deque*  | 0.954878  |
| *std::list*   | 3.99397   |
| *std::vector* | 2.75432   |

- The `2nd strategy` is more rational, since the program `performs faster` and consumes `2x less memory` .

**v0.5**

Performance analysis of the program was performed with `std::vector`, `std::list`, `std::deque` containers:

- `Three` separate `programs` have been created with their `corresponding containers` ;

- Tested with my personal computer (`1,6 GHz` Dual-Core Intel Core `i5` / `8 GB` 1600 MHz DDR3 / 128 GB `SSD`) :

*std::deque*

| Size / Time | Program   | Reading  | Sorting  | Splitting |
|-------------|-----------|----------|----------|-----------|
| 1000        | 0.011421  | 0.009889 | 0.001336 | 0.000195  |
| 10000       | 0.087951  | 0.073614 | 0.013391 | 0.000944  |
| 100000      | 1.051615  | 0.884327 | 0.148934 | 0.018354  |
| 1000000     | 7.068945  | 5.49479  | 1.47893  | 0.095225  |
| 10000000    | 59.157223 | 40.5008  | 17.6992  | 0.957223  |

*std::list*

| Size / Time | Program  | Reading  | Sorting  | Splitting |
|-------------|----------|----------|----------|-----------|
| 1000        | 0.013624 | 0.012653 | 0.000671 | 0.000299  |
| 10000       | 0.111652 | 0.100006 | 0.008476 | 0.003169  |
| 100000      | 1.039293 | 0.917151 | 0.089819 | 0.032322  |
| 1000000     | 8.727799 | 7.159    | 1.24516  | 0.323639  |
| 10000000    | 73.5484  | 53.7107  | 16.5857  | 3.252     |

*std::vector*

| Size / Time | Program  | Reading  | Sorting  | Splitting |
|-------------|----------|----------|----------|-----------|
| 1000        | 0.017851 | 0.017234 | 0.000417 | 0.000199  |
| 10000       | 0.092879 | 0.083231 | 0.007869 | 0.001778  |
| 100000      | 0.768513 | 0.658374 | 0.08578  | 0.024359  |
| 1000000     | 6.724573 | 5.54213  | 0.984382 | 0.198061  |
| 10000000    | 56.9782  | 41.863   | 12.1023  | 3.0129    |

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
