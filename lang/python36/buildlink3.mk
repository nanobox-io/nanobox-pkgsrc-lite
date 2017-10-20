# $NetBSD: buildlink3.mk,v 1.1 2017/01/01 14:34:27 adam Exp $

BUILDLINK_TREE+=	python

.if !defined(PYTHON_BUILDLINK3_MK)
PYTHON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.python+=		python>=3.6.0<3.7
BUILDLINK_PKGSRCDIR.python?=		../../base/python36

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python?=	${BUILDLINK_DEPMETHOD.python}
.endif

BUILDLINK_INCDIRS.python+=	include/python3.6
BUILDLINK_LIBDIRS.python+=	lib/python3.6/config
BUILDLINK_TRANSFORM+=		l:python:python3.6

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif # PYTHON_BUILDLINK3_MK

BUILDLINK_TREE+=	-python
