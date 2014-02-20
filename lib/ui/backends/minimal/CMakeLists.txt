include(MacroUseWincompat)
macro_use_wincompat()

file(GLOB ui_minimal_SOURCES *.cpp)
add_library (ui_minimal ${ui_minimal_SOURCES})

