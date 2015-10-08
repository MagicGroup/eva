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

macro( tqt_message )
  message( STATUS "${ARGN}" )
endmacro( )

pkg_search_module( TQT tqt )

if( NOT QT_FOUND )
  tde_message_fatal( "Unable to find tqt!\n Try adding the directory in which the tqt.pc file is located\nto the PKG_CONFIG_PATH variable." )
endif( )

# tmoc_executable
tde_execute_process(
  COMMAND pkg-config tqt --variable=tmoc_executable
  OUTPUT_VARIABLE TMOC_EXECUTABLE OUTPUT_STRIP_TRAILING_WHITESPACE )

if( NOT EXISTS ${TMOC_EXECUTABLE} )
  tde_message_fatal( "tmoc is not found!\n tqt is correctly installed?" )
endif( )

tqt_message( "  tmoc path: ${TMOC_EXECUTABLE}" )


# moc_executable
tde_execute_process(
  COMMAND pkg-config tqt --variable=moc_executable
  OUTPUT_VARIABLE MOC_EXECUTABLE OUTPUT_STRIP_TRAILING_WHITESPACE )

if( NOT EXISTS ${MOC_EXECUTABLE} )
  tde_message_fatal( "Path to moc is not set.\n tqt is correctly installed?" )
endif( )

tqt_message( "  moc path: ${MOC_EXECUTABLE}" )


# uic_executable
tde_execute_process(
  COMMAND pkg-config tqt --variable=uic_executable
  OUTPUT_VARIABLE UIC_EXECUTABLE OUTPUT_STRIP_TRAILING_WHITESPACE )

if( NOT EXISTS ${UIC_EXECUTABLE} )
  tde_message_fatal( "uic not found!\n tqt is correctly installed?" )
endif( )

tqt_message( "  uic path: ${UIC_EXECUTABLE}" )


# tqt-replace script
set( QT_REPLACE_SCRIPT "${QT_PREFIX}/bin/tqt-replace" )

if( NOT EXISTS ${QT_REPLACE_SCRIPT} )
  tde_message_fatal( "tqt-replace not found!\n Check tqt installation." )
endif( )

tqt_message( "  tqt-replace path: ${QT_REPLACE_SCRIPT}" )


# check if tqt is usable
tde_save( CMAKE_REQUIRED_INCLUDES CMAKE_REQUIRED_LIBRARIES )
set( CMAKE_REQUIRED_INCLUDES ${QT_INCLUDE_DIRS} )
foreach( _dirs ${QT_LIBRARY_DIRS} )
  list( APPEND CMAKE_REQUIRED_LIBRARIES "-L${_dirs}" )
endforeach()
list( APPEND CMAKE_REQUIRED_LIBRARIES ${QT_LIBRARIES} )

check_cxx_source_compiles("
    #include <tntqapplication.h>
    int main(int argc, char **argv) { TQApplication app(argc, argv); return 0; } "
  HAVE_USABLE_TQT )

if( NOT HAVE_USABLE_TQT )
  tde_message_fatal( "Unable to build a simple tqt test." )
endif( )

tde_restore( CMAKE_REQUIRED_INCLUDES CMAKE_REQUIRED_LIBRARIES )


# QT_CXX_FLAGS
foreach( _flag ${QT_CFLAGS} ${QT_CFLAGS_OTHER} )
  set( QT_CXX_FLAGS "${QT_CXX_FLAGS} ${_flag}" )
endforeach()

# Set compiler flags according to build type
set( CMAKE_CXX_FLAGS_RELWITHDEBINFO "-DNDEBUG" )
set( CMAKE_C_FLAGS_RELWITHDEBINFO   "-DNDEBUG" )
