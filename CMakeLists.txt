cmake_minimum_required(VERSION 3.15)
project(testAgent)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add_executable(${PROJECT_NAME} src/main.cpp)
# target_include_directories(${PROJECT_NAME} PRIVATE include)

# 跨平台配置示例
if(WIN32)
  # 设定编码为 UTF-8
  if(MSVC)
      add_compile_options(/utf-8)
  endif()
  add_definitions(-D_WIN32)
  # Windows特定库链接
  # target_link_libraries(${PROJECT_NAME} PRIVATE ws2_32)
elseif(UNIX AND NOT APPLE)
  add_definitions(-D__linux__)
  # Linux特定库链接
elseif(APPLE)
  add_definitions(-D__APPLE__)
  # macOS特定框架
  find_library(COCOA_LIBRARY Cocoa)
  target_link_libraries(${PROJECT_NAME} PRIVATE ${COCOA_LIBRARY})
endif()

add_executable(${PROJECT_NAME} src/main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE include)
