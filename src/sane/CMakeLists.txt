add_library(sane STATIC sane.cpp)
add_library(sane::sane ALIAS sane)

sane_setup_build_reqs(sane)
