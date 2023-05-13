
project(gtest_main)
#include(FetchContent)
#set(CMAKE_POLICY_DEFAULT_CMP0135 OLD)
#FetchContent_Declare(
#  gtest
#  GIT_REPOSITORY https://github.com/google/googletest.git
#  GIT_TAG        703bd9caab50b139428cea1aaff9974ebee5742e # release-1.10.0
#)
add_subdirectory(googletest)
# configure build of googletest
enable_testing()
#find_package(GTest REQUIRED)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
#FetchContent_MakeAvailable(gtest)

#add_executable(
#    unit_tests
#    test_ip_filter.cpp
#    )

#target_link_libraries(unit_tests PRIVATE
#    sub::lib1
#    gtest_main
#)
add_subdirectory(test_customContainer)

#not ready yet
#add_subdirectory(test_limitedAllocator)

