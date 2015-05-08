# $NetBSD: buildlink3.mk,v 1.12 2013/04/24 04:32:34 sbd Exp $

BUILDLINK_TREE+=	gle

.if !defined(GLE_BUILDLINK3_MK)
GLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gle+=		gle>=3.0.3
BUILDLINK_ABI_DEPENDS.gle+=	gle>=3.1.0nb2
BUILDLINK_PKGSRCDIR.gle?=	../../graphics/gle

# GLUT is used only by the examples, which aren't built or installed.
#.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.endif # GLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-gle
