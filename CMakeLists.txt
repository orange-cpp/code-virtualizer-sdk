cmake_minimum_required(VERSION 3.28.1)

project(cv-sdk)

add_library(cv-sdk INTERFACE)
target_include_directories(cv-sdk INTERFACE include)

if (WIN32)
    target_link_directories(cv-sdk INTERFACE lib)
endif()
