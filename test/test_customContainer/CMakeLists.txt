
project(test_customContainer)

add_executable(
    unit_tests
    test_customContainer.cpp
    )

target_link_libraries(unit_tests PRIVATE
  #  sub::lib1
    customContainer
    gtest_main
)

#gtest_discover_tests(test_customContainer)
# automatic discovery of unit tests
include(GoogleTest)
gtest_discover_tests(unit_tests
  PROPERTIES
    LABELS "unit"
  DISCOVERY_TIMEOUT  # how long to wait (in seconds) before crashing
    240
  )

