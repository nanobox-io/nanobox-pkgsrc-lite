# $NetBSD: Makefile,v 1.25 2017/10/15 23:19:11 prlw1 Exp $

DISTNAME=	at-spi2-core-2.25.91
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/at-spi2-core/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://www.linuxfoundation.org/collaborate/workgroups/accessibility/atk/at-spi/at-spi_on_d-bus
COMMENT=	Assistive Technology Service Provider Interface Core
LICENSE=	gnu-lgpl-v2

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}

PKGCONFIG_OVERRIDE+=	atspi-2.pc.in

CHECK_PORTABILITY_SKIP+=	config/test-driver

BUILD_DEFS+=		VARBASE PKG_SYSCONFBASE

EGDIR=			${PREFIX}/share/examples/at-spi2-core
PKG_SYSCONFSUBDIR=	at-spi2
busconfigdir=		${PKG_SYSCONFDIR}
eg_busconfigdir=	${EGDIR}/at-spi2
default_sessiondir=	${PKG_SYSCONFBASE}/xdg/autostart
eg_default_sessiondir=	${EGDIR}/xdg/autostart

INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

SUBST_CLASSES+=		eg
SUBST_SED.eg+=		-e 's,defaults,examples/${PKGBASE},g'
SUBST_FILES.eg+=	bus/Makefile.in
SUBST_STAGE.eg= 	pre-configure
SUBST_MESSAGE.eg=	Fixing path to examples directory.

CONF_FILES=	${eg_busconfigdir}/accessibility.conf \
			${busconfigdir}/accessibility.conf
CONF_FILES+=	${eg_default_sessiondir}/at-spi-dbus-bus.desktop \
			${default_sessiondir}/at-spi-dbus-bus.desktop
MAKE_DIRS+=	${default_sessiondir}

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
