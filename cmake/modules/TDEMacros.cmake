#################################################
#
#  (C) 2010-2012 Serghei Amelian
#  serghei (DOT) amelian (AT) gmail.com
#
#  (C) 2011-2012 Timothy Pearson
#  kb9vqf (AT) pearsoncomputing.net
#
#  Improvements and feedback are welcome
#
#  This file is released under GPL >= 2
#
#################################################

include( KDE3Macros ) # we will need this module for a while
include( CheckCXXCompilerFlag )


#################################################
#####
##### tde_message_fatal

macro( tde_message_fatal )
  message( FATAL_ERROR
    "#################################################\n"
    " ${ARGV}\n"
    "#################################################" )
endmacro( tde_message_fatal )


#################################################
#####
##### tde_get_arg( <ARG_NAME> <COUNT> <RETURN> <REST> <ARGS...> )
##### ARG_NAME(string): name of an argument to find in ARGS
##### COUNT(number): argument dimension, a number of items returned in RETURN
##### RETURN(list ref): items returned for argument as they found in ARGS
##### REST(list ref): rest of items except argument name and items returned in RETURN
##### ARGS(list): source list of arguments

macro( tde_get_arg ARG_NAME COUNT RETURN REST )
  unset( ${RETURN} )
  unset( ${REST} )
  list( APPEND ${REST} ${ARGN} )
  list( FIND ${REST} ${ARG_NAME} _arg_idx)
  if( NOT ${_arg_idx} EQUAL -1 )
    list( REMOVE_AT ${REST} ${_arg_idx} )
    set( _i 0 )
    while( ${_i} LESS ${COUNT} )
      list( GET ${REST} ${_arg_idx} _arg )
      list( REMOVE_AT ${REST} ${_arg_idx} )
      list( APPEND ${RETURN} ${_arg} )
      math( EXPR _i "${_i} + 1" )
    endwhile()
  endif()
endmacro( tde_get_arg )


################################################
#####
##### tde_execute_process( <ARGS...> [MESSAGE <MSG>] )
##### MSG: fatal error message (standard message will be written if not supplied)
##### ARGS: execute_process arguments

macro( tde_execute_process )
  tde_get_arg( MESSAGE 1 _message _rest_args ${ARGV} )
  tde_get_arg( RESULT_VARIABLE 1 _result_variable _tmp ${_rest_args} )
  tde_get_arg( COMMAND 1 _command _tmp ${_rest_args} )
  tde_get_arg( OUTPUT_VARIABLE 1 _output_variable _tmp ${_rest_args} )
  tde_get_arg( CACHE 3 _cache _rest_args2 ${_rest_args} )

  # handle optional FORCE parameter
  if( DEFINED _cache )
    list( GET _cache 2 _tmp )
    if( _tmp STREQUAL FORCE )
      set( _rest_args ${_rest_args2} )
    else()
      tde_get_arg( CACHE 2 _cache _rest_args ${_rest_args} )
    endif()
  endif()

  if( NOT DEFINED _result_variable )
    list( APPEND _rest_args RESULT_VARIABLE _exec_result )
    set( _result_variable _exec_result )
  endif()

  execute_process( ${_rest_args} )

  if( DEFINED _output_variable AND DEFINED _cache )
    set( ${_output_variable} ${${_output_variable}} CACHE ${_cache} )
  endif()

  if( ${_result_variable} )
    if( DEFINED _message )
      tde_message_fatal( ${_message} )
    else()
      if( ${${_result_variable}} MATCHES "^[0-9]+$" )
        set( ${_result_variable} "status ${${_result_variable}} returned!" )
      endif()
      tde_message_fatal( "Error executing '${_command}': ${${_result_variable}}" )
    endif()
  endif()
endmacro( tde_execute_process )


if( DEFINED MASTER_SOURCE_DIR )
  return( )
endif( )
########### slave part ends here ###############


################################################
#####
##### CMP0026 states we should not read the LOCATION property of a target,
##### and should be using generators instead. We can't do that here however
##### because we need the value of the property at configure time.

if( POLICY CMP0026 )
  cmake_policy( PUSH )
  cmake_policy( SET CMP0026 OLD )
endif( POLICY CMP0026 )


################################################
#####
##### tde_install_icons( <icons...> THEME <svgicons> DESTINATION <destdir> )
##### default theme: hicolor
##### default destination: ${SHARE_INSTALL_DIR}/icons

macro( tde_install_icons )
  tde_get_arg( DESTINATION 1 _dest _args ${ARGV} )
  tde_get_arg( THEME 1 _req_theme _icons ${_args} )

  #defaults
  if( NOT _icons )
    set( _icons "*" )
  endif( NOT _icons )
  if( NOT _dest )
    set( _dest "${ICON_INSTALL_DIR}" )
  endif( NOT _dest )

  foreach( _icon ${_icons} )
    unset( _theme ) # clearing

    file(GLOB _icon_files *-${_icon}.png *-${_icon}.mng _icon_files *-${_icon}.svg* )
    foreach( _icon_file ${_icon_files} )
      # FIXME need a review
      string( REGEX MATCH "^.*/([a-zA-Z][a-zA-Z])([0-9a-zA-Z]+)\\-([a-z]+)\\-([^/]+)$" _dummy  "${_icon_file}" )
      set( _type  "${CMAKE_MATCH_1}" )
      set( _size  "${CMAKE_MATCH_2}" )
      set( _group "${CMAKE_MATCH_3}" )
      set( _name  "${CMAKE_MATCH_4}" )

      # we must ignore invalid icon names
      if( _type AND _size AND _group AND _name )

        # autodetect theme
        if( NOT _req_theme )
          unset( _theme )
          if( "${_type}" STREQUAL "cr" )
            set( _theme crystalsvg )
          elseif( "${_type}" STREQUAL "lo" )
            set( _theme locolor )
          endif( "${_type}" STREQUAL "cr" )
          # defaulting
          if( NOT _theme )
            set( _theme hicolor )
          endif( NOT _theme )
        else( NOT _req_theme )
          set( _theme ${_req_theme} )
        endif( NOT _req_theme )

        # fix "group" name
        if( "${_group}" STREQUAL "mime" )
          set( _group  "mimetypes" )
        endif( "${_group}" STREQUAL "mime" )
        if( "${_group}" STREQUAL "filesys" )
          set( _group  "places" )
        endif( "${_group}" STREQUAL "filesys" )
        if( "${_group}" STREQUAL "category" )
          set( _group  "categories" )
        endif( "${_group}" STREQUAL "category" )
        if( "${_group}" STREQUAL "device" )
          set( _group  "devices" )
        endif( "${_group}" STREQUAL "device" )
        if( "${_group}" STREQUAL "app" )
          set( _group  "apps" )
        endif( "${_group}" STREQUAL "app" )
        if( "${_group}" STREQUAL "action" )
          set( _group  "actions" )
        endif( "${_group}" STREQUAL "action" )

        if( "${_size}" STREQUAL "sc" )
          install( FILES ${_icon_file} DESTINATION ${_dest}/${_theme}/scalable/${_group}/ RENAME ${_name} )
        else( "${_size}" STREQUAL "sc" )
          install( FILES ${_icon_file} DESTINATION ${_dest}/${_theme}/${_size}x${_size}/${_group}/ RENAME ${_name} )
        endif( "${_size}" STREQUAL "sc" )

      endif( _type AND _size AND _group AND _name )

    endforeach( _icon_file )
  endforeach( _icon )

