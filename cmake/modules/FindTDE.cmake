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

if( NOT TDE_FOUND )

  message( STATUS "checking for 'TDE'")

  pkg_search_module( TDE tqt )

  if( NOT TDE_FOUND )
    tde_message_fatal( "Unable to find tdelibs!\n Try adding the directory in which the tdelibs.pc file is located\nto the PKG_CONFIG_PATH variable." )
  endif( )

  # if the path is not already defined by user,
  # find tde-config executable
  if( NOT DEFINED KDECONFIG_EXECUTABLE )
    find_program( KDECONFIG_EXECUTABLE
      NAMES tde-config
      HINTS "${TDE_PREFIX}/bin" ${BIN_INSTALL_DIR} )
    if( NOT KDECONFIG_EXECUTABLE )
      tde_message_fatal( "tde-config are NOT found." )
    endif( NOT KDECONFIG_EXECUTABLE )
  endif( NOT DEFINED KDECONFIG_EXECUTABLE )

  set( ENV{LD_LIBRARY_PATH} "${TDE_LIBDIR}:$ENV{LD_LIBRARY_PATH}" )
  # check for installed trinity version
  tde_execute_process(
    COMMAND ${KDECONFIG_EXECUTABLE} --version
    OUTPUT_VARIABLE _version
    RESULT_VARIABLE _result
    OUTPUT_STRIP_TRAILING_WHITESPACE
    MESSAGE "Unable to run tde-config!\n TDELIBS are correctly installed?\n Path to tde-config are corect?" )

  # parse tde-config output, to extract TDE version
  string( REGEX MATCH "TDE: R([0-9\\.]+).*" __dummy "${_version}" )
  set( TDE_VERSION "${CMAKE_MATCH_1}" )

  # ask tde-config for few paths
  macro( __internal_get_path __type __var )
    tde_execute_process(
      COMMAND ${KDECONFIG_EXECUTABLE} --expandvars --install ${__type}
      OUTPUT_VARIABLE ${__var}
      CACHE INTERNAL "TDE ${__type} path" FORCE
      OUTPUT_STRIP_TRAILING_WHITESPACE )
  endmacro( __internal_get_path )

  __internal_get_path( include TDE_INCLUDE_DIR )
  __internal_get_path( lib TDE_LIB_DIR )
  __internal_get_path( exe TDE_BIN_DIR )
  __internal_get_path( data TDE_DATA_DIR )
  __internal_get_path( config TDE_CONFIG_DIR )
  __internal_get_path( html TDE_HTML_DIR )
  __internal_get_path( cmake TDE_CMAKE_DIR )
  __internal_get_path( qtplugins TDE_QTPLUGINS_DIR )

  # find kde tools
  macro( __internal_find_program __prog __var )
    find_program( ${__var}
      NAMES ${__prog}
      HINTS "${TDE_PREFIX}/bin" ${BIN_INSTALL_DIR}
      OUTPUT_STRIP_TRAILING_WHITESPACE )
    if( NOT ${__var} )
      tde_message_fatal( "${__prog} are NOT found.\n TDELIBS are correctly installed?" )
    endif( NOT ${__var} )
    set( ${__var} ${${__var}} CACHE INTERNAL "${__prog} executable" FORCE )
  endmacro( __internal_find_program )

  __internal_find_program( dcopidl KDE3_DCOPIDL_EXECUTABLE )
  __internal_find_program( dcopidlng KDE3_DCOPIDLNG_EXECUTABLE )
  __internal_find_program( dcopidl2cpp KDE3_DCOPIDL2CPP_EXECUTABLE )
  __internal_find_program( meinproc KDE3_MEINPROC_EXECUTABLE )
  __internal_find_program( tdeconfig_compiler KDE3_KCFGC_EXECUTABLE )
  __internal_find_program( maketdewidgets KDE3_MAKETDEWIDGETS_EXECUTABLE )

  # dcopidlng is a bash script which using tde-config;
  # if PATH to tde-config is not set, dcopidlng will fail;
  # for this reason we set KDECONFIG environment variable before running dcopidlng
  set( KDE3_DCOPIDLNG_EXECUTABLE env KDECONFIG=${KDECONFIG_EXECUTABLE} ${KDE3_DCOPIDLNG_EXECUTABLE}
    CACHE INTERNAL "dcopidlng executable" FORCE )

  # look for SCM data if present
  if( EXISTS "${CMAKE_SOURCE_DIR}/.tdescmmodule" )
    file( STRINGS "${CMAKE_SOURCE_DIR}/.tdescmmodule" TDE_SCM_MODULE_NAME )
  endif( EXISTS "${CMAKE_SOURCE_DIR}/.tdescmmodule" )
  if( EXISTS "${CMAKE_SOURCE_DIR}/.tdescmrevision" )
    file( STRINGS "${CMAKE_SOURCE_DIR}/.tdescmrevision" TDE_SCM_MODULE_REVISION )
  endif( EXISTS "${CMAKE_SOURCE_DIR}/.tdescmrevision" )

  message( STATUS "  found 'TDE', version ${TDE_VERSION}" )

endif( NOT TDE_FOUND )

include( "${TDE_CMAKE_DIR}/tdelibs.cmake" )
