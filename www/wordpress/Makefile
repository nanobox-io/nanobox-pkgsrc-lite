# $NetBSD: Makefile,v 1.72 2017/09/21 19:24:46 morr Exp $

DISTNAME=		wordpress-${VERSION}
VERSION=		4.8.2
CATEGORIES=		www
MASTER_SITES=		https://wordpress.org/

MAINTAINER=		morr@NetBSD.org
HOMEPAGE=		https://wordpress.org/
COMMENT=		Blogging tool written in php
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		pax

.include "../../mk/bsd.prefs.mk"
.include "../../lang/php/phpversion.mk"
.include "options.mk"

NO_BUILD=		yes
WRKSRC=			${WRKDIR}/wordpress

WWW_USER?=		${APACHE_USER}
WWW_GROUP?=		${APACHE_GROUP}

PKG_GROUPS_VARS=	WWW_GROUP
PKG_USERS_VARS=		WWW_USER
BUILD_DEFS+=		WWW_USER WWW_GROUP APACHE_USER APACHE_GROUP
EGDIR=			${PREFIX}/share/examples/wordpress
DOCDIR=			${PREFIX}/share/doc/wordpress
WPHOME=			${PREFIX}/share/wordpress
FILES_SUBST+=		WPHOME=${WPHOME}
MESSAGE_SUBST+=		DOCDIR=${DOCDIR}

CONF_FILES+=		${EGDIR}/wordpress.conf ${PKG_SYSCONFDIR}/wordpress.conf
OWN_DIRS_PERMS+=	${WPHOME}/wp-content/uploads \
			${WWW_USER} ${WWW_GROUP} 0750

INSTALLATION_DIRS+=	${DOCDIR} ${WPHOME} ${EGDIR}

DEPENDS+=		${PHP_PKG_PREFIX}-mysqli>=5.6.0:../../databases/php-mysqli
DEPENDS+=		${PHP_PKG_PREFIX}-gd>=5.6.0:../../graphics/php-gd
DEPENDS+=		${PHP_PKG_PREFIX}-curl>=5.6.0:../../www/php-curl
DEPENDS+=		${PHP_PKG_PREFIX}-zip>=5.6.0:../../archivers/php-zip
DEPENDS+=		${PHP_PKG_PREFIX}-zlib>=5.6.0:../../archivers/php-zlib

SUBST_CLASSES+=		conf
SUBST_MESSAGE.conf=	Fixing pathnames in configuration file.
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	../wordpress.conf
SUBST_SED.conf=		-e "s,@WPHOME@,${WPHOME},g"
.if !empty(PKG_OPTIONS:Map-php) && ${PKG_APACHE} == "apache24"
SUBST_SED.conf+=	-e "/Order allow,deny/d"
SUBST_SED.conf+=	-e "s,Allow from all,Require all granted,g"
.endif

post-extract:
	${CP} ${FILESDIR}/wordpress.conf ${WRKDIR}/wordpress.conf

do-install:
	${INSTALL_DATA} ${WRKSRC}/readme.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/license.txt ${DESTDIR}${DOCDIR}

#	${INSTALL_DATA} ${WRKSRC}/wp-config-sample.php ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/wordpress.conf ${DESTDIR}${EGDIR}

	${RM} ${WRKSRC}/readme.html
	${RM} ${WRKSRC}/license.txt
#	${RM} ${WRKSRC}/wp-config-sample.php

	cd ${WRKSRC} && pax -rw -pmp . ${DESTDIR}${WPHOME}
	${TOUCH} ${DESTDIR}${WPHOME}/wp-content/plugins/index.html
	${FIND} ${DESTDIR}${WPHOME} \
		-type d -exec ${CHMOD} ${PKGDIRMODE} "{}" \;
	${FIND} ${DESTDIR}${WPHOME} \
		-type f -exec ${CHMOD} ${SHAREMODE} "{}" \;

.include "../../mk/bsd.pkg.mk"
