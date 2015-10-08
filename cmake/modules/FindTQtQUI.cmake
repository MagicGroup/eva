#################################################
#
#  (C) 2010-2011 Serghei Amelian
#  serghei (DOT) amelian (AT) gmail.com
#
#  Improvements and feedback are welcome
#
#  This file is released under GPL >= 2
#
#################################################

macro( tqtttqui_message )
  message( STATUS "${ARGN}" )
endmacro( )

pkg_search_module( TQTQUI tqtttqui )

if( NOT TQTQUI_FOUND )
  tde_message_fatal( "Unable to find tqtttqui!\n Try adding the directory in which the tqtttqui.pc file is located\nto the PKG_CONFIG_PATH variable." )
endif( )

# check if tqtttqui is usable
tde_save( CMAKE_REQUIRED_INCLUDES CMAKE_REQUIRED_LIBRARIES )
set( CMAKE_REQUIRED_INCLUDES ${TQTQUI_INCLUDE_DIRS} )
foreach( _dirs ${TQTQUI_LIBRARY_DIRS} )
  list( APPEND CMAKE_REQUIRED_LIBRARIES "-L${_dirs}" )
endforeach()
list( APPEND CMAKE_REQUIRED_LIBRARIES ${TQTQUI_LIBRARIES} )

check_cxx_source_compiles("
    #include <tntqapplication.h>
    int main(int argc, char **argv) { TQApplication app(argc, argv); return 0; } "
  HAVE_USABLE_TQTQUI )

if( NOT HAVE_USABLE_TQTQUI )
  tde_message_fatal( "Unable to build a simple tqtttqui test." )
endif( )

tde_restore( CMAKE_REQUIRED_INCLUDES CMAKE_REQUIRED_LIBRARIES )


# TQTQUI_CXX_FLAGS
foreach( _flag ${TQTQUI_CFLAGS_OTHER} )
  set( TQTQUI_CXX_FLAGS "${TQTQUI_CXX_FLAGS} ${_flag}" )
endforeach()
