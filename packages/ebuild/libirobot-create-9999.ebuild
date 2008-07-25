# Copyright 1999-2008 Gentoo Foundation
# Distributed under the terms of the GNU General Public License v2
# $Header: $

inherit subversion

ESVN_REPO_URI="svn://ilab.usc.edu:3692/tool/irobot-create/trunk/"

DESCRIPTION="iRobot Create communication library."
HOMEPAGE="http://ilab.usc.edu/libirobot-create/"
SRC_URI=""

LICENSE="GPL-3"
SLOT="0"
KEYWORDS="~x86"

DEPEND=""
RDEPEND="${DEPEND}"

src_compile() {
        test -x "./bootstrap" && ./bootstrap || die "bootstrap failed"
        econf $(use_with ice) || die "econf failed"
	emake FLAGS="${CFLAGS}" || die "compile failed"
}

src_install() {
        emake DESTDIR="${D}" install || die "make install failed"
}
