cmake_minimum_required(VERSION 3.10)

#========================
#Headers
#========================
set(headers_path "${PROJECT_SOURCE_DIR}/include")
file(GLOB headers "${headers_path}/**/*")

#========================
#Sources
#========================
file(GLOB srcs "*.cpp")

#========================
#Building libraryexecutable===============
add_executable(${PROJECT_NAME} ${srcs})

target_include_directories(${PROJECT_NAME}
                           PUBLIC ${headers_path} )

target_link_libraries(${PROJECT_NAME}
                      PUBLIC libcurl nlohmann_json)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)