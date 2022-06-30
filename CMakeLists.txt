cmake_minimum_required(VERSION 3.22 FATAL_ERROR)
project(
  sane
  VERSION 0.1.0
  LANGUAGES CXX)

# sets up common build requirements for a target
function(sane_setup_build_reqs target_name)
  target_include_directories(${target_name} PUBLIC ${PROJECT_SOURCE_DIR}/src)
  set_target_properties(
    ${target_name}
    PROPERTIES CXX_STANDARD 20
               CXX_STANDARD_REQUIRED YES
               CXX_EXTENSIONS NO)
endfunction()

# include target definitions
add_subdirectory(src/sane)
