# $NetBSD: Makefile,v 1.1 2017/09/17 15:59:30 wiz Exp $

DISTNAME=	Email-Address-XS-1.00
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Email-Address-XS/
COMMENT=	Parse and format RFC 2822 email addresses and groups
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST= auto/Email/Address/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
