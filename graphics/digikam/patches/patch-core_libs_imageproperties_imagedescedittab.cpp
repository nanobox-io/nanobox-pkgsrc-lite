$NetBSD: patch-core_libs_imageproperties_imagedescedittab.cpp,v 1.1 2014/11/15 21:15:18 markd Exp $

commit f6945f23e0ed1e11f26e2c7e62b02baa8cfa640e
Author: Pino Toscano <pino@kde.org>
Date:   Tue Oct 14 22:26:19 2014 +0200

    fix libkexiv2 version for AltLangStrEdit::textEdit()
    
    it is part of current libkexiv2/master only (i.e. post 4.14.x, which
    is 2.3.x)

diff --git a/libs/imageproperties/imagedescedittab.cpp b/libs/imageproperties/imagedescedittab.cpp
index ebfbae1..3d12777 100644
--- core/libs/imageproperties/imagedescedittab.cpp
+++ core/libs/imageproperties/imagedescedittab.cpp
@@ -429,7 +429,7 @@ ImageDescEditTab::ImageDescEditTab(QWidget* const parent)
 
     // Initialize ---------------------------------------------
 
-#if KEXIV2_VERSION >= 0x020302
+#if KEXIV2_VERSION >= 0x020400
     d->titleEdit->textEdit()->installEventFilter(this);
     d->captionsEdit->textEdit()->installEventFilter(this);
 #endif
@@ -532,7 +532,7 @@ void ImageDescEditTab::setFocusToNewTagEdit()
 void ImageDescEditTab::setFocusToTitlesEdit()
 {
     d->tabWidget->setCurrentIndex(Private::DESCRIPTIONS);
-#if KEXIV2_VERSION >= 0x020302
+#if KEXIV2_VERSION >= 0x020400
     d->titleEdit->textEdit()->setFocus();
 #endif
 }
@@ -540,7 +540,7 @@ void ImageDescEditTab::setFocusToTitlesEdit()
 void ImageDescEditTab::setFocusToCommentsEdit()
 {
     d->tabWidget->setCurrentIndex(Private::DESCRIPTIONS);
-#if KEXIV2_VERSION >= 0x020302
+#if KEXIV2_VERSION >= 0x020400
     d->captionsEdit->textEdit()->setFocus();
 #endif
 }
