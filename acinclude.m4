##   -*- autoconf -*-

dnl    This file is part of the TDE libraries/packages
dnl    Copyright (C) 1997 Janos Farkas (chexum@shadow.banki.hu)
dnl              (C) 1997,98,99 Stephan Kulow (coolo@kde.org)

dnl    This file is free software; you can redistribute it and/or
dnl    modify it under the terms of the GNU Library General Public
dnl    License as published by the Free Software Foundation; either
dnl    version 2 of the License, or (at your option) any later version.

dnl    This library is distributed in the hope that it will be useful,
dnl    but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
dnl    Library General Public License for more details.

dnl    You should have received a copy of the GNU Library General Public License
dnl    along with this library; see the file COPYING.LIB.  If not, write to
dnl    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
dnl    Boston, MA 02110-1301, USA.

dnl IMPORTANT NOTE:
dnl Please do not modify this file unless you expect your modifications to be
dnl carried into every other module in the repository. 
dnl
dnl Single-module modifications are best placed in configure.in for tdelibs
dnl and tdebase or configure.in.in if present.

# serial 2
# Added 12/03/2011 by Timothy Pearson to shut automake serial warnings up

# KDE_PATH_X_DIRECT
dnl Internal subroutine of AC_PATH_X.
dnl Set ac_x_includes and/or ac_x_libraries.
AC_DEFUN([KDE_PATH_X_DIRECT],
[
AC_REQUIRE([KDE_CHECK_LIB64])

if test "$ac_x_includes" = NO; then
  # Guess where to find include files, by looking for this one X11 .h file.
  test -z "$x_direct_test_include" && x_direct_test_include=X11/Intrinsic.h

  # First, try using that file with no special directory specified.
AC_TRY_CPP([#include <$x_direct_test_include>],
[# We can compile using X headers with no special include directory.
ac_x_includes=],
[# Look for the header file in a standard set of common directories.
# Check X11 before X11Rn because it is often a symlink to the current release.
  for ac_dir in               \
    /usr/X11/include          \
    /usr/X11R6/include        \
    /usr/X11R5/include        \
    /usr/X11R4/include        \
                              \
    /usr/include/X11          \
    /usr/include/X11R6        \
    /usr/include/X11R5        \
    /usr/include/X11R4        \
                              \
    /usr/local/X11/include    \
    /usr/local/X11R6/include  \
    /usr/local/X11R5/include  \
    /usr/local/X11R4/include  \
                              \
    /usr/local/include/X11    \
    /usr/local/include/X11R6  \
    /usr/local/include/X11R5  \
    /usr/local/include/X11R4  \
                              \
    /usr/X386/include         \
    /usr/x386/include         \
    /usr/XFree86/include/X11  \
                              \
    /usr/include              \
    /usr/local/include        \
    /usr/unsupported/include  \
    /usr/athena/include       \
    /usr/local/x11r5/include  \
    /usr/lpp/Xamples/include  \
                              \
    /usr/openwin/include      \
    /usr/openwin/share/include \
    ; \
  do
    if test -r "$ac_dir/$x_direct_test_include"; then
      ac_x_includes=$ac_dir
      break
    fi
  done])
fi # $ac_x_includes = NO

if test "$ac_x_libraries" = NO; then
  # Check for the libraries.

  test -z "$x_direct_test_library" && x_direct_test_library=Xt
  test -z "$x_direct_test_function" && x_direct_test_function=XtMalloc

  # See if we find them without any special options.
  # Don't add to $LIBS permanently.
  ac_save_LIBS="$LIBS"
  LIBS="-l$x_direct_test_library $LIBS"
AC_TRY_LINK([#include <X11/Intrinsic.h>], [${x_direct_test_function}(1)],
[LIBS="$ac_save_LIBS"
# We can link X programs with no special library path.
ac_x_libraries=],
[LIBS="$ac_save_LIBS"
# First see if replacing the include by lib works.
# Check X11 before X11Rn because it is often a symlink to the current release.
for ac_dir in `echo "$ac_x_includes" | sed s/include/lib${tdelibsuff}/` \
    /usr/X11/lib${tdelibsuff}           \
    /usr/X11R6/lib${tdelibsuff}         \
    /usr/X11R5/lib${tdelibsuff}         \
    /usr/X11R4/lib${tdelibsuff}         \
                                        \
    /usr/lib${tdelibsuff}/X11           \
    /usr/lib${tdelibsuff}/X11R6         \
    /usr/lib${tdelibsuff}/X11R5         \
    /usr/lib${tdelibsuff}/X11R4         \
                                        \
    /usr/local/X11/lib${tdelibsuff}     \
    /usr/local/X11R6/lib${tdelibsuff}   \
    /usr/local/X11R5/lib${tdelibsuff}   \
    /usr/local/X11R4/lib${tdelibsuff}   \
                                        \
    /usr/local/lib${tdelibsuff}/X11     \
    /usr/local/lib${tdelibsuff}/X11R6   \
    /usr/local/lib${tdelibsuff}/X11R5   \
    /usr/local/lib${tdelibsuff}/X11R4   \
                                        \
    /usr/X386/lib${tdelibsuff}          \
    /usr/x386/lib${tdelibsuff}          \
    /usr/XFree86/lib${tdelibsuff}/X11   \
                                        \
    /usr/lib${tdelibsuff}               \
    /usr/local/lib${tdelibsuff}         \
    /usr/unsupported/lib${tdelibsuff}   \
    /usr/athena/lib${tdelibsuff}        \
    /usr/local/x11r5/lib${tdelibsuff}   \
    /usr/lpp/Xamples/lib${tdelibsuff}   \
    /lib/usr/lib${tdelibsuff}/X11       \
                                        \
    /usr/openwin/lib${tdelibsuff}       \
    /usr/openwin/share/lib${tdelibsuff} \
    ; \
do
dnl Don't even attempt the hair of trying to link an X program!
  for ac_extension in a so sl; do
    if test -r $ac_dir/lib${x_direct_test_library}.$ac_extension; then
      ac_x_libraries=$ac_dir
      break 2
    fi
  done
done])
fi # $ac_x_libraries = NO
])


dnl ------------------------------------------------------------------------
dnl Find a file (or one of more files in a list of dirs)
dnl ------------------------------------------------------------------------
dnl
AC_DEFUN([AC_FIND_FILE],
[
$3=NO
for i in $2;
do
  for j in $1;
  do
    echo "configure: __oline__: $i/$j" >&AC_FD_CC
    if test -r "$i/$j"; then
      echo "taking that" >&AC_FD_CC
      $3=$i
      break 2
    fi
  done
done
])

dnl KDE_FIND_PATH(program-name, variable-name, list-of-dirs,
dnl	if-not-found, test-parameter, prepend-path)
dnl
dnl Look for program-name in list-of-dirs+$PATH.
dnl If prepend-path is set, look in $PATH+list-of-dirs instead.
dnl If found, $variable-name is set. If not, if-not-found is evaluated.
dnl test-parameter: if set, the program is executed with this arg,
dnl                 and only a successful exit code is required.
AC_DEFUN([KDE_FIND_PATH],
[
   AC_MSG_CHECKING([for $1])
   if test -n "$$2"; then
        kde_cv_path="$$2";
   else
        kde_cache=`echo $1 | sed 'y%./+-%__p_%'`

        AC_CACHE_VAL(kde_cv_path_$kde_cache,
        [
        kde_cv_path="NONE"
	kde_save_IFS=$IFS
	IFS=':'
	dirs=""
	for dir in $PATH; do
	  dirs="$dirs $dir"
	done
	if test -z "$6"; then  dnl Append dirs in PATH (default)
	  dirs="$3 $dirs"
        else  dnl Prepend dirs in PATH (if 6th arg is set)
	  dirs="$dirs $3"
	fi
	IFS=$kde_save_IFS

        for dir in $dirs; do
	  if test -x "$dir/$1"; then
	    if test -n "$5"
	    then
              evalstr="$dir/$1 $5 2>&1 "
	      if eval $evalstr; then
                kde_cv_path="$dir/$1"
                break
	      fi
            else
		kde_cv_path="$dir/$1"
                break
	    fi
          fi
        done

        eval "kde_cv_path_$kde_cache=$kde_cv_path"

        ])

      eval "kde_cv_path=\"`echo '$kde_cv_path_'$kde_cache`\""

   fi

   if test -z "$kde_cv_path" || test "$kde_cv_path" = NONE; then
      AC_MSG_RESULT(not found)
      $4
   else
      AC_MSG_RESULT($kde_cv_path)
      $2=$kde_cv_path

   fi
])

AC_DEFUN([KDE_MOC_ERROR_MESSAGE],
[
    AC_MSG_ERROR([No TQt meta object compiler (tqmoc) found!
Please check whether you installed Qt correctly.
You need to have a running tqmoc binary.
configure tried to run $ac_cv_path_moc and the test didn't
succeed. If configure shouldn't have tried this one, set
the environment variable MOC to the right one before running
configure.
])
])

AC_DEFUN([KDE_TQTMOC_ERROR_MESSAGE],
[
    AC_MSG_ERROR([No Trinity Qt meta object compiler (tmoc) found!
Please check whether you installed the Trinity Qt Interface correctly.
You need to have a running tmoc binary.
configure tried to run $ac_cv_path_moc and the test didn't
succeed. If configure shouldn't have tried this one, set
the environment variable TQTMOC to the right one before running
configure.
])
])

AC_DEFUN([KDE_UIC_ERROR_MESSAGE],
[
    AC_MSG_WARN([No TQt ui compiler (tquic) found!
Please check whether you installed TQt correctly.
You need to have a running uic binary.
configure tried to run $ac_cv_path_uic and the test didn't
succeed. If configure shouldn't have tried this one, set
the environment variable UIC to the right one before running
configure.
])
])


AC_DEFUN([KDE_CHECK_UIC_FLAG],
[
    AC_MSG_CHECKING([whether uic supports -$1 ])
    kde_cache=`echo $1 | sed 'y% .=/+-%____p_%'`
    AC_CACHE_VAL(kde_cv_prog_uic_$kde_cache,
    [
        cat >conftest.ui <<EOT
        <!DOCTYPE UI><UI version="3" stdsetdef="1"></UI>
EOT
        ac_uic_testrun="$UIC_PATH -$1 $2 conftest.ui >/dev/null"
        if AC_TRY_EVAL(ac_uic_testrun); then
            eval "kde_cv_prog_uic_$kde_cache=yes"
        else
            eval "kde_cv_prog_uic_$kde_cache=no"
        fi
        rm -f conftest*
    ])

    if eval "test \"`echo '$kde_cv_prog_uic_'$kde_cache`\" = yes"; then
        AC_MSG_RESULT([yes])
        :
        $3
    else
        AC_MSG_RESULT([no])
        :
        $4
    fi
])


dnl ------------------------------------------------------------------------
dnl Find the meta object compiler and the ui compiler in the PATH,
dnl in $QTDIR/bin, and some more usual places
dnl ------------------------------------------------------------------------
dnl
AC_DEFUN([AC_PATH_QT_MOC_UIC],
[
   AC_REQUIRE([KDE_CHECK_PERL])
   qt_bindirs=""
   for dir in $kde_qt_dirs; do
      qt_bindirs="$qt_bindirs $dir/bin $dir/src/moc"
   done
   qt_bindirs="$qt_bindirs /usr/bin /usr/X11R6/bin /usr/local/qt/bin"
   if test ! "$ac_qt_bindir" = "NO"; then
      qt_bindirs="$ac_qt_bindir $qt_bindirs"
   fi

   if test "$kde_qtver" = "3"; then
     qt_bindirs="/usr/share/tqt3/bin /usr/share/qt3/bin $qt_bindirs"
   fi

   if test "$kde_qtver" = "4"; then
     qt_bindirs="/usr/share/qt4/bin $qt_bindirs"
   fi

   KDE_FIND_PATH(tqmoc, MOC, [$qt_bindirs], [KDE_MOC_ERROR_MESSAGE])
   if test -z "$UIC_NOT_NEEDED"; then
     if test $kde_qtver = 3; then
       KDE_FIND_PATH(uic-tqt, UIC_PATH, [$qt_bindirs], [UIC_PATH=""])
     fi
     if test $kde_qtver = 4; then
       KDE_FIND_PATH(uic-tqt, UIC_PATH, [$qt_bindirs], [UIC_PATH=""])
     fi
     if test -z "$UIC_PATH" ; then
       KDE_UIC_ERROR_MESSAGE
       exit 1
     else
       UIC=$UIC_PATH

       if test $kde_qtver = 3; then
         KDE_CHECK_UIC_FLAG(L,[/nonexistent],ac_uic_supports_libpath=yes,ac_uic_supports_libpath=no)
         KDE_CHECK_UIC_FLAG(nounload,,ac_uic_supports_nounload=yes,ac_uic_supports_nounload=no)

         if test x$ac_uic_supports_libpath = xyes; then
             UIC="$UIC -L \$(kde_widgetdir)"
         fi
         if test x$ac_uic_supports_nounload = xyes; then
             UIC="$UIC -nounload"
         fi
       fi

       if test $kde_qtver = 4; then
         KDE_CHECK_UIC_FLAG(L,[/nonexistent],ac_uic_supports_libpath=yes,ac_uic_supports_libpath=no)
         KDE_CHECK_UIC_FLAG(nounload,,ac_uic_supports_nounload=yes,ac_uic_supports_nounload=no)

         if test x$ac_uic_supports_libpath = xyes; then
             UIC="$UIC -L \$(kde_widgetdir)"
         fi
         if test x$ac_uic_supports_nounload = xyes; then
             UIC="$UIC -nounload"
         fi
       fi
     fi
   else
     UIC="echo uic not available: "
   fi

   AC_SUBST(MOC)
   AC_SUBST(UIC)

   UIC_TR="i18n"
   if test $kde_qtver = 3; then
     UIC_TR="tr2i18n"
   fi
   if test $kde_qtver = 4; then
     UIC_TR="tr2i18n"
   fi

   AC_SUBST(UIC_TR)
])

AC_DEFUN([KDE_1_CHECK_PATHS],
[
  KDE_1_CHECK_PATH_HEADERS

  KDE_TEST_RPATH=

  if test -n "$USE_RPATH"; then

     if test -n "$kde_libraries"; then
       KDE_TEST_RPATH="-R $kde_libraries"
     fi

     if test -n "$qt_libraries"; then
       KDE_TEST_RPATH="$KDE_TEST_RPATH -R $qt_libraries"
     fi

     if test -n "$x_libraries"; then
       KDE_TEST_RPATH="$KDE_TEST_RPATH -R $x_libraries"
     fi

     KDE_TEST_RPATH="$KDE_TEST_RPATH $KDE_EXTRA_RPATH"
  fi

AC_MSG_CHECKING([for TDE libraries installed])
ac_link='$LIBTOOL_SHELL --silent --mode=link ${CXX-g++} -o conftest $CXXFLAGS $all_includes $CPPFLAGS $LDFLAGS $all_libraries conftest.$ac_ext $LIBS -ltdecore $LIBQT $KDE_TEST_RPATH 1>&5'

if AC_TRY_EVAL(ac_link) && test -s conftest; then
  AC_MSG_RESULT(yes)
else
  AC_MSG_ERROR([your system fails at linking a small TDE application!
Check, if your compiler is installed correctly and if you have used the
same compiler to compile Qt and tdelibs as you did use now.
For more details about this problem, look at the end of config.log.])
fi

if eval `TDEDIR= ./conftest 2>&5`; then
  kde_result=done
else
  kde_result=problems
fi

TDEDIR= ./conftest 2> /dev/null >&5 # make an echo for config.log
kde_have_all_paths=yes

KDE_SET_PATHS($kde_result)

])

AC_DEFUN([KDE_SET_PATHS],
[
  kde_cv_all_paths="kde_have_all_paths=\"yes\" \
	kde_htmldir=\"$kde_htmldir\" \
	kde_appsdir=\"$kde_appsdir\" \
	kde_icondir=\"$kde_icondir\" \
	kde_sounddir=\"$kde_sounddir\" \
	kde_datadir=\"$kde_datadir\" \
	kde_locale=\"$kde_locale\" \
	kde_cgidir=\"$kde_cgidir\" \
	kde_confdir=\"$kde_confdir\" \
	kde_kcfgdir=\"$kde_kcfgdir\" \
	kde_mimedir=\"$kde_mimedir\" \
	kde_toolbardir=\"$kde_toolbardir\" \
	kde_wallpaperdir=\"$kde_wallpaperdir\" \
	kde_templatesdir=\"$kde_templatesdir\" \
	kde_bindir=\"$kde_bindir\" \
	kde_servicesdir=\"$kde_servicesdir\" \
	kde_servicetypesdir=\"$kde_servicetypesdir\" \
	kde_moduledir=\"$kde_moduledir\" \
	kde_styledir=\"$kde_styledir\" \
	kde_widgetdir=\"$kde_widgetdir\" \
	xdg_appsdir=\"$xdg_appsdir\" \
	xdg_menudir=\"$xdg_menudir\" \
	xdg_directorydir=\"$xdg_directorydir\" \
	kde_result=$1"
])

AC_DEFUN([KDE_SET_DEFAULT_PATHS],
[
if test "$1" = "default"; then

  if test -z "$kde_htmldir"; then
    kde_htmldir='\${datadir}/doc/tde/HTML'
  fi
  if test -z "$kde_appsdir"; then
    kde_appsdir='\${datadir}/applnk'
  fi
  if test -z "$kde_icondir"; then
    kde_icondir='\${datadir}/icons'
  fi
  if test -z "$kde_sounddir"; then
    kde_sounddir='\${datadir}/sounds'
  fi
  if test -z "$kde_datadir"; then
    kde_datadir='\${datadir}/apps'
  fi
  if test -z "$kde_locale"; then
    kde_locale='\${datadir}/locale'
  fi
  if test -z "$kde_cgidir"; then
    kde_cgidir='\${exec_prefix}/cgi-bin'
  fi
  if test -z "$kde_confdir"; then
    kde_confdir='\${datadir}/config'
  fi
  if test -z "$kde_kcfgdir"; then
    kde_kcfgdir='\${datadir}/config.kcfg'
  fi
  if test -z "$kde_mimedir"; then
    kde_mimedir='\${datadir}/mimelnk'
  fi
  if test -z "$kde_toolbardir"; then
    kde_toolbardir='\${datadir}/toolbar'
  fi
  if test -z "$kde_wallpaperdir"; then
    kde_wallpaperdir='\${datadir}/wallpapers'
  fi
  if test -z "$kde_templatesdir"; then
    kde_templatesdir='\${datadir}/templates'
  fi
  if test -z "$kde_bindir"; then
    kde_bindir='\${exec_prefix}/bin'
  fi
  if test -z "$kde_servicesdir"; then
    kde_servicesdir='\${datadir}/services'
  fi
  if test -z "$kde_servicetypesdir"; then
    kde_servicetypesdir='\${datadir}/servicetypes'
  fi
  if test -z "$kde_moduledir"; then
    if test "$kde_qtver" = "2"; then
      kde_moduledir='\${libdir}/kde2'
    else
      kde_moduledir='\${libdir}/trinity'
    fi
  fi
  if test -z "$kde_styledir"; then
    kde_styledir='\${libdir}/trinity/plugins/styles'
  fi
  if test -z "$kde_widgetdir"; then
    kde_widgetdir='\${libdir}/trinity/plugins/designer'
  fi
  if test -z "$xdg_appsdir"; then
    xdg_appsdir='\${datadir}/applications/tde'
  fi
  if test -z "$xdg_menudir"; then
    xdg_menudir='\${sysconfdir}/xdg/menus'
  fi
  if test -z "$xdg_directorydir"; then
    xdg_directorydir='\${datadir}/desktop-directories'
  fi

  KDE_SET_PATHS(defaults)

else

  if test $kde_qtver = 1; then
     AC_MSG_RESULT([compiling])
     KDE_1_CHECK_PATHS
  else
     AC_MSG_ERROR([path checking not yet supported for TDE 2])
  fi

fi
])

AC_DEFUN([KDE_CHECK_PATHS_FOR_COMPLETENESS],
[ if test -z "$kde_htmldir" || test -z "$kde_appsdir" ||
   test -z "$kde_icondir" || test -z "$kde_sounddir" ||
   test -z "$kde_datadir" || test -z "$kde_locale"  ||
   test -z "$kde_cgidir"  || test -z "$kde_confdir" ||
   test -z "$kde_kcfgdir" ||
   test -z "$kde_mimedir" || test -z "$kde_toolbardir" ||
   test -z "$kde_wallpaperdir" || test -z "$kde_templatesdir" ||
   test -z "$kde_bindir" || test -z "$kde_servicesdir" ||
   test -z "$kde_servicetypesdir" || test -z "$kde_moduledir" ||
   test -z "$kde_styledir" || test -z "kde_widgetdir" ||
   test -z "$xdg_appsdir" || test -z "$xdg_menudir" || test -z "$xdg_directorydir" ||
   test "x$kde_have_all_paths" != "xyes"; then
     kde_have_all_paths=no
  fi
])

AC_DEFUN([KDE_MISSING_PROG_ERROR],
[
    AC_MSG_ERROR([The important program $1 was not found!
Please check whether you installed TDE correctly.
])
])

AC_DEFUN([KDE_MISSING_ARTS_ERROR],
[
    AC_MSG_ERROR([The important program $1 was not found!
Please check whether you installed aRts correctly or use
--without-arts to compile without aRts support (this will remove functionality).
])
])

AC_DEFUN([KDE_SET_DEFAULT_BINDIRS],
[
    kde_default_bindirs="/usr/bin /usr/local/bin /opt/local/bin /usr/X11R6/bin /opt/kde/bin /opt/trinity/bin /opt/trinity/bin /usr/kde/bin /usr/local/kde/bin"
    test -n "$TDEDIR" && kde_default_bindirs="$TDEDIR/bin $kde_default_bindirs"
    if test -n "$TDEDIRS"; then
       kde_save_IFS=$IFS
       IFS=:
       for dir in $TDEDIRS; do
            kde_default_bindirs="$dir/bin $kde_default_bindirs "
       done
       IFS=$kde_save_IFS
    fi
])

AC_DEFUN([KDE_SUBST_PROGRAMS],
[
    AC_ARG_WITH(arts,
        AC_HELP_STRING([--without-arts],[build without aRts [default=no]]),
        [build_arts=$withval],
        [build_arts=yes]
    )
    AM_CONDITIONAL(include_ARTS, test "$build_arts" '!=' "no")
    if test "$build_arts" = "no"; then
        AC_DEFINE(WITHOUT_ARTS, 1, [Defined if compiling without arts])
    fi

        KDE_SET_DEFAULT_BINDIRS
        kde_default_bindirs="$exec_prefix/bin $prefix/bin $kde_libs_prefix/bin $kde_default_bindirs"
        KDE_FIND_PATH(dcopidl, DCOPIDL, [$kde_default_bindirs], [KDE_MISSING_PROG_ERROR(dcopidl)])
        KDE_FIND_PATH(dcopidl2cpp, DCOPIDL2CPP, [$kde_default_bindirs], [KDE_MISSING_PROG_ERROR(dcopidl2cpp)])
        if test "$build_arts" '!=' "no"; then
          KDE_FIND_PATH(mcopidl, MCOPIDL, [$kde_default_bindirs], [KDE_MISSING_ARTS_ERROR(mcopidl)])
          KDE_FIND_PATH(artsc-config, ARTSCCONFIG, [$kde_default_bindirs], [KDE_MISSING_ARTS_ERROR(artsc-config)])
        fi
        KDE_FIND_PATH(meinproc, MEINPROC, [$kde_default_bindirs])

        trinity14ornewer=1
        if test "$kde_qtver" = "3"; then
          if test "$KDECONFIG" != "compiled"; then
            if test `$KDECONFIG --version | grep TDE | sed 's/TDE: R\(..\).*/\1/'` -lt 14; then
              trinity14ornewer=
            fi
          fi
        fi
        if test "$kde_qtver" = "4"; then
          trinity14ornewer=1
        fi

        if test -n "$trinity14ornewer"; then
            KDE_FIND_PATH(tdeconfig_compiler, KCONFIG_COMPILER, [$kde_default_bindirs], [KDE_MISSING_PROG_ERROR(tdeconfig_compiler)])
            KDE_FIND_PATH(dcopidlng, DCOPIDLNG, [$kde_default_bindirs], [KDE_MISSING_PROG_ERROR(dcopidlng)])
            KDE_FIND_PATH(maketdewidgets, MAKETDEWIDGETS, [$kde_default_bindirs], [KDE_MISSING_PROG_ERROR(maketdewidgets)])
            AC_SUBST(MAKETDEWIDGETS)
        fi
        KDE_FIND_PATH(xmllint, XMLLINT, [${prefix}/bin ${exec_prefix}/bin], [XMLLINT=""])

        if test -n "$MEINPROC" -a "$MEINPROC" != "compiled"; then
 	    kde_sharedirs="$prefix/share /opt/trinity/share /opt/trinity/share /opt/kde/share /usr/share/kde /usr/local/share /usr/share"
            test -n "$TDEDIR" && kde_sharedirs="$TDEDIR/share $kde_sharedirs"
            AC_FIND_FILE(apps/ksgmltools2/customization/tde-chunk.xsl, $kde_sharedirs, KDE_XSL_STYLESHEET)
	    if test "$KDE_XSL_STYLESHEET" = "NO"; then
		KDE_XSL_STYLESHEET=""
	    else
                KDE_XSL_STYLESHEET="$KDE_XSL_STYLESHEET/apps/ksgmltools2/customization/tde-chunk.xsl"
	    fi
        fi

        DCOP_DEPENDENCIES='$(DCOPIDL)'
        if test -n "$trinity14ornewer"; then
            KCFG_DEPENDENCIES='$(KCONFIG_COMPILER)'
            DCOP_DEPENDENCIES='$(DCOPIDL) $(DCOPIDLNG)'
            AC_SUBST(KCONFIG_COMPILER)
            AC_SUBST(KCFG_DEPENDENCIES)
            AC_SUBST(DCOPIDLNG)
        fi
        AC_SUBST(DCOPIDL)
        AC_SUBST(DCOPIDL2CPP)
        AC_SUBST(DCOP_DEPENDENCIES)
        AC_SUBST(MCOPIDL)
        AC_SUBST(ARTSCCONFIG)
	AC_SUBST(MEINPROC)
 	AC_SUBST(KDE_XSL_STYLESHEET)
	AC_SUBST(XMLLINT)
])dnl

AC_DEFUN([AC_CREATE_KFSSTND],
[
AC_REQUIRE([AC_CHECK_RPATH])

AC_MSG_CHECKING([for TDE paths])
kde_result=""
kde_cached_paths=yes
AC_CACHE_VAL(kde_cv_all_paths,
[
  KDE_SET_DEFAULT_PATHS($1)
  kde_cached_paths=no
])
eval "$kde_cv_all_paths"
KDE_CHECK_PATHS_FOR_COMPLETENESS
if test "$kde_have_all_paths" = "no" && test "$kde_cached_paths" = "yes"; then
  # wrong values were cached, may be, we can set better ones
  kde_result=
  kde_htmldir= kde_appsdir= kde_icondir= kde_sounddir=
  kde_datadir= kde_locale=  kde_cgidir=  kde_confdir= kde_kcfgdir=
  kde_mimedir= kde_toolbardir= kde_wallpaperdir= kde_templatesdir=
  kde_bindir= kde_servicesdir= kde_servicetypesdir= kde_moduledir=
  kde_have_all_paths=
  kde_styledir=
  kde_widgetdir=
  xdg_appsdir = xdg_menudir= xdg_directorydir= 
  KDE_SET_DEFAULT_PATHS($1)
  eval "$kde_cv_all_paths"
  KDE_CHECK_PATHS_FOR_COMPLETENESS
  kde_result="$kde_result (cache overridden)"
fi
if test "$kde_have_all_paths" = "no"; then
  AC_MSG_ERROR([configure could not run a little TDE program to test the environment.
Since it had compiled and linked before, it must be a strange problem on your system.
Look at config.log for details. If you are not able to fix this, look at
http://www.kde.org/faq/installation.html or any www.kde.org mirror.
(If you're using an egcs version on Linux, you may update binutils!)
])
else
  rm -f conftest*
  AC_MSG_RESULT($kde_result)
fi

bindir=$kde_bindir

KDE_SUBST_PROGRAMS

])

AC_DEFUN([AC_SUBST_KFSSTND],
[
AC_SUBST(kde_htmldir)
AC_SUBST(kde_appsdir)
AC_SUBST(kde_icondir)
AC_SUBST(kde_sounddir)
AC_SUBST(kde_datadir)
AC_SUBST(kde_locale)
AC_SUBST(kde_confdir)
AC_SUBST(kde_kcfgdir)
AC_SUBST(kde_mimedir)
AC_SUBST(kde_wallpaperdir)
AC_SUBST(kde_bindir)
dnl X Desktop Group standards
AC_SUBST(xdg_appsdir)
AC_SUBST(xdg_menudir)
AC_SUBST(xdg_directorydir)
dnl for TDE 2
AC_SUBST(kde_templatesdir)
AC_SUBST(kde_servicesdir)
AC_SUBST(kde_servicetypesdir)
AC_SUBST(kde_moduledir)
AC_SUBST(tdeinitdir, '$(kde_moduledir)')
AC_SUBST(kde_styledir)
AC_SUBST(kde_widgetdir)
if test "$kde_qtver" = 1; then
  kde_minidir="$kde_icondir/mini"
else
# for TDE 1 - this breaks KDE2 apps using minidir, but
# that's the plan ;-/
  kde_minidir="/dev/null"
fi
dnl AC_SUBST(kde_minidir)
dnl AC_SUBST(kde_cgidir)
dnl AC_SUBST(kde_toolbardir)
])

AC_DEFUN([KDE_MISC_TESTS],
[
   dnl Checks for libraries.
   AC_CHECK_LIB(util, main, [LIBUTIL="-lutil"]) dnl for *BSD 
   AC_SUBST(LIBUTIL)
   AC_CHECK_LIB(compat, main, [LIBCOMPAT="-lcompat"]) dnl for *BSD
   AC_SUBST(LIBCOMPAT)
   kde_have_crypt=
   AC_CHECK_LIB(crypt, crypt, [LIBCRYPT="-lcrypt"; kde_have_crypt=yes],
      AC_CHECK_LIB(c, crypt, [kde_have_crypt=yes], [
        AC_MSG_WARN([you have no crypt in either libcrypt or libc.
You should install libcrypt from another source or configure with PAM
support])
	kde_have_crypt=no
      ]))
   AC_SUBST(LIBCRYPT)
   if test $kde_have_crypt = yes; then
      AC_DEFINE_UNQUOTED(HAVE_CRYPT, 1, [Defines if your system has the crypt function])
   fi
   AC_CHECK_SOCKLEN_T
   AC_CHECK_LIB(dnet, dnet_ntoa, [X_EXTRA_LIBS="$X_EXTRA_LIBS -ldnet"])
   if test $ac_cv_lib_dnet_dnet_ntoa = no; then
      AC_CHECK_LIB(dnet_stub, dnet_ntoa,
        [X_EXTRA_LIBS="$X_EXTRA_LIBS -ldnet_stub"])
   fi
   AC_CHECK_FUNC(inet_ntoa)
   if test $ac_cv_func_inet_ntoa = no; then
     AC_CHECK_LIB(nsl, inet_ntoa, X_EXTRA_LIBS="$X_EXTRA_LIBS -lnsl")
   fi
   AC_CHECK_FUNC(connect)
   if test $ac_cv_func_connect = no; then
      AC_CHECK_LIB(socket, connect, X_EXTRA_LIBS="-lsocket $X_EXTRA_LIBS", ,
        $X_EXTRA_LIBS)
   fi

   AC_CHECK_FUNC(remove)
   if test $ac_cv_func_remove = no; then
      AC_CHECK_LIB(posix, remove, X_EXTRA_LIBS="$X_EXTRA_LIBS -lposix")
   fi

   # BSDI BSD/OS 2.1 needs -lipc for XOpenDisplay.
   AC_CHECK_FUNC(shmat, ,
     AC_CHECK_LIB(ipc, shmat, X_EXTRA_LIBS="$X_EXTRA_LIBS -lipc"))
   
   # more headers that need to be explicitly included on darwin
   AC_CHECK_HEADERS(sys/types.h stdint.h)

   # sys/bitypes.h is needed for uint32_t and friends on Tru64
   AC_CHECK_HEADERS(sys/bitypes.h)

   # darwin requires a poll emulation library
   AC_CHECK_LIB(poll, poll, LIB_POLL="-lpoll")

   # for some image handling on Mac OS X
   AC_CHECK_HEADERS(Carbon/Carbon.h)

   # CoreAudio framework
   AC_CHECK_HEADER(CoreAudio/CoreAudio.h, [
     AC_DEFINE(HAVE_COREAUDIO, 1, [Define if you have the CoreAudio API])
     FRAMEWORK_COREAUDIO="-Wl,-framework,CoreAudio"
   ])

   AC_CHECK_RES_INIT
   AC_SUBST(LIB_POLL)
   AC_SUBST(FRAMEWORK_COREAUDIO)
   LIBSOCKET="$X_EXTRA_LIBS"
   AC_SUBST(LIBSOCKET)
   AC_SUBST(X_EXTRA_LIBS)
   AC_CHECK_LIB(ucb, killpg, [LIBUCB="-lucb"]) dnl for Solaris2.4
   AC_SUBST(LIBUCB)

   case $host in  dnl this *is* LynxOS specific
   *-*-lynxos* )
        AC_MSG_CHECKING([LynxOS header file wrappers])
        [CFLAGS="$CFLAGS -D__NO_INCLUDE_WARN__"]
        AC_MSG_RESULT(disabled)
        AC_CHECK_LIB(bsd, gethostbyname, [LIBSOCKET="-lbsd"]) dnl for LynxOS
         ;;
    esac

   KDE_CHECK_TYPES
   KDE_CHECK_LIBDL
   KDE_CHECK_STRLCPY
   KDE_CHECK_PIE_SUPPORT

# darwin needs this to initialize the environment
AC_CHECK_HEADERS(crt_externs.h)
AC_CHECK_FUNC(_NSGetEnviron, [AC_DEFINE(HAVE_NSGETENVIRON, 1, [Define if your system needs _NSGetEnviron to set up the environment])])
 
AH_VERBATIM(_DARWIN_ENVIRON,
[
#if defined(HAVE_NSGETENVIRON) && defined(HAVE_CRT_EXTERNS_H)
# include <sys/time.h>
# include <crt_externs.h>
# define environ (*_NSGetEnviron())
#endif
])

AH_VERBATIM(_AIX_STRINGS_H_BZERO,
[
/*
 * AIX defines FD_SET in terms of bzero, but fails to include <strings.h>
 * that defines bzero.
 */

#if defined(_AIX)
#include <strings.h>
#endif
])

AC_CHECK_FUNCS([vsnprintf snprintf])

AH_VERBATIM(_TRU64,[
/*
 * On HP-UX, the declaration of vsnprintf() is needed every time !
 */

#if !defined(HAVE_VSNPRINTF) || defined(hpux)
#if __STDC__
#include <stdarg.h>
#include <stdlib.h>
#else
#include <varargs.h>
#endif
#ifdef __cplusplus
extern "C"
#endif
int vsnprintf(char *str, size_t n, char const *fmt, va_list ap);
#ifdef __cplusplus
extern "C"
#endif
int snprintf(char *str, size_t n, char const *fmt, ...);
#endif
])

])

dnl ------------------------------------------------------------------------
dnl Find the header files and libraries for X-Windows. Extended the
dnl macro AC_PATH_X
dnl ------------------------------------------------------------------------
dnl
AC_DEFUN([K_PATH_X],
[
AC_REQUIRE([KDE_MISC_TESTS])dnl
AC_REQUIRE([KDE_CHECK_LIB64])

AC_ARG_ENABLE(
  embedded,
  AC_HELP_STRING([--enable-embedded],[link to Qt-embedded, don't use X]),
  kde_use_qt_emb=$enableval,
  kde_use_qt_emb=no
)

AC_ARG_ENABLE(
  qtopia,
  AC_HELP_STRING([--enable-qtopia],[link to Qt-embedded, link to the Qtopia Environment]),
  kde_use_qt_emb_palm=$enableval,
  kde_use_qt_emb_palm=no
)

AC_ARG_ENABLE(
  mac,
  AC_HELP_STRING([--enable-mac],[link to Qt/Mac (don't use X)]),
  kde_use_qt_mac=$enableval,
  kde_use_qt_mac=no
)

# used to disable x11-specific stuff on special platforms
AM_CONDITIONAL(include_x11, test "$kde_use_qt_emb" = "no" && test "$kde_use_qt_mac" = "no")

if test "$kde_use_qt_emb" = "no" && test "$kde_use_qt_mac" = "no"; then

AC_MSG_CHECKING(for X)

AC_CACHE_VAL(kde_cv_have_x,
[# One or both of the vars are not set, and there is no cached value.
if test "{$x_includes+set}" = set || test "$x_includes" = NONE; then
   kde_x_includes=NO
else
   kde_x_includes=$x_includes
fi
if test "{$x_libraries+set}" = set || test "$x_libraries" = NONE; then
   kde_x_libraries=NO
else
   kde_x_libraries=$x_libraries
fi

# below we use the standard autoconf calls
ac_x_libraries=$kde_x_libraries
ac_x_includes=$kde_x_includes

KDE_PATH_X_DIRECT
dnl AC_PATH_X_XMKMF picks /usr/lib as the path for the X libraries.
dnl Unfortunately, if compiling with the N32 ABI, this is not the correct
dnl location. The correct location is /usr/lib32 or an undefined value
dnl (the linker is smart enough to pick the correct default library).
dnl Things work just fine if you use just AC_PATH_X_DIRECT.
dnl Solaris has a similar problem. AC_PATH_X_XMKMF forces x_includes to
dnl /usr/openwin/include, which doesn't work. /usr/include does work, so
dnl x_includes should be left alone.
case "$host" in
mips-sgi-irix6*)
  ;;
*-*-solaris*)
  ;;
*)
  _AC_PATH_X_XMKMF
  if test -z "$ac_x_includes"; then
    ac_x_includes="."
  fi
  if test -z "$ac_x_libraries"; then
    ac_x_libraries="/usr/lib${tdelibsuff}"
  fi
esac
#from now on we use our own again

# when the user already gave --x-includes, we ignore
# what the standard autoconf macros told us.
if test "$kde_x_includes" = NO; then
  kde_x_includes=$ac_x_includes
fi

# for --x-libraries too
if test "$kde_x_libraries" = NO; then
  kde_x_libraries=$ac_x_libraries
fi

if test "$kde_x_includes" = NO; then
  AC_MSG_ERROR([Can't find X includes. Please check your installation and add the correct paths!])
fi

if test "$kde_x_libraries" = NO; then
  AC_MSG_ERROR([Can't find X libraries. Please check your installation and add the correct paths!])
fi

# Record where we found X for the cache.
kde_cv_have_x="have_x=yes \
         kde_x_includes=$kde_x_includes kde_x_libraries=$kde_x_libraries"
])dnl

eval "$kde_cv_have_x"

if test "$have_x" != yes; then
  AC_MSG_RESULT($have_x)
  no_x=yes
else
  AC_MSG_RESULT([libraries $kde_x_libraries, headers $kde_x_includes])
fi

if test -z "$kde_x_includes" || test "x$kde_x_includes" = xNONE; then
  X_INCLUDES=""
  x_includes="."; dnl better than nothing :-
 else
  x_includes=$kde_x_includes
  X_INCLUDES="-I$x_includes"
fi

if test -z "$kde_x_libraries" || test "x$kde_x_libraries" = xNONE || test "$kde_x_libraries" = "/usr/lib"; then
  X_LDFLAGS=""
  x_libraries="/usr/lib"; dnl better than nothing :-
 else
  x_libraries=$kde_x_libraries
  X_LDFLAGS="-L$x_libraries"
fi
all_includes="$X_INCLUDES"
all_libraries="$X_LDFLAGS $LDFLAGS_AS_NEEDED $LDFLAGS_NEW_DTAGS"

# Check for libraries that X11R6 Xt/Xaw programs need.
ac_save_LDFLAGS="$LDFLAGS"
LDFLAGS="$LDFLAGS $X_LDFLAGS"
# SM needs ICE to (dynamically) link under SunOS 4.x (so we have to
# check for ICE first), but we must link in the order -lSM -lICE or
# we get undefined symbols.  So assume we have SM if we have ICE.
# These have to be linked with before -lX11, unlike the other
# libraries we check for below, so use a different variable.
#  --interran@uluru.Stanford.EDU, kb@cs.umb.edu.
AC_CHECK_LIB(ICE, IceConnectionNumber,
  [LIBSM="-lSM -lICE"], , $X_EXTRA_LIBS)
LDFLAGS="$ac_save_LDFLAGS"

LIB_X11='-lX11 $(LIBSOCKET)'

AC_MSG_CHECKING(for libXext)
AC_CACHE_VAL(kde_cv_have_libXext,
[
kde_ldflags_safe="$LDFLAGS"
kde_libs_safe="$LIBS"

LDFLAGS="$LDFLAGS $X_LDFLAGS $USER_LDFLAGS"
LIBS="-lXext -lX11 $LIBSOCKET"

AC_TRY_LINK([
#include <stdio.h>
#ifdef STDC_HEADERS
# include <stdlib.h>
#endif
],
[
printf("hello Xext\n");
],
kde_cv_have_libXext=yes,
kde_cv_have_libXext=no
)

LDFLAGS=$kde_ldflags_safe
LIBS=$kde_libs_safe
])

AC_MSG_RESULT($kde_cv_have_libXext)

if test "$kde_cv_have_libXext" = "no"; then
  AC_MSG_ERROR([We need a working libXext to proceed. Since configure
can't find it itself, we stop here assuming that make wouldn't find
them either.])
fi

LIB_XEXT="-lXext"
QTE_NORTTI=""

CFLAGS="$CFLAGS -I/usr/include/tqt"
CXXFLAGS="$CXXFLAGS -I/usr/include/tqt"

elif test "$kde_use_qt_emb" = "yes"; then
  dnl We're using QT Embedded
  CPPFLAGS=-DQWS
  CXXFLAGS="$CXXFLAGS -fno-rtti"
  QTE_NORTTI="-fno-rtti -DQWS"
  X_PRE_LIBS=""
  LIB_X11=""
  LIB_XEXT=""
  LIB_XRENDER=""
  LIBSM=""
  X_INCLUDES=""
  X_LDFLAGS=""
  x_includes=""
  x_libraries=""
elif test "$kde_use_qt_mac" = "yes"; then
  dnl We're using QT/Mac (I use QT_MAC so that qglobal.h doesn't *have* to
  dnl be included to get the information) --Sam
  CXXFLAGS="$CXXFLAGS -DQT_MAC -no-cpp-precomp"
  CFLAGS="$CFLAGS -DQT_MAC -no-cpp-precomp"
  X_PRE_LIBS=""
  LIB_X11=""
  LIB_XEXT=""
  LIB_XRENDER=""
  LIBSM=""
  X_INCLUDES=""
  X_LDFLAGS=""
  x_includes=""
  x_libraries=""
fi
AC_SUBST(X_PRE_LIBS)
AC_SUBST(LIB_X11)
AC_SUBST(LIB_XRENDER)
AC_SUBST(LIBSM)
AC_SUBST(X_INCLUDES)
AC_SUBST(X_LDFLAGS)
AC_SUBST(x_includes)
AC_SUBST(x_libraries)
AC_SUBST(QTE_NORTTI)
AC_SUBST(LIB_XEXT)

])

AC_DEFUN([KDE_PRINT_QT_PROGRAM],
[
AC_REQUIRE([KDE_USE_QT])
cat > conftest.$ac_ext <<EOF
#include "confdefs.h"
EOF

if test "$kde_qtver" = "4"; then
cat >> conftest.$ac_ext <<EOF
#include <Qt/qglobal.h>
#include <Qt/qapplication.h>
EOF
fi

if test "$kde_qtver" = "3"; then
if $PKG_CONFIG --exists tqt-mt ; then
cat >> conftest.$ac_ext <<EOF
#include <tqglobal.h>
#include <tqapplication.h>
EOF
else
cat >> conftest.$ac_ext <<EOF
#include <tqt.h>
#include <qglobal.h>
#include <qapplication.h>
EOF
fi
fi

if test "$kde_qtver" = "2"; then
cat >> conftest.$ac_ext <<EOF
#include <qevent.h>
#include <qstring.h>
#include <qstyle.h>
EOF

if test $kde_qtsubver -gt 0; then
cat >> conftest.$ac_ext <<EOF
#if TQT_VERSION < 210
#error 1
#endif
EOF
fi
fi

if test "$kde_qtver" = "3"; then
if $PKG_CONFIG --exists tqt-mt ; then
cat >> conftest.$ac_ext <<EOF
#include <tqcursor.h>
#include <tqstylefactory.h>
#include <tqucomextra_p.h>
EOF
else
cat >> conftest.$ac_ext <<EOF
#include <qcursor.h>
#include <qstylefactory.h>
#include <private/qucomextra_p.h>
EOF
fi
fi

if test "$kde_qtver" = "4"; then
cat >> conftest.$ac_ext <<EOF
#include <Qt/qcursor.h>
#include <Qt/qstylefactory.h>
EOF
fi

echo "#if ! ($kde_qt_verstring)" >> conftest.$ac_ext
cat >> conftest.$ac_ext <<EOF
#error 1
#endif

int main() {
EOF
if test "$kde_qtver" = "2"; then
cat >> conftest.$ac_ext <<EOF
    QStringList *t = new QStringList();
    Q_UNUSED(t);
EOF
if test $kde_qtsubver -gt 0; then
cat >> conftest.$ac_ext <<EOF
    QString s;
    s.setLatin1("Elvis is alive", 14);
EOF
fi
fi
if test "$kde_qtver" = "3"; then
if $PKG_CONFIG --exists tqt-mt ; then
cat >> conftest.$ac_ext <<EOF
    (void)TQStyleFactory::create(TQString::null);
    TQCursor c(TQt::WhatsThisCursor);
EOF
else
cat >> conftest.$ac_ext <<EOF
    (void)QStyleFactory::create(QString::null);
    QCursor c(Qt::WhatsThisCursor);
EOF
fi
fi
if test "$kde_qtver" = "4"; then
cat >> conftest.$ac_ext <<EOF
    (void)QStyleFactory::create(QString::null);
    QCursor c(Qt::WhatsThisCursor);
EOF
fi
cat >> conftest.$ac_ext <<EOF
    return 0;
}
EOF
])

AC_DEFUN([KDE_USE_QT],
[
#if test -z "$1"; then
  # Current default Qt version: 3.3
  kde_qtver=3
  kde_qtsubver=3

  AC_LANG_SAVE
  AC_LANG_CPLUSPLUS
  ac_cxxflags_safe="$CXXFLAGS"
  CXXFLAGS="-I/usr/include/tqt"
  AC_TRY_COMPILE([
  #define TQT_VERSION_ONLY
  #include <tqt.h>
  #undef TQT_VERSION_ONLY
  #ifdef USE_QT4
  choke me
  #endif
  ], ,
    kde_qtver=3,
    kde_qtver=4
  )
  CXXFLAGS="$ac_cxxflags_safe"
  AC_LANG_RESTORE

  if test "$kde_qtver" = "3"; then
    AC_MSG_RESULT(Detected TQt3...)
  fi
  if test "$kde_qtver" = "4"; then
    AC_MSG_RESULT(Detected Qt4...)
  fi

#else
#  kde_qtsubver=`echo "$1" | sed -e 's#[0-9][0-9]*\.\([0-9][0-9]*\).*#\1#'`
#  # following is the check if subversion isnt found in passed argument
#  if test "$kde_qtsubver" = "$1"; then
#    kde_qtsubver=1
#  fi
#  kde_qtver=`echo "$1" | sed -e 's#^\([0-9][0-9]*\)\..*#\1#'`
#  if test "$kde_qtver" = "1"; then
#    kde_qtsubver=42
#  fi
#fi

if test -z "$2"; then
  if test "$kde_qtver" = "2"; then
    if test $kde_qtsubver -gt 0; then
      kde_qt_minversion=">= Qt 2.2.2"
    else
      kde_qt_minversion=">= Qt 2.0.2"
    fi
  fi
  if test "$kde_qtver" = "3"; then
    if test $kde_qtsubver -gt 0; then
	 if test $kde_qtsubver -gt 1; then
	    if test $kde_qtsubver -gt 2; then
		kde_qt_minversion=">= Qt 3.3 and < 4.0"
	    else
	        kde_qt_minversion=">= Qt 3.2 and < 4.0"
	    fi
	 else
            kde_qt_minversion=">= Qt 3.1 (20021021) and < 4.0"
         fi
    else
      kde_qt_minversion=">= Qt 3.0 and < 4.0"
    fi
  fi
  if test "$kde_qtver" = "4"; then
    if test $kde_qtsubver -gt 0; then
	 if test $kde_qtsubver -gt 1; then
	    if test $kde_qtsubver -gt 2; then
		kde_qt_minversion=">= Qt 4.3 and < 5.0"
	    else
	        kde_qt_minversion=">= Qt 4.2 and < 5.0"
	    fi
	 else
            kde_qt_minversion=">= Qt 4.1 and < 5.0"
         fi
    else
      kde_qt_minversion=">= Qt 4.0 and < 5.0"
    fi
  fi
  if test "$kde_qtver" = "1"; then
    kde_qt_minversion=">= 1.42 and < 2.0"
  fi
else
   kde_qt_minversion="$2"
fi

if test -z "$3"; then
   if test $kde_qtver = 4; then
     if test $kde_qtsubver -gt 0; then
       kde_qt_verstring="TQT_VERSION >= 0x04@VER@00 && TQT_VERSION < 0x050000"
       qtsubver=`echo "00$kde_qtsubver" | sed -e 's,.*\(..\)$,\1,'`
       kde_qt_verstring=`echo $kde_qt_verstring | sed -e "s,@VER@,$qtsubver,"`
     else
       kde_qt_verstring="TQT_VERSION >= 400 && TQT_VERSION < 0x050000"
     fi
   fi
   if test $kde_qtver = 3; then
     if test $kde_qtsubver -gt 0; then
       kde_qt_verstring="TQT_VERSION >= 0x03@VER@00 && TQT_VERSION < 0x040000"
       qtsubver=`echo "00$kde_qtsubver" | sed -e 's,.*\(..\)$,\1,'`
       kde_qt_verstring=`echo $kde_qt_verstring | sed -e "s,@VER@,$qtsubver,"`
     else
       kde_qt_verstring="TQT_VERSION >= 300 && TQT_VERSION < 0x040000"
     fi
   fi
   if test $kde_qtver = 2; then
     if test $kde_qtsubver -gt 0; then
       kde_qt_verstring="TQT_VERSION >= 222"
     else
       kde_qt_verstring="TQT_VERSION >= 200"
     fi
   fi
   if test $kde_qtver = 1; then
    kde_qt_verstring="TQT_VERSION >= 142 && TQT_VERSION < 200"
   fi
else
   kde_qt_verstring="$3"
fi

if test $kde_qtver = 4; then
  kde_qt_dirs="/usr/lib/qt4 /usr/lib/qt /usr/share/qt4"
fi
if test $kde_qtver = 3; then
  kde_qt_dirs="/usr/lib/tqt3 /usr/share/tqt3"
  if test -z "$PKG_CONFIG"; then
      AC_PATH_PROG(PKG_CONFIG, pkg-config, no)
  fi
  if test "$PKG_CONFIG" != "no" ; then
    if $PKG_CONFIG --exists tqt-mt ; then
       kde_qt_dirs="$kde_qt_dirs `$PKG_CONFIG --variable=prefix tqt-mt`"
       LIB_QUI="-ltqui"
       AC_SUBST(LIB_QUI)
    else
       if $PKG_CONFIG --exists qt-mt ; then
         kde_qt_dirs="$kde_qt_dirs `$PKG_CONFIG --variable=prefix tqt-mt`"
         LIB_QUI="-lqui"
         AC_SUBST(LIB_QUI)
       fi
    fi
  fi
fi
if test $kde_qtver = 2; then
   kde_qt_dirs="$QTDIR /usr/lib/qt2 /usr/lib/qt"
fi
if test $kde_qtver = 1; then
   kde_qt_dirs="$QTDIR /usr/lib/qt"
fi
])

AC_DEFUN([KDE_CHECK_QT_DIRECT],
[
AC_REQUIRE([KDE_USE_QT])
AC_MSG_CHECKING([if Qt compiles without flags])
AC_CACHE_VAL(kde_cv_qt_direct,
[
AC_LANG_SAVE
AC_LANG_CPLUSPLUS
ac_LD_LIBRARY_PATH_safe=$LD_LIBRARY_PATH
ac_LIBRARY_PATH="$LIBRARY_PATH"
ac_cxxflags_safe="$CXXFLAGS"
ac_ldflags_safe="$LDFLAGS"
ac_libs_safe="$LIBS"

CXXFLAGS="$CXXFLAGS -I$qt_includes"
LDFLAGS="$LDFLAGS $X_LDFLAGS"
if test "x$kde_use_qt_emb" != "xyes" && test "x$kde_use_qt_mac" != "xyes"; then
LIBS="$LIBQT -lXext -lX11 $LIBSOCKET"
else
LIBS="$LIBQT $LIBSOCKET"
fi
LD_LIBRARY_PATH=
export LD_LIBRARY_PATH
LIBRARY_PATH=
export LIBRARY_PATH

KDE_PRINT_QT_PROGRAM

if AC_TRY_EVAL(ac_link) && test -s conftest; then
  kde_cv_qt_direct="yes"
else
  kde_cv_qt_direct="no"
  echo "configure: failed program was:" >&AC_FD_CC
  cat conftest.$ac_ext >&AC_FD_CC
fi

rm -f conftest*
CXXFLAGS="$ac_cxxflags_safe"
LDFLAGS="$ac_ldflags_safe"
LIBS="$ac_libs_safe"

LD_LIBRARY_PATH="$ac_LD_LIBRARY_PATH_safe"
export LD_LIBRARY_PATH
LIBRARY_PATH="$ac_LIBRARY_PATH"
export LIBRARY_PATH
AC_LANG_RESTORE
])

if test "$kde_cv_qt_direct" = "yes"; then
  AC_MSG_RESULT(yes)
  $1
else
  AC_MSG_RESULT(no)
  $2
fi
])

dnl ------------------------------------------------------------------------
dnl Try to find the Qt headers and libraries.
dnl $(QT_LDFLAGS) will be -Lqtliblocation (if needed)
dnl and $(QT_INCLUDES) will be -Iqthdrlocation (if needed)
dnl ------------------------------------------------------------------------
dnl
AC_DEFUN([AC_PATH_QT_1_3],
[
AC_REQUIRE([K_PATH_X])
AC_REQUIRE([KDE_USE_QT])
AC_REQUIRE([KDE_CHECK_LIB64])

dnl ------------------------------------------------------------------------
dnl Add configure flag to enable linking to MT version of Qt library.
dnl ------------------------------------------------------------------------

AC_ARG_ENABLE(
  mt,
  AC_HELP_STRING([--disable-mt],[link to non-threaded Qt (deprecated)]),
  kde_use_qt_mt=$enableval,
  [
    if test $kde_qtver = 3; then
      kde_use_qt_mt=yes
    else
      if test $kde_qtver = 4; then
        kde_use_qt_mt=yes
      else
        kde_use_qt_mt=no
      fi
    fi
  ]
)

USING_QT_MT=""

dnl ------------------------------------------------------------------------
dnl If we not get --disable-qt-mt then adjust some vars for the host.
dnl ------------------------------------------------------------------------

KDE_MT_LDFLAGS=
KDE_MT_LIBS=
if test "x$kde_use_qt_mt" = "xyes"; then
  KDE_CHECK_THREADING
  if test "x$kde_use_threading" = "xyes"; then
    CPPFLAGS="$USE_THREADS -DQT_THREAD_SUPPORT $CPPFLAGS"
    KDE_MT_LDFLAGS="$USE_THREADS"
    KDE_MT_LIBS="$LIBPTHREAD"
  else
    kde_use_qt_mt=no
  fi
fi
AC_SUBST(KDE_MT_LDFLAGS)
AC_SUBST(KDE_MT_LIBS)

kde_qt_was_given=yes

dnl ------------------------------------------------------------------------
dnl If we haven't been told how to link to Qt, we work it out for ourselves.
dnl ------------------------------------------------------------------------
if test -z "$LIBQT_GLOB"; then
  if test "$kde_qtver" = "4"; then
    LIBQT_GLOB="libQtCore.*"
  fi
  if test "$kde_qtver" = "3"; then
    if test "x$kde_use_qt_emb" = "xyes"; then
      LIBQT_GLOB="libqte.*"
    else
      if $PKG_CONFIG --exists tqt-mt ; then
        LIBQT_GLOB="libtqt.*"
      else
        LIBQT_GLOB="libqt.*"
      fi
    fi
  fi
fi

dnl ------------------------------------------------------------
dnl If we got --enable-embedded then adjust the Qt library name.
dnl Also Qt4 uses a different library name
dnl ------------------------------------------------------------
if test "$kde_qtver" = "4"; then
  qtlib="QtCore -lQtGui -lQtNetwork -ltqt"
fi
if test "$kde_qtver" = "3"; then
  if test "x$kde_use_qt_emb" = "xyes"; then
    qtlib="qte"
  else
    if $PKG_CONFIG --exists tqt-mt ; then
      qtlib="tqt"
    else
      qtlib="qt"
    fi
  fi
fi

kde_int_qt="-l$qtlib"

if test -z "$LIBQPE"; then
dnl ------------------------------------------------------------
dnl If we got --enable-palmtop then add -lqpe to the link line
dnl ------------------------------------------------------------
  if test "x$kde_use_qt_emb" = "xyes"; then
    if test "x$kde_use_qt_emb_palm" = "xyes"; then
      LIB_QPE="-lqpe"
    else
      LIB_QPE=""
    fi
  else
    LIB_QPE=""
  fi
fi

dnl ------------------------------------------------------------------------
dnl If we got --enable-qt-mt then adjust the Qt library name for the host.
dnl ------------------------------------------------------------------------

if test "x$kde_use_qt_mt" = "xyes"; then
  if test $kde_qtver = 3; then
    LIBQT="-l$qtlib-mt"
    kde_int_qt="-l$qtlib-mt"
    LIBQT_GLOB="lib$qtlib-mt.*"
  else
    if test $kde_qtver = 4; then
      LIBQT="-l$qtlib"
    fi
  fi
  USING_QT_MT="using -mt"
else
  LIBQT="-l$qtlib"
fi

if test $kde_qtver != 1; then

  AC_REQUIRE([AC_FIND_PNG])
  AC_REQUIRE([AC_FIND_JPEG])
  LIBQT="$LIBQT $LIBPNG $LIBJPEG"
fi

if test $kde_qtver = 3; then
  AC_REQUIRE([KDE_CHECK_LIBDL])
  LIBQT="$LIBQT $LIBDL"
fi

if test $kde_qtver = 4; then
  AC_REQUIRE([KDE_CHECK_LIBDL])
  LIBQT="$LIBQT $LIBDL"
fi

AC_MSG_CHECKING([for Qt])

if test "x$kde_use_qt_emb" != "xyes" && test "x$kde_use_qt_mac" != "xyes"; then
LIBQT="$LIBQT $X_PRE_LIBS -lXext -lX11 $LIBSM $LIBSOCKET"
fi
ac_qt_includes=NO ac_qt_libraries=NO ac_qt_bindir=NO
qt_libraries=""
qt_includes=""
AC_ARG_WITH(qt-dir,
    AC_HELP_STRING([--with-qt-dir=DIR],[where the root of Qt is installed ]),
    [  ac_qt_includes="$withval"/include
       ac_qt_libraries="$withval"/lib${tdelibsuff}
       ac_qt_bindir="$withval"/bin
    ])

AC_ARG_WITH(qt-includes,
    AC_HELP_STRING([--with-qt-includes=DIR],[where the Qt includes are. ]),
    [
       ac_qt_includes="$withval"
    ])

kde_qt_libs_given=no

AC_ARG_WITH(qt-libraries,
    AC_HELP_STRING([--with-qt-libraries=DIR],[where the Qt library is installed.]),
    [  ac_qt_libraries="$withval"
       kde_qt_libs_given=yes
    ])

AC_CACHE_VAL(ac_cv_have_qt,
[#try to guess Qt locations

qt_incdirs=""
for dir in $kde_qt_dirs; do
   qt_incdirs="$qt_incdirs $dir/include $dir"
done
if test -z "$PKG_CONFIG"; then
    AC_PATH_PROG(PKG_CONFIG, pkg-config, no)
fi
if test "$PKG_CONFIG" != "no" ; then
  if $PKG_CONFIG --exists tqt-mt ; then
      qt_incdirs="$qt_incdirs `$PKG_CONFIG --variable=includedir tqt-mt`"
  else
      if $PKG_CONFIG --exists qt-mt ; then
          qt_incdirs="$qt_incdirs `$PKG_CONFIG --variable=includedir tqt-mt`"
      fi
  fi
fi
qt_incdirs="$qt_incdirs /usr/include/tqt3 /usr/include $x_includes"
if test ! "$ac_qt_includes" = "NO"; then
   qt_incdirs="$ac_qt_includes $qt_incdirs"
fi

if test "$kde_qtver" != "1"; then
  if test "$kde_qtver" = "4"; then
    kde_qt_header="Qt/qstyle.h"
  else
    kde_qt_header=qstyle.h
    kde_tqt_header=ntqstyle.h
  fi
else
  kde_qt_header=qglobal.h
  kde_tqt_header=ntqglobal.h
fi

AC_FIND_FILE($kde_qt_header, $qt_incdirs, qt_incdir)
if test "$qt_incdir" = "NO"; then
   AC_FIND_FILE($kde_tqt_header, $qt_incdirs, qt_incdir)
fi
ac_qt_includes="$qt_incdir"

qt_libdirs=""
for dir in $kde_qt_dirs; do
   qt_libdirs="$qt_libdirs $dir/lib${tdelibsuff} $dir/lib $dir"
done
if test -z "$PKG_CONFIG"; then
    AC_PATH_PROG(PKG_CONFIG, pkg-config, no)
fi
if test "$PKG_CONFIG" != "no" ; then
  if $PKG_CONFIG --exists tqt-mt ; then
      qt_libdirs="$qt_incdirs `$PKG_CONFIG --variable=libdir tqt-mt`"
  else
      if $PKG_CONFIG --exists qt-mt ; then
          qt_libdirs="$qt_incdirs `$PKG_CONFIG --variable=libdir tqt-mt`"
      fi
  fi
fi
qt_libdirs="$QTLIB $qt_libdirs /usr/X11R6/lib /usr/lib /usr/local/qt/lib $x_libraries"
if test ! "$ac_qt_libraries" = "NO"; then
  qt_libdir=$ac_qt_libraries
else
  qt_libdirs="$ac_qt_libraries $qt_libdirs"
  # if the Qt was given, the chance is too big that libqt.* doesn't exist
  qt_libdir=NONE
  for dir in $qt_libdirs; do
    try="ls -1 $dir/${LIBQT_GLOB}"
    if test -n "`$try 2> /dev/null`"; then qt_libdir=$dir; break; else echo "tried $dir" >&AC_FD_CC ; fi
  done
fi
for a in $qt_libdir/lib`echo ${kde_int_qt} | sed 's,^-l,,'`_incremental.*; do
  if test -e "$a"; then
    LIBQT="$LIBQT ${kde_int_qt}_incremental"
    break
  fi
done

ac_qt_libraries="$qt_libdir"

AC_LANG_SAVE
AC_LANG_CPLUSPLUS

ac_cxxflags_safe="$CXXFLAGS"
ac_ldflags_safe="$LDFLAGS"
ac_libs_safe="$LIBS"

CXXFLAGS="$CXXFLAGS -I$qt_incdir $all_includes"
LDFLAGS="$LDFLAGS -L$qt_libdir $all_libraries $USER_LDFLAGS $KDE_MT_LDFLAGS"
LIBS="$LIBS $LIBQT $KDE_MT_LIBS"

KDE_PRINT_QT_PROGRAM

if AC_TRY_EVAL(ac_link) && test -s conftest; then
  rm -f conftest*
else
  echo "configure: failed program was:" >&AC_FD_CC
  cat conftest.$ac_ext >&AC_FD_CC
  ac_qt_libraries="NO"
fi
rm -f conftest*
CXXFLAGS="$ac_cxxflags_safe"
LDFLAGS="$ac_ldflags_safe"
LIBS="$ac_libs_safe"

AC_LANG_RESTORE
if test "$ac_qt_includes" = NO || test "$ac_qt_libraries" = NO; then
  ac_cv_have_qt="have_qt=no"
  ac_qt_notfound=""
  missing_qt_mt=""
  if test "$ac_qt_includes" = NO; then
    if test "$ac_qt_libraries" = NO; then
      ac_qt_notfound="(headers and libraries)";
    else
      ac_qt_notfound="(headers)";
    fi
  else
    if test "x$kde_use_qt_mt" = "xyes"; then
       missing_qt_mt="
Make sure that you have compiled Qt with thread support!"
       ac_qt_notfound="(library $qtlib-mt)";
    else
       ac_qt_notfound="(library $qtlib)";
    fi
  fi

  AC_MSG_ERROR([Qt ($kde_qt_minversion) $ac_qt_notfound not found. Please check your installation!
For more details about this problem, look at the end of config.log.$missing_qt_mt])
else
  have_qt="yes"
fi
])

eval "$ac_cv_have_qt"

if test "$have_qt" != yes; then
  AC_MSG_RESULT([$have_qt]);
else
  ac_cv_have_qt="have_qt=yes \
    ac_qt_includes=$ac_qt_includes ac_qt_libraries=$ac_qt_libraries"
  AC_MSG_RESULT([libraries $ac_qt_libraries, headers $ac_qt_includes $USING_QT_MT])

  qt_libraries="$ac_qt_libraries"
  qt_includes="$ac_qt_includes"
fi

if test ! "$kde_qt_libs_given" = "yes" && test ! "$kde_qtver" = 3; then
     KDE_CHECK_QT_DIRECT(qt_libraries= ,[])
fi

AC_SUBST(qt_libraries)
AC_SUBST(qt_includes)

if test "$qt_includes" = "$x_includes" || test -z "$qt_includes"; then
 QT_INCLUDES=""
else
 QT_INCLUDES="-I$qt_includes"
 all_includes="$QT_INCLUDES $all_includes"
fi

if test "$qt_libraries" = "$x_libraries" || test -z "$qt_libraries"; then
 QT_LDFLAGS=""
else
 QT_LDFLAGS="-L$qt_libraries"
 all_libraries="$QT_LDFLAGS $all_libraries"
fi
test -z "$KDE_MT_LDFLAGS" || all_libraries="$all_libraries $KDE_MT_LDFLAGS"

AC_SUBST(QT_INCLUDES)
AC_SUBST(QT_LDFLAGS)
AC_PATH_QT_MOC_UIC

KDE_CHECK_TQT

KDE_CHECK_QT_JPEG

if test "x$kde_use_qt_emb" != "xyes" && test "x$kde_use_qt_mac" != "xyes"; then
LIB_QT="$kde_int_qt $LIBJPEG_QT "'$(LIBZ) $(LIBPNG) -lXext $(LIB_X11) $(LIBSM) $(LIBTQT_LDFLAGS)'
else
LIB_QT="$kde_int_qt $LIBJPEG_QT "'$(LIBZ) $(LIBPNG) $(LIBTQT_LDFLAGS)'
fi
test -z "$KDE_MT_LIBS" || LIB_QT="$LIB_QT $KDE_MT_LIBS"
for a in $qt_libdir/lib`echo ${kde_int_qt} | sed 's,^-l,,'`_incremental.*; do
  if test -e "$a"; then
     LIB_QT="$LIB_QT ${kde_int_qt}_incremental"
     break
  fi
done

AC_SUBST(LIB_QT)
AC_SUBST(LIB_QPE)

AC_SUBST(kde_qtver)
])

AC_DEFUN([AC_PATH_QT],
[
AC_PATH_QT_1_3
])

AC_DEFUN([KDE_CHECK_UIC_PLUGINS],
[
AC_REQUIRE([AC_PATH_QT_MOC_UIC])

if test x$ac_uic_supports_libpath = xyes; then

AC_MSG_CHECKING([if UIC has TDE plugins available])
AC_CACHE_VAL(kde_cv_uic_plugins,
[
cat > actest.ui << EOF
<!DOCTYPE UI><UI version="3.0" stdsetdef="1">
<class>NewConnectionDialog</class>
<widget class="TQDialog">
   <widget class="KLineEdit">
        <property name="name">
           <cstring>testInput</cstring>
        </property>
   </widget>
</widget>
</UI>
EOF
       


kde_cv_uic_plugins=no
kde_line="$UIC_PATH -L $kde_widgetdir"
if test x$ac_uic_supports_nounload = xyes; then
   kde_line="$kde_line -nounload"
fi
kde_line="$kde_line -impl actest.h actest.ui > actest.cpp"
if AC_TRY_EVAL(kde_line); then
	# if you're trying to debug this check and think it's incorrect,
	# better check your installation. The check _is_ correct - your
	# installation is not.
	if test -f actest.cpp && grep klineedit actest.cpp > /dev/null; then
		kde_cv_uic_plugins=yes
	fi
fi
rm -f actest.ui actest.cpp
])

AC_MSG_RESULT([$kde_cv_uic_plugins])
if test "$kde_cv_uic_plugins" != yes; then
	AC_MSG_ERROR([
you need to install tdelibs first.

If you did install tdelibs, then the Qt version that is picked up by
this configure is not the same version you used to compile tdelibs. 
The Qt Plugin installed by tdelibs is *ONLY* loadable if it is the 
_same Qt version_, compiled with the _same compiler_ and the same Qt
configuration settings.
])
fi
fi
])

AC_DEFUN([KDE_CHECK_FINAL],
[
  AC_ARG_ENABLE(final,
	AC_HELP_STRING([--enable-final],
		       [build size optimized apps (experimental - needs lots of memory)]),
	kde_use_final=$enableval, kde_use_final=no)

  if test "x$kde_use_final" = "xyes"; then
      KDE_USE_FINAL_TRUE=""
      KDE_USE_FINAL_FALSE="#"
   else
      KDE_USE_FINAL_TRUE="#"
      KDE_USE_FINAL_FALSE=""
  fi
  AC_SUBST(KDE_USE_FINAL_TRUE)
  AC_SUBST(KDE_USE_FINAL_FALSE)
])

AC_DEFUN([KDE_CHECK_CLOSURE],
[
  AC_ARG_ENABLE(closure,
		AC_HELP_STRING([--enable-closure],[delay template instantiation]),
  	kde_use_closure=$enableval, kde_use_closure=no)

  KDE_NO_UNDEFINED=""
  if test "x$kde_use_closure" = "xyes"; then
       KDE_USE_CLOSURE_TRUE=""
       KDE_USE_CLOSURE_FALSE="#"
#       CXXFLAGS="$CXXFLAGS $REPO"
  else
       KDE_USE_CLOSURE_TRUE="#"
       KDE_USE_CLOSURE_FALSE=""
       KDE_NO_UNDEFINED=""
       case $host in 
         *-*-linux-gnu)
           KDE_CHECK_COMPILER_FLAG([Wl,--no-undefined],
                [KDE_CHECK_COMPILER_FLAG([Wl,--allow-shlib-undefined],
		[KDE_NO_UNDEFINED="-Wl,--no-undefined -Wl,--allow-shlib-undefined"],
		[KDE_NO_UNDEFINED=""])],
	    [KDE_NO_UNDEFINED=""])
           ;;
       esac
  fi
  AC_SUBST(KDE_USE_CLOSURE_TRUE)
  AC_SUBST(KDE_USE_CLOSURE_FALSE)
  AC_SUBST(KDE_NO_UNDEFINED)
])

dnl Check if the linker supports --enable-new-dtags and --as-needed
AC_DEFUN([KDE_CHECK_NEW_LDFLAGS],
[
  AC_ARG_ENABLE(new_ldflags,
		AC_HELP_STRING([--enable-new-ldflags],
		[enable the new linker flags]),
	kde_use_new_ldflags=$enableval, 
	kde_use_new_ldflags=no)

  LDFLAGS_AS_NEEDED=""
  LDFLAGS_NEW_DTAGS=""
  if test "x$kde_use_new_ldflags" = "xyes"; then
       LDFLAGS_NEW_DTAGS=""
       KDE_CHECK_COMPILER_FLAG([Wl,--enable-new-dtags],
		[LDFLAGS_NEW_DTAGS="-Wl,--enable-new-dtags"],)

       KDE_CHECK_COMPILER_FLAG([Wl,--as-needed],
		[LDFLAGS_AS_NEEDED="-Wl,--as-needed"],)
  fi
  AC_SUBST(LDFLAGS_AS_NEEDED)
  AC_SUBST(LDFLAGS_NEW_DTAGS)
])

AC_DEFUN([KDE_CHECK_NMCHECK],
[
  AC_ARG_ENABLE(nmcheck,AC_HELP_STRING([--enable-nmcheck],[enable automatic namespace cleanness check]),
	kde_use_nmcheck=$enableval, kde_use_nmcheck=no)

  if test "$kde_use_nmcheck" = "yes"; then
      KDE_USE_NMCHECK_TRUE=""
      KDE_USE_NMCHECK_FALSE="#"
   else
      KDE_USE_NMCHECK_TRUE="#"
      KDE_USE_NMCHECK_FALSE=""
  fi
  AC_SUBST(KDE_USE_NMCHECK_TRUE)
  AC_SUBST(KDE_USE_NMCHECK_FALSE)
])

AC_DEFUN([KDE_EXPAND_MAKEVAR], [
savex=$exec_prefix
test "x$exec_prefix" = xNONE && exec_prefix=$prefix
tmp=$$2
while $1=`eval echo "$tmp"`; test "x$$1" != "x$tmp"; do tmp=$$1; done
exec_prefix=$savex
])

dnl ------------------------------------------------------------------------
dnl Now, the same with KDE
dnl $(KDE_LDFLAGS) will be the kdeliblocation (if needed)
dnl and $(kde_includes) will be the kdehdrlocation (if needed)
dnl ------------------------------------------------------------------------
dnl
AC_DEFUN([AC_BASE_PATH_KDE],
[
AC_REQUIRE([KDE_CHECK_STL])
AC_REQUIRE([AC_PATH_QT])dnl
AC_REQUIRE([KDE_CHECK_LIB64])

AC_CHECK_RPATH
AC_MSG_CHECKING([for KDE])

if test "${prefix}" != NONE; then
  kde_includes=${includedir}
  KDE_EXPAND_MAKEVAR(ac_kde_includes, includedir)

  kde_libraries=${libdir}
  KDE_EXPAND_MAKEVAR(ac_kde_libraries, libdir)

else
  ac_kde_includes=
  ac_kde_libraries=
  kde_libraries=""
  kde_includes=""
fi

AC_CACHE_VAL(ac_cv_have_kde,
[#try to guess kde locations

if test "$kde_qtver" = 1; then
  kde_check_header="ksock.h"
  kde_check_lib="libtdecore.la"
else
  kde_check_header="ksharedptr.h"
  kde_check_lib="libtdeio.la"
fi

if test -z "$1"; then

kde_incdirs="$kde_libs_prefix/include /opt/trinity/include/tde /opt/trinity/include/tde /usr/lib/kde/include /usr/local/kde/include /usr/local/include /usr/kde/include /usr/include/tde /usr/include /opt/trinity/include /opt/trinity/include /opt/kde/include $x_includes $qt_includes"
test -n "$TDEDIR" && kde_incdirs="$TDEDIR/include $TDEDIR/include/tde $TDEDIR $kde_incdirs"
kde_incdirs="$ac_kde_includes $kde_incdirs"
AC_FIND_FILE($kde_check_header, $kde_incdirs, kde_incdir)
ac_kde_includes="$kde_incdir"

if test -n "$ac_kde_includes" && test ! -r "$ac_kde_includes/$kde_check_header"; then
  AC_MSG_ERROR([
No TDE headers are installed in the chosen prefix. This will fail.
Please check this and use another prefix if needed!])
fi

kde_libdirs="$kde_libs_prefix/lib${tdelibsuff} /usr/lib/kde/lib${tdelibsuff} /usr/local/kde/lib${tdelibsuff} /usr/kde/lib${tdelibsuff} /usr/lib${tdelibsuff}/kde /usr/lib${tdelibsuff}/trinity /usr/lib${tdelibsuff} /usr/X11R6/lib${tdelibsuff} /usr/local/lib${tdelibsuff} /opt/trinity/lib${tdelibsuff} /opt/trinity/lib${tdelibsuff} /opt/kde/lib${tdelibsuff} /usr/X11R6/kde/lib${tdelibsuff}"
test -n "$TDEDIR" && kde_libdirs="$TDEDIR/lib${tdelibsuff} $TDEDIR $kde_libdirs"
kde_libdirs="$ac_kde_libraries $libdir $kde_libdirs"
AC_FIND_FILE($kde_check_lib, $kde_libdirs, kde_libdir)
ac_kde_libraries="$kde_libdir"

kde_widgetdir=NO
dnl this might be somewhere else
AC_FIND_FILE("trinity/plugins/designer/tdewidgets.la", $kde_libdirs, kde_widgetdir)

if test -n "$ac_kde_libraries" && test ! -r "$ac_kde_libraries/$kde_check_lib"; then
AC_MSG_ERROR([
in the prefix, you've chosen, are no TDE libraries installed. This will fail.
So, check this please and use another prefix!])
fi

if test -n "$kde_widgetdir" && test ! -r "$kde_widgetdir/trinity/plugins/designer/tdewidgets.la"; then
AC_MSG_ERROR([
I can't find the designer plugins. These are required and should have been installed
by tdelibs])
fi

if test -n "$kde_widgetdir"; then
    kde_widgetdir="$kde_widgetdir/trinity/plugins/designer"
fi


if test "$ac_kde_includes" = NO || test "$ac_kde_libraries" = NO || test "$kde_widgetdir" = NO; then
  ac_cv_have_kde="have_kde=no"
else
  ac_cv_have_kde="have_kde=yes \
    ac_kde_includes=$ac_kde_includes ac_kde_libraries=$ac_kde_libraries"
fi

else dnl test -z $1, e.g. from tdelibs

  ac_cv_have_kde="have_kde=no"

fi
])dnl

eval "$ac_cv_have_kde"

if test "$have_kde" != "yes"; then
 if test "${prefix}" = NONE; then
  ac_kde_prefix="$ac_default_prefix"
 else
  ac_kde_prefix="$prefix"
 fi
 if test "$exec_prefix" = NONE; then
  ac_kde_exec_prefix="$ac_kde_prefix"
  AC_MSG_RESULT([will be installed in $ac_kde_prefix])
 else
  ac_kde_exec_prefix="$exec_prefix"
  AC_MSG_RESULT([will be installed in $ac_kde_prefix and $ac_kde_exec_prefix])
 fi

 kde_libraries="${libdir}"
 kde_includes="${includedir}"

else
  ac_cv_have_kde="have_kde=yes \
    ac_kde_includes=$ac_kde_includes ac_kde_libraries=$ac_kde_libraries"
  AC_MSG_RESULT([libraries $ac_kde_libraries, headers $ac_kde_includes])

  kde_libraries="$ac_kde_libraries"
  kde_includes="$ac_kde_includes"
fi
AC_SUBST(kde_libraries)
AC_SUBST(kde_includes)

if test "$kde_includes" = "$x_includes" || test "$kde_includes" = "$qt_includes"  || test "$kde_includes" = "/usr/include"; then
 KDE_INCLUDES=""
else
 KDE_INCLUDES="-I$kde_includes"
 all_includes="$KDE_INCLUDES $all_includes"
fi

KDE_DEFAULT_CXXFLAGS="-DQT_CLEAN_NAMESPACE -DQT_NO_ASCII_CAST -DQT_NO_STL -DQT_NO_COMPAT -DQT_NO_TRANSLATION"
 
KDE_LDFLAGS="-L$kde_libraries"
if test ! "$kde_libraries" = "$x_libraries" && test ! "$kde_libraries" = "$qt_libraries" ; then 
 all_libraries="$KDE_LDFLAGS $all_libraries"
fi

AC_SUBST(KDE_LDFLAGS)
AC_SUBST(KDE_INCLUDES)

AC_REQUIRE([KDE_CHECK_EXTRA_LIBS])

all_libraries="$all_libraries $USER_LDFLAGS"
all_includes="$all_includes $USER_INCLUDES"
AC_SUBST(all_includes)
AC_SUBST(all_libraries)

if test -z "$1"; then
KDE_CHECK_UIC_PLUGINS
fi

ac_kde_libraries="$kde_libdir"

AC_SUBST(AUTODIRS)


])

AC_DEFUN([KDE_CHECK_EXTRA_LIBS],
[
AC_MSG_CHECKING(for extra includes)
AC_ARG_WITH(extra-includes,AC_HELP_STRING([--with-extra-includes=DIR],[adds non standard include paths]),
  kde_use_extra_includes="$withval",
  kde_use_extra_includes=NONE
)
kde_extra_includes=
if test -n "$kde_use_extra_includes" && \
   test "$kde_use_extra_includes" != "NONE"; then

   ac_save_ifs=$IFS
   IFS=':'
   for dir in $kde_use_extra_includes; do
     kde_extra_includes="$kde_extra_includes $dir"
     USER_INCLUDES="$USER_INCLUDES -I$dir"
   done
   IFS=$ac_save_ifs
   kde_use_extra_includes="added"
else
   kde_use_extra_includes="no"
fi
AC_SUBST(USER_INCLUDES)

AC_MSG_RESULT($kde_use_extra_includes)

kde_extra_libs=
AC_MSG_CHECKING(for extra libs)
AC_ARG_WITH(extra-libs,AC_HELP_STRING([--with-extra-libs=DIR],[adds non standard library paths]),
  kde_use_extra_libs=$withval,
  kde_use_extra_libs=NONE
)
if test -n "$kde_use_extra_libs" && \
   test "$kde_use_extra_libs" != "NONE"; then

   ac_save_ifs=$IFS
   IFS=':'
   for dir in $kde_use_extra_libs; do
     kde_extra_libs="$kde_extra_libs $dir"
     KDE_EXTRA_RPATH="$KDE_EXTRA_RPATH -R $dir"
     USER_LDFLAGS="$USER_LDFLAGS -L$dir"
   done
   IFS=$ac_save_ifs
   kde_use_extra_libs="added"
else
   kde_use_extra_libs="no"
fi

AC_SUBST(USER_LDFLAGS)

AC_MSG_RESULT($kde_use_extra_libs)

])

AC_DEFUN([KDE_1_CHECK_PATH_HEADERS],
[
    AC_MSG_CHECKING([for TDE headers installed])
    AC_LANG_SAVE
    AC_LANG_CPLUSPLUS
cat > conftest.$ac_ext <<EOF
#ifdef STDC_HEADERS
# include <stdlib.h>
#endif
#include <stdio.h>
#include "confdefs.h"
#include <kapp.h>

int main() {
    printf("kde_htmldir=\\"%s\\"\n", TDEApplication::kde_htmldir().data());
    printf("kde_appsdir=\\"%s\\"\n", TDEApplication::kde_appsdir().data());
    printf("kde_icondir=\\"%s\\"\n", TDEApplication::kde_icondir().data());
    printf("kde_sounddir=\\"%s\\"\n", TDEApplication::kde_sounddir().data());
    printf("kde_datadir=\\"%s\\"\n", TDEApplication::kde_datadir().data());
    printf("kde_locale=\\"%s\\"\n", TDEApplication::kde_localedir().data());
    printf("kde_cgidir=\\"%s\\"\n", TDEApplication::kde_cgidir().data());
    printf("kde_confdir=\\"%s\\"\n", TDEApplication::kde_configdir().data());
    printf("kde_mimedir=\\"%s\\"\n", TDEApplication::kde_mimedir().data());
    printf("kde_toolbardir=\\"%s\\"\n", TDEApplication::kde_toolbardir().data());
    printf("kde_wallpaperdir=\\"%s\\"\n",
	TDEApplication::kde_wallpaperdir().data());
    printf("kde_bindir=\\"%s\\"\n", TDEApplication::kde_bindir().data());
    printf("kde_partsdir=\\"%s\\"\n", TDEApplication::kde_partsdir().data());
    printf("kde_servicesdir=\\"/tmp/dummy\\"\n");
    printf("kde_servicetypesdir=\\"/tmp/dummy\\"\n");
    printf("kde_moduledir=\\"/tmp/dummy\\"\n");
    printf("kde_styledir=\\"/tmp/dummy\\"\n");
    printf("kde_widgetdir=\\"/tmp/dummy\\"\n");
    printf("xdg_appsdir=\\"/tmp/dummy\\"\n");
    printf("xdg_menudir=\\"/tmp/dummy\\"\n");
    printf("xdg_directorydir=\\"/tmp/dummy\\"\n");
    printf("kde_kcfgdir=\\"/tmp/dummy\\"\n");
    return 0;
    }
EOF

 ac_save_CPPFLAGS=$CPPFLAGS
 CPPFLAGS="$all_includes $CPPFLAGS"
 if AC_TRY_EVAL(ac_compile); then
   AC_MSG_RESULT(yes)
 else
   AC_MSG_ERROR([your system is not able to compile a small TDE application!
Check, if you installed the TDE header files correctly.
For more details about this problem, look at the end of config.log.])
  fi
  CPPFLAGS=$ac_save_CPPFLAGS

  AC_LANG_RESTORE
])

AC_DEFUN([KDE_CHECK_KDEQTADDON],
[
AC_MSG_CHECKING(for kde-qt-addon)
AC_CACHE_VAL(kde_cv_have_kdeqtaddon,
[
 kde_ldflags_safe="$LDFLAGS"
 kde_libs_safe="$LIBS"
 kde_cxxflags_safe="$CXXFLAGS"

 LIBS="-lkde-qt-addon $LIBQT $LIBS"
 CXXFLAGS="$CXXFLAGS -I$prefix/include -I$prefix/include/tde $all_includes"
 LDFLAGS="$LDFLAGS $all_libraries $USER_LDFLAGS"

if test "$kde_qtver" = "3"; then
if $PKG_CONFIG --exists tqt-mt ; then
 AC_TRY_LINK([
   #include <tqdom.h>
 ],
 [
   TQDomDocument doc;
 ],
  kde_cv_have_kdeqtaddon=yes,
  kde_cv_have_kdeqtaddon=no
 )
else
 AC_TRY_LINK([
   #include <qdom.h>
 ],
 [
   QDomDocument doc;
 ],
  kde_cv_have_kdeqtaddon=yes,
  kde_cv_have_kdeqtaddon=no
 )
fi
fi

if test "$kde_qtver" = "4"; then
 AC_TRY_LINK([
   #include <Qt/qdom.h>
 ],
 [
   QDomDocument doc;
 ],
  kde_cv_have_kdeqtaddon=yes,
  kde_cv_have_kdeqtaddon=no
 )

 LDFLAGS=$kde_ldflags_safe
 LIBS=$kde_libs_safe
 CXXFLAGS=$kde_cxxflags_safe
])
fi

AC_MSG_RESULT($kde_cv_have_kdeqtaddon)

if test "$kde_cv_have_kdeqtaddon" = "no"; then
  AC_MSG_ERROR([Can't find libkde-qt-addon. You need to install it first.
It is a separate package (and CVS module) named kde-qt-addon.])
fi
])

AC_DEFUN([KDE_CREATE_LIBS_ALIASES],
[
   AC_REQUIRE([KDE_MISC_TESTS])
   AC_REQUIRE([KDE_CHECK_LIBDL])
   AC_REQUIRE([K_PATH_X])

if test $kde_qtver = 4; then
   case $host in 
               *cygwin*) lib_kded="-ltdeinit_kded" ;;
               *) lib_kded="" ;;
       esac
   AC_SUBST(LIB_KDED, $lib_kded)
   AC_SUBST(LIB_TDECORE, "-ltdecore")
   AC_SUBST(LIB_TDEUI, "-ltdeui")
   AC_SUBST(LIB_TDEIO, "-ltdeio")
   AC_SUBST(LIB_KJS, "-lkjs")
   AC_SUBST(LIB_SMB, "-lsmb")
   AC_SUBST(LIB_KAB, "-lkab")
   AC_SUBST(LIB_TDEABC, "-ltdeabc")
   AC_SUBST(LIB_TDEHTML, "-ltdehtml")
   AC_SUBST(LIB_TDESPELL, "-ltdespell")
   AC_SUBST(LIB_TDEPARTS, "-ltdeparts")
   AC_SUBST(LIB_TDEPRINT, "-ltdeprint")
   AC_SUBST(LIB_TDEUTILS, "-ltdeutils")
   AC_SUBST(LIB_TDEPIM, "-ltdepim")
   AC_SUBST(LIB_TDEIMPROXY, "-ltdeimproxy")
   AC_SUBST(LIB_TDENEWSTUFF, "-ltdenewstuff")
   AC_SUBST(LIB_TDEDNSSD, "-ltdednssd")
   AC_SUBST(LIB_TDEUNITTEST, "-ltdeunittest")
# these are for backward compatibility
   AC_SUBST(LIB_TDESYCOCA, "-ltdeio")
   AC_SUBST(LIB_TDEFILE, "-ltdeio")
elif test $kde_qtver = 3; then
   case $host in 
               *cygwin*) lib_kded="-ltdeinit_kded" ;;
               *) lib_kded="" ;;
       esac
   AC_SUBST(LIB_KDED, $lib_kded)
   AC_SUBST(LIB_TDECORE, "-ltdecore")
   AC_SUBST(LIB_TDEUI, "-ltdeui")
   AC_SUBST(LIB_TDEIO, "-ltdeio")
   AC_SUBST(LIB_KJS, "-lkjs")
   AC_SUBST(LIB_SMB, "-lsmb")
   AC_SUBST(LIB_KAB, "-lkab")
   AC_SUBST(LIB_TDEABC, "-ltdeabc")
   AC_SUBST(LIB_TDEHTML, "-ltdehtml")
   AC_SUBST(LIB_TDESPELL, "-ltdespell")
   AC_SUBST(LIB_TDEPARTS, "-ltdeparts")
   AC_SUBST(LIB_TDEPRINT, "-ltdeprint")
   AC_SUBST(LIB_TDEUTILS, "-ltdeutils")
   AC_SUBST(LIB_TDEPIM, "-ltdepim")
   AC_SUBST(LIB_TDEIMPROXY, "-ltdeimproxy")
   AC_SUBST(LIB_TDENEWSTUFF, "-ltdenewstuff")
   AC_SUBST(LIB_TDEDNSSD, "-ltdednssd")
   AC_SUBST(LIB_TDEUNITTEST, "-ltdeunittest")
# these are for backward compatibility
   AC_SUBST(LIB_TDESYCOCA, "-ltdeio")
   AC_SUBST(LIB_TDEFILE, "-ltdeio")
elif test $kde_qtver = 2; then
   AC_SUBST(LIB_TDECORE, "-ltdecore")
   AC_SUBST(LIB_TDEUI, "-ltdeui")
   AC_SUBST(LIB_TDEIO, "-ltdeio")
   AC_SUBST(LIB_TDESYCOCA, "-ltdesycoca")
   AC_SUBST(LIB_SMB, "-lsmb")
   AC_SUBST(LIB_TDEFILE, "-ltdefile")
   AC_SUBST(LIB_KAB, "-lkab")
   AC_SUBST(LIB_TDEHTML, "-ltdehtml")
   AC_SUBST(LIB_TDESPELL, "-ltdespell")
   AC_SUBST(LIB_TDEPARTS, "-ltdeparts")
   AC_SUBST(LIB_TDEPRINT, "-ltdeprint")
else
   AC_SUBST(LIB_TDECORE, "-ltdecore -lXext $(LIB_QT)")
   AC_SUBST(LIB_TDEUI, "-ltdeui $(LIB_TDECORE)")
   AC_SUBST(LIB_KFM, "-lkfm $(LIB_TDECORE)")
   AC_SUBST(LIB_TDEFILE, "-ltdefile $(LIB_KFM) $(LIB_TDEUI)")
   AC_SUBST(LIB_KAB, "-lkab $(LIB_KIMGIO) $(LIB_TDECORE)")
fi
])

AC_DEFUN([AC_PATH_KDE],
[
  AC_BASE_PATH_KDE
  AC_ARG_ENABLE(path-check,AC_HELP_STRING([--disable-path-check],[don't try to find out, where to install]),
  [
  if test "$enableval" = "no";
    then ac_use_path_checking="default"
    else ac_use_path_checking=""
  fi
  ],
  [
  if test "$kde_qtver" = 1;
    then ac_use_path_checking=""
    else ac_use_path_checking="default"
  fi
  ]
  )

  AC_CREATE_KFSSTND($ac_use_path_checking)

  AC_SUBST_KFSSTND
  KDE_CREATE_LIBS_ALIASES
])

dnl KDE_CHECK_FUNC_EXT(<func>, [headers], [sample-use], [C prototype], [autoheader define], [call if found])
AC_DEFUN([KDE_CHECK_FUNC_EXT],
[
AC_MSG_CHECKING(for $1)
AC_CACHE_VAL(kde_cv_func_$1,
[
AC_LANG_SAVE
AC_LANG_CPLUSPLUS
save_CXXFLAGS="$CXXFLAGS"
kde_safe_LIBS="$LIBS"
LIBS="$LIBS $X_EXTRA_LIBS"
if test "$GXX" = "yes"; then
CXXFLAGS="$CXXFLAGS -pedantic-errors"
fi
if test -z "$qt_includes"; then
  CXXFLAGS="$CXXFLAGS"
else
  CXXFLAGS="$CXXFLAGS -I$qt_includes"
fi
AC_TRY_COMPILE([
$2
],
[
$3
],
kde_cv_func_$1=yes,
kde_cv_func_$1=no)
CXXFLAGS="$save_CXXFLAGS"
LIBS="$kde_safe_LIBS"
AC_LANG_RESTORE
])

AC_MSG_RESULT($kde_cv_func_$1)

AC_MSG_CHECKING([if $1 needs custom prototype])
AC_CACHE_VAL(kde_cv_proto_$1,
[
if test "x$kde_cv_func_$1" = xyes; then
  kde_cv_proto_$1=no
else
  case "$1" in
	setenv|unsetenv|usleep|random|srandom|seteuid|mkstemps|mkstemp|revoke|vsnprintf|strlcpy|strlcat)
		kde_cv_proto_$1="yes - in libtdefakes"
		;;
	*)
		kde_cv_proto_$1=unknown
		;;
  esac
fi

if test "x$kde_cv_proto_$1" = xunknown; then

AC_LANG_SAVE
AC_LANG_CPLUSPLUS
  kde_safe_libs=$LIBS
  LIBS="$LIBS $X_EXTRA_LIBS"
  AC_TRY_LINK([
$2

extern "C" $4;
],
[
$3
],
[ kde_cv_func_$1=yes
  kde_cv_proto_$1=yes ],
  [kde_cv_proto_$1="$1 unavailable"]
)
LIBS=$kde_safe_libs
AC_LANG_RESTORE
fi
])
AC_MSG_RESULT($kde_cv_proto_$1)

if test "x$kde_cv_func_$1" = xyes; then
  AC_DEFINE(HAVE_$5, 1, [Define if you have $1])
  $6
fi
if test "x$kde_cv_proto_$1" = xno; then
  AC_DEFINE(HAVE_$5_PROTO, 1,
  [Define if you have the $1 prototype])
fi

AH_VERBATIM([_HAVE_$5_PROTO],
[
#if !defined(HAVE_$5_PROTO)
#ifdef __cplusplus
extern "C" {
#endif
$4;
#ifdef __cplusplus
}
#endif
#endif
])
])

AC_DEFUN([AC_CHECK_SETENV],
[
	KDE_CHECK_FUNC_EXT(setenv, [
#include <stdlib.h>
], 
		[setenv("VAR", "VALUE", 1);],
	        [int setenv (const char *, const char *, int)],
		[SETENV])
])

AC_DEFUN([AC_CHECK_UNSETENV],
[
	KDE_CHECK_FUNC_EXT(unsetenv, [
#include <stdlib.h>
], 
		[unsetenv("VAR");],
	        [void unsetenv (const char *)],
		[UNSETENV])
])

AC_DEFUN([AC_CHECK_GETDOMAINNAME],
[
	KDE_CHECK_FUNC_EXT(getdomainname, [
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
], 
		[
char buffer[200];
getdomainname(buffer, 200);
], 	
	        [#include <sys/types.h>
		int getdomainname (char *, size_t)],
		[GETDOMAINNAME])
])

AC_DEFUN([AC_CHECK_GETHOSTNAME],
[
	KDE_CHECK_FUNC_EXT(gethostname, [
#include <stdlib.h>
#include <unistd.h>
], 
		[
char buffer[200];
gethostname(buffer, 200);
], 	
	        [int gethostname (char *, unsigned int)],
		[GETHOSTNAME])
])

AC_DEFUN([AC_CHECK_USLEEP],
[
	KDE_CHECK_FUNC_EXT(usleep, [
#include <unistd.h>
], 
		[
usleep(200);
], 	
	        [int usleep (unsigned int)],
		[USLEEP])
])


AC_DEFUN([AC_CHECK_RANDOM],
[
	KDE_CHECK_FUNC_EXT(random, [
#include <stdlib.h>
], 
		[
random();
], 	
	        [long int random(void)],
		[RANDOM])

	KDE_CHECK_FUNC_EXT(srandom, [
#include <stdlib.h>
], 
		[
srandom(27);
], 	
	        [void srandom(unsigned int)],
		[SRANDOM])

])

AC_DEFUN([AC_CHECK_INITGROUPS],
[
	KDE_CHECK_FUNC_EXT(initgroups, [
#include <sys/types.h>
#include <unistd.h>
#include <grp.h>
],
	[
char buffer[200];
initgroups(buffer, 27);
],
	[int initgroups(const char *, gid_t)],
	[INITGROUPS])
])

AC_DEFUN([AC_CHECK_MKSTEMPS],
[
	KDE_CHECK_FUNC_EXT(mkstemps, [
#include <stdlib.h>
#include <unistd.h>
],
	[
mkstemps("/tmp/aaaXXXXXX", 6);
],
	[int mkstemps(char *, int)],
	[MKSTEMPS])
])

AC_DEFUN([AC_CHECK_MKSTEMP],
[
	KDE_CHECK_FUNC_EXT(mkstemp, [
#include <stdlib.h>
#include <unistd.h>
],
	[
mkstemp("/tmp/aaaXXXXXX");
],
	[int mkstemp(char *)],
	[MKSTEMP])
])

AC_DEFUN([AC_CHECK_MKDTEMP],
[
	KDE_CHECK_FUNC_EXT(mkdtemp, [
#include <stdlib.h>
#include <unistd.h>
],
	[
mkdtemp("/tmp/aaaXXXXXX");
],
	[char *mkdtemp(char *)],
	[MKDTEMP])
])


AC_DEFUN([AC_CHECK_RES_INIT],
[
  AC_MSG_CHECKING([if res_init needs -lresolv])
  kde_libs_safe="$LIBS"
  LIBS="$LIBS $X_EXTRA_LIBS -lresolv"
  AC_TRY_LINK(
    [
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/nameser.h>
#include <resolv.h>
    ],
    [
      res_init(); 
    ],
    [
      LIBRESOLV="-lresolv"
      AC_MSG_RESULT(yes)
      AC_DEFINE(HAVE_RES_INIT, 1, [Define if you have the res_init function])
    ],
    [ AC_MSG_RESULT(no) ]
  )
  LIBS=$kde_libs_safe
  AC_SUBST(LIBRESOLV)

  KDE_CHECK_FUNC_EXT(res_init,
    [
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/nameser.h>
#include <resolv.h>
    ],
    [res_init()],
    [int res_init(void)],
    [RES_INIT])
])

AC_DEFUN([AC_CHECK_STRLCPY],
[
	KDE_CHECK_FUNC_EXT(strlcpy, [
#include <string.h>
],
[ char buf[20];
  strlcpy(buf, "TDE function test", sizeof(buf));
],
 	[unsigned long strlcpy(char*, const char*, unsigned long)],
	[STRLCPY])
])

AC_DEFUN([AC_CHECK_STRLCAT],
[
	KDE_CHECK_FUNC_EXT(strlcat, [
#include <string.h>
],
[ char buf[20];
  buf[0]='\0';
  strlcat(buf, "TDE function test", sizeof(buf));
],
 	[unsigned long strlcat(char*, const char*, unsigned long)],
	[STRLCAT])
])

AC_DEFUN([AC_CHECK_RES_QUERY],
[
	KDE_CHECK_FUNC_EXT(res_query, [
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/nameser.h>
#include <resolv.h>
#include <netdb.h>
],
[
res_query(NULL, 0, 0, NULL, 0);
],
	[int res_query(const char *, int, int, unsigned char *, int)],
	[RES_QUERY])
])

AC_DEFUN([AC_CHECK_DN_SKIPNAME],
[
	KDE_CHECK_FUNC_EXT(dn_skipname, [
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/nameser.h>
#include <resolv.h>
],
[
dn_skipname (NULL, NULL);
],
	[int dn_skipname (unsigned char *, unsigned char *)],
	[DN_SKIPNAME])
])


AC_DEFUN([AC_FIND_GIF],
   [AC_MSG_CHECKING([for giflib])
AC_CACHE_VAL(ac_cv_lib_gif,
[ac_save_LIBS="$LIBS"
if test "x$kde_use_qt_emb" != "xyes" && test "x$kde_use_qt_mac" != "xyes"; then
LIBS="$all_libraries -lgif -lX11 $LIBSOCKET"
else
LIBS="$all_libraries -lgif"
fi
AC_TRY_LINK(dnl
[
#ifdef __cplusplus
extern "C" {
#endif
int GifLastError(void);
#ifdef __cplusplus
}
#endif
/* We use char because int might match the return type of a gcc2
    builtin and then its argument prototype would still apply.  */
],
            [return GifLastError();],
            eval "ac_cv_lib_gif=yes",
            eval "ac_cv_lib_gif=no")
LIBS="$ac_save_LIBS"
])dnl
if eval "test \"`echo $ac_cv_lib_gif`\" = yes"; then
  AC_MSG_RESULT(yes)
  AC_DEFINE_UNQUOTED(HAVE_LIBGIF, 1, [Define if you have libgif])
else
  AC_MSG_ERROR(You need giflib30. Please install the tdesupport package)
fi
])

AC_DEFUN([KDE_FIND_JPEG_HELPER],
[
AC_MSG_CHECKING([for libjpeg$2])
AC_CACHE_VAL(ac_cv_lib_jpeg_$1,
[
ac_save_LIBS="$LIBS"
LIBS="$all_libraries $USER_LDFLAGS -ljpeg$2 -lm"
ac_save_CFLAGS="$CFLAGS"
CFLAGS="$CFLAGS $all_includes $USER_INCLUDES"
AC_TRY_LINK(
[
#ifdef __cplusplus
extern "C" {
#endif
void jpeg_CreateDecompress();
#ifdef __cplusplus
}
#endif
],
[jpeg_CreateDecompress();],
            eval "ac_cv_lib_jpeg_$1=-ljpeg$2",
            eval "ac_cv_lib_jpeg_$1=no")
LIBS="$ac_save_LIBS"
CFLAGS="$ac_save_CFLAGS"
])

if eval "test ! \"`echo $ac_cv_lib_jpeg_$1`\" = no"; then
  LIBJPEG="$ac_cv_lib_jpeg_$1"
  AC_MSG_RESULT($ac_cv_lib_jpeg_$1)
else
  AC_MSG_RESULT(no)
  $3
fi

])

AC_DEFUN([AC_FIND_JPEG],
[
dnl first look for libraries
KDE_FIND_JPEG_HELPER(6b, 6b,
   KDE_FIND_JPEG_HELPER(normal, [],
    [
       LIBJPEG=
    ]
   )
)

dnl then search the headers (can't use simply AC_TRY_xxx, as jpeglib.h
dnl requires system dependent includes loaded before it)
jpeg_incdirs="$includedir /usr/include /usr/local/include $kde_extra_includes"
AC_FIND_FILE(jpeglib.h, $jpeg_incdirs, jpeg_incdir)
test "x$jpeg_incdir" = xNO && jpeg_incdir=

dnl if headers _and_ libraries are missing, this is no error, and we
dnl continue with a warning (the user will get no jpeg support in tdehtml)
dnl if only one is missing, it means a configuration error, but we still
dnl only warn
if test -n "$jpeg_incdir" && test -n "$LIBJPEG" ; then
  AC_DEFINE_UNQUOTED(HAVE_LIBJPEG, 1, [Define if you have libjpeg])
else
  if test -n "$jpeg_incdir" || test -n "$LIBJPEG" ; then
    AC_MSG_WARN([
There is an installation error in jpeg support. You seem to have only one
of either the headers _or_ the libraries installed. You may need to either
provide correct --with-extra-... options, or the development package of
libjpeg6b. You can get a source package of libjpeg from http://www.ijg.org/
Disabling JPEG support.
])
  else
    AC_MSG_WARN([libjpeg not found. disable JPEG support.])
  fi
  jpeg_incdir=
  LIBJPEG=
fi

AC_SUBST(LIBJPEG)
AH_VERBATIM(_AC_CHECK_JPEG,
[/*
 * jpeg.h needs HAVE_BOOLEAN, when the system uses boolean in system
 * headers and I'm too lazy to write a configure test as long as only
 * unixware is related
 */
#ifdef _UNIXWARE
#define HAVE_BOOLEAN
#endif
])
])

AC_DEFUN([KDE_CHECK_TQT],
[
AC_MSG_CHECKING([if TQt is available])
AC_CACHE_VAL(kde_cv_tqt,
[
AC_LANG_SAVE
AC_LANG_CPLUSPLUS
ac_save_LIBS="$LIBS"
LIBS="$all_libraries $USER_LDFLAGS $LIBQT -ltqt"
ac_save_CXXFLAGS="$CXXFLAGS"
CXXFLAGS="$CXXFLAGS $all_includes $USER_INCLUDES"
if test "$kde_qtver" -gt "2"; then
AC_TRY_LINK(
[#include <tqtimer.h>],
            [
            TQTimer *test_timer(0);
            test_timer->start(1000);],
            eval "kde_cv_tqt=no",
            eval "kde_cv_tqt=yes")
fi
LIBS="$ac_save_LIBS"
CXXFLAGS="$ac_save_CXXFLAGS"
AC_LANG_RESTORE
])

if eval "test ! \"`echo $kde_cv_tqt`\" = no"; then
  AC_MSG_RESULT(no)
dnl  AC_MSG_ERROR([You are attempting to compile Trinity without the Trinity Qt Interface installed.  Please install libtqtinterface-dev and try again!])
  AC_MSG_WARN([You are attempting to compile Trinity without the Trinity Qt Interface installed.  Please install libtqtinterface-dev and try again!])
  TQTMOC="\$PATH=\$PATH:\$(srcdir)/ tmoc"
  LIBTQT_LDFLAGS="-ltqt"
  AC_SUBST(LIBTQT_LDFLAGS)
  qtlib="$qtlib $LIBTQT_LDFLAGS"
else
  AC_MSG_RESULT(yes)
  LIBTQT_LDFLAGS="-ltqt"
  AC_SUBST(LIBTQT_LDFLAGS)
dnl  all_libraries="$all_libraries $LIBTQT_LDFLAGS"
  QT_LDFLAGS="$QT_LDFLAGS $LIBTQT_LDFLAGS"
  AC_SUBST(QT_LDFLAGS)
  qtlib="$qtlib $LIBTQT_LDFLAGS"
  LIBTQT_CXXFLAGS="-include tqt.h"
  all_includes="$all_includes $LIBTQT_CXXFLAGS"
  QT_INCLUDES="$QT_INCLUDES $LIBTQT_CXXFLAGS"

  KDE_FIND_PATH(tmoc, TQTMOC, [$qt_bindirs], [KDE_TQTMOC_ERROR_MESSAGE])
  AC_SUBST(TQTMOC)

  KDE_FIND_PATH(dcopidl, TQTDCOPIDL, [$kde_default_bindirs], [KDE_MISSING_PROG_ERROR(dcopidl)])
  KDE_FIND_PATH(dcopidl2cpp, TQTDCOPIDL2CPP, [$kde_default_bindirs], [KDE_MISSING_PROG_ERROR(dcopidl2cpp)])
  if test "$build_arts" '!=' "no"; then
    KDE_FIND_PATH(mcopidl, TQTMCOPIDL, [$kde_default_bindirs], [KDE_MISSING_ARTS_ERROR(mcopidl)])
  fi
  KDE_FIND_PATH(dcopidlng, TQTDCOPIDLNG, [$kde_default_bindirs], [KDE_MISSING_PROG_ERROR(dcopidlng)])

  AC_SUBST(TQTDCOPIDL)
  AC_SUBST(TQTMCOPIDL)
  AC_SUBST(TQTDCOPIDLNG)
  AC_SUBST(TQTDCOPIDL2CPP)
fi

])

AC_DEFUN([KDE_CHECK_QT_JPEG],
[
if test -n "$LIBJPEG"; then
AC_MSG_CHECKING([if Qt needs $LIBJPEG])
AC_CACHE_VAL(kde_cv_qt_jpeg,
[
AC_LANG_SAVE
AC_LANG_CPLUSPLUS
ac_save_LIBS="$LIBS"
LIBS="$all_libraries $USER_LDFLAGS $LIBQT"
LIBS=`echo $LIBS | sed "s/$LIBJPEG//"`
ac_save_CXXFLAGS="$CXXFLAGS"
CXXFLAGS="$CXXFLAGS $all_includes $USER_INCLUDES"
if test "$kde_qtver" = "4"; then
AC_TRY_LINK(
[#include <Qt/qapplication.h>],
            [
            int argc;
            char** argv;
            QApplication app(argc, argv);],
            eval "kde_cv_qt_jpeg=no",
            eval "kde_cv_qt_jpeg=yes")
fi
if test "$kde_qtver" = "3"; then
if $PKG_CONFIG --exists tqt-mt ; then
AC_TRY_LINK(
[#include <tqapplication.h>],
            [
            int argc;
            char** argv;
            TQApplication app(argc, argv);],
            eval "kde_cv_qt_jpeg=no",
            eval "kde_cv_qt_jpeg=yes")
else
AC_TRY_LINK(
[#include <qapplication.h>],
            [
            int argc;
            char** argv;
            QApplication app(argc, argv);],
            eval "kde_cv_qt_jpeg=no",
            eval "kde_cv_qt_jpeg=yes")
fi
fi
LIBS="$ac_save_LIBS"
CXXFLAGS="$ac_save_CXXFLAGS"
AC_LANG_RESTORE
fi
])

if eval "test ! \"`echo $kde_cv_qt_jpeg`\" = no"; then
  AC_MSG_RESULT(yes)
  LIBJPEG_QT='$(LIBJPEG)'
else
  AC_MSG_RESULT(no)
  LIBJPEG_QT=
fi

])

AC_DEFUN([AC_FIND_ZLIB],
[
AC_REQUIRE([KDE_CHECK_EXTRA_LIBS])
AC_MSG_CHECKING([for libz])
AC_CACHE_VAL(ac_cv_lib_z,
[
kde_save_LIBS="$LIBS"
LIBS="$all_libraries $USER_LDFLAGS -lz $LIBSOCKET"
kde_save_CFLAGS="$CFLAGS"
CFLAGS="$CFLAGS $all_includes $USER_INCLUDES"
AC_TRY_LINK(dnl
[
#include<zlib.h>
#include<string.h>
],
[
  char buf[42];
  gzFile f = (gzFile) 0;
  /* this would segfault.. but we only link, don't run */
  (void) gzgets(f, buf, sizeof(buf));

  return (strcmp(zlibVersion(), ZLIB_VERSION) == 0);
],
            eval "ac_cv_lib_z='-lz'",
            eval "ac_cv_lib_z=no")
LIBS="$kde_save_LIBS"
CFLAGS="$kde_save_CFLAGS"
])dnl
if test ! "$ac_cv_lib_z" = no; then
  AC_DEFINE_UNQUOTED(HAVE_LIBZ, 1, [Define if you have libz])
  LIBZ="$ac_cv_lib_z"
  AC_MSG_RESULT($ac_cv_lib_z)
else
  AC_MSG_ERROR(not found. 
          Possibly configure picks up an outdated version
          installed by XFree86. Remove it from your system.

          Check your installation and look into config.log)
  LIBZ=""
fi
AC_SUBST(LIBZ)
])

AC_DEFUN([KDE_TRY_TIFFLIB],
[
AC_MSG_CHECKING([for libtiff $1])

AC_CACHE_VAL(kde_cv_libtiff_$1,
[
AC_LANG_SAVE
AC_LANG_CPLUSPLUS
kde_save_LIBS="$LIBS"
if test "x$kde_use_qt_emb" != "xyes" && test "x$kde_use_qt_mac" != "xyes"; then
LIBS="$all_libraries $USER_LDFLAGS -l$1 $LIBJPEG $LIBZ -lX11 $LIBSOCKET -lm"
else
LIBS="$all_libraries $USER_LDFLAGS -l$1 $LIBJPEG $LIBZ -lm"
fi
kde_save_CXXFLAGS="$CXXFLAGS"
kde_save_LDFLAGS="$LDFLAGS"
CXXFLAGS="$CXXFLAGS $all_includes $USER_INCLUDES"
LDFLAGS="$LDFLAGS -ltqt"

AC_TRY_LINK(dnl
[
#include<tiffio.h>
],
    [return (TIFFOpen( "", "r") == 0); ],
[
    kde_cv_libtiff_$1="-l$1 $LIBJPEG $LIBZ"
], [
    kde_cv_libtiff_$1=no
])

LIBS="$kde_save_LIBS"
CXXFLAGS="$kde_save_CXXFLAGS"
LDFLAGS="$kde_save_LDFLAGS"
AC_LANG_RESTORE
])

if test "$kde_cv_libtiff_$1" = "no"; then
    AC_MSG_RESULT(no)
    LIBTIFF=""
    $3
else
    LIBTIFF="$kde_cv_libtiff_$1"
    AC_MSG_RESULT(yes)
    AC_DEFINE_UNQUOTED(HAVE_LIBTIFF, 1, [Define if you have libtiff])
    $2
fi

])

AC_DEFUN([AC_FIND_TIFF],
[
AC_REQUIRE([K_PATH_X])
AC_REQUIRE([AC_FIND_ZLIB])
AC_REQUIRE([AC_FIND_JPEG])
AC_REQUIRE([KDE_CHECK_EXTRA_LIBS])

KDE_TRY_TIFFLIB(tiff, [],
   KDE_TRY_TIFFLIB(tiff34))

AC_SUBST(LIBTIFF)
])

AC_DEFUN([KDE_FIND_LIBEXR],
[
AC_REQUIRE([KDE_CHECK_EXTRA_LIBS])
AC_REQUIRE([AC_FIND_ZLIB])
AC_CACHE_VAL(ac_cv_libexr,
[
  if test -z "$PKG_CONFIG"; then
    AC_PATH_PROG(PKG_CONFIG, pkg-config, no)
  fi

  AC_MSG_CHECKING([for OpenEXR libraries])

  if test "$PKG_CONFIG" = "no" ; then
     AC_MSG_RESULT(no)
     echo "*** The pkg-config script could not be found. Make sure it is"
     echo "*** in your path, or set the PKG_CONFIG environment variable"
     echo "*** to the full path to pkg-config."
     echo "*** Or see http://www.freedesktop.org/software/pkgconfig to get pkg-config."
  else
     if ! $PKG_CONFIG --exists OpenEXR ; then
        AC_MSG_RESULT(no)
        EXRSTATUS=no
     else
        if ! $PKG_CONFIG --atleast-version="1.1.1" OpenEXR ; then
           AC_MSG_RESULT(no)
           EXRSTATUS=old
        else
           kde_save_LIBS="$LIBS"
           LIBS="$LIBS $all_libraries $USER_LDFLAGS `pkg-config --libs OpenEXR` $LIBZ"
           AC_LANG_SAVE
           AC_LANG_CPLUSPLUS
           kde_save_CXXFLAGS="$CXXFLAGS"
           kde_save_LDFLAGS="$LDFLAGS"
           LDFLAGS="$LFLAGS -ltqt"
           EXR_FLAGS=`$PKG_CONFIG --cflags OpenEXR`
           CXXFLAGS="$CXXFLAGS $all_includes $USER_INCLUDES $EXR_FLAGS"

           AC_TRY_LINK(dnl
               [
               #include <ImfRgbaFile.h>
               ],
               [
               using namespace Imf;
               RgbaInputFile file ("dummy");
               return 0;
               ],
               eval "ac_cv_libexr='`pkg-config --libs OpenEXR`'",
               eval "ac_cv_libexr=no"
           )
           LIBS="$kde_save_LIBS"
           CXXFLAGS="$kde_save_CXXFLAGS"
           LDFLAGS="$kde_save_LDFLAGS"
           AC_LANG_RESTORE
           ])dnl
           if eval "test ! \"`echo $ac_cv_libexr`\" = no"; then
               AC_DEFINE_UNQUOTED(HAVE_EXR, 1, [Define if you have OpenEXR])
               LIB_EXR="$ac_cv_libexr"
               AC_MSG_RESULT($ac_cv_libexr)
           else
               AC_MSG_RESULT(no)
               LIB_EXR=""
           fi
        fi
     fi
  fi
  AC_SUBST(LIB_EXR)
  AC_SUBST(EXR_FLAGS)
])



AC_DEFUN([AC_FIND_PNG],
[
AC_REQUIRE([KDE_CHECK_EXTRA_LIBS])
AC_REQUIRE([AC_FIND_ZLIB])
AC_MSG_CHECKING([for libpng])
AC_CACHE_VAL(ac_cv_lib_png,
[
kde_save_LIBS="$LIBS"
if test "x$kde_use_qt_emb" != "xyes" && test "x$kde_use_qt_mac" != "xyes"; then
LIBS="$LIBS $all_libraries $USER_LDFLAGS -lpng $LIBZ -lm -lX11 $LIBSOCKET"
else
LIBS="$LIBS $all_libraries $USER_LDFLAGS -lpng $LIBZ -lm"
fi
kde_save_CFLAGS="$CFLAGS"
CFLAGS="$CFLAGS $all_includes $USER_INCLUDES"

AC_TRY_LINK(dnl
    [
    #include<png.h>
    ],
    [
    png_structp png_ptr = png_create_read_struct(  /* image ptr */
		PNG_LIBPNG_VER_STRING, 0, 0, 0 );
    return( png_ptr != 0 );
    ],
    eval "ac_cv_lib_png='-lpng $LIBZ -lm'",
    eval "ac_cv_lib_png=no"
)
LIBS="$kde_save_LIBS"
CFLAGS="$kde_save_CFLAGS"
])dnl
if eval "test ! \"`echo $ac_cv_lib_png`\" = no"; then
  AC_DEFINE_UNQUOTED(HAVE_LIBPNG, 1, [Define if you have libpng])
  LIBPNG="$ac_cv_lib_png"
  AC_SUBST(LIBPNG)
  AC_MSG_RESULT($ac_cv_lib_png)
else
  AC_MSG_RESULT(no)
  LIBPNG=""
  AC_SUBST(LIBPNG)
fi
])


AC_DEFUN([AC_FIND_JASPER],
[
AC_REQUIRE([KDE_CHECK_EXTRA_LIBS])
AC_REQUIRE([AC_FIND_JPEG])
AC_MSG_CHECKING([for jasper])
AC_CACHE_VAL(ac_cv_jasper,
[
kde_save_LIBS="$LIBS"
LIBS="$LIBS $all_libraries $USER_LDFLAGS -ljasper $LIBJPEG -lm"
kde_save_CFLAGS="$CFLAGS"
CFLAGS="$CFLAGS $all_includes $USER_INCLUDES"

AC_TRY_LINK(dnl
    [
    #include<jasper/jasper.h>
    ],
    [
    return( jas_init() );
    ],
    eval "ac_cv_jasper='-ljasper $LIBJPEG -lm'",
    eval "ac_cv_jasper=no"
)
LIBS="$kde_save_LIBS"
CFLAGS="$kde_save_CFLAGS"
])dnl
if eval "test ! \"`echo $ac_cv_jasper`\" = no"; then
  AC_DEFINE_UNQUOTED(HAVE_JASPER, 1, [Define if you have jasper])
  LIB_JASPER="$ac_cv_jasper"
  AC_MSG_RESULT($ac_cv_jasper)
else
  AC_MSG_RESULT(no)
  LIB_JASPER=""
fi
AC_SUBST(LIB_JASPER)
])

AC_DEFUN([AC_CHECK_BOOL],
[
  AC_DEFINE_UNQUOTED(HAVE_BOOL, 1, [You _must_ have bool])
])

AC_DEFUN([AC_CHECK_GNU_EXTENSIONS],
[
AC_MSG_CHECKING(if you need GNU extensions)
AC_CACHE_VAL(ac_cv_gnu_extensions,
[
cat > conftest.c << EOF
#include <features.h>

#ifdef __GNU_LIBRARY__
yes
#endif
EOF

if (eval "$ac_cpp conftest.c") 2>&5 |
  egrep "yes" >/dev/null 2>&1; then
  rm -rf conftest*
  ac_cv_gnu_extensions=yes
else
  ac_cv_gnu_extensions=no
fi
])

AC_MSG_RESULT($ac_cv_gnu_extensions)
if test "$ac_cv_gnu_extensions" = "yes"; then
  AC_DEFINE_UNQUOTED(_GNU_SOURCE, 1, [Define if you need to use the GNU extensions])
fi
])

AC_DEFUN([KDE_CHECK_COMPILER_FLAG],
[
AC_MSG_CHECKING([whether $CXX supports -$1])
kde_cache=`echo $1 | sed 'y% .=/+-,%____p__%'`
AC_CACHE_VAL(kde_cv_prog_cxx_$kde_cache,
[
  AC_LANG_SAVE
  AC_LANG_CPLUSPLUS
  save_CXXFLAGS="$CXXFLAGS"
  CXXFLAGS="$CXXFLAGS -$1"
  AC_TRY_LINK([],[ return 0; ], [eval "kde_cv_prog_cxx_$kde_cache=yes"], [])
  CXXFLAGS="$save_CXXFLAGS"
  AC_LANG_RESTORE
])
if eval "test \"`echo '$kde_cv_prog_cxx_'$kde_cache`\" = yes"; then
 AC_MSG_RESULT(yes)
 :
 $2
else
 AC_MSG_RESULT(no)
 :
 $3
fi
])

AC_DEFUN([KDE_CHECK_C_COMPILER_FLAG],
[
AC_MSG_CHECKING([whether $CC supports -$1])
kde_cache=`echo $1 | sed 'y% .=/+-,%____p__%'`
AC_CACHE_VAL(kde_cv_prog_cc_$kde_cache,
[
  AC_LANG_SAVE
  AC_LANG_C
  save_CFLAGS="$CFLAGS"
  CFLAGS="$CFLAGS -$1"
  AC_TRY_LINK([],[ return 0; ], [eval "kde_cv_prog_cc_$kde_cache=yes"], [])
  CFLAGS="$save_CFLAGS"
  AC_LANG_RESTORE
])
if eval "test \"`echo '$kde_cv_prog_cc_'$kde_cache`\" = yes"; then
 AC_MSG_RESULT(yes)
 :
 $2
else
 AC_MSG_RESULT(no)
 :
 $3
fi
])


dnl AC_REMOVE_FORBIDDEN removes forbidden arguments from variables
dnl use: AC_REMOVE_FORBIDDEN(CC, [-forbid -bad-option whatever])
dnl it's all white-space separated
AC_DEFUN([AC_REMOVE_FORBIDDEN],
[ __val=$$1
  __forbid=" $2 "
  if test -n "$__val"; then
    __new=""
    ac_save_IFS=$IFS
    IFS=" 	"
    for i in $__val; do
      case "$__forbid" in
        *" $i "*) AC_MSG_WARN([found forbidden $i in $1, removing it]) ;;
	*) # Careful to not add spaces, where there were none, because otherwise
	   # libtool gets confused, if we change e.g. CXX
	   if test -z "$__new" ; then __new=$i ; else __new="$__new $i" ; fi ;;
      esac
    done
    IFS=$ac_save_IFS
    $1=$__new
  fi
])


AC_DEFUN([KDE_CHECK_FOR_BAD_COMPILER],
[
  AC_MSG_CHECKING([whether $CC is blacklisted])

  dnl In theory we have tu run this test against $CC and $CXX
  dnl in C and in C++ mode, because its perfectly legal for
  dnl the user to mix compiler versions, since C has a defined
  dnl ABI. 
  dnl 
  dnl For now, we assume the user is not on crack.

  AC_TRY_COMPILE([
#ifdef __GNUC__
#if __GNUC__ == 4 && __GNUC_MINOR__ == 0 && __GNUC_PATCHLEVEL__ == 0
choke me
#endif
#endif
], ,
  kde_bad_compiler=no, 
  kde_bad_compiler=yes
)

  AC_MSG_RESULT($kde_bad_compiler)

if test "$kde_bad_compiler" = "yes"; then
  AC_MSG_ERROR([

This particular compiler version is blacklisted because it
is known to miscompile KDE. Please use a newer version, or
if that is not yet available, choose an older version. 

Please do not report a bug or bother us reporting this
configure error. We know about it, and we introduced
it by intention to avoid untraceable bugs or crashes in KDE.

])
fi

])


AC_DEFUN([KDE_CHECK_FOR_OPT_NOINLINE_MATCH],
[
  AC_CACHE_CHECK([whether system headers can cope with -O2 -fno-inline],
    kde_cv_opt_noinline_match,
  [
  kde_cv_opt_noinline_match=irrelevant
  dnl if we don't use both -O2 and -fno-inline, this check is moot
  if echo "$CFLAGS" | grep -e -O2 >/dev/null 2>/dev/null \
     && echo "$CFLAGS" | grep -e -fno-inline >/dev/null 2>/dev/null ; then

    ac_cflags_save="$CFLAGS"
    CFLAGS="$CFLAGS -D_USE_GNU"

    AC_TRY_LINK([
  #include <string.h>
], [  const char *pt, *et;
  et = __extension__      ({ char __a0, __a1, __a2;       (__builtin_constant_p (  ";,"  ) && ((size_t)(const void *)((   ";,"   )+ 1) - (size_t)(const void *)(   ";,"   ) == 1)        ? ((__a0 =((__const char  *) (  ";,"  ))[0], __a0 == '\0')     ? ((void) (  pt ),((void *)0) )        : ((__a1 = ((__const char *) (  ";,"  ))[1], __a1== '\0')      ? (__extension__ (__builtin_constant_p (  __a0 ) && ( __a0 ) == '\0'   ? (char *) __rawmemchr (   pt  ,   __a0)       : strchr(   pt  ,   __a0 )))   : ((__a2 = ((__const char *) (  ";,"  ))[2], __a2 == '\0')      ? __strpbrk_c2 (  pt , __a0, __a1)      :(((__const char *) (  ";,"  ))[3] == '\0'     ? __strpbrk_c3 (  pt ,__a0, __a1, __a2): strpbrk (  pt ,   ";,"  ))))) : strpbrk (  pt ,  ";,"  )); }) ;
],
    kde_cv_opt_noinline_match=yes,
    kde_cv_opt_noinline_match=no
    )

    CFLAGS="$ac_cflags_save"
  fi
  ])
])


dnl AC_VALIDIFY_CXXFLAGS checks for forbidden flags the user may have given
AC_DEFUN([AC_VALIDIFY_CXXFLAGS],
[dnl
if test "x$kde_use_qt_emb" != "xyes"; then
 AC_REMOVE_FORBIDDEN(CXX, [-fno-rtti -rpath])
 AC_REMOVE_FORBIDDEN(CXXFLAGS, [-fno-rtti -rpath])
else
 AC_REMOVE_FORBIDDEN(CXX, [-rpath])
 AC_REMOVE_FORBIDDEN(CXXFLAGS, [-rpath])
fi
])

AC_DEFUN([AC_CHECK_COMPILERS],
[
  AC_ARG_ENABLE(debug,
	        AC_HELP_STRING([--enable-debug=ARG],[enables debug symbols (yes|no|full) [default=no]]),
  [
    case $enableval in
      yes)
        kde_use_debug_code="yes"
        kde_use_debug_define=no
        ;;
      full)
        kde_use_debug_code="full"
        kde_use_debug_define=no
        ;;
      *)
        kde_use_debug_code="no"
        kde_use_debug_define=yes
        ;;
    esac
  ], 
    [kde_use_debug_code="no"
      kde_use_debug_define=no
  ])

  dnl Just for configure --help
  AC_ARG_ENABLE(dummyoption,
	        AC_HELP_STRING([--disable-debug],
	  		       [disables debug output and debug symbols [default=no]]),
		[],[])

  AC_ARG_ENABLE(strict,
		AC_HELP_STRING([--enable-strict],
			      [compiles with strict compiler options (may not work!)]),
   [
    if test $enableval = "no"; then
         kde_use_strict_options="no"
       else
         kde_use_strict_options="yes"
    fi
   ], [kde_use_strict_options="no"])

  AC_ARG_ENABLE(warnings,AC_HELP_STRING([--disable-warnings],[disables compilation with -Wall and similar]),
   [
    if test $enableval = "no"; then
         kde_use_warnings="no"
       else
         kde_use_warnings="yes"
    fi
   ], [kde_use_warnings="yes"])

  dnl enable warnings for debug build
  if test "$kde_use_debug_code" != "no"; then
    kde_use_warnings=yes
  fi

  AC_ARG_ENABLE(profile,AC_HELP_STRING([--enable-profile],[creates profiling infos [default=no]]),
    [kde_use_profiling=$enableval],
    [kde_use_profiling="no"]
  )

  dnl this prevents stupid AC_PROG_CC to add "-g" to the default CFLAGS
  CFLAGS=" $CFLAGS"

  AC_PROG_CC 

  AC_PROG_CPP

  AC_C_BIGENDIAN

  if test "$GCC" = "yes"; then
    if test "$kde_use_debug_code" != "no"; then
      if test $kde_use_debug_code = "full"; then
        CFLAGS="-g3 -fno-inline $CFLAGS"
      else
        CFLAGS="-g -O2 -fno-schedule-insns -fno-inline $CFLAGS"
      fi
    else
      CFLAGS="-O2 $CFLAGS"
    fi
  fi

  if test "$kde_use_debug_define" = "yes"; then
    CFLAGS="-DNDEBUG $CFLAGS"
  fi


  case "$host" in
  *-*-sysv4.2uw*) CFLAGS="-D_UNIXWARE $CFLAGS";;
  *-*-sysv5uw7*) CFLAGS="-D_UNIXWARE7 $CFLAGS";;
  esac

  if test -z "$LDFLAGS" && test "$kde_use_debug_code" = "no" && test "$GCC" = "yes"; then
     LDFLAGS=""
  fi

  CXXFLAGS=" $CXXFLAGS"

  AC_PROG_CXX

  KDE_CHECK_FOR_BAD_COMPILER

  if test "$GXX" = "yes" || test "$CXX" = "KCC"; then
    if test "$kde_use_debug_code" != "no"; then
      if test "$CXX" = "KCC"; then
        CXXFLAGS="+K0 -Wall -pedantic -W -Wpointer-arith -Wwrite-strings $CXXFLAGS"
      else
        if test "$kde_use_debug_code" = "full"; then
          CXXFLAGS="-g3 -fno-inline $CXXFLAGS"
        else
          CXXFLAGS="-g -O2 -fno-schedule-insns -fno-inline $CXXFLAGS"
        fi
      fi
      KDE_CHECK_COMPILER_FLAG(fno-builtin,[CXXFLAGS="-fno-builtin $CXXFLAGS"])

      dnl convenience compiler flags
      KDE_CHECK_COMPILER_FLAG(Woverloaded-virtual, [WOVERLOADED_VIRTUAL="-Woverloaded-virtual"], [WOVERLOADED_VRITUAL=""])
      AC_SUBST(WOVERLOADED_VIRTUAL)
    else
      if test "$CXX" = "KCC"; then
        CXXFLAGS="+K3 $CXXFLAGS"
      else
        CXXFLAGS="-O2 $CXXFLAGS"
      fi
    fi
  fi

  if test "$kde_use_debug_define" = "yes"; then
    CXXFLAGS="-DNDEBUG -DNO_DEBUG $CXXFLAGS"
  fi  

  if test "$kde_use_profiling" = "yes"; then
    KDE_CHECK_COMPILER_FLAG(pg,
    [
      CFLAGS="-pg $CFLAGS"
      CXXFLAGS="-pg $CXXFLAGS"
    ])
  fi

  if test "$kde_use_warnings" = "yes"; then
      if test "$GCC" = "yes"; then
        CXXFLAGS="-Wall -W -Wpointer-arith $CXXFLAGS"
        case $host in
          *-*-linux-gnu)	
            CFLAGS="-std=iso9899:1999 -W -Wall -Wchar-subscripts -Wshadow -Wpointer-arith -Wmissing-prototypes -Wwrite-strings -D_XOPEN_SOURCE=500 -D_BSD_SOURCE $CFLAGS"
            CXXFLAGS="-ansi -D_XOPEN_SOURCE=500 -D_BSD_SOURCE -Wcast-align -Wchar-subscripts $CXXFLAGS"
            KDE_CHECK_COMPILER_FLAG(Wmissing-format-attribute, [CXXFLAGS="$CXXFLAGS -Wformat-security -Wmissing-format-attribute"])
            KDE_CHECK_C_COMPILER_FLAG(Wmissing-format-attribute, [CFLAGS="$CFLAGS -Wformat-security -Wmissing-format-attribute"])
          ;;
        esac
        KDE_CHECK_COMPILER_FLAG(Wundef,[CXXFLAGS="-Wundef $CXXFLAGS"])
        KDE_CHECK_COMPILER_FLAG(Wno-long-long,[CXXFLAGS="-Wno-long-long $CXXFLAGS"])
        dnl ### FIXME: revert for TDE 4
        KDE_CHECK_COMPILER_FLAG(Wno-non-virtual-dtor,[CXXFLAGS="$CXXFLAGS -Wno-non-virtual-dtor"])
     fi
  fi

  if test "$GXX" = "yes" && test "$kde_use_strict_options" = "yes"; then
    CXXFLAGS="-Wcast-qual -Wshadow -Wcast-align $CXXFLAGS"
  fi

  AC_ARG_ENABLE(pch,
     AC_HELP_STRING([--enable-pch],
                    [enables precompiled header support (currently only KCC or gcc >=3.4+unsermake) [default=no]]),
    [ kde_use_pch=$enableval ],[ kde_use_pch=no ])
 
  HAVE_GCC_VISIBILITY=0
  AC_SUBST([HAVE_GCC_VISIBILITY])

  if test "$GXX" = "yes"; then
    gcc_no_reorder_blocks=NO
    KDE_CHECK_COMPILER_FLAG(fno-reorder-blocks,[gcc_no_reorder_blocks=YES])
    if test $kde_use_debug_code != "no" && \
       test $kde_use_debug_code != "full" && \
       test "YES" = "$gcc_no_reorder_blocks" ; then
          CXXFLAGS="$CXXFLAGS -fno-reorder-blocks"
          CFLAGS="$CFLAGS -fno-reorder-blocks"
    fi
    KDE_CHECK_COMPILER_FLAG(fno-exceptions,[CXXFLAGS="$CXXFLAGS -fno-exceptions"])
    KDE_CHECK_COMPILER_FLAG(fno-check-new, [CXXFLAGS="$CXXFLAGS -fno-check-new"])
    KDE_CHECK_COMPILER_FLAG(fno-common, [CXXFLAGS="$CXXFLAGS -fno-common"])
    KDE_CHECK_COMPILER_FLAG(fexceptions, [USE_EXCEPTIONS="-fexceptions"], USE_EXCEPTIONS=	)
    ENABLE_PERMISSIVE_FLAG="-fpermissive"

    if test "$kde_use_pch" = "yes"; then
        AC_MSG_CHECKING(whether gcc supports precompiling c header files)
        echo >conftest.h
        if $CC -x c-header conftest.h >/dev/null 2>/dev/null; then
            kde_gcc_supports_pch=yes
            AC_MSG_RESULT(yes)
        else
            kde_gcc_supports_pch=no
            AC_MSG_RESULT(no)
        fi
        if test "$kde_gcc_supports_pch" = "yes"; then
            AC_MSG_CHECKING(whether gcc supports precompiling c++ header files)
            if $CXX -x c++-header conftest.h >/dev/null 2>/dev/null; then
                kde_gcc_supports_pch=yes
                AC_MSG_RESULT(yes)
            else
                kde_gcc_supports_pch=no
                AC_MSG_RESULT(no)
            fi
        fi
        rm -f conftest.h conftest.h.gch
    fi

    KDE_CHECK_FOR_OPT_NOINLINE_MATCH
    if test "x$kde_cv_opt_noinline_match" = "xno" ; then
       CFLAGS="`echo "$CFLAGS" | sed "s/ -fno-inline//"`"
    fi
  fi
  AM_CONDITIONAL(unsermake_enable_pch, test "$kde_use_pch" = "yes" && test "$kde_gcc_supports_pch" = "yes")
  if test "$CXX" = "KCC"; then
    dnl unfortunately we currently cannot disable exception support in KCC
    dnl because doing so is binary incompatible and Qt by default links with exceptions :-(
    dnl KDE_CHECK_COMPILER_FLAG(-no_exceptions,[CXXFLAGS="$CXXFLAGS --no_exceptions"])
    dnl KDE_CHECK_COMPILER_FLAG(-exceptions, [USE_EXCEPTIONS="--exceptions"], USE_EXCEPTIONS=	)

    if test "$kde_use_pch" = "yes"; then
      dnl TODO: support --pch-dir!
      KDE_CHECK_COMPILER_FLAG(-pch,[CXXFLAGS="$CXXFLAGS --pch"])
      dnl the below works (but the dir must exist), but it's
      dnl useless for a whole package.
      dnl The are precompiled headers for each source file, so when compiling
      dnl from scratch, it doesn't make a difference, and they take up
      dnl around ~5Mb _per_ sourcefile.
      dnl KDE_CHECK_COMPILER_FLAG(-pch_dir /tmp,
      dnl   [CXXFLAGS="$CXXFLAGS --pch_dir `pwd`/pcheaders"])
    fi
    dnl this flag controls inlining. by default KCC inlines in optimisation mode
    dnl all implementations that are defined inside the class {} declaration. 
    dnl because of templates-compatibility with broken gcc compilers, this
    dnl can cause excessive inlining. This flag limits it to a sane level
    KDE_CHECK_COMPILER_FLAG(-inline_keyword_space_time=6,[CXXFLAGS="$CXXFLAGS --inline_keyword_space_time=6"])
    KDE_CHECK_COMPILER_FLAG(-inline_auto_space_time=2,[CXXFLAGS="$CXXFLAGS --inline_auto_space_time=2"])
    KDE_CHECK_COMPILER_FLAG(-inline_implicit_space_time=2.0,[CXXFLAGS="$CXXFLAGS --inline_implicit_space_time=2.0"])
    KDE_CHECK_COMPILER_FLAG(-inline_generated_space_time=2.0,[CXXFLAGS="$CXXFLAGS --inline_generated_space_time=2.0"])
    dnl Some source files are shared between multiple executables
    dnl (or libraries) and some of those need template instantiations.
    dnl In that case KCC needs to compile those sources with
    dnl --one_instantiation_per_object.  To make it easy for us we compile
    dnl _all_ objects with that flag (--one_per is a shorthand).
    KDE_CHECK_COMPILER_FLAG(-one_per, [CXXFLAGS="$CXXFLAGS --one_per"])
  fi
  AC_SUBST(USE_EXCEPTIONS)
  dnl obsolete macro - provided to keep things going
  USE_RTTI=
  AC_SUBST(USE_RTTI)

  case "$host" in
      *-*-irix*)  test "$GXX" = yes && CXXFLAGS="-D_LANGUAGE_C_PLUS_PLUS -D__LANGUAGE_C_PLUS_PLUS $CXXFLAGS" ;;
      *-*-sysv4.2uw*) CXXFLAGS="-D_UNIXWARE $CXXFLAGS";;
      *-*-sysv5uw7*) CXXFLAGS="-D_UNIXWARE7 $CXXFLAGS";;
      *-*-solaris*) 
        if test "$GXX" = yes; then
          libstdcpp=`$CXX -print-file-name=libstdc++.so`
          if test ! -f $libstdcpp; then
             AC_MSG_ERROR([You've compiled gcc without --enable-shared. This doesn't work with KDE. Please recompile gcc with --enable-shared to receive a libstdc++.so])
          fi
        fi
        ;;
  esac

  AC_VALIDIFY_CXXFLAGS

  AC_PROG_CXXCPP

  if test "$GCC" = yes; then
     NOOPT_CFLAGS=-O0
  fi
  KDE_CHECK_COMPILER_FLAG(O0,[NOOPT_CXXFLAGS=-O0])

  AC_ARG_ENABLE(coverage,
    AC_HELP_STRING([--enable-coverage],[use gcc coverage testing]), [
      if test "$am_cv_CC_dependencies_compiler_type" = "gcc3"; then
        ac_coverage_compiler="-fprofile-arcs -ftest-coverage"
        ac_coverage_linker="-lgcc"
      elif test "$am_cv_CC_dependencies_compiler_type" = "gcc"; then
        ac_coverage_compiler="-fprofile-arcs -ftest-coverage"
        ac_coverage_linker=""
      else
        AC_MSG_ERROR([coverage with your compiler is not supported])
      fi
      CFLAGS="$CFLAGS $ac_coverage_compiler"
      CXXFLAGS="$CXXFLAGS $ac_coverage_compiler"
      LDFLAGS="$LDFLAGS $ac_coverage_linker"
    ])

  AC_SUBST(NOOPT_CXXFLAGS)
  AC_SUBST(NOOPT_CFLAGS)
  AC_SUBST(ENABLE_PERMISSIVE_FLAG)

  KDE_CHECK_NEW_LDFLAGS
  KDE_CHECK_FINAL
  KDE_CHECK_CLOSURE
  KDE_CHECK_NMCHECK

  ifdef([AM_DEPENDENCIES], AC_REQUIRE([KDE_ADD_DEPENDENCIES]), [])
])

AC_DEFUN([KDE_CHECK_VISIBILITY_GCC_BUG],
  [
    AC_CACHE_CHECK([for gcc -fvisibility-inlines-hidden bug], kde_cv_val_gcc_visibility_bug,
      [
        AC_LANG_SAVE
        AC_LANG_CPLUSPLUS

        safe_CXXFLAGS=$CXXFLAGS
        safe_LDFLAGS=$LDFLAGS
        CXXFLAGS="$CXXFLAGS -fPIC -fvisibility-inlines-hidden -O0"
        LDFLAGS="$LDFLAGS -shared -fPIC"

        AC_TRY_LINK(
        [
          /* http://gcc.gnu.org/bugzilla/show_bug.cgi?id=19664 */
	  #include <string>
          int some_function( void ) __attribute__ ((visibility("default")));
          int some_function( void )
          {
	    std::string s("blafasel");
            return 0;
          }
        ], [/* elvis is alive */],
        kde_cv_val_gcc_visibility_bug=no, kde_cv_val_gcc_visibility_bug=yes)

        CXXFLAGS=$safe_CXXFLAGS
        LDFLAGS=$safe_LDFLAGS
        AC_LANG_RESTORE
      ]
    )

    if test x$kde_cv_val_gcc_visibility_bug = xno; then
      CXXFLAGS="$CXXFLAGS -fvisibility-inlines-hidden"
    fi
  ]
)

AC_DEFUN([KDE_ENABLE_HIDDEN_VISIBILITY],
[
  AC_BEFORE([AC_PATH_QT_1_3], [KDE_ENABLE_HIDDEN_VISIBILITY])

  AC_MSG_CHECKING([grepping for visibility push/pop in headers])

  if test "x$GXX" = "xyes"; then
    AC_LANG_SAVE
    AC_LANG_CPLUSPLUS
    AC_EGREP_CPP(
       [GCC visibility push],
       [ #include <exception> 
       ], 
    [
      AC_MSG_RESULT(yes)
      kde_stdc_visibility_patched=yes ],
    [ 
      AC_MSG_RESULT(no)
      AC_MSG_WARN([Your libstdc++ doesn't appear to be patched for 
                   visibility support. Disabling -fvisibility=hidden])

      kde_stdc_visibility_patched=no ])

    AC_LANG_RESTORE

    kde_have_gcc_visibility=no
    KDE_CHECK_COMPILER_FLAG(fvisibility=hidden, 
    [
      kde_have_gcc_visibility=yes
      dnl the whole toolchain is just a mess, gcc is just too buggy
      dnl to handle STL with visibility enabled. Lets reconsider 
      dnl when gcc 4.2 is out or when things get fixed in the compiler.
      dnl Contact mueller@kde.org for details.
      AC_ARG_ENABLE(gcc-hidden-visibility,
        AC_HELP_STRING([--enable-gcc-hidden-visibility],[toolchain hidden visibility [default=no]]),
          [kde_have_gcc_visibility=$enableval],
          [kde_have_gcc_visibility=no])

      AC_CACHE_CHECK([if Qt is patched for -fvisibility], kde_cv_val_qt_gcc_visibility_patched,
        [
          AC_LANG_SAVE
          AC_LANG_CPLUSPLUS

          safe_CXXFLAGS=$CXXFLAGS
          CXXFLAGS="$CXXFLAGS $all_includes"

if test "$kde_qtver" = "3"; then
if $PKG_CONFIG --exists tqt-mt ; then
          AC_TRY_COMPILE(
          [
#include <tqglobal.h>
#if Q_EXPORT - 0 != 0
/* if this compiles, then Q_EXPORT is undefined */
/* if Q_EXPORT is nonempty, this will break compilation */
#endif
          ], [/* elvis is alive */],
          kde_cv_val_qt_gcc_visibility_patched=no, kde_cv_val_qt_gcc_visibility_patched=yes)
else
          AC_TRY_COMPILE(
          [
#include <tqt.h>
#include <qglobal.h>
#if Q_EXPORT - 0 != 0
/* if this compiles, then Q_EXPORT is undefined */
/* if Q_EXPORT is nonempty, this will break compilation */
#endif
          ], [/* elvis is alive */],
          kde_cv_val_qt_gcc_visibility_patched=no, kde_cv_val_qt_gcc_visibility_patched=yes)
fi
fi

if test "$kde_qtver" = "4"; then
AC_TRY_COMPILE(
          [
#include <Qt/qglobal.h>
#if Q_EXPORT - 0 != 0
/* if this compiles, then Q_EXPORT is undefined */
/* if Q_EXPORT is nonempty, this will break compilation */
#endif
          ], [/* elvis is alive */],
          kde_cv_val_qt_gcc_visibility_patched=no, kde_cv_val_qt_gcc_visibility_patched=yes)
fi

          CXXFLAGS=$safe_CXXFLAGS
          AC_LANG_RESTORE
        ]
      )

      if test x$kde_have_gcc_visibility = "xyes" && test x$kde_stdc_visibility_patched = "xyes" && test x$kde_cv_val_qt_gcc_visibility_patched = "xyes"; then
        CXXFLAGS="$CXXFLAGS -fvisibility=hidden"
        KDE_CHECK_VISIBILITY_GCC_BUG
        HAVE_GCC_VISIBILITY=1
        AC_DEFINE_UNQUOTED(__KDE_HAVE_GCC_VISIBILITY, "$HAVE_GCC_VISIBILITY", [define to 1 if -fvisibility is supported])
      fi
    ])
  fi
])

AC_DEFUN([KDE_ADD_DEPENDENCIES],
[
   [A]M_DEPENDENCIES(CC)
   [A]M_DEPENDENCIES(CXX)
])

dnl just a wrapper to clean up configure.in
AC_DEFUN([KDE_PROG_LIBTOOL],
[
AC_REQUIRE([AC_CHECK_COMPILERS])
AC_REQUIRE([AC_ENABLE_SHARED])
AC_REQUIRE([AC_ENABLE_STATIC])

AC_REQUIRE([AC_LIBTOOL_DLOPEN])
AC_REQUIRE([KDE_CHECK_LIB64])

AC_OBJEXT
AC_EXEEXT

AM_PROG_LIBTOOL
AC_LIBTOOL_CXX

# LIBTOOL_SHELL="/bin/sh ./libtool"
LIBTOOL_SHELL="libtool"
#  LIBTOOL="$LIBTOOL --silent"
KDE_PLUGIN="-avoid-version -module -no-undefined \$(KDE_NO_UNDEFINED) \$(KDE_RPATH) \$(KDE_MT_LDFLAGS)"
AC_SUBST(KDE_PLUGIN)

# This hack ensures that libtool creates shared libs for tdeunittest plugins. By default check_LTLIBRARIES makes static libs.
KDE_CHECK_PLUGIN="\$(KDE_PLUGIN) -rpath \$(libdir)"
AC_SUBST(KDE_CHECK_PLUGIN)

# we patch configure quite some so we better keep that consistent for incremental runs 
AC_SUBST(AUTOCONF,'$(SHELL) $(top_srcdir)/admin/cvs.sh configure || touch configure')
])

AC_DEFUN([KDE_CHECK_LIB64],
[
    AC_ARG_ENABLE(libsuffix,
        AC_HELP_STRING([--enable-libsuffix],
            [/lib directory suffix (64,32,none,auto[=default])]),
            tdelibsuff=$enableval, tdelibsuff="auto")
    
    if test "$tdelibsuff" = "auto"; then
    
cat > conftest.c << EOF
#include <stdio.h>
int main() {
 return 0;
}
EOF
        tdelibsuff=`$CC conftest.c -o conftest.out; ldd conftest.out |sed -ne '/libc.so/{
    s,.*/lib\([[^\/]]*\)/.*,\1, 
    p 
}'`
	rm -rf conftest.*
    fi	
	
    if test "$tdelibsuff" = "no" || test "$tdelibsuff" = "none"; then
       tdelibsuff=
    fi
    if test -z "$tdelibsuff"; then
        AC_MSG_RESULT([not using lib directory suffix])
        AC_DEFINE(KDELIBSUFF, [""], Suffix for lib directories)
    else
        if test "$libdir" = '${exec_prefix}/lib'; then
            libdir="$libdir${tdelibsuff}"
            AC_SUBST([libdir], ["$libdir"])  dnl ugly hack for lib64 platforms
        fi
        AC_DEFINE_UNQUOTED(KDELIBSUFF, ["${tdelibsuff}"], Suffix for lib directories)
        AC_MSG_RESULT([using lib directory suffix $tdelibsuff])
    fi
])

AC_DEFUN([KDE_CHECK_TYPES],
[  AC_CHECK_SIZEOF(int, 4)dnl
   AC_CHECK_SIZEOF(short)dnl
  AC_CHECK_SIZEOF(long, 4)dnl
  AC_CHECK_SIZEOF(char *, 4)dnl
])dnl

dnl Not used - kept for compat only?
AC_DEFUN([KDE_DO_IT_ALL],
[
AC_CANONICAL_SYSTEM
AC_ARG_PROGRAM
AM_INIT_AUTOMAKE($1, $2)
AM_DISABLE_LIBRARIES
AC_PREFIX_DEFAULT(${TDEDIR:-/usr/local/kde})
AC_CHECK_COMPILERS
KDE_PROG_LIBTOOL
AM_KDE_WITH_NLS
AC_PATH_KDE
])

AC_DEFUN([AC_CHECK_RPATH],
[
AC_MSG_CHECKING(for rpath)
AC_ARG_ENABLE(rpath,
      AC_HELP_STRING([--disable-rpath],[do not use the rpath feature of ld]),
      USE_RPATH=$enableval, USE_RPATH=yes)

if test -z "$KDE_RPATH" && test "$USE_RPATH" = "yes"; then

  KDE_RPATH="-R \$(libdir)"

  if test "$kde_libraries" != "$libdir"; then
      KDE_RPATH="$KDE_RPATH -R \$(kde_libraries)"
  fi

  if test -n "$qt_libraries"; then
    KDE_RPATH="$KDE_RPATH -R \$(qt_libraries)"
  fi
  dnl $x_libraries is set to /usr/lib in case
  if test -n "$X_LDFLAGS"; then
    X_RPATH="-R \$(x_libraries)"
    KDE_RPATH="$KDE_RPATH $X_RPATH"
  fi
  if test -n "$KDE_EXTRA_RPATH"; then
    KDE_RPATH="$KDE_RPATH \$(KDE_EXTRA_RPATH)"
  fi
fi
AC_SUBST(KDE_EXTRA_RPATH)
AC_SUBST(KDE_RPATH)
AC_SUBST(X_RPATH)
AC_MSG_RESULT($USE_RPATH)
])

dnl Check for the type of the third argument of getsockname
AC_DEFUN([AC_CHECK_SOCKLEN_T],
[
   AC_MSG_CHECKING(for socklen_t)
   AC_CACHE_VAL(kde_cv_socklen_t,
   [
      AC_LANG_PUSH(C++)
      kde_cv_socklen_t=no
      AC_TRY_COMPILE([
         #include <sys/types.h>
         #include <sys/socket.h>
      ],
      [
         socklen_t len;
         getpeername(0,0,&len);
      ],
      [
         kde_cv_socklen_t=yes
         kde_cv_socklen_t_equiv=socklen_t
      ])
      AC_LANG_POP(C++)
   ])
   AC_MSG_RESULT($kde_cv_socklen_t)
   if test $kde_cv_socklen_t = no; then
      AC_MSG_CHECKING([for socklen_t equivalent for socket functions])
      AC_CACHE_VAL(kde_cv_socklen_t_equiv,
      [
         kde_cv_socklen_t_equiv=int
         AC_LANG_PUSH(C++)
         for t in int size_t unsigned long "unsigned long"; do
            AC_TRY_COMPILE([
               #include <sys/types.h>
               #include <sys/socket.h>
            ],
            [
               $t len;
               getpeername(0,0,&len);
            ],
            [
               kde_cv_socklen_t_equiv="$t"
               break
            ])
         done
         AC_LANG_POP(C++)
      ])
      AC_MSG_RESULT($kde_cv_socklen_t_equiv)
   fi
   AC_DEFINE_UNQUOTED(kde_socklen_t, $kde_cv_socklen_t_equiv,
                     [type to use in place of socklen_t if not defined])
   AC_DEFINE_UNQUOTED(ksize_t, $kde_cv_socklen_t_equiv,
                     [type to use in place of socklen_t if not defined (deprecated, use kde_socklen_t)])
])

dnl This is a merge of some macros out of the gettext aclocal.m4
dnl since we don't need anything, I took the things we need
dnl the copyright for them is:
dnl >
dnl Copyright (C) 1994, 1995, 1996, 1997, 1998 Free Software Foundation, Inc.
dnl This Makefile.in is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl This program is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY, to the extent permitted by law; without
dnl even the implied warranty of MERCHANTABILITY or FITNESS FOR A
dnl PARTICULAR PURPOSE.
dnl >
dnl for this file it is relicensed under LGPL

AC_DEFUN([AM_KDE_WITH_NLS],
  [
    dnl If we use NLS figure out what method

    AM_PATH_PROG_WITH_TEST_KDE(MSGFMT, msgfmt,
        [test -n "`$ac_dir/$ac_word --version 2>&1 | grep 'GNU gettext'`"], msgfmt)
    AC_PATH_PROG(GMSGFMT, gmsgfmt, $MSGFMT)

     if test -z "`$GMSGFMT --version 2>&1 | grep 'GNU gettext'`"; then
        AC_MSG_RESULT([found msgfmt program is not GNU msgfmt; ignore it])
        GMSGFMT=":"
      fi
      MSGFMT=$GMSGFMT
      AC_SUBST(GMSGFMT)
      AC_SUBST(MSGFMT)

      AM_PATH_PROG_WITH_TEST_KDE(XGETTEXT, xgettext,
	[test -z "`$ac_dir/$ac_word -h 2>&1 | grep '(HELP)'`"], :)

      dnl Test whether we really found GNU xgettext.
      if test "$XGETTEXT" != ":"; then
	dnl If it is no GNU xgettext we define it as : so that the
	dnl Makefiles still can work.
	if $XGETTEXT --omit-header /dev/null 2> /dev/null; then
	  : ;
	else
	  AC_MSG_RESULT(
	    [found xgettext programs is not GNU xgettext; ignore it])
	  XGETTEXT=":"
	fi
      fi
     AC_SUBST(XGETTEXT)

  ])

# Search path for a program which passes the given test.
# Ulrich Drepper <drepper@cygnus.com>, 1996.

dnl AM_PATH_PROG_WITH_TEST_KDE(VARIABLE, PROG-TO-CHECK-FOR,
dnl   TEST-PERFORMED-ON-FOUND_PROGRAM [, VALUE-IF-NOT-FOUND [, PATH]])
AC_DEFUN([AM_PATH_PROG_WITH_TEST_KDE],
[# Extract the first word of "$2", so it can be a program name with args.
set dummy $2; ac_word=[$]2
AC_MSG_CHECKING([for $ac_word])
AC_CACHE_VAL(ac_cv_path_$1,
[case "[$]$1" in
  /*)
  ac_cv_path_$1="[$]$1" # Let the user override the test with a path.
  ;;
  *)
  IFS="${IFS= 	}"; ac_save_ifs="$IFS"; IFS="${IFS}:"
  for ac_dir in ifelse([$5], , $PATH, [$5]); do
    test -z "$ac_dir" && ac_dir=.
    if test -f $ac_dir/$ac_word; then
      if [$3]; then
	ac_cv_path_$1="$ac_dir/$ac_word"
	break
      fi
    fi
  done
  IFS="$ac_save_ifs"
dnl If no 4th arg is given, leave the cache variable unset,
dnl so AC_PATH_PROGS will keep looking.
ifelse([$4], , , [  test -z "[$]ac_cv_path_$1" && ac_cv_path_$1="$4"
])dnl
  ;;
esac])dnl
$1="$ac_cv_path_$1"
if test -n "[$]$1"; then
  AC_MSG_RESULT([$]$1)
else
  AC_MSG_RESULT(no)
fi
AC_SUBST($1)dnl
])


# Check whether LC_MESSAGES is available in <locale.h>.
# Ulrich Drepper <drepper@cygnus.com>, 1995.

AC_DEFUN([AM_LC_MESSAGES],
  [if test $ac_cv_header_locale_h = yes; then
    AC_CACHE_CHECK([for LC_MESSAGES], am_cv_val_LC_MESSAGES,
      [AC_TRY_LINK([#include <locale.h>], [return LC_MESSAGES],
       am_cv_val_LC_MESSAGES=yes, am_cv_val_LC_MESSAGES=no)])
    if test $am_cv_val_LC_MESSAGES = yes; then
      AC_DEFINE(HAVE_LC_MESSAGES, 1, [Define if your locale.h file contains LC_MESSAGES])
    fi
  fi])

dnl From Jim Meyering.
dnl FIXME: migrate into libit.

AC_DEFUN([AM_FUNC_OBSTACK],
[AC_CACHE_CHECK([for obstacks], am_cv_func_obstack,
 [AC_TRY_LINK([#include "obstack.h"],
	      [struct obstack *mem;obstack_free(mem,(char *) 0)],
	      am_cv_func_obstack=yes,
	      am_cv_func_obstack=no)])
 if test $am_cv_func_obstack = yes; then
   AC_DEFINE(HAVE_OBSTACK)
 else
   LIBOBJS="$LIBOBJS obstack.o"
 fi
])

dnl From Jim Meyering.  Use this if you use the GNU error.[ch].
dnl FIXME: Migrate into libit

AC_DEFUN([AM_FUNC_ERROR_AT_LINE],
[AC_CACHE_CHECK([for error_at_line], am_cv_lib_error_at_line,
 [AC_TRY_LINK([],[error_at_line(0, 0, "", 0, "");],
              am_cv_lib_error_at_line=yes,
	      am_cv_lib_error_at_line=no)])
 if test $am_cv_lib_error_at_line = no; then
   LIBOBJS="$LIBOBJS error.o"
 fi
 AC_SUBST(LIBOBJS)dnl
])

# Macro to add for using GNU gettext.
# Ulrich Drepper <drepper@cygnus.com>, 1995.

AC_DEFUN([AM_KDE_GNU_GETTEXT],
  [AC_REQUIRE([AC_PROG_MAKE_SET])dnl
   AC_REQUIRE([AC_PROG_RANLIB])dnl
   AC_REQUIRE([AC_HEADER_STDC])dnl
   AC_REQUIRE([AC_TYPE_OFF_T])dnl
   AC_REQUIRE([AC_TYPE_SIZE_T])dnl
   AC_REQUIRE([AC_FUNC_ALLOCA])dnl
   AC_REQUIRE([AC_FUNC_MMAP])dnl
   AC_REQUIRE([AM_KDE_WITH_NLS])dnl
   AC_CHECK_HEADERS([limits.h locale.h nl_types.h string.h values.h alloca.h])
   AC_CHECK_FUNCS([getcwd munmap putenv setlocale strchr strcasecmp \
__argz_count __argz_stringify __argz_next])

   AC_MSG_CHECKING(for stpcpy)
   AC_CACHE_VAL(kde_cv_func_stpcpy,
   [
   kde_safe_cxxflags=$CXXFLAGS
   CXXFLAGS="-Werror"
   AC_LANG_SAVE
   AC_LANG_CPLUSPLUS
   AC_TRY_COMPILE([
   #include <string.h>
   ],
   [
   char buffer[200];
   stpcpy(buffer, buffer);
   ],
   kde_cv_func_stpcpy=yes,
   kde_cv_func_stpcpy=no)
   AC_LANG_RESTORE
   CXXFLAGS=$kde_safe_cxxflags
   ])
   AC_MSG_RESULT($kde_cv_func_stpcpy)
   if eval "test \"`echo $kde_cv_func_stpcpy`\" = yes"; then
     AC_DEFINE(HAVE_STPCPY, 1, [Define if you have stpcpy])
   fi

   AM_LC_MESSAGES

   if test "x$CATOBJEXT" != "x"; then
     if test "x$ALL_LINGUAS" = "x"; then
       LINGUAS=
     else
       AC_MSG_CHECKING(for catalogs to be installed)
       NEW_LINGUAS=
       for lang in ${LINGUAS=$ALL_LINGUAS}; do
         case "$ALL_LINGUAS" in
          *$lang*) NEW_LINGUAS="$NEW_LINGUAS $lang" ;;
         esac
       done
       LINGUAS=$NEW_LINGUAS
       AC_MSG_RESULT($LINGUAS)
     fi

     dnl Construct list of names of catalog files to be constructed.
     if test -n "$LINGUAS"; then
       for lang in $LINGUAS; do CATALOGS="$CATALOGS $lang$CATOBJEXT"; done
     fi
   fi

  ])

AC_DEFUN([AC_HAVE_XPM],
 [AC_REQUIRE_CPP()dnl
  AC_REQUIRE([KDE_CHECK_EXTRA_LIBS])

 test -z "$XPM_LDFLAGS" && XPM_LDFLAGS=
 test -z "$XPM_INCLUDE" && XPM_INCLUDE=

 AC_ARG_WITH(xpm,AC_HELP_STRING([--without-xpm],[disable color pixmap XPM tests]),
	xpm_test=$withval, xpm_test="yes")
 if test "x$xpm_test" = xno; then
   ac_cv_have_xpm=no
 else
   AC_MSG_CHECKING(for XPM)
   AC_CACHE_VAL(ac_cv_have_xpm,
   [
    ac_save_ldflags="$LDFLAGS"
    ac_save_cflags="$CFLAGS"
    if test "x$kde_use_qt_emb" != "xyes" && test "x$kde_use_qt_mac" != "xyes"; then
      LDFLAGS="$LDFLAGS $X_LDFLAGS $USER_LDFLAGS $LDFLAGS $XPM_LDFLAGS $all_libraries -lXpm -lX11 -lXext $LIBZ $LIBSOCKET"
    else
      LDFLAGS="$LDFLAGS $X_LDFLAGS $USER_LDFLAGS $LDFLAGS $XPM_LDFLAGS $all_libraries -lXpm $LIBZ $LIBSOCKET"
    fi
    CFLAGS="$CFLAGS $X_INCLUDES $USER_INCLUDES"
    test -n "$XPM_INCLUDE" && CFLAGS="-I$XPM_INCLUDE $CFLAGS"
    AC_TRY_LINK([#include <X11/xpm.h>],[],
	ac_cv_have_xpm="yes",ac_cv_have_xpm="no")
    LDFLAGS="$ac_save_ldflags"
    CFLAGS="$ac_save_cflags"
   ])dnl

  if test "$ac_cv_have_xpm" = no; then
    AC_MSG_RESULT(no)
    XPM_LDFLAGS=""
    XPMINC=""
    $2
  else
    AC_DEFINE(HAVE_XPM, 1, [Define if you have XPM support])
    if test "$XPM_LDFLAGS" = ""; then
       XPMLIB='-lXpm $(LIB_X11)'
    else
       XPMLIB="-L$XPM_LDFLAGS -lXpm "'$(LIB_X11)'
    fi
    if test "$XPM_INCLUDE" = ""; then
       XPMINC=""
    else
       XPMINC="-I$XPM_INCLUDE"
    fi
    AC_MSG_RESULT(yes)
    $1
  fi
 fi
 AC_SUBST(XPMINC)
 AC_SUBST(XPMLIB)
])

AC_DEFUN([AC_HAVE_DPMS],
 [AC_REQUIRE_CPP()dnl
  AC_REQUIRE([KDE_CHECK_EXTRA_LIBS])

 test -z "$DPMS_LDFLAGS" && DPMS_LDFLAGS=
 test -z "$DPMS_INCLUDE" && DPMS_INCLUDE=
 DPMS_LIB=

 AC_ARG_WITH(dpms,AC_HELP_STRING([--without-dpms],[disable DPMS power saving]),
	dpms_test=$withval, dpms_test="yes")
 if test "x$dpms_test" = xno; then
   ac_cv_have_dpms=no
 else
   AC_MSG_CHECKING(for DPMS)
   dnl Note: ac_cv_have_dpms can be no, yes, or -lXdpms.
   dnl 'yes' means DPMS_LIB="", '-lXdpms' means DPMS_LIB="-lXdpms".
   AC_CACHE_VAL(ac_cv_have_dpms,
   [
    if test "x$kde_use_qt_emb" = "xyes" || test "x$kde_use_qt_mac" = "xyes"; then
      AC_MSG_RESULT(no)
      ac_cv_have_dpms="no"
    else
      ac_save_ldflags="$LDFLAGS"
      ac_save_cflags="$CFLAGS"
      ac_save_libs="$LIBS"
      LDFLAGS="$LDFLAGS $DPMS_LDFLAGS $all_libraries"
      LIBS="-lX11 -lXext $LIBSOCKET"
      CFLAGS="$CFLAGS $X_INCLUDES"
      test -n "$DPMS_INCLUDE" && CFLAGS="-I$DPMS_INCLUDE $CFLAGS"
      AC_TRY_LINK([
	  #include <X11/Xproto.h>
	  #include <X11/X.h>
	  #include <X11/Xlib.h>
	  #include <X11/extensions/dpms.h>
	  int foo_test_dpms()
	  { return DPMSSetTimeouts( 0, 0, 0, 0 ); }],[],
	  ac_cv_have_dpms="yes", [
              LIBS="-lXdpms $LIBS"
              AC_TRY_LINK([
	          #include <X11/Xproto.h>
        	  #include <X11/X.h>
        	  #include <X11/Xlib.h>
        	  #include <X11/extensions/dpms.h>
        	  int foo_test_dpms()
        	  { return DPMSSetTimeouts( 0, 0, 0, 0 ); }],[],
        	  [
                  ac_cv_have_dpms="-lXdpms"
                  ],ac_cv_have_dpms="no")
              ])
      LDFLAGS="$ac_save_ldflags"
      CFLAGS="$ac_save_cflags"
      LIBS="$ac_save_libs"
    fi
   ])dnl

  if test "$ac_cv_have_dpms" = no; then
    AC_MSG_RESULT(no)
    DPMS_LDFLAGS=""
    DPMSINC=""
    $2
  else
    AC_DEFINE(HAVE_DPMS, 1, [Define if you have DPMS support])
    if test "$ac_cv_have_dpms" = "-lXdpms"; then
       DPMS_LIB="-lXdpms"
    fi
    if test "$DPMS_LDFLAGS" = ""; then
       DPMSLIB="$DPMS_LIB "'$(LIB_X11)'
    else
       DPMSLIB="$DPMS_LDFLAGS $DPMS_LIB "'$(LIB_X11)'
    fi
    if test "$DPMS_INCLUDE" = ""; then
       DPMSINC=""
    else
       DPMSINC="-I$DPMS_INCLUDE"
    fi
    AC_MSG_RESULT(yes)
    $1
  fi
 fi
 ac_save_cflags="$CFLAGS"
 CFLAGS="$CFLAGS $X_INCLUDES"
 test -n "$DPMS_INCLUDE" && CFLAGS="-I$DPMS_INCLUDE $CFLAGS"
 AH_TEMPLATE(HAVE_DPMSCAPABLE_PROTO,
   [Define if you have the DPMSCapable prototype in <X11/extensions/dpms.h>])
 AC_CHECK_DECL(DPMSCapable,
   AC_DEFINE(HAVE_DPMSCAPABLE_PROTO),,
   [#include <X11/Xlib.h>
   #include <X11/extensions/dpms.h>])
 AH_TEMPLATE(HAVE_DPMSINFO_PROTO,
   [Define if you have the DPMSInfo prototype in <X11/extensions/dpms.h>])
 AC_CHECK_DECL(DPMSInfo,
   AC_DEFINE(HAVE_DPMSINFO_PROTO),,
   [#include <X11/Xlib.h>
   #include <X11/extensions/dpms.h>])
 CFLAGS="$ac_save_cflags"
 AC_SUBST(DPMSINC)
 AC_SUBST(DPMSLIB)
])

AC_DEFUN([AC_HAVE_GL],
 [AC_REQUIRE_CPP()dnl
  AC_REQUIRE([KDE_CHECK_EXTRA_LIBS])

 test -z "$GL_LDFLAGS" && GL_LDFLAGS=
 test -z "$GL_INCLUDE" && GL_INCLUDE=

 AC_ARG_WITH(gl,AC_HELP_STRING([--without-gl],[disable 3D GL modes]),
	gl_test=$withval, gl_test="yes")
 if test "x$kde_use_qt_emb" = "xyes"; then
   # GL and Qt Embedded is a no-go for now.
   ac_cv_have_gl=no
 elif test "x$gl_test" = xno; then
   ac_cv_have_gl=no
 else
   AC_MSG_CHECKING(for GL)
   AC_CACHE_VAL(ac_cv_have_gl,
   [
    AC_LANG_SAVE
    AC_LANG_CPLUSPLUS
    ac_save_ldflags=$LDFLAGS
    ac_save_cxxflags=$CXXFLAGS
    ac_save_libs=$LIBS
    LDFLAGS="$LDFLAGS $GL_LDFLAGS $X_LDFLAGS $all_libraries"
    LIBS="$LIBS -L/usr/lib/mesa -lGL -lGLU"
    test "x$kde_use_qt_mac" != xyes && test "x$kde_use_qt_emb" != xyes && LIBS="$LIBS -lX11"
    LIBS="$LIBS $LIB_XEXT -lm $LIBSOCKET"
    CXXFLAGS="$CFLAGS $X_INCLUDES"
    test -n "$GL_INCLUDE" && CFLAGS="-I$GL_INCLUDE $CFLAGS"
    AC_TRY_LINK([#include <GL/gl.h>
#include <GL/glu.h>
], [],
	ac_cv_have_gl="yes", ac_cv_have_gl="no")
    AC_LANG_RESTORE
    LDFLAGS=$ac_save_ldflags
    CXXFLAGS=$ac_save_cxxflags
    LIBS=$ac_save_libs
   ])dnl

  if test "$ac_cv_have_gl" = "no"; then
    AC_MSG_RESULT(no)
    GL_LDFLAGS=""
    GLINC=""
    $2
  else
    AC_DEFINE(HAVE_GL, 1, [Defines if you have GL (Mesa, OpenGL, ...)])
    if test "$GL_LDFLAGS" = ""; then
       GLLIB='-L/usr/lib/mesa -lGLU -lGL $(LIB_X11)'
    else
       GLLIB="$GL_LDFLAGS -L/usr/lib/mesa -lGLU -lGL "'$(LIB_X11)'
    fi
    if test "$GL_INCLUDE" = ""; then
       GLINC=""
    else
       GLINC="-I$GL_INCLUDE"
    fi
    AC_MSG_RESULT($ac_cv_have_gl)
    $1
  fi
 fi
 AC_SUBST(GLINC)
 AC_SUBST(GLLIB)
])


 dnl shadow password and PAM magic - maintained by ossi@kde.org

AC_DEFUN([KDE_PAM], [
  AC_REQUIRE([KDE_CHECK_LIBDL])

  want_pam=
  AC_ARG_WITH(pam,
    AC_HELP_STRING([--with-pam[=ARG]],[enable support for PAM: ARG=[yes|no|service name]]),
    [ if test "x$withval" = "xyes"; then
        want_pam=yes
        pam_service=tde
      elif test "x$withval" = "xno"; then
        want_pam=no
      else
        want_pam=yes
        pam_service=$withval
      fi
    ], [ pam_service=tde ])

  use_pam=
  PAMLIBS=
  if test "x$want_pam" != xno; then
    AC_CHECK_LIB(pam, pam_start, [
      AC_CHECK_HEADER(security/pam_appl.h,
        [ pam_header=security/pam_appl.h ],
        [ AC_CHECK_HEADER(pam/pam_appl.h,
            [ pam_header=pam/pam_appl.h ],
            [
    AC_MSG_WARN([PAM detected, but no headers found!
Make sure you have the necessary development packages installed.])
            ]
          )
        ]
      )
    ], , $LIBDL)
    if test -z "$pam_header"; then
      if test "x$want_pam" = xyes; then
        AC_MSG_ERROR([--with-pam was specified, but cannot compile with PAM!])
      fi
    else
      AC_DEFINE(HAVE_PAM, 1, [Defines if you have PAM (Pluggable Authentication Modules)])
      PAMLIBS="$PAM_MISC_LIB -lpam $LIBDL"
      use_pam=yes

      dnl darwin claims to be something special
      if test "$pam_header" = "pam/pam_appl.h"; then
        AC_DEFINE(HAVE_PAM_PAM_APPL_H, 1, [Define if your PAM headers are in pam/ instead of security/])
      fi

      dnl test whether struct pam_message is const (Linux) or not (Sun)
      AC_MSG_CHECKING(for const pam_message)
      AC_EGREP_HEADER([struct pam_message], $pam_header,
        [ AC_EGREP_HEADER([const struct pam_message], $pam_header,
                          [AC_MSG_RESULT([const: Linux-type PAM])],
                          [AC_MSG_RESULT([nonconst: Sun-type PAM])
                          AC_DEFINE(PAM_MESSAGE_NONCONST, 1, [Define if your PAM support takes non-const arguments (Solaris)])]
                          )],
        [AC_MSG_RESULT([not found - assume const, Linux-type PAM])])
    fi
  fi

  AC_SUBST(PAMLIBS)
])

dnl DEF_PAM_SERVICE(arg name, full name, define name)
AC_DEFUN([DEF_PAM_SERVICE], [
  AC_ARG_WITH($1-pam,
    AC_HELP_STRING([--with-$1-pam=[val]],[override PAM service from --with-pam for $2]),
    [ if test "x$use_pam" = xyes; then
        $3_PAM_SERVICE=$withval
      else
        AC_MSG_ERROR([Cannot use use --with-$1-pam, as no PAM was detected.
You may want to enforce it by using --with-pam.])
      fi
    ], 
    [ if test "x$use_pam" = xyes; then
        $3_PAM_SERVICE="$pam_service"
      fi
    ])
    if test -n "$$3_PAM_SERVICE"; then
      AC_MSG_RESULT([The PAM service used by $2 will be $$3_PAM_SERVICE])
      AC_DEFINE_UNQUOTED($3_PAM_SERVICE, "$$3_PAM_SERVICE", [The PAM service to be used by $2])
    fi
    AC_SUBST($3_PAM_SERVICE)
])

AC_DEFUN([KDE_SHADOWPASSWD], [
  AC_REQUIRE([KDE_PAM])

  AC_CHECK_LIB(shadow, getspent,
    [ LIBSHADOW="-lshadow"
      ac_use_shadow=yes
    ],
    [ dnl for UnixWare
      AC_CHECK_LIB(gen, getspent, 
        [ LIBGEN="-lgen"
          ac_use_shadow=yes
        ], 
        [ AC_CHECK_FUNC(getspent, 
            [ ac_use_shadow=yes ],
            [ ac_use_shadow=no ])
	])
    ])
  AC_SUBST(LIBSHADOW)
  AC_SUBST(LIBGEN)
  
  AC_MSG_CHECKING([for shadow passwords])

  AC_ARG_WITH(shadow,
    AC_HELP_STRING([--with-shadow],[If you want shadow password support]),
    [ if test "x$withval" != "xno"; then
        use_shadow=yes
      else
        use_shadow=no
      fi
    ], [
      use_shadow="$ac_use_shadow"
    ])

  if test "x$use_shadow" = xyes; then
    AC_MSG_RESULT(yes)
    AC_DEFINE(HAVE_SHADOW, 1, [Define if you use shadow passwords])
  else
    AC_MSG_RESULT(no)
    LIBSHADOW=
    LIBGEN=
  fi

  dnl finally make the relevant binaries setuid root, if we have shadow passwds.
  dnl this still applies, if we could use it indirectly through pam.
  if test "x$use_shadow" = xyes || 
     ( test "x$use_pam" = xyes && test "x$ac_use_shadow" = xyes ); then
      case $host in
      *-*-freebsd* | *-*-netbsd* | *-*-openbsd*)
	SETUIDFLAGS="-m 4755 -o root";;
      *)
	SETUIDFLAGS="-m 4755";;
      esac
  fi
  AC_SUBST(SETUIDFLAGS)

])

AC_DEFUN([KDE_PASSWDLIBS], [
  AC_REQUIRE([KDE_MISC_TESTS]) dnl for LIBCRYPT
  AC_REQUIRE([KDE_PAM])
  AC_REQUIRE([KDE_SHADOWPASSWD])

  if test "x$use_pam" = "xyes"; then 
    PASSWDLIBS="$PAMLIBS"
  else
    PASSWDLIBS="$LIBCRYPT $LIBSHADOW $LIBGEN"
  fi

  dnl FreeBSD uses a shadow-like setup, where /etc/passwd holds the users, but
  dnl /etc/master.passwd holds the actual passwords.  /etc/master.passwd requires
  dnl root to read, so kcheckpass needs to be root (even when using pam, since pam
  dnl may need to read /etc/master.passwd).
  case $host in
  *-*-freebsd*)
    SETUIDFLAGS="-m 4755 -o root"
    ;;
  *)
    ;;
  esac

  AC_SUBST(PASSWDLIBS)
])

AC_DEFUN([KDE_CHECK_LIBDL],
[
AC_CHECK_LIB(dl, dlopen, [
LIBDL="-ldl"
ac_cv_have_dlfcn=yes
])

AC_CHECK_LIB(dld, shl_unload, [
LIBDL="-ldld"
ac_cv_have_shload=yes
])

AC_SUBST(LIBDL)
])

AC_DEFUN([KDE_CHECK_DLOPEN],
[
KDE_CHECK_LIBDL
AC_CHECK_HEADERS(dlfcn.h dl.h)
if test "$ac_cv_header_dlfcn_h" = "no"; then
  ac_cv_have_dlfcn=no
fi

if test "$ac_cv_header_dl_h" = "no"; then
  ac_cv_have_shload=no
fi

dnl XXX why change enable_dlopen? its already set by autoconf's AC_ARG_ENABLE
dnl (MM)
AC_ARG_ENABLE(dlopen,
AC_HELP_STRING([--disable-dlopen],[link statically [default=no]]),
enable_dlopen=$enableval,
enable_dlopen=yes)

# override the user's opinion, if we know it better ;)
if test "$ac_cv_have_dlfcn" = "no" && test "$ac_cv_have_shload" = "no"; then
  enable_dlopen=no
fi

if test "$ac_cv_have_dlfcn" = "yes"; then
  AC_DEFINE_UNQUOTED(HAVE_DLFCN, 1, [Define if you have dlfcn])
fi

if test "$ac_cv_have_shload" = "yes"; then
  AC_DEFINE_UNQUOTED(HAVE_SHLOAD, 1, [Define if you have shload])
fi

if test "$enable_dlopen" = no ; then
  test -n "$1" && eval $1
else
  test -n "$2" && eval $2
fi

])

AC_DEFUN([KDE_CHECK_DYNAMIC_LOADING],
[
KDE_CHECK_DLOPEN(libtool_enable_shared=yes, libtool_enable_static=no)
KDE_PROG_LIBTOOL
AC_MSG_CHECKING([dynamic loading])
eval "`egrep '^build_libtool_libs=' libtool`"
if test "$build_libtool_libs" = "yes" && test "$enable_dlopen" = "yes"; then
  dynamic_loading=yes
  AC_DEFINE_UNQUOTED(HAVE_DYNAMIC_LOADING)
else
  dynamic_loading=no
fi
AC_MSG_RESULT($dynamic_loading)
if test "$dynamic_loading" = "yes"; then
  $1
else
  $2
fi
])

AC_DEFUN([KDE_ADD_INCLUDES],
[
if test -z "$1"; then
  test_include="Pix.h"
else
  test_include="$1"
fi

AC_MSG_CHECKING([for libg++ ($test_include)])

AC_CACHE_VAL(kde_cv_libgpp_includes,
[
kde_cv_libgpp_includes=no

   for ac_dir in               \
                               \
     /usr/include/g++          \
     /usr/include              \
     /usr/unsupported/include  \
     /opt/include              \
     $extra_include            \
     ; \
   do
     if test -r "$ac_dir/$test_include"; then
       kde_cv_libgpp_includes=$ac_dir
       break
     fi
   done
])

AC_MSG_RESULT($kde_cv_libgpp_includes)
if test "$kde_cv_libgpp_includes" != "no"; then
  all_includes="-I$kde_cv_libgpp_includes $all_includes $USER_INCLUDES"
fi
])
])

AC_DEFUN([KDE_CHECK_LIBPTHREAD],
[
  dnl This code is here specifically to handle the
  dnl various flavors of threading library on FreeBSD
  dnl 4-, 5-, and 6-, and the (weird) rules around it.
  dnl There may be an environment PTHREAD_LIBS that 
  dnl specifies what to use; otherwise, search for it.
  dnl -pthread is special cased and unsets LIBPTHREAD
  dnl below if found.
  LIBPTHREAD=""

  if test -n "$PTHREAD_LIBS"; then
    if test "x$PTHREAD_LIBS" = "x-pthread" ; then
      LIBPTHREAD="PTHREAD"
    else
      PTHREAD_LIBS_save="$PTHREAD_LIBS"
      PTHREAD_LIBS=`echo "$PTHREAD_LIBS_save" | sed -e 's,^-l,,g'`
      AC_MSG_CHECKING([for pthread_create in $PTHREAD_LIBS])
      KDE_CHECK_LIB($PTHREAD_LIBS, pthread_create, [
          LIBPTHREAD="$PTHREAD_LIBS_save"])
      PTHREAD_LIBS="$PTHREAD_LIBS_save"
    fi
  fi

  dnl Is this test really needed, in the face of the Tru64 test below?
  if test -z "$LIBPTHREAD"; then
    AC_CHECK_LIB(pthread, pthread_create, [LIBPTHREAD="-lpthread"])
  fi

  dnl This is a special Tru64 check, see BR 76171 issue #18.
  if test -z "$LIBPTHREAD" ; then
    AC_MSG_CHECKING([for pthread_create in -lpthread])
    kde_safe_libs=$LIBS
    LIBS="$LIBS -lpthread"
    AC_TRY_LINK([#include <pthread.h>],[(void)pthread_create(0,0,0,0);],[
        AC_MSG_RESULT(yes)
        LIBPTHREAD="-lpthread"],[
	AC_MSG_RESULT(no)])
    LIBS=$kde_safe_libs
  fi

  dnl Un-special-case for FreeBSD.
  if test "x$LIBPTHREAD" = "xPTHREAD" ; then
    LIBPTHREAD=""
  fi

  AC_SUBST(LIBPTHREAD)
])

AC_DEFUN([KDE_CHECK_PTHREAD_OPTION],
[
      USE_THREADS=""
      if test -z "$LIBPTHREAD"; then
        KDE_CHECK_COMPILER_FLAG(pthread, [USE_THREADS="-D_THREAD_SAFE -pthread"])
      fi

    AH_VERBATIM(__svr_define, [
#if defined(__SVR4) && !defined(__svr4__)
#define __svr4__ 1
#endif
])
    case $host_os in
 	solaris*)
		KDE_CHECK_COMPILER_FLAG(mt, [USE_THREADS="-mt"])
                CPPFLAGS="$CPPFLAGS -D_REENTRANT -D_POSIX_PTHREAD_SEMANTICS -DUSE_SOLARIS -DSVR4"
    		;;
        freebsd*)
                CPPFLAGS="$CPPFLAGS -D_THREAD_SAFE $PTHREAD_CFLAGS"
                ;;
        aix*)
                CPPFLAGS="$CPPFLAGS -D_THREAD_SAFE"
                LIBPTHREAD="$LIBPTHREAD -lc_r"
                ;;
        linux*) CPPFLAGS="$CPPFLAGS -D_REENTRANT"
                if test "$CXX" = "KCC"; then
                  CXXFLAGS="$CXXFLAGS --thread_safe"
		  NOOPT_CXXFLAGS="$NOOPT_CXXFLAGS --thread_safe"
                fi
                ;;
	*)
		;;
    esac
    AC_SUBST(USE_THREADS)
    AC_SUBST(LIBPTHREAD)
])

AC_DEFUN([KDE_CHECK_THREADING],
[
  AC_REQUIRE([KDE_CHECK_LIBPTHREAD])
  AC_REQUIRE([KDE_CHECK_PTHREAD_OPTION])
  dnl default is yes if libpthread is found and no if no libpthread is available
  if test -z "$LIBPTHREAD"; then
    if test -z "$USE_THREADS"; then
      kde_check_threading_default=no
    else
      kde_check_threading_default=yes
    fi
  else
    kde_check_threading_default=yes
  fi
  AC_ARG_ENABLE(threading,AC_HELP_STRING([--disable-threading],[disables threading even if libpthread found]),
   kde_use_threading=$enableval, kde_use_threading=$kde_check_threading_default)
  if test "x$kde_use_threading" = "xyes"; then
    AC_DEFINE(HAVE_LIBPTHREAD, 1, [Define if you have a working libpthread (will enable threaded code)])
  fi
])

AC_DEFUN([KDE_TRY_LINK_PYTHON],
[
if test "$kde_python_link_found" = no; then

if test "$1" = normal; then
  AC_MSG_CHECKING(if a Python application links)
else
  AC_MSG_CHECKING(if Python depends on $2)
fi

AC_CACHE_VAL(kde_cv_try_link_python_$1,
[
kde_save_cflags="$CFLAGS"
CFLAGS="$CFLAGS $PYTHONINC"
kde_save_libs="$LIBS"
LIBS="$LIBS $LIBPYTHON $2 $LIBDL $LIBSOCKET"
kde_save_ldflags="$LDFLAGS"
LDFLAGS="$LDFLAGS $PYTHONLIB"

AC_TRY_LINK(
[
#include <Python.h>
],[
	PySys_SetArgv(1, 0);
],
	[kde_cv_try_link_python_$1=yes],
	[kde_cv_try_link_python_$1=no]
)
CFLAGS="$kde_save_cflags"
LIBS="$kde_save_libs"
LDFLAGS="$kde_save_ldflags"
])

if test "$kde_cv_try_link_python_$1" = "yes"; then
  AC_MSG_RESULT(yes)
  kde_python_link_found=yes
  if test ! "$1" = normal; then
    LIBPYTHON="$LIBPYTHON $2"
  fi
  $3
else
  AC_MSG_RESULT(no)
  $4
fi

fi

])

AC_DEFUN([KDE_CHECK_PYTHON_DIR],
[
AC_MSG_CHECKING([for Python directory])
 
AC_CACHE_VAL(kde_cv_pythondir,
[
  if test -z "$PYTHONDIR"; then
    kde_cv_pythondir=/usr/local
  else
    kde_cv_pythondir="$PYTHONDIR"
  fi
])
 
AC_ARG_WITH(pythondir,
AC_HELP_STRING([--with-pythondir=pythondir],[use python installed in pythondir]),
[
  ac_python_dir=$withval
], ac_python_dir=$kde_cv_pythondir
)
 
AC_MSG_RESULT($ac_python_dir)
])

AC_DEFUN([KDE_CHECK_PYTHON_INTERN],
[
AC_REQUIRE([KDE_CHECK_LIBDL])
AC_REQUIRE([KDE_CHECK_LIBPTHREAD])
AC_REQUIRE([KDE_CHECK_PYTHON_DIR])

if test -z "$1"; then
  version="1.5"
else
  version="$1"
fi

AC_MSG_CHECKING([for Python$version])

python_incdirs="$ac_python_dir/include /usr/include /usr/local/include/ $kde_extra_includes"
AC_FIND_FILE(Python.h, $python_incdirs, python_incdir)
if test ! -r $python_incdir/Python.h; then
  AC_FIND_FILE(python$version/Python.h, $python_incdirs, python_incdir)
  python_incdir=$python_incdir/python$version
  if test ! -r $python_incdir/Python.h; then
    python_incdir=no
  fi
fi

PYTHONINC=-I$python_incdir

python_multiarch_libdirs="`find /usr/lib/ -maxdepth 1 -type d | xargs echo`"
python_libdirs="$ac_python_dir/lib$tdelibsuff /usr/lib$tdelibsuff /usr/local /usr/lib$tdelibsuff $python_multiarch_libdirs $kde_extra_libs"
AC_FIND_FILE(libpython$version.so, $python_libdirs, python_libdir)
if test ! -r $python_libdir/libpython$version.so; then
  AC_FIND_FILE(libpython$version.a, $python_libdirs, python_libdir)
  if test ! -r $python_libdir/libpython$version.a; then
    AC_FIND_FILE(python$version/config/libpython$version.a, $python_libdirs, python_libdir)
    python_libdir=$python_libdir/python$version/config
    if test ! -r $python_libdir/libpython$version.a; then
      python_libdir=no
    fi
  fi
fi

PYTHONLIB=-L$python_libdir
kde_orig_LIBPYTHON=$LIBPYTHON
if test -z "$LIBPYTHON"; then
  LIBPYTHON=-lpython$version
fi

AC_FIND_FILE(python$version/copy.py, $python_libdirs, python_moddir)
python_moddir=$python_moddir/python$version
if test ! -r $python_moddir/copy.py; then
  python_moddir=no
fi

PYTHONMODDIR=$python_moddir

AC_MSG_RESULT(header $python_incdir library $python_libdir modules $python_moddir)

if test x$python_incdir = xno ||  test x$python_libdir = xno ||  test x$python_moddir = xno; then
   LIBPYTHON=$kde_orig_LIBPYTHON
   test "x$PYTHONLIB" = "x-Lno" && PYTHONLIB=""
   test "x$PYTHONINC" = "x-Ino" && PYTHONINC=""
   $2
else 
  dnl Note: this test is very weak
  kde_python_link_found=no
  KDE_TRY_LINK_PYTHON(normal)
  KDE_TRY_LINK_PYTHON(m, -lm)
  KDE_TRY_LINK_PYTHON(pthread, $LIBPTHREAD)
  KDE_TRY_LINK_PYTHON(tcl, -ltcl)
  KDE_TRY_LINK_PYTHON(db2, -ldb2)
  KDE_TRY_LINK_PYTHON(m_and_thread, [$LIBPTHREAD -lm])
  KDE_TRY_LINK_PYTHON(m_and_thread_and_util, [$LIBPTHREAD -lm -lutil])
  KDE_TRY_LINK_PYTHON(m_and_thread_and_db3, [$LIBPTHREAD -lm -ldb-3 -lutil])
  KDE_TRY_LINK_PYTHON(pthread_and_db3, [$LIBPTHREAD -ldb-3])
  KDE_TRY_LINK_PYTHON(m_and_thread_and_db, [$LIBPTHREAD -lm -ldb -ltermcap -lutil])
  KDE_TRY_LINK_PYTHON(pthread_and_dl, [$LIBPTHREAD $LIBDL -lutil -lreadline -lncurses -lm])
  KDE_TRY_LINK_PYTHON(pthread_and_panel_curses, [$LIBPTHREAD $LIBDL -lm -lpanel -lcurses])
  KDE_TRY_LINK_PYTHON(m_and_thread_and_db_special, [$LIBPTHREAD -lm -ldb -lutil], [],
	[AC_MSG_WARN([it seems, Python depends on another library.
    Please set LIBPYTHON to '-lpython$version -lotherlib' before calling configure to fix this
    and contact the authors to let them know about this problem])
	])

  LIBPYTHON="$LIBPYTHON $LIBDL $LIBSOCKET"
  AC_SUBST(PYTHONINC)
  AC_SUBST(PYTHONLIB)
  AC_SUBST(LIBPYTHON)
  AC_SUBST(PYTHONMODDIR)
  AC_DEFINE(HAVE_PYTHON, 1, [Define if you have the development files for python])
fi

])


AC_DEFUN([KDE_CHECK_PYTHON],
[
  KDE_CHECK_PYTHON_INTERN("2.7",
    [KDE_CHECK_PYTHON_INTERN("2.6",
      [KDE_CHECK_PYTHON_INTERN("2.5",
        [KDE_CHECK_PYTHON_INTERN("2.4",
          [KDE_CHECK_PYTHON_INTERN("2.3", 
            [KDE_CHECK_PYTHON_INTERN("2.2", 
              [KDE_CHECK_PYTHON_INTERN("2.1", 
                [KDE_CHECK_PYTHON_INTERN("2.0", 
                  [KDE_CHECK_PYTHON_INTERN($1, $2) ])
                ])
              ])
            ])
          ])
        ])
      ])
    ])
])

AC_DEFUN([KDE_CHECK_STL],
[
    AC_LANG_SAVE
    AC_LANG_CPLUSPLUS
    ac_save_CXXFLAGS="$CXXFLAGS"
    CXXFLAGS="`echo $CXXFLAGS | sed s/-fno-exceptions//`"
    if test -z "$qt_includes"; then
      CXXFLAGS="$CXXFLAGS"
    else
      CXXFLAGS="$CXXFLAGS -I$qt_includes"
    fi

    AC_MSG_CHECKING([if C++ programs can be compiled])
    AC_CACHE_VAL(kde_cv_stl_works,
    [
      AC_TRY_COMPILE([
#include <string>
using namespace std;
],[
  string astring="Hallo Welt.";
  astring.erase(0, 6); // now astring is "Welt"
  return 0;
], kde_cv_stl_works=yes,
   kde_cv_stl_works=no)
])

   AC_MSG_RESULT($kde_cv_stl_works)

   if test "$kde_cv_stl_works" = "yes"; then
     # back compatible
	 AC_DEFINE_UNQUOTED(HAVE_SGI_STL, 1, [Define if you have a STL implementation by SGI])
   else
	 AC_MSG_ERROR([Your Installation isn't able to compile simple C++ programs.
Check config.log for details - if you're using a Linux distribution you might miss
a package named similar to libstdc++-dev.])
   fi

   CXXFLAGS="$ac_save_CXXFLAGS"
   AC_LANG_RESTORE
])

AC_DEFUN([AC_FIND_QIMGIO],
   [AC_REQUIRE([AC_FIND_JPEG])
AC_REQUIRE([KDE_CHECK_EXTRA_LIBS])
AC_MSG_CHECKING([for qimgio])
AC_CACHE_VAL(ac_cv_lib_qimgio,
[
AC_LANG_SAVE
AC_LANG_CPLUSPLUS
ac_save_LIBS="$LIBS"
ac_save_CXXFLAGS="$CXXFLAGS"

if test "$kde_qtver" = "3"; then
LIBS="$all_libraries -lqimgio -lpng -lz $LIBJPEG $LIBQT"
CXXFLAGS="$CXXFLAGS -I$qt_incdir $all_includes"
if $PKG_CONFIG --exists tqt-mt ; then
AC_TRY_RUN(dnl
[
#include <tqimageio.h>
#include <tqstring.h>
int main() {
                TQString t = "hallo";
                t.fill('t');
                qInitImageIO();
}
],
            ac_cv_lib_qimgio=yes,
            ac_cv_lib_qimgio=no,
            ac_cv_lib_qimgio=no)
else
AC_TRY_RUN(dnl
[
#include <qimageio.h>
#include <qstring.h>
int main() {
                QString t = "hallo";
                t.fill('t');
                qInitImageIO();
}
],
            ac_cv_lib_qimgio=yes,
            ac_cv_lib_qimgio=no,
            ac_cv_lib_qimgio=no)
fi
fi

if test "$kde_qtver" = "4"; then
LIBS="$all_libraries -lpng -lz $LIBJPEG $LIBQT"
CXXFLAGS="$CXXFLAGS -I$qt_incdir $all_includes"
AC_TRY_RUN(dnl
[
#include <tqimageio.h>
#include <tqstring.h>
int main() {
		QString t = "hallo";
		t.fill('t');
		qInitImageIO();
}
],
            ac_cv_lib_qimgio=yes,
            ac_cv_lib_qimgio=no,
	    ac_cv_lib_qimgio=no)
fi

LIBS="$ac_save_LIBS"
CXXFLAGS="$ac_save_CXXFLAGS"
AC_LANG_RESTORE
])dnl
if eval "test \"`echo $ac_cv_lib_qimgio`\" = yes"; then
  LIBQIMGIO="-lqimgio -lpng -lz $LIBJPEG"
  AC_MSG_RESULT(yes)
  AC_DEFINE_UNQUOTED(HAVE_QIMGIO, 1, [Define if you have the Qt extension qimgio available])
  AC_SUBST(LIBQIMGIO)
else
  AC_MSG_RESULT(not found)
fi
])

AC_DEFUN([KDE_CHECK_HONORS_SOCKET_PERMS],
[
AC_MSG_CHECKING([if underlying system honors socket permissions])
AC_CACHE_VAL(ac_cv_honors_socket_perms,
[
AC_LANG_SAVE
AC_LANG_C
ac_save_LIBS="$LIBS"
ac_save_CPPFLAGS="$CPPFLAGS"
LIBS="$all_libraries"
CPPFLAGS="$CPPFLAGS $all_includes"
AC_TRY_RUN(dnl
[
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
int main()
{
    int fd, fd2;
    struct sockaddr_un sa;

    if ((fd = socket(PF_UNIX, SOCK_STREAM, 0)) < 0)
        return 2;
    sa.sun_family = AF_UNIX;
    strcpy(sa.sun_path, "testsock");
    unlink(sa.sun_path);
    if (bind(fd, (struct sockaddr *)&sa, sizeof(sa)))
        return 2;
    chmod(sa.sun_path, 0);
    setuid(getuid() + 1000);
    if ((fd2 = socket(PF_UNIX, SOCK_STREAM, 0)) < 0)
        return 2;
    connect(fd2, (struct sockaddr *)&sa, sizeof(sa));
    return errno != EACCES;
}
],
            ac_cv_honors_socket_perms=yes,
            ac_cv_honors_socket_perms=no,
	    ac_cv_honors_socket_perms=no)
LIBS="$ac_save_LIBS"
CPPFLAGS="$ac_save_CPPFLAGS"
AC_LANG_RESTORE
])dnl
if eval "test \"`echo $ac_cv_honors_socket_perms`\" = yes"; then
  AC_MSG_RESULT(yes)
  AC_DEFINE_UNQUOTED(HONORS_SOCKET_PERMS, 1, [Defined if the underlying system honors socket permissions])
else
  AC_MSG_RESULT(no)
fi
])

AC_DEFUN([AM_DISABLE_LIBRARIES],
[
    AC_PROVIDE([AM_ENABLE_STATIC])
    AC_PROVIDE([AM_ENABLE_SHARED])
    enable_static=no
    enable_shared=yes
])


AC_DEFUN([AC_CHECK_UTMP_FILE],
[
    AC_MSG_CHECKING([for utmp file])

    AC_CACHE_VAL(kde_cv_utmp_file,
    [
    kde_cv_utmp_file=no

    for ac_file in    \
                      \
	/var/run/utmp \
	/var/adm/utmp \
	/etc/utmp     \
     ; \
    do
     if test -r "$ac_file"; then
       kde_cv_utmp_file=$ac_file
       break
     fi
    done
    ])

    if test "$kde_cv_utmp_file" != "no"; then
	AC_DEFINE_UNQUOTED(UTMP, "$kde_cv_utmp_file", [Define the file for utmp entries])
	$1
	AC_MSG_RESULT($kde_cv_utmp_file)
    else
    	$2
	AC_MSG_RESULT([non found])
    fi
])


AC_DEFUN([KDE_CREATE_SUBDIRSLIST],
[

DO_NOT_COMPILE="$DO_NOT_COMPILE CVS debian bsd-port admin"
TOPSUBDIRS=""

if test ! -s $srcdir/subdirs; then
  dnl Note: Makefile.common creates subdirs, so this is just a fallback
  files=`cd $srcdir && ls -1`
  dirs=`for i in $files; do if test -d $i; then echo $i; fi; done`
  for i in $dirs; do
    echo $i >> $srcdir/subdirs
  done
fi

ac_topsubdirs=
if test -s $srcdir/inst-apps; then
  ac_topsubdirs="`cat $srcdir/inst-apps`"
elif test -s $srcdir/subdirs; then
  ac_topsubdirs="`cat $srcdir/subdirs`"
fi

for i in $ac_topsubdirs; do
  AC_MSG_CHECKING([if $i should be compiled])
  if test -d $srcdir/$i; then
    install_it="yes"
    for j in $DO_NOT_COMPILE; do
      if test $i = $j; then
        install_it="no"
      fi
    done
  else
    install_it="no"
  fi
  AC_MSG_RESULT($install_it)
  vari=`echo $i | sed -e 's,[[-+.@]],_,g'`
  if test $install_it = "yes"; then
    TOPSUBDIRS="$TOPSUBDIRS $i"
    eval "$vari""_SUBDIR_included=yes"
  else
    eval "$vari""_SUBDIR_included=no"
  fi
done

AC_SUBST(TOPSUBDIRS)
])

AC_DEFUN([KDE_CHECK_NAMESPACES],
[
AC_MSG_CHECKING(whether C++ compiler supports namespaces)
AC_LANG_SAVE
AC_LANG_CPLUSPLUS
AC_TRY_COMPILE([
],
[
namespace Foo {
  extern int i;
  namespace Bar {
    extern int i;
  }
}

int Foo::i = 0;
int Foo::Bar::i = 1;
],[
  AC_MSG_RESULT(yes)
  AC_DEFINE(HAVE_NAMESPACES)
], [
AC_MSG_RESULT(no)
])
AC_LANG_RESTORE
])

dnl ------------------------------------------------------------------------
dnl Check for S_ISSOCK macro. Doesn't exist on Unix SCO. faure@kde.org
dnl ------------------------------------------------------------------------
dnl
AC_DEFUN([AC_CHECK_S_ISSOCK],
[
AC_MSG_CHECKING(for S_ISSOCK)
AC_CACHE_VAL(ac_cv_have_s_issock,
[
AC_TRY_LINK(
[
#include <sys/stat.h>
],
[
struct stat buff;
int b = S_ISSOCK( buff.st_mode );
],
ac_cv_have_s_issock=yes,
ac_cv_have_s_issock=no)
])
AC_MSG_RESULT($ac_cv_have_s_issock)
if test "$ac_cv_have_s_issock" = "yes"; then
  AC_DEFINE_UNQUOTED(HAVE_S_ISSOCK, 1, [Define if sys/stat.h declares S_ISSOCK.])
fi

AH_VERBATIM(_ISSOCK,
[
#ifndef HAVE_S_ISSOCK
#define HAVE_S_ISSOCK
#define S_ISSOCK(mode) (1==0)
#endif
])

])

dnl ------------------------------------------------------------------------
dnl Check for MAXPATHLEN macro, defines KDEMAXPATHLEN. faure@kde.org
dnl ------------------------------------------------------------------------
dnl
AC_DEFUN([AC_CHECK_KDEMAXPATHLEN],
[
AC_MSG_CHECKING(for MAXPATHLEN)
AC_CACHE_VAL(ac_cv_maxpathlen,
[
cat > conftest.$ac_ext <<EOF
#ifdef STDC_HEADERS
# include <stdlib.h>
#endif
#include <stdio.h>
#include <sys/param.h>
#ifndef MAXPATHLEN
#define MAXPATHLEN 1024
#endif

KDE_HELLO MAXPATHLEN

EOF

ac_try="$ac_cpp conftest.$ac_ext 2>/dev/null | grep '^KDE_HELLO' >conftest.out"

if AC_TRY_EVAL(ac_try) && test -s conftest.out; then
    ac_cv_maxpathlen=`sed 's#KDE_HELLO ##' conftest.out`
else
    ac_cv_maxpathlen=1024
fi

rm conftest.*

])
AC_MSG_RESULT($ac_cv_maxpathlen)
AC_DEFINE_UNQUOTED(KDEMAXPATHLEN,$ac_cv_maxpathlen, [Define a safe value for MAXPATHLEN] )
])

AC_DEFUN([KDE_CHECK_HEADER],
[
   kde_safe_cppflags=$CPPFLAGS
   CPPFLAGS="$CPPFLAGS $all_includes -I$kde_incdir/tde -I/usr/include/tqt"
   AC_LANG_SAVE
   AC_LANG_CPLUSPLUS
   AC_CHECK_HEADER([$1], [$2], [$3], [$4])
   AC_LANG_RESTORE
   CPPFLAGS=$kde_safe_cppflags
])

AC_DEFUN([KDE_CHECK_HEADERS],
[
   AH_CHECK_HEADERS_TDE([$1])
   AC_LANG_SAVE
   kde_safe_cppflags=$CPPFLAGS
   CPPFLAGS="$CPPFLAGS $all_includes -I$kde_incdir/tde -I/usr/include/tqt"
   AC_LANG_CPLUSPLUS
   AC_CHECK_HEADERS([$1], [$2], [$3], [$4])
   CPPFLAGS=$kde_safe_cppflags
   AC_LANG_RESTORE
])

AC_DEFUN([KDE_FAST_CONFIGURE],
[
  dnl makes configure fast (needs perl)
  AC_ARG_ENABLE(fast-perl, AC_HELP_STRING([--disable-fast-perl],[disable fast Makefile generation (needs perl)]),
      with_fast_perl=$enableval, with_fast_perl=yes)
])

AC_DEFUN([KDE_CONF_FILES],
[
  val=
  if test -f $srcdir/configure.files ; then
    val=`sed -e 's%^%\$(top_srcdir)/%' $srcdir/configure.files`
  fi
  CONF_FILES=
  if test -n "$val" ; then
    for i in $val ; do
      CONF_FILES="$CONF_FILES $i"
    done
  fi
  AC_SUBST(CONF_FILES)
])dnl

dnl This sets the prefix, for arts and tdelibs
dnl Do NOT use in any other module.
dnl It only looks at --prefix, TDEDIR and falls back to /usr/local/kde
AC_DEFUN([KDE_SET_PREFIX_CORE],
[
  unset CDPATH
  dnl make $TDEDIR the default for the installation
  AC_PREFIX_DEFAULT(${TDEDIR:-/usr/local/kde})

  if test "x$prefix" = "xNONE"; then
    prefix=$ac_default_prefix
    ac_configure_args="$ac_configure_args --prefix=$prefix"
  fi
  # And delete superfluous '/' to make compares easier
  prefix=`echo "$prefix" | sed 's,//*,/,g' | sed -e 's,/$,,'`
  exec_prefix=`echo "$exec_prefix" | sed 's,//*,/,g' | sed -e 's,/$,,'`

  kde_libs_prefix='$(prefix)'
  kde_libs_htmldir='$(kde_htmldir)'
  AC_SUBST(kde_libs_prefix)
  AC_SUBST(kde_libs_htmldir)
  KDE_FAST_CONFIGURE
  KDE_CONF_FILES
])


AC_DEFUN([KDE_SET_PREFIX],
[
  unset CDPATH
  dnl We can't give real code to that macro, only a value.
  dnl It only matters for --help, since we set the prefix in this function anyway.
  AC_PREFIX_DEFAULT(${TDEDIR:-the kde prefix})

  KDE_SET_DEFAULT_BINDIRS
  if test "x$prefix" = "xNONE"; then
    dnl no prefix given: look for tde-config in the PATH and deduce the prefix from it
    KDE_FIND_PATH(tde-config, KDECONFIG, [$kde_default_bindirs], [KDE_MISSING_PROG_ERROR(tde-config)], [], prepend)
  else
    dnl prefix given: look for tde-config, preferrably in prefix, otherwise in PATH
    kde_save_PATH="$PATH"
    PATH="$exec_prefix/bin:$prefix/bin:$PATH"
    KDE_FIND_PATH(tde-config, KDECONFIG, [$kde_default_bindirs], [KDE_MISSING_PROG_ERROR(tde-config)], [], prepend)
    PATH="$kde_save_PATH"
  fi

  kde_libs_prefix=`$KDECONFIG --prefix`
  if test -z "$kde_libs_prefix" || test ! -x "$kde_libs_prefix"; then
       AC_MSG_ERROR([$KDECONFIG --prefix outputed the non existant prefix '$kde_libs_prefix' for tdelibs.
                    This means it has been moved since you installed it.
                    This won't work. Please recompile tdelibs for the new prefix.
                    ])
  fi
  kde_libs_htmldir=`$KDECONFIG --install html --expandvars`

  AC_MSG_CHECKING([where to install])
  if test "x$prefix" = "xNONE"; then
    prefix=$kde_libs_prefix
    AC_MSG_RESULT([$prefix (as returned by tde-config)])
  else
    dnl --prefix was given. Compare prefixes and warn (in configure.in.bot.end) if different
    given_prefix=$prefix
    AC_MSG_RESULT([$prefix (as requested)])
  fi

  # And delete superfluous '/' to make compares easier
  prefix=`echo "$prefix" | sed 's,//*,/,g' | sed -e 's,/$,,'`
  exec_prefix=`echo "$exec_prefix" | sed 's,//*,/,g' | sed -e 's,/$,,'`
  given_prefix=`echo "$given_prefix" | sed 's,//*,/,g' | sed -e 's,/$,,'`

  AC_SUBST(KDECONFIG)
  AC_SUBST(kde_libs_prefix)
  AC_SUBST(kde_libs_htmldir)

  KDE_FAST_CONFIGURE
  KDE_CONF_FILES
])

pushdef([AC_PROG_INSTALL],
[
  dnl our own version, testing for a -p flag
  popdef([AC_PROG_INSTALL])
  dnl as AC_PROG_INSTALL works as it works we first have
  dnl to save if the user didn't specify INSTALL, as the
  dnl autoconf one overwrites INSTALL and we have no chance to find
  dnl out afterwards
  test -n "$INSTALL" && kde_save_INSTALL_given=$INSTALL
  test -n "$INSTALL_PROGRAM" && kde_save_INSTALL_PROGRAM_given=$INSTALL_PROGRAM
  test -n "$INSTALL_SCRIPT" && kde_save_INSTALL_SCRIPT_given=$INSTALL_SCRIPT
  AC_PROG_INSTALL

  if test -z "$kde_save_INSTALL_given" ; then
    # OK, user hasn't given any INSTALL, autoconf found one for us
    # now we test, if it supports the -p flag
    AC_MSG_CHECKING(for -p flag to install)
    rm -f confinst.$$.* > /dev/null 2>&1
    echo "Testtest" > confinst.$$.orig
    ac_res=no
    if ${INSTALL} -p confinst.$$.orig confinst.$$.new > /dev/null 2>&1 ; then
      if test -f confinst.$$.new ; then
        # OK, -p seems to do no harm to install
	INSTALL="${INSTALL} -p"
	ac_res=yes
      fi
    fi
    rm -f confinst.$$.*
    AC_MSG_RESULT($ac_res)
  fi
  dnl the following tries to resolve some signs and wonders coming up
  dnl with different autoconf/automake versions
  dnl e.g.:
  dnl  *automake 1.4 install-strip sets A_M_INSTALL_PROGRAM_FLAGS to -s
  dnl   and has INSTALL_PROGRAM = @INSTALL_PROGRAM@ $(A_M_INSTALL_PROGRAM_FLAGS)
  dnl   it header-vars.am, so there the actual INSTALL_PROGRAM gets the -s
  dnl  *automake 1.4a (and above) use INSTALL_STRIP_FLAG and only has
  dnl   INSTALL_PROGRAM = @INSTALL_PROGRAM@ there, but changes the
  dnl   install-@DIR@PROGRAMS targets to explicitly use that flag
  dnl  *autoconf 2.13 is dumb, and thinks it can use INSTALL_PROGRAM as
  dnl   INSTALL_SCRIPT, which breaks with automake <= 1.4
  dnl  *autoconf >2.13 (since 10.Apr 1999) has not that failure
  dnl  *sometimes TDE does not use the install-@DIR@PROGRAM targets from
  dnl   automake (due to broken Makefile.am or whatever) to install programs,
  dnl   and so does not see the -s flag in automake > 1.4
  dnl to clean up that mess we:
  dnl  +set INSTALL_PROGRAM to use INSTALL_STRIP_FLAG
  dnl   which cleans KDE's program with automake > 1.4;
  dnl  +set INSTALL_SCRIPT to only use INSTALL, to clean up autoconf's problems
  dnl   with automake<=1.4
  dnl  note that dues to this sometimes two '-s' flags are used (if KDE
  dnl   properly uses install-@DIR@PROGRAMS, but I don't care
  dnl
  dnl And to all this comes, that I even can't write in comments variable
  dnl  names used by automake, because it is so stupid to think I wanted to
  dnl  _use_ them, therefor I have written A_M_... instead of AM_
  dnl hmm, I wanted to say something ... ahh yes: Arghhh.

  if test -z "$kde_save_INSTALL_PROGRAM_given" ; then
    INSTALL_PROGRAM='${INSTALL} $(INSTALL_STRIP_FLAG)'
  fi
  if test -z "$kde_save_INSTALL_SCRIPT_given" ; then
    INSTALL_SCRIPT='${INSTALL}'
  fi
])dnl

AC_DEFUN([KDE_LANG_CPLUSPLUS],
[AC_LANG_CPLUSPLUS
ac_link='rm -rf SunWS_cache; ${CXX-g++} -o conftest${ac_exeext} $CXXFLAGS $CPPFLAGS $LDFLAGS conftest.$ac_ext $LIBS 1>&AC_FD_CC'
pushdef([AC_LANG_CPLUSPLUS], [popdef([AC_LANG_CPLUSPLUS]) KDE_LANG_CPLUSPLUS])
])

pushdef([AC_LANG_CPLUSPLUS],
[popdef([AC_LANG_CPLUSPLUS])
KDE_LANG_CPLUSPLUS
])

AC_DEFUN([KDE_CHECK_LONG_LONG],
[
AC_MSG_CHECKING(for long long)
AC_CACHE_VAL(kde_cv_c_long_long,
[
  AC_LANG_SAVE
  AC_LANG_CPLUSPLUS
  AC_TRY_LINK([], [
  long long foo = 0;
  foo = foo+1;
  ],
  kde_cv_c_long_long=yes, kde_cv_c_long_long=no)
  AC_LANG_RESTORE
])
AC_MSG_RESULT($kde_cv_c_long_long)
if test "$kde_cv_c_long_long" = yes; then
   AC_DEFINE(HAVE_LONG_LONG, 1, [Define if you have long long as datatype])
fi
])

AC_DEFUN([KDE_CHECK_LIB],
[
     kde_save_LDFLAGS="$LDFLAGS"
     dnl AC_CHECK_LIB modifies LIBS, so save it here
     kde_save_LIBS="$LIBS"
     LDFLAGS="$LDFLAGS $all_libraries -ltqt"
     case $host_os in
      aix*) LDFLAGS="-brtl $LDFLAGS"
	test "$GCC" = yes && LDFLAGS="-Wl,$LDFLAGS"
	;;
     esac
     AC_CHECK_LIB($1, $2, $3, $4, $5)
     LDFLAGS="$kde_save_LDFLAGS"
     LIBS="$kde_save_LIBS"
])

AC_DEFUN([KDE_JAVA_PREFIX],
[
	dir=`dirname "$1"`
	base=`basename "$1"`
	list=`ls -1 $dir 2> /dev/null`
	for entry in $list; do 
		if test -d $dir/$entry/bin; then
			case $entry in
			   $base)
				javadirs="$javadirs $dir/$entry/bin"
				;;
			esac
		elif test -d $dir/$entry/jre/bin; then
			case $entry in
			   $base)
				javadirs="$javadirs $dir/$entry/jre/bin"
				;;
			esac
		fi
	done
])

dnl KDE_CHEC_JAVA_DIR(onlyjre)
AC_DEFUN([KDE_CHECK_JAVA_DIR],
[

AC_ARG_WITH(java,
AC_HELP_STRING([--with-java=javadir],[use java installed in javadir, --without-java disables]),
[  ac_java_dir=$withval
], ac_java_dir=""
)

AC_MSG_CHECKING([for Java])

dnl at this point ac_java_dir is either a dir, 'no' to disable, or '' to say look in $PATH
if test "x$ac_java_dir" = "xno"; then
   kde_java_bindir=no
   kde_java_includedir=no
   kde_java_libjvmdir=no
   kde_java_libgcjdir=no
   kde_java_libhpidir=no
else
  if test "x$ac_java_dir" = "x"; then
     
     
      dnl No option set -> collect list of candidate paths
      if test -n "$JAVA_HOME"; then
        KDE_JAVA_PREFIX($JAVA_HOME)
      fi
      KDE_JAVA_PREFIX(/usr/j2se)
      KDE_JAVA_PREFIX(/usr/lib/j2se)
      KDE_JAVA_PREFIX(/usr/j*dk*)
      KDE_JAVA_PREFIX(/usr/lib/j*dk*)
      KDE_JAVA_PREFIX(/opt/j*sdk*)
      KDE_JAVA_PREFIX(/usr/lib/java*)
      KDE_JAVA_PREFIX(/usr/java*)
      KDE_JAVA_PREFIX(/usr/java/j*dk*)
      KDE_JAVA_PREFIX(/usr/java/j*re*)
      KDE_JAVA_PREFIX(/usr/lib/SunJava2*)
      KDE_JAVA_PREFIX(/usr/lib/SunJava*)
      KDE_JAVA_PREFIX(/usr/lib/IBMJava2*)
      KDE_JAVA_PREFIX(/usr/lib/IBMJava*)
      KDE_JAVA_PREFIX(/opt/java*)

      kde_cv_path="NONE"
      kde_save_IFS=$IFS
      IFS=':'
      for dir in $PATH; do
	  if test -d "$dir"; then
	      javadirs="$javadirs $dir"
	  fi
      done
      IFS=$kde_save_IFS
      jredirs=

      dnl Now javadirs contains a list of paths that exist, all ending with bin/
      for dir in $javadirs; do
          dnl Check for the java executable
	  if test -x "$dir/java"; then
	      sane_path=$(cd $dir; /bin/pwd)
	      dnl And also check for a libjvm.so somewhere under there
	      dnl Since we have to go to the parent dir, /usr/bin is excluded, /usr is too big.
              if test "$sane_path" != "/usr/bin"; then
                  libjvmdir=`find $dir/.. -name libjvm.so | sed 's,libjvm.so,,'|head -n 1`
		  if test ! -f $libjvmdir/libjvm.so; then continue; fi
		  jredirs="$jredirs $dir"
	      fi
	  fi
      done

      dnl Now jredirs contains a reduced list, of paths where both java and ../**/libjvm.so was found
      JAVAC=
      JAVA=
      kde_java_bindir=no
      for dir in $jredirs; do
	  JAVA="$dir/java"
	  kde_java_bindir=$dir
	  if test -x "$dir/javac"; then
		JAVAC="$dir/javac"
                break
	  fi
      done

      if test -n "$JAVAC"; then
          dnl this substitution might not work - well, we test for jni.h below
          kde_java_includedir=`echo $JAVAC | sed -e 's,bin/javac$,include/,'`
      else
          kde_java_includedir=no
      fi
  else
    dnl config option set
    kde_java_bindir=$ac_java_dir/bin
    if test -x $ac_java_dir/bin/java && test ! -x $ac_java_dir/bin/javac; then
	kde_java_includedir=no
    else
        kde_java_includedir=$ac_java_dir/include
    fi
  fi
fi

dnl At this point kde_java_bindir and kde_java_includedir are either set or "no"
if test "x$kde_java_bindir" != "xno"; then

  dnl Look for libjvm.so
  kde_java_libjvmdir=`find $kde_java_bindir/.. -name libjvm.so | sed 's,libjvm.so,,'|head -n 1`
  dnl Look for libgcj.so
  kde_java_libgcjdir=`find $kde_java_bindir/.. -name libgcj.so | sed 's,libgcj.so,,'|head -n 1`
  dnl Look for libhpi.so and avoid green threads
  kde_java_libhpidir=`find $kde_java_bindir/.. -name libhpi.so | grep -v green | sed 's,libhpi.so,,' | head -n 1`

  dnl Now check everything's fine under there
  dnl the include dir is our flag for having the JDK
  if test -d "$kde_java_includedir"; then
    if test ! -x "$kde_java_bindir/javac"; then
      AC_MSG_ERROR([javac not found under $kde_java_bindir - it seems you passed a wrong --with-java.])
    fi
    if test ! -x "$kde_java_bindir/javah"; then
      AC_MSG_ERROR([javah not found under $kde_java_bindir. javac was found though! Use --with-java or --without-java.])
    fi
    if test ! -x "$kde_java_bindir/jar"; then
      AC_MSG_ERROR([jar not found under $kde_java_bindir. javac was found though! Use --with-java or --without-java.])
    fi
    if test ! -r "$kde_java_includedir/jni.h"; then
      AC_MSG_ERROR([jni.h not found under $kde_java_includedir. Use --with-java or --without-java.])
    fi

    jni_includes="-I$kde_java_includedir"
    dnl Strange thing, jni.h requires jni_md.h which is under genunix here..
    dnl and under linux here.. 
    
    dnl not needed for gcj

    if test "x$kde_java_libgcjdir" = "x"; then 
      test -d "$kde_java_includedir/linux" && jni_includes="$jni_includes -I$kde_java_includedir/linux"
      test -d "$kde_java_includedir/solaris" && jni_includes="$jni_includes -I$kde_java_includedir/solaris"
      test -d "$kde_java_includedir/genunix" && jni_includes="$jni_includes -I$kde_java_includedir/genunix"
    fi

  else
    JAVAC=
    jni_includes=
  fi

  if test "x$kde_java_libgcjdir" = "x"; then 
     if test ! -r "$kde_java_libjvmdir/libjvm.so"; then
        AC_MSG_ERROR([libjvm.so not found under $kde_java_libjvmdir. Use --without-java.])
     fi 
  else
     if test ! -r "$kde_java_libgcjdir/libgcj.so"; then
        AC_MSG_ERROR([libgcj.so not found under $kde_java_libgcjdir. Use --without-java.])
     fi 
  fi

  if test ! -x "$kde_java_bindir/java"; then
      AC_MSG_ERROR([java not found under $kde_java_bindir. javac was found though! Use --with-java or --without-java.])
  fi

  dnl not needed for gcj compile

  if test -n "$jni_includes"; then
    dnl Check for JNI version
    AC_LANG_SAVE
    AC_LANG_CPLUSPLUS
    ac_cxxflags_safe="$CXXFLAGS"
    CXXFLAGS="$CXXFLAGS $all_includes $jni_includes"

    AC_TRY_COMPILE([
  #include <jni.h>
	      ],
	      [
  #ifndef JNI_VERSION_1_2
  Syntax Error
  #endif
	      ],[ kde_jni_works=yes ],
	      [ kde_jni_works=no ])

    if test $kde_jni_works = no; then
      AC_MSG_ERROR([Incorrect version of $kde_java_includedir/jni.h.
		    You need to have Java Development Kit (JDK) version 1.2. 

		    Use --with-java to specify another location.
		    Use --without-java to configure without java support.
		    Or download a newer JDK and try again. 
		    See e.g. http://java.sun.com/products/jdk/1.2 ])
    fi

    CXXFLAGS="$ac_cxxflags_safe"    
    AC_LANG_RESTORE

    dnl All tests ok, inform and subst the variables

    JAVAC=$kde_java_bindir/javac
    JAVAH=$kde_java_bindir/javah
    JAR=$kde_java_bindir/jar
    AC_DEFINE_UNQUOTED(PATH_JAVA, "$kde_java_bindir/java", [Define where your java executable is])
    if test "x$kde_java_libgcjdir" = "x"; then
      if test ! -r "$kde_java_libhpidir/libhpi.so"; then
        JVMLIBS="-L$kde_java_libjvmdir -ljvm"
      else
        JVMLIBS="-L$kde_java_libjvmdir -ljvm -L$kde_java_libhpidir -lhpi"
      fi
    else
      JVMLIBS="-L$kde_java_libgcjdir -lgcj"
    fi
    AC_MSG_RESULT([java JDK in $kde_java_bindir])

  else
      AC_DEFINE_UNQUOTED(PATH_JAVA, "$kde_java_bindir/java", [Define where your java executable is])
      AC_MSG_RESULT([java JRE in $kde_java_bindir])
  fi
elif test -d "/Library/Java/Home"; then
  kde_java_bindir="/Library/Java/Home/bin"
  jni_includes="-I/Library/Java/Home/include"

  JAVAC=$kde_java_bindir/javac
  JAVAH=$kde_java_bindir/javah
  JAR=$kde_java_bindir/jar
  JVMLIBS="-Wl,-framework,JavaVM"

  AC_DEFINE_UNQUOTED(PATH_JAVA, "$kde_java_bindir/java", [Define where your java executable is])
  AC_MSG_RESULT([Apple Java Framework])
else
  AC_MSG_RESULT([none found])
fi

AC_SUBST(JAVAC)
AC_SUBST(JAVAH)
AC_SUBST(JAR)
AC_SUBST(JVMLIBS)
AC_SUBST(jni_includes)

# for backward compat
kde_cv_java_includedir=$kde_java_includedir
kde_cv_java_bindir=$kde_java_bindir
])

dnl this is a redefinition of autoconf 2.5x's AC_FOREACH.
dnl When the argument list becomes big, as in TDE for AC_OUTPUT in
dnl big packages, m4_foreach is dog-slow.  So use our own version of
dnl it.  (matz@kde.org)
m4_define([mm_foreach],
[m4_pushdef([$1])_mm_foreach($@)m4_popdef([$1])])
m4_define([mm_car], [[$1]])
m4_define([mm_car2], [[$@]])
m4_define([_mm_foreach],
[m4_if(m4_quote($2), [], [],
       [m4_define([$1], mm_car($2))$3[]_mm_foreach([$1],
                                                   mm_car2(m4_shift($2)),
                                                   [$3])])])
m4_define([AC_FOREACH],
[mm_foreach([$1], m4_split(m4_normalize([$2])), [$3])])

# AH_CHECK_HEADERS_TDE(HEADER-FILE...)
# --------------------------------
m4_define([AH_CHECK_HEADERS_TDE],
[m4_foreach_w([AC_Header], [$1],
  [AH_TEMPLATE(AS_TR_CPP([HAVE_]m4_defn([AC_Header])),
     [Define to 1 if you have the <]m4_defn([AC_Header])[> header file.])])])

AC_DEFUN([KDE_NEED_FLEX],
[
kde_libs_safe=$LIBS
LIBS="$LIBS $USER_LDFLAGS"
AM_PROG_LEX
LIBS=$kde_libs_safe
if test -z "$LEXLIB"; then
    AC_MSG_ERROR([You need to have flex installed.])
fi
AC_SUBST(LEXLIB)
])

AC_DEFUN([AC_PATH_QTOPIA],
[
  dnl TODO: use AC_CACHE_VAL

  if test -z "$1"; then
    qtopia_minver_maj=1
    qtopia_minver_min=5
    qtopia_minver_pat=0
  else
    qtopia_minver_maj=`echo "$1" | sed -e "s/^\(.*\)\..*\..*$/\1/"`
    qtopia_minver_min=`echo "$1" | sed -e "s/^.*\.\(.*\)\..*$/\1/"`
    qtopia_minver_pat=`echo "$1" | sed -e "s/^.*\..*\.\(.*\)$/\1/"`
  fi

  qtopia_minver="$qtopia_minver_maj$qtopia_minver_min$qtopia_minver_pat"
  qtopia_minverstr="$qtopia_minver_maj.$qtopia_minver_min.$qtopia_minver_pat"

  AC_REQUIRE([AC_PATH_QT])

  AC_MSG_CHECKING([for Qtopia])

  LIB_QTOPIA="-lqpe"
  AC_SUBST(LIB_QTOPIA)

  kde_qtopia_dirs="$QPEDIR /opt/Qtopia"

  ac_qtopia_incdir=NO

  AC_ARG_WITH(qtopia-dir,
              AC_HELP_STRING([--with-qtopia-dir=DIR],[where the root of Qtopia is installed]),
              [  ac_qtopia_incdir="$withval"/include] ) 
  
  qtopia_incdirs=""
  for dir in $kde_qtopia_dirs; do
    qtopia_incdirs="$qtopia_incdirs $dir/include"
  done

  if test ! "$ac_qtopia_incdir" = "NO"; then
    qtopia_incdirs="$ac_qtopia_incdir $qtopia_incdirs"
  fi

  qtopia_incdir=""
  AC_FIND_FILE(qpe/qpeapplication.h, $qtopia_incdirs, qtopia_incdir)
  ac_qtopia_incdir="$qtopia_incdir"

  if test -z "$qtopia_incdir"; then
    AC_MSG_ERROR([Cannot find Qtopia headers. Please check your installation.])
  fi

  qtopia_ver_maj=`cat $qtopia_incdir/qpe/version.h | sed -n -e 's,.*QPE_VERSION "\(.*\)\..*\..*".*,\1,p'`;
  qtopia_ver_min=`cat $qtopia_incdir/qpe/version.h | sed -n -e 's,.*QPE_VERSION ".*\.\(.*\)\..*".*,\1,p'`;
  qtopia_ver_pat=`cat $qtopia_incdir/qpe/version.h | sed -n -e 's,.*QPE_VERSION ".*\..*\.\(.*\)".*,\1,p'`;

  qtopia_ver="$qtopia_ver_maj$qtopia_ver_min$qtopia_ver_pat"
  qtopia_verstr="$qtopia_ver_maj.$qtopia_ver_min.$qtopia_ver_pat"
  if test "$qtopia_ver" -lt "$qtopia_minver"; then
    AC_MSG_ERROR([found Qtopia version $qtopia_verstr but version $qtopia_minverstr
is required.])
  fi

  AC_LANG_SAVE
  AC_LANG_CPLUSPLUS

  ac_cxxflags_safe="$CXXFLAGS"
  ac_ldflags_safe="$LDFLAGS"
  ac_libs_safe="$LIBS"

  CXXFLAGS="$CXXFLAGS -I$qtopia_incdir $all_includes"
  LDFLAGS="$LDFLAGS $QT_LDFLAGS $all_libraries $USER_LDFLAGS $KDE_MT_LDFLAGS"
  LIBS="$LIBS $LIB_QTOPIA $LIBQT"

  cat > conftest.$ac_ext <<EOF
#include "confdefs.h"
#include <qpe/qpeapplication.h>
#include <qpe/version.h>

int main( int argc, char **argv )
{
    QPEApplication app( argc, argv );
    return 0;
}
EOF

  if AC_TRY_EVAL(ac_link) && test -s conftest; then
    rm -f conftest*
  else
    rm -f conftest*
    AC_MSG_ERROR([Cannot link small Qtopia Application. For more details look at
the end of config.log])
  fi

  CXXFLAGS="$ac_cxxflags_safe"
  LDFLAGS="$ac_ldflags_safe"
  LIBS="$ac_libs_safe"

  AC_LANG_RESTORE

  QTOPIA_INCLUDES="-I$qtopia_incdir"
  AC_SUBST(QTOPIA_INCLUDES)

  AC_MSG_RESULT([found version $qtopia_verstr with headers at $qtopia_incdir])
])


AC_DEFUN([KDE_INIT_DOXYGEN],
[
AC_MSG_CHECKING([for Qt docs])
kde_qtdir=
if test "${with_qt_dir+set}" = set; then
  kde_qtdir="$with_qt_dir"
fi

AC_FIND_FILE(qsql.html, [ $kde_qtdir/doc/html /usr/share/doc/packages/tqt3/html /usr/share/doc/packages/qt3/html /usr/lib/qt/doc /usr/lib/tqt3/doc /usr/lib/qt3/doc /usr/lib/tqt3/doc/html /usr/lib/qt3/doc/html /usr/doc/tqt3/html /usr/doc/qt3/html /usr/doc/tqt3 /usr/doc/qt3 /usr/share/doc/tqt3-doc /usr/share/doc/qt3-doc /usr/share/tqt3/doc/html /usr/share/qt3/doc/html /usr/X11R6/share/doc/qt/html ], QTDOCDIR)
AC_MSG_RESULT($QTDOCDIR)

AC_SUBST(QTDOCDIR)

KDE_FIND_PATH(dot, DOT, [], [])
if test -n "$DOT"; then
  KDE_HAVE_DOT="YES"
else
  KDE_HAVE_DOT="NO"
fi
AC_SUBST(KDE_HAVE_DOT)
KDE_FIND_PATH(doxygen, DOXYGEN, [], [])
AC_SUBST(DOXYGEN)

DOXYGEN_PROJECT_NAME="$1"
DOXYGEN_PROJECT_NUMBER="$2"
AC_SUBST(DOXYGEN_PROJECT_NAME)
AC_SUBST(DOXYGEN_PROJECT_NUMBER)

KDE_HAS_DOXYGEN=no
if test -n "$DOXYGEN" && test -x "$DOXYGEN" && test -f $QTDOCDIR/qsql.html; then
  KDE_HAS_DOXYGEN=yes
fi
AC_SUBST(KDE_HAS_DOXYGEN)

])


AC_DEFUN([AC_FIND_BZIP2],
[
AC_MSG_CHECKING([for bzDecompress in libbz2])
AC_CACHE_VAL(ac_cv_lib_bzip2,
[
AC_LANG_SAVE
AC_LANG_CPLUSPLUS
kde_save_LIBS="$LIBS"
LIBS="$all_libraries $USER_LDFLAGS -lbz2 $LIBSOCKET"
kde_save_CXXFLAGS="$CXXFLAGS"
CXXFLAGS="$CXXFLAGS $all_includes $USER_INCLUDES"
AC_TRY_LINK(dnl
[
#define BZ_NO_STDIO
#include<bzlib.h>
],
            [ bz_stream s; (void) bzDecompress(&s); ],
            eval "ac_cv_lib_bzip2='-lbz2'",
            eval "ac_cv_lib_bzip2=no")
LIBS="$kde_save_LIBS"
CXXFLAGS="$kde_save_CXXFLAGS"
AC_LANG_RESTORE
])dnl
AC_MSG_RESULT($ac_cv_lib_bzip2)

if test ! "$ac_cv_lib_bzip2" = no; then
  BZIP2DIR=bzip2

  LIBBZ2="$ac_cv_lib_bzip2"
  AC_SUBST(LIBBZ2)

else

   cxx_shared_flag=
   ld_shared_flag=
   KDE_CHECK_COMPILER_FLAG(shared, [
	ld_shared_flag="-shared"
   ])
   KDE_CHECK_COMPILER_FLAG(fPIC, [
        cxx_shared_flag="-fPIC"
   ])

   AC_MSG_CHECKING([for BZ2_bzDecompress in (shared) libbz2])
   AC_CACHE_VAL(ac_cv_lib_bzip2_prefix,
   [
   AC_LANG_SAVE
   AC_LANG_CPLUSPLUS
   kde_save_LIBS="$LIBS"
   LIBS="$all_libraries $USER_LDFLAGS $ld_shared_flag -lbz2 $LIBSOCKET"
   kde_save_CXXFLAGS="$CXXFLAGS"
   CXXFLAGS="$CFLAGS $cxx_shared_flag $all_includes $USER_INCLUDES"

   AC_TRY_LINK(dnl
   [
   #define BZ_NO_STDIO
   #include<bzlib.h>
   ],
               [ bz_stream s; (void) BZ2_bzDecompress(&s); ],
               eval "ac_cv_lib_bzip2_prefix='-lbz2'",
               eval "ac_cv_lib_bzip2_prefix=no")
   LIBS="$kde_save_LIBS"
   CXXFLAGS="$kde_save_CXXFLAGS"
   AC_LANG_RESTORE
   ])dnl

   AC_MSG_RESULT($ac_cv_lib_bzip2_prefix)
   
   if test ! "$ac_cv_lib_bzip2_prefix" = no; then
     BZIP2DIR=bzip2
    
     LIBBZ2="$ac_cv_lib_bzip2_prefix"
     AC_SUBST(LIBBZ2)

     AC_DEFINE(NEED_BZ2_PREFIX, 1, [Define if the libbz2 functions need the BZ2_ prefix])
   dnl else, we just ignore this
   fi

fi
AM_CONDITIONAL(include_BZIP2, test -n "$BZIP2DIR")
])

dnl ------------------------------------------------------------------------
dnl Try to find the SSL headers and libraries.
dnl $(SSL_LDFLAGS) will be -Lsslliblocation (if needed)
dnl and $(SSL_INCLUDES) will be -Isslhdrlocation (if needed)
dnl ------------------------------------------------------------------------
dnl
AC_DEFUN([KDE_CHECK_SSL],
[
LIBSSL="-lssl -lcrypto"
AC_REQUIRE([KDE_CHECK_LIB64])

ac_ssl_includes=NO ac_ssl_libraries=NO
ssl_libraries=""
ssl_includes=""
AC_ARG_WITH(ssl-dir,
    AC_HELP_STRING([--with-ssl-dir=DIR],[where the root of OpenSSL is installed]),
    [  ac_ssl_includes="$withval"/include
       ac_ssl_libraries="$withval"/lib$tdelibsuff
    ])

want_ssl=yes
AC_ARG_WITH(ssl,
    AC_HELP_STRING([--without-ssl],[disable SSL checks]),
    [want_ssl=$withval])

if test $want_ssl = yes; then

AC_MSG_CHECKING(for OpenSSL)

AC_CACHE_VAL(ac_cv_have_ssl,
[#try to guess OpenSSL locations
  
  ssl_incdirs="/usr/include /usr/local/include /usr/ssl/include /usr/local/ssl/include $prefix/include $kde_extra_includes"
  ssl_incdirs="$ac_ssl_includes $ssl_incdirs"
  AC_FIND_FILE(openssl/ssl.h, $ssl_incdirs, ssl_incdir)
  ac_ssl_includes="$ssl_incdir"

  ssl_libdirs="/usr/lib$tdelibsuff /usr/local/lib$tdelibsuff /usr/ssl/lib$tdelibsuff /usr/local/ssl/lib$tdelibsuff $libdir $prefix/lib$tdelibsuff $exec_prefix/lib$tdelibsuff $kde_extra_libs"
  if test ! "$ac_ssl_libraries" = "NO"; then
    ssl_libdirs="$ac_ssl_libraries $ssl_libdirs"
  fi

  test=NONE
  ssl_libdir=NONE
  for dir in $ssl_libdirs; do
    try="ls -1 $dir/libssl*"
    if test=`eval $try 2> /dev/null`; then ssl_libdir=$dir; break; else echo "tried $dir" >&AC_FD_CC ; fi
  done

  ac_ssl_libraries="$ssl_libdir"

  ac_ldflags_safe="$LDFLAGS"
  ac_libs_safe="$LIBS"

  LDFLAGS="$LDFLAGS -L$ssl_libdir $all_libraries"
  LIBS="$LIBS $LIBSSL -lRSAglue -lrsaref"

  AC_TRY_LINK(,void RSAPrivateEncrypt(void);RSAPrivateEncrypt();,
  ac_ssl_rsaref="yes"
  ,
  ac_ssl_rsaref="no"
  )

  LDFLAGS="$ac_ldflags_safe"
  LIBS="$ac_libs_safe"

  if test "$ac_ssl_includes" = NO || test "$ac_ssl_libraries" = NO; then
    have_ssl=no
  else
    have_ssl=yes;
  fi

  ])

  eval "$ac_cv_have_ssl"

  AC_MSG_RESULT([libraries $ac_ssl_libraries, headers $ac_ssl_includes])

  AC_MSG_CHECKING([whether OpenSSL uses rsaref])
  AC_MSG_RESULT($ac_ssl_rsaref)

  AC_MSG_CHECKING([for easter eggs])
  AC_MSG_RESULT([none found])

else
  have_ssl=no
fi

if test "$have_ssl" = yes; then
  AC_MSG_CHECKING(for OpenSSL version)
  dnl Check for SSL version
  AC_CACHE_VAL(ac_cv_ssl_version,
  [

    cat >conftest.$ac_ext <<EOF
#include <openssl/opensslv.h>
#include <stdio.h>
    int main() {
 
#ifndef OPENSSL_VERSION_NUMBER
      printf("ssl_version=\\"error\\"\n");
#else
      if (OPENSSL_VERSION_NUMBER < 0x00906000)
        printf("ssl_version=\\"old\\"\n");
      else
        printf("ssl_version=\\"ok\\"\n");
#endif
     return (0);
    }
EOF

    ac_save_CPPFLAGS=$CPPFLAGS
    if test "$ac_ssl_includes" != "/usr/include"; then
        CPPFLAGS="$CPPFLAGS -I$ac_ssl_includes"
    fi

    if AC_TRY_EVAL(ac_link); then 

      if eval `./conftest 2>&5`; then
        if test $ssl_version = error; then
          AC_MSG_ERROR([$ssl_incdir/openssl/opensslv.h doesn't define OPENSSL_VERSION_NUMBER !])
        else
          if test $ssl_version = old; then
            AC_MSG_WARN([OpenSSL version too old. Upgrade to 0.9.6 at least, see http://www.openssl.org. SSL support disabled.])
            have_ssl=no
          fi
        fi
        ac_cv_ssl_version="ssl_version=$ssl_version"
      else
        AC_MSG_ERROR([Your system couldn't run a small SSL test program.
        Check config.log, and if you can't figure it out, send a mail to 
        David Faure <faure@kde.org>, attaching your config.log])
      fi

    else
      AC_MSG_ERROR([Your system couldn't link a small SSL test program.
      Check config.log, and if you can't figure it out, send a mail to 
      David Faure <faure@kde.org>, attaching your config.log])
    fi 
    CPPFLAGS=$ac_save_CPPFLAGS

  ])

  eval "$ac_cv_ssl_version"
  AC_MSG_RESULT($ssl_version)
fi

if test "$have_ssl" != yes; then
  LIBSSL="";
else
  AC_DEFINE(HAVE_SSL, 1, [If we are going to use OpenSSL])
  ac_cv_have_ssl="have_ssl=yes \
    ac_ssl_includes=$ac_ssl_includes ac_ssl_libraries=$ac_ssl_libraries ac_ssl_rsaref=$ac_ssl_rsaref"
  
  
  ssl_libraries="$ac_ssl_libraries"
  ssl_includes="$ac_ssl_includes"

  if test "$ac_ssl_rsaref" = yes; then
    LIBSSL="-lssl -lcrypto -lRSAglue -lrsaref" 
  fi

  if test $ssl_version = "old"; then
    AC_DEFINE(HAVE_OLD_SSL_API, 1, [Define if you have OpenSSL < 0.9.6])
  fi
fi

SSL_INCLUDES=

if test "$ssl_includes" = "/usr/include"; then
  if test -f /usr/kerberos/include/krb5.h; then
	SSL_INCLUDES="-I/usr/kerberos/include"
  fi
elif test  "$ssl_includes" != "/usr/local/include" && test -n "$ssl_includes"; then
  SSL_INCLUDES="-I$ssl_includes"
fi

if test "$ssl_libraries" = "/usr/lib" || test "$ssl_libraries" = "/usr/local/lib" || test -z "$ssl_libraries" || test "$ssl_libraries" = "NONE"; then
 SSL_LDFLAGS=""
else
 SSL_LDFLAGS="-L$ssl_libraries -R$ssl_libraries"
fi

AC_SUBST(SSL_INCLUDES)
AC_SUBST(SSL_LDFLAGS)
AC_SUBST(LIBSSL)
])

AC_DEFUN([KDE_CHECK_STRLCPY],
[
  AC_REQUIRE([AC_CHECK_STRLCAT])
  AC_REQUIRE([AC_CHECK_STRLCPY])
  AC_CHECK_SIZEOF(size_t)
  AC_CHECK_SIZEOF(unsigned long)

  AC_MSG_CHECKING([sizeof size_t == sizeof unsigned long])
  AC_TRY_COMPILE(,[
    #if SIZEOF_SIZE_T != SIZEOF_UNSIGNED_LONG
       choke me
    #endif
    ],AC_MSG_RESULT([yes]),[
      AC_MSG_RESULT(no)
      AC_MSG_ERROR([
       Apparently on your system our assumption sizeof size_t == sizeof unsigned long 
       does not apply. Please mail kde-devel@kde.org with a description of your system!
      ])
  ])
])

AC_DEFUN([KDE_CHECK_BINUTILS],
[
  AC_MSG_CHECKING([if ld supports unversioned version maps])

  kde_save_LDFLAGS="$LDFLAGS"
  LDFLAGS="$LDFLAGS -Wl,--version-script=conftest.map"
  echo "{ local: extern \"C++\" { foo }; };" > conftest.map
  AC_TRY_LINK([int foo;],
[
#ifdef __INTEL_COMPILER
icc apparently does not support libtools version-info and version-script
at the same time. Dunno where the bug is, but until somebody figured out,
better disable the optional version scripts.
#endif

  foo = 42;
], kde_supports_versionmaps=yes, kde_supports_versionmaps=no)
  LDFLAGS="$kde_save_LDFLAGS"
  rm -f conftest.map
  AM_CONDITIONAL(include_VERSION_SCRIPT, 
    [test "$kde_supports_versionmaps" = "yes" && test "$kde_use_debug_code" = "no"])

  AC_MSG_RESULT($kde_supports_versionmaps)
])

AC_DEFUN([AM_PROG_OBJC],[
AC_CHECK_PROGS(OBJC, gcc, gcc)
test -z "$OBJC" && AC_MSG_ERROR([no acceptable objective-c gcc found in \$PATH])
if test "x${OBJCFLAGS-unset}" = xunset; then
   OBJCFLAGS="-g -O2"
fi
AC_SUBST(OBJCFLAGS)
_AM_IF_OPTION([no-dependencies],, [_AM_DEPENDENCIES(OBJC)])
])

AC_DEFUN([KDE_CHECK_PERL],
[
	KDE_FIND_PATH(perl, PERL, [$bindir $exec_prefix/bin $prefix/bin], [
		    AC_MSG_ERROR([No Perl found in your $PATH.
We need perl to generate some code.])
	])
    AC_SUBST(PERL)
])

AC_DEFUN([KDE_CHECK_LARGEFILE],
[
AC_SYS_LARGEFILE
if test "$ac_cv_sys_file_offset_bits" != no; then
  CPPFLAGS="$CPPFLAGS -D_FILE_OFFSET_BITS=$ac_cv_sys_file_offset_bits"
fi

if test "x$ac_cv_sys_large_files" != "xno"; then
  CPPFLAGS="$CPPFLAGS -D_LARGE_FILES=1"
fi

])

dnl A small extension to PKG_CHECK_MODULES (defined in pkg.m4.in)
dnl which allows to search for libs that get installed into the TDE prefix.
dnl
dnl Syntax:  KDE_PKG_CHECK_MODULES(KSTUFF, libkexif >= 0.2 glib = 1.3.4, action-if, action-not)
dnl defines KSTUFF_LIBS, KSTUFF_CFLAGS, see pkg-config man page
dnl also defines KSTUFF_PKG_ERRORS on error
AC_DEFUN([KDE_PKG_CHECK_MODULES], [

   PKG_CONFIG_PATH="$prefix/lib${tdelibsuff}/pkgconfig:$PKG_CONFIG_PATH"
   if test "$prefix" != "$kde_libs_prefix"; then
       PKG_CONFIG_PATH="$kde_libs_prefix/lib${tdelibsuff}/pkgconfig:$PKG_CONFIG_PATH"
   fi
   export PKG_CONFIG_PATH
   PKG_CHECK_MODULES([$1],[$2],[$3],[$4])
])


dnl Check for PIE support in the compiler and linker
AC_DEFUN([KDE_CHECK_PIE_SUPPORT],
[
  AC_CACHE_CHECK([for PIE support], kde_cv_val_pie_support,
  [
    AC_LANG_SAVE
    AC_LANG_CPLUSPLUS
    safe_CXXFLAGS=$CXXFLAGS
    safe_LDFLAGS=$LDFLAGS
    CXXFLAGS="$CXXFLAGS -fPIE"
    LDFLAGS="$LDFLAGS -pie"

    AC_TRY_LINK([int foo;], [], [kde_cv_val_pie_support=yes], [kde_cv_val_pie_support=no])

    CXXFLAGS=$safe_CXXFLAGS
    LDFLAGS=$safe_LDFLAGS
    AC_LANG_RESTORE
  ])

  AC_MSG_CHECKING(if enabling -pie/fPIE support)

  AC_ARG_ENABLE(pie,
    AC_HELP_STRING([--enable-pie],[platform supports PIE linking [default=detect]]),
      [kde_has_pie_support=$enableval],
      [kde_has_pie_support=detect])

  if test "$kde_has_pie_support" = "detect"; then
    kde_has_pie_support=$kde_cv_val_pie_support
  fi

  AC_MSG_RESULT([$kde_has_pie_support])

  KDE_USE_FPIE=""
  KDE_USE_PIE=""

  AC_SUBST([KDE_USE_FPIE])
  AC_SUBST([KDE_USE_PIE])

  if test "$kde_has_pie_support" = "yes"; then
    KDE_USE_FPIE="-fPIE"
    KDE_USE_PIE="-pie"
  fi
])

dnl
dnl AM_PATH_CPPUNIT(MINIMUM-VERSION, [ACTION-IF-FOUND [, ACTION-IF-NOT-FOUND]])
dnl
AC_DEFUN([AM_PATH_CPPUNIT],
[

AC_ARG_WITH(cppunit-prefix,[  --with-cppunit-prefix=PFX   Prefix where CppUnit is installed (optional)],
            cppunit_config_prefix="$withval", cppunit_config_prefix="")
AC_ARG_WITH(cppunit-exec-prefix,[  --with-cppunit-exec-prefix=PFX  Exec prefix where CppUnit is installed (optional)],
            cppunit_config_exec_prefix="$withval", cppunit_config_exec_prefix="")
AC_MSG_CHECKING(if CPPUNIT tests should be built (default=yes))
AC_ARG_ENABLE(cppunit,
              [  --disable-cppunit       Do not try to build with CPPUNIT tests],,
              enable_cppunit=yes)
AC_MSG_RESULT($enable_cppunit)

if test "x$enable_cppunit" = "xyes"; then

  AC_MSG_CHECKING(if unit-tests requiring an online connection should be built (default=no))
  AC_ARG_ENABLE(online_tests,
              [  --enable-online-tests   Include online tests with CPPUNIT tests],,
              enable_online_tests=no)
  AC_MSG_RESULT($enable_online_tests)

  if test x$cppunit_config_exec_prefix != x ; then
     cppunit_config_args="$cppunit_config_args --exec-prefix=$cppunit_config_exec_prefix"
     if test x${CPPUNIT_CONFIG+set} != xset ; then
        CPPUNIT_CONFIG=$cppunit_config_exec_prefix/bin/cppunit-config
     fi
  fi
  if test x$cppunit_config_prefix != x ; then
     cppunit_config_args="$cppunit_config_args --prefix=$cppunit_config_prefix"
     if test x${CPPUNIT_CONFIG+set} != xset ; then
        CPPUNIT_CONFIG=$cppunit_config_prefix/bin/cppunit-config
     fi
  fi

  AC_PATH_PROG(CPPUNIT_CONFIG, cppunit-config, no)
  cppunit_version_min=$1

  AC_MSG_CHECKING(for CPPUNIT - version >= $cppunit_version_min)
  no_cppunit=""
  if test "$CPPUNIT_CONFIG" = "no" ; then
    AC_MSG_RESULT(no)
    AC_MSG_WARN(Unable to locate cppunit-config. Tests will not be built)
    no_cppunit=yes
  else
    CPPUNIT_CFLAGS=`$CPPUNIT_CONFIG --cflags`
    CPPUNIT_LIBS=`$CPPUNIT_CONFIG --libs`
    cppunit_version=`$CPPUNIT_CONFIG --version`

    cppunit_major_version=`echo $cppunit_version | \
           sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\1/'`
    cppunit_minor_version=`echo $cppunit_version | \
           sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\2/'`
    cppunit_micro_version=`echo $cppunit_version | \
           sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\3/'`

    cppunit_major_min=`echo $cppunit_version_min | \
           sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\1/'`
    cppunit_minor_min=`echo $cppunit_version_min | \
           sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\2/'`
    cppunit_micro_min=`echo $cppunit_version_min | \
           sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\3/'`

    cppunit_version_proper=`expr \
        $cppunit_major_version \> $cppunit_major_min \| \
        $cppunit_major_version \= $cppunit_major_min \& \
        $cppunit_minor_version \> $cppunit_minor_min \| \
        $cppunit_major_version \= $cppunit_major_min \& \
        $cppunit_minor_version \= $cppunit_minor_min \& \
        $cppunit_micro_version \>= $cppunit_micro_min `

    if test "$cppunit_version_proper" = "1" ; then
      AC_MSG_RESULT([$cppunit_major_version.$cppunit_minor_version.$cppunit_micro_version])
    else
      AC_MSG_RESULT(no)
      AC_MSG_WARN(Minimum version of CPPUNIT couldn't be found. Tests will not be built)
      no_cppunit=yes
    fi
  fi
else
  no_cppunit=user
fi

  if test "x$no_cppunit" = x ; then
    ifelse([$2], , :, [$2])
    if test "x$enable_online_tests" = "xyes"; then
      AC_DEFINE_UNQUOTED(PERFORM_ONLINE_UNITTESTS, 1, [Define if unit tests requiring online access should be compiled])
    fi
  else
    CPPUNIT_CFLAGS=""
    CPPUNIT_LIBS=""
    ifelse([$3], , :, [$3])
  fi

  AC_SUBST(CPPUNIT_CFLAGS)
  AC_SUBST(CPPUNIT_LIBS)
])

dnl
dnl AM_KDE_MIN_VERSION(MIN-VERSION-MAJOR, MIN-VERSION-MINOR, MIN-VERSION-MICRO)
dnl
AC_DEFUN([AM_KDE_MIN_VERSION],
[
	AC_MSG_CHECKING([if minimum TDE version is available])
	AC_LANG_SAVE
	AC_LANG_CPLUSPLUS
	save_CXXFLAGS=$CXXFLAGS
	CXXFLAGS="$CXXFLAGS -I$srcdir $all_includes"
	AC_TRY_COMPILE([
	#include "kdecompat.h"
	#if !( KDE_IS_VERSION( $1, $2, $3 ) )
	#error TDE version does not meet KMyMoney minimum requirement
	#endif
		], [], AC_MSG_RESULT(yes), AC_MSG_ERROR(no)
	)
	CXXFLAGS=$save_CXXFLAGS
	AC_LANG_RESTORE
])

AC_DEFUN([AC_GLIB_2],
[

AC_MSG_CHECKING([for glib == 2.0])

GLIB2_LIBS=`$PKG_CONFIG --libs glib-2.0`
GLIB2_CFLAGS="`$PKG_CONFIG --cflags glib-2.0`"
if test -z "$GLIB2_LIBS"; then
        AC_MSG_RESULT(no);
        DO_NOT_COMPILE="$DO_NOT_COMPILE mozilla"
else
        AC_MSG_RESULT([cflags $GLIB2_CFLAGS]);
        AC_SUBST(GLIB2_CFLAGS)
        AC_SUBST(GLIB2_LIBS)
fi

])

AC_DEFUN([AC_GTK_2],
[

AC_MSG_CHECKING([for gtk == 2.0])

GTK2_LIBS=`$PKG_CONFIG --libs gtk+-2.0`
GTK2_CFLAGS="`$PKG_CONFIG --cflags gtk+-2.0`"
if test -z "$GTK2_LIBS"; then
        AC_MSG_RESULT(no);
        DO_NOT_COMPILE="$DO_NOT_COMPILE mozilla"
else
        AC_MSG_RESULT([cflags $GTK2_CFLAGS]);
        AC_SUBST(GTK2_CFLAGS)
        AC_SUBST(GTK2_LIBS)
fi

])

AC_DEFUN([AC_TAGCOLL2],
[

AC_MSG_CHECKING([for libtagcoll2])

TAGCOLL2_LIBS=`$PKG_CONFIG --libs libtagcoll2`
TAGCOLL2_CFLAGS="`$PKG_CONFIG --cflags libtagcoll2`"
if test -z "$TAGCOLL2_LIBS"; then
        AC_MSG_RESULT(no);
else
        AC_MSG_RESULT([cflags $TAGCOLL2_CFLAGS]);
        AC_SUBST(TAGCOLL2_CFLAGS)
        AC_SUBST(TAGCOLL2_LIBS)
fi

])

AC_DEFUN([AC_LIBOFX],
[
AC_MSG_CHECKING(if the OFX importer plugin is desired)
AC_ARG_ENABLE(ofxplugin,
  AC_HELP_STRING([--enable-ofxplugin],[enable OFX importer plugin (default=auto)]),
  [enable_ofxplugin="$enableval"],
  [enable_ofxplugin="auto"])
AC_MSG_RESULT($enable_ofxplugin)

AC_MSG_CHECKING(if OFX direct connect is desired)
AC_ARG_ENABLE(ofxbanking,
  AC_HELP_STRING([--enable-ofxbanking],[enable OFX direct connect (default=auto)]),
  [enable_ofxbanking="$enableval"],
  [enable_ofxbanking="auto"])
AC_MSG_RESULT($enable_ofxbanking)

# make sure we include the plugin even if not mentioned explicitly
if test "$enable_ofxbanking" != "no" -a "$enable_ofxplugin" != "yes"; then
  enable_ofxplugin=$enable_ofxbanking
fi
 
if test "$enable_ofxplugin" != "no" -o "$enable_ofxbanking" != "no"; then
  ac_save_CFLAGS="$CFLAGS"
  CFLAGS="$CFLAGS $all_includes $USER_INCLUDES"
  AC_CHECK_HEADER([OpenSP/macros.h],
   [],
   [
    if test "$enable_ofxplugin" != "auto" -o "$enable_ofxbanking" != "auto"; then
      AC_MSG_ERROR([cannot find OpenSP headers. Please ensure you have OpenSP installed.])
    fi
    AC_MSG_RESULT([cannot find OpenSP headers. Skipping OFX support])
    enable_ofxbanking=no
    enable_ofxplugin=no
   ])
  if test "$enable_ofxplugin" != "no"; then
    CFLAGS="$ac_save_CFLAGS"
    PKG_CHECK_MODULES(OFX,libofx >= 0.8.2)
  fi
fi
if test "$enable_ofxplugin" != "no"; then
 OFX_IMPORTERPLUGIN="ofximport" 
 enable_ofxplugin=yes
fi

if test "$enable_ofxbanking" != "no"; then
  enable_ofxbanking=yes
fi

AM_CONDITIONAL(OFXBANKING, test "$enable_ofxbanking" != "no" )
AC_SUBST(OFX_LIBS)
AC_SUBST(OFX_IMPORTERPLUGIN)
])

dnl
dnl check the memory leakage checker option
dnl if enabled or disabled, directly controlled
dnl if not given, follows --enable-debug and if
dnl debugging support is turned on, the memory
dnl leakage checker is turned on also
dnl
dnl Need AC_CHECK_COMPILERS to be run before
AC_DEFUN([AC_MEMORY_LEAK_CHECK], [
  AC_ARG_ENABLE(
  leak-check,
  AC_HELP_STRING([--enable-leak-check],[enable memory leak checker (default=no)]),
  use_memory_leak_check=$enableval,use_memory_leak_check=no)

  if test "x$use_memory_leak_check" != "xno"; then
    CPPFLAGS="$CPPFLAGS -D_CHECK_MEMORY"
  fi
  if test "x$kde_use_debug_code" != "xno"; then
    CPPFLAGS="$CPPFLAGS -DKMM_DEBUG=1"
  else
    CPPFLAGS="$CPPFLAGS -DKMM_DEBUG=0"
  fi
])

dnl
dnl check the pdf generation option
dnl if enabled or disabled, directly controlled
dnl
AC_DEFUN([AC_PDF_GENERATION], [
  AC_MSG_CHECKING(if the PDF document generation is desired)
  AC_ARG_ENABLE( pdf-docs,
    [  --enable-pdf-docs       enable generation of PDF documents (default=auto)],
    enable_pdfdocs="$enableval",
    enable_pdfdocs="auto")

  AC_MSG_RESULT($enable_pdfdocs)
  if test "x$enable_pdfdocs" != "xno"; then
    AC_CHECK_PROG(found_recode, recode, yes, no)
    AC_CHECK_PROG(found_html2ps, html2ps, yes, no)
    AC_CHECK_PROG(found_ps2pdf, ps2pdf, yes, no)
    if test "x$found_recode" != "xyes" && "x$found_html2ps" != "xyes" && "x$found_ps2pdf" != "xyes"; then
      if test "x$enable_pdfdocs" = "xyes"; then
        AC_MSG_ERROR(At least one of the tools for PDF generation is missing)
      fi
      enable_pdfdocs="no"
    else
      enable_pdfdocs="yes"
    fi
  fi

  AM_CONDITIONAL(GENERATE_PDF, test "x$enable_pdfdocs" = "xyes")
])

dnl Macro to check for KDChart include and library files
dnl Availability of KDChart defaults to 'no'

AC_DEFUN([AC_QTDESIGNER_SUPPORT],
[
AC_MSG_CHECKING([if library for Qt-Designer widgets should be installed])
AC_ARG_ENABLE(qtdesigner,
  AC_HELP_STRING([--enable-qtdesigner],[Install KMyMoney specific widget library for Qt-Designer (default=no)]),
  [
    enable_qtdesigner="$enableval" 
    AC_MSG_RESULT($enable_qtdesigner)
  ],
  [
    enable_qtdesigner="no"
    AC_MSG_RESULT($enable_qtdesigner)
  ])
  AM_CONDITIONAL(INSTALL_QTDESIGNER_SUPPORT, test "$enable_qtdesigner" = "yes")
])
# sqlite3.m4
# ----------
#
# Copyright 2008 by Thomas Baumgart
#
# License: See file COPYING
#
# Checks for the necessity to build our own qt-sqlite3 support library
# and the presence of the sqlite3 development headers.
#
# Supports the following options:
#
# --enable-sqlite3
# --disable-sqlite3
#
# If none of them is present, the detection is automatic. If the development
# headers are not found for automatic detection, the generation will be
# disabled w/o error. If --enable-sqlite3 is provided in the same stage,
# an error is given if the sqlite3 development files are not installed.
#
# The following variables are provided via AC_SUBST:
#
# SQLITE3 - contains the subdirectory to visit for compilation
# LIBSQLITE3 - contains the full pathname for the Qt plugin driver


AC_DEFUN([AC_SQLITE3], [
  AC_MSG_CHECKING(if the SQLITE3 support is desired)
  AC_ARG_ENABLE(sqlite3,
    AC_HELP_STRING([--enable-sqlite3],[build SQLITE3 support library (default=auto)]),
    enable_sqlite3="$enableval",
    enable_sqlite3="auto")
  AC_MSG_RESULT($enable_sqlite3)

  if test ! $enable_sqlite3 = no; then
    # determine name and path of sqlite3 plugin library
    qtlib=""
    if test ! "lib${tdelibsuff}" = "lib"; then
      qtlib=".lib64"
    fi 
    if test x$QTDIR = x; then
      QTDIR=`dirname $MOC`
      QTDIR=${QTDIR%/bin}
    fi
    if test "$PKG_CONFIG" != "no" ; then
      if $PKG_CONFIG --exists tqt-mt ; then
        qt_plugins_dir="`pkg-config --variable=pluginsdir tqt-mt`"
      else
        if $PKG_CONFIG --exists qt-mt ; then
          qt_plugins_dir="`pkg-config --variable=pluginsdir tqt-mt`"
        fi
      fi
    fi
    if test "x$qt_plugins_dir" = "x"; then
      qt_plugins_dir=${QTDIR}/plugins
    fi
    LIBSQLITE3=${qt_plugins_dir}/sqldrivers/libqsqlite3${qtlib}.so

    # do the checks
    if test $enable_sqlite3 = auto; then
      AC_MSG_CHECKING(if the SQLITE3 support is already present)
      if test ! -e ${LIBSQLITE3}; then
        result=no
      else
        # add check for local qt-sqlite3 directory here
        result=yes
        enable_sqlite3=no
        # in case a previous run unpacked the SQLITE3 support stuff
        # it is pretty sure that we have build the existing support
        # if that's the case, we just enable it again
        if test -d qt-sqlite3-0.2; then
          enable_sqlite3=auto
        fi
      fi
      AC_MSG_RESULT($result)
    fi

    # we only need to check for the headers in case we need to build
    if test ! $enable_sqlite3 = no; then
      # now check for the presence of SQLITE libraries
      AC_CHECK_HEADER([sqlite3.h], [enable_sqlite3=yes],
        [
          if test $enable_sqlite3 = auto; then
            enable_sqlite3=no
          else
            AC_MSG_ERROR(SQLITE development files not found)
          fi
        ])
    fi
  fi

  if test $enable_sqlite3 = yes; then
    AC_MSG_CHECKING(if the environment variable QTDIR is set)
    if test x$QTDIR = x; then
      AC_MSG_ERROR(QTDIR not set)
    fi
    AC_MSG_RESULT($QTDIR)
    ac_qmake=${QTDIR}/bin/qmake
    AC_ARG_WITH(qmake,
        AC_HELP_STRING([--with-qmake=PATH],[which version of QMake to use ]),
        [  ac_qmake="$withval" ])
  fi

  if test $enable_sqlite3 = yes; then
    rm -rf qt-sqlite3-0.2
    gunzip -c `dirname -- ${0}`/23011-qt-sqlite3-0.2.tar.gz | tar -xf -
    cd qt-sqlite3-0.2
    ${ac_qmake} QMAKE=${ac_qmake}
    SQLITE3=qt-sqlite3-0.2
    sed -i s/^install:.*$// Makefile
    sed -i s/^uninstall:.*$// Makefile
    # create the targets required for 'make distcheck' and 'make [un]install'
    cat >> Makefile <<EOF
dvi:

check:

installcheck:

distuninstallcheck:

dist:

distcleancheck:

# for installation and de-installation we need to take care
# of the _inst case which is caused by running 'make distcheck'
install:
	if test ! x$SQLITE3 = x; then \
	  if test "x\$(DESTDIR)" = "x" -a "${prefix:0-5}" = "_inst"; then \
	    /bin/sh ../$ac_aux_dir/mkinstalldirs \`dirname ${prefix}${LIBSQLITE3}\`; \
	    ${INSTALL} sqldrivers/libqsqlite3.so ${prefix}${LIBSQLITE3}; \
	    chmod 755 ${prefix}${LIBSQLITE3}; \
	  else \
	    /bin/sh ../$ac_aux_dir/mkinstalldirs \`dirname \$(DESTDIR)${LIBSQLITE3}\`; \
	    ${INSTALL} sqldrivers/libqsqlite3.so \$(DESTDIR)${LIBSQLITE3}; \
	    chmod 755 \$(DESTDIR)${LIBSQLITE3}; \
	  fi \
	fi

uninstall:
	if test ! x$SQLITE3 = x; then \
	  if test "x\$(DESTDIR)" = "x" -a "${prefix:0-5}" = "_inst"; then \
	    rm -rf ${prefix}${LIBSQLITE3}; \
	  else \
	    rm -rf \$(DESTDIR)${LIBSQLITE3}; \
	  fi \
	fi

EOF

    cd ..
    AC_SUBST(SQLITE3)
    AC_SUBST(LIBSQLITE3) 
  fi
])
# libtool.m4 - Configure libtool for the host system. -*-Autoconf-*-
#
#   Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001, 2003, 2004, 2005,
#                 2006, 2007, 2008, 2009, 2010, 2011 Free Software
#                 Foundation, Inc.
#   Written by Gordon Matzigkeit, 1996
#
# This file is free software; the Free Software Foundation gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.

m4_define([_LT_COPYING], [dnl
#   Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001, 2003, 2004, 2005,
#                 2006, 2007, 2008, 2009, 2010, 2011 Free Software
#                 Foundation, Inc.
#   Written by Gordon Matzigkeit, 1996
#
#   This file is part of GNU Libtool.
#
# GNU Libtool is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; either version 2 of
# the License, or (at your option) any later version.
#
# As a special exception to the GNU General Public License,
# if you distribute this file as part of a program or library that
# is built using GNU Libtool, you may include this file under the
# same distribution terms that you use for the rest of that program.
#
# GNU Libtool is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNU Libtool; see the file COPYING.  If not, a copy
# can be downloaded from http://www.gnu.org/licenses/gpl.html, or
# obtained by writing to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
])

# serial 57 LT_INIT


# LT_PREREQ(VERSION)
# ------------------
# Complain and exit if this libtool version is less that VERSION.
m4_defun([LT_PREREQ],
[m4_if(m4_version_compare(m4_defn([LT_PACKAGE_VERSION]), [$1]), -1,
       [m4_default([$3],
		   [m4_fatal([Libtool version $1 or higher is required],
		             63)])],
       [$2])])


# _LT_CHECK_BUILDDIR
# ------------------
# Complain if the absolute build directory name contains unusual characters
m4_defun([_LT_CHECK_BUILDDIR],
[case `pwd` in
  *\ * | *\	*)
    AC_MSG_WARN([Libtool does not cope well with whitespace in `pwd`]) ;;
esac
])


# LT_INIT([OPTIONS])
# ------------------
AC_DEFUN([LT_INIT],
[AC_PREREQ([2.58])dnl We use AC_INCLUDES_DEFAULT
AC_REQUIRE([AC_CONFIG_AUX_DIR_DEFAULT])dnl
AC_BEFORE([$0], [LT_LANG])dnl
AC_BEFORE([$0], [LT_OUTPUT])dnl
AC_BEFORE([$0], [LTDL_INIT])dnl
m4_require([_LT_CHECK_BUILDDIR])dnl

dnl Autoconf doesn't catch unexpanded LT_ macros by default:
m4_pattern_forbid([^_?LT_[A-Z_]+$])dnl
m4_pattern_allow([^(_LT_EOF|LT_DLGLOBAL|LT_DLLAZY_OR_NOW|LT_MULTI_MODULE)$])dnl
dnl aclocal doesn't pull ltoptions.m4, ltsugar.m4, or ltversion.m4
dnl unless we require an AC_DEFUNed macro:
AC_REQUIRE([LTOPTIONS_VERSION])dnl
AC_REQUIRE([LTSUGAR_VERSION])dnl
AC_REQUIRE([LTVERSION_VERSION])dnl
AC_REQUIRE([LTOBSOLETE_VERSION])dnl
m4_require([_LT_PROG_LTMAIN])dnl

_LT_SHELL_INIT([SHELL=${CONFIG_SHELL-/bin/sh}])

dnl Parse OPTIONS
_LT_SET_OPTIONS([$0], [$1])

# This can be used to rebuild libtool when needed
LIBTOOL_DEPS="$ltmain"

# Always use our own libtool.
LIBTOOL='$(SHELL) $(top_builddir)/libtool'
AC_SUBST(LIBTOOL)dnl

_LT_SETUP

# Only expand once:
m4_define([LT_INIT])
])# LT_INIT

# Old names:
AU_ALIAS([AC_PROG_LIBTOOL], [LT_INIT])
AU_ALIAS([AM_PROG_LIBTOOL], [LT_INIT])
dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([AC_PROG_LIBTOOL], [])
dnl AC_DEFUN([AM_PROG_LIBTOOL], [])


# _LT_CC_BASENAME(CC)
# -------------------
# Calculate cc_basename.  Skip known compiler wrappers and cross-prefix.
m4_defun([_LT_CC_BASENAME],
[for cc_temp in $1""; do
  case $cc_temp in
    compile | *[[\\/]]compile | ccache | *[[\\/]]ccache ) ;;
    distcc | *[[\\/]]distcc | purify | *[[\\/]]purify ) ;;
    \-*) ;;
    *) break;;
  esac
done
cc_basename=`$ECHO "$cc_temp" | $SED "s%.*/%%; s%^$host_alias-%%"`
])


# _LT_FILEUTILS_DEFAULTS
# ----------------------
# It is okay to use these file commands and assume they have been set
# sensibly after `m4_require([_LT_FILEUTILS_DEFAULTS])'.
m4_defun([_LT_FILEUTILS_DEFAULTS],
[: ${CP="cp -f"}
: ${MV="mv -f"}
: ${RM="rm -f"}
])# _LT_FILEUTILS_DEFAULTS


# _LT_SETUP
# ---------
m4_defun([_LT_SETUP],
[AC_REQUIRE([AC_CANONICAL_HOST])dnl
AC_REQUIRE([AC_CANONICAL_BUILD])dnl
AC_REQUIRE([_LT_PREPARE_SED_QUOTE_VARS])dnl
AC_REQUIRE([_LT_PROG_ECHO_BACKSLASH])dnl

_LT_DECL([], [PATH_SEPARATOR], [1], [The PATH separator for the build system])dnl
dnl
_LT_DECL([], [host_alias], [0], [The host system])dnl
_LT_DECL([], [host], [0])dnl
_LT_DECL([], [host_os], [0])dnl
dnl
_LT_DECL([], [build_alias], [0], [The build system])dnl
_LT_DECL([], [build], [0])dnl
_LT_DECL([], [build_os], [0])dnl
dnl
AC_REQUIRE([AC_PROG_CC])dnl
AC_REQUIRE([LT_PATH_LD])dnl
AC_REQUIRE([LT_PATH_NM])dnl
dnl
AC_REQUIRE([AC_PROG_LN_S])dnl
test -z "$LN_S" && LN_S="ln -s"
_LT_DECL([], [LN_S], [1], [Whether we need soft or hard links])dnl
dnl
AC_REQUIRE([LT_CMD_MAX_LEN])dnl
_LT_DECL([objext], [ac_objext], [0], [Object file suffix (normally "o")])dnl
_LT_DECL([], [exeext], [0], [Executable file suffix (normally "")])dnl
dnl
m4_require([_LT_FILEUTILS_DEFAULTS])dnl
m4_require([_LT_CHECK_SHELL_FEATURES])dnl
m4_require([_LT_PATH_CONVERSION_FUNCTIONS])dnl
m4_require([_LT_CMD_RELOAD])dnl
m4_require([_LT_CHECK_MAGIC_METHOD])dnl
m4_require([_LT_CHECK_SHAREDLIB_FROM_LINKLIB])dnl
m4_require([_LT_CMD_OLD_ARCHIVE])dnl
m4_require([_LT_CMD_GLOBAL_SYMBOLS])dnl
m4_require([_LT_WITH_SYSROOT])dnl

_LT_CONFIG_LIBTOOL_INIT([
# See if we are running on zsh, and set the options which allow our
# commands through without removal of \ escapes INIT.
if test -n "\${ZSH_VERSION+set}" ; then
   setopt NO_GLOB_SUBST
fi
])
if test -n "${ZSH_VERSION+set}" ; then
   setopt NO_GLOB_SUBST
fi

_LT_CHECK_OBJDIR

m4_require([_LT_TAG_COMPILER])dnl

case $host_os in
aix3*)
  # AIX sometimes has problems with the GCC collect2 program.  For some
  # reason, if we set the COLLECT_NAMES environment variable, the problems
  # vanish in a puff of smoke.
  if test "X${COLLECT_NAMES+set}" != Xset; then
    COLLECT_NAMES=
    export COLLECT_NAMES
  fi
  ;;
esac

# Global variables:
ofile=libtool
can_build_shared=yes

# All known linkers require a `.a' archive for static linking (except MSVC,
# which needs '.lib').
libext=a

with_gnu_ld="$lt_cv_prog_gnu_ld"

old_CC="$CC"
old_CFLAGS="$CFLAGS"

# Set sane defaults for various variables
test -z "$CC" && CC=cc
test -z "$LTCC" && LTCC=$CC
test -z "$LTCFLAGS" && LTCFLAGS=$CFLAGS
test -z "$LD" && LD=ld
test -z "$ac_objext" && ac_objext=o

_LT_CC_BASENAME([$compiler])

# Only perform the check for file, if the check method requires it
test -z "$MAGIC_CMD" && MAGIC_CMD=file
case $deplibs_check_method in
file_magic*)
  if test "$file_magic_cmd" = '$MAGIC_CMD'; then
    _LT_PATH_MAGIC
  fi
  ;;
esac

# Use C for the default configuration in the libtool script
LT_SUPPORTED_TAG([CC])
_LT_LANG_C_CONFIG
_LT_LANG_DEFAULT_CONFIG
_LT_CONFIG_COMMANDS
])# _LT_SETUP


# _LT_PREPARE_SED_QUOTE_VARS
# --------------------------
# Define a few sed substitution that help us do robust quoting.
m4_defun([_LT_PREPARE_SED_QUOTE_VARS],
[# Backslashify metacharacters that are still active within
# double-quoted strings.
sed_quote_subst='s/\([["`$\\]]\)/\\\1/g'

# Same as above, but do not quote variable references.
double_quote_subst='s/\([["`\\]]\)/\\\1/g'

# Sed substitution to delay expansion of an escaped shell variable in a
# double_quote_subst'ed string.
delay_variable_subst='s/\\\\\\\\\\\$/\\\\\\$/g'

# Sed substitution to delay expansion of an escaped single quote.
delay_single_quote_subst='s/'\''/'\'\\\\\\\'\''/g'

# Sed substitution to avoid accidental globbing in evaled expressions
no_glob_subst='s/\*/\\\*/g'
])

# _LT_PROG_LTMAIN
# ---------------
# Note that this code is called both from `configure', and `config.status'
# now that we use AC_CONFIG_COMMANDS to generate libtool.  Notably,
# `config.status' has no value for ac_aux_dir unless we are using Automake,
# so we pass a copy along to make sure it has a sensible value anyway.
m4_defun([_LT_PROG_LTMAIN],
[m4_ifdef([AC_REQUIRE_AUX_FILE], [AC_REQUIRE_AUX_FILE([ltmain.sh])])dnl
_LT_CONFIG_LIBTOOL_INIT([ac_aux_dir='$ac_aux_dir'])
ltmain="$ac_aux_dir/ltmain.sh"
])# _LT_PROG_LTMAIN


## ------------------------------------- ##
## Accumulate code for creating libtool. ##
## ------------------------------------- ##

# So that we can recreate a full libtool script including additional
# tags, we accumulate the chunks of code to send to AC_CONFIG_COMMANDS
# in macros and then make a single call at the end using the `libtool'
# label.


# _LT_CONFIG_LIBTOOL_INIT([INIT-COMMANDS])
# ----------------------------------------
# Register INIT-COMMANDS to be passed to AC_CONFIG_COMMANDS later.
m4_define([_LT_CONFIG_LIBTOOL_INIT],
[m4_ifval([$1],
          [m4_append([_LT_OUTPUT_LIBTOOL_INIT],
                     [$1
])])])

# Initialize.
m4_define([_LT_OUTPUT_LIBTOOL_INIT])


# _LT_CONFIG_LIBTOOL([COMMANDS])
# ------------------------------
# Register COMMANDS to be passed to AC_CONFIG_COMMANDS later.
m4_define([_LT_CONFIG_LIBTOOL],
[m4_ifval([$1],
          [m4_append([_LT_OUTPUT_LIBTOOL_COMMANDS],
                     [$1
])])])

# Initialize.
m4_define([_LT_OUTPUT_LIBTOOL_COMMANDS])


# _LT_CONFIG_SAVE_COMMANDS([COMMANDS], [INIT_COMMANDS])
# -----------------------------------------------------
m4_defun([_LT_CONFIG_SAVE_COMMANDS],
[_LT_CONFIG_LIBTOOL([$1])
_LT_CONFIG_LIBTOOL_INIT([$2])
])


# _LT_FORMAT_COMMENT([COMMENT])
# -----------------------------
# Add leading comment marks to the start of each line, and a trailing
# full-stop to the whole comment if one is not present already.
m4_define([_LT_FORMAT_COMMENT],
[m4_ifval([$1], [
m4_bpatsubst([m4_bpatsubst([$1], [^ *], [# ])],
              [['`$\]], [\\\&])]m4_bmatch([$1], [[!?.]$], [], [.])
)])



## ------------------------ ##
## FIXME: Eliminate VARNAME ##
## ------------------------ ##


# _LT_DECL([CONFIGNAME], VARNAME, VALUE, [DESCRIPTION], [IS-TAGGED?])
# -------------------------------------------------------------------
# CONFIGNAME is the name given to the value in the libtool script.
# VARNAME is the (base) name used in the configure script.
# VALUE may be 0, 1 or 2 for a computed quote escaped value based on
# VARNAME.  Any other value will be used directly.
m4_define([_LT_DECL],
[lt_if_append_uniq([lt_decl_varnames], [$2], [, ],
    [lt_dict_add_subkey([lt_decl_dict], [$2], [libtool_name],
	[m4_ifval([$1], [$1], [$2])])
    lt_dict_add_subkey([lt_decl_dict], [$2], [value], [$3])
    m4_ifval([$4],
	[lt_dict_add_subkey([lt_decl_dict], [$2], [description], [$4])])
    lt_dict_add_subkey([lt_decl_dict], [$2],
	[tagged?], [m4_ifval([$5], [yes], [no])])])
])


# _LT_TAGDECL([CONFIGNAME], VARNAME, VALUE, [DESCRIPTION])
# --------------------------------------------------------
m4_define([_LT_TAGDECL], [_LT_DECL([$1], [$2], [$3], [$4], [yes])])


# lt_decl_tag_varnames([SEPARATOR], [VARNAME1...])
# ------------------------------------------------
m4_define([lt_decl_tag_varnames],
[_lt_decl_filter([tagged?], [yes], $@)])


# _lt_decl_filter(SUBKEY, VALUE, [SEPARATOR], [VARNAME1..])
# ---------------------------------------------------------
m4_define([_lt_decl_filter],
[m4_case([$#],
  [0], [m4_fatal([$0: too few arguments: $#])],
  [1], [m4_fatal([$0: too few arguments: $#: $1])],
  [2], [lt_dict_filter([lt_decl_dict], [$1], [$2], [], lt_decl_varnames)],
  [3], [lt_dict_filter([lt_decl_dict], [$1], [$2], [$3], lt_decl_varnames)],
  [lt_dict_filter([lt_decl_dict], $@)])[]dnl
])


# lt_decl_quote_varnames([SEPARATOR], [VARNAME1...])
# --------------------------------------------------
m4_define([lt_decl_quote_varnames],
[_lt_decl_filter([value], [1], $@)])


# lt_decl_dquote_varnames([SEPARATOR], [VARNAME1...])
# ---------------------------------------------------
m4_define([lt_decl_dquote_varnames],
[_lt_decl_filter([value], [2], $@)])


# lt_decl_varnames_tagged([SEPARATOR], [VARNAME1...])
# ---------------------------------------------------
m4_define([lt_decl_varnames_tagged],
[m4_assert([$# <= 2])dnl
_$0(m4_quote(m4_default([$1], [[, ]])),
    m4_ifval([$2], [[$2]], [m4_dquote(lt_decl_tag_varnames)]),
    m4_split(m4_normalize(m4_quote(_LT_TAGS)), [ ]))])
m4_define([_lt_decl_varnames_tagged],
[m4_ifval([$3], [lt_combine([$1], [$2], [_], $3)])])


# lt_decl_all_varnames([SEPARATOR], [VARNAME1...])
# ------------------------------------------------
m4_define([lt_decl_all_varnames],
[_$0(m4_quote(m4_default([$1], [[, ]])),
     m4_if([$2], [],
	   m4_quote(lt_decl_varnames),
	m4_quote(m4_shift($@))))[]dnl
])
m4_define([_lt_decl_all_varnames],
[lt_join($@, lt_decl_varnames_tagged([$1],
			lt_decl_tag_varnames([[, ]], m4_shift($@))))dnl
])


# _LT_CONFIG_STATUS_DECLARE([VARNAME])
# ------------------------------------
# Quote a variable value, and forward it to `config.status' so that its
# declaration there will have the same value as in `configure'.  VARNAME
# must have a single quote delimited value for this to work.
m4_define([_LT_CONFIG_STATUS_DECLARE],
[$1='`$ECHO "$][$1" | $SED "$delay_single_quote_subst"`'])


# _LT_CONFIG_STATUS_DECLARATIONS
# ------------------------------
# We delimit libtool config variables with single quotes, so when
# we write them to config.status, we have to be sure to quote all
# embedded single quotes properly.  In configure, this macro expands
# each variable declared with _LT_DECL (and _LT_TAGDECL) into:
#
#    <var>='`$ECHO "$<var>" | $SED "$delay_single_quote_subst"`'
m4_defun([_LT_CONFIG_STATUS_DECLARATIONS],
[m4_foreach([_lt_var], m4_quote(lt_decl_all_varnames),
    [m4_n([_LT_CONFIG_STATUS_DECLARE(_lt_var)])])])


# _LT_LIBTOOL_TAGS
# ----------------
# Output comment and list of tags supported by the script
m4_defun([_LT_LIBTOOL_TAGS],
[_LT_FORMAT_COMMENT([The names of the tagged configurations supported by this script])dnl
available_tags="_LT_TAGS"dnl
])


# _LT_LIBTOOL_DECLARE(VARNAME, [TAG])
# -----------------------------------
# Extract the dictionary values for VARNAME (optionally with TAG) and
# expand to a commented shell variable setting:
#
#    # Some comment about what VAR is for.
#    visible_name=$lt_internal_name
m4_define([_LT_LIBTOOL_DECLARE],
[_LT_FORMAT_COMMENT(m4_quote(lt_dict_fetch([lt_decl_dict], [$1],
					   [description])))[]dnl
m4_pushdef([_libtool_name],
    m4_quote(lt_dict_fetch([lt_decl_dict], [$1], [libtool_name])))[]dnl
m4_case(m4_quote(lt_dict_fetch([lt_decl_dict], [$1], [value])),
    [0], [_libtool_name=[$]$1],
    [1], [_libtool_name=$lt_[]$1],
    [2], [_libtool_name=$lt_[]$1],
    [_libtool_name=lt_dict_fetch([lt_decl_dict], [$1], [value])])[]dnl
m4_ifval([$2], [_$2])[]m4_popdef([_libtool_name])[]dnl
])


# _LT_LIBTOOL_CONFIG_VARS
# -----------------------
# Produce commented declarations of non-tagged libtool config variables
# suitable for insertion in the LIBTOOL CONFIG section of the `libtool'
# script.  Tagged libtool config variables (even for the LIBTOOL CONFIG
# section) are produced by _LT_LIBTOOL_TAG_VARS.
m4_defun([_LT_LIBTOOL_CONFIG_VARS],
[m4_foreach([_lt_var],
    m4_quote(_lt_decl_filter([tagged?], [no], [], lt_decl_varnames)),
    [m4_n([_LT_LIBTOOL_DECLARE(_lt_var)])])])


# _LT_LIBTOOL_TAG_VARS(TAG)
# -------------------------
m4_define([_LT_LIBTOOL_TAG_VARS],
[m4_foreach([_lt_var], m4_quote(lt_decl_tag_varnames),
    [m4_n([_LT_LIBTOOL_DECLARE(_lt_var, [$1])])])])


# _LT_TAGVAR(VARNAME, [TAGNAME])
# ------------------------------
m4_define([_LT_TAGVAR], [m4_ifval([$2], [$1_$2], [$1])])


# _LT_CONFIG_COMMANDS
# -------------------
# Send accumulated output to $CONFIG_STATUS.  Thanks to the lists of
# variables for single and double quote escaping we saved from calls
# to _LT_DECL, we can put quote escaped variables declarations
# into `config.status', and then the shell code to quote escape them in
# for loops in `config.status'.  Finally, any additional code accumulated
# from calls to _LT_CONFIG_LIBTOOL_INIT is expanded.
m4_defun([_LT_CONFIG_COMMANDS],
[AC_PROVIDE_IFELSE([LT_OUTPUT],
	dnl If the libtool generation code has been placed in $CONFIG_LT,
	dnl instead of duplicating it all over again into config.status,
	dnl then we will have config.status run $CONFIG_LT later, so it
	dnl needs to know what name is stored there:
        [AC_CONFIG_COMMANDS([libtool],
            [$SHELL $CONFIG_LT || AS_EXIT(1)], [CONFIG_LT='$CONFIG_LT'])],
    dnl If the libtool generation code is destined for config.status,
    dnl expand the accumulated commands and init code now:
    [AC_CONFIG_COMMANDS([libtool],
        [_LT_OUTPUT_LIBTOOL_COMMANDS], [_LT_OUTPUT_LIBTOOL_COMMANDS_INIT])])
])#_LT_CONFIG_COMMANDS


# Initialize.
m4_define([_LT_OUTPUT_LIBTOOL_COMMANDS_INIT],
[

# The HP-UX ksh and POSIX shell print the target directory to stdout
# if CDPATH is set.
(unset CDPATH) >/dev/null 2>&1 && unset CDPATH

sed_quote_subst='$sed_quote_subst'
double_quote_subst='$double_quote_subst'
delay_variable_subst='$delay_variable_subst'
_LT_CONFIG_STATUS_DECLARATIONS
LTCC='$LTCC'
LTCFLAGS='$LTCFLAGS'
compiler='$compiler_DEFAULT'

# A function that is used when there is no print builtin or printf.
func_fallback_echo ()
{
  eval 'cat <<_LTECHO_EOF
\$[]1
_LTECHO_EOF'
}

# Quote evaled strings.
for var in lt_decl_all_varnames([[ \
]], lt_decl_quote_varnames); do
    case \`eval \\\\\$ECHO \\\\""\\\\\$\$var"\\\\"\` in
    *[[\\\\\\\`\\"\\\$]]*)
      eval "lt_\$var=\\\\\\"\\\`\\\$ECHO \\"\\\$\$var\\" | \\\$SED \\"\\\$sed_quote_subst\\"\\\`\\\\\\""
      ;;
    *)
      eval "lt_\$var=\\\\\\"\\\$\$var\\\\\\""
      ;;
    esac
done

# Double-quote double-evaled strings.
for var in lt_decl_all_varnames([[ \
]], lt_decl_dquote_varnames); do
    case \`eval \\\\\$ECHO \\\\""\\\\\$\$var"\\\\"\` in
    *[[\\\\\\\`\\"\\\$]]*)
      eval "lt_\$var=\\\\\\"\\\`\\\$ECHO \\"\\\$\$var\\" | \\\$SED -e \\"\\\$double_quote_subst\\" -e \\"\\\$sed_quote_subst\\" -e \\"\\\$delay_variable_subst\\"\\\`\\\\\\""
      ;;
    *)
      eval "lt_\$var=\\\\\\"\\\$\$var\\\\\\""
      ;;
    esac
done

_LT_OUTPUT_LIBTOOL_INIT
])

# _LT_GENERATED_FILE_INIT(FILE, [COMMENT])
# ------------------------------------
# Generate a child script FILE with all initialization necessary to
# reuse the environment learned by the parent script, and make the
# file executable.  If COMMENT is supplied, it is inserted after the
# `#!' sequence but before initialization text begins.  After this
# macro, additional text can be appended to FILE to form the body of
# the child script.  The macro ends with non-zero status if the
# file could not be fully written (such as if the disk is full).
m4_ifdef([AS_INIT_GENERATED],
[m4_defun([_LT_GENERATED_FILE_INIT],[AS_INIT_GENERATED($@)])],
[m4_defun([_LT_GENERATED_FILE_INIT],
[m4_require([AS_PREPARE])]dnl
[m4_pushdef([AS_MESSAGE_LOG_FD])]dnl
[lt_write_fail=0
cat >$1 <<_ASEOF || lt_write_fail=1
#! $SHELL
# Generated by $as_me.
$2
SHELL=\${CONFIG_SHELL-$SHELL}
export SHELL
_ASEOF
cat >>$1 <<\_ASEOF || lt_write_fail=1
AS_SHELL_SANITIZE
_AS_PREPARE
exec AS_MESSAGE_FD>&1
_ASEOF
test $lt_write_fail = 0 && chmod +x $1[]dnl
m4_popdef([AS_MESSAGE_LOG_FD])])])# _LT_GENERATED_FILE_INIT

# LT_OUTPUT
# ---------
# This macro allows early generation of the libtool script (before
# AC_OUTPUT is called), incase it is used in configure for compilation
# tests.
AC_DEFUN([LT_OUTPUT],
[: ${CONFIG_LT=./config.lt}
AC_MSG_NOTICE([creating $CONFIG_LT])
_LT_GENERATED_FILE_INIT(["$CONFIG_LT"],
[# Run this file to recreate a libtool stub with the current configuration.])

cat >>"$CONFIG_LT" <<\_LTEOF
lt_cl_silent=false
exec AS_MESSAGE_LOG_FD>>config.log
{
  echo
  AS_BOX([Running $as_me.])
} >&AS_MESSAGE_LOG_FD

lt_cl_help="\
\`$as_me' creates a local libtool stub from the current configuration,
for use in further configure time tests before the real libtool is
generated.

Usage: $[0] [[OPTIONS]]

  -h, --help      print this help, then exit
  -V, --version   print version number, then exit
  -q, --quiet     do not print progress messages
  -d, --debug     don't remove temporary files

Report bugs to <bug-libtool@gnu.org>."

lt_cl_version="\
m4_ifset([AC_PACKAGE_NAME], [AC_PACKAGE_NAME ])config.lt[]dnl
m4_ifset([AC_PACKAGE_VERSION], [ AC_PACKAGE_VERSION])
configured by $[0], generated by m4_PACKAGE_STRING.

Copyright (C) 2011 Free Software Foundation, Inc.
This config.lt script is free software; the Free Software Foundation
gives unlimited permision to copy, distribute and modify it."

while test $[#] != 0
do
  case $[1] in
    --version | --v* | -V )
      echo "$lt_cl_version"; exit 0 ;;
    --help | --h* | -h )
      echo "$lt_cl_help"; exit 0 ;;
    --debug | --d* | -d )
      debug=: ;;
    --quiet | --q* | --silent | --s* | -q )
      lt_cl_silent=: ;;

    -*) AC_MSG_ERROR([unrecognized option: $[1]
Try \`$[0] --help' for more information.]) ;;

    *) AC_MSG_ERROR([unrecognized argument: $[1]
Try \`$[0] --help' for more information.]) ;;
  esac
  shift
done

if $lt_cl_silent; then
  exec AS_MESSAGE_FD>/dev/null
fi
_LTEOF

cat >>"$CONFIG_LT" <<_LTEOF
_LT_OUTPUT_LIBTOOL_COMMANDS_INIT
_LTEOF

cat >>"$CONFIG_LT" <<\_LTEOF
AC_MSG_NOTICE([creating $ofile])
_LT_OUTPUT_LIBTOOL_COMMANDS
AS_EXIT(0)
_LTEOF
chmod +x "$CONFIG_LT"

# configure is writing to config.log, but config.lt does its own redirection,
# appending to config.log, which fails on DOS, as config.log is still kept
# open by configure.  Here we exec the FD to /dev/null, effectively closing
# config.log, so it can be properly (re)opened and appended to by config.lt.
lt_cl_success=:
test "$silent" = yes &&
  lt_config_lt_args="$lt_config_lt_args --quiet"
exec AS_MESSAGE_LOG_FD>/dev/null
$SHELL "$CONFIG_LT" $lt_config_lt_args || lt_cl_success=false
exec AS_MESSAGE_LOG_FD>>config.log
$lt_cl_success || AS_EXIT(1)
])# LT_OUTPUT


# _LT_CONFIG(TAG)
# ---------------
# If TAG is the built-in tag, create an initial libtool script with a
# default configuration from the untagged config vars.  Otherwise add code
# to config.status for appending the configuration named by TAG from the
# matching tagged config vars.
m4_defun([_LT_CONFIG],
[m4_require([_LT_FILEUTILS_DEFAULTS])dnl
_LT_CONFIG_SAVE_COMMANDS([
  m4_define([_LT_TAG], m4_if([$1], [], [C], [$1]))dnl
  m4_if(_LT_TAG, [C], [
    # See if we are running on zsh, and set the options which allow our
    # commands through without removal of \ escapes.
    if test -n "${ZSH_VERSION+set}" ; then
      setopt NO_GLOB_SUBST
    fi

    cfgfile="${ofile}T"
    trap "$RM \"$cfgfile\"; exit 1" 1 2 15
    $RM "$cfgfile"

    cat <<_LT_EOF >> "$cfgfile"
#! $SHELL

# `$ECHO "$ofile" | sed 's%^.*/%%'` - Provide generalized library-building support services.
# Generated automatically by $as_me ($PACKAGE$TIMESTAMP) $VERSION
# Libtool was configured on host `(hostname || uname -n) 2>/dev/null | sed 1q`:
# NOTE: Changes made to this file will be lost: look at ltmain.sh.
#
_LT_COPYING
_LT_LIBTOOL_TAGS

# ### BEGIN LIBTOOL CONFIG
_LT_LIBTOOL_CONFIG_VARS
_LT_LIBTOOL_TAG_VARS
# ### END LIBTOOL CONFIG

_LT_EOF

  case $host_os in
  aix3*)
    cat <<\_LT_EOF >> "$cfgfile"
# AIX sometimes has problems with the GCC collect2 program.  For some
# reason, if we set the COLLECT_NAMES environment variable, the problems
# vanish in a puff of smoke.
if test "X${COLLECT_NAMES+set}" != Xset; then
  COLLECT_NAMES=
  export COLLECT_NAMES
fi
_LT_EOF
    ;;
  esac

  _LT_PROG_LTMAIN

  # We use sed instead of cat because bash on DJGPP gets confused if
  # if finds mixed CR/LF and LF-only lines.  Since sed operates in
  # text mode, it properly converts lines to CR/LF.  This bash problem
  # is reportedly fixed, but why not run on old versions too?
  sed '$q' "$ltmain" >> "$cfgfile" \
     || (rm -f "$cfgfile"; exit 1)

  _LT_PROG_REPLACE_SHELLFNS

   mv -f "$cfgfile" "$ofile" ||
    (rm -f "$ofile" && cp "$cfgfile" "$ofile" && rm -f "$cfgfile")
  chmod +x "$ofile"
],
[cat <<_LT_EOF >> "$ofile"

dnl Unfortunately we have to use $1 here, since _LT_TAG is not expanded
dnl in a comment (ie after a #).
# ### BEGIN LIBTOOL TAG CONFIG: $1
_LT_LIBTOOL_TAG_VARS(_LT_TAG)
# ### END LIBTOOL TAG CONFIG: $1
_LT_EOF
])dnl /m4_if
],
[m4_if([$1], [], [
    PACKAGE='$PACKAGE'
    VERSION='$VERSION'
    TIMESTAMP='$TIMESTAMP'
    RM='$RM'
    ofile='$ofile'], [])
])dnl /_LT_CONFIG_SAVE_COMMANDS
])# _LT_CONFIG


# LT_SUPPORTED_TAG(TAG)
# ---------------------
# Trace this macro to discover what tags are supported by the libtool
# --tag option, using:
#    autoconf --trace 'LT_SUPPORTED_TAG:$1'
AC_DEFUN([LT_SUPPORTED_TAG], [])


# C support is built-in for now
m4_define([_LT_LANG_C_enabled], [])
m4_define([_LT_TAGS], [])


# LT_LANG(LANG)
# -------------
# Enable libtool support for the given language if not already enabled.
AC_DEFUN([LT_LANG],
[AC_BEFORE([$0], [LT_OUTPUT])dnl
m4_case([$1],
  [C],			[_LT_LANG(C)],
  [C++],		[_LT_LANG(CXX)],
  [Go],			[_LT_LANG(GO)],
  [Java],		[_LT_LANG(GCJ)],
  [Fortran 77],		[_LT_LANG(F77)],
  [Fortran],		[_LT_LANG(FC)],
  [Windows Resource],	[_LT_LANG(RC)],
  [m4_ifdef([_LT_LANG_]$1[_CONFIG],
    [_LT_LANG($1)],
    [m4_fatal([$0: unsupported language: "$1"])])])dnl
])# LT_LANG


# _LT_LANG(LANGNAME)
# ------------------
m4_defun([_LT_LANG],
[m4_ifdef([_LT_LANG_]$1[_enabled], [],
  [LT_SUPPORTED_TAG([$1])dnl
  m4_append([_LT_TAGS], [$1 ])dnl
  m4_define([_LT_LANG_]$1[_enabled], [])dnl
  _LT_LANG_$1_CONFIG($1)])dnl
])# _LT_LANG


m4_ifndef([AC_PROG_GO], [
############################################################
# NOTE: This macro has been submitted for inclusion into   #
#  GNU Autoconf as AC_PROG_GO.  When it is available in    #
#  a released version of Autoconf we should remove this    #
#  macro and use it instead.                               #
############################################################
m4_defun([AC_PROG_GO],
[AC_LANG_PUSH(Go)dnl
AC_ARG_VAR([GOC],     [Go compiler command])dnl
AC_ARG_VAR([GOFLAGS], [Go compiler flags])dnl
_AC_ARG_VAR_LDFLAGS()dnl
AC_CHECK_TOOL(GOC, gccgo)
if test -z "$GOC"; then
  if test -n "$ac_tool_prefix"; then
    AC_CHECK_PROG(GOC, [${ac_tool_prefix}gccgo], [${ac_tool_prefix}gccgo])
  fi
fi
if test -z "$GOC"; then
  AC_CHECK_PROG(GOC, gccgo, gccgo, false)
fi
])#m4_defun
])#m4_ifndef


# _LT_LANG_DEFAULT_CONFIG
# -----------------------
m4_defun([_LT_LANG_DEFAULT_CONFIG],
[AC_PROVIDE_IFELSE([AC_PROG_CXX],
  [LT_LANG(CXX)],
  [m4_define([AC_PROG_CXX], defn([AC_PROG_CXX])[LT_LANG(CXX)])])

AC_PROVIDE_IFELSE([AC_PROG_F77],
  [LT_LANG(F77)],
  [m4_define([AC_PROG_F77], defn([AC_PROG_F77])[LT_LANG(F77)])])

AC_PROVIDE_IFELSE([AC_PROG_FC],
  [LT_LANG(FC)],
  [m4_define([AC_PROG_FC], defn([AC_PROG_FC])[LT_LANG(FC)])])

dnl The call to [A][M_PROG_GCJ] is quoted like that to stop aclocal
dnl pulling things in needlessly.
AC_PROVIDE_IFELSE([AC_PROG_GCJ],
  [LT_LANG(GCJ)],
  [AC_PROVIDE_IFELSE([A][M_PROG_GCJ],
    [LT_LANG(GCJ)],
    [AC_PROVIDE_IFELSE([LT_PROG_GCJ],
      [LT_LANG(GCJ)],
      [m4_ifdef([AC_PROG_GCJ],
	[m4_define([AC_PROG_GCJ], defn([AC_PROG_GCJ])[LT_LANG(GCJ)])])
       m4_ifdef([A][M_PROG_GCJ],
	[m4_define([A][M_PROG_GCJ], defn([A][M_PROG_GCJ])[LT_LANG(GCJ)])])
       m4_ifdef([LT_PROG_GCJ],
	[m4_define([LT_PROG_GCJ], defn([LT_PROG_GCJ])[LT_LANG(GCJ)])])])])])

AC_PROVIDE_IFELSE([AC_PROG_GO],
  [LT_LANG(GO)],
  [m4_define([AC_PROG_GO], defn([AC_PROG_GO])[LT_LANG(GO)])])

AC_PROVIDE_IFELSE([LT_PROG_RC],
  [LT_LANG(RC)],
  [m4_define([LT_PROG_RC], defn([LT_PROG_RC])[LT_LANG(RC)])])
])# _LT_LANG_DEFAULT_CONFIG

# Obsolete macros:
AU_DEFUN([AC_LIBTOOL_CXX], [LT_LANG(C++)])
AU_DEFUN([AC_LIBTOOL_F77], [LT_LANG(Fortran 77)])
AU_DEFUN([AC_LIBTOOL_FC], [LT_LANG(Fortran)])
AU_DEFUN([AC_LIBTOOL_GCJ], [LT_LANG(Java)])
AU_DEFUN([AC_LIBTOOL_RC], [LT_LANG(Windows Resource)])
dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([AC_LIBTOOL_CXX], [])
dnl AC_DEFUN([AC_LIBTOOL_F77], [])
dnl AC_DEFUN([AC_LIBTOOL_FC], [])
dnl AC_DEFUN([AC_LIBTOOL_GCJ], [])
dnl AC_DEFUN([AC_LIBTOOL_RC], [])


# _LT_TAG_COMPILER
# ----------------
m4_defun([_LT_TAG_COMPILER],
[AC_REQUIRE([AC_PROG_CC])dnl

_LT_DECL([LTCC], [CC], [1], [A C compiler])dnl
_LT_DECL([LTCFLAGS], [CFLAGS], [1], [LTCC compiler flags])dnl
_LT_TAGDECL([CC], [compiler], [1], [A language specific compiler])dnl
_LT_TAGDECL([with_gcc], [GCC], [0], [Is the compiler the GNU compiler?])dnl

# If no C compiler was specified, use CC.
LTCC=${LTCC-"$CC"}

# If no C compiler flags were specified, use CFLAGS.
LTCFLAGS=${LTCFLAGS-"$CFLAGS"}

# Allow CC to be a program name with arguments.
compiler=$CC
])# _LT_TAG_COMPILER


# _LT_COMPILER_BOILERPLATE
# ------------------------
# Check for compiler boilerplate output or warnings with
# the simple compiler test code.
m4_defun([_LT_COMPILER_BOILERPLATE],
[m4_require([_LT_DECL_SED])dnl
ac_outfile=conftest.$ac_objext
echo "$lt_simple_compile_test_code" >conftest.$ac_ext
eval "$ac_compile" 2>&1 >/dev/null | $SED '/^$/d; /^ *+/d' >conftest.err
_lt_compiler_boilerplate=`cat conftest.err`
$RM conftest*
])# _LT_COMPILER_BOILERPLATE


# _LT_LINKER_BOILERPLATE
# ----------------------
# Check for linker boilerplate output or warnings with
# the simple link test code.
m4_defun([_LT_LINKER_BOILERPLATE],
[m4_require([_LT_DECL_SED])dnl
ac_outfile=conftest.$ac_objext
echo "$lt_simple_link_test_code" >conftest.$ac_ext
eval "$ac_link" 2>&1 >/dev/null | $SED '/^$/d; /^ *+/d' >conftest.err
_lt_linker_boilerplate=`cat conftest.err`
$RM -r conftest*
])# _LT_LINKER_BOILERPLATE

# _LT_REQUIRED_DARWIN_CHECKS
# -------------------------
m4_defun_once([_LT_REQUIRED_DARWIN_CHECKS],[
  case $host_os in
    rhapsody* | darwin*)
    AC_CHECK_TOOL([DSYMUTIL], [dsymutil], [:])
    AC_CHECK_TOOL([NMEDIT], [nmedit], [:])
    AC_CHECK_TOOL([LIPO], [lipo], [:])
    AC_CHECK_TOOL([OTOOL], [otool], [:])
    AC_CHECK_TOOL([OTOOL64], [otool64], [:])
    _LT_DECL([], [DSYMUTIL], [1],
      [Tool to manipulate archived DWARF debug symbol files on Mac OS X])
    _LT_DECL([], [NMEDIT], [1],
      [Tool to change global to local symbols on Mac OS X])
    _LT_DECL([], [LIPO], [1],
      [Tool to manipulate fat objects and archives on Mac OS X])
    _LT_DECL([], [OTOOL], [1],
      [ldd/readelf like tool for Mach-O binaries on Mac OS X])
    _LT_DECL([], [OTOOL64], [1],
      [ldd/readelf like tool for 64 bit Mach-O binaries on Mac OS X 10.4])

    AC_CACHE_CHECK([for -single_module linker flag],[lt_cv_apple_cc_single_mod],
      [lt_cv_apple_cc_single_mod=no
      if test -z "${LT_MULTI_MODULE}"; then
	# By default we will add the -single_module flag. You can override
	# by either setting the environment variable LT_MULTI_MODULE
	# non-empty at configure time, or by adding -multi_module to the
	# link flags.
	rm -rf libconftest.dylib*
	echo "int foo(void){return 1;}" > conftest.c
	echo "$LTCC $LTCFLAGS $LDFLAGS -o libconftest.dylib \
-dynamiclib -Wl,-single_module conftest.c" >&AS_MESSAGE_LOG_FD
	$LTCC $LTCFLAGS $LDFLAGS -o libconftest.dylib \
	  -dynamiclib -Wl,-single_module conftest.c 2>conftest.err
        _lt_result=$?
	# If there is a non-empty error log, and "single_module"
	# appears in it, assume the flag caused a linker warning
        if test -s conftest.err && $GREP single_module conftest.err; then
	  cat conftest.err >&AS_MESSAGE_LOG_FD
	# Otherwise, if the output was created with a 0 exit code from
	# the compiler, it worked.
	elif test -f libconftest.dylib && test $_lt_result -eq 0; then
	  lt_cv_apple_cc_single_mod=yes
	else
	  cat conftest.err >&AS_MESSAGE_LOG_FD
	fi
	rm -rf libconftest.dylib*
	rm -f conftest.*
      fi])

    AC_CACHE_CHECK([for -exported_symbols_list linker flag],
      [lt_cv_ld_exported_symbols_list],
      [lt_cv_ld_exported_symbols_list=no
      save_LDFLAGS=$LDFLAGS
      echo "_main" > conftest.sym
      LDFLAGS="$LDFLAGS -Wl,-exported_symbols_list,conftest.sym"
      AC_LINK_IFELSE([AC_LANG_PROGRAM([],[])],
	[lt_cv_ld_exported_symbols_list=yes],
	[lt_cv_ld_exported_symbols_list=no])
	LDFLAGS="$save_LDFLAGS"
    ])

    AC_CACHE_CHECK([for -force_load linker flag],[lt_cv_ld_force_load],
      [lt_cv_ld_force_load=no
      cat > conftest.c << _LT_EOF
int forced_loaded() { return 2;}
_LT_EOF
      echo "$LTCC $LTCFLAGS -c -o conftest.o conftest.c" >&AS_MESSAGE_LOG_FD
      $LTCC $LTCFLAGS -c -o conftest.o conftest.c 2>&AS_MESSAGE_LOG_FD
      echo "$AR cru libconftest.a conftest.o" >&AS_MESSAGE_LOG_FD
      $AR cru libconftest.a conftest.o 2>&AS_MESSAGE_LOG_FD
      echo "$RANLIB libconftest.a" >&AS_MESSAGE_LOG_FD
      $RANLIB libconftest.a 2>&AS_MESSAGE_LOG_FD
      cat > conftest.c << _LT_EOF
int main() { return 0;}
_LT_EOF
      echo "$LTCC $LTCFLAGS $LDFLAGS -o conftest conftest.c -Wl,-force_load,./libconftest.a" >&AS_MESSAGE_LOG_FD
      $LTCC $LTCFLAGS $LDFLAGS -o conftest conftest.c -Wl,-force_load,./libconftest.a 2>conftest.err
      _lt_result=$?
      if test -s conftest.err && $GREP force_load conftest.err; then
	cat conftest.err >&AS_MESSAGE_LOG_FD
      elif test -f conftest && test $_lt_result -eq 0 && $GREP forced_load conftest >/dev/null 2>&1 ; then
	lt_cv_ld_force_load=yes
      else
	cat conftest.err >&AS_MESSAGE_LOG_FD
      fi
        rm -f conftest.err libconftest.a conftest conftest.c
        rm -rf conftest.dSYM
    ])
    case $host_os in
    rhapsody* | darwin1.[[012]])
      _lt_dar_allow_undefined='${wl}-undefined ${wl}suppress' ;;
    darwin1.*)
      _lt_dar_allow_undefined='${wl}-flat_namespace ${wl}-undefined ${wl}suppress' ;;
    darwin*) # darwin 5.x on
      # if running on 10.5 or later, the deployment target defaults
      # to the OS version, if on x86, and 10.4, the deployment
      # target defaults to 10.4. Don't you love it?
      case ${MACOSX_DEPLOYMENT_TARGET-10.0},$host in
	10.0,*86*-darwin8*|10.0,*-darwin[[91]]*)
	  _lt_dar_allow_undefined='${wl}-undefined ${wl}dynamic_lookup' ;;
	10.[[012]]*)
	  _lt_dar_allow_undefined='${wl}-flat_namespace ${wl}-undefined ${wl}suppress' ;;
	10.*)
	  _lt_dar_allow_undefined='${wl}-undefined ${wl}dynamic_lookup' ;;
      esac
    ;;
  esac
    if test "$lt_cv_apple_cc_single_mod" = "yes"; then
      _lt_dar_single_mod='$single_module'
    fi
    if test "$lt_cv_ld_exported_symbols_list" = "yes"; then
      _lt_dar_export_syms=' ${wl}-exported_symbols_list,$output_objdir/${libname}-symbols.expsym'
    else
      _lt_dar_export_syms='~$NMEDIT -s $output_objdir/${libname}-symbols.expsym ${lib}'
    fi
    if test "$DSYMUTIL" != ":" && test "$lt_cv_ld_force_load" = "no"; then
      _lt_dsymutil='~$DSYMUTIL $lib || :'
    else
      _lt_dsymutil=
    fi
    ;;
  esac
])


# _LT_DARWIN_LINKER_FEATURES([TAG])
# ---------------------------------
# Checks for linker and compiler features on darwin
m4_defun([_LT_DARWIN_LINKER_FEATURES],
[
  m4_require([_LT_REQUIRED_DARWIN_CHECKS])
  _LT_TAGVAR(archive_cmds_need_lc, $1)=no
  _LT_TAGVAR(hardcode_direct, $1)=no
  _LT_TAGVAR(hardcode_automatic, $1)=yes
  _LT_TAGVAR(hardcode_shlibpath_var, $1)=unsupported
  if test "$lt_cv_ld_force_load" = "yes"; then
    _LT_TAGVAR(whole_archive_flag_spec, $1)='`for conv in $convenience\"\"; do test  -n \"$conv\" && new_convenience=\"$new_convenience ${wl}-force_load,$conv\"; done; func_echo_all \"$new_convenience\"`'
    m4_case([$1], [F77], [_LT_TAGVAR(compiler_needs_object, $1)=yes],
                  [FC],  [_LT_TAGVAR(compiler_needs_object, $1)=yes])
  else
    _LT_TAGVAR(whole_archive_flag_spec, $1)=''
  fi
  _LT_TAGVAR(link_all_deplibs, $1)=yes
  _LT_TAGVAR(allow_undefined_flag, $1)="$_lt_dar_allow_undefined"
  case $cc_basename in
     ifort*) _lt_dar_can_shared=yes ;;
     *) _lt_dar_can_shared=$GCC ;;
  esac
  if test "$_lt_dar_can_shared" = "yes"; then
    output_verbose_link_cmd=func_echo_all
    _LT_TAGVAR(archive_cmds, $1)="\$CC -dynamiclib \$allow_undefined_flag -o \$lib \$libobjs \$deplibs \$compiler_flags -install_name \$rpath/\$soname \$verstring $_lt_dar_single_mod${_lt_dsymutil}"
    _LT_TAGVAR(module_cmds, $1)="\$CC \$allow_undefined_flag -o \$lib -bundle \$libobjs \$deplibs \$compiler_flags${_lt_dsymutil}"
    _LT_TAGVAR(archive_expsym_cmds, $1)="sed 's,^,_,' < \$export_symbols > \$output_objdir/\${libname}-symbols.expsym~\$CC -dynamiclib \$allow_undefined_flag -o \$lib \$libobjs \$deplibs \$compiler_flags -install_name \$rpath/\$soname \$verstring ${_lt_dar_single_mod}${_lt_dar_export_syms}${_lt_dsymutil}"
    _LT_TAGVAR(module_expsym_cmds, $1)="sed -e 's,^,_,' < \$export_symbols > \$output_objdir/\${libname}-symbols.expsym~\$CC \$allow_undefined_flag -o \$lib -bundle \$libobjs \$deplibs \$compiler_flags${_lt_dar_export_syms}${_lt_dsymutil}"
    m4_if([$1], [CXX],
[   if test "$lt_cv_apple_cc_single_mod" != "yes"; then
      _LT_TAGVAR(archive_cmds, $1)="\$CC -r -keep_private_externs -nostdlib -o \${lib}-master.o \$libobjs~\$CC -dynamiclib \$allow_undefined_flag -o \$lib \${lib}-master.o \$deplibs \$compiler_flags -install_name \$rpath/\$soname \$verstring${_lt_dsymutil}"
      _LT_TAGVAR(archive_expsym_cmds, $1)="sed 's,^,_,' < \$export_symbols > \$output_objdir/\${libname}-symbols.expsym~\$CC -r -keep_private_externs -nostdlib -o \${lib}-master.o \$libobjs~\$CC -dynamiclib \$allow_undefined_flag -o \$lib \${lib}-master.o \$deplibs \$compiler_flags -install_name \$rpath/\$soname \$verstring${_lt_dar_export_syms}${_lt_dsymutil}"
    fi
],[])
  else
  _LT_TAGVAR(ld_shlibs, $1)=no
  fi
])

# _LT_SYS_MODULE_PATH_AIX([TAGNAME])
# ----------------------------------
# Links a minimal program and checks the executable
# for the system default hardcoded library path. In most cases,
# this is /usr/lib:/lib, but when the MPI compilers are used
# the location of the communication and MPI libs are included too.
# If we don't find anything, use the default library path according
# to the aix ld manual.
# Store the results from the different compilers for each TAGNAME.
# Allow to override them for all tags through lt_cv_aix_libpath.
m4_defun([_LT_SYS_MODULE_PATH_AIX],
[m4_require([_LT_DECL_SED])dnl
if test "${lt_cv_aix_libpath+set}" = set; then
  aix_libpath=$lt_cv_aix_libpath
else
  AC_CACHE_VAL([_LT_TAGVAR([lt_cv_aix_libpath_], [$1])],
  [AC_LINK_IFELSE([AC_LANG_PROGRAM],[
  lt_aix_libpath_sed='[
      /Import File Strings/,/^$/ {
	  /^0/ {
	      s/^0  *\([^ ]*\) *$/\1/
	      p
	  }
      }]'
  _LT_TAGVAR([lt_cv_aix_libpath_], [$1])=`dump -H conftest$ac_exeext 2>/dev/null | $SED -n -e "$lt_aix_libpath_sed"`
  # Check for a 64-bit object if we didn't find anything.
  if test -z "$_LT_TAGVAR([lt_cv_aix_libpath_], [$1])"; then
    _LT_TAGVAR([lt_cv_aix_libpath_], [$1])=`dump -HX64 conftest$ac_exeext 2>/dev/null | $SED -n -e "$lt_aix_libpath_sed"`
  fi],[])
  if test -z "$_LT_TAGVAR([lt_cv_aix_libpath_], [$1])"; then
    _LT_TAGVAR([lt_cv_aix_libpath_], [$1])="/usr/lib:/lib"
  fi
  ])
  aix_libpath=$_LT_TAGVAR([lt_cv_aix_libpath_], [$1])
fi
])# _LT_SYS_MODULE_PATH_AIX


# _LT_SHELL_INIT(ARG)
# -------------------
m4_define([_LT_SHELL_INIT],
[m4_divert_text([M4SH-INIT], [$1
])])# _LT_SHELL_INIT



# _LT_PROG_ECHO_BACKSLASH
# -----------------------
# Find how we can fake an echo command that does not interpret backslash.
# In particular, with Autoconf 2.60 or later we add some code to the start
# of the generated configure script which will find a shell with a builtin
# printf (which we can use as an echo command).
m4_defun([_LT_PROG_ECHO_BACKSLASH],
[ECHO='\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\'
ECHO=$ECHO$ECHO$ECHO$ECHO$ECHO
ECHO=$ECHO$ECHO$ECHO$ECHO$ECHO$ECHO

AC_MSG_CHECKING([how to print strings])
# Test print first, because it will be a builtin if present.
if test "X`( print -r -- -n ) 2>/dev/null`" = X-n && \
   test "X`print -r -- $ECHO 2>/dev/null`" = "X$ECHO"; then
  ECHO='print -r --'
elif test "X`printf %s $ECHO 2>/dev/null`" = "X$ECHO"; then
  ECHO='printf %s\n'
else
  # Use this function as a fallback that always works.
  func_fallback_echo ()
  {
    eval 'cat <<_LTECHO_EOF
$[]1
_LTECHO_EOF'
  }
  ECHO='func_fallback_echo'
fi

# func_echo_all arg...
# Invoke $ECHO with all args, space-separated.
func_echo_all ()
{
    $ECHO "$*" 
}

case "$ECHO" in
  printf*) AC_MSG_RESULT([printf]) ;;
  print*) AC_MSG_RESULT([print -r]) ;;
  *) AC_MSG_RESULT([cat]) ;;
esac

m4_ifdef([_AS_DETECT_SUGGESTED],
[_AS_DETECT_SUGGESTED([
  test -n "${ZSH_VERSION+set}${BASH_VERSION+set}" || (
    ECHO='\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\'
    ECHO=$ECHO$ECHO$ECHO$ECHO$ECHO
    ECHO=$ECHO$ECHO$ECHO$ECHO$ECHO$ECHO
    PATH=/empty FPATH=/empty; export PATH FPATH
    test "X`printf %s $ECHO`" = "X$ECHO" \
      || test "X`print -r -- $ECHO`" = "X$ECHO" )])])

_LT_DECL([], [SHELL], [1], [Shell to use when invoking shell scripts])
_LT_DECL([], [ECHO], [1], [An echo program that protects backslashes])
])# _LT_PROG_ECHO_BACKSLASH


# _LT_WITH_SYSROOT
# ----------------
AC_DEFUN([_LT_WITH_SYSROOT],
[AC_MSG_CHECKING([for sysroot])
AC_ARG_WITH([sysroot],
[  --with-sysroot[=DIR] Search for dependent libraries within DIR
                        (or the compiler's sysroot if not specified).],
[], [with_sysroot=no])

dnl lt_sysroot will always be passed unquoted.  We quote it here
dnl in case the user passed a directory name.
lt_sysroot=
case ${with_sysroot} in #(
 yes)
   if test "$GCC" = yes; then
     lt_sysroot=`$CC --print-sysroot 2>/dev/null`
   fi
   ;; #(
 /*)
   lt_sysroot=`echo "$with_sysroot" | sed -e "$sed_quote_subst"`
   ;; #(
 no|'')
   ;; #(
 *)
   AC_MSG_RESULT([${with_sysroot}])
   AC_MSG_ERROR([The sysroot must be an absolute path.])
   ;;
esac

 AC_MSG_RESULT([${lt_sysroot:-no}])
_LT_DECL([], [lt_sysroot], [0], [The root where to search for ]dnl
[dependent libraries, and in which our libraries should be installed.])])

# _LT_ENABLE_LOCK
# ---------------
m4_defun([_LT_ENABLE_LOCK],
[AC_ARG_ENABLE([libtool-lock],
  [AS_HELP_STRING([--disable-libtool-lock],
    [avoid locking (might break parallel builds)])])
test "x$enable_libtool_lock" != xno && enable_libtool_lock=yes

# Some flags need to be propagated to the compiler or linker for good
# libtool support.
case $host in
ia64-*-hpux*)
  # Find out which ABI we are using.
  echo 'int i;' > conftest.$ac_ext
  if AC_TRY_EVAL(ac_compile); then
    case `/usr/bin/file conftest.$ac_objext` in
      *ELF-32*)
	HPUX_IA64_MODE="32"
	;;
      *ELF-64*)
	HPUX_IA64_MODE="64"
	;;
    esac
  fi
  rm -rf conftest*
  ;;
*-*-irix6*)
  # Find out which ABI we are using.
  echo '[#]line '$LINENO' "configure"' > conftest.$ac_ext
  if AC_TRY_EVAL(ac_compile); then
    if test "$lt_cv_prog_gnu_ld" = yes; then
      case `/usr/bin/file conftest.$ac_objext` in
	*32-bit*)
	  LD="${LD-ld} -melf32bsmip"
	  ;;
	*N32*)
	  LD="${LD-ld} -melf32bmipn32"
	  ;;
	*64-bit*)
	  LD="${LD-ld} -melf64bmip"
	;;
      esac
    else
      case `/usr/bin/file conftest.$ac_objext` in
	*32-bit*)
	  LD="${LD-ld} -32"
	  ;;
	*N32*)
	  LD="${LD-ld} -n32"
	  ;;
	*64-bit*)
	  LD="${LD-ld} -64"
	  ;;
      esac
    fi
  fi
  rm -rf conftest*
  ;;

x86_64-*kfreebsd*-gnu|x86_64-*linux*|powerpc*-*linux*| \
s390*-*linux*|s390*-*tpf*|sparc*-*linux*)
  # Find out which ABI we are using.
  echo 'int i;' > conftest.$ac_ext
  if AC_TRY_EVAL(ac_compile); then
    case `/usr/bin/file conftest.o` in
      *32-bit*)
	case $host in
	  x86_64-*kfreebsd*-gnu)
	    LD="${LD-ld} -m elf_i386_fbsd"
	    ;;
	  x86_64-*linux*)
	    LD="${LD-ld} -m elf_i386"
	    ;;
	  powerpc64le-*linux*)
	    LD="${LD-ld} -m elf32lppclinux"
	    ;;
	  powerpc64-*linux*)
	    LD="${LD-ld} -m elf32ppclinux"
	    ;;
	  s390x-*linux*)
	    LD="${LD-ld} -m elf_s390"
	    ;;
	  sparc64-*linux*)
	    LD="${LD-ld} -m elf32_sparc"
	    ;;
	esac
	;;
      *64-bit*)
	case $host in
	  x86_64-*kfreebsd*-gnu)
	    LD="${LD-ld} -m elf_x86_64_fbsd"
	    ;;
	  x86_64-*linux*)
	    LD="${LD-ld} -m elf_x86_64"
	    ;;
	  powerpcle-*linux*)
	    LD="${LD-ld} -m elf64lppc"
	    ;;
	  powerpc-*linux*)
	    LD="${LD-ld} -m elf64ppc"
	    ;;
	  s390*-*linux*|s390*-*tpf*)
	    LD="${LD-ld} -m elf64_s390"
	    ;;
	  sparc*-*linux*)
	    LD="${LD-ld} -m elf64_sparc"
	    ;;
	esac
	;;
    esac
  fi
  rm -rf conftest*
  ;;

*-*-sco3.2v5*)
  # On SCO OpenServer 5, we need -belf to get full-featured binaries.
  SAVE_CFLAGS="$CFLAGS"
  CFLAGS="$CFLAGS -belf"
  AC_CACHE_CHECK([whether the C compiler needs -belf], lt_cv_cc_needs_belf,
    [AC_LANG_PUSH(C)
     AC_LINK_IFELSE([AC_LANG_PROGRAM([[]],[[]])],[lt_cv_cc_needs_belf=yes],[lt_cv_cc_needs_belf=no])
     AC_LANG_POP])
  if test x"$lt_cv_cc_needs_belf" != x"yes"; then
    # this is probably gcc 2.8.0, egcs 1.0 or newer; no need for -belf
    CFLAGS="$SAVE_CFLAGS"
  fi
  ;;
*-*solaris*)
  # Find out which ABI we are using.
  echo 'int i;' > conftest.$ac_ext
  if AC_TRY_EVAL(ac_compile); then
    case `/usr/bin/file conftest.o` in
    *64-bit*)
      case $lt_cv_prog_gnu_ld in
      yes*)
        case $host in
        i?86-*-solaris*)
          LD="${LD-ld} -m elf_x86_64"
          ;;
        sparc*-*-solaris*)
          LD="${LD-ld} -m elf64_sparc"
          ;;
        esac
        # GNU ld 2.21 introduced _sol2 emulations.  Use them if available.
        if ${LD-ld} -V | grep _sol2 >/dev/null 2>&1; then
          LD="${LD-ld}_sol2"
        fi
        ;;
      *)
	if ${LD-ld} -64 -r -o conftest2.o conftest.o >/dev/null 2>&1; then
	  LD="${LD-ld} -64"
	fi
	;;
      esac
      ;;
    esac
  fi
  rm -rf conftest*
  ;;
esac

need_locks="$enable_libtool_lock"
])# _LT_ENABLE_LOCK


# _LT_PROG_AR
# -----------
m4_defun([_LT_PROG_AR],
[AC_CHECK_TOOLS(AR, [ar], false)
: ${AR=ar}
: ${AR_FLAGS=cru}
_LT_DECL([], [AR], [1], [The archiver])
_LT_DECL([], [AR_FLAGS], [1], [Flags to create an archive])

AC_CACHE_CHECK([for archiver @FILE support], [lt_cv_ar_at_file],
  [lt_cv_ar_at_file=no
   AC_COMPILE_IFELSE([AC_LANG_PROGRAM],
     [echo conftest.$ac_objext > conftest.lst
      lt_ar_try='$AR $AR_FLAGS libconftest.a @conftest.lst >&AS_MESSAGE_LOG_FD'
      AC_TRY_EVAL([lt_ar_try])
      if test "$ac_status" -eq 0; then
	# Ensure the archiver fails upon bogus file names.
	rm -f conftest.$ac_objext libconftest.a
	AC_TRY_EVAL([lt_ar_try])
	if test "$ac_status" -ne 0; then
          lt_cv_ar_at_file=@
        fi
      fi
      rm -f conftest.* libconftest.a
     ])
  ])

if test "x$lt_cv_ar_at_file" = xno; then
  archiver_list_spec=
else
  archiver_list_spec=$lt_cv_ar_at_file
fi
_LT_DECL([], [archiver_list_spec], [1],
  [How to feed a file listing to the archiver])
])# _LT_PROG_AR


# _LT_CMD_OLD_ARCHIVE
# -------------------
m4_defun([_LT_CMD_OLD_ARCHIVE],
[_LT_PROG_AR

AC_CHECK_TOOL(STRIP, strip, :)
test -z "$STRIP" && STRIP=:
_LT_DECL([], [STRIP], [1], [A symbol stripping program])

AC_CHECK_TOOL(RANLIB, ranlib, :)
test -z "$RANLIB" && RANLIB=:
_LT_DECL([], [RANLIB], [1],
    [Commands used to install an old-style archive])

# Determine commands to create old-style static archives.
old_archive_cmds='$AR $AR_FLAGS $oldlib$oldobjs'
old_postinstall_cmds='chmod 644 $oldlib'
old_postuninstall_cmds=

if test -n "$RANLIB"; then
  case $host_os in
  openbsd*)
    old_postinstall_cmds="$old_postinstall_cmds~\$RANLIB -t \$tool_oldlib"
    ;;
  *)
    old_postinstall_cmds="$old_postinstall_cmds~\$RANLIB \$tool_oldlib"
    ;;
  esac
  old_archive_cmds="$old_archive_cmds~\$RANLIB \$tool_oldlib"
fi

case $host_os in
  darwin*)
    lock_old_archive_extraction=yes ;;
  *)
    lock_old_archive_extraction=no ;;
esac
_LT_DECL([], [old_postinstall_cmds], [2])
_LT_DECL([], [old_postuninstall_cmds], [2])
_LT_TAGDECL([], [old_archive_cmds], [2],
    [Commands used to build an old-style archive])
_LT_DECL([], [lock_old_archive_extraction], [0],
    [Whether to use a lock for old archive extraction])
])# _LT_CMD_OLD_ARCHIVE


# _LT_COMPILER_OPTION(MESSAGE, VARIABLE-NAME, FLAGS,
#		[OUTPUT-FILE], [ACTION-SUCCESS], [ACTION-FAILURE])
# ----------------------------------------------------------------
# Check whether the given compiler option works
AC_DEFUN([_LT_COMPILER_OPTION],
[m4_require([_LT_FILEUTILS_DEFAULTS])dnl
m4_require([_LT_DECL_SED])dnl
AC_CACHE_CHECK([$1], [$2],
  [$2=no
   m4_if([$4], , [ac_outfile=conftest.$ac_objext], [ac_outfile=$4])
   echo "$lt_simple_compile_test_code" > conftest.$ac_ext
   lt_compiler_flag="$3"
   # Insert the option either (1) after the last *FLAGS variable, or
   # (2) before a word containing "conftest.", or (3) at the end.
   # Note that $ac_compile itself does not contain backslashes and begins
   # with a dollar sign (not a hyphen), so the echo should work correctly.
   # The option is referenced via a variable to avoid confusing sed.
   lt_compile=`echo "$ac_compile" | $SED \
   -e 's:.*FLAGS}\{0,1\} :&$lt_compiler_flag :; t' \
   -e 's: [[^ ]]*conftest\.: $lt_compiler_flag&:; t' \
   -e 's:$: $lt_compiler_flag:'`
   (eval echo "\"\$as_me:$LINENO: $lt_compile\"" >&AS_MESSAGE_LOG_FD)
   (eval "$lt_compile" 2>conftest.err)
   ac_status=$?
   cat conftest.err >&AS_MESSAGE_LOG_FD
   echo "$as_me:$LINENO: \$? = $ac_status" >&AS_MESSAGE_LOG_FD
   if (exit $ac_status) && test -s "$ac_outfile"; then
     # The compiler can only warn and ignore the option if not recognized
     # So say no if there are warnings other than the usual output.
     $ECHO "$_lt_compiler_boilerplate" | $SED '/^$/d' >conftest.exp
     $SED '/^$/d; /^ *+/d' conftest.err >conftest.er2
     if test ! -s conftest.er2 || diff conftest.exp conftest.er2 >/dev/null; then
       $2=yes
     fi
   fi
   $RM conftest*
])

if test x"[$]$2" = xyes; then
    m4_if([$5], , :, [$5])
else
    m4_if([$6], , :, [$6])
fi
])# _LT_COMPILER_OPTION

# Old name:
AU_ALIAS([AC_LIBTOOL_COMPILER_OPTION], [_LT_COMPILER_OPTION])
dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([AC_LIBTOOL_COMPILER_OPTION], [])


# _LT_LINKER_OPTION(MESSAGE, VARIABLE-NAME, FLAGS,
#                  [ACTION-SUCCESS], [ACTION-FAILURE])
# ----------------------------------------------------
# Check whether the given linker option works
AC_DEFUN([_LT_LINKER_OPTION],
[m4_require([_LT_FILEUTILS_DEFAULTS])dnl
m4_require([_LT_DECL_SED])dnl
AC_CACHE_CHECK([$1], [$2],
  [$2=no
   save_LDFLAGS="$LDFLAGS"
   LDFLAGS="$LDFLAGS $3"
   echo "$lt_simple_link_test_code" > conftest.$ac_ext
   if (eval $ac_link 2>conftest.err) && test -s conftest$ac_exeext; then
     # The linker can only warn and ignore the option if not recognized
     # So say no if there are warnings
     if test -s conftest.err; then
       # Append any errors to the config.log.
       cat conftest.err 1>&AS_MESSAGE_LOG_FD
       $ECHO "$_lt_linker_boilerplate" | $SED '/^$/d' > conftest.exp
       $SED '/^$/d; /^ *+/d' conftest.err >conftest.er2
       if diff conftest.exp conftest.er2 >/dev/null; then
         $2=yes
       fi
     else
       $2=yes
     fi
   fi
   $RM -r conftest*
   LDFLAGS="$save_LDFLAGS"
])

if test x"[$]$2" = xyes; then
    m4_if([$4], , :, [$4])
else
    m4_if([$5], , :, [$5])
fi
])# _LT_LINKER_OPTION

# Old name:
AU_ALIAS([AC_LIBTOOL_LINKER_OPTION], [_LT_LINKER_OPTION])
dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([AC_LIBTOOL_LINKER_OPTION], [])


# LT_CMD_MAX_LEN
#---------------
AC_DEFUN([LT_CMD_MAX_LEN],
[AC_REQUIRE([AC_CANONICAL_HOST])dnl
# find the maximum length of command line arguments
AC_MSG_CHECKING([the maximum length of command line arguments])
AC_CACHE_VAL([lt_cv_sys_max_cmd_len], [dnl
  i=0
  teststring="ABCD"

  case $build_os in
  msdosdjgpp*)
    # On DJGPP, this test can blow up pretty badly due to problems in libc
    # (any single argument exceeding 2000 bytes causes a buffer overrun
    # during glob expansion).  Even if it were fixed, the result of this
    # check would be larger than it should be.
    lt_cv_sys_max_cmd_len=12288;    # 12K is about right
    ;;

  gnu*)
    # Under GNU Hurd, this test is not required because there is
    # no limit to the length of command line arguments.
    # Libtool will interpret -1 as no limit whatsoever
    lt_cv_sys_max_cmd_len=-1;
    ;;

  cygwin* | mingw* | cegcc*)
    # On Win9x/ME, this test blows up -- it succeeds, but takes
    # about 5 minutes as the teststring grows exponentially.
    # Worse, since 9x/ME are not pre-emptively multitasking,
    # you end up with a "frozen" computer, even though with patience
    # the test eventually succeeds (with a max line length of 256k).
    # Instead, let's just punt: use the minimum linelength reported by
    # all of the supported platforms: 8192 (on NT/2K/XP).
    lt_cv_sys_max_cmd_len=8192;
    ;;

  mint*)
    # On MiNT this can take a long time and run out of memory.
    lt_cv_sys_max_cmd_len=8192;
    ;;

  amigaos*)
    # On AmigaOS with pdksh, this test takes hours, literally.
    # So we just punt and use a minimum line length of 8192.
    lt_cv_sys_max_cmd_len=8192;
    ;;

  netbsd* | freebsd* | openbsd* | darwin* | dragonfly*)
    # This has been around since 386BSD, at least.  Likely further.
    if test -x /sbin/sysctl; then
      lt_cv_sys_max_cmd_len=`/sbin/sysctl -n kern.argmax`
    elif test -x /usr/sbin/sysctl; then
      lt_cv_sys_max_cmd_len=`/usr/sbin/sysctl -n kern.argmax`
    else
      lt_cv_sys_max_cmd_len=65536	# usable default for all BSDs
    fi
    # And add a safety zone
    lt_cv_sys_max_cmd_len=`expr $lt_cv_sys_max_cmd_len \/ 4`
    lt_cv_sys_max_cmd_len=`expr $lt_cv_sys_max_cmd_len \* 3`
    ;;

  interix*)
    # We know the value 262144 and hardcode it with a safety zone (like BSD)
    lt_cv_sys_max_cmd_len=196608
    ;;

  os2*)
    # The test takes a long time on OS/2.
    lt_cv_sys_max_cmd_len=8192
    ;;

  osf*)
    # Dr. Hans Ekkehard Plesser reports seeing a kernel panic running configure
    # due to this test when exec_disable_arg_limit is 1 on Tru64. It is not
    # nice to cause kernel panics so lets avoid the loop below.
    # First set a reasonable default.
    lt_cv_sys_max_cmd_len=16384
    #
    if test -x /sbin/sysconfig; then
      case `/sbin/sysconfig -q proc exec_disable_arg_limit` in
        *1*) lt_cv_sys_max_cmd_len=-1 ;;
      esac
    fi
    ;;
  sco3.2v5*)
    lt_cv_sys_max_cmd_len=102400
    ;;
  sysv5* | sco5v6* | sysv4.2uw2*)
    kargmax=`grep ARG_MAX /etc/conf/cf.d/stune 2>/dev/null`
    if test -n "$kargmax"; then
      lt_cv_sys_max_cmd_len=`echo $kargmax | sed 's/.*[[	 ]]//'`
    else
      lt_cv_sys_max_cmd_len=32768
    fi
    ;;
  *)
    lt_cv_sys_max_cmd_len=`(getconf ARG_MAX) 2> /dev/null`
    if test -n "$lt_cv_sys_max_cmd_len"; then
      lt_cv_sys_max_cmd_len=`expr $lt_cv_sys_max_cmd_len \/ 4`
      lt_cv_sys_max_cmd_len=`expr $lt_cv_sys_max_cmd_len \* 3`
    else
      # Make teststring a little bigger before we do anything with it.
      # a 1K string should be a reasonable start.
      for i in 1 2 3 4 5 6 7 8 ; do
        teststring=$teststring$teststring
      done
      SHELL=${SHELL-${CONFIG_SHELL-/bin/sh}}
      # If test is not a shell built-in, we'll probably end up computing a
      # maximum length that is only half of the actual maximum length, but
      # we can't tell.
      while { test "X"`env echo "$teststring$teststring" 2>/dev/null` \
	         = "X$teststring$teststring"; } >/dev/null 2>&1 &&
	      test $i != 17 # 1/2 MB should be enough
      do
        i=`expr $i + 1`
        teststring=$teststring$teststring
      done
      # Only check the string length outside the loop.
      lt_cv_sys_max_cmd_len=`expr "X$teststring" : ".*" 2>&1`
      teststring=
      # Add a significant safety factor because C++ compilers can tack on
      # massive amounts of additional arguments before passing them to the
      # linker.  It appears as though 1/2 is a usable value.
      lt_cv_sys_max_cmd_len=`expr $lt_cv_sys_max_cmd_len \/ 2`
    fi
    ;;
  esac
])
if test -n $lt_cv_sys_max_cmd_len ; then
  AC_MSG_RESULT($lt_cv_sys_max_cmd_len)
else
  AC_MSG_RESULT(none)
fi
max_cmd_len=$lt_cv_sys_max_cmd_len
_LT_DECL([], [max_cmd_len], [0],
    [What is the maximum length of a command?])
])# LT_CMD_MAX_LEN

# Old name:
AU_ALIAS([AC_LIBTOOL_SYS_MAX_CMD_LEN], [LT_CMD_MAX_LEN])
dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([AC_LIBTOOL_SYS_MAX_CMD_LEN], [])


# _LT_HEADER_DLFCN
# ----------------
m4_defun([_LT_HEADER_DLFCN],
[AC_CHECK_HEADERS([dlfcn.h], [], [], [AC_INCLUDES_DEFAULT])dnl
])# _LT_HEADER_DLFCN


# _LT_TRY_DLOPEN_SELF (ACTION-IF-TRUE, ACTION-IF-TRUE-W-USCORE,
#                      ACTION-IF-FALSE, ACTION-IF-CROSS-COMPILING)
# ----------------------------------------------------------------
m4_defun([_LT_TRY_DLOPEN_SELF],
[m4_require([_LT_HEADER_DLFCN])dnl
if test "$cross_compiling" = yes; then :
  [$4]
else
  lt_dlunknown=0; lt_dlno_uscore=1; lt_dlneed_uscore=2
  lt_status=$lt_dlunknown
  cat > conftest.$ac_ext <<_LT_EOF
[#line $LINENO "configure"
#include "confdefs.h"

#if HAVE_DLFCN_H
#include <dlfcn.h>
#endif

#include <stdio.h>

#ifdef RTLD_GLOBAL
#  define LT_DLGLOBAL		RTLD_GLOBAL
#else
#  ifdef DL_GLOBAL
#    define LT_DLGLOBAL		DL_GLOBAL
#  else
#    define LT_DLGLOBAL		0
#  endif
#endif

/* We may have to define LT_DLLAZY_OR_NOW in the command line if we
   find out it does not work in some platform. */
#ifndef LT_DLLAZY_OR_NOW
#  ifdef RTLD_LAZY
#    define LT_DLLAZY_OR_NOW		RTLD_LAZY
#  else
#    ifdef DL_LAZY
#      define LT_DLLAZY_OR_NOW		DL_LAZY
#    else
#      ifdef RTLD_NOW
#        define LT_DLLAZY_OR_NOW	RTLD_NOW
#      else
#        ifdef DL_NOW
#          define LT_DLLAZY_OR_NOW	DL_NOW
#        else
#          define LT_DLLAZY_OR_NOW	0
#        endif
#      endif
#    endif
#  endif
#endif

/* When -fvisbility=hidden is used, assume the code has been annotated
   correspondingly for the symbols needed.  */
#if defined(__GNUC__) && (((__GNUC__ == 3) && (__GNUC_MINOR__ >= 3)) || (__GNUC__ > 3))
int fnord () __attribute__((visibility("default")));
#endif

int fnord () { return 42; }
int main ()
{
  void *self = dlopen (0, LT_DLGLOBAL|LT_DLLAZY_OR_NOW);
  int status = $lt_dlunknown;

  if (self)
    {
      if (dlsym (self,"fnord"))       status = $lt_dlno_uscore;
      else
        {
	  if (dlsym( self,"_fnord"))  status = $lt_dlneed_uscore;
          else puts (dlerror ());
	}
      /* dlclose (self); */
    }
  else
    puts (dlerror ());

  return status;
}]
_LT_EOF
  if AC_TRY_EVAL(ac_link) && test -s conftest${ac_exeext} 2>/dev/null; then
    (./conftest; exit; ) >&AS_MESSAGE_LOG_FD 2>/dev/null
    lt_status=$?
    case x$lt_status in
      x$lt_dlno_uscore) $1 ;;
      x$lt_dlneed_uscore) $2 ;;
      x$lt_dlunknown|x*) $3 ;;
    esac
  else :
    # compilation failed
    $3
  fi
fi
rm -fr conftest*
])# _LT_TRY_DLOPEN_SELF


# LT_SYS_DLOPEN_SELF
# ------------------
AC_DEFUN([LT_SYS_DLOPEN_SELF],
[m4_require([_LT_HEADER_DLFCN])dnl
if test "x$enable_dlopen" != xyes; then
  enable_dlopen=unknown
  enable_dlopen_self=unknown
  enable_dlopen_self_static=unknown
else
  lt_cv_dlopen=no
  lt_cv_dlopen_libs=

  case $host_os in
  beos*)
    lt_cv_dlopen="load_add_on"
    lt_cv_dlopen_libs=
    lt_cv_dlopen_self=yes
    ;;

  mingw* | pw32* | cegcc*)
    lt_cv_dlopen="LoadLibrary"
    lt_cv_dlopen_libs=
    ;;

  cygwin*)
    lt_cv_dlopen="dlopen"
    lt_cv_dlopen_libs=
    ;;

  darwin*)
  # if libdl is installed we need to link against it
    AC_CHECK_LIB([dl], [dlopen],
		[lt_cv_dlopen="dlopen" lt_cv_dlopen_libs="-ldl"],[
    lt_cv_dlopen="dyld"
    lt_cv_dlopen_libs=
    lt_cv_dlopen_self=yes
    ])
    ;;

  *)
    AC_CHECK_FUNC([shl_load],
	  [lt_cv_dlopen="shl_load"],
      [AC_CHECK_LIB([dld], [shl_load],
	    [lt_cv_dlopen="shl_load" lt_cv_dlopen_libs="-ldld"],
	[AC_CHECK_FUNC([dlopen],
	      [lt_cv_dlopen="dlopen"],
	  [AC_CHECK_LIB([dl], [dlopen],
		[lt_cv_dlopen="dlopen" lt_cv_dlopen_libs="-ldl"],
	    [AC_CHECK_LIB([svld], [dlopen],
		  [lt_cv_dlopen="dlopen" lt_cv_dlopen_libs="-lsvld"],
	      [AC_CHECK_LIB([dld], [dld_link],
		    [lt_cv_dlopen="dld_link" lt_cv_dlopen_libs="-ldld"])
	      ])
	    ])
	  ])
	])
      ])
    ;;
  esac

  if test "x$lt_cv_dlopen" != xno; then
    enable_dlopen=yes
  else
    enable_dlopen=no
  fi

  case $lt_cv_dlopen in
  dlopen)
    save_CPPFLAGS="$CPPFLAGS"
    test "x$ac_cv_header_dlfcn_h" = xyes && CPPFLAGS="$CPPFLAGS -DHAVE_DLFCN_H"

    save_LDFLAGS="$LDFLAGS"
    wl=$lt_prog_compiler_wl eval LDFLAGS=\"\$LDFLAGS $export_dynamic_flag_spec\"

    save_LIBS="$LIBS"
    LIBS="$lt_cv_dlopen_libs $LIBS"

    AC_CACHE_CHECK([whether a program can dlopen itself],
	  lt_cv_dlopen_self, [dnl
	  _LT_TRY_DLOPEN_SELF(
	    lt_cv_dlopen_self=yes, lt_cv_dlopen_self=yes,
	    lt_cv_dlopen_self=no, lt_cv_dlopen_self=cross)
    ])

    if test "x$lt_cv_dlopen_self" = xyes; then
      wl=$lt_prog_compiler_wl eval LDFLAGS=\"\$LDFLAGS $lt_prog_compiler_static\"
      AC_CACHE_CHECK([whether a statically linked program can dlopen itself],
	  lt_cv_dlopen_self_static, [dnl
	  _LT_TRY_DLOPEN_SELF(
	    lt_cv_dlopen_self_static=yes, lt_cv_dlopen_self_static=yes,
	    lt_cv_dlopen_self_static=no,  lt_cv_dlopen_self_static=cross)
      ])
    fi

    CPPFLAGS="$save_CPPFLAGS"
    LDFLAGS="$save_LDFLAGS"
    LIBS="$save_LIBS"
    ;;
  esac

  case $lt_cv_dlopen_self in
  yes|no) enable_dlopen_self=$lt_cv_dlopen_self ;;
  *) enable_dlopen_self=unknown ;;
  esac

  case $lt_cv_dlopen_self_static in
  yes|no) enable_dlopen_self_static=$lt_cv_dlopen_self_static ;;
  *) enable_dlopen_self_static=unknown ;;
  esac
fi
_LT_DECL([dlopen_support], [enable_dlopen], [0],
	 [Whether dlopen is supported])
_LT_DECL([dlopen_self], [enable_dlopen_self], [0],
	 [Whether dlopen of programs is supported])
_LT_DECL([dlopen_self_static], [enable_dlopen_self_static], [0],
	 [Whether dlopen of statically linked programs is supported])
])# LT_SYS_DLOPEN_SELF

# Old name:
AU_ALIAS([AC_LIBTOOL_DLOPEN_SELF], [LT_SYS_DLOPEN_SELF])
dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([AC_LIBTOOL_DLOPEN_SELF], [])


# _LT_COMPILER_C_O([TAGNAME])
# ---------------------------
# Check to see if options -c and -o are simultaneously supported by compiler.
# This macro does not hard code the compiler like AC_PROG_CC_C_O.
m4_defun([_LT_COMPILER_C_O],
[m4_require([_LT_DECL_SED])dnl
m4_require([_LT_FILEUTILS_DEFAULTS])dnl
m4_require([_LT_TAG_COMPILER])dnl
AC_CACHE_CHECK([if $compiler supports -c -o file.$ac_objext],
  [_LT_TAGVAR(lt_cv_prog_compiler_c_o, $1)],
  [_LT_TAGVAR(lt_cv_prog_compiler_c_o, $1)=no
   $RM -r conftest 2>/dev/null
   mkdir conftest
   cd conftest
   mkdir out
   echo "$lt_simple_compile_test_code" > conftest.$ac_ext

   lt_compiler_flag="-o out/conftest2.$ac_objext"
   # Insert the option either (1) after the last *FLAGS variable, or
   # (2) before a word containing "conftest.", or (3) at the end.
   # Note that $ac_compile itself does not contain backslashes and begins
   # with a dollar sign (not a hyphen), so the echo should work correctly.
   lt_compile=`echo "$ac_compile" | $SED \
   -e 's:.*FLAGS}\{0,1\} :&$lt_compiler_flag :; t' \
   -e 's: [[^ ]]*conftest\.: $lt_compiler_flag&:; t' \
   -e 's:$: $lt_compiler_flag:'`
   (eval echo "\"\$as_me:$LINENO: $lt_compile\"" >&AS_MESSAGE_LOG_FD)
   (eval "$lt_compile" 2>out/conftest.err)
   ac_status=$?
   cat out/conftest.err >&AS_MESSAGE_LOG_FD
   echo "$as_me:$LINENO: \$? = $ac_status" >&AS_MESSAGE_LOG_FD
   if (exit $ac_status) && test -s out/conftest2.$ac_objext
   then
     # The compiler can only warn and ignore the option if not recognized
     # So say no if there are warnings
     $ECHO "$_lt_compiler_boilerplate" | $SED '/^$/d' > out/conftest.exp
     $SED '/^$/d; /^ *+/d' out/conftest.err >out/conftest.er2
     if test ! -s out/conftest.er2 || diff out/conftest.exp out/conftest.er2 >/dev/null; then
       _LT_TAGVAR(lt_cv_prog_compiler_c_o, $1)=yes
     fi
   fi
   chmod u+w . 2>&AS_MESSAGE_LOG_FD
   $RM conftest*
   # SGI C++ compiler will create directory out/ii_files/ for
   # template instantiation
   test -d out/ii_files && $RM out/ii_files/* && rmdir out/ii_files
   $RM out/* && rmdir out
   cd ..
   $RM -r conftest
   $RM conftest*
])
_LT_TAGDECL([compiler_c_o], [lt_cv_prog_compiler_c_o], [1],
	[Does compiler simultaneously support -c and -o options?])
])# _LT_COMPILER_C_O


# _LT_COMPILER_FILE_LOCKS([TAGNAME])
# ----------------------------------
# Check to see if we can do hard links to lock some files if needed
m4_defun([_LT_COMPILER_FILE_LOCKS],
[m4_require([_LT_ENABLE_LOCK])dnl
m4_require([_LT_FILEUTILS_DEFAULTS])dnl
_LT_COMPILER_C_O([$1])

hard_links="nottested"
if test "$_LT_TAGVAR(lt_cv_prog_compiler_c_o, $1)" = no && test "$need_locks" != no; then
  # do not overwrite the value of need_locks provided by the user
  AC_MSG_CHECKING([if we can lock with hard links])
  hard_links=yes
  $RM conftest*
  ln conftest.a conftest.b 2>/dev/null && hard_links=no
  touch conftest.a
  ln conftest.a conftest.b 2>&5 || hard_links=no
  ln conftest.a conftest.b 2>/dev/null && hard_links=no
  AC_MSG_RESULT([$hard_links])
  if test "$hard_links" = no; then
    AC_MSG_WARN([`$CC' does not support `-c -o', so `make -j' may be unsafe])
    need_locks=warn
  fi
else
  need_locks=no
fi
_LT_DECL([], [need_locks], [1], [Must we lock files when doing compilation?])
])# _LT_COMPILER_FILE_LOCKS


# _LT_CHECK_OBJDIR
# ----------------
m4_defun([_LT_CHECK_OBJDIR],
[AC_CACHE_CHECK([for objdir], [lt_cv_objdir],
[rm -f .libs 2>/dev/null
mkdir .libs 2>/dev/null
if test -d .libs; then
  lt_cv_objdir=.libs
else
  # MS-DOS does not allow filenames that begin with a dot.
  lt_cv_objdir=_libs
fi
rmdir .libs 2>/dev/null])
objdir=$lt_cv_objdir
_LT_DECL([], [objdir], [0],
         [The name of the directory that contains temporary libtool files])dnl
m4_pattern_allow([LT_OBJDIR])dnl
AC_DEFINE_UNQUOTED(LT_OBJDIR, "$lt_cv_objdir/",
  [Define to the sub-directory in which libtool stores uninstalled libraries.])
])# _LT_CHECK_OBJDIR


# _LT_LINKER_HARDCODE_LIBPATH([TAGNAME])
# --------------------------------------
# Check hardcoding attributes.
m4_defun([_LT_LINKER_HARDCODE_LIBPATH],
[AC_MSG_CHECKING([how to hardcode library paths into programs])
_LT_TAGVAR(hardcode_action, $1)=
if test -n "$_LT_TAGVAR(hardcode_libdir_flag_spec, $1)" ||
   test -n "$_LT_TAGVAR(runpath_var, $1)" ||
   test "X$_LT_TAGVAR(hardcode_automatic, $1)" = "Xyes" ; then

  # We can hardcode non-existent directories.
  if test "$_LT_TAGVAR(hardcode_direct, $1)" != no &&
     # If the only mechanism to avoid hardcoding is shlibpath_var, we
     # have to relink, otherwise we might link with an installed library
     # when we should be linking with a yet-to-be-installed one
     ## test "$_LT_TAGVAR(hardcode_shlibpath_var, $1)" != no &&
     test "$_LT_TAGVAR(hardcode_minus_L, $1)" != no; then
    # Linking always hardcodes the temporary library directory.
    _LT_TAGVAR(hardcode_action, $1)=relink
  else
    # We can link without hardcoding, and we can hardcode nonexisting dirs.
    _LT_TAGVAR(hardcode_action, $1)=immediate
  fi
else
  # We cannot hardcode anything, or else we can only hardcode existing
  # directories.
  _LT_TAGVAR(hardcode_action, $1)=unsupported
fi
AC_MSG_RESULT([$_LT_TAGVAR(hardcode_action, $1)])

if test "$_LT_TAGVAR(hardcode_action, $1)" = relink ||
   test "$_LT_TAGVAR(inherit_rpath, $1)" = yes; then
  # Fast installation is not supported
  enable_fast_install=no
elif test "$shlibpath_overrides_runpath" = yes ||
     test "$enable_shared" = no; then
  # Fast installation is not necessary
  enable_fast_install=needless
fi
_LT_TAGDECL([], [hardcode_action], [0],
    [How to hardcode a shared library path into an executable])
])# _LT_LINKER_HARDCODE_LIBPATH


# _LT_CMD_STRIPLIB
# ----------------
m4_defun([_LT_CMD_STRIPLIB],
[m4_require([_LT_DECL_EGREP])
striplib=
old_striplib=
AC_MSG_CHECKING([whether stripping libraries is possible])
if test -n "$STRIP" && $STRIP -V 2>&1 | $GREP "GNU strip" >/dev/null; then
  test -z "$old_striplib" && old_striplib="$STRIP --strip-debug"
  test -z "$striplib" && striplib="$STRIP --strip-unneeded"
  AC_MSG_RESULT([yes])
else
# FIXME - insert some real tests, host_os isn't really good enough
  case $host_os in
  darwin*)
    if test -n "$STRIP" ; then
      striplib="$STRIP -x"
      old_striplib="$STRIP -S"
      AC_MSG_RESULT([yes])
    else
      AC_MSG_RESULT([no])
    fi
    ;;
  *)
    AC_MSG_RESULT([no])
    ;;
  esac
fi
_LT_DECL([], [old_striplib], [1], [Commands to strip libraries])
_LT_DECL([], [striplib], [1])
])# _LT_CMD_STRIPLIB


# _LT_SYS_DYNAMIC_LINKER([TAG])
# -----------------------------
# PORTME Fill in your ld.so characteristics
m4_defun([_LT_SYS_DYNAMIC_LINKER],
[AC_REQUIRE([AC_CANONICAL_HOST])dnl
m4_require([_LT_DECL_EGREP])dnl
m4_require([_LT_FILEUTILS_DEFAULTS])dnl
m4_require([_LT_DECL_OBJDUMP])dnl
m4_require([_LT_DECL_SED])dnl
m4_require([_LT_CHECK_SHELL_FEATURES])dnl
AC_MSG_CHECKING([dynamic linker characteristics])
m4_if([$1],
	[], [
if test "$GCC" = yes; then
  case $host_os in
    darwin*) lt_awk_arg="/^libraries:/,/LR/" ;;
    *) lt_awk_arg="/^libraries:/" ;;
  esac
  case $host_os in
    mingw* | cegcc*) lt_sed_strip_eq="s,=\([[A-Za-z]]:\),\1,g" ;;
    *) lt_sed_strip_eq="s,=/,/,g" ;;
  esac
  lt_search_path_spec=`$CC -print-search-dirs | awk $lt_awk_arg | $SED -e "s/^libraries://" -e $lt_sed_strip_eq`
  case $lt_search_path_spec in
  *\;*)
    # if the path contains ";" then we assume it to be the separator
    # otherwise default to the standard path separator (i.e. ":") - it is
    # assumed that no part of a normal pathname contains ";" but that should
    # okay in the real world where ";" in dirpaths is itself problematic.
    lt_search_path_spec=`$ECHO "$lt_search_path_spec" | $SED 's/;/ /g'`
    ;;
  *)
    lt_search_path_spec=`$ECHO "$lt_search_path_spec" | $SED "s/$PATH_SEPARATOR/ /g"`
    ;;
  esac
  # Ok, now we have the path, separated by spaces, we can step through it
  # and add multilib dir if necessary.
  lt_tmp_lt_search_path_spec=
  lt_multi_os_dir=`$CC $CPPFLAGS $CFLAGS $LDFLAGS -print-multi-os-directory 2>/dev/null`
  for lt_sys_path in $lt_search_path_spec; do
    if test -d "$lt_sys_path/$lt_multi_os_dir"; then
      lt_tmp_lt_search_path_spec="$lt_tmp_lt_search_path_spec $lt_sys_path/$lt_multi_os_dir"
    else
      test -d "$lt_sys_path" && \
	lt_tmp_lt_search_path_spec="$lt_tmp_lt_search_path_spec $lt_sys_path"
    fi
  done
  lt_search_path_spec=`$ECHO "$lt_tmp_lt_search_path_spec" | awk '
BEGIN {RS=" "; FS="/|\n";} {
  lt_foo="";
  lt_count=0;
  for (lt_i = NF; lt_i > 0; lt_i--) {
    if ($lt_i != "" && $lt_i != ".") {
      if ($lt_i == "..") {
        lt_count++;
      } else {
        if (lt_count == 0) {
          lt_foo="/" $lt_i lt_foo;
        } else {
          lt_count--;
        }
      }
    }
  }
  if (lt_foo != "") { lt_freq[[lt_foo]]++; }
  if (lt_freq[[lt_foo]] == 1) { print lt_foo; }
}'`
  # AWK program above erroneously prepends '/' to C:/dos/paths
  # for these hosts.
  case $host_os in
    mingw* | cegcc*) lt_search_path_spec=`$ECHO "$lt_search_path_spec" |\
      $SED 's,/\([[A-Za-z]]:\),\1,g'` ;;
  esac
  sys_lib_search_path_spec=`$ECHO "$lt_search_path_spec" | $lt_NL2SP`
else
  sys_lib_search_path_spec="/lib /usr/lib /usr/local/lib"
fi])
library_names_spec=
libname_spec='lib$name'
soname_spec=
shrext_cmds=".so"
postinstall_cmds=
postuninstall_cmds=
finish_cmds=
finish_eval=
shlibpath_var=
shlibpath_overrides_runpath=unknown
version_type=none
dynamic_linker="$host_os ld.so"
sys_lib_dlsearch_path_spec="/lib /usr/lib"
need_lib_prefix=unknown
hardcode_into_libs=no

# when you set need_version to no, make sure it does not cause -set_version
# flags to be left without arguments
need_version=unknown

case $host_os in
aix3*)
  version_type=linux # correct to gnu/linux during the next big refactor
  library_names_spec='${libname}${release}${shared_ext}$versuffix $libname.a'
  shlibpath_var=LIBPATH

  # AIX 3 has no versioning support, so we append a major version to the name.
  soname_spec='${libname}${release}${shared_ext}$major'
  ;;

aix[[4-9]]*)
  version_type=linux # correct to gnu/linux during the next big refactor
  need_lib_prefix=no
  need_version=no
  hardcode_into_libs=yes
  if test "$host_cpu" = ia64; then
    # AIX 5 supports IA64
    library_names_spec='${libname}${release}${shared_ext}$major ${libname}${release}${shared_ext}$versuffix $libname${shared_ext}'
    shlibpath_var=LD_LIBRARY_PATH
  else
    # With GCC up to 2.95.x, collect2 would create an import file
    # for dependence libraries.  The import file would start with
    # the line `#! .'.  This would cause the generated library to
    # depend on `.', always an invalid library.  This was fixed in
    # development snapshots of GCC prior to 3.0.
    case $host_os in
      aix4 | aix4.[[01]] | aix4.[[01]].*)
      if { echo '#if __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 97)'
	   echo ' yes '
	   echo '#endif'; } | ${CC} -E - | $GREP yes > /dev/null; then
	:
      else
	can_build_shared=no
      fi
      ;;
    esac
    # AIX (on Power*) has no versioning support, so currently we can not hardcode correct
    # soname into executable. Probably we can add versioning support to
    # collect2, so additional links can be useful in future.
    if test "$aix_use_runtimelinking" = yes; then
      # If using run time linking (on AIX 4.2 or later) use lib<name>.so
      # instead of lib<name>.a to let people know that these are not
      # typical AIX shared libraries.
      library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
    else
      # We preserve .a as extension for shared libraries through AIX4.2
      # and later when we are not doing run time linking.
      library_names_spec='${libname}${release}.a $libname.a'
      soname_spec='${libname}${release}${shared_ext}$major'
    fi
    shlibpath_var=LIBPATH
  fi
  ;;

amigaos*)
  case $host_cpu in
  powerpc)
    # Since July 2007 AmigaOS4 officially supports .so libraries.
    # When compiling the executable, add -use-dynld -Lsobjs: to the compileline.
    library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
    ;;
  m68k)
    library_names_spec='$libname.ixlibrary $libname.a'
    # Create ${libname}_ixlibrary.a entries in /sys/libs.
    finish_eval='for lib in `ls $libdir/*.ixlibrary 2>/dev/null`; do libname=`func_echo_all "$lib" | $SED '\''s%^.*/\([[^/]]*\)\.ixlibrary$%\1%'\''`; test $RM /sys/libs/${libname}_ixlibrary.a; $show "cd /sys/libs && $LN_S $lib ${libname}_ixlibrary.a"; cd /sys/libs && $LN_S $lib ${libname}_ixlibrary.a || exit 1; done'
    ;;
  esac
  ;;

beos*)
  library_names_spec='${libname}${shared_ext}'
  dynamic_linker="$host_os ld.so"
  shlibpath_var=LIBRARY_PATH
  ;;

bsdi[[45]]*)
  version_type=linux # correct to gnu/linux during the next big refactor
  need_version=no
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
  soname_spec='${libname}${release}${shared_ext}$major'
  finish_cmds='PATH="\$PATH:/sbin" ldconfig $libdir'
  shlibpath_var=LD_LIBRARY_PATH
  sys_lib_search_path_spec="/shlib /usr/lib /usr/X11/lib /usr/contrib/lib /lib /usr/local/lib"
  sys_lib_dlsearch_path_spec="/shlib /usr/lib /usr/local/lib"
  # the default ld.so.conf also contains /usr/contrib/lib and
  # /usr/X11R6/lib (/usr/X11 is a link to /usr/X11R6), but let us allow
  # libtool to hard-code these into programs
  ;;

cygwin* | mingw* | pw32* | cegcc*)
  version_type=windows
  shrext_cmds=".dll"
  need_version=no
  need_lib_prefix=no

  case $GCC,$cc_basename in
  yes,*)
    # gcc
    library_names_spec='$libname.dll.a'
    # DLL is installed to $(libdir)/../bin by postinstall_cmds
    postinstall_cmds='base_file=`basename \${file}`~
      dlpath=`$SHELL 2>&1 -c '\''. $dir/'\''\${base_file}'\''i; echo \$dlname'\''`~
      dldir=$destdir/`dirname \$dlpath`~
      test -d \$dldir || mkdir -p \$dldir~
      $install_prog $dir/$dlname \$dldir/$dlname~
      chmod a+x \$dldir/$dlname~
      if test -n '\''$stripme'\'' && test -n '\''$striplib'\''; then
        eval '\''$striplib \$dldir/$dlname'\'' || exit \$?;
      fi'
    postuninstall_cmds='dldll=`$SHELL 2>&1 -c '\''. $file; echo \$dlname'\''`~
      dlpath=$dir/\$dldll~
       $RM \$dlpath'
    shlibpath_overrides_runpath=yes

    case $host_os in
    cygwin*)
      # Cygwin DLLs use 'cyg' prefix rather than 'lib'
      soname_spec='`echo ${libname} | sed -e 's/^lib/cyg/'``echo ${release} | $SED -e 's/[[.]]/-/g'`${versuffix}${shared_ext}'
m4_if([$1], [],[
      sys_lib_search_path_spec="$sys_lib_search_path_spec /usr/lib/w32api"])
      ;;
    mingw* | cegcc*)
      # MinGW DLLs use traditional 'lib' prefix
      soname_spec='${libname}`echo ${release} | $SED -e 's/[[.]]/-/g'`${versuffix}${shared_ext}'
      ;;
    pw32*)
      # pw32 DLLs use 'pw' prefix rather than 'lib'
      library_names_spec='`echo ${libname} | sed -e 's/^lib/pw/'``echo ${release} | $SED -e 's/[[.]]/-/g'`${versuffix}${shared_ext}'
      ;;
    esac
    dynamic_linker='Win32 ld.exe'
    ;;

  *,cl*)
    # Native MSVC
    libname_spec='$name'
    soname_spec='${libname}`echo ${release} | $SED -e 's/[[.]]/-/g'`${versuffix}${shared_ext}'
    library_names_spec='${libname}.dll.lib'

    case $build_os in
    mingw*)
      sys_lib_search_path_spec=
      lt_save_ifs=$IFS
      IFS=';'
      for lt_path in $LIB
      do
        IFS=$lt_save_ifs
        # Let DOS variable expansion print the short 8.3 style file name.
        lt_path=`cd "$lt_path" 2>/dev/null && cmd //C "for %i in (".") do @echo %~si"`
        sys_lib_search_path_spec="$sys_lib_search_path_spec $lt_path"
      done
      IFS=$lt_save_ifs
      # Convert to MSYS style.
      sys_lib_search_path_spec=`$ECHO "$sys_lib_search_path_spec" | sed -e 's|\\\\|/|g' -e 's| \\([[a-zA-Z]]\\):| /\\1|g' -e 's|^ ||'`
      ;;
    cygwin*)
      # Convert to unix form, then to dos form, then back to unix form
      # but this time dos style (no spaces!) so that the unix form looks
      # like /cygdrive/c/PROGRA~1:/cygdr...
      sys_lib_search_path_spec=`cygpath --path --unix "$LIB"`
      sys_lib_search_path_spec=`cygpath --path --dos "$sys_lib_search_path_spec" 2>/dev/null`
      sys_lib_search_path_spec=`cygpath --path --unix "$sys_lib_search_path_spec" | $SED -e "s/$PATH_SEPARATOR/ /g"`
      ;;
    *)
      sys_lib_search_path_spec="$LIB"
      if $ECHO "$sys_lib_search_path_spec" | [$GREP ';[c-zC-Z]:/' >/dev/null]; then
        # It is most probably a Windows format PATH.
        sys_lib_search_path_spec=`$ECHO "$sys_lib_search_path_spec" | $SED -e 's/;/ /g'`
      else
        sys_lib_search_path_spec=`$ECHO "$sys_lib_search_path_spec" | $SED -e "s/$PATH_SEPARATOR/ /g"`
      fi
      # FIXME: find the short name or the path components, as spaces are
      # common. (e.g. "Program Files" -> "PROGRA~1")
      ;;
    esac

    # DLL is installed to $(libdir)/../bin by postinstall_cmds
    postinstall_cmds='base_file=`basename \${file}`~
      dlpath=`$SHELL 2>&1 -c '\''. $dir/'\''\${base_file}'\''i; echo \$dlname'\''`~
      dldir=$destdir/`dirname \$dlpath`~
      test -d \$dldir || mkdir -p \$dldir~
      $install_prog $dir/$dlname \$dldir/$dlname'
    postuninstall_cmds='dldll=`$SHELL 2>&1 -c '\''. $file; echo \$dlname'\''`~
      dlpath=$dir/\$dldll~
       $RM \$dlpath'
    shlibpath_overrides_runpath=yes
    dynamic_linker='Win32 link.exe'
    ;;

  *)
    # Assume MSVC wrapper
    library_names_spec='${libname}`echo ${release} | $SED -e 's/[[.]]/-/g'`${versuffix}${shared_ext} $libname.lib'
    dynamic_linker='Win32 ld.exe'
    ;;
  esac
  # FIXME: first we should search . and the directory the executable is in
  shlibpath_var=PATH
  ;;

darwin* | rhapsody*)
  dynamic_linker="$host_os dyld"
  version_type=darwin
  need_lib_prefix=no
  need_version=no
  library_names_spec='${libname}${release}${major}$shared_ext ${libname}$shared_ext'
  soname_spec='${libname}${release}${major}$shared_ext'
  shlibpath_overrides_runpath=yes
  shlibpath_var=DYLD_LIBRARY_PATH
  shrext_cmds='`test .$module = .yes && echo .so || echo .dylib`'
m4_if([$1], [],[
  sys_lib_search_path_spec="$sys_lib_search_path_spec /usr/local/lib"])
  sys_lib_dlsearch_path_spec='/usr/local/lib /lib /usr/lib'
  ;;

dgux*)
  version_type=linux # correct to gnu/linux during the next big refactor
  need_lib_prefix=no
  need_version=no
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname$shared_ext'
  soname_spec='${libname}${release}${shared_ext}$major'
  shlibpath_var=LD_LIBRARY_PATH
  ;;

freebsd* | dragonfly*)
  # DragonFly does not have aout.  When/if they implement a new
  # versioning mechanism, adjust this.
  if test -x /usr/bin/objformat; then
    objformat=`/usr/bin/objformat`
  else
    case $host_os in
    freebsd[[23]].*) objformat=aout ;;
    *) objformat=elf ;;
    esac
  fi
  version_type=freebsd-$objformat
  case $version_type in
    freebsd-elf*)
      library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext} $libname${shared_ext}'
      need_version=no
      need_lib_prefix=no
      ;;
    freebsd-*)
      library_names_spec='${libname}${release}${shared_ext}$versuffix $libname${shared_ext}$versuffix'
      need_version=yes
      ;;
  esac
  shlibpath_var=LD_LIBRARY_PATH
  case $host_os in
  freebsd2.*)
    shlibpath_overrides_runpath=yes
    ;;
  freebsd3.[[01]]* | freebsdelf3.[[01]]*)
    shlibpath_overrides_runpath=yes
    hardcode_into_libs=yes
    ;;
  freebsd3.[[2-9]]* | freebsdelf3.[[2-9]]* | \
  freebsd4.[[0-5]] | freebsdelf4.[[0-5]] | freebsd4.1.1 | freebsdelf4.1.1)
    shlibpath_overrides_runpath=no
    hardcode_into_libs=yes
    ;;
  *) # from 4.6 on, and DragonFly
    shlibpath_overrides_runpath=yes
    hardcode_into_libs=yes
    ;;
  esac
  ;;

gnu*)
  version_type=linux # correct to gnu/linux during the next big refactor
  need_lib_prefix=no
  need_version=no
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}${major} ${libname}${shared_ext}'
  soname_spec='${libname}${release}${shared_ext}$major'
  shlibpath_var=LD_LIBRARY_PATH
  shlibpath_overrides_runpath=no
  hardcode_into_libs=yes
  ;;

haiku*)
  version_type=linux # correct to gnu/linux during the next big refactor
  need_lib_prefix=no
  need_version=no
  dynamic_linker="$host_os runtime_loader"
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}${major} ${libname}${shared_ext}'
  soname_spec='${libname}${release}${shared_ext}$major'
  shlibpath_var=LIBRARY_PATH
  shlibpath_overrides_runpath=yes
  sys_lib_dlsearch_path_spec='/boot/home/config/lib /boot/common/lib /boot/system/lib'
  hardcode_into_libs=yes
  ;;

hpux9* | hpux10* | hpux11*)
  # Give a soname corresponding to the major version so that dld.sl refuses to
  # link against other versions.
  version_type=sunos
  need_lib_prefix=no
  need_version=no
  case $host_cpu in
  ia64*)
    shrext_cmds='.so'
    hardcode_into_libs=yes
    dynamic_linker="$host_os dld.so"
    shlibpath_var=LD_LIBRARY_PATH
    shlibpath_overrides_runpath=yes # Unless +noenvvar is specified.
    library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
    soname_spec='${libname}${release}${shared_ext}$major'
    if test "X$HPUX_IA64_MODE" = X32; then
      sys_lib_search_path_spec="/usr/lib/hpux32 /usr/local/lib/hpux32 /usr/local/lib"
    else
      sys_lib_search_path_spec="/usr/lib/hpux64 /usr/local/lib/hpux64"
    fi
    sys_lib_dlsearch_path_spec=$sys_lib_search_path_spec
    ;;
  hppa*64*)
    shrext_cmds='.sl'
    hardcode_into_libs=yes
    dynamic_linker="$host_os dld.sl"
    shlibpath_var=LD_LIBRARY_PATH # How should we handle SHLIB_PATH
    shlibpath_overrides_runpath=yes # Unless +noenvvar is specified.
    library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
    soname_spec='${libname}${release}${shared_ext}$major'
    sys_lib_search_path_spec="/usr/lib/pa20_64 /usr/ccs/lib/pa20_64"
    sys_lib_dlsearch_path_spec=$sys_lib_search_path_spec
    ;;
  *)
    shrext_cmds='.sl'
    dynamic_linker="$host_os dld.sl"
    shlibpath_var=SHLIB_PATH
    shlibpath_overrides_runpath=no # +s is required to enable SHLIB_PATH
    library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
    soname_spec='${libname}${release}${shared_ext}$major'
    ;;
  esac
  # HP-UX runs *really* slowly unless shared libraries are mode 555, ...
  postinstall_cmds='chmod 555 $lib'
  # or fails outright, so override atomically:
  install_override_mode=555
  ;;

interix[[3-9]]*)
  version_type=linux # correct to gnu/linux during the next big refactor
  need_lib_prefix=no
  need_version=no
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major ${libname}${shared_ext}'
  soname_spec='${libname}${release}${shared_ext}$major'
  dynamic_linker='Interix 3.x ld.so.1 (PE, like ELF)'
  shlibpath_var=LD_LIBRARY_PATH
  shlibpath_overrides_runpath=no
  hardcode_into_libs=yes
  ;;

irix5* | irix6* | nonstopux*)
  case $host_os in
    nonstopux*) version_type=nonstopux ;;
    *)
	if test "$lt_cv_prog_gnu_ld" = yes; then
		version_type=linux # correct to gnu/linux during the next big refactor
	else
		version_type=irix
	fi ;;
  esac
  need_lib_prefix=no
  need_version=no
  soname_spec='${libname}${release}${shared_ext}$major'
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major ${libname}${release}${shared_ext} $libname${shared_ext}'
  case $host_os in
  irix5* | nonstopux*)
    libsuff= shlibsuff=
    ;;
  *)
    case $LD in # libtool.m4 will add one of these switches to LD
    *-32|*"-32 "|*-melf32bsmip|*"-melf32bsmip ")
      libsuff= shlibsuff= libmagic=32-bit;;
    *-n32|*"-n32 "|*-melf32bmipn32|*"-melf32bmipn32 ")
      libsuff=32 shlibsuff=N32 libmagic=N32;;
    *-64|*"-64 "|*-melf64bmip|*"-melf64bmip ")
      libsuff=64 shlibsuff=64 libmagic=64-bit;;
    *) libsuff= shlibsuff= libmagic=never-match;;
    esac
    ;;
  esac
  shlibpath_var=LD_LIBRARY${shlibsuff}_PATH
  shlibpath_overrides_runpath=no
  sys_lib_search_path_spec="/usr/lib${libsuff} /lib${libsuff} /usr/local/lib${libsuff}"
  sys_lib_dlsearch_path_spec="/usr/lib${libsuff} /lib${libsuff}"
  hardcode_into_libs=yes
  ;;

# No shared lib support for Linux oldld, aout, or coff.
linux*oldld* | linux*aout* | linux*coff*)
  dynamic_linker=no
  ;;

# This must be glibc/ELF.
linux* | k*bsd*-gnu | kopensolaris*-gnu)
  version_type=linux # correct to gnu/linux during the next big refactor
  need_lib_prefix=no
  need_version=no
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
  soname_spec='${libname}${release}${shared_ext}$major'
  finish_cmds='PATH="\$PATH:/sbin" ldconfig -n $libdir'
  shlibpath_var=LD_LIBRARY_PATH
  shlibpath_overrides_runpath=no

  # Some binutils ld are patched to set DT_RUNPATH
  AC_CACHE_VAL([lt_cv_shlibpath_overrides_runpath],
    [lt_cv_shlibpath_overrides_runpath=no
    save_LDFLAGS=$LDFLAGS
    save_libdir=$libdir
    eval "libdir=/foo; wl=\"$_LT_TAGVAR(lt_prog_compiler_wl, $1)\"; \
	 LDFLAGS=\"\$LDFLAGS $_LT_TAGVAR(hardcode_libdir_flag_spec, $1)\""
    AC_LINK_IFELSE([AC_LANG_PROGRAM([],[])],
      [AS_IF([ ($OBJDUMP -p conftest$ac_exeext) 2>/dev/null | grep "RUNPATH.*$libdir" >/dev/null],
	 [lt_cv_shlibpath_overrides_runpath=yes])])
    LDFLAGS=$save_LDFLAGS
    libdir=$save_libdir
    ])
  shlibpath_overrides_runpath=$lt_cv_shlibpath_overrides_runpath

  # This implies no fast_install, which is unacceptable.
  # Some rework will be needed to allow for fast_install
  # before this can be enabled.
  hardcode_into_libs=yes

  # Add ABI-specific directories to the system library path.
  sys_lib_dlsearch_path_spec="/lib64 /usr/lib64 /lib /usr/lib"

  # Append ld.so.conf contents to the search path
  if test -f /etc/ld.so.conf; then
    lt_ld_extra=`awk '/^include / { system(sprintf("cd /etc; cat %s 2>/dev/null", \[$]2)); skip = 1; } { if (!skip) print \[$]0; skip = 0; }' < /etc/ld.so.conf | $SED -e 's/#.*//;/^[	 ]*hwcap[	 ]/d;s/[:,	]/ /g;s/=[^=]*$//;s/=[^= ]* / /g;s/"//g;/^$/d' | tr '\n' ' '`
    sys_lib_dlsearch_path_spec="$sys_lib_dlsearch_path_spec $lt_ld_extra"

  fi

  # We used to test for /lib/ld.so.1 and disable shared libraries on
  # powerpc, because MkLinux only supported shared libraries with the
  # GNU dynamic linker.  Since this was broken with cross compilers,
  # most powerpc-linux boxes support dynamic linking these days and
  # people can always --disable-shared, the test was removed, and we
  # assume the GNU/Linux dynamic linker is in use.
  dynamic_linker='GNU/Linux ld.so'
  ;;

netbsd*)
  version_type=sunos
  need_lib_prefix=no
  need_version=no
  if echo __ELF__ | $CC -E - | $GREP __ELF__ >/dev/null; then
    library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${shared_ext}$versuffix'
    finish_cmds='PATH="\$PATH:/sbin" ldconfig -m $libdir'
    dynamic_linker='NetBSD (a.out) ld.so'
  else
    library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major ${libname}${shared_ext}'
    soname_spec='${libname}${release}${shared_ext}$major'
    dynamic_linker='NetBSD ld.elf_so'
  fi
  shlibpath_var=LD_LIBRARY_PATH
  shlibpath_overrides_runpath=yes
  hardcode_into_libs=yes
  ;;

newsos6)
  version_type=linux # correct to gnu/linux during the next big refactor
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
  shlibpath_var=LD_LIBRARY_PATH
  shlibpath_overrides_runpath=yes
  ;;

*nto* | *qnx*)
  version_type=qnx
  need_lib_prefix=no
  need_version=no
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
  soname_spec='${libname}${release}${shared_ext}$major'
  shlibpath_var=LD_LIBRARY_PATH
  shlibpath_overrides_runpath=no
  hardcode_into_libs=yes
  dynamic_linker='ldqnx.so'
  ;;

openbsd*)
  version_type=sunos
  sys_lib_dlsearch_path_spec="/usr/lib"
  need_lib_prefix=no
  # Some older versions of OpenBSD (3.3 at least) *do* need versioned libs.
  case $host_os in
    openbsd3.3 | openbsd3.3.*)	need_version=yes ;;
    *)				need_version=no  ;;
  esac
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${shared_ext}$versuffix'
  finish_cmds='PATH="\$PATH:/sbin" ldconfig -m $libdir'
  shlibpath_var=LD_LIBRARY_PATH
  if test -z "`echo __ELF__ | $CC -E - | $GREP __ELF__`" || test "$host_os-$host_cpu" = "openbsd2.8-powerpc"; then
    case $host_os in
      openbsd2.[[89]] | openbsd2.[[89]].*)
	shlibpath_overrides_runpath=no
	;;
      *)
	shlibpath_overrides_runpath=yes
	;;
      esac
  else
    shlibpath_overrides_runpath=yes
  fi
  ;;

os2*)
  libname_spec='$name'
  shrext_cmds=".dll"
  need_lib_prefix=no
  library_names_spec='$libname${shared_ext} $libname.a'
  dynamic_linker='OS/2 ld.exe'
  shlibpath_var=LIBPATH
  ;;

osf3* | osf4* | osf5*)
  version_type=osf
  need_lib_prefix=no
  need_version=no
  soname_spec='${libname}${release}${shared_ext}$major'
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
  shlibpath_var=LD_LIBRARY_PATH
  sys_lib_search_path_spec="/usr/shlib /usr/ccs/lib /usr/lib/cmplrs/cc /usr/lib /usr/local/lib /var/shlib"
  sys_lib_dlsearch_path_spec="$sys_lib_search_path_spec"
  ;;

rdos*)
  dynamic_linker=no
  ;;

solaris*)
  version_type=linux # correct to gnu/linux during the next big refactor
  need_lib_prefix=no
  need_version=no
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
  soname_spec='${libname}${release}${shared_ext}$major'
  shlibpath_var=LD_LIBRARY_PATH
  shlibpath_overrides_runpath=yes
  hardcode_into_libs=yes
  # ldd complains unless libraries are executable
  postinstall_cmds='chmod +x $lib'
  ;;

sunos4*)
  version_type=sunos
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${shared_ext}$versuffix'
  finish_cmds='PATH="\$PATH:/usr/etc" ldconfig $libdir'
  shlibpath_var=LD_LIBRARY_PATH
  shlibpath_overrides_runpath=yes
  if test "$with_gnu_ld" = yes; then
    need_lib_prefix=no
  fi
  need_version=yes
  ;;

sysv4 | sysv4.3*)
  version_type=linux # correct to gnu/linux during the next big refactor
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
  soname_spec='${libname}${release}${shared_ext}$major'
  shlibpath_var=LD_LIBRARY_PATH
  case $host_vendor in
    sni)
      shlibpath_overrides_runpath=no
      need_lib_prefix=no
      runpath_var=LD_RUN_PATH
      ;;
    siemens)
      need_lib_prefix=no
      ;;
    motorola)
      need_lib_prefix=no
      need_version=no
      shlibpath_overrides_runpath=no
      sys_lib_search_path_spec='/lib /usr/lib /usr/ccs/lib'
      ;;
  esac
  ;;

sysv4*MP*)
  if test -d /usr/nec ;then
    version_type=linux # correct to gnu/linux during the next big refactor
    library_names_spec='$libname${shared_ext}.$versuffix $libname${shared_ext}.$major $libname${shared_ext}'
    soname_spec='$libname${shared_ext}.$major'
    shlibpath_var=LD_LIBRARY_PATH
  fi
  ;;

sysv5* | sco3.2v5* | sco5v6* | unixware* | OpenUNIX* | sysv4*uw2*)
  version_type=freebsd-elf
  need_lib_prefix=no
  need_version=no
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext} $libname${shared_ext}'
  soname_spec='${libname}${release}${shared_ext}$major'
  shlibpath_var=LD_LIBRARY_PATH
  shlibpath_overrides_runpath=yes
  hardcode_into_libs=yes
  if test "$with_gnu_ld" = yes; then
    sys_lib_search_path_spec='/usr/local/lib /usr/gnu/lib /usr/ccs/lib /usr/lib /lib'
  else
    sys_lib_search_path_spec='/usr/ccs/lib /usr/lib'
    case $host_os in
      sco3.2v5*)
        sys_lib_search_path_spec="$sys_lib_search_path_spec /lib"
	;;
    esac
  fi
  sys_lib_dlsearch_path_spec='/usr/lib'
  ;;

tpf*)
  # TPF is a cross-target only.  Preferred cross-host = GNU/Linux.
  version_type=linux # correct to gnu/linux during the next big refactor
  need_lib_prefix=no
  need_version=no
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
  shlibpath_var=LD_LIBRARY_PATH
  shlibpath_overrides_runpath=no
  hardcode_into_libs=yes
  ;;

uts4*)
  version_type=linux # correct to gnu/linux during the next big refactor
  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
  soname_spec='${libname}${release}${shared_ext}$major'
  shlibpath_var=LD_LIBRARY_PATH
  ;;

*)
  dynamic_linker=no
  ;;
esac
AC_MSG_RESULT([$dynamic_linker])
test "$dynamic_linker" = no && can_build_shared=no

variables_saved_for_relink="PATH $shlibpath_var $runpath_var"
if test "$GCC" = yes; then
  variables_saved_for_relink="$variables_saved_for_relink GCC_EXEC_PREFIX COMPILER_PATH LIBRARY_PATH"
fi

if test "${lt_cv_sys_lib_search_path_spec+set}" = set; then
  sys_lib_search_path_spec="$lt_cv_sys_lib_search_path_spec"
fi
if test "${lt_cv_sys_lib_dlsearch_path_spec+set}" = set; then
  sys_lib_dlsearch_path_spec="$lt_cv_sys_lib_dlsearch_path_spec"
fi

_LT_DECL([], [variables_saved_for_relink], [1],
    [Variables whose values should be saved in libtool wrapper scripts and
    restored at link time])
_LT_DECL([], [need_lib_prefix], [0],
    [Do we need the "lib" prefix for modules?])
_LT_DECL([], [need_version], [0], [Do we need a version for libraries?])
_LT_DECL([], [version_type], [0], [Library versioning type])
_LT_DECL([], [runpath_var], [0],  [Shared library runtime path variable])
_LT_DECL([], [shlibpath_var], [0],[Shared library path variable])
_LT_DECL([], [shlibpath_overrides_runpath], [0],
    [Is shlibpath searched before the hard-coded library search path?])
_LT_DECL([], [libname_spec], [1], [Format of library name prefix])
_LT_DECL([], [library_names_spec], [1],
    [[List of archive names.  First name is the real one, the rest are links.
    The last name is the one that the linker finds with -lNAME]])
_LT_DECL([], [soname_spec], [1],
    [[The coded name of the library, if different from the real name]])
_LT_DECL([], [install_override_mode], [1],
    [Permission mode override for installation of shared libraries])
_LT_DECL([], [postinstall_cmds], [2],
    [Command to use after installation of a shared archive])
_LT_DECL([], [postuninstall_cmds], [2],
    [Command to use after uninstallation of a shared archive])
_LT_DECL([], [finish_cmds], [2],
    [Commands used to finish a libtool library installation in a directory])
_LT_DECL([], [finish_eval], [1],
    [[As "finish_cmds", except a single script fragment to be evaled but
    not shown]])
_LT_DECL([], [hardcode_into_libs], [0],
    [Whether we should hardcode library paths into libraries])
_LT_DECL([], [sys_lib_search_path_spec], [2],
    [Compile-time system search path for libraries])
_LT_DECL([], [sys_lib_dlsearch_path_spec], [2],
    [Run-time system search path for libraries])
])# _LT_SYS_DYNAMIC_LINKER


# _LT_PATH_TOOL_PREFIX(TOOL)
# --------------------------
# find a file program which can recognize shared library
AC_DEFUN([_LT_PATH_TOOL_PREFIX],
[m4_require([_LT_DECL_EGREP])dnl
AC_MSG_CHECKING([for $1])
AC_CACHE_VAL(lt_cv_path_MAGIC_CMD,
[case $MAGIC_CMD in
[[\\/*] |  ?:[\\/]*])
  lt_cv_path_MAGIC_CMD="$MAGIC_CMD" # Let the user override the test with a path.
  ;;
*)
  lt_save_MAGIC_CMD="$MAGIC_CMD"
  lt_save_ifs="$IFS"; IFS=$PATH_SEPARATOR
dnl $ac_dummy forces splitting on constant user-supplied paths.
dnl POSIX.2 word splitting is done only on the output of word expansions,
dnl not every word.  This closes a longstanding sh security hole.
  ac_dummy="m4_if([$2], , $PATH, [$2])"
  for ac_dir in $ac_dummy; do
    IFS="$lt_save_ifs"
    test -z "$ac_dir" && ac_dir=.
    if test -f $ac_dir/$1; then
      lt_cv_path_MAGIC_CMD="$ac_dir/$1"
      if test -n "$file_magic_test_file"; then
	case $deplibs_check_method in
	"file_magic "*)
	  file_magic_regex=`expr "$deplibs_check_method" : "file_magic \(.*\)"`
	  MAGIC_CMD="$lt_cv_path_MAGIC_CMD"
	  if eval $file_magic_cmd \$file_magic_test_file 2> /dev/null |
	    $EGREP "$file_magic_regex" > /dev/null; then
	    :
	  else
	    cat <<_LT_EOF 1>&2

*** Warning: the command libtool uses to detect shared libraries,
*** $file_magic_cmd, produces output that libtool cannot recognize.
*** The result is that libtool may fail to recognize shared libraries
*** as such.  This will affect the creation of libtool libraries that
*** depend on shared libraries, but programs linked with such libtool
*** libraries will work regardless of this problem.  Nevertheless, you
*** may want to report the problem to your system manager and/or to
*** bug-libtool@gnu.org

_LT_EOF
	  fi ;;
	esac
      fi
      break
    fi
  done
  IFS="$lt_save_ifs"
  MAGIC_CMD="$lt_save_MAGIC_CMD"
  ;;
esac])
MAGIC_CMD="$lt_cv_path_MAGIC_CMD"
if test -n "$MAGIC_CMD"; then
  AC_MSG_RESULT($MAGIC_CMD)
else
  AC_MSG_RESULT(no)
fi
_LT_DECL([], [MAGIC_CMD], [0],
	 [Used to examine libraries when file_magic_cmd begins with "file"])dnl
])# _LT_PATH_TOOL_PREFIX

# Old name:
AU_ALIAS([AC_PATH_TOOL_PREFIX], [_LT_PATH_TOOL_PREFIX])
dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([AC_PATH_TOOL_PREFIX], [])


# _LT_PATH_MAGIC
# --------------
# find a file program which can recognize a shared library
m4_defun([_LT_PATH_MAGIC],
[_LT_PATH_TOOL_PREFIX(${ac_tool_prefix}file, /usr/bin$PATH_SEPARATOR$PATH)
if test -z "$lt_cv_path_MAGIC_CMD"; then
  if test -n "$ac_tool_prefix"; then
    _LT_PATH_TOOL_PREFIX(file, /usr/bin$PATH_SEPARATOR$PATH)
  else
    MAGIC_CMD=:
  fi
fi
])# _LT_PATH_MAGIC


# LT_PATH_LD
# ----------
# find the pathname to the GNU or non-GNU linker
AC_DEFUN([LT_PATH_LD],
[AC_REQUIRE([AC_PROG_CC])dnl
AC_REQUIRE([AC_CANONICAL_HOST])dnl
AC_REQUIRE([AC_CANONICAL_BUILD])dnl
m4_require([_LT_DECL_SED])dnl
m4_require([_LT_DECL_EGREP])dnl
m4_require([_LT_PROG_ECHO_BACKSLASH])dnl

AC_ARG_WITH([gnu-ld],
    [AS_HELP_STRING([--with-gnu-ld],
	[assume the C compiler uses GNU ld @<:@default=no@:>@])],
    [test "$withval" = no || with_gnu_ld=yes],
    [with_gnu_ld=no])dnl

ac_prog=ld
if test "$GCC" = yes; then
  # Check if gcc -print-prog-name=ld gives a path.
  AC_MSG_CHECKING([for ld used by $CC])
  case $host in
  *-*-mingw*)
    # gcc leaves a trailing carriage return which upsets mingw
    ac_prog=`($CC -print-prog-name=ld) 2>&5 | tr -d '\015'` ;;
  *)
    ac_prog=`($CC -print-prog-name=ld) 2>&5` ;;
  esac
  case $ac_prog in
    # Accept absolute paths.
    [[\\/]]* | ?:[[\\/]]*)
      re_direlt='/[[^/]][[^/]]*/\.\./'
      # Canonicalize the pathname of ld
      ac_prog=`$ECHO "$ac_prog"| $SED 's%\\\\%/%g'`
      while $ECHO "$ac_prog" | $GREP "$re_direlt" > /dev/null 2>&1; do
	ac_prog=`$ECHO $ac_prog| $SED "s%$re_direlt%/%"`
      done
      test -z "$LD" && LD="$ac_prog"
      ;;
  "")
    # If it fails, then pretend we aren't using GCC.
    ac_prog=ld
    ;;
  *)
    # If it is relative, then search for the first ld in PATH.
    with_gnu_ld=unknown
    ;;
  esac
elif test "$with_gnu_ld" = yes; then
  AC_MSG_CHECKING([for GNU ld])
else
  AC_MSG_CHECKING([for non-GNU ld])
fi
AC_CACHE_VAL(lt_cv_path_LD,
[if test -z "$LD"; then
  lt_save_ifs="$IFS"; IFS=$PATH_SEPARATOR
  for ac_dir in $PATH; do
    IFS="$lt_save_ifs"
    test -z "$ac_dir" && ac_dir=.
    if test -f "$ac_dir/$ac_prog" || test -f "$ac_dir/$ac_prog$ac_exeext"; then
      lt_cv_path_LD="$ac_dir/$ac_prog"
      # Check to see if the program is GNU ld.  I'd rather use --version,
      # but apparently some variants of GNU ld only accept -v.
      # Break only if it was the GNU/non-GNU ld that we prefer.
      case `"$lt_cv_path_LD" -v 2>&1 </dev/null` in
      *GNU* | *'with BFD'*)
	test "$with_gnu_ld" != no && break
	;;
      *)
	test "$with_gnu_ld" != yes && break
	;;
      esac
    fi
  done
  IFS="$lt_save_ifs"
else
  lt_cv_path_LD="$LD" # Let the user override the test with a path.
fi])
LD="$lt_cv_path_LD"
if test -n "$LD"; then
  AC_MSG_RESULT($LD)
else
  AC_MSG_RESULT(no)
fi
test -z "$LD" && AC_MSG_ERROR([no acceptable ld found in \$PATH])
_LT_PATH_LD_GNU
AC_SUBST([LD])

_LT_TAGDECL([], [LD], [1], [The linker used to build libraries])
])# LT_PATH_LD

# Old names:
AU_ALIAS([AM_PROG_LD], [LT_PATH_LD])
AU_ALIAS([AC_PROG_LD], [LT_PATH_LD])
dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([AM_PROG_LD], [])
dnl AC_DEFUN([AC_PROG_LD], [])


# _LT_PATH_LD_GNU
#- --------------
m4_defun([_LT_PATH_LD_GNU],
[AC_CACHE_CHECK([if the linker ($LD) is GNU ld], lt_cv_prog_gnu_ld,
[# I'd rather use --version here, but apparently some GNU lds only accept -v.
case `$LD -v 2>&1 </dev/null` in
*GNU* | *'with BFD'*)
  lt_cv_prog_gnu_ld=yes
  ;;
*)
  lt_cv_prog_gnu_ld=no
  ;;
esac])
with_gnu_ld=$lt_cv_prog_gnu_ld
])# _LT_PATH_LD_GNU


# _LT_CMD_RELOAD
# --------------
# find reload flag for linker
#   -- PORTME Some linkers may need a different reload flag.
m4_defun([_LT_CMD_RELOAD],
[AC_CACHE_CHECK([for $LD option to reload object files],
  lt_cv_ld_reload_flag,
  [lt_cv_ld_reload_flag='-r'])
reload_flag=$lt_cv_ld_reload_flag
case $reload_flag in
"" | " "*) ;;
*) reload_flag=" $reload_flag" ;;
esac
reload_cmds='$LD$reload_flag -o $output$reload_objs'
case $host_os in
  cygwin* | mingw* | pw32* | cegcc*)
    if test "$GCC" != yes; then
      reload_cmds=false
    fi
    ;;
  darwin*)
    if test "$GCC" = yes; then
      reload_cmds='$LTCC $LTCFLAGS -nostdlib ${wl}-r -o $output$reload_objs'
    else
      reload_cmds='$LD$reload_flag -o $output$reload_objs'
    fi
    ;;
esac
_LT_TAGDECL([], [reload_flag], [1], [How to create reloadable object files])dnl
_LT_TAGDECL([], [reload_cmds], [2])dnl
])# _LT_CMD_RELOAD


# _LT_CHECK_MAGIC_METHOD
# ----------------------
# how to check for library dependencies
#  -- PORTME fill in with the dynamic library characteristics
m4_defun([_LT_CHECK_MAGIC_METHOD],
[m4_require([_LT_DECL_EGREP])
m4_require([_LT_DECL_OBJDUMP])
AC_CACHE_CHECK([how to recognize dependent libraries],
lt_cv_deplibs_check_method,
[lt_cv_file_magic_cmd='$MAGIC_CMD'
lt_cv_file_magic_test_file=
lt_cv_deplibs_check_method='unknown'
# Need to set the preceding variable on all platforms that support
# interlibrary dependencies.
# 'none' -- dependencies not supported.
# `unknown' -- same as none, but documents that we really don't know.
# 'pass_all' -- all dependencies passed with no checks.
# 'test_compile' -- check by making test program.
# 'file_magic [[regex]]' -- check by looking for files in library path
# which responds to the $file_magic_cmd with a given extended regex.
# If you have `file' or equivalent on your system and you're not sure
# whether `pass_all' will *always* work, you probably want this one.

case $host_os in
aix[[4-9]]*)
  lt_cv_deplibs_check_method=pass_all
  ;;

beos*)
  lt_cv_deplibs_check_method=pass_all
  ;;

bsdi[[45]]*)
  lt_cv_deplibs_check_method='file_magic ELF [[0-9]][[0-9]]*-bit [[ML]]SB (shared object|dynamic lib)'
  lt_cv_file_magic_cmd='/usr/bin/file -L'
  lt_cv_file_magic_test_file=/shlib/libc.so
  ;;

cygwin*)
  # func_win32_libid is a shell function defined in ltmain.sh
  lt_cv_deplibs_check_method='file_magic ^x86 archive import|^x86 DLL'
  lt_cv_file_magic_cmd='func_win32_libid'
  ;;

mingw* | pw32*)
  # Base MSYS/MinGW do not provide the 'file' command needed by
  # func_win32_libid shell function, so use a weaker test based on 'objdump',
  # unless we find 'file', for example because we are cross-compiling.
  # func_win32_libid assumes BSD nm, so disallow it if using MS dumpbin.
  if ( test "$lt_cv_nm_interface" = "BSD nm" && file / ) >/dev/null 2>&1; then
    lt_cv_deplibs_check_method='file_magic ^x86 archive import|^x86 DLL'
    lt_cv_file_magic_cmd='func_win32_libid'
  else
    # Keep this pattern in sync with the one in func_win32_libid.
    lt_cv_deplibs_check_method='file_magic file format (pei*-i386(.*architecture: i386)?|pe-arm-wince|pe-x86-64)'
    lt_cv_file_magic_cmd='$OBJDUMP -f'
  fi
  ;;

cegcc*)
  # use the weaker test based on 'objdump'. See mingw*.
  lt_cv_deplibs_check_method='file_magic file format pe-arm-.*little(.*architecture: arm)?'
  lt_cv_file_magic_cmd='$OBJDUMP -f'
  ;;

darwin* | rhapsody*)
  lt_cv_deplibs_check_method=pass_all
  ;;

freebsd* | dragonfly*)
  if echo __ELF__ | $CC -E - | $GREP __ELF__ > /dev/null; then
    case $host_cpu in
    i*86 )
      # Not sure whether the presence of OpenBSD here was a mistake.
      # Let's accept both of them until this is cleared up.
      lt_cv_deplibs_check_method='file_magic (FreeBSD|OpenBSD|DragonFly)/i[[3-9]]86 (compact )?demand paged shared library'
      lt_cv_file_magic_cmd=/usr/bin/file
      lt_cv_file_magic_test_file=`echo /usr/lib/libc.so.*`
      ;;
    esac
  else
    lt_cv_deplibs_check_method=pass_all
  fi
  ;;

gnu*)
  lt_cv_deplibs_check_method=pass_all
  ;;

haiku*)
  lt_cv_deplibs_check_method=pass_all
  ;;

hpux10.20* | hpux11*)
  lt_cv_file_magic_cmd=/usr/bin/file
  case $host_cpu in
  ia64*)
    lt_cv_deplibs_check_method='file_magic (s[[0-9]][[0-9]][[0-9]]|ELF-[[0-9]][[0-9]]) shared object file - IA64'
    lt_cv_file_magic_test_file=/usr/lib/hpux32/libc.so
    ;;
  hppa*64*)
    [lt_cv_deplibs_check_method='file_magic (s[0-9][0-9][0-9]|ELF[ -][0-9][0-9])(-bit)?( [LM]SB)? shared object( file)?[, -]* PA-RISC [0-9]\.[0-9]']
    lt_cv_file_magic_test_file=/usr/lib/pa20_64/libc.sl
    ;;
  *)
    lt_cv_deplibs_check_method='file_magic (s[[0-9]][[0-9]][[0-9]]|PA-RISC[[0-9]]\.[[0-9]]) shared library'
    lt_cv_file_magic_test_file=/usr/lib/libc.sl
    ;;
  esac
  ;;

interix[[3-9]]*)
  # PIC code is broken on Interix 3.x, that's why |\.a not |_pic\.a here
  lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so|\.a)$'
  ;;

irix5* | irix6* | nonstopux*)
  case $LD in
  *-32|*"-32 ") libmagic=32-bit;;
  *-n32|*"-n32 ") libmagic=N32;;
  *-64|*"-64 ") libmagic=64-bit;;
  *) libmagic=never-match;;
  esac
  lt_cv_deplibs_check_method=pass_all
  ;;

# This must be glibc/ELF.
linux* | k*bsd*-gnu | kopensolaris*-gnu)
  lt_cv_deplibs_check_method=pass_all
  ;;

netbsd*)
  if echo __ELF__ | $CC -E - | $GREP __ELF__ > /dev/null; then
    lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so\.[[0-9]]+\.[[0-9]]+|_pic\.a)$'
  else
    lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so|_pic\.a)$'
  fi
  ;;

newos6*)
  lt_cv_deplibs_check_method='file_magic ELF [[0-9]][[0-9]]*-bit [[ML]]SB (executable|dynamic lib)'
  lt_cv_file_magic_cmd=/usr/bin/file
  lt_cv_file_magic_test_file=/usr/lib/libnls.so
  ;;

*nto* | *qnx*)
  lt_cv_deplibs_check_method=pass_all
  ;;

openbsd*)
  if test -z "`echo __ELF__ | $CC -E - | $GREP __ELF__`" || test "$host_os-$host_cpu" = "openbsd2.8-powerpc"; then
    lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so\.[[0-9]]+\.[[0-9]]+|\.so|_pic\.a)$'
  else
    lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so\.[[0-9]]+\.[[0-9]]+|_pic\.a)$'
  fi
  ;;

osf3* | osf4* | osf5*)
  lt_cv_deplibs_check_method=pass_all
  ;;

rdos*)
  lt_cv_deplibs_check_method=pass_all
  ;;

solaris*)
  lt_cv_deplibs_check_method=pass_all
  ;;

sysv5* | sco3.2v5* | sco5v6* | unixware* | OpenUNIX* | sysv4*uw2*)
  lt_cv_deplibs_check_method=pass_all
  ;;

sysv4 | sysv4.3*)
  case $host_vendor in
  motorola)
    lt_cv_deplibs_check_method='file_magic ELF [[0-9]][[0-9]]*-bit [[ML]]SB (shared object|dynamic lib) M[[0-9]][[0-9]]* Version [[0-9]]'
    lt_cv_file_magic_test_file=`echo /usr/lib/libc.so*`
    ;;
  ncr)
    lt_cv_deplibs_check_method=pass_all
    ;;
  sequent)
    lt_cv_file_magic_cmd='/bin/file'
    lt_cv_deplibs_check_method='file_magic ELF [[0-9]][[0-9]]*-bit [[LM]]SB (shared object|dynamic lib )'
    ;;
  sni)
    lt_cv_file_magic_cmd='/bin/file'
    lt_cv_deplibs_check_method="file_magic ELF [[0-9]][[0-9]]*-bit [[LM]]SB dynamic lib"
    lt_cv_file_magic_test_file=/lib/libc.so
    ;;
  siemens)
    lt_cv_deplibs_check_method=pass_all
    ;;
  pc)
    lt_cv_deplibs_check_method=pass_all
    ;;
  esac
  ;;

tpf*)
  lt_cv_deplibs_check_method=pass_all
  ;;
esac
])

file_magic_glob=
want_nocaseglob=no
if test "$build" = "$host"; then
  case $host_os in
  mingw* | pw32*)
    if ( shopt | grep nocaseglob ) >/dev/null 2>&1; then
      want_nocaseglob=yes
    else
      file_magic_glob=`echo aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ | $SED -e "s/\(..\)/s\/[[\1]]\/[[\1]]\/g;/g"`
    fi
    ;;
  esac
fi

file_magic_cmd=$lt_cv_file_magic_cmd
deplibs_check_method=$lt_cv_deplibs_check_method
test -z "$deplibs_check_method" && deplibs_check_method=unknown

_LT_DECL([], [deplibs_check_method], [1],
    [Method to check whether dependent libraries are shared objects])
_LT_DECL([], [file_magic_cmd], [1],
    [Command to use when deplibs_check_method = "file_magic"])
_LT_DECL([], [file_magic_glob], [1],
    [How to find potential files when deplibs_check_method = "file_magic"])
_LT_DECL([], [want_nocaseglob], [1],
    [Find potential files using nocaseglob when deplibs_check_method = "file_magic"])
])# _LT_CHECK_MAGIC_METHOD


# LT_PATH_NM
# ----------
# find the pathname to a BSD- or MS-compatible name lister
AC_DEFUN([LT_PATH_NM],
[AC_REQUIRE([AC_PROG_CC])dnl
AC_CACHE_CHECK([for BSD- or MS-compatible name lister (nm)], lt_cv_path_NM,
[if test -n "$NM"; then
  # Let the user override the test.
  lt_cv_path_NM="$NM"
else
  lt_nm_to_check="${ac_tool_prefix}nm"
  if test -n "$ac_tool_prefix" && test "$build" = "$host"; then
    lt_nm_to_check="$lt_nm_to_check nm"
  fi
  for lt_tmp_nm in $lt_nm_to_check; do
    lt_save_ifs="$IFS"; IFS=$PATH_SEPARATOR
    for ac_dir in $PATH /usr/ccs/bin/elf /usr/ccs/bin /usr/ucb /bin; do
      IFS="$lt_save_ifs"
      test -z "$ac_dir" && ac_dir=.
      tmp_nm="$ac_dir/$lt_tmp_nm"
      if test -f "$tmp_nm" || test -f "$tmp_nm$ac_exeext" ; then
	# Check to see if the nm accepts a BSD-compat flag.
	# Adding the `sed 1q' prevents false positives on HP-UX, which says:
	#   nm: unknown option "B" ignored
	# Tru64's nm complains that /dev/null is an invalid object file
	case `"$tmp_nm" -B /dev/null 2>&1 | sed '1q'` in
	*/dev/null* | *'Invalid file or object type'*)
	  lt_cv_path_NM="$tmp_nm -B"
	  break
	  ;;
	*)
	  case `"$tmp_nm" -p /dev/null 2>&1 | sed '1q'` in
	  */dev/null*)
	    lt_cv_path_NM="$tmp_nm -p"
	    break
	    ;;
	  *)
	    lt_cv_path_NM=${lt_cv_path_NM="$tmp_nm"} # keep the first match, but
	    continue # so that we can try to find one that supports BSD flags
	    ;;
	  esac
	  ;;
	esac
      fi
    done
    IFS="$lt_save_ifs"
  done
  : ${lt_cv_path_NM=no}
fi])
if test "$lt_cv_path_NM" != "no"; then
  NM="$lt_cv_path_NM"
else
  # Didn't find any BSD compatible name lister, look for dumpbin.
  if test -n "$DUMPBIN"; then :
    # Let the user override the test.
  else
    AC_CHECK_TOOLS(DUMPBIN, [dumpbin "link -dump"], :)
    case `$DUMPBIN -symbols /dev/null 2>&1 | sed '1q'` in
    *COFF*)
      DUMPBIN="$DUMPBIN -symbols"
      ;;
    *)
      DUMPBIN=:
      ;;
    esac
  fi
  AC_SUBST([DUMPBIN])
  if test "$DUMPBIN" != ":"; then
    NM="$DUMPBIN"
  fi
fi
test -z "$NM" && NM=nm
AC_SUBST([NM])
_LT_DECL([], [NM], [1], [A BSD- or MS-compatible name lister])dnl

AC_CACHE_CHECK([the name lister ($NM) interface], [lt_cv_nm_interface],
  [lt_cv_nm_interface="BSD nm"
  echo "int some_variable = 0;" > conftest.$ac_ext
  (eval echo "\"\$as_me:$LINENO: $ac_compile\"" >&AS_MESSAGE_LOG_FD)
  (eval "$ac_compile" 2>conftest.err)
  cat conftest.err >&AS_MESSAGE_LOG_FD
  (eval echo "\"\$as_me:$LINENO: $NM \\\"conftest.$ac_objext\\\"\"" >&AS_MESSAGE_LOG_FD)
  (eval "$NM \"conftest.$ac_objext\"" 2>conftest.err > conftest.out)
  cat conftest.err >&AS_MESSAGE_LOG_FD
  (eval echo "\"\$as_me:$LINENO: output\"" >&AS_MESSAGE_LOG_FD)
  cat conftest.out >&AS_MESSAGE_LOG_FD
  if $GREP 'External.*some_variable' conftest.out > /dev/null; then
    lt_cv_nm_interface="MS dumpbin"
  fi
  rm -f conftest*])
])# LT_PATH_NM

# Old names:
AU_ALIAS([AM_PROG_NM], [LT_PATH_NM])
AU_ALIAS([AC_PROG_NM], [LT_PATH_NM])
dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([AM_PROG_NM], [])
dnl AC_DEFUN([AC_PROG_NM], [])

# _LT_CHECK_SHAREDLIB_FROM_LINKLIB
# --------------------------------
# how to determine the name of the shared library
# associated with a specific link library.
#  -- PORTME fill in with the dynamic library characteristics
m4_defun([_LT_CHECK_SHAREDLIB_FROM_LINKLIB],
[m4_require([_LT_DECL_EGREP])
m4_require([_LT_DECL_OBJDUMP])
m4_require([_LT_DECL_DLLTOOL])
AC_CACHE_CHECK([how to associate runtime and link libraries],
lt_cv_sharedlib_from_linklib_cmd,
[lt_cv_sharedlib_from_linklib_cmd='unknown'

case $host_os in
cygwin* | mingw* | pw32* | cegcc*)
  # two different shell functions defined in ltmain.sh
  # decide which to use based on capabilities of $DLLTOOL
  case `$DLLTOOL --help 2>&1` in
  *--identify-strict*)
    lt_cv_sharedlib_from_linklib_cmd=func_cygming_dll_for_implib
    ;;
  *)
    lt_cv_sharedlib_from_linklib_cmd=func_cygming_dll_for_implib_fallback
    ;;
  esac
  ;;
*)
  # fallback: assume linklib IS sharedlib
  lt_cv_sharedlib_from_linklib_cmd="$ECHO"
  ;;
esac
])
sharedlib_from_linklib_cmd=$lt_cv_sharedlib_from_linklib_cmd
test -z "$sharedlib_from_linklib_cmd" && sharedlib_from_linklib_cmd=$ECHO

_LT_DECL([], [sharedlib_from_linklib_cmd], [1],
    [Command to associate shared and link libraries])
])# _LT_CHECK_SHAREDLIB_FROM_LINKLIB


# _LT_PATH_MANIFEST_TOOL
# ----------------------
# locate the manifest tool
m4_defun([_LT_PATH_MANIFEST_TOOL],
[AC_CHECK_TOOL(MANIFEST_TOOL, mt, :)
test -z "$MANIFEST_TOOL" && MANIFEST_TOOL=mt
AC_CACHE_CHECK([if $MANIFEST_TOOL is a manifest tool], [lt_cv_path_mainfest_tool],
  [lt_cv_path_mainfest_tool=no
  echo "$as_me:$LINENO: $MANIFEST_TOOL '-?'" >&AS_MESSAGE_LOG_FD
  $MANIFEST_TOOL '-?' 2>conftest.err > conftest.out
  cat conftest.err >&AS_MESSAGE_LOG_FD
  if $GREP 'Manifest Tool' conftest.out > /dev/null; then
    lt_cv_path_mainfest_tool=yes
  fi
  rm -f conftest*])
if test "x$lt_cv_path_mainfest_tool" != xyes; then
  MANIFEST_TOOL=:
fi
_LT_DECL([], [MANIFEST_TOOL], [1], [Manifest tool])dnl
])# _LT_PATH_MANIFEST_TOOL


# LT_LIB_M
# --------
# check for math library
AC_DEFUN([LT_LIB_M],
[AC_REQUIRE([AC_CANONICAL_HOST])dnl
LIBM=
case $host in
*-*-beos* | *-*-cegcc* | *-*-cygwin* | *-*-haiku* | *-*-pw32* | *-*-darwin*)
  # These system don't have libm, or don't need it
  ;;
*-ncr-sysv4.3*)
  AC_CHECK_LIB(mw, _mwvalidcheckl, LIBM="-lmw")
  AC_CHECK_LIB(m, cos, LIBM="$LIBM -lm")
  ;;
*)
  AC_CHECK_LIB(m, cos, LIBM="-lm")
  ;;
esac
AC_SUBST([LIBM])
])# LT_LIB_M

# Old name:
AU_ALIAS([AC_CHECK_LIBM], [LT_LIB_M])
dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([AC_CHECK_LIBM], [])


# _LT_COMPILER_NO_RTTI([TAGNAME])
# -------------------------------
m4_defun([_LT_COMPILER_NO_RTTI],
[m4_require([_LT_TAG_COMPILER])dnl

_LT_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)=

if test "$GCC" = yes; then
  case $cc_basename in
  nvcc*)
    _LT_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)=' -Xcompiler -fno-builtin' ;;
  *)
    _LT_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)=' -fno-builtin' ;;
  esac

  _LT_COMPILER_OPTION([if $compiler supports -fno-rtti -fno-exceptions],
    lt_cv_prog_compiler_rtti_exceptions,
    [-fno-rtti -fno-exceptions], [],
    [_LT_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)="$_LT_TAGVAR(lt_prog_compiler_no_builtin_flag, $1) -fno-rtti -fno-exceptions"])
fi
_LT_TAGDECL([no_builtin_flag], [lt_prog_compiler_no_builtin_flag], [1],
	[Compiler flag to turn off builtin functions])
])# _LT_COMPILER_NO_RTTI


# _LT_CMD_GLOBAL_SYMBOLS
# ----------------------
m4_defun([_LT_CMD_GLOBAL_SYMBOLS],
[AC_REQUIRE([AC_CANONICAL_HOST])dnl
AC_REQUIRE([AC_PROG_CC])dnl
AC_REQUIRE([AC_PROG_AWK])dnl
AC_REQUIRE([LT_PATH_NM])dnl
AC_REQUIRE([LT_PATH_LD])dnl
m4_require([_LT_DECL_SED])dnl
m4_require([_LT_DECL_EGREP])dnl
m4_require([_LT_TAG_COMPILER])dnl

# Check for command to grab the raw symbol name followed by C symbol from nm.
AC_MSG_CHECKING([command to parse $NM output from $compiler object])
AC_CACHE_VAL([lt_cv_sys_global_symbol_pipe],
[
# These are sane defaults that work on at least a few old systems.
# [They come from Ultrix.  What could be older than Ultrix?!! ;)]

# Character class describing NM global symbol codes.
symcode='[[BCDEGRST]]'

# Regexp to match symbols that can be accessed directly from C.
sympat='\([[_A-Za-z]][[_A-Za-z0-9]]*\)'

# Define system-specific variables.
case $host_os in
aix*)
  symcode='[[BCDT]]'
  ;;
cygwin* | mingw* | pw32* | cegcc*)
  symcode='[[ABCDGISTW]]'
  ;;
hpux*)
  if test "$host_cpu" = ia64; then
    symcode='[[ABCDEGRST]]'
  fi
  ;;
irix* | nonstopux*)
  symcode='[[BCDEGRST]]'
  ;;
osf*)
  symcode='[[BCDEGQRST]]'
  ;;
solaris*)
  symcode='[[BDRT]]'
  ;;
sco3.2v5*)
  symcode='[[DT]]'
  ;;
sysv4.2uw2*)
  symcode='[[DT]]'
  ;;
sysv5* | sco5v6* | unixware* | OpenUNIX*)
  symcode='[[ABDT]]'
  ;;
sysv4)
  symcode='[[DFNSTU]]'
  ;;
esac

# If we're using GNU nm, then use its standard symbol codes.
case `$NM -V 2>&1` in
*GNU* | *'with BFD'*)
  symcode='[[ABCDGIRSTW]]' ;;
esac

# Transform an extracted symbol line into a proper C declaration.
# Some systems (esp. on ia64) link data and code symbols differently,
# so use this general approach.
lt_cv_sys_global_symbol_to_cdecl="sed -n -e 's/^T .* \(.*\)$/extern int \1();/p' -e 's/^$symcode* .* \(.*\)$/extern char \1;/p'"

# Transform an extracted symbol line into symbol name and symbol address
lt_cv_sys_global_symbol_to_c_name_address="sed -n -e 's/^: \([[^ ]]*\)[[ ]]*$/  {\\\"\1\\\", (void *) 0},/p' -e 's/^$symcode* \([[^ ]]*\) \([[^ ]]*\)$/  {\"\2\", (void *) \&\2},/p'"
lt_cv_sys_global_symbol_to_c_name_address_lib_prefix="sed -n -e 's/^: \([[^ ]]*\)[[ ]]*$/  {\\\"\1\\\", (void *) 0},/p' -e 's/^$symcode* \([[^ ]]*\) \(lib[[^ ]]*\)$/  {\"\2\", (void *) \&\2},/p' -e 's/^$symcode* \([[^ ]]*\) \([[^ ]]*\)$/  {\"lib\2\", (void *) \&\2},/p'"

# Handle CRLF in mingw tool chain
opt_cr=
case $build_os in
mingw*)
  opt_cr=`$ECHO 'x\{0,1\}' | tr x '\015'` # option cr in regexp
  ;;
esac

# Try without a prefix underscore, then with it.
for ac_symprfx in "" "_"; do

  # Transform symcode, sympat, and symprfx into a raw symbol and a C symbol.
  symxfrm="\\1 $ac_symprfx\\2 \\2"

  # Write the raw and C identifiers.
  if test "$lt_cv_nm_interface" = "MS dumpbin"; then
    # Fake it for dumpbin and say T for any non-static function
    # and D for any global variable.
    # Also find C++ and __fastcall symbols from MSVC++,
    # which start with @ or ?.
    lt_cv_sys_global_symbol_pipe="$AWK ['"\
"     {last_section=section; section=\$ 3};"\
"     /^COFF SYMBOL TABLE/{for(i in hide) delete hide[i]};"\
"     /Section length .*#relocs.*(pick any)/{hide[last_section]=1};"\
"     \$ 0!~/External *\|/{next};"\
"     / 0+ UNDEF /{next}; / UNDEF \([^|]\)*()/{next};"\
"     {if(hide[section]) next};"\
"     {f=0}; \$ 0~/\(\).*\|/{f=1}; {printf f ? \"T \" : \"D \"};"\
"     {split(\$ 0, a, /\||\r/); split(a[2], s)};"\
"     s[1]~/^[@?]/{print s[1], s[1]; next};"\
"     s[1]~prfx {split(s[1],t,\"@\"); print t[1], substr(t[1],length(prfx))}"\
"     ' prfx=^$ac_symprfx]"
  else
    lt_cv_sys_global_symbol_pipe="sed -n -e 's/^.*[[	 ]]\($symcode$symcode*\)[[	 ]][[	 ]]*$ac_symprfx$sympat$opt_cr$/$symxfrm/p'"
  fi
  lt_cv_sys_global_symbol_pipe="$lt_cv_sys_global_symbol_pipe | sed '/ __gnu_lto/d'"

  # Check to see that the pipe works correctly.
  pipe_works=no

  rm -f conftest*
  cat > conftest.$ac_ext <<_LT_EOF
#ifdef __cplusplus
extern "C" {
#endif
char nm_test_var;
void nm_test_func(void);
void nm_test_func(void){}
#ifdef __cplusplus
}
#endif
int main(){nm_test_var='a';nm_test_func();return(0);}
_LT_EOF

  if AC_TRY_EVAL(ac_compile); then
    # Now try to grab the symbols.
    nlist=conftest.nm
    if AC_TRY_EVAL(NM conftest.$ac_objext \| "$lt_cv_sys_global_symbol_pipe" \> $nlist) && test -s "$nlist"; then
      # Try sorting and uniquifying the output.
      if sort "$nlist" | uniq > "$nlist"T; then
	mv -f "$nlist"T "$nlist"
      else
	rm -f "$nlist"T
      fi

      # Make sure that we snagged all the symbols we need.
      if $GREP ' nm_test_var$' "$nlist" >/dev/null; then
	if $GREP ' nm_test_func$' "$nlist" >/dev/null; then
	  cat <<_LT_EOF > conftest.$ac_ext
/* Keep this code in sync between libtool.m4, ltmain, lt_system.h, and tests.  */
#if defined(_WIN32) || defined(__CYGWIN__) || defined(_WIN32_WCE)
/* DATA imports from DLLs on WIN32 con't be const, because runtime
   relocations are performed -- see ld's documentation on pseudo-relocs.  */
# define LT@&t@_DLSYM_CONST
#elif defined(__osf__)
/* This system does not cope well with relocations in const data.  */
# define LT@&t@_DLSYM_CONST
#else
# define LT@&t@_DLSYM_CONST const
#endif

#ifdef __cplusplus
extern "C" {
#endif

_LT_EOF
	  # Now generate the symbol file.
	  eval "$lt_cv_sys_global_symbol_to_cdecl"' < "$nlist" | $GREP -v main >> conftest.$ac_ext'

	  cat <<_LT_EOF >> conftest.$ac_ext

/* The mapping between symbol names and symbols.  */
LT@&t@_DLSYM_CONST struct {
  const char *name;
  void       *address;
}
lt__PROGRAM__LTX_preloaded_symbols[[]] =
{
  { "@PROGRAM@", (void *) 0 },
_LT_EOF
	  $SED "s/^$symcode$symcode* \(.*\) \(.*\)$/  {\"\2\", (void *) \&\2},/" < "$nlist" | $GREP -v main >> conftest.$ac_ext
	  cat <<\_LT_EOF >> conftest.$ac_ext
  {0, (void *) 0}
};

/* This works around a problem in FreeBSD linker */
#ifdef FREEBSD_WORKAROUND
static const void *lt_preloaded_setup() {
  return lt__PROGRAM__LTX_preloaded_symbols;
}
#endif

#ifdef __cplusplus
}
#endif
_LT_EOF
	  # Now try linking the two files.
	  mv conftest.$ac_objext conftstm.$ac_objext
	  lt_globsym_save_LIBS=$LIBS
	  lt_globsym_save_CFLAGS=$CFLAGS
	  LIBS="conftstm.$ac_objext"
	  CFLAGS="$CFLAGS$_LT_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)"
	  if AC_TRY_EVAL(ac_link) && test -s conftest${ac_exeext}; then
	    pipe_works=yes
	  fi
	  LIBS=$lt_globsym_save_LIBS
	  CFLAGS=$lt_globsym_save_CFLAGS
	else
	  echo "cannot find nm_test_func in $nlist" >&AS_MESSAGE_LOG_FD
	fi
      else
	echo "cannot find nm_test_var in $nlist" >&AS_MESSAGE_LOG_FD
      fi
    else
      echo "cannot run $lt_cv_sys_global_symbol_pipe" >&AS_MESSAGE_LOG_FD
    fi
  else
    echo "$progname: failed program was:" >&AS_MESSAGE_LOG_FD
    cat conftest.$ac_ext >&5
  fi
  rm -rf conftest* conftst*

  # Do not use the global_symbol_pipe unless it works.
  if test "$pipe_works" = yes; then
    break
  else
    lt_cv_sys_global_symbol_pipe=
  fi
done
])
if test -z "$lt_cv_sys_global_symbol_pipe"; then
  lt_cv_sys_global_symbol_to_cdecl=
fi
if test -z "$lt_cv_sys_global_symbol_pipe$lt_cv_sys_global_symbol_to_cdecl"; then
  AC_MSG_RESULT(failed)
else
  AC_MSG_RESULT(ok)
fi

# Response file support.
if test "$lt_cv_nm_interface" = "MS dumpbin"; then
  nm_file_list_spec='@'
elif $NM --help 2>/dev/null | grep '[[@]]FILE' >/dev/null; then
  nm_file_list_spec='@'
fi

_LT_DECL([global_symbol_pipe], [lt_cv_sys_global_symbol_pipe], [1],
    [Take the output of nm and produce a listing of raw symbols and C names])
_LT_DECL([global_symbol_to_cdecl], [lt_cv_sys_global_symbol_to_cdecl], [1],
    [Transform the output of nm in a proper C declaration])
_LT_DECL([global_symbol_to_c_name_address],
    [lt_cv_sys_global_symbol_to_c_name_address], [1],
    [Transform the output of nm in a C name address pair])
_LT_DECL([global_symbol_to_c_name_address_lib_prefix],
    [lt_cv_sys_global_symbol_to_c_name_address_lib_prefix], [1],
    [Transform the output of nm in a C name address pair when lib prefix is needed])
_LT_DECL([], [nm_file_list_spec], [1],
    [Specify filename containing input files for $NM])
]) # _LT_CMD_GLOBAL_SYMBOLS


# _LT_COMPILER_PIC([TAGNAME])
# ---------------------------
m4_defun([_LT_COMPILER_PIC],
[m4_require([_LT_TAG_COMPILER])dnl
_LT_TAGVAR(lt_prog_compiler_wl, $1)=
_LT_TAGVAR(lt_prog_compiler_pic, $1)=
_LT_TAGVAR(lt_prog_compiler_static, $1)=

m4_if([$1], [CXX], [
  # C++ specific cases for pic, static, wl, etc.
  if test "$GXX" = yes; then
    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
    _LT_TAGVAR(lt_prog_compiler_static, $1)='-static'

    case $host_os in
    aix*)
      # All AIX code is PIC.
      if test "$host_cpu" = ia64; then
	# AIX 5 now supports IA64 processor
	_LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
      fi
      ;;

    amigaos*)
      case $host_cpu in
      powerpc)
            # see comment about AmigaOS4 .so support
            _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
        ;;
      m68k)
            # FIXME: we need at least 68020 code to build shared libraries, but
            # adding the `-m68020' flag to GCC prevents building anything better,
            # like `-m68040'.
            _LT_TAGVAR(lt_prog_compiler_pic, $1)='-m68020 -resident32 -malways-restore-a4'
        ;;
      esac
      ;;

    beos* | irix5* | irix6* | nonstopux* | osf3* | osf4* | osf5*)
      # PIC is the default for these OSes.
      ;;
    mingw* | cygwin* | os2* | pw32* | cegcc*)
      # This hack is so that the source file can tell whether it is being
      # built for inclusion in a dll (and should export symbols for example).
      # Although the cygwin gcc ignores -fPIC, still need this for old-style
      # (--disable-auto-import) libraries
      m4_if([$1], [GCJ], [],
	[_LT_TAGVAR(lt_prog_compiler_pic, $1)='-DDLL_EXPORT'])
      ;;
    darwin* | rhapsody*)
      # PIC is the default on this platform
      # Common symbols not allowed in MH_DYLIB files
      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fno-common'
      ;;
    *djgpp*)
      # DJGPP does not support shared libraries at all
      _LT_TAGVAR(lt_prog_compiler_pic, $1)=
      ;;
    haiku*)
      # PIC is the default for Haiku.
      # The "-static" flag exists, but is broken.
      _LT_TAGVAR(lt_prog_compiler_static, $1)=
      ;;
    interix[[3-9]]*)
      # Interix 3.x gcc -fpic/-fPIC options generate broken code.
      # Instead, we relocate shared libraries at runtime.
      ;;
    sysv4*MP*)
      if test -d /usr/nec; then
	_LT_TAGVAR(lt_prog_compiler_pic, $1)=-Kconform_pic
      fi
      ;;
    hpux*)
      # PIC is the default for 64-bit PA HP-UX, but not for 32-bit
      # PA HP-UX.  On IA64 HP-UX, PIC is the default but the pic flag
      # sets the default TLS model and affects inlining.
      case $host_cpu in
      hppa*64*)
	;;
      *)
	_LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
	;;
      esac
      ;;
    *qnx* | *nto*)
      # QNX uses GNU C++, but need to define -shared option too, otherwise
      # it will coredump.
      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC -shared'
      ;;
    *)
      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
      ;;
    esac
  else
    case $host_os in
      aix[[4-9]]*)
	# All AIX code is PIC.
	if test "$host_cpu" = ia64; then
	  # AIX 5 now supports IA64 processor
	  _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
	else
	  _LT_TAGVAR(lt_prog_compiler_static, $1)='-bnso -bI:/lib/syscalls.exp'
	fi
	;;
      chorus*)
	case $cc_basename in
	cxch68*)
	  # Green Hills C++ Compiler
	  # _LT_TAGVAR(lt_prog_compiler_static, $1)="--no_auto_instantiation -u __main -u __premain -u _abort -r $COOL_DIR/lib/libOrb.a $MVME_DIR/lib/CC/libC.a $MVME_DIR/lib/classix/libcx.s.a"
	  ;;
	esac
	;;
      mingw* | cygwin* | os2* | pw32* | cegcc*)
	# This hack is so that the source file can tell whether it is being
	# built for inclusion in a dll (and should export symbols for example).
	m4_if([$1], [GCJ], [],
	  [_LT_TAGVAR(lt_prog_compiler_pic, $1)='-DDLL_EXPORT'])
	;;
      dgux*)
	case $cc_basename in
	  ec++*)
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
	    ;;
	  ghcx*)
	    # Green Hills C++ Compiler
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-pic'
	    ;;
	  *)
	    ;;
	esac
	;;
      freebsd* | dragonfly*)
	# FreeBSD uses GNU C++
	;;
      hpux9* | hpux10* | hpux11*)
	case $cc_basename in
	  CC*)
	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	    _LT_TAGVAR(lt_prog_compiler_static, $1)='${wl}-a ${wl}archive'
	    if test "$host_cpu" != ia64; then
	      _LT_TAGVAR(lt_prog_compiler_pic, $1)='+Z'
	    fi
	    ;;
	  aCC*)
	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	    _LT_TAGVAR(lt_prog_compiler_static, $1)='${wl}-a ${wl}archive'
	    case $host_cpu in
	    hppa*64*|ia64*)
	      # +Z the default
	      ;;
	    *)
	      _LT_TAGVAR(lt_prog_compiler_pic, $1)='+Z'
	      ;;
	    esac
	    ;;
	  *)
	    ;;
	esac
	;;
      interix*)
	# This is c89, which is MS Visual C++ (no shared libs)
	# Anyone wants to do a port?
	;;
      irix5* | irix6* | nonstopux*)
	case $cc_basename in
	  CC*)
	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	    _LT_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
	    # CC pic flag -KPIC is the default.
	    ;;
	  *)
	    ;;
	esac
	;;
      linux* | k*bsd*-gnu | kopensolaris*-gnu)
	case $cc_basename in
	  KCC*)
	    # KAI C++ Compiler
	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='--backend -Wl,'
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
	    ;;
	  ecpc* )
	    # old Intel C++ for x86_64 which still supported -KPIC.
	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
	    _LT_TAGVAR(lt_prog_compiler_static, $1)='-static'
	    ;;
	  icpc* )
	    # Intel C++, used to be incompatible with GCC.
	    # ICC 10 doesn't accept -KPIC any more.
	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
	    _LT_TAGVAR(lt_prog_compiler_static, $1)='-static'
	    ;;
	  pgCC* | pgcpp*)
	    # Portland Group C++ compiler
	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fpic'
	    _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
	    ;;
	  cxx*)
	    # Compaq C++
	    # Make sure the PIC flag is empty.  It appears that all Alpha
	    # Linux and Compaq Tru64 Unix objects are PIC.
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)=
	    _LT_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
	    ;;
	  xlc* | xlC* | bgxl[[cC]]* | mpixl[[cC]]*)
	    # IBM XL 8.0, 9.0 on PPC and BlueGene
	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-qpic'
	    _LT_TAGVAR(lt_prog_compiler_static, $1)='-qstaticlink'
	    ;;
	  *)
	    case `$CC -V 2>&1 | sed 5q` in
	    *Sun\ C*)
	      # Sun C++ 5.9
	      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
	      _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
	      _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Qoption ld '
	      ;;
	    esac
	    ;;
	esac
	;;
      lynxos*)
	;;
      m88k*)
	;;
      mvs*)
	case $cc_basename in
	  cxx*)
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-W c,exportall'
	    ;;
	  *)
	    ;;
	esac
	;;
      netbsd*)
	;;
      *qnx* | *nto*)
        # QNX uses GNU C++, but need to define -shared option too, otherwise
        # it will coredump.
        _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC -shared'
        ;;
      osf3* | osf4* | osf5*)
	case $cc_basename in
	  KCC*)
	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='--backend -Wl,'
	    ;;
	  RCC*)
	    # Rational C++ 2.4.1
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-pic'
	    ;;
	  cxx*)
	    # Digital/Compaq C++
	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	    # Make sure the PIC flag is empty.  It appears that all Alpha
	    # Linux and Compaq Tru64 Unix objects are PIC.
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)=
	    _LT_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
	    ;;
	  *)
	    ;;
	esac
	;;
      psos*)
	;;
      solaris*)
	case $cc_basename in
	  CC* | sunCC*)
	    # Sun C++ 4.2, 5.x and Centerline C++
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
	    _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Qoption ld '
	    ;;
	  gcx*)
	    # Green Hills C++ Compiler
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-PIC'
	    ;;
	  *)
	    ;;
	esac
	;;
      sunos4*)
	case $cc_basename in
	  CC*)
	    # Sun C++ 4.x
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-pic'
	    _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
	    ;;
	  lcc*)
	    # Lucid
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-pic'
	    ;;
	  *)
	    ;;
	esac
	;;
      sysv5* | unixware* | sco3.2v5* | sco5v6* | OpenUNIX*)
	case $cc_basename in
	  CC*)
	    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
	    _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
	    ;;
	esac
	;;
      tandem*)
	case $cc_basename in
	  NCC*)
	    # NonStop-UX NCC 3.20
	    _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
	    ;;
	  *)
	    ;;
	esac
	;;
      vxworks*)
	;;
      *)
	_LT_TAGVAR(lt_prog_compiler_can_build_shared, $1)=no
	;;
    esac
  fi
],
[
  if test "$GCC" = yes; then
    _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
    _LT_TAGVAR(lt_prog_compiler_static, $1)='-static'

    case $host_os in
      aix*)
      # All AIX code is PIC.
      if test "$host_cpu" = ia64; then
	# AIX 5 now supports IA64 processor
	_LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
      fi
      ;;

    amigaos*)
      case $host_cpu in
      powerpc)
            # see comment about AmigaOS4 .so support
            _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
        ;;
      m68k)
            # FIXME: we need at least 68020 code to build shared libraries, but
            # adding the `-m68020' flag to GCC prevents building anything better,
            # like `-m68040'.
            _LT_TAGVAR(lt_prog_compiler_pic, $1)='-m68020 -resident32 -malways-restore-a4'
        ;;
      esac
      ;;

    beos* | irix5* | irix6* | nonstopux* | osf3* | osf4* | osf5*)
      # PIC is the default for these OSes.
      ;;

    mingw* | cygwin* | pw32* | os2* | cegcc*)
      # This hack is so that the source file can tell whether it is being
      # built for inclusion in a dll (and should export symbols for example).
      # Although the cygwin gcc ignores -fPIC, still need this for old-style
      # (--disable-auto-import) libraries
      m4_if([$1], [GCJ], [],
	[_LT_TAGVAR(lt_prog_compiler_pic, $1)='-DDLL_EXPORT'])
      ;;

    darwin* | rhapsody*)
      # PIC is the default on this platform
      # Common symbols not allowed in MH_DYLIB files
      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fno-common'
      ;;

    haiku*)
      # PIC is the default for Haiku.
      # The "-static" flag exists, but is broken.
      _LT_TAGVAR(lt_prog_compiler_static, $1)=
      ;;

    hpux*)
      # PIC is the default for 64-bit PA HP-UX, but not for 32-bit
      # PA HP-UX.  On IA64 HP-UX, PIC is the default but the pic flag
      # sets the default TLS model and affects inlining.
      case $host_cpu in
      hppa*64*)
	# +Z the default
	;;
      *)
	_LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
	;;
      esac
      ;;

    interix[[3-9]]*)
      # Interix 3.x gcc -fpic/-fPIC options generate broken code.
      # Instead, we relocate shared libraries at runtime.
      ;;

    msdosdjgpp*)
      # Just because we use GCC doesn't mean we suddenly get shared libraries
      # on systems that don't support them.
      _LT_TAGVAR(lt_prog_compiler_can_build_shared, $1)=no
      enable_shared=no
      ;;

    *nto* | *qnx*)
      # QNX uses GNU C++, but need to define -shared option too, otherwise
      # it will coredump.
      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC -shared'
      ;;

    sysv4*MP*)
      if test -d /usr/nec; then
	_LT_TAGVAR(lt_prog_compiler_pic, $1)=-Kconform_pic
      fi
      ;;

    *)
      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
      ;;
    esac

    case $cc_basename in
    nvcc*) # Cuda Compiler Driver 2.2
      _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Xlinker '
      if test -n "$_LT_TAGVAR(lt_prog_compiler_pic, $1)"; then
        _LT_TAGVAR(lt_prog_compiler_pic, $1)="-Xcompiler $_LT_TAGVAR(lt_prog_compiler_pic, $1)"
      fi
      ;;
    esac
  else
    # PORTME Check for flag to pass linker flags through the system compiler.
    case $host_os in
    aix*)
      _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
      if test "$host_cpu" = ia64; then
	# AIX 5 now supports IA64 processor
	_LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
      else
	_LT_TAGVAR(lt_prog_compiler_static, $1)='-bnso -bI:/lib/syscalls.exp'
      fi
      ;;

    mingw* | cygwin* | pw32* | os2* | cegcc*)
      # This hack is so that the source file can tell whether it is being
      # built for inclusion in a dll (and should export symbols for example).
      m4_if([$1], [GCJ], [],
	[_LT_TAGVAR(lt_prog_compiler_pic, $1)='-DDLL_EXPORT'])
      ;;

    hpux9* | hpux10* | hpux11*)
      _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
      # PIC is the default for IA64 HP-UX and 64-bit HP-UX, but
      # not for PA HP-UX.
      case $host_cpu in
      hppa*64*|ia64*)
	# +Z the default
	;;
      *)
	_LT_TAGVAR(lt_prog_compiler_pic, $1)='+Z'
	;;
      esac
      # Is there a better lt_prog_compiler_static that works with the bundled CC?
      _LT_TAGVAR(lt_prog_compiler_static, $1)='${wl}-a ${wl}archive'
      ;;

    irix5* | irix6* | nonstopux*)
      _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
      # PIC (with -KPIC) is the default.
      _LT_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
      ;;

    linux* | k*bsd*-gnu | kopensolaris*-gnu)
      case $cc_basename in
      # old Intel for x86_64 which still supported -KPIC.
      ecc*)
	_LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	_LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
	_LT_TAGVAR(lt_prog_compiler_static, $1)='-static'
        ;;
      # icc used to be incompatible with GCC.
      # ICC 10 doesn't accept -KPIC any more.
      icc* | ifort*)
	_LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	_LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
	_LT_TAGVAR(lt_prog_compiler_static, $1)='-static'
        ;;
      # Lahey Fortran 8.1.
      lf95*)
	_LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	_LT_TAGVAR(lt_prog_compiler_pic, $1)='--shared'
	_LT_TAGVAR(lt_prog_compiler_static, $1)='--static'
	;;
      nagfor*)
	# NAG Fortran compiler
	_LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,-Wl,,'
	_LT_TAGVAR(lt_prog_compiler_pic, $1)='-PIC'
	_LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
	;;
      pgcc* | pgf77* | pgf90* | pgf95* | pgfortran*)
        # Portland Group compilers (*not* the Pentium gcc compiler,
	# which looks to be a dead project)
	_LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	_LT_TAGVAR(lt_prog_compiler_pic, $1)='-fpic'
	_LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
        ;;
      ccc*)
        _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
        # All Alpha code is PIC.
        _LT_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
        ;;
      xl* | bgxl* | bgf* | mpixl*)
	# IBM XL C 8.0/Fortran 10.1, 11.1 on PPC and BlueGene
	_LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	_LT_TAGVAR(lt_prog_compiler_pic, $1)='-qpic'
	_LT_TAGVAR(lt_prog_compiler_static, $1)='-qstaticlink'
	;;
      *)
	case `$CC -V 2>&1 | sed 5q` in
	*Sun\ Ceres\ Fortran* | *Sun*Fortran*\ [[1-7]].* | *Sun*Fortran*\ 8.[[0-3]]*)
	  # Sun Fortran 8.3 passes all unrecognized flags to the linker
	  _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
	  _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
	  _LT_TAGVAR(lt_prog_compiler_wl, $1)=''
	  ;;
	*Sun\ F* | *Sun*Fortran*)
	  _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
	  _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
	  _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Qoption ld '
	  ;;
	*Sun\ C*)
	  # Sun C 5.9
	  _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
	  _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
	  _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	  ;;
        *Intel*\ [[CF]]*Compiler*)
	  _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	  _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
	  _LT_TAGVAR(lt_prog_compiler_static, $1)='-static'
	  ;;
	*Portland\ Group*)
	  _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
	  _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fpic'
	  _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
	  ;;
	esac
	;;
      esac
      ;;

    newsos6)
      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
      _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
      ;;

    *nto* | *qnx*)
      # QNX uses GNU C++, but need to define -shared option too, otherwise
      # it will coredump.
      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC -shared'
      ;;

    osf3* | osf4* | osf5*)
      _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
      # All OSF/1 code is PIC.
      _LT_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
      ;;

    rdos*)
      _LT_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
      ;;

    solaris*)
      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
      _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
      case $cc_basename in
      f77* | f90* | f95* | sunf77* | sunf90* | sunf95*)
	_LT_TAGVAR(lt_prog_compiler_wl, $1)='-Qoption ld ';;
      *)
	_LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,';;
      esac
      ;;

    sunos4*)
      _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Qoption ld '
      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-PIC'
      _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
      ;;

    sysv4 | sysv4.2uw2* | sysv4.3*)
      _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
      _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
      ;;

    sysv4*MP*)
      if test -d /usr/nec ;then
	_LT_TAGVAR(lt_prog_compiler_pic, $1)='-Kconform_pic'
	_LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
      fi
      ;;

    sysv5* | unixware* | sco3.2v5* | sco5v6* | OpenUNIX*)
      _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
      _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
      ;;

    unicos*)
      _LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
      _LT_TAGVAR(lt_prog_compiler_can_build_shared, $1)=no
      ;;

    uts4*)
      _LT_TAGVAR(lt_prog_compiler_pic, $1)='-pic'
      _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
      ;;

    *)
      _LT_TAGVAR(lt_prog_compiler_can_build_shared, $1)=no
      ;;
    esac
  fi
])
case $host_os in
  # For platforms which do not support PIC, -DPIC is meaningless:
  *djgpp*)
    _LT_TAGVAR(lt_prog_compiler_pic, $1)=
    ;;
  *)
    _LT_TAGVAR(lt_prog_compiler_pic, $1)="$_LT_TAGVAR(lt_prog_compiler_pic, $1)@&t@m4_if([$1],[],[ -DPIC],[m4_if([$1],[CXX],[ -DPIC],[])])"
    ;;
esac

AC_CACHE_CHECK([for $compiler option to produce PIC],
  [_LT_TAGVAR(lt_cv_prog_compiler_pic, $1)],
  [_LT_TAGVAR(lt_cv_prog_compiler_pic, $1)=$_LT_TAGVAR(lt_prog_compiler_pic, $1)])
_LT_TAGVAR(lt_prog_compiler_pic, $1)=$_LT_TAGVAR(lt_cv_prog_compiler_pic, $1)

#
# Check to make sure the PIC flag actually works.
#
if test -n "$_LT_TAGVAR(lt_prog_compiler_pic, $1)"; then
  _LT_COMPILER_OPTION([if $compiler PIC flag $_LT_TAGVAR(lt_prog_compiler_pic, $1) works],
    [_LT_TAGVAR(lt_cv_prog_compiler_pic_works, $1)],
    [$_LT_TAGVAR(lt_prog_compiler_pic, $1)@&t@m4_if([$1],[],[ -DPIC],[m4_if([$1],[CXX],[ -DPIC],[])])], [],
    [case $_LT_TAGVAR(lt_prog_compiler_pic, $1) in
     "" | " "*) ;;
     *) _LT_TAGVAR(lt_prog_compiler_pic, $1)=" $_LT_TAGVAR(lt_prog_compiler_pic, $1)" ;;
     esac],
    [_LT_TAGVAR(lt_prog_compiler_pic, $1)=
     _LT_TAGVAR(lt_prog_compiler_can_build_shared, $1)=no])
fi
_LT_TAGDECL([pic_flag], [lt_prog_compiler_pic], [1],
	[Additional compiler flags for building library objects])

_LT_TAGDECL([wl], [lt_prog_compiler_wl], [1],
	[How to pass a linker flag through the compiler])
#
# Check to make sure the static flag actually works.
#
wl=$_LT_TAGVAR(lt_prog_compiler_wl, $1) eval lt_tmp_static_flag=\"$_LT_TAGVAR(lt_prog_compiler_static, $1)\"
_LT_LINKER_OPTION([if $compiler static flag $lt_tmp_static_flag works],
  _LT_TAGVAR(lt_cv_prog_compiler_static_works, $1),
  $lt_tmp_static_flag,
  [],
  [_LT_TAGVAR(lt_prog_compiler_static, $1)=])
_LT_TAGDECL([link_static_flag], [lt_prog_compiler_static], [1],
	[Compiler flag to prevent dynamic linking])
])# _LT_COMPILER_PIC


# _LT_LINKER_SHLIBS([TAGNAME])
# ----------------------------
# See if the linker supports building shared libraries.
m4_defun([_LT_LINKER_SHLIBS],
[AC_REQUIRE([LT_PATH_LD])dnl
AC_REQUIRE([LT_PATH_NM])dnl
m4_require([_LT_PATH_MANIFEST_TOOL])dnl
m4_require([_LT_FILEUTILS_DEFAULTS])dnl
m4_require([_LT_DECL_EGREP])dnl
m4_require([_LT_DECL_SED])dnl
m4_require([_LT_CMD_GLOBAL_SYMBOLS])dnl
m4_require([_LT_TAG_COMPILER])dnl
AC_MSG_CHECKING([whether the $compiler linker ($LD) supports shared libraries])
m4_if([$1], [CXX], [
  _LT_TAGVAR(export_symbols_cmds, $1)='$NM $libobjs $convenience | $global_symbol_pipe | $SED '\''s/.* //'\'' | sort | uniq > $export_symbols'
  _LT_TAGVAR(exclude_expsyms, $1)=['_GLOBAL_OFFSET_TABLE_|_GLOBAL__F[ID]_.*']
  case $host_os in
  aix[[4-9]]*)
    # If we're using GNU nm, then we don't want the "-C" option.
    # -C means demangle to AIX nm, but means don't demangle with GNU nm
    # Also, AIX nm treats weak defined symbols like other global defined
    # symbols, whereas GNU nm marks them as "W".
    if $NM -V 2>&1 | $GREP 'GNU' > /dev/null; then
      _LT_TAGVAR(export_symbols_cmds, $1)='$NM -Bpg $libobjs $convenience | awk '\''{ if (((\$ 2 == "T") || (\$ 2 == "D") || (\$ 2 == "B") || (\$ 2 == "W")) && ([substr](\$ 3,1,1) != ".")) { print \$ 3 } }'\'' | sort -u > $export_symbols'
    else
      _LT_TAGVAR(export_symbols_cmds, $1)='$NM -BCpg $libobjs $convenience | awk '\''{ if (((\$ 2 == "T") || (\$ 2 == "D") || (\$ 2 == "B")) && ([substr](\$ 3,1,1) != ".")) { print \$ 3 } }'\'' | sort -u > $export_symbols'
    fi
    ;;
  pw32*)
    _LT_TAGVAR(export_symbols_cmds, $1)="$ltdll_cmds"
    ;;
  cygwin* | mingw* | cegcc*)
    case $cc_basename in
    cl*)
      _LT_TAGVAR(exclude_expsyms, $1)='_NULL_IMPORT_DESCRIPTOR|_IMPORT_DESCRIPTOR_.*'
      ;;
    *)
      _LT_TAGVAR(export_symbols_cmds, $1)='$NM $libobjs $convenience | $global_symbol_pipe | $SED -e '\''/^[[BCDGRS]][[ ]]/s/.*[[ ]]\([[^ ]]*\)/\1 DATA/;s/^.*[[ ]]__nm__\([[^ ]]*\)[[ ]][[^ ]]*/\1 DATA/;/^I[[ ]]/d;/^[[AITW]][[ ]]/s/.* //'\'' | sort | uniq > $export_symbols'
      _LT_TAGVAR(exclude_expsyms, $1)=['[_]+GLOBAL_OFFSET_TABLE_|[_]+GLOBAL__[FID]_.*|[_]+head_[A-Za-z0-9_]+_dll|[A-Za-z0-9_]+_dll_iname']
      ;;
    esac
    ;;
  *)
    _LT_TAGVAR(export_symbols_cmds, $1)='$NM $libobjs $convenience | $global_symbol_pipe | $SED '\''s/.* //'\'' | sort | uniq > $export_symbols'
    ;;
  esac
], [
  runpath_var=
  _LT_TAGVAR(allow_undefined_flag, $1)=
  _LT_TAGVAR(always_export_symbols, $1)=no
  _LT_TAGVAR(archive_cmds, $1)=
  _LT_TAGVAR(archive_expsym_cmds, $1)=
  _LT_TAGVAR(compiler_needs_object, $1)=no
  _LT_TAGVAR(enable_shared_with_static_runtimes, $1)=no
  _LT_TAGVAR(export_dynamic_flag_spec, $1)=
  _LT_TAGVAR(export_symbols_cmds, $1)='$NM $libobjs $convenience | $global_symbol_pipe | $SED '\''s/.* //'\'' | sort | uniq > $export_symbols'
  _LT_TAGVAR(hardcode_automatic, $1)=no
  _LT_TAGVAR(hardcode_direct, $1)=no
  _LT_TAGVAR(hardcode_direct_absolute, $1)=no
  _LT_TAGVAR(hardcode_libdir_flag_spec, $1)=
  _LT_TAGVAR(hardcode_libdir_separator, $1)=
  _LT_TAGVAR(hardcode_minus_L, $1)=no
  _LT_TAGVAR(hardcode_shlibpath_var, $1)=unsupported
  _LT_TAGVAR(inherit_rpath, $1)=no
  _LT_TAGVAR(link_all_deplibs, $1)=unknown
  _LT_TAGVAR(module_cmds, $1)=
  _LT_TAGVAR(module_expsym_cmds, $1)=
  _LT_TAGVAR(old_archive_from_new_cmds, $1)=
  _LT_TAGVAR(old_archive_from_expsyms_cmds, $1)=
  _LT_TAGVAR(thread_safe_flag_spec, $1)=
  _LT_TAGVAR(whole_archive_flag_spec, $1)=
  # include_expsyms should be a list of space-separated symbols to be *always*
  # included in the symbol list
  _LT_TAGVAR(include_expsyms, $1)=
  # exclude_expsyms can be an extended regexp of symbols to exclude
  # it will be wrapped by ` (' and `)$', so one must not match beginning or
  # end of line.  Example: `a|bc|.*d.*' will exclude the symbols `a' and `bc',
  # as well as any symbol that contains `d'.
  _LT_TAGVAR(exclude_expsyms, $1)=['_GLOBAL_OFFSET_TABLE_|_GLOBAL__F[ID]_.*']
  # Although _GLOBAL_OFFSET_TABLE_ is a valid symbol C name, most a.out
  # platforms (ab)use it in PIC code, but their linkers get confused if
  # the symbol is explicitly referenced.  Since portable code cannot
  # rely on this symbol name, it's probably fine to never include it in
  # preloaded symbol tables.
  # Exclude shared library initialization/finalization symbols.
dnl Note also adjust exclude_expsyms for C++ above.
  extract_expsyms_cmds=

  case $host_os in
  cygwin* | mingw* | pw32* | cegcc*)
    # FIXME: the MSVC++ port hasn't been tested in a loooong time
    # When not using gcc, we currently assume that we are using
    # Microsoft Visual C++.
    if test "$GCC" != yes; then
      with_gnu_ld=no
    fi
    ;;
  interix*)
    # we just hope/assume this is gcc and not c89 (= MSVC++)
    with_gnu_ld=yes
    ;;
  openbsd*)
    with_gnu_ld=no
    ;;
  esac

  _LT_TAGVAR(ld_shlibs, $1)=yes

  # On some targets, GNU ld is compatible enough with the native linker
  # that we're better off using the native interface for both.
  lt_use_gnu_ld_interface=no
  if test "$with_gnu_ld" = yes; then
    case $host_os in
      aix*)
	# The AIX port of GNU ld has always aspired to compatibility
	# with the native linker.  However, as the warning in the GNU ld
	# block says, versions before 2.19.5* couldn't really create working
	# shared libraries, regardless of the interface used.
	case `$LD -v 2>&1` in
	  *\ \(GNU\ Binutils\)\ 2.19.5*) ;;
	  *\ \(GNU\ Binutils\)\ 2.[[2-9]]*) ;;
	  *\ \(GNU\ Binutils\)\ [[3-9]]*) ;;
	  *)
	    lt_use_gnu_ld_interface=yes
	    ;;
	esac
	;;
      *)
	lt_use_gnu_ld_interface=yes
	;;
    esac
  fi

  if test "$lt_use_gnu_ld_interface" = yes; then
    # If archive_cmds runs LD, not CC, wlarc should be empty
    wlarc='${wl}'

    # Set some defaults for GNU ld with shared library support. These
    # are reset later if shared libraries are not supported. Putting them
    # here allows them to be overridden if necessary.
    runpath_var=LD_RUN_PATH
    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
    _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}--export-dynamic'
    # ancient GNU ld didn't support --whole-archive et. al.
    if $LD --help 2>&1 | $GREP 'no-whole-archive' > /dev/null; then
      _LT_TAGVAR(whole_archive_flag_spec, $1)="$wlarc"'--whole-archive$convenience '"$wlarc"'--no-whole-archive'
    else
      _LT_TAGVAR(whole_archive_flag_spec, $1)=
    fi
    supports_anon_versioning=no
    case `$LD -v 2>&1` in
      *GNU\ gold*) supports_anon_versioning=yes ;;
      *\ [[01]].* | *\ 2.[[0-9]].* | *\ 2.10.*) ;; # catch versions < 2.11
      *\ 2.11.93.0.2\ *) supports_anon_versioning=yes ;; # RH7.3 ...
      *\ 2.11.92.0.12\ *) supports_anon_versioning=yes ;; # Mandrake 8.2 ...
      *\ 2.11.*) ;; # other 2.11 versions
      *) supports_anon_versioning=yes ;;
    esac

    # See if GNU ld supports shared libraries.
    case $host_os in
    aix[[3-9]]*)
      # On AIX/PPC, the GNU linker is very broken
      if test "$host_cpu" != ia64; then
	_LT_TAGVAR(ld_shlibs, $1)=no
	cat <<_LT_EOF 1>&2

*** Warning: the GNU linker, at least up to release 2.19, is reported
*** to be unable to reliably create shared libraries on AIX.
*** Therefore, libtool is disabling shared libraries support.  If you
*** really care for shared libraries, you may want to install binutils
*** 2.20 or above, or modify your PATH so that a non-GNU linker is found.
*** You will then need to restart the configuration process.

_LT_EOF
      fi
      ;;

    amigaos*)
      case $host_cpu in
      powerpc)
            # see comment about AmigaOS4 .so support
            _LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
            _LT_TAGVAR(archive_expsym_cmds, $1)=''
        ;;
      m68k)
            _LT_TAGVAR(archive_cmds, $1)='$RM $output_objdir/a2ixlibrary.data~$ECHO "#define NAME $libname" > $output_objdir/a2ixlibrary.data~$ECHO "#define LIBRARY_ID 1" >> $output_objdir/a2ixlibrary.data~$ECHO "#define VERSION $major" >> $output_objdir/a2ixlibrary.data~$ECHO "#define REVISION $revision" >> $output_objdir/a2ixlibrary.data~$AR $AR_FLAGS $lib $libobjs~$RANLIB $lib~(cd $output_objdir && a2ixlibrary -32)'
            _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
            _LT_TAGVAR(hardcode_minus_L, $1)=yes
        ;;
      esac
      ;;

    beos*)
      if $LD --help 2>&1 | $GREP ': supported targets:.* elf' > /dev/null; then
	_LT_TAGVAR(allow_undefined_flag, $1)=unsupported
	# Joseph Beckenbach <jrb3@best.com> says some releases of gcc
	# support --undefined.  This deserves some investigation.  FIXME
	_LT_TAGVAR(archive_cmds, $1)='$CC -nostart $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
      else
	_LT_TAGVAR(ld_shlibs, $1)=no
      fi
      ;;

    cygwin* | mingw* | pw32* | cegcc*)
      # _LT_TAGVAR(hardcode_libdir_flag_spec, $1) is actually meaningless,
      # as there is no search path for DLLs.
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
      _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}--export-all-symbols'
      _LT_TAGVAR(allow_undefined_flag, $1)=unsupported
      _LT_TAGVAR(always_export_symbols, $1)=no
      _LT_TAGVAR(enable_shared_with_static_runtimes, $1)=yes
      _LT_TAGVAR(export_symbols_cmds, $1)='$NM $libobjs $convenience | $global_symbol_pipe | $SED -e '\''/^[[BCDGRS]][[ ]]/s/.*[[ ]]\([[^ ]]*\)/\1 DATA/;s/^.*[[ ]]__nm__\([[^ ]]*\)[[ ]][[^ ]]*/\1 DATA/;/^I[[ ]]/d;/^[[AITW]][[ ]]/s/.* //'\'' | sort | uniq > $export_symbols'
      _LT_TAGVAR(exclude_expsyms, $1)=['[_]+GLOBAL_OFFSET_TABLE_|[_]+GLOBAL__[FID]_.*|[_]+head_[A-Za-z0-9_]+_dll|[A-Za-z0-9_]+_dll_iname']

      if $LD --help 2>&1 | $GREP 'auto-import' > /dev/null; then
        _LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags -o $output_objdir/$soname ${wl}--enable-auto-image-base -Xlinker --out-implib -Xlinker $lib'
	# If the export-symbols file already is a .def file (1st line
	# is EXPORTS), use it as is; otherwise, prepend...
	_LT_TAGVAR(archive_expsym_cmds, $1)='if test "x`$SED 1q $export_symbols`" = xEXPORTS; then
	  cp $export_symbols $output_objdir/$soname.def;
	else
	  echo EXPORTS > $output_objdir/$soname.def;
	  cat $export_symbols >> $output_objdir/$soname.def;
	fi~
	$CC -shared $output_objdir/$soname.def $libobjs $deplibs $compiler_flags -o $output_objdir/$soname ${wl}--enable-auto-image-base -Xlinker --out-implib -Xlinker $lib'
      else
	_LT_TAGVAR(ld_shlibs, $1)=no
      fi
      ;;

    haiku*)
      _LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
      _LT_TAGVAR(link_all_deplibs, $1)=yes
      ;;

    interix[[3-9]]*)
      _LT_TAGVAR(hardcode_direct, $1)=no
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
      _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
      # Hack: On Interix 3.x, we cannot compile PIC because of a broken gcc.
      # Instead, shared libraries are loaded at an image base (0x10000000 by
      # default) and relocated if they conflict, which is a slow very memory
      # consuming and fragmenting process.  To avoid this, we pick a random,
      # 256 KiB-aligned image base between 0x50000000 and 0x6FFC0000 at link
      # time.  Moving up from 0x10000000 also allows more sbrk(2) space.
      _LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag $libobjs $deplibs $compiler_flags ${wl}-h,$soname ${wl}--image-base,`expr ${RANDOM-$$} % 4096 / 2 \* 262144 + 1342177280` -o $lib'
      _LT_TAGVAR(archive_expsym_cmds, $1)='sed "s,^,_," $export_symbols >$output_objdir/$soname.expsym~$CC -shared $pic_flag $libobjs $deplibs $compiler_flags ${wl}-h,$soname ${wl}--retain-symbols-file,$output_objdir/$soname.expsym ${wl}--image-base,`expr ${RANDOM-$$} % 4096 / 2 \* 262144 + 1342177280` -o $lib'
      ;;

    gnu* | linux* | tpf* | k*bsd*-gnu | kopensolaris*-gnu)
      tmp_diet=no
      if test "$host_os" = linux-dietlibc; then
	case $cc_basename in
	  diet\ *) tmp_diet=yes;;	# linux-dietlibc with static linking (!diet-dyn)
	esac
      fi
      if $LD --help 2>&1 | $EGREP ': supported targets:.* elf' > /dev/null \
	 && test "$tmp_diet" = no
      then
	tmp_addflag=' $pic_flag'
	tmp_sharedflag='-shared'
	case $cc_basename,$host_cpu in
        pgcc*)				# Portland Group C compiler
	  _LT_TAGVAR(whole_archive_flag_spec, $1)='${wl}--whole-archive`for conv in $convenience\"\"; do test  -n \"$conv\" && new_convenience=\"$new_convenience,$conv\"; done; func_echo_all \"$new_convenience\"` ${wl}--no-whole-archive'
	  tmp_addflag=' $pic_flag'
	  ;;
	pgf77* | pgf90* | pgf95* | pgfortran*)
					# Portland Group f77 and f90 compilers
	  _LT_TAGVAR(whole_archive_flag_spec, $1)='${wl}--whole-archive`for conv in $convenience\"\"; do test  -n \"$conv\" && new_convenience=\"$new_convenience,$conv\"; done; func_echo_all \"$new_convenience\"` ${wl}--no-whole-archive'
	  tmp_addflag=' $pic_flag -Mnomain' ;;
	ecc*,ia64* | icc*,ia64*)	# Intel C compiler on ia64
	  tmp_addflag=' -i_dynamic' ;;
	efc*,ia64* | ifort*,ia64*)	# Intel Fortran compiler on ia64
	  tmp_addflag=' -i_dynamic -nofor_main' ;;
	ifc* | ifort*)			# Intel Fortran compiler
	  tmp_addflag=' -nofor_main' ;;
	lf95*)				# Lahey Fortran 8.1
	  _LT_TAGVAR(whole_archive_flag_spec, $1)=
	  tmp_sharedflag='--shared' ;;
	xl[[cC]]* | bgxl[[cC]]* | mpixl[[cC]]*) # IBM XL C 8.0 on PPC (deal with xlf below)
	  tmp_sharedflag='-qmkshrobj'
	  tmp_addflag= ;;
	nvcc*)	# Cuda Compiler Driver 2.2
	  _LT_TAGVAR(whole_archive_flag_spec, $1)='${wl}--whole-archive`for conv in $convenience\"\"; do test  -n \"$conv\" && new_convenience=\"$new_convenience,$conv\"; done; func_echo_all \"$new_convenience\"` ${wl}--no-whole-archive'
	  _LT_TAGVAR(compiler_needs_object, $1)=yes
	  ;;
	esac
	case `$CC -V 2>&1 | sed 5q` in
	*Sun\ C*)			# Sun C 5.9
	  _LT_TAGVAR(whole_archive_flag_spec, $1)='${wl}--whole-archive`new_convenience=; for conv in $convenience\"\"; do test -z \"$conv\" || new_convenience=\"$new_convenience,$conv\"; done; func_echo_all \"$new_convenience\"` ${wl}--no-whole-archive'
	  _LT_TAGVAR(compiler_needs_object, $1)=yes
	  tmp_sharedflag='-G' ;;
	*Sun\ F*)			# Sun Fortran 8.3
	  tmp_sharedflag='-G' ;;
	esac
	_LT_TAGVAR(archive_cmds, $1)='$CC '"$tmp_sharedflag""$tmp_addflag"' $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'

        if test "x$supports_anon_versioning" = xyes; then
          _LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $output_objdir/$libname.ver~
	    cat $export_symbols | sed -e "s/\(.*\)/\1;/" >> $output_objdir/$libname.ver~
	    echo "local: *; };" >> $output_objdir/$libname.ver~
	    $CC '"$tmp_sharedflag""$tmp_addflag"' $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-version-script ${wl}$output_objdir/$libname.ver -o $lib'
        fi

	case $cc_basename in
	xlf* | bgf* | bgxlf* | mpixlf*)
	  # IBM XL Fortran 10.1 on PPC cannot create shared libs itself
	  _LT_TAGVAR(whole_archive_flag_spec, $1)='--whole-archive$convenience --no-whole-archive'
	  _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
	  _LT_TAGVAR(archive_cmds, $1)='$LD -shared $libobjs $deplibs $linker_flags -soname $soname -o $lib'
	  if test "x$supports_anon_versioning" = xyes; then
	    _LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $output_objdir/$libname.ver~
	      cat $export_symbols | sed -e "s/\(.*\)/\1;/" >> $output_objdir/$libname.ver~
	      echo "local: *; };" >> $output_objdir/$libname.ver~
	      $LD -shared $libobjs $deplibs $linker_flags -soname $soname -version-script $output_objdir/$libname.ver -o $lib'
	  fi
	  ;;
	esac
      else
        _LT_TAGVAR(ld_shlibs, $1)=no
      fi
      ;;

    netbsd*)
      if echo __ELF__ | $CC -E - | $GREP __ELF__ >/dev/null; then
	_LT_TAGVAR(archive_cmds, $1)='$LD -Bshareable $libobjs $deplibs $linker_flags -o $lib'
	wlarc=
      else
	_LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $pic_flag $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
      fi
      ;;

    solaris*)
      if $LD -v 2>&1 | $GREP 'BFD 2\.8' > /dev/null; then
	_LT_TAGVAR(ld_shlibs, $1)=no
	cat <<_LT_EOF 1>&2

*** Warning: The releases 2.8.* of the GNU linker cannot reliably
*** create shared libraries on Solaris systems.  Therefore, libtool
*** is disabling shared libraries support.  We urge you to upgrade GNU
*** binutils to release 2.9.1 or newer.  Another option is to modify
*** your PATH or compiler configuration so that the native linker is
*** used, and then restart.

_LT_EOF
      elif $LD --help 2>&1 | $GREP ': supported targets:.* elf' > /dev/null; then
	_LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $pic_flag $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
      else
	_LT_TAGVAR(ld_shlibs, $1)=no
      fi
      ;;

    sysv5* | sco3.2v5* | sco5v6* | unixware* | OpenUNIX*)
      case `$LD -v 2>&1` in
        *\ [[01]].* | *\ 2.[[0-9]].* | *\ 2.1[[0-5]].*)
	_LT_TAGVAR(ld_shlibs, $1)=no
	cat <<_LT_EOF 1>&2

*** Warning: Releases of the GNU linker prior to 2.16.91.0.3 can not
*** reliably create shared libraries on SCO systems.  Therefore, libtool
*** is disabling shared libraries support.  We urge you to upgrade GNU
*** binutils to release 2.16.91.0.3 or newer.  Another option is to modify
*** your PATH or compiler configuration so that the native linker is
*** used, and then restart.

_LT_EOF
	;;
	*)
	  # For security reasons, it is highly recommended that you always
	  # use absolute paths for naming shared libraries, and exclude the
	  # DT_RUNPATH tag from executables and libraries.  But doing so
	  # requires that you compile everything twice, which is a pain.
	  if $LD --help 2>&1 | $GREP ': supported targets:.* elf' > /dev/null; then
	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
	    _LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
	    _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
	  else
	    _LT_TAGVAR(ld_shlibs, $1)=no
	  fi
	;;
      esac
      ;;

    sunos4*)
      _LT_TAGVAR(archive_cmds, $1)='$LD -assert pure-text -Bshareable -o $lib $libobjs $deplibs $linker_flags'
      wlarc=
      _LT_TAGVAR(hardcode_direct, $1)=yes
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      ;;

    *)
      if $LD --help 2>&1 | $GREP ': supported targets:.* elf' > /dev/null; then
	_LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $pic_flag $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
      else
	_LT_TAGVAR(ld_shlibs, $1)=no
      fi
      ;;
    esac

    if test "$_LT_TAGVAR(ld_shlibs, $1)" = no; then
      runpath_var=
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)=
      _LT_TAGVAR(export_dynamic_flag_spec, $1)=
      _LT_TAGVAR(whole_archive_flag_spec, $1)=
    fi
  else
    # PORTME fill in a description of your system's linker (not GNU ld)
    case $host_os in
    aix3*)
      _LT_TAGVAR(allow_undefined_flag, $1)=unsupported
      _LT_TAGVAR(always_export_symbols, $1)=yes
      _LT_TAGVAR(archive_expsym_cmds, $1)='$LD -o $output_objdir/$soname $libobjs $deplibs $linker_flags -bE:$export_symbols -T512 -H512 -bM:SRE~$AR $AR_FLAGS $lib $output_objdir/$soname'
      # Note: this linker hardcodes the directories in LIBPATH if there
      # are no directories specified by -L.
      _LT_TAGVAR(hardcode_minus_L, $1)=yes
      if test "$GCC" = yes && test -z "$lt_prog_compiler_static"; then
	# Neither direct hardcoding nor static linking is supported with a
	# broken collect2.
	_LT_TAGVAR(hardcode_direct, $1)=unsupported
      fi
      ;;

    aix[[4-9]]*)
      if test "$host_cpu" = ia64; then
	# On IA64, the linker does run time linking by default, so we don't
	# have to do anything special.
	aix_use_runtimelinking=no
	exp_sym_flag='-Bexport'
	no_entry_flag=""
      else
	# If we're using GNU nm, then we don't want the "-C" option.
	# -C means demangle to AIX nm, but means don't demangle with GNU nm
	# Also, AIX nm treats weak defined symbols like other global
	# defined symbols, whereas GNU nm marks them as "W".
	if $NM -V 2>&1 | $GREP 'GNU' > /dev/null; then
	  _LT_TAGVAR(export_symbols_cmds, $1)='$NM -Bpg $libobjs $convenience | awk '\''{ if (((\$ 2 == "T") || (\$ 2 == "D") || (\$ 2 == "B") || (\$ 2 == "W")) && ([substr](\$ 3,1,1) != ".")) { print \$ 3 } }'\'' | sort -u > $export_symbols'
	else
	  _LT_TAGVAR(export_symbols_cmds, $1)='$NM -BCpg $libobjs $convenience | awk '\''{ if (((\$ 2 == "T") || (\$ 2 == "D") || (\$ 2 == "B")) && ([substr](\$ 3,1,1) != ".")) { print \$ 3 } }'\'' | sort -u > $export_symbols'
	fi
	aix_use_runtimelinking=no

	# Test if we are trying to use run time linking or normal
	# AIX style linking. If -brtl is somewhere in LDFLAGS, we
	# need to do runtime linking.
	case $host_os in aix4.[[23]]|aix4.[[23]].*|aix[[5-9]]*)
	  for ld_flag in $LDFLAGS; do
	  if (test $ld_flag = "-brtl" || test $ld_flag = "-Wl,-brtl"); then
	    aix_use_runtimelinking=yes
	    break
	  fi
	  done
	  ;;
	esac

	exp_sym_flag='-bexport'
	no_entry_flag='-bnoentry'
      fi

      # When large executables or shared objects are built, AIX ld can
      # have problems creating the table of contents.  If linking a library
      # or program results in "error TOC overflow" add -mminimal-toc to
      # CXXFLAGS/CFLAGS for g++/gcc.  In the cases where that is not
      # enough to fix the problem, add -Wl,-bbigtoc to LDFLAGS.

      _LT_TAGVAR(archive_cmds, $1)=''
      _LT_TAGVAR(hardcode_direct, $1)=yes
      _LT_TAGVAR(hardcode_direct_absolute, $1)=yes
      _LT_TAGVAR(hardcode_libdir_separator, $1)=':'
      _LT_TAGVAR(link_all_deplibs, $1)=yes
      _LT_TAGVAR(file_list_spec, $1)='${wl}-f,'

      if test "$GCC" = yes; then
	case $host_os in aix4.[[012]]|aix4.[[012]].*)
	# We only want to do this on AIX 4.2 and lower, the check
	# below for broken collect2 doesn't work under 4.3+
	  collect2name=`${CC} -print-prog-name=collect2`
	  if test -f "$collect2name" &&
	   strings "$collect2name" | $GREP resolve_lib_name >/dev/null
	  then
	  # We have reworked collect2
	  :
	  else
	  # We have old collect2
	  _LT_TAGVAR(hardcode_direct, $1)=unsupported
	  # It fails to find uninstalled libraries when the uninstalled
	  # path is not listed in the libpath.  Setting hardcode_minus_L
	  # to unsupported forces relinking
	  _LT_TAGVAR(hardcode_minus_L, $1)=yes
	  _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
	  _LT_TAGVAR(hardcode_libdir_separator, $1)=
	  fi
	  ;;
	esac
	shared_flag='-shared'
	if test "$aix_use_runtimelinking" = yes; then
	  shared_flag="$shared_flag "'${wl}-G'
	fi
      else
	# not using gcc
	if test "$host_cpu" = ia64; then
	# VisualAge C++, Version 5.5 for AIX 5L for IA-64, Beta 3 Release
	# chokes on -Wl,-G. The following line is correct:
	  shared_flag='-G'
	else
	  if test "$aix_use_runtimelinking" = yes; then
	    shared_flag='${wl}-G'
	  else
	    shared_flag='${wl}-bM:SRE'
	  fi
	fi
      fi

      _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-bexpall'
      # It seems that -bexpall does not export symbols beginning with
      # underscore (_), so it is better to generate a list of symbols to export.
      _LT_TAGVAR(always_export_symbols, $1)=yes
      if test "$aix_use_runtimelinking" = yes; then
	# Warning - without using the other runtime loading flags (-brtl),
	# -berok will link without error, but may produce a broken library.
	_LT_TAGVAR(allow_undefined_flag, $1)='-berok'
        # Determine the default libpath from the value encoded in an
        # empty executable.
        _LT_SYS_MODULE_PATH_AIX([$1])
        _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-blibpath:$libdir:'"$aix_libpath"
        _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -o $output_objdir/$soname $libobjs $deplibs '"\${wl}$no_entry_flag"' $compiler_flags `if test "x${allow_undefined_flag}" != "x"; then func_echo_all "${wl}${allow_undefined_flag}"; else :; fi` '"\${wl}$exp_sym_flag:\$export_symbols $shared_flag"
      else
	if test "$host_cpu" = ia64; then
	  _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-R $libdir:/usr/lib:/lib'
	  _LT_TAGVAR(allow_undefined_flag, $1)="-z nodefs"
	  _LT_TAGVAR(archive_expsym_cmds, $1)="\$CC $shared_flag"' -o $output_objdir/$soname $libobjs $deplibs '"\${wl}$no_entry_flag"' $compiler_flags ${wl}${allow_undefined_flag} '"\${wl}$exp_sym_flag:\$export_symbols"
	else
	 # Determine the default libpath from the value encoded in an
	 # empty executable.
	 _LT_SYS_MODULE_PATH_AIX([$1])
	 _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-blibpath:$libdir:'"$aix_libpath"
	  # Warning - without using the other run time loading flags,
	  # -berok will link without error, but may produce a broken library.
	  _LT_TAGVAR(no_undefined_flag, $1)=' ${wl}-bernotok'
	  _LT_TAGVAR(allow_undefined_flag, $1)=' ${wl}-berok'
	  if test "$with_gnu_ld" = yes; then
	    # We only use this code for GNU lds that support --whole-archive.
	    _LT_TAGVAR(whole_archive_flag_spec, $1)='${wl}--whole-archive$convenience ${wl}--no-whole-archive'
	  else
	    # Exported symbols can be pulled into shared objects from archives
	    _LT_TAGVAR(whole_archive_flag_spec, $1)='$convenience'
	  fi
	  _LT_TAGVAR(archive_cmds_need_lc, $1)=yes
	  # This is similar to how AIX traditionally builds its shared libraries.
	  _LT_TAGVAR(archive_expsym_cmds, $1)="\$CC $shared_flag"' -o $output_objdir/$soname $libobjs $deplibs ${wl}-bnoentry $compiler_flags ${wl}-bE:$export_symbols${allow_undefined_flag}~$AR $AR_FLAGS $output_objdir/$libname$release.a $output_objdir/$soname'
	fi
      fi
      ;;

    amigaos*)
      case $host_cpu in
      powerpc)
            # see comment about AmigaOS4 .so support
            _LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
            _LT_TAGVAR(archive_expsym_cmds, $1)=''
        ;;
      m68k)
            _LT_TAGVAR(archive_cmds, $1)='$RM $output_objdir/a2ixlibrary.data~$ECHO "#define NAME $libname" > $output_objdir/a2ixlibrary.data~$ECHO "#define LIBRARY_ID 1" >> $output_objdir/a2ixlibrary.data~$ECHO "#define VERSION $major" >> $output_objdir/a2ixlibrary.data~$ECHO "#define REVISION $revision" >> $output_objdir/a2ixlibrary.data~$AR $AR_FLAGS $lib $libobjs~$RANLIB $lib~(cd $output_objdir && a2ixlibrary -32)'
            _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
            _LT_TAGVAR(hardcode_minus_L, $1)=yes
        ;;
      esac
      ;;

    bsdi[[45]]*)
      _LT_TAGVAR(export_dynamic_flag_spec, $1)=-rdynamic
      ;;

    cygwin* | mingw* | pw32* | cegcc*)
      # When not using gcc, we currently assume that we are using
      # Microsoft Visual C++.
      # hardcode_libdir_flag_spec is actually meaningless, as there is
      # no search path for DLLs.
      case $cc_basename in
      cl*)
	# Native MSVC
	_LT_TAGVAR(hardcode_libdir_flag_spec, $1)=' '
	_LT_TAGVAR(allow_undefined_flag, $1)=unsupported
	_LT_TAGVAR(always_export_symbols, $1)=yes
	_LT_TAGVAR(file_list_spec, $1)='@'
	# Tell ltmain to make .lib files, not .a files.
	libext=lib
	# Tell ltmain to make .dll files, not .so files.
	shrext_cmds=".dll"
	# FIXME: Setting linknames here is a bad hack.
	_LT_TAGVAR(archive_cmds, $1)='$CC -o $output_objdir/$soname $libobjs $compiler_flags $deplibs -Wl,-dll~linknames='
	_LT_TAGVAR(archive_expsym_cmds, $1)='if test "x`$SED 1q $export_symbols`" = xEXPORTS; then
	    sed -n -e 's/\\\\\\\(.*\\\\\\\)/-link\\\ -EXPORT:\\\\\\\1/' -e '1\\\!p' < $export_symbols > $output_objdir/$soname.exp;
	  else
	    sed -e 's/\\\\\\\(.*\\\\\\\)/-link\\\ -EXPORT:\\\\\\\1/' < $export_symbols > $output_objdir/$soname.exp;
	  fi~
	  $CC -o $tool_output_objdir$soname $libobjs $compiler_flags $deplibs "@$tool_output_objdir$soname.exp" -Wl,-DLL,-IMPLIB:"$tool_output_objdir$libname.dll.lib"~
	  linknames='
	# The linker will not automatically build a static lib if we build a DLL.
	# _LT_TAGVAR(old_archive_from_new_cmds, $1)='true'
	_LT_TAGVAR(enable_shared_with_static_runtimes, $1)=yes
	_LT_TAGVAR(exclude_expsyms, $1)='_NULL_IMPORT_DESCRIPTOR|_IMPORT_DESCRIPTOR_.*'
	_LT_TAGVAR(export_symbols_cmds, $1)='$NM $libobjs $convenience | $global_symbol_pipe | $SED -e '\''/^[[BCDGRS]][[ ]]/s/.*[[ ]]\([[^ ]]*\)/\1,DATA/'\'' | $SED -e '\''/^[[AITW]][[ ]]/s/.*[[ ]]//'\'' | sort | uniq > $export_symbols'
	# Don't use ranlib
	_LT_TAGVAR(old_postinstall_cmds, $1)='chmod 644 $oldlib'
	_LT_TAGVAR(postlink_cmds, $1)='lt_outputfile="@OUTPUT@"~
	  lt_tool_outputfile="@TOOL_OUTPUT@"~
	  case $lt_outputfile in
	    *.exe|*.EXE) ;;
	    *)
	      lt_outputfile="$lt_outputfile.exe"
	      lt_tool_outputfile="$lt_tool_outputfile.exe"
	      ;;
	  esac~
	  if test "$MANIFEST_TOOL" != ":" && test -f "$lt_outputfile.manifest"; then
	    $MANIFEST_TOOL -manifest "$lt_tool_outputfile.manifest" -outputresource:"$lt_tool_outputfile" || exit 1;
	    $RM "$lt_outputfile.manifest";
	  fi'
	;;
      *)
	# Assume MSVC wrapper
	_LT_TAGVAR(hardcode_libdir_flag_spec, $1)=' '
	_LT_TAGVAR(allow_undefined_flag, $1)=unsupported
	# Tell ltmain to make .lib files, not .a files.
	libext=lib
	# Tell ltmain to make .dll files, not .so files.
	shrext_cmds=".dll"
	# FIXME: Setting linknames here is a bad hack.
	_LT_TAGVAR(archive_cmds, $1)='$CC -o $lib $libobjs $compiler_flags `func_echo_all "$deplibs" | $SED '\''s/ -lc$//'\''` -link -dll~linknames='
	# The linker will automatically build a .lib file if we build a DLL.
	_LT_TAGVAR(old_archive_from_new_cmds, $1)='true'
	# FIXME: Should let the user specify the lib program.
	_LT_TAGVAR(old_archive_cmds, $1)='lib -OUT:$oldlib$oldobjs$old_deplibs'
	_LT_TAGVAR(enable_shared_with_static_runtimes, $1)=yes
	;;
      esac
      ;;

    darwin* | rhapsody*)
      _LT_DARWIN_LINKER_FEATURES($1)
      ;;

    dgux*)
      _LT_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      ;;

    # FreeBSD 2.2.[012] allows us to include c++rt0.o to get C++ constructor
    # support.  Future versions do this automatically, but an explicit c++rt0.o
    # does not break anything, and helps significantly (at the cost of a little
    # extra space).
    freebsd2.2*)
      _LT_TAGVAR(archive_cmds, $1)='$LD -Bshareable -o $lib $libobjs $deplibs $linker_flags /usr/lib/c++rt0.o'
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
      _LT_TAGVAR(hardcode_direct, $1)=yes
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      ;;

    # Unfortunately, older versions of FreeBSD 2 do not have this feature.
    freebsd2.*)
      _LT_TAGVAR(archive_cmds, $1)='$LD -Bshareable -o $lib $libobjs $deplibs $linker_flags'
      _LT_TAGVAR(hardcode_direct, $1)=yes
      _LT_TAGVAR(hardcode_minus_L, $1)=yes
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      ;;

    # FreeBSD 3 and greater uses gcc -shared to do shared libraries.
    freebsd* | dragonfly*)
      _LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag -o $lib $libobjs $deplibs $compiler_flags'
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
      _LT_TAGVAR(hardcode_direct, $1)=yes
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      ;;

    hpux9*)
      if test "$GCC" = yes; then
	_LT_TAGVAR(archive_cmds, $1)='$RM $output_objdir/$soname~$CC -shared $pic_flag ${wl}+b ${wl}$install_libdir -o $output_objdir/$soname $libobjs $deplibs $compiler_flags~test $output_objdir/$soname = $lib || mv $output_objdir/$soname $lib'
      else
	_LT_TAGVAR(archive_cmds, $1)='$RM $output_objdir/$soname~$LD -b +b $install_libdir -o $output_objdir/$soname $libobjs $deplibs $linker_flags~test $output_objdir/$soname = $lib || mv $output_objdir/$soname $lib'
      fi
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}+b ${wl}$libdir'
      _LT_TAGVAR(hardcode_libdir_separator, $1)=:
      _LT_TAGVAR(hardcode_direct, $1)=yes

      # hardcode_minus_L: Not really in the search PATH,
      # but as the default location of the library.
      _LT_TAGVAR(hardcode_minus_L, $1)=yes
      _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
      ;;

    hpux10*)
      if test "$GCC" = yes && test "$with_gnu_ld" = no; then
	_LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag ${wl}+h ${wl}$soname ${wl}+b ${wl}$install_libdir -o $lib $libobjs $deplibs $compiler_flags'
      else
	_LT_TAGVAR(archive_cmds, $1)='$LD -b +h $soname +b $install_libdir -o $lib $libobjs $deplibs $linker_flags'
      fi
      if test "$with_gnu_ld" = no; then
	_LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}+b ${wl}$libdir'
	_LT_TAGVAR(hardcode_libdir_separator, $1)=:
	_LT_TAGVAR(hardcode_direct, $1)=yes
	_LT_TAGVAR(hardcode_direct_absolute, $1)=yes
	_LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
	# hardcode_minus_L: Not really in the search PATH,
	# but as the default location of the library.
	_LT_TAGVAR(hardcode_minus_L, $1)=yes
      fi
      ;;

    hpux11*)
      if test "$GCC" = yes && test "$with_gnu_ld" = no; then
	case $host_cpu in
	hppa*64*)
	  _LT_TAGVAR(archive_cmds, $1)='$CC -shared ${wl}+h ${wl}$soname -o $lib $libobjs $deplibs $compiler_flags'
	  ;;
	ia64*)
	  _LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag ${wl}+h ${wl}$soname ${wl}+nodefaultrpath -o $lib $libobjs $deplibs $compiler_flags'
	  ;;
	*)
	  _LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag ${wl}+h ${wl}$soname ${wl}+b ${wl}$install_libdir -o $lib $libobjs $deplibs $compiler_flags'
	  ;;
	esac
      else
	case $host_cpu in
	hppa*64*)
	  _LT_TAGVAR(archive_cmds, $1)='$CC -b ${wl}+h ${wl}$soname -o $lib $libobjs $deplibs $compiler_flags'
	  ;;
	ia64*)
	  _LT_TAGVAR(archive_cmds, $1)='$CC -b ${wl}+h ${wl}$soname ${wl}+nodefaultrpath -o $lib $libobjs $deplibs $compiler_flags'
	  ;;
	*)
	m4_if($1, [], [
	  # Older versions of the 11.00 compiler do not understand -b yet
	  # (HP92453-01 A.11.01.20 doesn't, HP92453-01 B.11.X.35175-35176.GP does)
	  _LT_LINKER_OPTION([if $CC understands -b],
	    _LT_TAGVAR(lt_cv_prog_compiler__b, $1), [-b],
	    [_LT_TAGVAR(archive_cmds, $1)='$CC -b ${wl}+h ${wl}$soname ${wl}+b ${wl}$install_libdir -o $lib $libobjs $deplibs $compiler_flags'],
	    [_LT_TAGVAR(archive_cmds, $1)='$LD -b +h $soname +b $install_libdir -o $lib $libobjs $deplibs $linker_flags'])],
	  [_LT_TAGVAR(archive_cmds, $1)='$CC -b ${wl}+h ${wl}$soname ${wl}+b ${wl}$install_libdir -o $lib $libobjs $deplibs $compiler_flags'])
	  ;;
	esac
      fi
      if test "$with_gnu_ld" = no; then
	_LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}+b ${wl}$libdir'
	_LT_TAGVAR(hardcode_libdir_separator, $1)=:

	case $host_cpu in
	hppa*64*|ia64*)
	  _LT_TAGVAR(hardcode_direct, $1)=no
	  _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
	  ;;
	*)
	  _LT_TAGVAR(hardcode_direct, $1)=yes
	  _LT_TAGVAR(hardcode_direct_absolute, $1)=yes
	  _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'

	  # hardcode_minus_L: Not really in the search PATH,
	  # but as the default location of the library.
	  _LT_TAGVAR(hardcode_minus_L, $1)=yes
	  ;;
	esac
      fi
      ;;

    irix5* | irix6* | nonstopux*)
      if test "$GCC" = yes; then
	_LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag $libobjs $deplibs $compiler_flags ${wl}-soname ${wl}$soname `test -n "$verstring" && func_echo_all "${wl}-set_version ${wl}$verstring"` ${wl}-update_registry ${wl}${output_objdir}/so_locations -o $lib'
	# Try to use the -exported_symbol ld option, if it does not
	# work, assume that -exports_file does not work either and
	# implicitly export all symbols.
	# This should be the same for all languages, so no per-tag cache variable.
	AC_CACHE_CHECK([whether the $host_os linker accepts -exported_symbol],
	  [lt_cv_irix_exported_symbol],
	  [save_LDFLAGS="$LDFLAGS"
	   LDFLAGS="$LDFLAGS -shared ${wl}-exported_symbol ${wl}foo ${wl}-update_registry ${wl}/dev/null"
	   AC_LINK_IFELSE(
	     [AC_LANG_SOURCE(
	        [AC_LANG_CASE([C], [[int foo (void) { return 0; }]],
			      [C++], [[int foo (void) { return 0; }]],
			      [Fortran 77], [[
      subroutine foo
      end]],
			      [Fortran], [[
      subroutine foo
      end]])])],
	      [lt_cv_irix_exported_symbol=yes],
	      [lt_cv_irix_exported_symbol=no])
           LDFLAGS="$save_LDFLAGS"])
	if test "$lt_cv_irix_exported_symbol" = yes; then
          _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $pic_flag $libobjs $deplibs $compiler_flags ${wl}-soname ${wl}$soname `test -n "$verstring" && func_echo_all "${wl}-set_version ${wl}$verstring"` ${wl}-update_registry ${wl}${output_objdir}/so_locations ${wl}-exports_file ${wl}$export_symbols -o $lib'
	fi
      else
	_LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags -soname $soname `test -n "$verstring" && func_echo_all "-set_version $verstring"` -update_registry ${output_objdir}/so_locations -o $lib'
	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags -soname $soname `test -n "$verstring" && func_echo_all "-set_version $verstring"` -update_registry ${output_objdir}/so_locations -exports_file $export_symbols -o $lib'
      fi
      _LT_TAGVAR(archive_cmds_need_lc, $1)='no'
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
      _LT_TAGVAR(hardcode_libdir_separator, $1)=:
      _LT_TAGVAR(inherit_rpath, $1)=yes
      _LT_TAGVAR(link_all_deplibs, $1)=yes
      ;;

    netbsd*)
      if echo __ELF__ | $CC -E - | $GREP __ELF__ >/dev/null; then
	_LT_TAGVAR(archive_cmds, $1)='$LD -Bshareable -o $lib $libobjs $deplibs $linker_flags'  # a.out
      else
	_LT_TAGVAR(archive_cmds, $1)='$LD -shared -o $lib $libobjs $deplibs $linker_flags'      # ELF
      fi
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
      _LT_TAGVAR(hardcode_direct, $1)=yes
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      ;;

    newsos6)
      _LT_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
      _LT_TAGVAR(hardcode_direct, $1)=yes
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
      _LT_TAGVAR(hardcode_libdir_separator, $1)=:
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      ;;

    *nto* | *qnx*)
      ;;

    openbsd*)
      if test -f /usr/libexec/ld.so; then
	_LT_TAGVAR(hardcode_direct, $1)=yes
	_LT_TAGVAR(hardcode_shlibpath_var, $1)=no
	_LT_TAGVAR(hardcode_direct_absolute, $1)=yes
	if test -z "`echo __ELF__ | $CC -E - | $GREP __ELF__`" || test "$host_os-$host_cpu" = "openbsd2.8-powerpc"; then
	  _LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag -o $lib $libobjs $deplibs $compiler_flags'
	  _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $pic_flag -o $lib $libobjs $deplibs $compiler_flags ${wl}-retain-symbols-file,$export_symbols'
	  _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
	  _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
	else
	  case $host_os in
	   openbsd[[01]].* | openbsd2.[[0-7]] | openbsd2.[[0-7]].*)
	     _LT_TAGVAR(archive_cmds, $1)='$LD -Bshareable -o $lib $libobjs $deplibs $linker_flags'
	     _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
	     ;;
	   *)
	     _LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag -o $lib $libobjs $deplibs $compiler_flags'
	     _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
	     ;;
	  esac
	fi
      else
	_LT_TAGVAR(ld_shlibs, $1)=no
      fi
      ;;

    os2*)
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
      _LT_TAGVAR(hardcode_minus_L, $1)=yes
      _LT_TAGVAR(allow_undefined_flag, $1)=unsupported
      _LT_TAGVAR(archive_cmds, $1)='$ECHO "LIBRARY $libname INITINSTANCE" > $output_objdir/$libname.def~$ECHO "DESCRIPTION \"$libname\"" >> $output_objdir/$libname.def~echo DATA >> $output_objdir/$libname.def~echo " SINGLE NONSHARED" >> $output_objdir/$libname.def~echo EXPORTS >> $output_objdir/$libname.def~emxexp $libobjs >> $output_objdir/$libname.def~$CC -Zdll -Zcrtdll -o $lib $libobjs $deplibs $compiler_flags $output_objdir/$libname.def'
      _LT_TAGVAR(old_archive_from_new_cmds, $1)='emximp -o $output_objdir/$libname.a $output_objdir/$libname.def'
      ;;

    osf3*)
      if test "$GCC" = yes; then
	_LT_TAGVAR(allow_undefined_flag, $1)=' ${wl}-expect_unresolved ${wl}\*'
	_LT_TAGVAR(archive_cmds, $1)='$CC -shared${allow_undefined_flag} $libobjs $deplibs $compiler_flags ${wl}-soname ${wl}$soname `test -n "$verstring" && func_echo_all "${wl}-set_version ${wl}$verstring"` ${wl}-update_registry ${wl}${output_objdir}/so_locations -o $lib'
      else
	_LT_TAGVAR(allow_undefined_flag, $1)=' -expect_unresolved \*'
	_LT_TAGVAR(archive_cmds, $1)='$CC -shared${allow_undefined_flag} $libobjs $deplibs $compiler_flags -soname $soname `test -n "$verstring" && func_echo_all "-set_version $verstring"` -update_registry ${output_objdir}/so_locations -o $lib'
      fi
      _LT_TAGVAR(archive_cmds_need_lc, $1)='no'
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
      _LT_TAGVAR(hardcode_libdir_separator, $1)=:
      ;;

    osf4* | osf5*)	# as osf3* with the addition of -msym flag
      if test "$GCC" = yes; then
	_LT_TAGVAR(allow_undefined_flag, $1)=' ${wl}-expect_unresolved ${wl}\*'
	_LT_TAGVAR(archive_cmds, $1)='$CC -shared${allow_undefined_flag} $pic_flag $libobjs $deplibs $compiler_flags ${wl}-msym ${wl}-soname ${wl}$soname `test -n "$verstring" && func_echo_all "${wl}-set_version ${wl}$verstring"` ${wl}-update_registry ${wl}${output_objdir}/so_locations -o $lib'
	_LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
      else
	_LT_TAGVAR(allow_undefined_flag, $1)=' -expect_unresolved \*'
	_LT_TAGVAR(archive_cmds, $1)='$CC -shared${allow_undefined_flag} $libobjs $deplibs $compiler_flags -msym -soname $soname `test -n "$verstring" && func_echo_all "-set_version $verstring"` -update_registry ${output_objdir}/so_locations -o $lib'
	_LT_TAGVAR(archive_expsym_cmds, $1)='for i in `cat $export_symbols`; do printf "%s %s\\n" -exported_symbol "\$i" >> $lib.exp; done; printf "%s\\n" "-hidden">> $lib.exp~
	$CC -shared${allow_undefined_flag} ${wl}-input ${wl}$lib.exp $compiler_flags $libobjs $deplibs -soname $soname `test -n "$verstring" && $ECHO "-set_version $verstring"` -update_registry ${output_objdir}/so_locations -o $lib~$RM $lib.exp'

	# Both c and cxx compiler support -rpath directly
	_LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-rpath $libdir'
      fi
      _LT_TAGVAR(archive_cmds_need_lc, $1)='no'
      _LT_TAGVAR(hardcode_libdir_separator, $1)=:
      ;;

    solaris*)
      _LT_TAGVAR(no_undefined_flag, $1)=' -z defs'
      if test "$GCC" = yes; then
	wlarc='${wl}'
	_LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag ${wl}-z ${wl}text ${wl}-h ${wl}$soname -o $lib $libobjs $deplibs $compiler_flags'
	_LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~echo "local: *; };" >> $lib.exp~
	  $CC -shared $pic_flag ${wl}-z ${wl}text ${wl}-M ${wl}$lib.exp ${wl}-h ${wl}$soname -o $lib $libobjs $deplibs $compiler_flags~$RM $lib.exp'
      else
	case `$CC -V 2>&1` in
	*"Compilers 5.0"*)
	  wlarc=''
	  _LT_TAGVAR(archive_cmds, $1)='$LD -G${allow_undefined_flag} -h $soname -o $lib $libobjs $deplibs $linker_flags'
	  _LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~echo "local: *; };" >> $lib.exp~
	  $LD -G${allow_undefined_flag} -M $lib.exp -h $soname -o $lib $libobjs $deplibs $linker_flags~$RM $lib.exp'
	  ;;
	*)
	  wlarc='${wl}'
	  _LT_TAGVAR(archive_cmds, $1)='$CC -G${allow_undefined_flag} -h $soname -o $lib $libobjs $deplibs $compiler_flags'
	  _LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~echo "local: *; };" >> $lib.exp~
	  $CC -G${allow_undefined_flag} -M $lib.exp -h $soname -o $lib $libobjs $deplibs $compiler_flags~$RM $lib.exp'
	  ;;
	esac
      fi
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      case $host_os in
      solaris2.[[0-5]] | solaris2.[[0-5]].*) ;;
      *)
	# The compiler driver will combine and reorder linker options,
	# but understands `-z linker_flag'.  GCC discards it without `$wl',
	# but is careful enough not to reorder.
	# Supported since Solaris 2.6 (maybe 2.5.1?)
	if test "$GCC" = yes; then
	  _LT_TAGVAR(whole_archive_flag_spec, $1)='${wl}-z ${wl}allextract$convenience ${wl}-z ${wl}defaultextract'
	else
	  _LT_TAGVAR(whole_archive_flag_spec, $1)='-z allextract$convenience -z defaultextract'
	fi
	;;
      esac
      _LT_TAGVAR(link_all_deplibs, $1)=yes
      ;;

    sunos4*)
      if test "x$host_vendor" = xsequent; then
	# Use $CC to link under sequent, because it throws in some extra .o
	# files that make .init and .fini sections work.
	_LT_TAGVAR(archive_cmds, $1)='$CC -G ${wl}-h $soname -o $lib $libobjs $deplibs $compiler_flags'
      else
	_LT_TAGVAR(archive_cmds, $1)='$LD -assert pure-text -Bstatic -o $lib $libobjs $deplibs $linker_flags'
      fi
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
      _LT_TAGVAR(hardcode_direct, $1)=yes
      _LT_TAGVAR(hardcode_minus_L, $1)=yes
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      ;;

    sysv4)
      case $host_vendor in
	sni)
	  _LT_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
	  _LT_TAGVAR(hardcode_direct, $1)=yes # is this really true???
	;;
	siemens)
	  ## LD is ld it makes a PLAMLIB
	  ## CC just makes a GrossModule.
	  _LT_TAGVAR(archive_cmds, $1)='$LD -G -o $lib $libobjs $deplibs $linker_flags'
	  _LT_TAGVAR(reload_cmds, $1)='$CC -r -o $output$reload_objs'
	  _LT_TAGVAR(hardcode_direct, $1)=no
        ;;
	motorola)
	  _LT_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
	  _LT_TAGVAR(hardcode_direct, $1)=no #Motorola manual says yes, but my tests say they lie
	;;
      esac
      runpath_var='LD_RUN_PATH'
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      ;;

    sysv4.3*)
      _LT_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      _LT_TAGVAR(export_dynamic_flag_spec, $1)='-Bexport'
      ;;

    sysv4*MP*)
      if test -d /usr/nec; then
	_LT_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
	_LT_TAGVAR(hardcode_shlibpath_var, $1)=no
	runpath_var=LD_RUN_PATH
	hardcode_runpath_var=yes
	_LT_TAGVAR(ld_shlibs, $1)=yes
      fi
      ;;

    sysv4*uw2* | sysv5OpenUNIX* | sysv5UnixWare7.[[01]].[[10]]* | unixware7* | sco3.2v5.0.[[024]]*)
      _LT_TAGVAR(no_undefined_flag, $1)='${wl}-z,text'
      _LT_TAGVAR(archive_cmds_need_lc, $1)=no
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      runpath_var='LD_RUN_PATH'

      if test "$GCC" = yes; then
	_LT_TAGVAR(archive_cmds, $1)='$CC -shared ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared ${wl}-Bexport:$export_symbols ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
      else
	_LT_TAGVAR(archive_cmds, $1)='$CC -G ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -G ${wl}-Bexport:$export_symbols ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
      fi
      ;;

    sysv5* | sco3.2v5* | sco5v6*)
      # Note: We can NOT use -z defs as we might desire, because we do not
      # link with -lc, and that would cause any symbols used from libc to
      # always be unresolved, which means just about no library would
      # ever link correctly.  If we're not using GNU ld we use -z text
      # though, which does catch some bad symbols but isn't as heavy-handed
      # as -z defs.
      _LT_TAGVAR(no_undefined_flag, $1)='${wl}-z,text'
      _LT_TAGVAR(allow_undefined_flag, $1)='${wl}-z,nodefs'
      _LT_TAGVAR(archive_cmds_need_lc, $1)=no
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-R,$libdir'
      _LT_TAGVAR(hardcode_libdir_separator, $1)=':'
      _LT_TAGVAR(link_all_deplibs, $1)=yes
      _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-Bexport'
      runpath_var='LD_RUN_PATH'

      if test "$GCC" = yes; then
	_LT_TAGVAR(archive_cmds, $1)='$CC -shared ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared ${wl}-Bexport:$export_symbols ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
      else
	_LT_TAGVAR(archive_cmds, $1)='$CC -G ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -G ${wl}-Bexport:$export_symbols ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
      fi
      ;;

    uts4*)
      _LT_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      ;;

    *)
      _LT_TAGVAR(ld_shlibs, $1)=no
      ;;
    esac

    if test x$host_vendor = xsni; then
      case $host in
      sysv4 | sysv4.2uw2* | sysv4.3* | sysv5*)
	_LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-Blargedynsym'
	;;
      esac
    fi
  fi
])
AC_MSG_RESULT([$_LT_TAGVAR(ld_shlibs, $1)])
test "$_LT_TAGVAR(ld_shlibs, $1)" = no && can_build_shared=no

_LT_TAGVAR(with_gnu_ld, $1)=$with_gnu_ld

_LT_DECL([], [libext], [0], [Old archive suffix (normally "a")])dnl
_LT_DECL([], [shrext_cmds], [1], [Shared library suffix (normally ".so")])dnl
_LT_DECL([], [extract_expsyms_cmds], [2],
    [The commands to extract the exported symbol list from a shared archive])

#
# Do we need to explicitly link libc?
#
case "x$_LT_TAGVAR(archive_cmds_need_lc, $1)" in
x|xyes)
  # Assume -lc should be added
  _LT_TAGVAR(archive_cmds_need_lc, $1)=yes

  if test "$enable_shared" = yes && test "$GCC" = yes; then
    case $_LT_TAGVAR(archive_cmds, $1) in
    *'~'*)
      # FIXME: we may have to deal with multi-command sequences.
      ;;
    '$CC '*)
      # Test whether the compiler implicitly links with -lc since on some
      # systems, -lgcc has to come before -lc. If gcc already passes -lc
      # to ld, don't add -lc before -lgcc.
      AC_CACHE_CHECK([whether -lc should be explicitly linked in],
	[lt_cv_]_LT_TAGVAR(archive_cmds_need_lc, $1),
	[$RM conftest*
	echo "$lt_simple_compile_test_code" > conftest.$ac_ext

	if AC_TRY_EVAL(ac_compile) 2>conftest.err; then
	  soname=conftest
	  lib=conftest
	  libobjs=conftest.$ac_objext
	  deplibs=
	  wl=$_LT_TAGVAR(lt_prog_compiler_wl, $1)
	  pic_flag=$_LT_TAGVAR(lt_prog_compiler_pic, $1)
	  compiler_flags=-v
	  linker_flags=-v
	  verstring=
	  output_objdir=.
	  libname=conftest
	  lt_save_allow_undefined_flag=$_LT_TAGVAR(allow_undefined_flag, $1)
	  _LT_TAGVAR(allow_undefined_flag, $1)=
	  if AC_TRY_EVAL(_LT_TAGVAR(archive_cmds, $1) 2\>\&1 \| $GREP \" -lc \" \>/dev/null 2\>\&1)
	  then
	    lt_cv_[]_LT_TAGVAR(archive_cmds_need_lc, $1)=no
	  else
	    lt_cv_[]_LT_TAGVAR(archive_cmds_need_lc, $1)=yes
	  fi
	  _LT_TAGVAR(allow_undefined_flag, $1)=$lt_save_allow_undefined_flag
	else
	  cat conftest.err 1>&5
	fi
	$RM conftest*
	])
      _LT_TAGVAR(archive_cmds_need_lc, $1)=$lt_cv_[]_LT_TAGVAR(archive_cmds_need_lc, $1)
      ;;
    esac
  fi
  ;;
esac

_LT_TAGDECL([build_libtool_need_lc], [archive_cmds_need_lc], [0],
    [Whether or not to add -lc for building shared libraries])
_LT_TAGDECL([allow_libtool_libs_with_static_runtimes],
    [enable_shared_with_static_runtimes], [0],
    [Whether or not to disallow shared libs when runtime libs are static])
_LT_TAGDECL([], [export_dynamic_flag_spec], [1],
    [Compiler flag to allow reflexive dlopens])
_LT_TAGDECL([], [whole_archive_flag_spec], [1],
    [Compiler flag to generate shared objects directly from archives])
_LT_TAGDECL([], [compiler_needs_object], [1],
    [Whether the compiler copes with passing no objects directly])
_LT_TAGDECL([], [old_archive_from_new_cmds], [2],
    [Create an old-style archive from a shared archive])
_LT_TAGDECL([], [old_archive_from_expsyms_cmds], [2],
    [Create a temporary old-style archive to link instead of a shared archive])
_LT_TAGDECL([], [archive_cmds], [2], [Commands used to build a shared archive])
_LT_TAGDECL([], [archive_expsym_cmds], [2])
_LT_TAGDECL([], [module_cmds], [2],
    [Commands used to build a loadable module if different from building
    a shared archive.])
_LT_TAGDECL([], [module_expsym_cmds], [2])
_LT_TAGDECL([], [with_gnu_ld], [1],
    [Whether we are building with GNU ld or not])
_LT_TAGDECL([], [allow_undefined_flag], [1],
    [Flag that allows shared libraries with undefined symbols to be built])
_LT_TAGDECL([], [no_undefined_flag], [1],
    [Flag that enforces no undefined symbols])
_LT_TAGDECL([], [hardcode_libdir_flag_spec], [1],
    [Flag to hardcode $libdir into a binary during linking.
    This must work even if $libdir does not exist])
_LT_TAGDECL([], [hardcode_libdir_separator], [1],
    [Whether we need a single "-rpath" flag with a separated argument])
_LT_TAGDECL([], [hardcode_direct], [0],
    [Set to "yes" if using DIR/libNAME${shared_ext} during linking hardcodes
    DIR into the resulting binary])
_LT_TAGDECL([], [hardcode_direct_absolute], [0],
    [Set to "yes" if using DIR/libNAME${shared_ext} during linking hardcodes
    DIR into the resulting binary and the resulting library dependency is
    "absolute", i.e impossible to change by setting ${shlibpath_var} if the
    library is relocated])
_LT_TAGDECL([], [hardcode_minus_L], [0],
    [Set to "yes" if using the -LDIR flag during linking hardcodes DIR
    into the resulting binary])
_LT_TAGDECL([], [hardcode_shlibpath_var], [0],
    [Set to "yes" if using SHLIBPATH_VAR=DIR during linking hardcodes DIR
    into the resulting binary])
_LT_TAGDECL([], [hardcode_automatic], [0],
    [Set to "yes" if building a shared library automatically hardcodes DIR
    into the library and all subsequent libraries and executables linked
    against it])
_LT_TAGDECL([], [inherit_rpath], [0],
    [Set to yes if linker adds runtime paths of dependent libraries
    to runtime path list])
_LT_TAGDECL([], [link_all_deplibs], [0],
    [Whether libtool must link a program against all its dependency libraries])
_LT_TAGDECL([], [always_export_symbols], [0],
    [Set to "yes" if exported symbols are required])
_LT_TAGDECL([], [export_symbols_cmds], [2],
    [The commands to list exported symbols])
_LT_TAGDECL([], [exclude_expsyms], [1],
    [Symbols that should not be listed in the preloaded symbols])
_LT_TAGDECL([], [include_expsyms], [1],
    [Symbols that must always be exported])
_LT_TAGDECL([], [prelink_cmds], [2],
    [Commands necessary for linking programs (against libraries) with templates])
_LT_TAGDECL([], [postlink_cmds], [2],
    [Commands necessary for finishing linking programs])
_LT_TAGDECL([], [file_list_spec], [1],
    [Specify filename containing input files])
dnl FIXME: Not yet implemented
dnl _LT_TAGDECL([], [thread_safe_flag_spec], [1],
dnl    [Compiler flag to generate thread safe objects])
])# _LT_LINKER_SHLIBS


# _LT_LANG_C_CONFIG([TAG])
# ------------------------
# Ensure that the configuration variables for a C compiler are suitably
# defined.  These variables are subsequently used by _LT_CONFIG to write
# the compiler configuration to `libtool'.
m4_defun([_LT_LANG_C_CONFIG],
[m4_require([_LT_DECL_EGREP])dnl
lt_save_CC="$CC"
AC_LANG_PUSH(C)

# Source file extension for C test sources.
ac_ext=c

# Object file extension for compiled C test sources.
objext=o
_LT_TAGVAR(objext, $1)=$objext

# Code to be used in simple compile tests
lt_simple_compile_test_code="int some_variable = 0;"

# Code to be used in simple link tests
lt_simple_link_test_code='int main(){return(0);}'

_LT_TAG_COMPILER
# Save the default compiler, since it gets overwritten when the other
# tags are being tested, and _LT_TAGVAR(compiler, []) is a NOP.
compiler_DEFAULT=$CC

# save warnings/boilerplate of simple test code
_LT_COMPILER_BOILERPLATE
_LT_LINKER_BOILERPLATE

## CAVEAT EMPTOR:
## There is no encapsulation within the following macros, do not change
## the running order or otherwise move them around unless you know exactly
## what you are doing...
if test -n "$compiler"; then
  _LT_COMPILER_NO_RTTI($1)
  _LT_COMPILER_PIC($1)
  _LT_COMPILER_C_O($1)
  _LT_COMPILER_FILE_LOCKS($1)
  _LT_LINKER_SHLIBS($1)
  _LT_SYS_DYNAMIC_LINKER($1)
  _LT_LINKER_HARDCODE_LIBPATH($1)
  LT_SYS_DLOPEN_SELF
  _LT_CMD_STRIPLIB

  # Report which library types will actually be built
  AC_MSG_CHECKING([if libtool supports shared libraries])
  AC_MSG_RESULT([$can_build_shared])

  AC_MSG_CHECKING([whether to build shared libraries])
  test "$can_build_shared" = "no" && enable_shared=no

  # On AIX, shared libraries and static libraries use the same namespace, and
  # are all built from PIC.
  case $host_os in
  aix3*)
    test "$enable_shared" = yes && enable_static=no
    if test -n "$RANLIB"; then
      archive_cmds="$archive_cmds~\$RANLIB \$lib"
      postinstall_cmds='$RANLIB $lib'
    fi
    ;;

  aix[[4-9]]*)
    if test "$host_cpu" != ia64 && test "$aix_use_runtimelinking" = no ; then
      test "$enable_shared" = yes && enable_static=no
    fi
    ;;
  esac
  AC_MSG_RESULT([$enable_shared])

  AC_MSG_CHECKING([whether to build static libraries])
  # Make sure either enable_shared or enable_static is yes.
  test "$enable_shared" = yes || enable_static=yes
  AC_MSG_RESULT([$enable_static])

  _LT_CONFIG($1)
fi
AC_LANG_POP
CC="$lt_save_CC"
])# _LT_LANG_C_CONFIG


# _LT_LANG_CXX_CONFIG([TAG])
# --------------------------
# Ensure that the configuration variables for a C++ compiler are suitably
# defined.  These variables are subsequently used by _LT_CONFIG to write
# the compiler configuration to `libtool'.
m4_defun([_LT_LANG_CXX_CONFIG],
[m4_require([_LT_FILEUTILS_DEFAULTS])dnl
m4_require([_LT_DECL_EGREP])dnl
m4_require([_LT_PATH_MANIFEST_TOOL])dnl
if test -n "$CXX" && ( test "X$CXX" != "Xno" &&
    ( (test "X$CXX" = "Xg++" && `g++ -v >/dev/null 2>&1` ) ||
    (test "X$CXX" != "Xg++"))) ; then
  AC_PROG_CXXCPP
else
  _lt_caught_CXX_error=yes
fi

AC_LANG_PUSH(C++)
_LT_TAGVAR(archive_cmds_need_lc, $1)=no
_LT_TAGVAR(allow_undefined_flag, $1)=
_LT_TAGVAR(always_export_symbols, $1)=no
_LT_TAGVAR(archive_expsym_cmds, $1)=
_LT_TAGVAR(compiler_needs_object, $1)=no
_LT_TAGVAR(export_dynamic_flag_spec, $1)=
_LT_TAGVAR(hardcode_direct, $1)=no
_LT_TAGVAR(hardcode_direct_absolute, $1)=no
_LT_TAGVAR(hardcode_libdir_flag_spec, $1)=
_LT_TAGVAR(hardcode_libdir_separator, $1)=
_LT_TAGVAR(hardcode_minus_L, $1)=no
_LT_TAGVAR(hardcode_shlibpath_var, $1)=unsupported
_LT_TAGVAR(hardcode_automatic, $1)=no
_LT_TAGVAR(inherit_rpath, $1)=no
_LT_TAGVAR(module_cmds, $1)=
_LT_TAGVAR(module_expsym_cmds, $1)=
_LT_TAGVAR(link_all_deplibs, $1)=unknown
_LT_TAGVAR(old_archive_cmds, $1)=$old_archive_cmds
_LT_TAGVAR(reload_flag, $1)=$reload_flag
_LT_TAGVAR(reload_cmds, $1)=$reload_cmds
_LT_TAGVAR(no_undefined_flag, $1)=
_LT_TAGVAR(whole_archive_flag_spec, $1)=
_LT_TAGVAR(enable_shared_with_static_runtimes, $1)=no

# Source file extension for C++ test sources.
ac_ext=cpp

# Object file extension for compiled C++ test sources.
objext=o
_LT_TAGVAR(objext, $1)=$objext

# No sense in running all these tests if we already determined that
# the CXX compiler isn't working.  Some variables (like enable_shared)
# are currently assumed to apply to all compilers on this platform,
# and will be corrupted by setting them based on a non-working compiler.
if test "$_lt_caught_CXX_error" != yes; then
  # Code to be used in simple compile tests
  lt_simple_compile_test_code="int some_variable = 0;"

  # Code to be used in simple link tests
  lt_simple_link_test_code='int main(int, char *[[]]) { return(0); }'

  # ltmain only uses $CC for tagged configurations so make sure $CC is set.
  _LT_TAG_COMPILER

  # save warnings/boilerplate of simple test code
  _LT_COMPILER_BOILERPLATE
  _LT_LINKER_BOILERPLATE

  # Allow CC to be a program name with arguments.
  lt_save_CC=$CC
  lt_save_CFLAGS=$CFLAGS
  lt_save_LD=$LD
  lt_save_GCC=$GCC
  GCC=$GXX
  lt_save_with_gnu_ld=$with_gnu_ld
  lt_save_path_LD=$lt_cv_path_LD
  if test -n "${lt_cv_prog_gnu_ldcxx+set}"; then
    lt_cv_prog_gnu_ld=$lt_cv_prog_gnu_ldcxx
  else
    $as_unset lt_cv_prog_gnu_ld
  fi
  if test -n "${lt_cv_path_LDCXX+set}"; then
    lt_cv_path_LD=$lt_cv_path_LDCXX
  else
    $as_unset lt_cv_path_LD
  fi
  test -z "${LDCXX+set}" || LD=$LDCXX
  CC=${CXX-"c++"}
  CFLAGS=$CXXFLAGS
  compiler=$CC
  _LT_TAGVAR(compiler, $1)=$CC
  _LT_CC_BASENAME([$compiler])

  if test -n "$compiler"; then
    # We don't want -fno-exception when compiling C++ code, so set the
    # no_builtin_flag separately
    if test "$GXX" = yes; then
      _LT_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)=' -fno-builtin'
    else
      _LT_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)=
    fi

    if test "$GXX" = yes; then
      # Set up default GNU C++ configuration

      LT_PATH_LD

      # Check if GNU C++ uses GNU ld as the underlying linker, since the
      # archiving commands below assume that GNU ld is being used.
      if test "$with_gnu_ld" = yes; then
        _LT_TAGVAR(archive_cmds, $1)='$CC $pic_flag -shared -nostdlib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname $wl$soname -o $lib'
        _LT_TAGVAR(archive_expsym_cmds, $1)='$CC $pic_flag -shared -nostdlib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'

        _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
        _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}--export-dynamic'

        # If archive_cmds runs LD, not CC, wlarc should be empty
        # XXX I think wlarc can be eliminated in ltcf-cxx, but I need to
        #     investigate it a little bit more. (MM)
        wlarc='${wl}'

        # ancient GNU ld didn't support --whole-archive et. al.
        if eval "`$CC -print-prog-name=ld` --help 2>&1" |
	  $GREP 'no-whole-archive' > /dev/null; then
          _LT_TAGVAR(whole_archive_flag_spec, $1)="$wlarc"'--whole-archive$convenience '"$wlarc"'--no-whole-archive'
        else
          _LT_TAGVAR(whole_archive_flag_spec, $1)=
        fi
      else
        with_gnu_ld=no
        wlarc=

        # A generic and very simple default shared library creation
        # command for GNU C++ for the case where it uses the native
        # linker, instead of GNU ld.  If possible, this setting should
        # overridden to take advantage of the native linker features on
        # the platform it is being used on.
        _LT_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags -o $lib'
      fi

      # Commands to make compiler produce verbose output that lists
      # what "hidden" libraries, object files and flags are used when
      # linking a shared library.
      output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | $GREP -v "^Configured with:" | $GREP "\-L"'

    else
      GXX=no
      with_gnu_ld=no
      wlarc=
    fi

    # PORTME: fill in a description of your system's C++ link characteristics
    AC_MSG_CHECKING([whether the $compiler linker ($LD) supports shared libraries])
    _LT_TAGVAR(ld_shlibs, $1)=yes
    case $host_os in
      aix3*)
        # FIXME: insert proper C++ library support
        _LT_TAGVAR(ld_shlibs, $1)=no
        ;;
      aix[[4-9]]*)
        if test "$host_cpu" = ia64; then
          # On IA64, the linker does run time linking by default, so we don't
          # have to do anything special.
          aix_use_runtimelinking=no
          exp_sym_flag='-Bexport'
          no_entry_flag=""
        else
          aix_use_runtimelinking=no

          # Test if we are trying to use run time linking or normal
          # AIX style linking. If -brtl is somewhere in LDFLAGS, we
          # need to do runtime linking.
          case $host_os in aix4.[[23]]|aix4.[[23]].*|aix[[5-9]]*)
	    for ld_flag in $LDFLAGS; do
	      case $ld_flag in
	      *-brtl*)
	        aix_use_runtimelinking=yes
	        break
	        ;;
	      esac
	    done
	    ;;
          esac

          exp_sym_flag='-bexport'
          no_entry_flag='-bnoentry'
        fi

        # When large executables or shared objects are built, AIX ld can
        # have problems creating the table of contents.  If linking a library
        # or program results in "error TOC overflow" add -mminimal-toc to
        # CXXFLAGS/CFLAGS for g++/gcc.  In the cases where that is not
        # enough to fix the problem, add -Wl,-bbigtoc to LDFLAGS.

        _LT_TAGVAR(archive_cmds, $1)=''
        _LT_TAGVAR(hardcode_direct, $1)=yes
        _LT_TAGVAR(hardcode_direct_absolute, $1)=yes
        _LT_TAGVAR(hardcode_libdir_separator, $1)=':'
        _LT_TAGVAR(link_all_deplibs, $1)=yes
        _LT_TAGVAR(file_list_spec, $1)='${wl}-f,'

        if test "$GXX" = yes; then
          case $host_os in aix4.[[012]]|aix4.[[012]].*)
          # We only want to do this on AIX 4.2 and lower, the check
          # below for broken collect2 doesn't work under 4.3+
	  collect2name=`${CC} -print-prog-name=collect2`
	  if test -f "$collect2name" &&
	     strings "$collect2name" | $GREP resolve_lib_name >/dev/null
	  then
	    # We have reworked collect2
	    :
	  else
	    # We have old collect2
	    _LT_TAGVAR(hardcode_direct, $1)=unsupported
	    # It fails to find uninstalled libraries when the uninstalled
	    # path is not listed in the libpath.  Setting hardcode_minus_L
	    # to unsupported forces relinking
	    _LT_TAGVAR(hardcode_minus_L, $1)=yes
	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
	    _LT_TAGVAR(hardcode_libdir_separator, $1)=
	  fi
          esac
          shared_flag='-shared'
	  if test "$aix_use_runtimelinking" = yes; then
	    shared_flag="$shared_flag "'${wl}-G'
	  fi
        else
          # not using gcc
          if test "$host_cpu" = ia64; then
	  # VisualAge C++, Version 5.5 for AIX 5L for IA-64, Beta 3 Release
	  # chokes on -Wl,-G. The following line is correct:
	  shared_flag='-G'
          else
	    if test "$aix_use_runtimelinking" = yes; then
	      shared_flag='${wl}-G'
	    else
	      shared_flag='${wl}-bM:SRE'
	    fi
          fi
        fi

        _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-bexpall'
        # It seems that -bexpall does not export symbols beginning with
        # underscore (_), so it is better to generate a list of symbols to
	# export.
        _LT_TAGVAR(always_export_symbols, $1)=yes
        if test "$aix_use_runtimelinking" = yes; then
          # Warning - without using the other runtime loading flags (-brtl),
          # -berok will link without error, but may produce a broken library.
          _LT_TAGVAR(allow_undefined_flag, $1)='-berok'
          # Determine the default libpath from the value encoded in an empty
          # executable.
          _LT_SYS_MODULE_PATH_AIX([$1])
          _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-blibpath:$libdir:'"$aix_libpath"

          _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -o $output_objdir/$soname $libobjs $deplibs '"\${wl}$no_entry_flag"' $compiler_flags `if test "x${allow_undefined_flag}" != "x"; then func_echo_all "${wl}${allow_undefined_flag}"; else :; fi` '"\${wl}$exp_sym_flag:\$export_symbols $shared_flag"
        else
          if test "$host_cpu" = ia64; then
	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-R $libdir:/usr/lib:/lib'
	    _LT_TAGVAR(allow_undefined_flag, $1)="-z nodefs"
	    _LT_TAGVAR(archive_expsym_cmds, $1)="\$CC $shared_flag"' -o $output_objdir/$soname $libobjs $deplibs '"\${wl}$no_entry_flag"' $compiler_flags ${wl}${allow_undefined_flag} '"\${wl}$exp_sym_flag:\$export_symbols"
          else
	    # Determine the default libpath from the value encoded in an
	    # empty executable.
	    _LT_SYS_MODULE_PATH_AIX([$1])
	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-blibpath:$libdir:'"$aix_libpath"
	    # Warning - without using the other run time loading flags,
	    # -berok will link without error, but may produce a broken library.
	    _LT_TAGVAR(no_undefined_flag, $1)=' ${wl}-bernotok'
	    _LT_TAGVAR(allow_undefined_flag, $1)=' ${wl}-berok'
	    if test "$with_gnu_ld" = yes; then
	      # We only use this code for GNU lds that support --whole-archive.
	      _LT_TAGVAR(whole_archive_flag_spec, $1)='${wl}--whole-archive$convenience ${wl}--no-whole-archive'
	    else
	      # Exported symbols can be pulled into shared objects from archives
	      _LT_TAGVAR(whole_archive_flag_spec, $1)='$convenience'
	    fi
	    _LT_TAGVAR(archive_cmds_need_lc, $1)=yes
	    # This is similar to how AIX traditionally builds its shared
	    # libraries.
	    _LT_TAGVAR(archive_expsym_cmds, $1)="\$CC $shared_flag"' -o $output_objdir/$soname $libobjs $deplibs ${wl}-bnoentry $compiler_flags ${wl}-bE:$export_symbols${allow_undefined_flag}~$AR $AR_FLAGS $output_objdir/$libname$release.a $output_objdir/$soname'
          fi
        fi
        ;;

      beos*)
	if $LD --help 2>&1 | $GREP ': supported targets:.* elf' > /dev/null; then
	  _LT_TAGVAR(allow_undefined_flag, $1)=unsupported
	  # Joseph Beckenbach <jrb3@best.com> says some releases of gcc
	  # support --undefined.  This deserves some investigation.  FIXME
	  _LT_TAGVAR(archive_cmds, $1)='$CC -nostart $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
	else
	  _LT_TAGVAR(ld_shlibs, $1)=no
	fi
	;;

      chorus*)
        case $cc_basename in
          *)
	  # FIXME: insert proper C++ library support
	  _LT_TAGVAR(ld_shlibs, $1)=no
	  ;;
        esac
        ;;

      cygwin* | mingw* | pw32* | cegcc*)
	case $GXX,$cc_basename in
	,cl* | no,cl*)
	  # Native MSVC
	  # hardcode_libdir_flag_spec is actually meaningless, as there is
	  # no search path for DLLs.
	  _LT_TAGVAR(hardcode_libdir_flag_spec, $1)=' '
	  _LT_TAGVAR(allow_undefined_flag, $1)=unsupported
	  _LT_TAGVAR(always_export_symbols, $1)=yes
	  _LT_TAGVAR(file_list_spec, $1)='@'
	  # Tell ltmain to make .lib files, not .a files.
	  libext=lib
	  # Tell ltmain to make .dll files, not .so files.
	  shrext_cmds=".dll"
	  # FIXME: Setting linknames here is a bad hack.
	  _LT_TAGVAR(archive_cmds, $1)='$CC -o $output_objdir/$soname $libobjs $compiler_flags $deplibs -Wl,-dll~linknames='
	  _LT_TAGVAR(archive_expsym_cmds, $1)='if test "x`$SED 1q $export_symbols`" = xEXPORTS; then
	      $SED -n -e 's/\\\\\\\(.*\\\\\\\)/-link\\\ -EXPORT:\\\\\\\1/' -e '1\\\!p' < $export_symbols > $output_objdir/$soname.exp;
	    else
	      $SED -e 's/\\\\\\\(.*\\\\\\\)/-link\\\ -EXPORT:\\\\\\\1/' < $export_symbols > $output_objdir/$soname.exp;
	    fi~
	    $CC -o $tool_output_objdir$soname $libobjs $compiler_flags $deplibs "@$tool_output_objdir$soname.exp" -Wl,-DLL,-IMPLIB:"$tool_output_objdir$libname.dll.lib"~
	    linknames='
	  # The linker will not automatically build a static lib if we build a DLL.
	  # _LT_TAGVAR(old_archive_from_new_cmds, $1)='true'
	  _LT_TAGVAR(enable_shared_with_static_runtimes, $1)=yes
	  # Don't use ranlib
	  _LT_TAGVAR(old_postinstall_cmds, $1)='chmod 644 $oldlib'
	  _LT_TAGVAR(postlink_cmds, $1)='lt_outputfile="@OUTPUT@"~
	    lt_tool_outputfile="@TOOL_OUTPUT@"~
	    case $lt_outputfile in
	      *.exe|*.EXE) ;;
	      *)
		lt_outputfile="$lt_outputfile.exe"
		lt_tool_outputfile="$lt_tool_outputfile.exe"
		;;
	    esac~
	    func_to_tool_file "$lt_outputfile"~
	    if test "$MANIFEST_TOOL" != ":" && test -f "$lt_outputfile.manifest"; then
	      $MANIFEST_TOOL -manifest "$lt_tool_outputfile.manifest" -outputresource:"$lt_tool_outputfile" || exit 1;
	      $RM "$lt_outputfile.manifest";
	    fi'
	  ;;
	*)
	  # g++
	  # _LT_TAGVAR(hardcode_libdir_flag_spec, $1) is actually meaningless,
	  # as there is no search path for DLLs.
	  _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
	  _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}--export-all-symbols'
	  _LT_TAGVAR(allow_undefined_flag, $1)=unsupported
	  _LT_TAGVAR(always_export_symbols, $1)=no
	  _LT_TAGVAR(enable_shared_with_static_runtimes, $1)=yes

	  if $LD --help 2>&1 | $GREP 'auto-import' > /dev/null; then
	    _LT_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags -o $output_objdir/$soname ${wl}--enable-auto-image-base -Xlinker --out-implib -Xlinker $lib'
	    # If the export-symbols file already is a .def file (1st line
	    # is EXPORTS), use it as is; otherwise, prepend...
	    _LT_TAGVAR(archive_expsym_cmds, $1)='if test "x`$SED 1q $export_symbols`" = xEXPORTS; then
	      cp $export_symbols $output_objdir/$soname.def;
	    else
	      echo EXPORTS > $output_objdir/$soname.def;
	      cat $export_symbols >> $output_objdir/$soname.def;
	    fi~
	    $CC -shared -nostdlib $output_objdir/$soname.def $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags -o $output_objdir/$soname ${wl}--enable-auto-image-base -Xlinker --out-implib -Xlinker $lib'
	  else
	    _LT_TAGVAR(ld_shlibs, $1)=no
	  fi
	  ;;
	esac
	;;
      darwin* | rhapsody*)
        _LT_DARWIN_LINKER_FEATURES($1)
	;;

      dgux*)
        case $cc_basename in
          ec++*)
	    # FIXME: insert proper C++ library support
	    _LT_TAGVAR(ld_shlibs, $1)=no
	    ;;
          ghcx*)
	    # Green Hills C++ Compiler
	    # FIXME: insert proper C++ library support
	    _LT_TAGVAR(ld_shlibs, $1)=no
	    ;;
          *)
	    # FIXME: insert proper C++ library support
	    _LT_TAGVAR(ld_shlibs, $1)=no
	    ;;
        esac
        ;;

      freebsd2.*)
        # C++ shared libraries reported to be fairly broken before
	# switch to ELF
        _LT_TAGVAR(ld_shlibs, $1)=no
        ;;

      freebsd-elf*)
        _LT_TAGVAR(archive_cmds_need_lc, $1)=no
        ;;

      freebsd* | dragonfly*)
        # FreeBSD 3 and later use GNU C++ and GNU ld with standard ELF
        # conventions
        _LT_TAGVAR(ld_shlibs, $1)=yes
        ;;

      gnu*)
        ;;

      haiku*)
        _LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
        _LT_TAGVAR(link_all_deplibs, $1)=yes
        ;;

      hpux9*)
        _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}+b ${wl}$libdir'
        _LT_TAGVAR(hardcode_libdir_separator, $1)=:
        _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
        _LT_TAGVAR(hardcode_direct, $1)=yes
        _LT_TAGVAR(hardcode_minus_L, $1)=yes # Not in the search PATH,
				             # but as the default
				             # location of the library.

        case $cc_basename in
          CC*)
            # FIXME: insert proper C++ library support
            _LT_TAGVAR(ld_shlibs, $1)=no
            ;;
          aCC*)
            _LT_TAGVAR(archive_cmds, $1)='$RM $output_objdir/$soname~$CC -b ${wl}+b ${wl}$install_libdir -o $output_objdir/$soname $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags~test $output_objdir/$soname = $lib || mv $output_objdir/$soname $lib'
            # Commands to make compiler produce verbose output that lists
            # what "hidden" libraries, object files and flags are used when
            # linking a shared library.
            #
            # There doesn't appear to be a way to prevent this compiler from
            # explicitly linking system object files so we need to strip them
            # from the output so that they don't get included in the library
            # dependencies.
            output_verbose_link_cmd='templist=`($CC -b $CFLAGS -v conftest.$objext 2>&1) | $EGREP "\-L"`; list=""; for z in $templist; do case $z in conftest.$objext) list="$list $z";; *.$objext);; *) list="$list $z";;esac; done; func_echo_all "$list"'
            ;;
          *)
            if test "$GXX" = yes; then
              _LT_TAGVAR(archive_cmds, $1)='$RM $output_objdir/$soname~$CC -shared -nostdlib $pic_flag ${wl}+b ${wl}$install_libdir -o $output_objdir/$soname $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags~test $output_objdir/$soname = $lib || mv $output_objdir/$soname $lib'
            else
              # FIXME: insert proper C++ library support
              _LT_TAGVAR(ld_shlibs, $1)=no
            fi
            ;;
        esac
        ;;

      hpux10*|hpux11*)
        if test $with_gnu_ld = no; then
	  _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}+b ${wl}$libdir'
	  _LT_TAGVAR(hardcode_libdir_separator, $1)=:

          case $host_cpu in
            hppa*64*|ia64*)
              ;;
            *)
	      _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
              ;;
          esac
        fi
        case $host_cpu in
          hppa*64*|ia64*)
            _LT_TAGVAR(hardcode_direct, $1)=no
            _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
            ;;
          *)
            _LT_TAGVAR(hardcode_direct, $1)=yes
            _LT_TAGVAR(hardcode_direct_absolute, $1)=yes
            _LT_TAGVAR(hardcode_minus_L, $1)=yes # Not in the search PATH,
					         # but as the default
					         # location of the library.
            ;;
        esac

        case $cc_basename in
          CC*)
	    # FIXME: insert proper C++ library support
	    _LT_TAGVAR(ld_shlibs, $1)=no
	    ;;
          aCC*)
	    case $host_cpu in
	      hppa*64*)
	        _LT_TAGVAR(archive_cmds, $1)='$CC -b ${wl}+h ${wl}$soname -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags'
	        ;;
	      ia64*)
	        _LT_TAGVAR(archive_cmds, $1)='$CC -b ${wl}+h ${wl}$soname ${wl}+nodefaultrpath -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags'
	        ;;
	      *)
	        _LT_TAGVAR(archive_cmds, $1)='$CC -b ${wl}+h ${wl}$soname ${wl}+b ${wl}$install_libdir -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags'
	        ;;
	    esac
	    # Commands to make compiler produce verbose output that lists
	    # what "hidden" libraries, object files and flags are used when
	    # linking a shared library.
	    #
	    # There doesn't appear to be a way to prevent this compiler from
	    # explicitly linking system object files so we need to strip them
	    # from the output so that they don't get included in the library
	    # dependencies.
	    output_verbose_link_cmd='templist=`($CC -b $CFLAGS -v conftest.$objext 2>&1) | $GREP "\-L"`; list=""; for z in $templist; do case $z in conftest.$objext) list="$list $z";; *.$objext);; *) list="$list $z";;esac; done; func_echo_all "$list"'
	    ;;
          *)
	    if test "$GXX" = yes; then
	      if test $with_gnu_ld = no; then
	        case $host_cpu in
	          hppa*64*)
	            _LT_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib -fPIC ${wl}+h ${wl}$soname -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags'
	            ;;
	          ia64*)
	            _LT_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib $pic_flag ${wl}+h ${wl}$soname ${wl}+nodefaultrpath -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags'
	            ;;
	          *)
	            _LT_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib $pic_flag ${wl}+h ${wl}$soname ${wl}+b ${wl}$install_libdir -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags'
	            ;;
	        esac
	      fi
	    else
	      # FIXME: insert proper C++ library support
	      _LT_TAGVAR(ld_shlibs, $1)=no
	    fi
	    ;;
        esac
        ;;

      interix[[3-9]]*)
	_LT_TAGVAR(hardcode_direct, $1)=no
	_LT_TAGVAR(hardcode_shlibpath_var, $1)=no
	_LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
	_LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
	# Hack: On Interix 3.x, we cannot compile PIC because of a broken gcc.
	# Instead, shared libraries are loaded at an image base (0x10000000 by
	# default) and relocated if they conflict, which is a slow very memory
	# consuming and fragmenting process.  To avoid this, we pick a random,
	# 256 KiB-aligned image base between 0x50000000 and 0x6FFC0000 at link
	# time.  Moving up from 0x10000000 also allows more sbrk(2) space.
	_LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag $libobjs $deplibs $compiler_flags ${wl}-h,$soname ${wl}--image-base,`expr ${RANDOM-$$} % 4096 / 2 \* 262144 + 1342177280` -o $lib'
	_LT_TAGVAR(archive_expsym_cmds, $1)='sed "s,^,_," $export_symbols >$output_objdir/$soname.expsym~$CC -shared $pic_flag $libobjs $deplibs $compiler_flags ${wl}-h,$soname ${wl}--retain-symbols-file,$output_objdir/$soname.expsym ${wl}--image-base,`expr ${RANDOM-$$} % 4096 / 2 \* 262144 + 1342177280` -o $lib'
	;;
      irix5* | irix6*)
        case $cc_basename in
          CC*)
	    # SGI C++
	    _LT_TAGVAR(archive_cmds, $1)='$CC -shared -all -multigot $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags -soname $soname `test -n "$verstring" && func_echo_all "-set_version $verstring"` -update_registry ${output_objdir}/so_locations -o $lib'

	    # Archives containing C++ object files must be created using
	    # "CC -ar", where "CC" is the IRIX C++ compiler.  This is
	    # necessary to make sure instantiated templates are included
	    # in the archive.
	    _LT_TAGVAR(old_archive_cmds, $1)='$CC -ar -WR,-u -o $oldlib $oldobjs'
	    ;;
          *)
	    if test "$GXX" = yes; then
	      if test "$with_gnu_ld" = no; then
	        _LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag -nostdlib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname ${wl}$soname `test -n "$verstring" && func_echo_all "${wl}-set_version ${wl}$verstring"` ${wl}-update_registry ${wl}${output_objdir}/so_locations -o $lib'
	      else
	        _LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag -nostdlib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname ${wl}$soname `test -n "$verstring" && func_echo_all "${wl}-set_version ${wl}$verstring"` -o $lib'
	      fi
	    fi
	    _LT_TAGVAR(link_all_deplibs, $1)=yes
	    ;;
        esac
        _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
        _LT_TAGVAR(hardcode_libdir_separator, $1)=:
        _LT_TAGVAR(inherit_rpath, $1)=yes
        ;;

      linux* | k*bsd*-gnu | kopensolaris*-gnu)
        case $cc_basename in
          KCC*)
	    # Kuck and Associates, Inc. (KAI) C++ Compiler

	    # KCC will only create a shared library if the output file
	    # ends with ".so" (or ".sl" for HP-UX), so rename the library
	    # to its proper name (with version) after linking.
	    _LT_TAGVAR(archive_cmds, $1)='tempext=`echo $shared_ext | $SED -e '\''s/\([[^()0-9A-Za-z{}]]\)/\\\\\1/g'\''`; templib=`echo $lib | $SED -e "s/\${tempext}\..*/.so/"`; $CC $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags --soname $soname -o \$templib; mv \$templib $lib'
	    _LT_TAGVAR(archive_expsym_cmds, $1)='tempext=`echo $shared_ext | $SED -e '\''s/\([[^()0-9A-Za-z{}]]\)/\\\\\1/g'\''`; templib=`echo $lib | $SED -e "s/\${tempext}\..*/.so/"`; $CC $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags --soname $soname -o \$templib ${wl}-retain-symbols-file,$export_symbols; mv \$templib $lib'
	    # Commands to make compiler produce verbose output that lists
	    # what "hidden" libraries, object files and flags are used when
	    # linking a shared library.
	    #
	    # There doesn't appear to be a way to prevent this compiler from
	    # explicitly linking system object files so we need to strip them
	    # from the output so that they don't get included in the library
	    # dependencies.
	    output_verbose_link_cmd='templist=`$CC $CFLAGS -v conftest.$objext -o libconftest$shared_ext 2>&1 | $GREP "ld"`; rm -f libconftest$shared_ext; list=""; for z in $templist; do case $z in conftest.$objext) list="$list $z";; *.$objext);; *) list="$list $z";;esac; done; func_echo_all "$list"'

	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
	    _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}--export-dynamic'

	    # Archives containing C++ object files must be created using
	    # "CC -Bstatic", where "CC" is the KAI C++ compiler.
	    _LT_TAGVAR(old_archive_cmds, $1)='$CC -Bstatic -o $oldlib $oldobjs'
	    ;;
	  icpc* | ecpc* )
	    # Intel C++
	    with_gnu_ld=yes
	    # version 8.0 and above of icpc choke on multiply defined symbols
	    # if we add $predep_objects and $postdep_objects, however 7.1 and
	    # earlier do not add the objects themselves.
	    case `$CC -V 2>&1` in
	      *"Version 7."*)
	        _LT_TAGVAR(archive_cmds, $1)='$CC -shared $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname $wl$soname -o $lib'
		_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
		;;
	      *)  # Version 8.0 or newer
	        tmp_idyn=
	        case $host_cpu in
		  ia64*) tmp_idyn=' -i_dynamic';;
		esac
	        _LT_TAGVAR(archive_cmds, $1)='$CC -shared'"$tmp_idyn"' $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
		_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared'"$tmp_idyn"' $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
		;;
	    esac
	    _LT_TAGVAR(archive_cmds_need_lc, $1)=no
	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
	    _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}--export-dynamic'
	    _LT_TAGVAR(whole_archive_flag_spec, $1)='${wl}--whole-archive$convenience ${wl}--no-whole-archive'
	    ;;
          pgCC* | pgcpp*)
            # Portland Group C++ compiler
	    case `$CC -V` in
	    *pgCC\ [[1-5]].* | *pgcpp\ [[1-5]].*)
	      _LT_TAGVAR(prelink_cmds, $1)='tpldir=Template.dir~
		rm -rf $tpldir~
		$CC --prelink_objects --instantiation_dir $tpldir $objs $libobjs $compile_deplibs~
		compile_command="$compile_command `find $tpldir -name \*.o | sort | $NL2SP`"'
	      _LT_TAGVAR(old_archive_cmds, $1)='tpldir=Template.dir~
		rm -rf $tpldir~
		$CC --prelink_objects --instantiation_dir $tpldir $oldobjs$old_deplibs~
		$AR $AR_FLAGS $oldlib$oldobjs$old_deplibs `find $tpldir -name \*.o | sort | $NL2SP`~
		$RANLIB $oldlib'
	      _LT_TAGVAR(archive_cmds, $1)='tpldir=Template.dir~
		rm -rf $tpldir~
		$CC --prelink_objects --instantiation_dir $tpldir $predep_objects $libobjs $deplibs $convenience $postdep_objects~
		$CC -shared $pic_flag $predep_objects $libobjs $deplibs `find $tpldir -name \*.o | sort | $NL2SP` $postdep_objects $compiler_flags ${wl}-soname ${wl}$soname -o $lib'
	      _LT_TAGVAR(archive_expsym_cmds, $1)='tpldir=Template.dir~
		rm -rf $tpldir~
		$CC --prelink_objects --instantiation_dir $tpldir $predep_objects $libobjs $deplibs $convenience $postdep_objects~
		$CC -shared $pic_flag $predep_objects $libobjs $deplibs `find $tpldir -name \*.o | sort | $NL2SP` $postdep_objects $compiler_flags ${wl}-soname ${wl}$soname ${wl}-retain-symbols-file ${wl}$export_symbols -o $lib'
	      ;;
	    *) # Version 6 and above use weak symbols
	      _LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname ${wl}$soname -o $lib'
	      _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $pic_flag $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname ${wl}$soname ${wl}-retain-symbols-file ${wl}$export_symbols -o $lib'
	      ;;
	    esac

	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}--rpath ${wl}$libdir'
	    _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}--export-dynamic'
	    _LT_TAGVAR(whole_archive_flag_spec, $1)='${wl}--whole-archive`for conv in $convenience\"\"; do test  -n \"$conv\" && new_convenience=\"$new_convenience,$conv\"; done; func_echo_all \"$new_convenience\"` ${wl}--no-whole-archive'
            ;;
	  cxx*)
	    # Compaq C++
	    _LT_TAGVAR(archive_cmds, $1)='$CC -shared $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname $wl$soname -o $lib'
	    _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname $wl$soname  -o $lib ${wl}-retain-symbols-file $wl$export_symbols'

	    runpath_var=LD_RUN_PATH
	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-rpath $libdir'
	    _LT_TAGVAR(hardcode_libdir_separator, $1)=:

	    # Commands to make compiler produce verbose output that lists
	    # what "hidden" libraries, object files and flags are used when
	    # linking a shared library.
	    #
	    # There doesn't appear to be a way to prevent this compiler from
	    # explicitly linking system object files so we need to strip them
	    # from the output so that they don't get included in the library
	    # dependencies.
	    output_verbose_link_cmd='templist=`$CC -shared $CFLAGS -v conftest.$objext 2>&1 | $GREP "ld"`; templist=`func_echo_all "$templist" | $SED "s/\(^.*ld.*\)\( .*ld .*$\)/\1/"`; list=""; for z in $templist; do case $z in conftest.$objext) list="$list $z";; *.$objext);; *) list="$list $z";;esac; done; func_echo_all "X$list" | $Xsed'
	    ;;
	  xl* | mpixl* | bgxl*)
	    # IBM XL 8.0 on PPC, with GNU ld
	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
	    _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}--export-dynamic'
	    _LT_TAGVAR(archive_cmds, $1)='$CC -qmkshrobj $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
	    if test "x$supports_anon_versioning" = xyes; then
	      _LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $output_objdir/$libname.ver~
		cat $export_symbols | sed -e "s/\(.*\)/\1;/" >> $output_objdir/$libname.ver~
		echo "local: *; };" >> $output_objdir/$libname.ver~
		$CC -qmkshrobj $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-version-script ${wl}$output_objdir/$libname.ver -o $lib'
	    fi
	    ;;
	  *)
	    case `$CC -V 2>&1 | sed 5q` in
	    *Sun\ C*)
	      # Sun C++ 5.9
	      _LT_TAGVAR(no_undefined_flag, $1)=' -zdefs'
	      _LT_TAGVAR(archive_cmds, $1)='$CC -G${allow_undefined_flag} -h$soname -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags'
	      _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -G${allow_undefined_flag} -h$soname -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-retain-symbols-file ${wl}$export_symbols'
	      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
	      _LT_TAGVAR(whole_archive_flag_spec, $1)='${wl}--whole-archive`new_convenience=; for conv in $convenience\"\"; do test -z \"$conv\" || new_convenience=\"$new_convenience,$conv\"; done; func_echo_all \"$new_convenience\"` ${wl}--no-whole-archive'
	      _LT_TAGVAR(compiler_needs_object, $1)=yes

	      # Not sure whether something based on
	      # $CC $CFLAGS -v conftest.$objext -o libconftest$shared_ext 2>&1
	      # would be better.
	      output_verbose_link_cmd='func_echo_all'

	      # Archives containing C++ object files must be created using
	      # "CC -xar", where "CC" is the Sun C++ compiler.  This is
	      # necessary to make sure instantiated templates are included
	      # in the archive.
	      _LT_TAGVAR(old_archive_cmds, $1)='$CC -xar -o $oldlib $oldobjs'
	      ;;
	    esac
	    ;;
	esac
	;;

      lynxos*)
        # FIXME: insert proper C++ library support
	_LT_TAGVAR(ld_shlibs, $1)=no
	;;

      m88k*)
        # FIXME: insert proper C++ library support
        _LT_TAGVAR(ld_shlibs, $1)=no
	;;

      mvs*)
        case $cc_basename in
          cxx*)
	    # FIXME: insert proper C++ library support
	    _LT_TAGVAR(ld_shlibs, $1)=no
	    ;;
	  *)
	    # FIXME: insert proper C++ library support
	    _LT_TAGVAR(ld_shlibs, $1)=no
	    ;;
	esac
	;;

      netbsd*)
        if echo __ELF__ | $CC -E - | $GREP __ELF__ >/dev/null; then
	  _LT_TAGVAR(archive_cmds, $1)='$LD -Bshareable  -o $lib $predep_objects $libobjs $deplibs $postdep_objects $linker_flags'
	  wlarc=
	  _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
	  _LT_TAGVAR(hardcode_direct, $1)=yes
	  _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
	fi
	# Workaround some broken pre-1.5 toolchains
	output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | $GREP conftest.$objext | $SED -e "s:-lgcc -lc -lgcc::"'
	;;

      *nto* | *qnx*)
        _LT_TAGVAR(ld_shlibs, $1)=yes
	;;

      openbsd2*)
        # C++ shared libraries are fairly broken
	_LT_TAGVAR(ld_shlibs, $1)=no
	;;

      openbsd*)
	if test -f /usr/libexec/ld.so; then
	  _LT_TAGVAR(hardcode_direct, $1)=yes
	  _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
	  _LT_TAGVAR(hardcode_direct_absolute, $1)=yes
	  _LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags -o $lib'
	  _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
	  if test -z "`echo __ELF__ | $CC -E - | grep __ELF__`" || test "$host_os-$host_cpu" = "openbsd2.8-powerpc"; then
	    _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $pic_flag $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-retain-symbols-file,$export_symbols -o $lib'
	    _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
	    _LT_TAGVAR(whole_archive_flag_spec, $1)="$wlarc"'--whole-archive$convenience '"$wlarc"'--no-whole-archive'
	  fi
	  output_verbose_link_cmd=func_echo_all
	else
	  _LT_TAGVAR(ld_shlibs, $1)=no
	fi
	;;

      osf3* | osf4* | osf5*)
        case $cc_basename in
          KCC*)
	    # Kuck and Associates, Inc. (KAI) C++ Compiler

	    # KCC will only create a shared library if the output file
	    # ends with ".so" (or ".sl" for HP-UX), so rename the library
	    # to its proper name (with version) after linking.
	    _LT_TAGVAR(archive_cmds, $1)='tempext=`echo $shared_ext | $SED -e '\''s/\([[^()0-9A-Za-z{}]]\)/\\\\\1/g'\''`; templib=`echo "$lib" | $SED -e "s/\${tempext}\..*/.so/"`; $CC $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags --soname $soname -o \$templib; mv \$templib $lib'

	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
	    _LT_TAGVAR(hardcode_libdir_separator, $1)=:

	    # Archives containing C++ object files must be created using
	    # the KAI C++ compiler.
	    case $host in
	      osf3*) _LT_TAGVAR(old_archive_cmds, $1)='$CC -Bstatic -o $oldlib $oldobjs' ;;
	      *) _LT_TAGVAR(old_archive_cmds, $1)='$CC -o $oldlib $oldobjs' ;;
	    esac
	    ;;
          RCC*)
	    # Rational C++ 2.4.1
	    # FIXME: insert proper C++ library support
	    _LT_TAGVAR(ld_shlibs, $1)=no
	    ;;
          cxx*)
	    case $host in
	      osf3*)
	        _LT_TAGVAR(allow_undefined_flag, $1)=' ${wl}-expect_unresolved ${wl}\*'
	        _LT_TAGVAR(archive_cmds, $1)='$CC -shared${allow_undefined_flag} $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname $soname `test -n "$verstring" && func_echo_all "${wl}-set_version $verstring"` -update_registry ${output_objdir}/so_locations -o $lib'
	        _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
		;;
	      *)
	        _LT_TAGVAR(allow_undefined_flag, $1)=' -expect_unresolved \*'
	        _LT_TAGVAR(archive_cmds, $1)='$CC -shared${allow_undefined_flag} $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags -msym -soname $soname `test -n "$verstring" && func_echo_all "-set_version $verstring"` -update_registry ${output_objdir}/so_locations -o $lib'
	        _LT_TAGVAR(archive_expsym_cmds, $1)='for i in `cat $export_symbols`; do printf "%s %s\\n" -exported_symbol "\$i" >> $lib.exp; done~
	          echo "-hidden">> $lib.exp~
	          $CC -shared$allow_undefined_flag $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags -msym -soname $soname ${wl}-input ${wl}$lib.exp  `test -n "$verstring" && $ECHO "-set_version $verstring"` -update_registry ${output_objdir}/so_locations -o $lib~
	          $RM $lib.exp'
	        _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-rpath $libdir'
		;;
	    esac

	    _LT_TAGVAR(hardcode_libdir_separator, $1)=:

	    # Commands to make compiler produce verbose output that lists
	    # what "hidden" libraries, object files and flags are used when
	    # linking a shared library.
	    #
	    # There doesn't appear to be a way to prevent this compiler from
	    # explicitly linking system object files so we need to strip them
	    # from the output so that they don't get included in the library
	    # dependencies.
	    output_verbose_link_cmd='templist=`$CC -shared $CFLAGS -v conftest.$objext 2>&1 | $GREP "ld" | $GREP -v "ld:"`; templist=`func_echo_all "$templist" | $SED "s/\(^.*ld.*\)\( .*ld.*$\)/\1/"`; list=""; for z in $templist; do case $z in conftest.$objext) list="$list $z";; *.$objext);; *) list="$list $z";;esac; done; func_echo_all "$list"'
	    ;;
	  *)
	    if test "$GXX" = yes && test "$with_gnu_ld" = no; then
	      _LT_TAGVAR(allow_undefined_flag, $1)=' ${wl}-expect_unresolved ${wl}\*'
	      case $host in
	        osf3*)
	          _LT_TAGVAR(archive_cmds, $1)='$CC -shared -nostdlib ${allow_undefined_flag} $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-soname ${wl}$soname `test -n "$verstring" && func_echo_all "${wl}-set_version ${wl}$verstring"` ${wl}-update_registry ${wl}${output_objdir}/so_locations -o $lib'
		  ;;
	        *)
	          _LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag -nostdlib ${allow_undefined_flag} $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-msym ${wl}-soname ${wl}$soname `test -n "$verstring" && func_echo_all "${wl}-set_version ${wl}$verstring"` ${wl}-update_registry ${wl}${output_objdir}/so_locations -o $lib'
		  ;;
	      esac

	      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
	      _LT_TAGVAR(hardcode_libdir_separator, $1)=:

	      # Commands to make compiler produce verbose output that lists
	      # what "hidden" libraries, object files and flags are used when
	      # linking a shared library.
	      output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | $GREP -v "^Configured with:" | $GREP "\-L"'

	    else
	      # FIXME: insert proper C++ library support
	      _LT_TAGVAR(ld_shlibs, $1)=no
	    fi
	    ;;
        esac
        ;;

      psos*)
        # FIXME: insert proper C++ library support
        _LT_TAGVAR(ld_shlibs, $1)=no
        ;;

      sunos4*)
        case $cc_basename in
          CC*)
	    # Sun C++ 4.x
	    # FIXME: insert proper C++ library support
	    _LT_TAGVAR(ld_shlibs, $1)=no
	    ;;
          lcc*)
	    # Lucid
	    # FIXME: insert proper C++ library support
	    _LT_TAGVAR(ld_shlibs, $1)=no
	    ;;
          *)
	    # FIXME: insert proper C++ library support
	    _LT_TAGVAR(ld_shlibs, $1)=no
	    ;;
        esac
        ;;

      solaris*)
        case $cc_basename in
          CC* | sunCC*)
	    # Sun C++ 4.2, 5.x and Centerline C++
            _LT_TAGVAR(archive_cmds_need_lc,$1)=yes
	    _LT_TAGVAR(no_undefined_flag, $1)=' -zdefs'
	    _LT_TAGVAR(archive_cmds, $1)='$CC -G${allow_undefined_flag}  -h$soname -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags'
	    _LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~echo "local: *; };" >> $lib.exp~
	      $CC -G${allow_undefined_flag} ${wl}-M ${wl}$lib.exp -h$soname -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags~$RM $lib.exp'

	    _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
	    _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
	    case $host_os in
	      solaris2.[[0-5]] | solaris2.[[0-5]].*) ;;
	      *)
		# The compiler driver will combine and reorder linker options,
		# but understands `-z linker_flag'.
	        # Supported since Solaris 2.6 (maybe 2.5.1?)
		_LT_TAGVAR(whole_archive_flag_spec, $1)='-z allextract$convenience -z defaultextract'
	        ;;
	    esac
	    _LT_TAGVAR(link_all_deplibs, $1)=yes

	    output_verbose_link_cmd='func_echo_all'

	    # Archives containing C++ object files must be created using
	    # "CC -xar", where "CC" is the Sun C++ compiler.  This is
	    # necessary to make sure instantiated templates are included
	    # in the archive.
	    _LT_TAGVAR(old_archive_cmds, $1)='$CC -xar -o $oldlib $oldobjs'
	    ;;
          gcx*)
	    # Green Hills C++ Compiler
	    _LT_TAGVAR(archive_cmds, $1)='$CC -shared $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-h $wl$soname -o $lib'

	    # The C++ compiler must be used to create the archive.
	    _LT_TAGVAR(old_archive_cmds, $1)='$CC $LDFLAGS -archive -o $oldlib $oldobjs'
	    ;;
          *)
	    # GNU C++ compiler with Solaris linker
	    if test "$GXX" = yes && test "$with_gnu_ld" = no; then
	      _LT_TAGVAR(no_undefined_flag, $1)=' ${wl}-z ${wl}defs'
	      if $CC --version | $GREP -v '^2\.7' > /dev/null; then
	        _LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag -nostdlib $LDFLAGS $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-h $wl$soname -o $lib'
	        _LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~echo "local: *; };" >> $lib.exp~
		  $CC -shared $pic_flag -nostdlib ${wl}-M $wl$lib.exp -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags~$RM $lib.exp'

	        # Commands to make compiler produce verbose output that lists
	        # what "hidden" libraries, object files and flags are used when
	        # linking a shared library.
	        output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | $GREP -v "^Configured with:" | $GREP "\-L"'
	      else
	        # g++ 2.7 appears to require `-G' NOT `-shared' on this
	        # platform.
	        _LT_TAGVAR(archive_cmds, $1)='$CC -G -nostdlib $LDFLAGS $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-h $wl$soname -o $lib'
	        _LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~echo "local: *; };" >> $lib.exp~
		  $CC -G -nostdlib ${wl}-M $wl$lib.exp -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags~$RM $lib.exp'

	        # Commands to make compiler produce verbose output that lists
	        # what "hidden" libraries, object files and flags are used when
	        # linking a shared library.
	        output_verbose_link_cmd='$CC -G $CFLAGS -v conftest.$objext 2>&1 | $GREP -v "^Configured with:" | $GREP "\-L"'
	      fi

	      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-R $wl$libdir'
	      case $host_os in
		solaris2.[[0-5]] | solaris2.[[0-5]].*) ;;
		*)
		  _LT_TAGVAR(whole_archive_flag_spec, $1)='${wl}-z ${wl}allextract$convenience ${wl}-z ${wl}defaultextract'
		  ;;
	      esac
	    fi
	    ;;
        esac
        ;;

    sysv4*uw2* | sysv5OpenUNIX* | sysv5UnixWare7.[[01]].[[10]]* | unixware7* | sco3.2v5.0.[[024]]*)
      _LT_TAGVAR(no_undefined_flag, $1)='${wl}-z,text'
      _LT_TAGVAR(archive_cmds_need_lc, $1)=no
      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
      runpath_var='LD_RUN_PATH'

      case $cc_basename in
        CC*)
	  _LT_TAGVAR(archive_cmds, $1)='$CC -G ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
	  _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -G ${wl}-Bexport:$export_symbols ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
	  ;;
	*)
	  _LT_TAGVAR(archive_cmds, $1)='$CC -shared ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
	  _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared ${wl}-Bexport:$export_symbols ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
	  ;;
      esac
      ;;

      sysv5* | sco3.2v5* | sco5v6*)
	# Note: We can NOT use -z defs as we might desire, because we do not
	# link with -lc, and that would cause any symbols used from libc to
	# always be unresolved, which means just about no library would
	# ever link correctly.  If we're not using GNU ld we use -z text
	# though, which does catch some bad symbols but isn't as heavy-handed
	# as -z defs.
	_LT_TAGVAR(no_undefined_flag, $1)='${wl}-z,text'
	_LT_TAGVAR(allow_undefined_flag, $1)='${wl}-z,nodefs'
	_LT_TAGVAR(archive_cmds_need_lc, $1)=no
	_LT_TAGVAR(hardcode_shlibpath_var, $1)=no
	_LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-R,$libdir'
	_LT_TAGVAR(hardcode_libdir_separator, $1)=':'
	_LT_TAGVAR(link_all_deplibs, $1)=yes
	_LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-Bexport'
	runpath_var='LD_RUN_PATH'

	case $cc_basename in
          CC*)
	    _LT_TAGVAR(archive_cmds, $1)='$CC -G ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
	    _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -G ${wl}-Bexport:$export_symbols ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
	    _LT_TAGVAR(old_archive_cmds, $1)='$CC -Tprelink_objects $oldobjs~
	      '"$_LT_TAGVAR(old_archive_cmds, $1)"
	    _LT_TAGVAR(reload_cmds, $1)='$CC -Tprelink_objects $reload_objs~
	      '"$_LT_TAGVAR(reload_cmds, $1)"
	    ;;
	  *)
	    _LT_TAGVAR(archive_cmds, $1)='$CC -shared ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
	    _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared ${wl}-Bexport:$export_symbols ${wl}-h,$soname -o $lib $libobjs $deplibs $compiler_flags'
	    ;;
	esac
      ;;

      tandem*)
        case $cc_basename in
          NCC*)
	    # NonStop-UX NCC 3.20
	    # FIXME: insert proper C++ library support
	    _LT_TAGVAR(ld_shlibs, $1)=no
	    ;;
          *)
	    # FIXME: insert proper C++ library support
	    _LT_TAGVAR(ld_shlibs, $1)=no
	    ;;
        esac
        ;;

      vxworks*)
        # FIXME: insert proper C++ library support
        _LT_TAGVAR(ld_shlibs, $1)=no
        ;;

      *)
        # FIXME: insert proper C++ library support
        _LT_TAGVAR(ld_shlibs, $1)=no
        ;;
    esac

    AC_MSG_RESULT([$_LT_TAGVAR(ld_shlibs, $1)])
    test "$_LT_TAGVAR(ld_shlibs, $1)" = no && can_build_shared=no

    _LT_TAGVAR(GCC, $1)="$GXX"
    _LT_TAGVAR(LD, $1)="$LD"

    ## CAVEAT EMPTOR:
    ## There is no encapsulation within the following macros, do not change
    ## the running order or otherwise move them around unless you know exactly
    ## what you are doing...
    _LT_SYS_HIDDEN_LIBDEPS($1)
    _LT_COMPILER_PIC($1)
    _LT_COMPILER_C_O($1)
    _LT_COMPILER_FILE_LOCKS($1)
    _LT_LINKER_SHLIBS($1)
    _LT_SYS_DYNAMIC_LINKER($1)
    _LT_LINKER_HARDCODE_LIBPATH($1)

    _LT_CONFIG($1)
  fi # test -n "$compiler"

  CC=$lt_save_CC
  CFLAGS=$lt_save_CFLAGS
  LDCXX=$LD
  LD=$lt_save_LD
  GCC=$lt_save_GCC
  with_gnu_ld=$lt_save_with_gnu_ld
  lt_cv_path_LDCXX=$lt_cv_path_LD
  lt_cv_path_LD=$lt_save_path_LD
  lt_cv_prog_gnu_ldcxx=$lt_cv_prog_gnu_ld
  lt_cv_prog_gnu_ld=$lt_save_with_gnu_ld
fi # test "$_lt_caught_CXX_error" != yes

AC_LANG_POP
])# _LT_LANG_CXX_CONFIG


# _LT_FUNC_STRIPNAME_CNF
# ----------------------
# func_stripname_cnf prefix suffix name
# strip PREFIX and SUFFIX off of NAME.
# PREFIX and SUFFIX must not contain globbing or regex special
# characters, hashes, percent signs, but SUFFIX may contain a leading
# dot (in which case that matches only a dot).
#
# This function is identical to the (non-XSI) version of func_stripname,
# except this one can be used by m4 code that may be executed by configure,
# rather than the libtool script.
m4_defun([_LT_FUNC_STRIPNAME_CNF],[dnl
AC_REQUIRE([_LT_DECL_SED])
AC_REQUIRE([_LT_PROG_ECHO_BACKSLASH])
func_stripname_cnf ()
{
  case ${2} in
  .*) func_stripname_result=`$ECHO "${3}" | $SED "s%^${1}%%; s%\\\\${2}\$%%"`;;
  *)  func_stripname_result=`$ECHO "${3}" | $SED "s%^${1}%%; s%${2}\$%%"`;;
  esac
} # func_stripname_cnf
])# _LT_FUNC_STRIPNAME_CNF

# _LT_SYS_HIDDEN_LIBDEPS([TAGNAME])
# ---------------------------------
# Figure out "hidden" library dependencies from verbose
# compiler output when linking a shared library.
# Parse the compiler output and extract the necessary
# objects, libraries and library flags.
m4_defun([_LT_SYS_HIDDEN_LIBDEPS],
[m4_require([_LT_FILEUTILS_DEFAULTS])dnl
AC_REQUIRE([_LT_FUNC_STRIPNAME_CNF])dnl
# Dependencies to place before and after the object being linked:
_LT_TAGVAR(predep_objects, $1)=
_LT_TAGVAR(postdep_objects, $1)=
_LT_TAGVAR(predeps, $1)=
_LT_TAGVAR(postdeps, $1)=
_LT_TAGVAR(compiler_lib_search_path, $1)=

dnl we can't use the lt_simple_compile_test_code here,
dnl because it contains code intended for an executable,
dnl not a library.  It's possible we should let each
dnl tag define a new lt_????_link_test_code variable,
dnl but it's only used here...
m4_if([$1], [], [cat > conftest.$ac_ext <<_LT_EOF
int a;
void foo (void) { a = 0; }
_LT_EOF
], [$1], [CXX], [cat > conftest.$ac_ext <<_LT_EOF
class Foo
{
public:
  Foo (void) { a = 0; }
private:
  int a;
};
_LT_EOF
], [$1], [F77], [cat > conftest.$ac_ext <<_LT_EOF
      subroutine foo
      implicit none
      integer*4 a
      a=0
      return
      end
_LT_EOF
], [$1], [FC], [cat > conftest.$ac_ext <<_LT_EOF
      subroutine foo
      implicit none
      integer a
      a=0
      return
      end
_LT_EOF
], [$1], [GCJ], [cat > conftest.$ac_ext <<_LT_EOF
public class foo {
  private int a;
  public void bar (void) {
    a = 0;
  }
};
_LT_EOF
], [$1], [GO], [cat > conftest.$ac_ext <<_LT_EOF
package foo
func foo() {
}
_LT_EOF
])

_lt_libdeps_save_CFLAGS=$CFLAGS
case "$CC $CFLAGS " in #(
*\ -flto*\ *) CFLAGS="$CFLAGS -fno-lto" ;;
*\ -fwhopr*\ *) CFLAGS="$CFLAGS -fno-whopr" ;;
*\ -fuse-linker-plugin*\ *) CFLAGS="$CFLAGS -fno-use-linker-plugin" ;;
esac

dnl Parse the compiler output and extract the necessary
dnl objects, libraries and library flags.
if AC_TRY_EVAL(ac_compile); then
  # Parse the compiler output and extract the necessary
  # objects, libraries and library flags.

  # Sentinel used to keep track of whether or not we are before
  # the conftest object file.
  pre_test_object_deps_done=no

  for p in `eval "$output_verbose_link_cmd"`; do
    case ${prev}${p} in

    -L* | -R* | -l*)
       # Some compilers place space between "-{L,R}" and the path.
       # Remove the space.
       if test $p = "-L" ||
          test $p = "-R"; then
	 prev=$p
	 continue
       fi

       # Expand the sysroot to ease extracting the directories later.
       if test -z "$prev"; then
         case $p in
         -L*) func_stripname_cnf '-L' '' "$p"; prev=-L; p=$func_stripname_result ;;
         -R*) func_stripname_cnf '-R' '' "$p"; prev=-R; p=$func_stripname_result ;;
         -l*) func_stripname_cnf '-l' '' "$p"; prev=-l; p=$func_stripname_result ;;
         esac
       fi
       case $p in
       =*) func_stripname_cnf '=' '' "$p"; p=$lt_sysroot$func_stripname_result ;;
       esac
       if test "$pre_test_object_deps_done" = no; then
	 case ${prev} in
	 -L | -R)
	   # Internal compiler library paths should come after those
	   # provided the user.  The postdeps already come after the
	   # user supplied libs so there is no need to process them.
	   if test -z "$_LT_TAGVAR(compiler_lib_search_path, $1)"; then
	     _LT_TAGVAR(compiler_lib_search_path, $1)="${prev}${p}"
	   else
	     _LT_TAGVAR(compiler_lib_search_path, $1)="${_LT_TAGVAR(compiler_lib_search_path, $1)} ${prev}${p}"
	   fi
	   ;;
	 # The "-l" case would never come before the object being
	 # linked, so don't bother handling this case.
	 esac
       else
	 if test -z "$_LT_TAGVAR(postdeps, $1)"; then
	   _LT_TAGVAR(postdeps, $1)="${prev}${p}"
	 else
	   _LT_TAGVAR(postdeps, $1)="${_LT_TAGVAR(postdeps, $1)} ${prev}${p}"
	 fi
       fi
       prev=
       ;;

    *.lto.$objext) ;; # Ignore GCC LTO objects
    *.$objext)
       # This assumes that the test object file only shows up
       # once in the compiler output.
       if test "$p" = "conftest.$objext"; then
	 pre_test_object_deps_done=yes
	 continue
       fi

       if test "$pre_test_object_deps_done" = no; then
	 if test -z "$_LT_TAGVAR(predep_objects, $1)"; then
	   _LT_TAGVAR(predep_objects, $1)="$p"
	 else
	   _LT_TAGVAR(predep_objects, $1)="$_LT_TAGVAR(predep_objects, $1) $p"
	 fi
       else
	 if test -z "$_LT_TAGVAR(postdep_objects, $1)"; then
	   _LT_TAGVAR(postdep_objects, $1)="$p"
	 else
	   _LT_TAGVAR(postdep_objects, $1)="$_LT_TAGVAR(postdep_objects, $1) $p"
	 fi
       fi
       ;;

    *) ;; # Ignore the rest.

    esac
  done

  # Clean up.
  rm -f a.out a.exe
else
  echo "libtool.m4: error: problem compiling $1 test program"
fi

$RM -f confest.$objext
CFLAGS=$_lt_libdeps_save_CFLAGS

# PORTME: override above test on systems where it is broken
m4_if([$1], [CXX],
[case $host_os in
interix[[3-9]]*)
  # Interix 3.5 installs completely hosed .la files for C++, so rather than
  # hack all around it, let's just trust "g++" to DTRT.
  _LT_TAGVAR(predep_objects,$1)=
  _LT_TAGVAR(postdep_objects,$1)=
  _LT_TAGVAR(postdeps,$1)=
  ;;

linux*)
  case `$CC -V 2>&1 | sed 5q` in
  *Sun\ C*)
    # Sun C++ 5.9

    # The more standards-conforming stlport4 library is
    # incompatible with the Cstd library. Avoid specifying
    # it if it's in CXXFLAGS. Ignore libCrun as
    # -library=stlport4 depends on it.
    case " $CXX $CXXFLAGS " in
    *" -library=stlport4 "*)
      solaris_use_stlport4=yes
      ;;
    esac

    if test "$solaris_use_stlport4" != yes; then
      _LT_TAGVAR(postdeps,$1)='-library=Cstd -library=Crun'
    fi
    ;;
  esac
  ;;

solaris*)
  case $cc_basename in
  CC* | sunCC*)
    # The more standards-conforming stlport4 library is
    # incompatible with the Cstd library. Avoid specifying
    # it if it's in CXXFLAGS. Ignore libCrun as
    # -library=stlport4 depends on it.
    case " $CXX $CXXFLAGS " in
    *" -library=stlport4 "*)
      solaris_use_stlport4=yes
      ;;
    esac

    # Adding this requires a known-good setup of shared libraries for
    # Sun compiler versions before 5.6, else PIC objects from an old
    # archive will be linked into the output, leading to subtle bugs.
    if test "$solaris_use_stlport4" != yes; then
      _LT_TAGVAR(postdeps,$1)='-library=Cstd -library=Crun'
    fi
    ;;
  esac
  ;;
esac
])

case " $_LT_TAGVAR(postdeps, $1) " in
*" -lc "*) _LT_TAGVAR(archive_cmds_need_lc, $1)=no ;;
esac
 _LT_TAGVAR(compiler_lib_search_dirs, $1)=
if test -n "${_LT_TAGVAR(compiler_lib_search_path, $1)}"; then
 _LT_TAGVAR(compiler_lib_search_dirs, $1)=`echo " ${_LT_TAGVAR(compiler_lib_search_path, $1)}" | ${SED} -e 's! -L! !g' -e 's!^ !!'`
fi
_LT_TAGDECL([], [compiler_lib_search_dirs], [1],
    [The directories searched by this compiler when creating a shared library])
_LT_TAGDECL([], [predep_objects], [1],
    [Dependencies to place before and after the objects being linked to
    create a shared library])
_LT_TAGDECL([], [postdep_objects], [1])
_LT_TAGDECL([], [predeps], [1])
_LT_TAGDECL([], [postdeps], [1])
_LT_TAGDECL([], [compiler_lib_search_path], [1],
    [The library search path used internally by the compiler when linking
    a shared library])
])# _LT_SYS_HIDDEN_LIBDEPS


# _LT_LANG_F77_CONFIG([TAG])
# --------------------------
# Ensure that the configuration variables for a Fortran 77 compiler are
# suitably defined.  These variables are subsequently used by _LT_CONFIG
# to write the compiler configuration to `libtool'.
m4_defun([_LT_LANG_F77_CONFIG],
[AC_LANG_PUSH(Fortran 77)
if test -z "$F77" || test "X$F77" = "Xno"; then
  _lt_disable_F77=yes
fi

_LT_TAGVAR(archive_cmds_need_lc, $1)=no
_LT_TAGVAR(allow_undefined_flag, $1)=
_LT_TAGVAR(always_export_symbols, $1)=no
_LT_TAGVAR(archive_expsym_cmds, $1)=
_LT_TAGVAR(export_dynamic_flag_spec, $1)=
_LT_TAGVAR(hardcode_direct, $1)=no
_LT_TAGVAR(hardcode_direct_absolute, $1)=no
_LT_TAGVAR(hardcode_libdir_flag_spec, $1)=
_LT_TAGVAR(hardcode_libdir_separator, $1)=
_LT_TAGVAR(hardcode_minus_L, $1)=no
_LT_TAGVAR(hardcode_automatic, $1)=no
_LT_TAGVAR(inherit_rpath, $1)=no
_LT_TAGVAR(module_cmds, $1)=
_LT_TAGVAR(module_expsym_cmds, $1)=
_LT_TAGVAR(link_all_deplibs, $1)=unknown
_LT_TAGVAR(old_archive_cmds, $1)=$old_archive_cmds
_LT_TAGVAR(reload_flag, $1)=$reload_flag
_LT_TAGVAR(reload_cmds, $1)=$reload_cmds
_LT_TAGVAR(no_undefined_flag, $1)=
_LT_TAGVAR(whole_archive_flag_spec, $1)=
_LT_TAGVAR(enable_shared_with_static_runtimes, $1)=no

# Source file extension for f77 test sources.
ac_ext=f

# Object file extension for compiled f77 test sources.
objext=o
_LT_TAGVAR(objext, $1)=$objext

# No sense in running all these tests if we already determined that
# the F77 compiler isn't working.  Some variables (like enable_shared)
# are currently assumed to apply to all compilers on this platform,
# and will be corrupted by setting them based on a non-working compiler.
if test "$_lt_disable_F77" != yes; then
  # Code to be used in simple compile tests
  lt_simple_compile_test_code="\
      subroutine t
      return
      end
"

  # Code to be used in simple link tests
  lt_simple_link_test_code="\
      program t
      end
"

  # ltmain only uses $CC for tagged configurations so make sure $CC is set.
  _LT_TAG_COMPILER

  # save warnings/boilerplate of simple test code
  _LT_COMPILER_BOILERPLATE
  _LT_LINKER_BOILERPLATE

  # Allow CC to be a program name with arguments.
  lt_save_CC="$CC"
  lt_save_GCC=$GCC
  lt_save_CFLAGS=$CFLAGS
  CC=${F77-"f77"}
  CFLAGS=$FFLAGS
  compiler=$CC
  _LT_TAGVAR(compiler, $1)=$CC
  _LT_CC_BASENAME([$compiler])
  GCC=$G77
  if test -n "$compiler"; then
    AC_MSG_CHECKING([if libtool supports shared libraries])
    AC_MSG_RESULT([$can_build_shared])

    AC_MSG_CHECKING([whether to build shared libraries])
    test "$can_build_shared" = "no" && enable_shared=no

    # On AIX, shared libraries and static libraries use the same namespace, and
    # are all built from PIC.
    case $host_os in
      aix3*)
        test "$enable_shared" = yes && enable_static=no
        if test -n "$RANLIB"; then
          archive_cmds="$archive_cmds~\$RANLIB \$lib"
          postinstall_cmds='$RANLIB $lib'
        fi
        ;;
      aix[[4-9]]*)
	if test "$host_cpu" != ia64 && test "$aix_use_runtimelinking" = no ; then
	  test "$enable_shared" = yes && enable_static=no
	fi
        ;;
    esac
    AC_MSG_RESULT([$enable_shared])

    AC_MSG_CHECKING([whether to build static libraries])
    # Make sure either enable_shared or enable_static is yes.
    test "$enable_shared" = yes || enable_static=yes
    AC_MSG_RESULT([$enable_static])

    _LT_TAGVAR(GCC, $1)="$G77"
    _LT_TAGVAR(LD, $1)="$LD"

    ## CAVEAT EMPTOR:
    ## There is no encapsulation within the following macros, do not change
    ## the running order or otherwise move them around unless you know exactly
    ## what you are doing...
    _LT_COMPILER_PIC($1)
    _LT_COMPILER_C_O($1)
    _LT_COMPILER_FILE_LOCKS($1)
    _LT_LINKER_SHLIBS($1)
    _LT_SYS_DYNAMIC_LINKER($1)
    _LT_LINKER_HARDCODE_LIBPATH($1)

    _LT_CONFIG($1)
  fi # test -n "$compiler"

  GCC=$lt_save_GCC
  CC="$lt_save_CC"
  CFLAGS="$lt_save_CFLAGS"
fi # test "$_lt_disable_F77" != yes

AC_LANG_POP
])# _LT_LANG_F77_CONFIG


# _LT_LANG_FC_CONFIG([TAG])
# -------------------------
# Ensure that the configuration variables for a Fortran compiler are
# suitably defined.  These variables are subsequently used by _LT_CONFIG
# to write the compiler configuration to `libtool'.
m4_defun([_LT_LANG_FC_CONFIG],
[AC_LANG_PUSH(Fortran)

if test -z "$FC" || test "X$FC" = "Xno"; then
  _lt_disable_FC=yes
fi

_LT_TAGVAR(archive_cmds_need_lc, $1)=no
_LT_TAGVAR(allow_undefined_flag, $1)=
_LT_TAGVAR(always_export_symbols, $1)=no
_LT_TAGVAR(archive_expsym_cmds, $1)=
_LT_TAGVAR(export_dynamic_flag_spec, $1)=
_LT_TAGVAR(hardcode_direct, $1)=no
_LT_TAGVAR(hardcode_direct_absolute, $1)=no
_LT_TAGVAR(hardcode_libdir_flag_spec, $1)=
_LT_TAGVAR(hardcode_libdir_separator, $1)=
_LT_TAGVAR(hardcode_minus_L, $1)=no
_LT_TAGVAR(hardcode_automatic, $1)=no
_LT_TAGVAR(inherit_rpath, $1)=no
_LT_TAGVAR(module_cmds, $1)=
_LT_TAGVAR(module_expsym_cmds, $1)=
_LT_TAGVAR(link_all_deplibs, $1)=unknown
_LT_TAGVAR(old_archive_cmds, $1)=$old_archive_cmds
_LT_TAGVAR(reload_flag, $1)=$reload_flag
_LT_TAGVAR(reload_cmds, $1)=$reload_cmds
_LT_TAGVAR(no_undefined_flag, $1)=
_LT_TAGVAR(whole_archive_flag_spec, $1)=
_LT_TAGVAR(enable_shared_with_static_runtimes, $1)=no

# Source file extension for fc test sources.
ac_ext=${ac_fc_srcext-f}

# Object file extension for compiled fc test sources.
objext=o
_LT_TAGVAR(objext, $1)=$objext

# No sense in running all these tests if we already determined that
# the FC compiler isn't working.  Some variables (like enable_shared)
# are currently assumed to apply to all compilers on this platform,
# and will be corrupted by setting them based on a non-working compiler.
if test "$_lt_disable_FC" != yes; then
  # Code to be used in simple compile tests
  lt_simple_compile_test_code="\
      subroutine t
      return
      end
"

  # Code to be used in simple link tests
  lt_simple_link_test_code="\
      program t
      end
"

  # ltmain only uses $CC for tagged configurations so make sure $CC is set.
  _LT_TAG_COMPILER

  # save warnings/boilerplate of simple test code
  _LT_COMPILER_BOILERPLATE
  _LT_LINKER_BOILERPLATE

  # Allow CC to be a program name with arguments.
  lt_save_CC="$CC"
  lt_save_GCC=$GCC
  lt_save_CFLAGS=$CFLAGS
  CC=${FC-"f95"}
  CFLAGS=$FCFLAGS
  compiler=$CC
  GCC=$ac_cv_fc_compiler_gnu

  _LT_TAGVAR(compiler, $1)=$CC
  _LT_CC_BASENAME([$compiler])

  if test -n "$compiler"; then
    AC_MSG_CHECKING([if libtool supports shared libraries])
    AC_MSG_RESULT([$can_build_shared])

    AC_MSG_CHECKING([whether to build shared libraries])
    test "$can_build_shared" = "no" && enable_shared=no

    # On AIX, shared libraries and static libraries use the same namespace, and
    # are all built from PIC.
    case $host_os in
      aix3*)
        test "$enable_shared" = yes && enable_static=no
        if test -n "$RANLIB"; then
          archive_cmds="$archive_cmds~\$RANLIB \$lib"
          postinstall_cmds='$RANLIB $lib'
        fi
        ;;
      aix[[4-9]]*)
	if test "$host_cpu" != ia64 && test "$aix_use_runtimelinking" = no ; then
	  test "$enable_shared" = yes && enable_static=no
	fi
        ;;
    esac
    AC_MSG_RESULT([$enable_shared])

    AC_MSG_CHECKING([whether to build static libraries])
    # Make sure either enable_shared or enable_static is yes.
    test "$enable_shared" = yes || enable_static=yes
    AC_MSG_RESULT([$enable_static])

    _LT_TAGVAR(GCC, $1)="$ac_cv_fc_compiler_gnu"
    _LT_TAGVAR(LD, $1)="$LD"

    ## CAVEAT EMPTOR:
    ## There is no encapsulation within the following macros, do not change
    ## the running order or otherwise move them around unless you know exactly
    ## what you are doing...
    _LT_SYS_HIDDEN_LIBDEPS($1)
    _LT_COMPILER_PIC($1)
    _LT_COMPILER_C_O($1)
    _LT_COMPILER_FILE_LOCKS($1)
    _LT_LINKER_SHLIBS($1)
    _LT_SYS_DYNAMIC_LINKER($1)
    _LT_LINKER_HARDCODE_LIBPATH($1)

    _LT_CONFIG($1)
  fi # test -n "$compiler"

  GCC=$lt_save_GCC
  CC=$lt_save_CC
  CFLAGS=$lt_save_CFLAGS
fi # test "$_lt_disable_FC" != yes

AC_LANG_POP
])# _LT_LANG_FC_CONFIG


# _LT_LANG_GCJ_CONFIG([TAG])
# --------------------------
# Ensure that the configuration variables for the GNU Java Compiler compiler
# are suitably defined.  These variables are subsequently used by _LT_CONFIG
# to write the compiler configuration to `libtool'.
m4_defun([_LT_LANG_GCJ_CONFIG],
[AC_REQUIRE([LT_PROG_GCJ])dnl
AC_LANG_SAVE

# Source file extension for Java test sources.
ac_ext=java

# Object file extension for compiled Java test sources.
objext=o
_LT_TAGVAR(objext, $1)=$objext

# Code to be used in simple compile tests
lt_simple_compile_test_code="class foo {}"

# Code to be used in simple link tests
lt_simple_link_test_code='public class conftest { public static void main(String[[]] argv) {}; }'

# ltmain only uses $CC for tagged configurations so make sure $CC is set.
_LT_TAG_COMPILER

# save warnings/boilerplate of simple test code
_LT_COMPILER_BOILERPLATE
_LT_LINKER_BOILERPLATE

# Allow CC to be a program name with arguments.
lt_save_CC=$CC
lt_save_CFLAGS=$CFLAGS
lt_save_GCC=$GCC
GCC=yes
CC=${GCJ-"gcj"}
CFLAGS=$GCJFLAGS
compiler=$CC
_LT_TAGVAR(compiler, $1)=$CC
_LT_TAGVAR(LD, $1)="$LD"
_LT_CC_BASENAME([$compiler])

# GCJ did not exist at the time GCC didn't implicitly link libc in.
_LT_TAGVAR(archive_cmds_need_lc, $1)=no

_LT_TAGVAR(old_archive_cmds, $1)=$old_archive_cmds
_LT_TAGVAR(reload_flag, $1)=$reload_flag
_LT_TAGVAR(reload_cmds, $1)=$reload_cmds

## CAVEAT EMPTOR:
## There is no encapsulation within the following macros, do not change
## the running order or otherwise move them around unless you know exactly
## what you are doing...
if test -n "$compiler"; then
  _LT_COMPILER_NO_RTTI($1)
  _LT_COMPILER_PIC($1)
  _LT_COMPILER_C_O($1)
  _LT_COMPILER_FILE_LOCKS($1)
  _LT_LINKER_SHLIBS($1)
  _LT_LINKER_HARDCODE_LIBPATH($1)

  _LT_CONFIG($1)
fi

AC_LANG_RESTORE

GCC=$lt_save_GCC
CC=$lt_save_CC
CFLAGS=$lt_save_CFLAGS
])# _LT_LANG_GCJ_CONFIG


# _LT_LANG_GO_CONFIG([TAG])
# --------------------------
# Ensure that the configuration variables for the GNU Go compiler
# are suitably defined.  These variables are subsequently used by _LT_CONFIG
# to write the compiler configuration to `libtool'.
m4_defun([_LT_LANG_GO_CONFIG],
[AC_REQUIRE([LT_PROG_GO])dnl
AC_LANG_SAVE

# Source file extension for Go test sources.
ac_ext=go

# Object file extension for compiled Go test sources.
objext=o
_LT_TAGVAR(objext, $1)=$objext

# Code to be used in simple compile tests
lt_simple_compile_test_code="package main; func main() { }"

# Code to be used in simple link tests
lt_simple_link_test_code='package main; func main() { }'

# ltmain only uses $CC for tagged configurations so make sure $CC is set.
_LT_TAG_COMPILER

# save warnings/boilerplate of simple test code
_LT_COMPILER_BOILERPLATE
_LT_LINKER_BOILERPLATE

# Allow CC to be a program name with arguments.
lt_save_CC=$CC
lt_save_CFLAGS=$CFLAGS
lt_save_GCC=$GCC
GCC=yes
CC=${GOC-"gccgo"}
CFLAGS=$GOFLAGS
compiler=$CC
_LT_TAGVAR(compiler, $1)=$CC
_LT_TAGVAR(LD, $1)="$LD"
_LT_CC_BASENAME([$compiler])

# Go did not exist at the time GCC didn't implicitly link libc in.
_LT_TAGVAR(archive_cmds_need_lc, $1)=no

_LT_TAGVAR(old_archive_cmds, $1)=$old_archive_cmds
_LT_TAGVAR(reload_flag, $1)=$reload_flag
_LT_TAGVAR(reload_cmds, $1)=$reload_cmds

## CAVEAT EMPTOR:
## There is no encapsulation within the following macros, do not change
## the running order or otherwise move them around unless you know exactly
## what you are doing...
if test -n "$compiler"; then
  _LT_COMPILER_NO_RTTI($1)
  _LT_COMPILER_PIC($1)
  _LT_COMPILER_C_O($1)
  _LT_COMPILER_FILE_LOCKS($1)
  _LT_LINKER_SHLIBS($1)
  _LT_LINKER_HARDCODE_LIBPATH($1)

  _LT_CONFIG($1)
fi

AC_LANG_RESTORE

GCC=$lt_save_GCC
CC=$lt_save_CC
CFLAGS=$lt_save_CFLAGS
])# _LT_LANG_GO_CONFIG


# _LT_LANG_RC_CONFIG([TAG])
# -------------------------
# Ensure that the configuration variables for the Windows resource compiler
# are suitably defined.  These variables are subsequently used by _LT_CONFIG
# to write the compiler configuration to `libtool'.
m4_defun([_LT_LANG_RC_CONFIG],
[AC_REQUIRE([LT_PROG_RC])dnl
AC_LANG_SAVE

# Source file extension for RC test sources.
ac_ext=rc

# Object file extension for compiled RC test sources.
objext=o
_LT_TAGVAR(objext, $1)=$objext

# Code to be used in simple compile tests
lt_simple_compile_test_code='sample MENU { MENUITEM "&Soup", 100, CHECKED }'

# Code to be used in simple link tests
lt_simple_link_test_code="$lt_simple_compile_test_code"

# ltmain only uses $CC for tagged configurations so make sure $CC is set.
_LT_TAG_COMPILER

# save warnings/boilerplate of simple test code
_LT_COMPILER_BOILERPLATE
_LT_LINKER_BOILERPLATE

# Allow CC to be a program name with arguments.
lt_save_CC="$CC"
lt_save_CFLAGS=$CFLAGS
lt_save_GCC=$GCC
GCC=
CC=${RC-"windres"}
CFLAGS=
compiler=$CC
_LT_TAGVAR(compiler, $1)=$CC
_LT_CC_BASENAME([$compiler])
_LT_TAGVAR(lt_cv_prog_compiler_c_o, $1)=yes

if test -n "$compiler"; then
  :
  _LT_CONFIG($1)
fi

GCC=$lt_save_GCC
AC_LANG_RESTORE
CC=$lt_save_CC
CFLAGS=$lt_save_CFLAGS
])# _LT_LANG_RC_CONFIG


# LT_PROG_GCJ
# -----------
AC_DEFUN([LT_PROG_GCJ],
[m4_ifdef([AC_PROG_GCJ], [AC_PROG_GCJ],
  [m4_ifdef([A][M_PROG_GCJ], [A][M_PROG_GCJ],
    [AC_CHECK_TOOL(GCJ, gcj,)
      test "x${GCJFLAGS+set}" = xset || GCJFLAGS="-g -O2"
      AC_SUBST(GCJFLAGS)])])[]dnl
])

# Old name:
AU_ALIAS([LT_AC_PROG_GCJ], [LT_PROG_GCJ])
dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([LT_AC_PROG_GCJ], [])


# LT_PROG_GO
# ----------
AC_DEFUN([LT_PROG_GO],
[AC_CHECK_TOOL(GOC, gccgo,)
])


# LT_PROG_RC
# ----------
AC_DEFUN([LT_PROG_RC],
[AC_CHECK_TOOL(RC, windres,)
])

# Old name:
AU_ALIAS([LT_AC_PROG_RC], [LT_PROG_RC])
dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([LT_AC_PROG_RC], [])


# _LT_DECL_EGREP
# --------------
# If we don't have a new enough Autoconf to choose the best grep
# available, choose the one first in the user's PATH.
m4_defun([_LT_DECL_EGREP],
[AC_REQUIRE([AC_PROG_EGREP])dnl
AC_REQUIRE([AC_PROG_FGREP])dnl
test -z "$GREP" && GREP=grep
_LT_DECL([], [GREP], [1], [A grep program that handles long lines])
_LT_DECL([], [EGREP], [1], [An ERE matcher])
_LT_DECL([], [FGREP], [1], [A literal string matcher])
dnl Non-bleeding-edge autoconf doesn't subst GREP, so do it here too
AC_SUBST([GREP])
])


# _LT_DECL_OBJDUMP
# --------------
# If we don't have a new enough Autoconf to choose the best objdump
# available, choose the one first in the user's PATH.
m4_defun([_LT_DECL_OBJDUMP],
[AC_CHECK_TOOL(OBJDUMP, objdump, false)
test -z "$OBJDUMP" && OBJDUMP=objdump
_LT_DECL([], [OBJDUMP], [1], [An object symbol dumper])
AC_SUBST([OBJDUMP])
])

# _LT_DECL_DLLTOOL
# ----------------
# Ensure DLLTOOL variable is set.
m4_defun([_LT_DECL_DLLTOOL],
[AC_CHECK_TOOL(DLLTOOL, dlltool, false)
test -z "$DLLTOOL" && DLLTOOL=dlltool
_LT_DECL([], [DLLTOOL], [1], [DLL creation program])
AC_SUBST([DLLTOOL])
])

# _LT_DECL_SED
# ------------
# Check for a fully-functional sed program, that truncates
# as few characters as possible.  Prefer GNU sed if found.
m4_defun([_LT_DECL_SED],
[AC_PROG_SED
test -z "$SED" && SED=sed
Xsed="$SED -e 1s/^X//"
_LT_DECL([], [SED], [1], [A sed program that does not truncate output])
_LT_DECL([], [Xsed], ["\$SED -e 1s/^X//"],
    [Sed that helps us avoid accidentally triggering echo(1) options like -n])
])# _LT_DECL_SED

m4_ifndef([AC_PROG_SED], [
############################################################
# NOTE: This macro has been submitted for inclusion into   #
#  GNU Autoconf as AC_PROG_SED.  When it is available in   #
#  a released version of Autoconf we should remove this    #
#  macro and use it instead.                               #
############################################################

m4_defun([AC_PROG_SED],
[AC_MSG_CHECKING([for a sed that does not truncate output])
AC_CACHE_VAL(lt_cv_path_SED,
[# Loop through the user's path and test for sed and gsed.
# Then use that list of sed's as ones to test for truncation.
as_save_IFS=$IFS; IFS=$PATH_SEPARATOR
for as_dir in $PATH
do
  IFS=$as_save_IFS
  test -z "$as_dir" && as_dir=.
  for lt_ac_prog in sed gsed; do
    for ac_exec_ext in '' $ac_executable_extensions; do
      if $as_executable_p "$as_dir/$lt_ac_prog$ac_exec_ext"; then
        lt_ac_sed_list="$lt_ac_sed_list $as_dir/$lt_ac_prog$ac_exec_ext"
      fi
    done
  done
done
IFS=$as_save_IFS
lt_ac_max=0
lt_ac_count=0
# Add /usr/xpg4/bin/sed as it is typically found on Solaris
# along with /bin/sed that truncates output.
for lt_ac_sed in $lt_ac_sed_list /usr/xpg4/bin/sed; do
  test ! -f $lt_ac_sed && continue
  cat /dev/null > conftest.in
  lt_ac_count=0
  echo $ECHO_N "0123456789$ECHO_C" >conftest.in
  # Check for GNU sed and select it if it is found.
  if "$lt_ac_sed" --version 2>&1 < /dev/null | grep 'GNU' > /dev/null; then
    lt_cv_path_SED=$lt_ac_sed
    break
  fi
  while true; do
    cat conftest.in conftest.in >conftest.tmp
    mv conftest.tmp conftest.in
    cp conftest.in conftest.nl
    echo >>conftest.nl
    $lt_ac_sed -e 's/a$//' < conftest.nl >conftest.out || break
    cmp -s conftest.out conftest.nl || break
    # 10000 chars as input seems more than enough
    test $lt_ac_count -gt 10 && break
    lt_ac_count=`expr $lt_ac_count + 1`
    if test $lt_ac_count -gt $lt_ac_max; then
      lt_ac_max=$lt_ac_count
      lt_cv_path_SED=$lt_ac_sed
    fi
  done
done
])
SED=$lt_cv_path_SED
AC_SUBST([SED])
AC_MSG_RESULT([$SED])
])#AC_PROG_SED
])#m4_ifndef

# Old name:
AU_ALIAS([LT_AC_PROG_SED], [AC_PROG_SED])
dnl aclocal-1.4 backwards compatibility:
dnl AC_DEFUN([LT_AC_PROG_SED], [])


# _LT_CHECK_SHELL_FEATURES
# ------------------------
# Find out whether the shell is Bourne or XSI compatible,
# or has some other useful features.
m4_defun([_LT_CHECK_SHELL_FEATURES],
[AC_MSG_CHECKING([whether the shell understands some XSI constructs])
# Try some XSI features
xsi_shell=no
( _lt_dummy="a/b/c"
  test "${_lt_dummy##*/},${_lt_dummy%/*},${_lt_dummy#??}"${_lt_dummy%"$_lt_dummy"}, \
      = c,a/b,b/c, \
    && eval 'test $(( 1 + 1 )) -eq 2 \
    && test "${#_lt_dummy}" -eq 5' ) >/dev/null 2>&1 \
  && xsi_shell=yes
AC_MSG_RESULT([$xsi_shell])
_LT_CONFIG_LIBTOOL_INIT([xsi_shell='$xsi_shell'])

AC_MSG_CHECKING([whether the shell understands "+="])
lt_shell_append=no
( foo=bar; set foo baz; eval "$[1]+=\$[2]" && test "$foo" = barbaz ) \
    >/dev/null 2>&1 \
  && lt_shell_append=yes
AC_MSG_RESULT([$lt_shell_append])
_LT_CONFIG_LIBTOOL_INIT([lt_shell_append='$lt_shell_append'])

if ( (MAIL=60; unset MAIL) || exit) >/dev/null 2>&1; then
  lt_unset=unset
else
  lt_unset=false
fi
_LT_DECL([], [lt_unset], [0], [whether the shell understands "unset"])dnl

# test EBCDIC or ASCII
case `echo X|tr X '\101'` in
 A) # ASCII based system
    # \n is not interpreted correctly by Solaris 8 /usr/ucb/tr
  lt_SP2NL='tr \040 \012'
  lt_NL2SP='tr \015\012 \040\040'
  ;;
 *) # EBCDIC based system
  lt_SP2NL='tr \100 \n'
  lt_NL2SP='tr \r\n \100\100'
  ;;
esac
_LT_DECL([SP2NL], [lt_SP2NL], [1], [turn spaces into newlines])dnl
_LT_DECL([NL2SP], [lt_NL2SP], [1], [turn newlines into spaces])dnl
])# _LT_CHECK_SHELL_FEATURES


# _LT_PROG_FUNCTION_REPLACE (FUNCNAME, REPLACEMENT-BODY)
# ------------------------------------------------------
# In `$cfgfile', look for function FUNCNAME delimited by `^FUNCNAME ()$' and
# '^} FUNCNAME ', and replace its body with REPLACEMENT-BODY.
m4_defun([_LT_PROG_FUNCTION_REPLACE],
[dnl {
sed -e '/^$1 ()$/,/^} # $1 /c\
$1 ()\
{\
m4_bpatsubsts([$2], [$], [\\], [^\([	 ]\)], [\\\1])
} # Extended-shell $1 implementation' "$cfgfile" > $cfgfile.tmp \
  && mv -f "$cfgfile.tmp" "$cfgfile" \
    || (rm -f "$cfgfile" && cp "$cfgfile.tmp" "$cfgfile" && rm -f "$cfgfile.tmp")
test 0 -eq $? || _lt_function_replace_fail=:
])


# _LT_PROG_REPLACE_SHELLFNS
# -------------------------
# Replace existing portable implementations of several shell functions with
# equivalent extended shell implementations where those features are available..
m4_defun([_LT_PROG_REPLACE_SHELLFNS],
[if test x"$xsi_shell" = xyes; then
  _LT_PROG_FUNCTION_REPLACE([func_dirname], [dnl
    case ${1} in
      */*) func_dirname_result="${1%/*}${2}" ;;
      *  ) func_dirname_result="${3}" ;;
    esac])

  _LT_PROG_FUNCTION_REPLACE([func_basename], [dnl
    func_basename_result="${1##*/}"])

  _LT_PROG_FUNCTION_REPLACE([func_dirname_and_basename], [dnl
    case ${1} in
      */*) func_dirname_result="${1%/*}${2}" ;;
      *  ) func_dirname_result="${3}" ;;
    esac
    func_basename_result="${1##*/}"])

  _LT_PROG_FUNCTION_REPLACE([func_stripname], [dnl
    # pdksh 5.2.14 does not do ${X%$Y} correctly if both X and Y are
    # positional parameters, so assign one to ordinary parameter first.
    func_stripname_result=${3}
    func_stripname_result=${func_stripname_result#"${1}"}
    func_stripname_result=${func_stripname_result%"${2}"}])

  _LT_PROG_FUNCTION_REPLACE([func_split_long_opt], [dnl
    func_split_long_opt_name=${1%%=*}
    func_split_long_opt_arg=${1#*=}])

  _LT_PROG_FUNCTION_REPLACE([func_split_short_opt], [dnl
    func_split_short_opt_arg=${1#??}
    func_split_short_opt_name=${1%"$func_split_short_opt_arg"}])

  _LT_PROG_FUNCTION_REPLACE([func_lo2o], [dnl
    case ${1} in
      *.lo) func_lo2o_result=${1%.lo}.${objext} ;;
      *)    func_lo2o_result=${1} ;;
    esac])

  _LT_PROG_FUNCTION_REPLACE([func_xform], [    func_xform_result=${1%.*}.lo])

  _LT_PROG_FUNCTION_REPLACE([func_arith], [    func_arith_result=$(( $[*] ))])

  _LT_PROG_FUNCTION_REPLACE([func_len], [    func_len_result=${#1}])
fi

if test x"$lt_shell_append" = xyes; then
  _LT_PROG_FUNCTION_REPLACE([func_append], [    eval "${1}+=\\${2}"])

  _LT_PROG_FUNCTION_REPLACE([func_append_quoted], [dnl
    func_quote_for_eval "${2}"
dnl m4 expansion turns \\\\ into \\, and then the shell eval turns that into \
    eval "${1}+=\\\\ \\$func_quote_for_eval_result"])

  # Save a `func_append' function call where possible by direct use of '+='
  sed -e 's%func_append \([[a-zA-Z_]]\{1,\}\) "%\1+="%g' $cfgfile > $cfgfile.tmp \
    && mv -f "$cfgfile.tmp" "$cfgfile" \
      || (rm -f "$cfgfile" && cp "$cfgfile.tmp" "$cfgfile" && rm -f "$cfgfile.tmp")
  test 0 -eq $? || _lt_function_replace_fail=:
else
  # Save a `func_append' function call even when '+=' is not available
  sed -e 's%func_append \([[a-zA-Z_]]\{1,\}\) "%\1="$\1%g' $cfgfile > $cfgfile.tmp \
    && mv -f "$cfgfile.tmp" "$cfgfile" \
      || (rm -f "$cfgfile" && cp "$cfgfile.tmp" "$cfgfile" && rm -f "$cfgfile.tmp")
  test 0 -eq $? || _lt_function_replace_fail=:
fi

if test x"$_lt_function_replace_fail" = x":"; then
  AC_MSG_WARN([Unable to substitute extended shell functions in $ofile])
fi
])

# _LT_PATH_CONVERSION_FUNCTIONS
# -----------------------------
# Determine which file name conversion functions should be used by
# func_to_host_file (and, implicitly, by func_to_host_path).  These are needed
# for certain cross-compile configurations and native mingw.
m4_defun([_LT_PATH_CONVERSION_FUNCTIONS],
[AC_REQUIRE([AC_CANONICAL_HOST])dnl
AC_REQUIRE([AC_CANONICAL_BUILD])dnl
AC_MSG_CHECKING([how to convert $build file names to $host format])
AC_CACHE_VAL(lt_cv_to_host_file_cmd,
[case $host in
  *-*-mingw* )
    case $build in
      *-*-mingw* ) # actually msys
        lt_cv_to_host_file_cmd=func_convert_file_msys_to_w32
        ;;
      *-*-cygwin* )
        lt_cv_to_host_file_cmd=func_convert_file_cygwin_to_w32
        ;;
      * ) # otherwise, assume *nix
        lt_cv_to_host_file_cmd=func_convert_file_nix_to_w32
        ;;
    esac
    ;;
  *-*-cygwin* )
    case $build in
      *-*-mingw* ) # actually msys
        lt_cv_to_host_file_cmd=func_convert_file_msys_to_cygwin
        ;;
      *-*-cygwin* )
        lt_cv_to_host_file_cmd=func_convert_file_noop
        ;;
      * ) # otherwise, assume *nix
        lt_cv_to_host_file_cmd=func_convert_file_nix_to_cygwin
        ;;
    esac
    ;;
  * ) # unhandled hosts (and "normal" native builds)
    lt_cv_to_host_file_cmd=func_convert_file_noop
    ;;
esac
])
to_host_file_cmd=$lt_cv_to_host_file_cmd
AC_MSG_RESULT([$lt_cv_to_host_file_cmd])
_LT_DECL([to_host_file_cmd], [lt_cv_to_host_file_cmd],
         [0], [convert $build file names to $host format])dnl

AC_MSG_CHECKING([how to convert $build file names to toolchain format])
AC_CACHE_VAL(lt_cv_to_tool_file_cmd,
[#assume ordinary cross tools, or native build.
lt_cv_to_tool_file_cmd=func_convert_file_noop
case $host in
  *-*-mingw* )
    case $build in
      *-*-mingw* ) # actually msys
        lt_cv_to_tool_file_cmd=func_convert_file_msys_to_w32
        ;;
    esac
    ;;
esac
])
to_tool_file_cmd=$lt_cv_to_tool_file_cmd
AC_MSG_RESULT([$lt_cv_to_tool_file_cmd])
_LT_DECL([to_tool_file_cmd], [lt_cv_to_tool_file_cmd],
         [0], [convert $build files to toolchain format])dnl
])# _LT_PATH_CONVERSION_FUNCTIONS
