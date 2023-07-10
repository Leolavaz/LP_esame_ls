cmake_minimum_required(VERSION 3.5)


add_subdirectory(./lib/googletest-master/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest-master/googletest)
include_directories(${gtest_SOURCE_DIR}/include${gtest_SOURCE_DIR})
set(TEST_SOURCE_FILES run_all_tests.cpp ShoppingListFixture.cpp ObserverTest.cpp UserFixture.cpp ItemTest.cpp)
add_executable(runListsTest ${TEST_SOURCE_FILES})
target_link_libraries(runListsTest gtest gtest_main core)