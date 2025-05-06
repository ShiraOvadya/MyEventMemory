# # cmake_minimum_required(VERSION 3.10)
# # project(FaceEngine)

# # set(CMAKE_CXX_STANDARD 17)

# # # איפה נמצאת ספריית dlib
# # add_subdirectory(../libs/dlib dlib_build)

# # # קובץ הקוד שלך
# # add_executable(FaceEngine main.cpp)

# # # קישור לספריית dlib

# # target_link_libraries(FaceEngine dlib::dlib)
# # cmake_minimum_required(VERSION 3.10)
# # project(HelloWorld)

# # add_executable(hello main.cpp)
# # cmake_minimum_required(VERSION 3.15)
# # project(test_dlib)

# # find_package(dlib CONFIG REQUIRED)

# # add_executable(test_dlib test_dlib.cpp)
# # target_link_libraries(test_dlib PRIVATE dlib::dlib)




# # cmake_minimum_required(VERSION 3.10)
# # project(FaceEngine)

# # set(CMAKE_CXX_STANDARD 17)

# # # הוספת נתיב ההדר של dlib
# # include_directories(${CMAKE_SOURCE_DIR}/dlib)

# # # הוספת תת-פרויקט dlib
# # add_subdirectory(dlib dlib_build)

# # # קובץ הקוד שלך
# # add_executable(FaceEngine main.cpp)

# # # קישור לספריית dlib
# # target_link_libraries(FaceEngine dlib::dlib)
# # cmake_minimum_required(VERSION 3.10)
# # project(MyFirstCMakeProject)

# # add_executable(MyFirstCMakeProject main.cpp)
# # cmake_minimum_required(VERSION 3.0)
# # project(MyDlibProject)

# # set(CMAKE_CXX_STANDARD 14)

# # add_subdirectory(dlib)

# # add_executable(main main.cpp)

# # target_link_libraries(main dlib::dlib)
# # cmake_minimum_required(VERSION 3.5)
# # project(MyDlibProject)

# # set(CMAKE_CXX_STANDARD 14)

# # include_directories(dlib)
# # include_directories(dlib/external)

# # add_executable(main
# #     main.cpp
# #     dlib/all/source.cpp
# # )


# # cmake_minimum_required(VERSION 3.5)
# # project(MyDlibProject)

# # set(CMAKE_CXX_STANDARD 14)

# # include_directories(dlib)
# # include_directories(dlib/external)

# # add_executable(main
# #     main.cpp
# #     dlib/dlib-master/dlib/all/source.cpp
# # )

# # cmake_minimum_required(VERSION 3.5)
# # project(MyDlibProject)

# # set(CMAKE_CXX_STANDARD 14)

# # # ציין את הנתיב לתיקיית dlib הראשית (שבה נמצא הקובץ all/source.cpp)
# # set(DLIB_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/dlib/dlib-master/dlib")
# # include_directories(${DLIB_ROOT})

# # # הוספת הדגל /bigobj (נחוץ ל-Windows)
# # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")

# # # הגדרת הקבצים שיש לתרגם
# # add_executable(main
# #     main.cpp
# #     ${DLIB_ROOT}/all/source.cpp
# # )




# # cmake_minimum_required(VERSION 3.5)
# # project(MyDlibProject)

# # set(CMAKE_CXX_STANDARD 14)

# # # הוספת הנתיבים הנכונים עבור קבצים בתוך dlib
# # include_directories(dlib/dlib-master/dlib/image_processing)  # תיקיית image_processing
# # include_directories(dlib/dlib-master/dlib)  # תיקיית dlib עצמה

# # # הוספת הדגל /bigobj
# # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")

# # # הגדרת הקבצים שיש לתרגם
# # add_executable(main
# #     main.cpp
# #     dlib/dlib-master/dlib/all/source.cpp
# # )

# # cmake_minimum_required(VERSION 3.5)
# # project(MyDlibProject)

# # # הגדרת הסטנדרט של ה-C++
# # set(CMAKE_CXX_STANDARD 14)

# # # הגדרת דגלים מיוחדים לקומפיילר (/bigobj לקבצים גדולים)
# # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")

# # # הגדרת נתיב ההכללה עבור Dlib
# # # כולל את התיקייה האב של 'dlib' בלבד כדי להימנע משגיאות
# # include_directories(${CMAKE_SOURCE_DIR}/dlib/dlib-master)

# # # הגדרת קובצי המקור שלך
# # add_executable(main
# #     main.cpp
# #     dlib/dlib-master/dlib/all/source.cpp
# # )

# # # אם יש ספריות נוספות שצריך לקשר, אפשר להוסיף אותן 


# # cmake_minimum_required(VERSION 3.5)
# # project(MyDlibProject)

# # # הגדרת הסטנדרט של ה-C++ ל-17
# # set(CMAKE_CXX_STANDARD 17)
# # set(CMAKE_CXX_STANDARD_REQUIRED ON)

# # # הגדרת דגלים מיוחדים לקומפיילר (/bigobj לקבצים גדולים)
# # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")

