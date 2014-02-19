
include_directories (${Cairo_INCLUDE_DIRS})


#==============================================================================
# lib definition
# 
#==============================================================================
add_library (conf raudio_config.c  rdisplay_config.c  rplaylist_config.c  rstyle_config.c)
