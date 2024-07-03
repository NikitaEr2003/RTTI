file(GLOB SOURCES *.cpp )

add_executable(RTTI ${SOURCES})

target_include_directories(RTTI PRIVATE ./include)