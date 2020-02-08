Requirements:
    - CMake 3.14 or later
    - Compiler supporting C++17 and gcc-style warning flags (-Wall, -Werror, etc)

Building:
    mkdir build
    cd build
    cmake ..
    make

Testing:
    cd build
    ctest

Ambiguities:
    - Should the pencil be able to write numbers and special characters?
      If so, what is the cost?
    - Can a dull pencil write other whitespace characters?
    - What should happen if a pencil writes an uppercase character,
      but only has 1 durability?