$NetBSD$

Support multiarch site-packages.

--- Lib/site.py.orig	2012-04-11 06:54:03.000000000 +0000
+++ Lib/site.py	2012-12-13 15:07:50.954286242 +0000
@@ -285,9 +285,13 @@
         if sys.platform in ('os2emx', 'riscos'):
             sitepackages.append(os.path.join(prefix, "Lib", "site-packages"))
         elif os.sep == '/':
+            if sys.maxsize > 2**32:
+                libarchsuffix = "@LIBARCHSUFFIX.64@".lstrip('/')
+            else:
+                libarchsuffix = "@LIBARCHSUFFIX.32@".lstrip('/')
             sitepackages.append(os.path.join(prefix, "lib",
                                         "python" + sys.version[:3],
-                                        "site-packages"))
+                                        "site-packages", libarchsuffix).rstrip('/'))
             sitepackages.append(os.path.join(prefix, "lib", "site-python"))
         else:
             sitepackages.append(prefix)
