cmake_minimum_required(VERSION 3.10)

#==============================
#INCLUDE NLOHMANN JSON LIBRARY
#==============================
set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(json)

#========================
#INCLUDE CURL LIBRARY
#========================
set(CURL_TEST OFF CACHE INTERNAL "")
add_subdirectory(curl)