# # # הגדרת נתיב ההכללה עבור Dlib (רק התיקיה הראשית של dlib-master)
# # include_directories(${CMAKE_SOURCE_DIR}/dlib/dlib-master)

# # # הגדרת קובצי המקור
# # add_executable(main
# #     main.cpp
# #     dlib/dlib-master/dlib/all/source.cpp
# # )

# # # אם יש ספריות נוספות שצריך לקשר, אפשר להוסיף אותן כאן
# cmake_minimum_required(VERSION 3.5)
# project(MyDlibProject)

# # הגדרת הסטנדרט של C++
# set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# # אם מקמפל ב-MSVC, הוסף דגל /bigobj. ב-MinGW לא צריך.
# if(MSVC)
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
# endif()

# # הוספת נתיב ההכללה של Dlib (רק התיקייה הראשית של dlib)
# include_directories(${CMAKE_SOURCE_DIR}/dlib/dlib-master)

# # הוספת קבצי המקור שלך
# add_executable(main
#     main.cpp
#     dlib/dlib-master/dlib/all/source.cpp
#     )


# # קישור לספריות נוסxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx צריך
# find_package(PNG REQUIRED)
# find_package(JPEG REQUIRED)
# find_package(ZLIB REQUIRED)

# target_link_libraries(main ${PNG_LIBRARIES} ${JPEG_LIBRARIES} ${ZLIB_LIBRARIES})

# cmake_minimum_required(VERSION 3.5)
# project(FaceRecognitionModule)

# # הגדרת הסטנדרט של C++
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# # אם מקמפל ב-MSVC (למשל ב-Windows עם Visual Studio), הוסף דגל /bigobj
# if(MSVC)
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
# endif()

# # הוספת נתיב ההכללה של dlib (נקודת התחלה ל-#include <dlib/...>)
# include_directories(${PROJECT_SOURCE_DIR}/dlib/dlib-master)

# # יצירת קובץ הרצה
# add_executable(main
#     main.cpp
#     dlib/dlib-master/dlib/all/source.cpp
# )

# # חיפוש וקישור לספריות תמונה
# find_package(PNG REQUIRED)
# find_package(JPEG REQUIRED)
# find_package(ZLIB REQUIRED)

# target_link_libraries(main ${PNG_LIBRARIES} ${JPEG_LIBRARIES} ${ZLIB_LIBRARIES})










cmake_minimum_required(VERSION 3.5)
project(FaceRecognitionModule)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# תוספות לדיבאג
set(CMAKE_VERBOSE_MAKEFILE ON)

# Handle big object files for MSVC (Windows)
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
endif()
add_definitions(-DDLIB_NO_SUPPORT_FOR_WINDOWS_STYLE_SOCKETS)
# add_definitions(-D__cpp_lib_byte=201603)

# dlib setup
add_subdirectory(dlib/dlib-master dlib_build)

# Add executable
add_executable(main
    main.cpp
)

# Link dlib
target_link_libraries(main dlib::dlib)

# Include headers
target_include_directories(main PRIVATE ${PROJECT_SOURCE_DIR}/dlib/dlib-master)

# Optional Windows networking support
if(WIN32)
    target_link_libraries(main ws2_32)
endif()

# cmake_minimum_required(VERSION 3.5)
# project(FaceRecognitionModule)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# # תוספות לדיבאג
# set(CMAKE_VERBOSE_MAKEFILE ON)

# # פתרון שגיאת std::byte
# add_compile_options(-include cstddef)

# # Handle big object files for MSVC (Windows)
# if(MSVC)
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
# endif()
# add_definitions(-DDLIB_NO_SUPPORT_FOR_WINDOWS_STYLE_SOCKETS)


# # dlib setup
# add_subdirectory(dlib/dlib-master dlib_build)

# # Add executable
# add_executable(main
#     main.cpp
# )

# # Link dlib
# target_link_libraries(main dlib::dlib)

# # Include headers
# target_include_directories(main PRIVATE ${PROJECT_SOURCE_DIR}/dlib/dlib-master)

# # Optional Windows networking support
# if(WIN32)
#     target_link_libraries(main ws2_32)
# endif()






# cmake_minimum_required(VERSION 3.5)
# project(FaceRecognitionModule)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# # תוספות לדיבאג
# set(CMAKE_VERBOSE_MAKEFILE ON)

# # Handle big object files for MSVC (Windows)
# if(MSVC)
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
# endif()

# # הגדרת הדגלים
# add_definitions(-DDLIB_NO_SUPPORT_FOR_WINDOWS_STYLE_SOCKETS)
# add_definitions(-D__cpp_lib_byte=201603)

# # הגדרת תיקיית dlib
# add_subdirectory(dlib/dlib-master dlib_build)

# # הוספת executable
# add_executable(main
#     main.cpp
# )

# # קישור עם dlib
# target_link_libraries(main dlib::dlib)

# # כולל את כותרות dlib
# target_include_directories(main PRIVATE ${PROJECT_SOURCE_DIR}/dlib/dlib-master)

# # תמיכה ברשת על Windows (אם יש צורך)
# if(WIN32)
#     target_link_libraries(main ws2_32)
# endif()
