project(day-count-test)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.16.0
)
FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME}
  day_count.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  day-count
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
