project(verticalplayer)

cmake_minimum_required(VERSION 3.1)

set(OF_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../of/" CACHE PATH "The root directory of ofnode/of project.")
include(${OF_ROOT}/openFrameworks.cmake)

ofxaddon(ofxGstVideoSyncPlayer)

set(SOURCES
    src/main.cpp
    src/ofApp.cpp
)

add_executable(
    ${PROJECT_NAME}-1
    MACOSX_BUNDLE
    ${SOURCES}
    ${OFXADDONS_SOURCES}
)

add_executable(
    ${PROJECT_NAME}-2
    MACOSX_BUNDLE
    ${SOURCES}
    ${OFXADDONS_SOURCES}
)

add_executable(
    ${PROJECT_NAME}
    MACOSX_BUNDLE
    ${SOURCES}
    ${OFXADDONS_SOURCES}
)

target_compile_definitions(${PROJECT_NAME} PRIVATE MASTER)
target_compile_definitions(${PROJECT_NAME}-1 PRIVATE ONE)
target_compile_definitions(${PROJECT_NAME}-2 PRIVATE TWO)

target_link_libraries(
    ${PROJECT_NAME}-1
    ${OPENFRAMEWORKS_LIBRARIES}
    gstnet-1.0
    gstreamer-1.0
    gio-2.0
    gobject-2.0
    glib-2.0
)

target_link_libraries(
    ${PROJECT_NAME}-2
    ${OPENFRAMEWORKS_LIBRARIES}
    gstnet-1.0
    gstreamer-1.0
    gio-2.0
    gobject-2.0
    glib-2.0
)

target_link_libraries(
    ${PROJECT_NAME}
    ${OPENFRAMEWORKS_LIBRARIES}
    gstnet-1.0
    gstreamer-1.0
    gio-2.0
    gobject-2.0
    glib-2.0
)

ofSetTargetProperties()
