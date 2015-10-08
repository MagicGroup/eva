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

set( CMAKE_MODULE_PATH "${MASTER_SOURCE_DIR}/cmake/modules" )
include( TDEMacros )

get_filename_component( _ui_basename ${UI_FILE} NAME_WE )

# FIXME this will working only on out-of-source mode
set( local_ui_file ${_ui_basename}.ui )
configure_file( ${UI_FILE} ${local_ui_file} COPYONLY )
tde_execute_process( COMMAND ${QT_REPLACE_SCRIPT} ${local_ui_file} )

# ui.h extension file, if exists
if( EXISTS "${UI_FILE}.h" )
  configure_file( ${UI_FILE}.h ${local_ui_file}.h COPYONLY )
  tde_execute_process( COMMAND ${QT_REPLACE_SCRIPT} ${local_ui_file}.h )
endif( )

if( TDE_QTPLUGINS_DIR )
  set( L -L ${TDE_QTPLUGINS_DIR} )
endif( )

tde_execute_process( COMMAND ${UIC_EXECUTABLE}
  -nounload -tr tr2i18n
  ${L}
  ${local_ui_file}
  OUTPUT_VARIABLE _ui_h_content )

if( _ui_h_content )
  string( REGEX REPLACE "#ifndef " "#ifndef UI_" _ui_h_content "${_ui_h_content}" )
  string( REGEX REPLACE "#define " "#define UI_" _ui_h_content "${_ui_h_content}" )
  string( REGEX REPLACE "public TQWizard" "public KWizard" _ui_h_content "${_ui_h_content}" )
  string( REGEX REPLACE "public TQWizard" "public KWizard" _ui_h_content "${_ui_h_content}" )
  string( REGEX REPLACE "#include <ntntqwizard.h>" "#include <kwizard.h>" _ui_h_content "${_ui_h_content}" )
  string( REGEX REPLACE "#include <ntqwizard.h>" "#include <kwizard.h>" _ui_h_content "${_ui_h_content}" )
  file( WRITE ${_ui_basename}.h "${_ui_h_content}" )
endif( )

tde_execute_process( COMMAND ${UIC_EXECUTABLE}
  -nounload -tr tr2i18n
  ${L}
  -impl ${_ui_basename}.h
  ${local_ui_file}
  OUTPUT_VARIABLE _ui_cpp_content )

if( _ui_cpp_content )
  string( REGEX REPLACE "tr2i18n\\(\"\"\\)" "TQString::null" _ui_cpp_content "${_ui_cpp_content}" )
  string( REGEX REPLACE "tr2i18n\\(\"\", \"\"\\)" "TQString::null" _ui_cpp_content "${_ui_cpp_content}" )
  string( REGEX REPLACE ": TQWizard\\(" ": KWizard(" _ui_cpp_content "${_ui_cpp_content}" )
  string( REGEX REPLACE ": TQWizard\\(" ": KWizard(" _ui_cpp_content "${_ui_cpp_content}" )
  file( WRITE ${_ui_basename}.cpp "#include <kdialog.h>\n#include <tdelocale.h>\n\n${_ui_cpp_content}" )
endif( )
