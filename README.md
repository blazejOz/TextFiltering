# TextFiltering

A simple C++ project to help my brother learn how open source contributions work

### Build
```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

### Run the app
The example app takes input strings as command-line arguments and prints transformed output.
```bash
./build/text_filtering_app "I like to walk outside"
```

### Run tests
GoogleTest is fetched automatically via CMake's FetchContent.
```bash
ctest --test-dir build --output-on-failure
```

Or run the test binary directly:
```bash
./build/text_filtering_test
```