endmacro( tde_install_icons )


#################################################
#####
##### tde_add_lut( <source> <result> [depends] )
##### default depends: source

macro( tde_add_lut _src _lut _dep )
  set( create_hash_table ${CMAKE_SOURCE_DIR}/kjs/create_hash_table )
  if( NOT _dep )
    set( _dep ${_src} )
  endif( NOT _dep )
  add_custom_command( OUTPUT ${_lut}
    COMMAND perl ARGS ${create_hash_table} ${CMAKE_CURRENT_SOURCE_DIR}/${_src} -i > ${_lut}
    DEPENDS ${_src} )
  set_source_files_properties( ${_dep} PROPERTIES OBJECT_DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${_lut} )
  unset( _dep )
endmacro( tde_add_lut )


#################################################
#####
##### tde_add_luts( <sources...> )

macro( tde_add_luts )
  foreach( _src ${ARGV} )
    get_filename_component( _lut ${_src} NAME_WE )
    set( _lut "${_lut}.lut.h" )
    tde_add_lut( ${_src} ${_lut} ${_src} )
  endforeach( _src )
endmacro( tde_add_luts )


#################################################
#####
##### tde_file_to_cpp( <source> <destination> <variable> )

macro( tde_file_to_cpp _src _dst _var )
  if( IS_ABSOLUTE ${_dst} )
    set( dst ${_dst} )
  else( )
    set( dst "${CMAKE_CURRENT_BINARY_DIR}/${_dst}" )
  endif( )
  file( READ ${_src} text )
  string( REGEX REPLACE "\n" "\\\\n\"\n\"" text "${text}" )
  set( text "/* Generated by CMake */\n\nconst char *${_var} = \n\n\"${text}\";\n" )
  string( REGEX REPLACE "\n\"\";\n$" ";\n" text "${text}" )
  file( WRITE ${dst} "${text}" )
endmacro( )


#################################################
#####
##### tde_install_la_file( <target> <destination> )

