project(quasi-coupon-dates-test)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.16.0
)
FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME}
  quasi_coupon_dates.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  quasi-coupon-dates
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
