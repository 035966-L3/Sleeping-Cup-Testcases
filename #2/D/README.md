### General instruction

You need to adjust the data using `adjust.cpp` after generation.

### Usage (Windows)

1. Generate data (Tests 3-30) as usual.
2. Compile `adjust.cpp`.
3. Run the command `for /L %i in (3, 1, 30) do adjust.exe %i.in`.

### Usage (Linux)

1. Generate data (Tests 3-30) as usual.
2. Compile `adjust.cpp`.
3. Run the command `chmod +x adjust`.
4. Run the command `for i in {3..30}; do ./adjust "$i.in"; done`.