macro( tde_install_la_file _target _destination )

  get_target_property( _target_location ${_target} LOCATION )
  get_filename_component( _laname ${_target_location} NAME_WE )
  get_filename_component( _soname ${_target_location} NAME )
  set( _laname ${CMAKE_CURRENT_BINARY_DIR}/${_laname}.la )

  file( WRITE ${_laname}
"# ${_laname} - a libtool library file, generated by cmake
# The name that we can dlopen(3).
dlname='${_soname}'
# Names of this library
library_names='${_soname} ${_soname} ${_soname}'
# The name of the static archive
old_library=''
# Libraries that this one depends upon.
dependency_libs=''
# Version information.\ncurrent=0\nage=0\nrevision=0
# Is this an already installed library?\ninstalled=yes
# Should we warn about portability when linking against -modules?\nshouldnotlink=yes
# Files to dlopen/dlpreopen\ndlopen=''\ndlpreopen=''
# Directory that this library needs to be installed in:
libdir='${_destination}'
" )

  install( FILES ${_laname} DESTINATION ${_destination} )

endmacro( tde_install_la_file )


#################################################
#####
##### tde_add_ui_files

macro( tde_add_ui_files _sources )
  foreach( _ui_file ${ARGN} )

    get_filename_component( _ui_basename ${_ui_file} NAME_WE )
    get_filename_component( _ui_absolute_path ${_ui_file} ABSOLUTE )

    list( APPEND ${_sources} ${_ui_basename}.cpp )

    add_custom_command( OUTPUT ${_ui_basename}.h ${_ui_basename}.cpp
      COMMAND ${CMAKE_COMMAND}
        -DUIC_EXECUTABLE:FILEPATH=${UIC_EXECUTABLE}
        -DQT_REPLACE_SCRIPT:FILEPATH=${QT_REPLACE_SCRIPT}
        -DTDE_QTPLUGINS_DIR:FILEPATH=${TDE_QTPLUGINS_DIR}
        -DUI_FILE:FILEPATH=${_ui_absolute_path}
        -DMASTER_SOURCE_DIR:FILEPATH=${CMAKE_SOURCE_DIR}
        -DMASTER_BINARY_DIR:FILEPATH=${CMAKE_BINARY_DIR}
        -P ${CMAKE_MODULE_PATH}/tde_uic.cmake
      COMMAND ${MOC_EXECUTABLE} ${_ui_basename}.h >> ${_ui_basename}.cpp
      DEPENDS ${_ui_absolute_path} )

  endforeach( _ui_file )
endmacro( tde_add_ui_files )


#################################################
#####
##### tde_moc

macro( tde_moc _sources )
  foreach( _input_file ${ARGN} )

    get_filename_component( _input_file "${_input_file}" ABSOLUTE )
    get_filename_component( _basename ${_input_file} NAME_WE )
    set( _output_file "${_basename}.moc.cpp" )
    add_custom_command( OUTPUT ${_output_file}
      COMMAND
        ${TMOC_EXECUTABLE} ${_input_file} -o ${_output_file}
      DEPENDS
        ${_input_file} )
    list( APPEND ${_sources} ${_output_file} )

  endforeach( )
endmacro( )


#################################################
#####
##### tde_automoc

macro( tde_automoc )
  foreach( _src_file ${ARGN} )

    get_filename_component( _src_file "${_src_file}" ABSOLUTE )

    if( EXISTS "${_src_file}" )

      # read source file and check if have moc include
      file( READ "${_src_file}" _src_content )
      string( REGEX MATCHALL "#include +[^ ]+\\.moc[\">]" _moc_includes "${_src_content}" )

      # found included moc(s)?
      if( _moc_includes )
        foreach( _moc_file ${_moc_includes} )

          # extracting moc filename
          string( REGEX MATCH "[^ <\"]+\\.moc" _moc_file "${_moc_file}" )
          set( _moc_file "${CMAKE_CURRENT_BINARY_DIR}/${_moc_file}" )

          # create header filename
          get_filename_component( _src_path "${_src_file}" ABSOLUTE )
          get_filename_component( _src_path "${_src_path}" PATH )
          get_filename_component( _src_header "${_moc_file}" NAME_WE )
          set( _header_file "${_src_path}/${_src_header}.h" )

          # if header doesn't exists, check in META_INCLUDES
          if( NOT EXISTS "${_header_file}" )
            unset( _found )
            foreach( _src_path ${_meta_includes} )
              set( _header_file "${_src_path}/${_src_header}.h" )
              if( EXISTS "${_header_file}" )
                set( _found 1 )
                break( )
              endif( )
            endforeach( )
            if( NOT _found )
              get_filename_component( _moc_file "${_moc_file}" NAME )
              tde_message_fatal( "AUTOMOC error: '${_moc_file}' cannot be generated.\n Reason: '${_src_file}.h' not found." )
            endif( )
          endif( )

          # moc-ing header
          add_custom_command( OUTPUT ${_moc_file}
            COMMAND ${TMOC_EXECUTABLE} ${_header_file} -o ${_moc_file}
            DEPENDS ${_header_file} )

          # create dependency between source file and moc file
          set_property( SOURCE ${_src_file} APPEND PROPERTY OBJECT_DEPENDS ${_moc_file} )

        endforeach( _moc_file )

      endif( _moc_includes )

    endif( EXISTS "${_src_file}" )

  endforeach( _src_file )
endmacro( tde_automoc )


#################################################
#####
##### __tde_internal_process_sources

macro( __tde_internal_process_sources _sources )

  unset( ${_sources} )

  foreach( _arg ${ARGN} )
    get_filename_component( _ext ${_arg} EXT )
    get_filename_component( _name ${_arg} NAME_WE )
    get_filename_component( _path ${_arg} PATH )

    # if not path, set it to "."
    if( NOT _path )
      set( _path "./" )
    endif( NOT _path )

    # handle .ui files
    if( ${_ext} STREQUAL ".ui" )
      tde_add_ui_files( ${_sources} ${_arg} )

    # handle .skel files
    elseif( ${_ext} STREQUAL ".skel" )
      kde3_add_dcop_skels( ${_sources} ${_path}/${_name}.h )

    # handle .stub files
    elseif( ${_ext} STREQUAL ".stub" )
      kde3_add_dcop_stubs( ${_sources} ${_path}/${_name}.h )

    # handle .kcfgc files
    elseif( ${_ext} STREQUAL ".kcfgc" )
      kde3_add_kcfg_files( ${_sources} ${_arg} )

    # handle any other files
    else( ${_ext} STREQUAL ".ui" )
      list(APPEND ${_sources} ${_arg} )
    endif( ${_ext} STREQUAL ".ui" )
  endforeach( _arg )

endmacro( __tde_internal_process_sources )


#################################################
#####
##### tde_install_libtool_file

macro( tde_install_libtool_file _target _destination )

  get_target_property( _target_location ${_target} LOCATION )

  # get name of target
  get_filename_component( _name ${_target_location} NAME_WE )

  # get .la name
  set( _laname ${_name}.la )

  # get .so name
  get_filename_component( _soname ${_target_location} NAME )

  # get version of target
  get_target_property( _target_version ${_target} VERSION )
  get_target_property( _target_soversion ${_target} SOVERSION )

  # we have so version
  if( _target_version )
    set( _library_name_1 "${_soname}.${_target_version}" )
    set( _library_name_2 "${_soname}.${_target_soversion}" )
    set( _library_name_3 "${_soname}" )

    string( REGEX MATCH "^([0-9]+)\\.([0-9]+)\\.([0-9]+)$" _dummy  "${_target_version}" )
    set( _version_current  "${CMAKE_MATCH_1}" )
    set( _version_age  "${CMAKE_MATCH_2}" )
    set( _version_revision "${CMAKE_MATCH_3}" )

  # we have no so version (module?)
  else( _target_version )
    set( _library_name_1 "${_soname}" )
    set( _library_name_2 "${_soname}" )
    set( _library_name_3 "${_soname}" )
    set( _version_current  "0" )
    set( _version_age  "0" )
    set( _version_revision "0" )
  endif( _target_version )

  if( IS_ABSOLUTE ${_destination} )
    set( _libdir "${_destination}" )
  else( IS_ABSOLUTE ${_destination} )
    set( _libdir "${CMAKE_INSTALL_PREFIX}/${_destination}" )
  endif( IS_ABSOLUTE ${_destination} )

  configure_file( ${CMAKE_SOURCE_DIR}/cmake/modules/template_libtool_file.cmake "${_laname}" @ONLY )

  install( FILES "${CMAKE_CURRENT_BINARY_DIR}/${_laname}" DESTINATION ${_destination} )

endmacro( tde_install_libtool_file )


#################################################
#####
##### tde_install_export / tde_import

function( tde_install_export )
  file( GLOB export_files ${CMAKE_CURRENT_BINARY_DIR}/export-*.cmake )

  set( mode "WRITE" )
  foreach( filename ${export_files} )
    file( READ ${filename} content )
    file( ${mode} "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.cmake" "${content}" )
    set( mode "APPEND" )
  endforeach( )

  install( FILES "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.cmake" DESTINATION ${CMAKE_INSTALL_DIR} )
endfunction( )


macro( tde_import _library )
  message( STATUS "checking for '${_library}'" )
  string( TOUPPER "BUILD_${_library}" _build )
  if( ${_build} )
    message( STATUS "  ok, activated for build" )
  else()
    if( EXISTS "${TDE_CMAKE_DIR}/${_library}.cmake" )
      include( "${TDE_CMAKE_DIR}/${_library}.cmake" )
      message( STATUS "  ok, found import file" )
    else()
      tde_message_fatal( "'${_library}' are required,\n but is not installed nor selected for build" )
    endif()
  endif()
endmacro()


#################################################
#####
##### tde_add_library

macro( tde_add_library _arg_target )

  unset( _target )
  unset( _type )
  unset( _static_pic )
  unset( _automoc )
  unset( _meta_includes )
  unset( _no_libtool_file )
  unset( _no_export )
  unset( _version )
  unset( _sources )
  unset( _destination )
  unset( _embed )
  unset( _link )
  unset( _dependencies )
  unset( _storage )

  set( _shouldnotlink no )

  # metadata
  unset( _description )
  unset( _license )
  unset( _copyright )
  unset( _authors )
  unset( _product )
  unset( _organization )
  unset( _version )
  unset( _datetime )
  unset( _notes )

  # default metadata
  set( _product "Trinity Desktop Environment" )
  tde_curdatetime( _datetime )

  foreach( _arg ${ARGV} )

    # this variable help us to skip
    # storing unapropriate values (i.e. directives)
    unset( _skip_store )

    # found one of directives: "SHARED", "STATIC", "MODULE"
    if( "+${_arg}" STREQUAL "+SHARED" OR "+${_arg}" STREQUAL "+STATIC" OR "+${_arg}" STREQUAL "+MODULE" )
      set( _skip_store 1 )
      set( _type "${_arg}" )
    endif( "+${_arg}" STREQUAL "+SHARED" OR "+${_arg}" STREQUAL "+STATIC" OR "+${_arg}" STREQUAL "+MODULE" )

    # found directive "STATIC_PIC"
    if( "+${_arg}" STREQUAL "+STATIC_PIC" )
      set( _skip_store 1 )
      set( _type "STATIC" )
      set( _static_pic 1 )
    endif( "+${_arg}" STREQUAL "+STATIC_PIC" )

    # found directive "AUTOMOC"
    if( "+${_arg}" STREQUAL "+AUTOMOC" )
      set( _skip_store 1 )
      set( _automoc 1 )
    endif( "+${_arg}" STREQUAL "+AUTOMOC" )

    # found directive "META_INCLUDES"
    if( "+${_arg}" STREQUAL "+META_INCLUDES" )
      set( _skip_store 1 )
      set( _storage "_meta_includes" )
    endif( )

    # found directive "NO_LIBTOOL_FILE"
    if( "+${_arg}" STREQUAL "+NO_LIBTOOL_FILE" )
      set( _skip_store 1 )
      set( _no_libtool_file 1 )
    endif( "+${_arg}" STREQUAL "+NO_LIBTOOL_FILE" )

    # found directive "NO_EXPORT"
    if( "+${_arg}" STREQUAL "+NO_EXPORT" )
      set( _skip_store 1 )
      set( _no_export 1 )
    endif( "+${_arg}" STREQUAL "+NO_EXPORT" )

    # found directive "VERSION"
    if( "+${_arg}" STREQUAL "+VERSION" )
      set( _skip_store 1 )
      set( _storage "_version" )
    endif( "+${_arg}" STREQUAL "+VERSION" )

    # found directive "SOURCES"
    if( "+${_arg}" STREQUAL "+SOURCES" )
      set( _skip_store 1 )
      set( _storage "_sources" )
    endif( "+${_arg}" STREQUAL "+SOURCES" )

    # found directive "EMBED"
    if( "+${_arg}" STREQUAL "+EMBED" )
      set( _skip_store 1 )
      set( _storage "_embed" )
    endif( "+${_arg}" STREQUAL "+EMBED" )

    # found directive "LINK"
    if( "+${_arg}" STREQUAL "+LINK" )
      set( _skip_store 1 )
      set( _storage "_link" )
    endif( "+${_arg}" STREQUAL "+LINK" )

    # found directive "DEPENDENCIES"
    if( "+${_arg}" STREQUAL "+DEPENDENCIES" )
      set( _skip_store 1 )
      set( _storage "_dependencies" )
    endif( "+${_arg}" STREQUAL "+DEPENDENCIES" )

    # found directive "DESTINATION"
    if( "+${_arg}" STREQUAL "+DESTINATION" )
      set( _skip_store 1 )
      set( _storage "_destination" )
      unset( ${_storage} )
    endif( "+${_arg}" STREQUAL "+DESTINATION" )

   # metadata
    if( "+${_arg}" STREQUAL "+DESCRIPTION" )
      set( _skip_store 1 )
      set( _storage "_description" )
    endif( )
    if( "+${_arg}" STREQUAL "+LICENSE" )
      set( _skip_store 1 )
      set( _storage "_license" )
    endif( )
    if( "+${_arg}" STREQUAL "+COPYRIGHT" )
      set( _skip_store 1 )
      set( _storage "_copyright" )
    endif( )
    if( "+${_arg}" STREQUAL "+AUTHORS" )
      set( _skip_store 1 )
      set( _storage "_authors" )
    endif( )
    if( "+${_arg}" STREQUAL "+PRODUCT" )
      set( _skip_store 1 )
      set( _storage "_product" )
    endif( )
    if( "+${_arg}" STREQUAL "+ORGANIZATION" )
      set( _skip_store 1 )
      set( _storage "_organization" )
    endif( )
    if( "+${_arg}" STREQUAL "+VERSION" )
      set( _skip_store 1 )
      set( _storage "_version" )
    endif( )
    if( "+${_arg}" STREQUAL "+DATETIME" )
      set( _skip_store 1 )
      set( _storage "_datetime" )
    endif( )
    if( "+${_arg}" STREQUAL "+NOTES" )
      set( _skip_store 1 )
      set( _storage "_notes" )
    endif( )

    # storing value
    if( _storage AND NOT _skip_store )
      list( APPEND ${_storage} ${_arg} )
      list( REMOVE_DUPLICATES ${_storage} )
    endif( _storage AND NOT _skip_store )

  endforeach( _arg )

  # if no type is set, we choose one
  # based on BUILD_SHARED_LIBS
  if( NOT _type )
    if( BUILD_SHARED_LIBS )
      set( _type "SHARED" )
    else( BUILD_SHARED_LIBS )
      set( _type "STATIC" )
    endif( BUILD_SHARED_LIBS )
  endif( NOT _type )

  # change target name, based on type
  string( TOLOWER "${_type}" _type_lower )
  set( _target "${_arg_target}-${_type_lower}" )

  # create variables like "LIB_xxx" for convenience
  if( ${_type} STREQUAL "SHARED" )
    string( TOUPPER "${_arg_target}" _tmp )
    set( LIB_${_tmp} ${_target} CACHE INTERNAL LIB_${tmp} FORCE )
  endif( ${_type} STREQUAL "SHARED" )

  # disallow target without sources
  if( NOT _sources )
    message( FATAL_ERROR "\nTarget [$_target] have no sources." )
  endif( NOT _sources )

  # processing different types of sources
  __tde_internal_process_sources( _sources ${_sources} )

  # set automoc
  if( _automoc )
    tde_automoc( ${_sources} )
  endif( _automoc )

  # add target
  add_library( ${_target} ${_type} ${_sources} )

  # we assume that modules have no prefix and no version
  # also, should not link
  if( ${_type} STREQUAL "MODULE" )
    set_target_properties( ${_target} PROPERTIES PREFIX "" )
    unset( _version )
    set( _shouldnotlink yes )
  endif( ${_type} STREQUAL "MODULE" )

  # set real name of target
  set_target_properties( ${_target} PROPERTIES OUTPUT_NAME ${_arg_target} )

  # set -fPIC flag for static libraries
  if( _static_pic )
    set_target_properties( ${_target} PROPERTIES COMPILE_FLAGS -fPIC )
  endif( _static_pic )

  # set version
  if( _version )
    if( ${CMAKE_SYSTEM_NAME} STREQUAL "OpenBSD" )
      # OpenBSD: _soversion and _version both contains only major and minor
      string( REGEX MATCH "^([0-9]+)\\.([0-9]+)\\.([0-9]+)$" _dummy  "${_version}" )
      set( _version  "${CMAKE_MATCH_1}.${CMAKE_MATCH_2}" )
      set( _soversion  "${CMAKE_MATCH_1}.${CMAKE_MATCH_2}" )
    else( ${CMAKE_SYSTEM_NAME} STREQUAL "OpenBSD" )
      # General (Linux) case: _soversion contains only the major number of version
      string( REGEX MATCH "^[0-9]+" _soversion ${_version} )
    endif( ${CMAKE_SYSTEM_NAME} STREQUAL "OpenBSD" )
    set_target_properties( ${_target} PROPERTIES VERSION ${_version} SOVERSION ${_soversion} )
  endif( _version )

  # set interface libraries (only for shared)
  unset( _shared_libs )
  if( NOT ${_type} STREQUAL "STATIC" )
    foreach( _lib ${_link} )
      #get_target_property( _lib_type ${_lib} TYPE )
      #if( NOT "STATIC_LIBRARY" STREQUAL "${_lib_type}" )
      if( NOT ${_lib} MATCHES ".+-static" )
        list( APPEND _shared_libs ${_lib} )
      endif( NOT ${_lib} MATCHES ".+-static" )
      #endif( NOT "STATIC_LIBRARY" STREQUAL "${_lib_type}" )
    endforeach( _lib )
  endif( NOT ${_type} STREQUAL "STATIC" )

  # set embedded archives
  if( _embed )
    list( INSERT _link 0 -Wl,-whole-archive ${_embed} -Wl,-no-whole-archive )
  endif( _embed )

  # set link libraries
  if( _link )
    if( _embed AND ${CMAKE_VERSION} VERSION_EQUAL "2.8.12.0" )
      # hack for broken CMake 2.8.12.0
      set_target_properties( ${_target} PROPERTIES LINK_LIBRARIES "${_link}" )
    else( _embed AND  ${CMAKE_VERSION} VERSION_EQUAL "2.8.12.0" )
      target_link_libraries( ${_target} ${_link} )
    endif( _embed AND  ${CMAKE_VERSION} VERSION_EQUAL "2.8.12.0" )
  endif( )
  if( _shared_libs )
    set_target_properties( ${_target} PROPERTIES
                           LINK_INTERFACE_LIBRARIES "${_shared_libs}"
                           INTERFACE_LINK_LIBRARIES "${_shared_libs}" )
  endif( _shared_libs )

  # set dependencies
  if( _dependencies )
    add_dependencies( ${_target} ${_dependencies} )
  endif( _dependencies )

  # if destination directory is set
  if( _destination )

    # we export only shared libs (no static, no modules);
    # also, do not export targets marked as "NO_EXPORT" (usually for tdeinit)
    if( "SHARED" STREQUAL ${_type} AND NOT _no_export )

      # get target properties: output name, version, soversion
      get_target_property( _output ${_target} LOCATION )
      get_filename_component( _output ${_output} NAME )
      get_target_property( _version ${_target} VERSION )
      get_target_property( _soversion ${_target} SOVERSION )

      if( _version )
        set( _location "${_destination}/${_output}.${_version}" )
        set( _soname "${_output}.${_soversion}" )
      else( )
        set( _location "${_destination}/${_output}" )
        set( _soname "${_output}" )
      endif( )

      configure_file( ${CMAKE_SOURCE_DIR}/cmake/modules/template_export_library.cmake "${PROJECT_BINARY_DIR}/export-${_target}.cmake" @ONLY )
    endif( )

    # install target
    install( TARGETS ${_target} DESTINATION ${_destination} )

    # install .la files for dynamic libraries
    if( NOT "STATIC" STREQUAL ${_type} AND NOT _no_libtool_file )
      tde_install_libtool_file( ${_target} ${_destination} )
    endif( )

  endif( _destination )

  # embed name and metadata
  set( ELF_EMBEDDING_METADATA "\"${_target}\" \"${_description}\" \"${_license}\" \"${_copyright}\" \"${_authors}\" \"${_product}\" \"${_organization}\" \"${_version}\" \"${_datetime}\" \"x-sharedlib\" \"${TDE_SCM_MODULE_NAME}\" \"${TDE_SCM_MODULE_REVISION}\" \"${_notes}\"" )
  separate_arguments( ELF_EMBEDDING_METADATA )
  if( EXISTS ${CMAKE_INSTALL_PREFIX}/bin/tdelfeditor )
    add_custom_command(
      TARGET ${_target}
      POST_BUILD
      COMMAND ${CMAKE_INSTALL_PREFIX}/bin/tdelfeditor -m ${CMAKE_CURRENT_BINARY_DIR}/${_soname} ${ELF_EMBEDDING_METADATA} || true
      COMMAND ${CMAKE_INSTALL_PREFIX}/bin/tdelfeditor -e ${CMAKE_CURRENT_BINARY_DIR}/${_soname} || true
    )
    if( _version )
      add_custom_command(
        TARGET ${_target}
        POST_BUILD
        COMMAND ${CMAKE_INSTALL_PREFIX}/bin/tdelfeditor -m ${CMAKE_CURRENT_BINARY_DIR}/${_soname}.${_version} ${ELF_EMBEDDING_METADATA} || true
        COMMAND ${CMAKE_INSTALL_PREFIX}/bin/tdelfeditor -e ${CMAKE_CURRENT_BINARY_DIR}/${_soname}.${_version} || true
      )
    endif( )
  endif( EXISTS ${CMAKE_INSTALL_PREFIX}/bin/tdelfeditor )

endmacro( tde_add_library )


#################################################
#####
##### tde_add_kpart

macro( tde_add_kpart _target )
  tde_add_library( ${_target} ${ARGN} MODULE )
endmacro( tde_add_kpart )


#################################################
#####
##### tde_curdatetime
macro( tde_curdatetime result )
  tde_execute_process( COMMAND "date" "+%m/%d/%Y %H:%M:%S" OUTPUT_VARIABLE ${result} )
  string( REGEX REPLACE "(..)/(..)/(....) (........).*" "\\1/\\2/\\3 \\4" ${result} ${${result}} )
endmacro( tde_curdatetime )


#################################################
#####
##### tde_add_executable

macro( tde_add_executable _arg_target )

  unset( _target )
  unset( _automoc )
  unset( _meta_includes )
  unset( _setuid )
  unset( _sources )
  unset( _destination )
  unset( _link )
  unset( _dependencies )
  unset( _storage )

  # metadata
  unset( _description )
  unset( _license )
  unset( _copyright )
  unset( _authors )
  unset( _product )
  unset( _organization )
  unset( _version )
  unset( _datetime )
  unset( _notes )

  # default metadata
  set( _product "Trinity Desktop Environment" )
  set( _version "${TDE_VERSION}" )
  tde_curdatetime( _datetime )

  foreach( _arg ${ARGV} )

    # this variable help us to skip
    # storing unapropriate values (i.e. directives)
    unset( _skip_store )

    # found directive "AUTOMOC"
    if( "+${_arg}" STREQUAL "+AUTOMOC" )
      set( _skip_store 1 )
      set( _automoc 1 )
    endif( "+${_arg}" STREQUAL "+AUTOMOC" )

    # found directive "META_INCLUDES"
    if( "+${_arg}" STREQUAL "+META_INCLUDES" )
      set( _skip_store 1 )
      set( _storage "_meta_includes" )
    endif( )

    # found directive "SETUID"
    if( "+${_arg}" STREQUAL "+SETUID" )
      set( _skip_store 1 )
      set( _setuid 1 )
    endif( "+${_arg}" STREQUAL "+SETUID" )

    # found directive "SOURCES"
    if( "+${_arg}" STREQUAL "+SOURCES" )
      set( _skip_store 1 )
      set( _storage "_sources" )
    endif( "+${_arg}" STREQUAL "+SOURCES" )

    # found directive "LINK"
    if( "+${_arg}" STREQUAL "+LINK" )
      set( _skip_store 1 )
      set( _storage "_link" )
    endif( "+${_arg}" STREQUAL "+LINK" )

    # found directive "DEPENDENCIES"
    if( "+${_arg}" STREQUAL "+DEPENDENCIES" )
      set( _skip_store 1 )
      set( _storage "_dependencies" )
    endif( "+${_arg}" STREQUAL "+DEPENDENCIES" )

    # found directive "DESTINATION"
    if( "+${_arg}" STREQUAL "+DESTINATION" )
      set( _skip_store 1 )
      set( _storage "_destination" )
      unset( ${_storage} )
    endif( "+${_arg}" STREQUAL "+DESTINATION" )

    # metadata
    if( "+${_arg}" STREQUAL "+DESCRIPTION" )
      set( _skip_store 1 )
      set( _storage "_description" )
    endif( )
    if( "+${_arg}" STREQUAL "+LICENSE" )
      set( _skip_store 1 )
      set( _storage "_license" )
    endif( )
    if( "+${_arg}" STREQUAL "+COPYRIGHT" )
      set( _skip_store 1 )
      set( _storage "_copyright" )
    endif( )
    if( "+${_arg}" STREQUAL "+AUTHORS" )
      set( _skip_store 1 )
      set( _storage "_authors" )
    endif( )
    if( "+${_arg}" STREQUAL "+PRODUCT" )
      set( _skip_store 1 )
      set( _storage "_product" )
    endif( )
    if( "+${_arg}" STREQUAL "+ORGANIZATION" )
      set( _skip_store 1 )
      set( _storage "_organization" )
    endif( )
    if( "+${_arg}" STREQUAL "+VERSION" )
      set( _skip_store 1 )
      set( _storage "_version" )
    endif( )
    if( "+${_arg}" STREQUAL "+DATETIME" )
      set( _skip_store 1 )
      set( _storage "_datetime" )
    endif( )
    if( "+${_arg}" STREQUAL "+NOTES" )
      set( _skip_store 1 )
      set( _storage "_notes" )
    endif( )

    # storing value
    if( _storage AND NOT _skip_store )
      #set( ${_storage} "${${_storage}} ${_arg}" )
      list( APPEND ${_storage} ${_arg} )
    endif( _storage AND NOT _skip_store )

  endforeach( _arg )

  set( _target "${_arg_target}" )

  # disallow target without sources
  if( NOT _sources )
    message( FATAL_ERROR "\nTarget [$_target] have no sources." )
  endif( NOT _sources )

  # processing different types of sources
  __tde_internal_process_sources( _sources ${_sources} )

  # set automoc
  if( _automoc )
    tde_automoc( ${_sources} )
  endif( _automoc )

  # add target
  add_executable( ${_target} ${_sources} )

  # set link libraries
  if( _link )
    target_link_libraries( ${_target} ${_link} )
  endif( _link )

  # set dependencies
  if( _dependencies )
    add_dependencies( ${_target} ${_dependencies} )
  endif( _dependencies )

  # set PIE flags for setuid binaries
  if( _setuid )
    set_target_properties( ${_target} PROPERTIES COMPILE_FLAGS "${TDE_PIE_CFLAGS}" )
    set_target_properties( ${_target} PROPERTIES LINK_FLAGS "${TDE_PIE_LDFLAGS}" )
  endif( _setuid )

  # set destination directory
  if( _destination )
    if( _setuid )
      install( TARGETS ${_target} DESTINATION ${_destination} PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_EXECUTE WORLD_EXECUTE SETUID )
    else( _setuid )
      install( TARGETS ${_target} DESTINATION ${_destination} )
    endif( _setuid )
  endif( _destination )

  # embed icon, name, and metadata
  set( ELF_EMBEDDING_METADATA "\"${_target}\" \"${_description}\" \"${_license}\" \"${_copyright}\" \"${_authors}\" \"${_product}\" \"${_organization}\" \"${_version}\" \"${_datetime}\" \"${_target}\" \"${TDE_SCM_MODULE_NAME}\" \"${TDE_SCM_MODULE_REVISION}\" \"${_notes}\"" )
  separate_arguments( ELF_EMBEDDING_METADATA )
  if( EXISTS ${CMAKE_INSTALL_PREFIX}/bin/tdelfeditor )
    add_custom_command(
      TARGET ${_target}
      POST_BUILD
      COMMAND ${CMAKE_INSTALL_PREFIX}/bin/tdelfeditor -m ${CMAKE_CURRENT_BINARY_DIR}/${_target} ${ELF_EMBEDDING_METADATA} || true
      COMMAND ${CMAKE_INSTALL_PREFIX}/bin/tdelfeditor -e ${CMAKE_CURRENT_BINARY_DIR}/${_target} || true
      COMMAND ${CMAKE_INSTALL_PREFIX}/bin/tdelfeditor -t ${CMAKE_CURRENT_BINARY_DIR}/${_target} ${_target} || true
    )
  endif( EXISTS ${CMAKE_INSTALL_PREFIX}/bin/tdelfeditor )

endmacro( tde_add_executable )


#################################################
#####
##### tde_add_tdeinit_executable

macro( tde_add_tdeinit_executable _target )

  configure_file( ${CMAKE_SOURCE_DIR}/cmake/modules/template_tdeinit_executable.cmake ${_target}_tdeinit_executable.cpp COPYONLY )
  configure_file( ${CMAKE_SOURCE_DIR}/cmake/modules/template_tdeinit_module.cmake ${_target}_tdeinit_module.cpp COPYONLY )

  unset( _sources )
  unset( _runtime_destination )
  unset( _library_destination )
  unset( _plugin_destination )

  # default storage is _sources
  set( _storage _sources )

  # set default export to NO_EXPORT
  set( _export "NO_EXPORT" )

  foreach( _arg ${ARGN} )

    # this variable help us to skip
    # storing unapropriate values (i.e. directives)
    unset( _skip_store )

    # found directive "EXPORT"
    if( "+${_arg}" STREQUAL "+EXPORT" )
      set( _skip_store 1 )
      unset( _export )
    endif( "+${_arg}" STREQUAL "+EXPORT" )

    # found directive "RUNTIME_DESTINATION"
    if( "+${_arg}" STREQUAL "+RUNTIME_DESTINATION" )
      set( _skip_store 1 )
      set( _storage "_runtime_destination" )
      unset( ${_storage} )
    endif( "+${_arg}" STREQUAL "+RUNTIME_DESTINATION" )

    # found directive "LIBRARY_DESTINATION"
    if( "+${_arg}" STREQUAL "+LIBRARY_DESTINATION" )
      set( _skip_store 1 )
      set( _storage "_library_destination" )
      unset( ${_storage} )
    endif( "+${_arg}" STREQUAL "+LIBRARY_DESTINATION" )

    # found directive "PLUGIN_DESTINATION"
    if( "+${_arg}" STREQUAL "+PLUGIN_DESTINATION" )
      set( _skip_store 1 )
      set( _storage "_plugin_destination" )
      unset( ${_storage} )
    endif( "+${_arg}" STREQUAL "+PLUGIN_DESTINATION" )

    # storing value
    if( _storage AND NOT _skip_store )
      list( APPEND ${_storage} ${_arg} )
      set( _storage "_sources" )
    endif( _storage AND NOT _skip_store )

  endforeach( _arg )

  # if destinations are not set, we using some defaults
  # we assume that tdeinit executable MUST be installed
  # (otherwise why we build it?)
  if( NOT _runtime_destination )
    set( _runtime_destination ${BIN_INSTALL_DIR} )
  endif( NOT _runtime_destination )
  if( NOT _library_destination )
    set( _library_destination ${LIB_INSTALL_DIR} )
  endif( NOT _library_destination )
  if( NOT _plugin_destination )
    set( _plugin_destination ${PLUGIN_INSTALL_DIR} )
  endif( NOT _plugin_destination )

  # create the library
  tde_add_library( tdeinit_${_target} ${_sources} SHARED ${_export}
    DESTINATION ${_library_destination}
  )

  # create the executable
  tde_add_executable( ${_target}
    SOURCES ${CMAKE_CURRENT_BINARY_DIR}/${_target}_tdeinit_executable.cpp
    LINK tdeinit_${_target}-shared
    DESTINATION ${_runtime_destination}
  )

  # create the plugin
  tde_add_kpart( ${_target}
    SOURCES ${CMAKE_CURRENT_BINARY_DIR}/${_target}_tdeinit_module.cpp
    LINK tdeinit_${_target}-shared
    DESTINATION ${_plugin_destination}
  )

endmacro( tde_add_tdeinit_executable )


#################################################
#####
##### tde_create_translation

macro( tde_create_translation )

  unset( _srcs )
  unset( _lang )
  unset( _dest )
  unset( _out_name )
  unset( _directive )
  unset( _var )

  foreach( _arg ${ARGN} )

    # found directive "FILES"
    if( "+${_arg}" STREQUAL "+FILES" )
      unset( _srcs )
      set( _var _srcs )
      set( _directive 1 )
    endif( )

    # found directive "LANG"
    if( "+${_arg}" STREQUAL "+LANG" )
      unset( _lang )
      set( _var _lang )
      set( _directive 1 )
    endif( )

    # found directive "DESTINATION"
    if( "+${_arg}" STREQUAL "+DESTINATION" )
      unset( _dest )
      set( _var _dest )
      set( _directive 1 )
    endif( )

    # found directive "DESTINATION"
    if( "+${_arg}" STREQUAL "+OUTPUT_NAME" )
      unset( _proj )
      set( _var _out_name )
      set( _directive 1 )
    endif( )

    # collect data
    if( _directive )
      unset( _directive )
    elseif( _var )
      list( APPEND ${_var} ${_arg} )
    endif()

  endforeach( )

  if( NOT MSGFMT_EXECUTABLE )
    tde_message_fatal( "MSGFMT_EXECUTABLE variable is not defined" )
  elseif( NOT _lang )
    tde_message_fatal( "missing LANG directive" )
  endif( )

  # if no file specified, include all *.po files
  if( NOT _srcs )
    file( GLOB _srcs RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.po  )
  endif( )
  if( NOT _srcs )
    tde_message_fatal( "no source files" )
  endif( )

  if( NOT _lang STREQUAL "auto")
    set( _real_lang ${_lang} )
    
    if( NOT _dest )
      set( _dest "${LOCALE_INSTALL_DIR}/${_lang}/LC_MESSAGES" )
    endif( )
    
    # OUTPUT_NAME can only be used if we have only one file
    list( LENGTH _srcs _srcs_num)
    if( _out_name AND _srcs_num GREATER 1 )
      tde_message_fatal( "OUTPUT_NAME can be supplied only with single file or LANG=auto" )
    endif( )

  elseif( NOT _out_name )
    tde_message_fatal( "LANG=auto reqires OUTPUT_NAME directive to be set" )
  elseif( _dest )
    tde_message_fatal( "DESTINATION cannot be used with LANG=auto" )
  endif( )

  # generate *.mo files
  foreach( _src ${_srcs} )

    get_filename_component( _src ${_src} ABSOLUTE )

    if( _out_name )
	  set( _out ${_out_name} )
      if( _lang STREQUAL "auto" )
        get_filename_component( _real_lang ${_src} NAME_WE )
        set( _dest "${LOCALE_INSTALL_DIR}/${_real_lang}/LC_MESSAGES" )
      endif( )
    else( )
      get_filename_component( _out ${_src} NAME_WE )
    endif( )

    string( REPLACE "@" "_" _target ${_real_lang} )
    set( _out_filename "${_out}-${_real_lang}.mo" )
    set( _install_filename "${_out}.mo" )

    add_custom_command(
      OUTPUT ${_out_filename}
      COMMAND ${MSGFMT_EXECUTABLE} ${_src} -o ${_out_filename}
      DEPENDS ${_src} )
    add_custom_target( "${_out}-${_target}-translation" ALL DEPENDS ${_out_filename} )
    install( FILES ${CMAKE_CURRENT_BINARY_DIR}/${_out_filename} RENAME ${_install_filename} DESTINATION ${_dest} )

  endforeach( )

endmacro( )


#################################################
#####
##### tde_create_handbook

macro( tde_create_handbook )

  unset( _target )
  unset( _dest )
  unset( _noindex )
  unset( _srcs )
  unset( _extra )
  unset( _srcdir )

  set( _lang en )
  set( _first_arg 1 )
  set( _var _target )

  foreach( _arg ${ARGN} )

    # found directive "NOINDEX"
    if( "+${_arg}" STREQUAL "+NOINDEX" )
      set( _noindex 1 )
      set( _directive 1 )
    endif()

    # found directive "FILES"
    if( "+${_arg}" STREQUAL "+FILES" )
      unset( _srcs )
      set( _var _srcs )
      set( _directive 1 )
    endif()

    # found directive "EXTRA"
    if( "+${_arg}" STREQUAL "+EXTRA" )
      unset( _extra )
      set( _var _extra )
      set( _directive 1 )
    endif()

    # found directive "SRCDIR"
    if( "+${_arg}" STREQUAL "+SRCDIR" )
      unset( _srcdir )
      set( _var _srcdir )
      set( _directive 1 )
    endif()

    # found directive DESTINATION
    if( "+${_arg}" STREQUAL "+DESTINATION" )
      unset( _dest )
      set( _var _dest )
      set( _directive 1 )
    endif()

    # found directive "LANG"
    if( "+${_arg}" STREQUAL "+LANG" )
      unset( _lang )
      set( _var _lang )
      set( _directive 1 )
    endif()

    # collect data
    if( _directive )
      unset( _directive )
    elseif( _var )
      if( _first_arg )
        set( _target "${_arg}" )
      else()
        list( APPEND ${_var} ${_arg} )
      endif()
    endif()

    unset( _first_arg )

  endforeach()

  # if no target specified, try to guess it from DESTINATION
  if( NOT _target )
    if( NOT _dest )
      tde_message_fatal( "target name cannot be determined because DESTINATION is not set" )
    endif()
    string( REPLACE "/" "-" _target "${_dest}" )
  endif()

  set( _target "${_target}-${_lang}-handbook" )

  # if no file specified, include all docbooks, stylesheets and images
  if( NOT _srcs )
    file( GLOB _srcs RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.docbook *.css *.png  )
  endif()

  # if no destination specified, defaulting to HTML_INSTALL_DIR
  if( NOT _dest )
    set( _dest "${HTML_INSTALL_DIR}/${_lang}" )
  # if destination is NOT absolute path,
  # we assume that is relative to HTML_INSTALL_DIR
  elseif( NOT IS_ABSOLUTE ${_dest} )
    set( _dest "${HTML_INSTALL_DIR}/${_lang}/${_dest}" )
  endif()

  if( NOT _srcs )
    tde_message_fatal( "no source files" )
  endif()

  if( NOT _noindex )

    # check for index.docbook
    list( FIND _srcs "index.docbook" _find_index )
    if( -1 EQUAL _find_index )
      tde_message_fatal( "missing index.docbook file" )
    endif()

    # check for srcdir
    if( _srcdir )
      set( _srcdir "--srcdir=${_srcdir}" )
    endif()

    add_custom_command(
      OUTPUT index.cache.bz2
      COMMAND ${KDE3_MEINPROC_EXECUTABLE} ${_srcdir} --check --cache index.cache.bz2 ${CMAKE_CURRENT_SOURCE_DIR}/index.docbook
      DEPENDS ${_srcs} )

    add_custom_target( ${_target} ALL DEPENDS index.cache.bz2 )

    list( APPEND _srcs ${CMAKE_CURRENT_BINARY_DIR}/index.cache.bz2 )

    if( NOT TDE_HTML_DIR )
      set( TDE_HTML_DIR ${HTML_INSTALL_DIR} )
    endif( )

    tde_install_empty_directory( ${_dest} )
    tde_install_symlink( ${TDE_HTML_DIR}/${_lang}/common ${_dest} )

  endif()

  install( FILES ${_srcs} ${_extra} DESTINATION ${_dest} )

endmacro( )


#################################################
#####
##### tde_include_tqt

macro( tde_include_tqt )
  foreach( _cpp ${ARGN} )
    set_source_files_properties( ${_cpp} PROPERTIES COMPILE_FLAGS "-include tntqt.h" )
  endforeach()
endmacro( )


#################################################
#####
##### tde_install_symlink

macro( tde_install_symlink _target _link )

  # if path is relative, we must to prefix it with CMAKE_INSTALL_PREFIX
  if( IS_ABSOLUTE "${_link}" )
    set( _destination "${_link}" )
  else( IS_ABSOLUTE "${_link}" )
    set( _destination "${CMAKE_INSTALL_PREFIX}/${_link}" )
  endif( IS_ABSOLUTE "${_link}" )

  get_filename_component( _path "${_destination}" PATH )
  if( NOT IS_DIRECTORY "\$ENV{DESTDIR}${_path}" )
    install( CODE "file( MAKE_DIRECTORY \"\$ENV{DESTDIR}${_path}\" )" )
  endif( NOT IS_DIRECTORY "\$ENV{DESTDIR}${_path}" )

  install( CODE "execute_process( COMMAND ln -s ${_target} \$ENV{DESTDIR}${_destination} )" )

endmacro( tde_install_symlink )


#################################################
#####
##### tde_install_empty_directory

macro( tde_install_empty_directory _path )

  # if path is relative, we must to prefix it with CMAKE_INSTALL_PREFIX
  if( IS_ABSOLUTE "${_path}" )
    set( _destination "${_path}" )
  else( IS_ABSOLUTE "${_path}" )
    set( _destination "${CMAKE_INSTALL_PREFIX}/${_path}" )
  endif( IS_ABSOLUTE "${_path}" )

  install( CODE "file( MAKE_DIRECTORY \"\$ENV{DESTDIR}${_destination}\" )" )

endmacro( tde_install_empty_directory )


#################################################
#####
##### tde_conditional_add_subdirectory

macro( tde_conditional_add_subdirectory _cond _path )

  if( ${_cond} )
    add_subdirectory( "${_path}" )
  endif( ${_cond} )

endmacro( tde_conditional_add_subdirectory )


#################################################
#####
##### tde_auto_add_subdirectories

macro( tde_auto_add_subdirectories )
  file( GLOB _dirs RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} * )
  foreach( _dir ${_dirs} )
    if( IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${_dir} )
      if( NOT ${_dir} STREQUAL ".svn" AND EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${_dir}/CMakeLists.txt )
        add_subdirectory( ${_dir} )
      endif()
    endif()
  endforeach()
