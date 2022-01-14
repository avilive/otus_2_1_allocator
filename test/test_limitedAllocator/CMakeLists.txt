
enable_testing()
file(GLOB SRCS *.cpp)
ADD_EXECUTABLE(test_ip_filter ${SRCS})

#add_executable(
#  hello_test
#  hello_test.cc
#)
add_library(${PROJECT_NAME} test_ip_filter.cpp)
add_library(sub::test ALIAS ${PROJECT_NAME})

TARGET_LINK_LIBRARIES(test_ip_filter
  #  sub::lib1
  # sub::test
    libgtest
    libgmock
)

include(GoogleTest)
gtest_discover_tests(test_ip_filter)
