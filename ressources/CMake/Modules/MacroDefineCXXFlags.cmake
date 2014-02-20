MACRO(macro_define_cxxflags)

if (CMAKE_COMPILER_IS_GNUCXX)

   if (CMAKE_SYSTEM_NAME MATCHES Linux)
   
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-attributes")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-builtin-macro-redefined")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wcast-align")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wcast-qual")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wchar-subscripts")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wclobbered")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wconversion")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wcoverage-mismatch")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-declarations")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wdisabled-optimization")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-div-by-zero")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wdouble-promotion")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wempty-body")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wenum-compare")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-endif-labels")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wfloat-equal")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wformat")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wformat=2")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-format-contains-nul")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-format-extra-args")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wformat-nonliteral")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wformat-security")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wformat-y2k")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-free-nonheap-object")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wignored-qualifiers")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Winit-self")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Winline")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wmaybe-uninitialized")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-int-to-pointer-cast")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Winvalid-pch")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wunsafe-loop-optimizations")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wlogical-op")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wlong-long")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wmain")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wmissing-braces")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wmissing-field-initializers")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wmissing-format-attribute")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wmissing-include-dirs")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-mudflap")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-multichar")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wnonnull")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-overflow")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Woverlength-strings")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wpacked")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wpacked-bitfield-compat")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wparentheses")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wpointer-arith")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wreturn-type")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wsequence-point")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wshadow")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wsign-compare")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wsign-conversion")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wstack-protector")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wstrict-aliasing")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wstrict-overflow")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wswitch")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wswitch-default")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wswitch-enum")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wsync-nand")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wtrampolines")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wtrigraphs")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wtype-limits")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wuninitialized")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wunknown-pragmas")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wunused")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wunused-function")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wunused-label")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wunused-local-typedefs")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wunused-parameter")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-result")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wunused-value")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wunused-variable")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wunused-but-set-parameter")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wunused-but-set-variable")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wvariadic-macros")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wvector-operation-performance")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wvla")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wvolatile-register-var")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wwrite-strings")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ansi")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
   
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ffast-math")
   set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_FORTIFY_SOURCE=2 -O1")
#    set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pie -fPIC -fPIE")
#    set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,-z,relro,-z,now")
#    set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fstack-protector")

   if (CMAKE_BUILD_TYPE MATCHES Release)
      set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -mmmx -msse -m3dnow")
   endif (CMAKE_BUILD_TYPE MATCHES Release)

   if (CMAKE_BUILD_TYPE MATCHES Debug)
      set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -pg -DDEBUG")
      set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
   endif (CMAKE_BUILD_TYPE MATCHES Debug)


   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

   endif (CMAKE_SYSTEM_NAME MATCHES Linux)
endif (CMAKE_COMPILER_IS_GNUCXX)


ENDMACRO(macro_define_cxxflags)