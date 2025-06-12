project("quasi-coupon-dates-test" LANGUAGES CXX)

add_executable(${PROJECT_NAME}
  quasi_coupon_dates.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  quasi-coupon-dates
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
