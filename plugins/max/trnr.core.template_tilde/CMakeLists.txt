set(C74_MIN_API_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/min-api)
include(${C74_MIN_API_DIR}/script/min-pretarget.cmake)

include_directories( 
	"${C74_INCLUDES}"
)

set(SOURCE_FILES
	${PROJECT_NAME}.cpp
)

add_library( 
	${PROJECT_NAME} 
	MODULE
	${SOURCE_FILES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE trnr-dsp)

include(${C74_MIN_API_DIR}/script/min-posttarget.cmake)