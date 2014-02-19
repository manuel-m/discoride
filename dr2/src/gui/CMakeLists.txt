include_directories (${Cairo_INCLUDE_DIRS})


#==============================================================================
# lib definition
# 
#==============================================================================
add_library (gui rpanel_dock0.c rpanel_dock1.c rpanel_mix.c rpanel_playlist.c rpanels.c rpanel_sidebar.c rpanel_waves.c)


target_link_libraries (gui ride)