endmacro()


#################################################
#####
##### tde_save / tde_restore

macro( tde_save )
  foreach( _var ${ARGN} )
    set( __bak_${_var} ${${_var}} )
  endforeach()
endmacro()

macro( tde_save_and_set _var )
  set( __bak_${_var} ${${_var}} )
  set( ${_var} ${ARGN} )
endmacro( )

macro( tde_restore )
  foreach( _var ${ARGN} )
    set( ${_var} ${__bak_${_var}} )
    unset( __bak_${_var} )
  endforeach()
endmacro()


#################################################
#####
##### tde_setup_install_path

macro( tde_setup_install_path _path _default )
  if( DEFINED ${_path} )
    set( ${_path} "${${_path}}" CACHE INTERNAL "" FORCE )
  else( )
    set( ${_path} "${_default}" )
  endif( )
endmacro( )


##################################################

if( ${CMAKE_SOURCE_DIR} MATCHES ${CMAKE_BINARY_DIR} )
    tde_message_fatal( "Please use out-of-source building, like this:
 \n   rm ${CMAKE_SOURCE_DIR}/CMakeCache.txt
   mkdir /tmp/${PROJECT_NAME}.build
   cd /tmp/${PROJECT_NAME}.build
   cmake ${CMAKE_SOURCE_DIR} [arguments...]" )
endif( )

#################################################
#####
##### tde_setup_architecture_flags

macro( tde_setup_architecture_flags )
  message( STATUS "Detected ${CMAKE_SYSTEM_PROCESSOR} CPU architecture" )
  ## Immediate symbol binding is available only for gcc but not on ARM architectures
  if( ${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" AND NOT ${CMAKE_SYSTEM_PROCESSOR} MATCHES arm* AND NOT ${CMAKE_SYSTEM_NAME} STREQUAL "OpenBSD" )
    set( LINKER_IMMEDIATE_BINDING_FLAGS "-z\ now" CACHE INTERNAL "" FORCE )
  else( )
    set( LINKER_IMMEDIATE_BINDING_FLAGS "" CACHE INTERNAL "" FORCE )
  endif( )

  check_cxx_compiler_flag( -fPIE HAVE_PIE_SUPPORT )
  if( HAVE_PIE_SUPPORT )
    set( TDE_PIE_CFLAGS -fPIE )
    set( TDE_PIE_LDFLAGS -pie )
  endif( HAVE_PIE_SUPPORT )
endmacro( )


################################################
#####
##### Restore CMP0026 policy

if( POLICY CMP0026 )
  cmake_policy( POP )
endif( POLICY CMP0026 )

