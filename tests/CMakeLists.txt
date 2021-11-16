include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

FetchContent_MakeAvailable(googletest)

set(BOOST_PYTHONLIB python39)
find_package(PythonLibs 3.9 REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})

find_package(Boost 1.65.0 COMPONENTS ${BOOST_PYTHONLIB} python REQUIRED)

enable_testing()
add_executable(
  main_test
  test.cpp
  ${CMAKE_HOME_DIRECTORY}/src/walk.cpp
  ${CMAKE_HOME_DIRECTORY}/src/stat.cpp
)

target_link_libraries(
  main_test
  gtest_main
  ${Boost_LIBRARIES} ${PYTHON_LIBRARIES}
)

include(GoogleTest)
gtest_discover_tests(main_test)
