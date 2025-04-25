project("quasi-coupon-dates")

add_library(${PROJECT_NAME} INTERFACE
  quasi_coupon_dates.h
)

target_include_directories(${PROJECT_NAME} INTERFACE .)

export(TARGETS quasi-coupon-dates NAMESPACE QuasiCouponDates:: FILE QuasiCouponDatesConfig.cmake)
