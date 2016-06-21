$NetBSD$

--- Source/WebCore/rendering/shapes/BoxShape.cpp.orig	2016-01-29 16:29:33.000000000 +0000
+++ Source/WebCore/rendering/shapes/BoxShape.cpp
@@ -43,7 +43,7 @@ static inline LayoutUnit adjustRadiusFor
 
     LayoutUnit ratio = radius / margin;
     if (ratio < 1)
-        return radius + (margin * (1 + pow(ratio - 1, 3)));
+        return radius + (margin * (1 + pow(ratio - 1, 3.0)));
 
     return radius + margin;
 }
