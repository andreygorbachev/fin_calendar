# project "fin-calendar_quasi-coupon-dates"

add_library(${PROJECT_NAME} INTERFACE
  date_adjuster_interface.h
  date_adjusters.h
  duration_variant.h
  quasi_coupon_schedule.h
  quasi_coupon_dates.h
)

target_include_directories(${PROJECT_NAME} INTERFACE .)

#export(TARGETS quasi-coupon-dates NAMESPACE QuasiCouponDates:: FILE QuasiCouponDatesConfig.cmake)
