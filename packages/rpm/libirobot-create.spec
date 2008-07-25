Name: libirobot-create
Summary: iRobot Create communication library.
Vendor: iLab
Version: 0.1
Release: 1
License: GPL
URL: http://ilab.usc.edu/%{name}
Group: Development/Tools
Source: %{name}-%{version}.tar.gz
BuildRoot: /var/tmp/%{name}-%{version}-%{release}-buildroot
Prefix: /usr

%description
The iRobot Create library allows user to easily communicate with the iRobot
Create robot. It implements the Open Interface protocol version 2.

%prep
%setup -q

%configure --docdir=%{_datadir}/doc/%{name}-%{version}
%build
make

%install
rm -rf $RPM_BUILD_ROOT
make DESTDIR=$RPM_BUILD_ROOT install

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root,-)
%{_bindir}/irobot-create-ctl
%{_includedir}/irobot-create.hh
%{_includedir}/irobot-create-fwd.hh
%{_libdir}/libirobot-create.*
%{_datadir}/doc/%{name}-%{version}/*

%changelog
