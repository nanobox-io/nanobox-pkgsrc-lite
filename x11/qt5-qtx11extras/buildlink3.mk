# $NetBSD: buildlink3.mk,v 1.15 2017/02/12 06:24:59 ryoon Exp $

BUILDLINK_TREE+=	qt5-qtx11extras

.if !defined(QT5_QTX11EXTRAS_BUILDLINK3_MK)
QT5_QTX11EXTRAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtx11extras+=	qt5-qtx11extras>=5.5.1
BUILDLINK_ABI_DEPENDS.qt5-qtx11extras+=	qt5-qtx11extras>=5.5.1nb6
BUILDLINK_PKGSRCDIR.qt5-qtx11extras?=	../../x11/qt5-qtx11extras

BUILDLINK_INCDIRS.qt5-qtx11extras+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qtx11extras+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qtx11extras+=	qt5/plugins

.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.endif	# QT5_QTX11EXTRAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtx11extras
