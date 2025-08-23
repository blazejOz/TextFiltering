cmake_minimum_required(VERSION 3.20)
project(text_filtering LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(text_filtering
    src/CensorFilter.cpp
)
target_include_directories(text_filtering PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(text_filtering_app src/main.cpp)
target_link_libraries(text_filtering_app PRIVATE text_filtering)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  text_filtering_test
  tests/censorship_tests.cpp
)
target_link_libraries(
  text_filtering_test
  text_filtering
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(text_filtering_test)
