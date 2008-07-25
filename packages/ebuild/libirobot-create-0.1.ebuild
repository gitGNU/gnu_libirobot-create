# Copyright 1999-2008 Gentoo Foundation
# Distributed under the terms of the GNU General Public License v2
# $Header: $

inherit eutils base

DESCRIPTION="iRobot Create communication library."
HOMEPAGE="http://ilab.usc.edu/libirobot-create/"
SRC_URI="http://ilab.usc.edu/packages/gentoo/${P}.tar.gz"

LICENSE="GPL-3"
SLOT="0"
KEYWORDS="~x86"
IUSE=""

src_compile() {
        econf || die "econf failed"
	emake FLAGS="${CFLAGS}" || die "compile problem"
}

src_install() {
        emake DESTDIR="${D}" install || die "make install failed"
}
