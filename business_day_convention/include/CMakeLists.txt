# project "fin-calendar_business-day-convention"

add_library(${PROJECT_NAME} INTERFACE
  no_adjustment.h
  following.h
  preceding.h
  modified_following.h
  modified_preceding.h
  business_day_convention.h
)

target_include_directories(${PROJECT_NAME} INTERFACE .)

target_link_libraries(${PROJECT_NAME} INTERFACE
  calendar
)

#export(TARGETS business-day-convention NAMESPACE BusinessDayConvention:: FILE BusinessDayConventionConfig.cmake)
