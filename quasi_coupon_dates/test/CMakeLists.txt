project("${PROJECT_NAME}_test" LANGUAGES CXX)

add_executable(${PROJECT_NAME}
  date_adjusters.cpp
  duration_variant.cpp
  quasi_coupon_schedule.cpp
  quasi_coupon_dates.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  fin-calendar_quasi-coupon-dates
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
