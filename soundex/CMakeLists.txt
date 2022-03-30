cmake_minimum_required(VERSION 3.12)
project(soundex VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-O2 -Wall -Wextra")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_executable(
    soundex_encode
    soundex_test.cpp
    string_utils.cpp
)

target_include_directories(soundex_encode
    PRIVATE "${PROJECT_BINARY_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(
    soundex_encode
    gtest_main
    gmock
    gmock_main
)

include(GoogleTest)
set(crashUncaughtExcept --gtest_catch_exceptions 0)
gtest_discover_tests(soundex_encode "${crashUncaughtExcept}")

install(TARGETS soundex_encode DESTINATION bin)
