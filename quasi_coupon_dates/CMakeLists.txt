project("${PROJECT_NAME}_quasi-coupon-dates" LANGUAGES NONE)

add_subdirectory(include)

if(NOT FIN_CALENDAR_MINIMAL)

	enable_testing()

	add_subdirectory(test)

endif()
