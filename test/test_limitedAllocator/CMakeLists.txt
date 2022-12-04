
project(test_limitedAllocator)

add_executable(
    unit_test_limitedAllocator
    test_limitedAllocator.cpp
    )

target_link_libraries(unit_test_limitedAllocator PRIVATE
  #  sub::lib1
    limitedAllocator
    gtest_main
)

#gtest_discover_tests(test_customContainer)
# automatic discovery of unit tests
include(GoogleTest)
gtest_discover_tests(unit_test_limitedAllocator
  PROPERTIES
    LABELS "unit"
  DISCOVERY_TIMEOUT  # how long to wait (in seconds) before crashing
    240
  )

