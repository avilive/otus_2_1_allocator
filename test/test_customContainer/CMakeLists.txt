
project(test_customContainer)


if (MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
elseif(MinGW)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
endif()

#add_executable(
#  unit_test_customContainer
#  test_customContainer.cpp
# )

  

#target_link_libraries(unit_test_customContainer PRIVATE
  ##  sub::lib1
#    customContainer
#    gtest_main
#)
############


#add_library(static3 STATIC test_customContainer.cpp)
#target_link_libraries(static3 PRIVATE gtest_main)
############
#gtest_discover_tests(test_customContainer)
# automatic discovery of unit tests
include(GoogleTest)

gtest_discover_tests(unit_test_customContainer 
  PROPERTIES
    LABELS "unit"
  DISCOVERY_TIMEOUT  # how long to wait (in seconds) before crashing
    600
  )
 

