# CMakeList.txt : CMake project for otus_1_2_ip_filter, include source and define
# project specific logic here.
#
project (customContainer)
#cmake_minimum_required (VERSION 3.8)


add_library(${PROJECT_NAME} INTERFACE)
#add_library(sub::libcnt ALIAS ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} INTERFACE customContainer/ limitedAllocator/) 
#target_include_directories(${PROJECT_NAME} PUBLIC
#    ${PROJECT_SOURCE_DIR}/include
#)

#set_target_properties(libs PROPERTIES
#    CXX_STANDARD 14
#    CXX_STANDARD_REQUIRED ON
#)

# TODO: Add tests and install targets if needed.
