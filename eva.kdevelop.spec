# This spec file was generated by KDevelop 
# Please report any problem to KDevelop Team <kdevelop-devel@kdevelop.org> 
# Thanks to Matthias Saou for his explanations on http://freshrpms.net/docs/fight.html

Name: eva.tdevelop
Version: 0.3.0
Release: 
Vendor: 
Copyright: 
Summary: 
Group: 
Packager: 
BuildRoot:  %{_tmppath}/%{name}-root 
Source: 

%description


%prep
%setup
CFLAGS="$RPM_OPT_FLAGS" CXXFLAGS="$RPM_OPT_FLAGS" ./configure \ 
--target=
--disable-debug --enable-debug=no 

%build
%configure
make

%install
rm -rf %{buildroot}
%makeinstall

%clean
rm -rf %{buildroot}

%post -p /sbin/ldconfig
%postun -p /sbin/ldconfig
%files
%defattr(-, root, root)
%doc AUTHORS COPYING ChangeLog NEWS README TODO
%{_bindir}/*
%{_libdir}/*.so.*
%{_datadir}/%{name}
%{_mandir}/man8/*
%changelog

