#==============================================================================
# includes 
# 
#==============================================================================
include_directories (${Cairo_INCLUDE_DIRS})
include_directories (${TAGLIB_INCLUDE_DIRS})
include_directories (${MPG123_INCLUDE_DIRS})
include_directories (${PORTAUDIO_INCLUDE_DIRS})
include_directories (${GLFW_INCLUDE_DIRS})


#==============================================================================
# lib definition
# 
#==============================================================================
add_library (ride 
  raudio.c 
  raudio_callbacks.c 
  raudio_decode.c 
  raudio_playbuffer_cb.c 
  rbutton.c 
  rcairogl.c 
  rchan.c 
  rcolor.c 
  rcpu.c
  rdata.c
  rdeckgauge.c
  rdeckwave4.c 
  rdisplay.c 
  rframe.c 
  rglfw.c 
  rglfw_cairo.c 
  rhslider2.c 
  rjog.c 
  rkey.c 
  rlabel.c 
  rlist.c 
  rmem.c 
  rplaylist.c 
  rstack_proxy.c 
  rstl.c 
  rstyle.c 
  rtrace.c
  rtrack.c
  rvmeter.c
  rvslider2.c
  rwid.c
  tinycthread.c
  ride.c)




