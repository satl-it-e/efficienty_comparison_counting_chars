# Words length

Determining average words length and dispersion from file. 

## Compilation

Creating new working directory: <br />
`mkdir build`

Go to working directory: <br />
`cd build`

Compiling cpp files: <br />
`cmake -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..`  <br />
`make`

## Running program

Go to upper directory: <br />
`cd .. ` <br />

Run test_one_way: <br />
`./test_one_way <method_id> <input_filename> <output_filename>` <br />
**<method_id>** - Id of method. <br />
**<input_filename>** - filename from which program will determine average word length. <br />
**<output_filename>** - where results will be printed. <br />


## Running test script

Run test: <br /> 
`python3 test_all_ways.py <number_of_tests>` <br />
**<number_of_tests>** -- Number of test required for each option.


## Three different methods
 - 1 - reading file by separate words.
 - 2 - reading entire file into memory. Splitting words using library boost.
 - 3 - reading entire file into memory. Checking for sequence of letters ('a/A' - 'z/Z').
 
## Results

Method ID | 1 | 2 | 3
--- | --- | --- | ---
**Time of processing (microseconds):** |238996 | 882145 | 102726