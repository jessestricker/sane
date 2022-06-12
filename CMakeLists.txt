cmake_minimum_required(VERSION 3.22 FATAL_ERROR)
project(
  sane
  VERSION 0.1.0
  LANGUAGES CXX)

# Sets up common build requirements for a target.
function(sane_setup_build_reqs target_name)
  target_include_directories(${target_name} PUBLIC ${PROJECT_SOURCE_DIR}/src)
  target_compile_features(${target_name} PUBLIC cxx_std_20)
  set_target_properties(${target_name} PROPERTIES CXX_EXTENSIONS NO
                                                  CXX_STANDARD_REQUIRED YES)
endfunction()

add_subdirectory(src/sane)
