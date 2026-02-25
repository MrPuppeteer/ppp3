cmake_minimum_required(VERSION 3.5)

project(Programming_Qt VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# set(PROJECT_SOURCES
set(COMMON_SOURCES
  # main.cpp
  PPP/Window.h
  PPP/Graph.h
  PPP/GUI.h
  PPP/Simple_window.h
  PPP/Point.h
  PPP/std_lib_facilities.h
  PPP/Window.cpp
  PPP/Graph.cpp
  PPP/Image_private.h
  PPP/GUI.cpp
  PPP/GUI_private.h
  PPP/Simple_window.cpp
  PPP/Colormap.cpp
)

function(add_gui_app TARGET_NAME MAIN_SOURCE)

  if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${TARGET_NAME}
      MANUAL_FINALIZATION
      ${MAIN_SOURCE}
      ${COMMON_SOURCES}
    )
  else()
    # Define target properties for Android with Qt 6 as:
    #    set_property(TARGET Programming_Qt APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
    #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
    # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
    if(ANDROID)
      add_library(${TARGET_NAME} SHARED
        ${MAIN_SOURCE}
        ${COMMON_SOURCES}
      )
    # Define properties for Android with Qt 5 after find_package() calls as:
    #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
      add_executable(${TARGET_NAME}
        ${MAIN_SOURCE}
        ${COMMON_SOURCES}
      )
    endif()
  endif()

  target_link_libraries(${TARGET_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
  target_include_directories(${TARGET_NAME} PRIVATE .)

  set_target_properties(${TARGET_NAME} PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER "com.example.${TARGET_NAME}"
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
  )
    
  if(MSVC)
    target_compile_options(${TARGET_NAME} PRIVATE /EHsc /W4 /WX)
  else()
    target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
  endif()

  if (EMSCRIPTEN)
    target_link_options(${TARGET_NAME} PUBLIC -sASYNCIFY -Os)
  endif()

  install(TARGETS ${TARGET_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

  if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${TARGET_NAME})
  endif()

endfunction()

add_gui_app(10.3.first_example 10.3.first_example.cpp)
add_gui_app(10.7.1.axis 10.7.1.axis.cpp)
add_gui_app(10.7.2.graphing_function 10.7.2.graphing_function.cpp)
add_gui_app(10.7.3.polygons 10.7.3.polygons.cpp)
add_gui_app(10.7.4.rectangles 10.7.4.rectangles.cpp)
add_gui_app(10.7.5.fill 10.7.5.fill.cpp)
add_gui_app(10.7.6.text 10.7.6.text.cpp)
add_gui_app(10.7.7.images 10.7.7.images.cpp)
add_gui_app(10.7.8.much_more 10.7.8.much_more.cpp)
add_gui_app(10.d.hello_world_graphical_ver 10.d.hello_world_graphical_ver.cpp)
add_gui_app(10.e.01.rectangles 10.e.01.rectangles.cpp)
add_gui_app(10.e.02.howdy 10.e.02.howdy.cpp)
add_gui_app(10.e.03.initials 10.e.03.initials.cpp)
add_gui_app(10.e.04.tic-tac-toe 10.e.04.tic-tac-toe.cpp)
add_gui_app(10.e.05.red_frame 10.e.05.red_frame.cpp)
add_gui_app(10.e.06.shape 10.e.06.shape.cpp)
add_gui_app(10.e.06.window 10.e.06.window.cpp)
add_gui_app(10.e.07.house 10.e.07.house.cpp)
add_gui_app(10.e.08.olympic_rings 10.e.08.olympic_rings.cpp)
add_gui_app(10.e.09.image 10.e.09.image.cpp)
add_gui_app(10.e.10.diagram 10.e.10.diagram.cpp)
add_gui_app(10.e.11.polygons_series 10.e.11.polygons_series.cpp)
add_gui_app(10.e.12.starlike 10.e.12.starlike.cpp)
add_gui_app(10.e.13.colorful_starlike 10.e.13.colorful_starlike.cpp)
