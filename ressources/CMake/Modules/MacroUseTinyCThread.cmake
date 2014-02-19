# define TINYCTHREAD_A
# add tinycthread headers dir

MACRO(macro_use_tinycthread)

include_directories (${PROJECT_SOURCE_DIR}/external_libs/tinycthread)

ENDMACRO(macro_use_tinycthread)
