# CMakeList.txt : CMake project for otus_1_2_ip_filter, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project (main)

set(SOURCES
    main.cpp 
)

add_executable(${PROJECT_NAME} main.cpp)

install(TARGETS main)

#find_path(CUST_CONT otus_2_1_custom_allocator/libs/customContainer/customContainer.h)

target_link_libraries(${PROJECT_NAME}
    #sub::libcnt
    customContainer
)

# TODO: Add tests and install targets if needed.
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)