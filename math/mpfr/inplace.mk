# $NetBSD: inplace.mk,v 1.4 2014/12/05 13:14:21 wiz Exp $
#
# Include this file to extract math/mpfr source into the WRKSRC of
# another package. This is to be used by GCC packages to avoid the
# numerous dependencies math/mpfr has.

.PHONY: fetch-inplace-mpfr extract-inplace-mpfr
post-fetch: fetch-inplace-mpfr

post-extract: extract-inplace-mpfr

fetch-inplace-mpfr:
	(cd ../../math/mpfr && ${MAKE} WRKDIR=${WRKSRC}/.devel.mpfr EXTRACT_DIR=${WRKSRC} \
		WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' SKIP_DEPENDS=YES checksum clean)

extract-inplace-mpfr:
	(cd ../../math/mpfr && ${MAKE} WRKDIR=${WRKSRC}/.devel.mpfr EXTRACT_DIR=${WRKSRC} \
		WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' SKIP_DEPENDS=YES MULTIARCH=NO patch clean)
	${MV} ${WRKSRC}/mpfr-* ${WRKSRC}/mpfr
