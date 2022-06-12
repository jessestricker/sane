add_library(sane STATIC)
add_library(sane::sane ALIAS sane)

sane_setup_build_reqs(sane)
