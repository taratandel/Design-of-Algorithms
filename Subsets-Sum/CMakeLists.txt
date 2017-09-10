# In The Name Of God
# ========================================
# [] File Name : CMakeLists.txt
#
# [] Creation Date : 08-05-2015
#
# [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
# =======================================
cmake_minimum_required (VERSION 2.6)
project (Subsets-Sum)

# Set porject imformation
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

subdirs (src)

# The version number
set (Subsets-Sum_MAJOR_VERSION 1)
set (Subsets-Sum_MINOR_VERSION 1)

# Add personal c flags
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O0 -g -std=gnu11 ")
