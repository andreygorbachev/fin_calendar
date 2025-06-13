project("${PROJECT_NAME}_day-count" LANGUAGES NONE)

add_subdirectory(include)

if(NOT FIN_CALENDAR_MINIMAL)

	add_subdirectory(test)

endif()
