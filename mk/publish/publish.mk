
######################################################################
### publish (PUBLIC)
######################################################################
### publish will upload the newly built package and any dependencies
### that were built and don't already exist on the remote repository
###
.PHONY: publish publish-old publish-s3 sync-s3 sync-old download
publish: sync-old-pkg-summary sync-s3-pkg-summary

publish-old: sync-old sync-old-pkg-summary
	@${PHASE_MSG} "Publishing ${PKGNAME} and any newly built dependencies"
	@../../mk/publish/publish.sh

publish-s3: sync-s3 sync-s3-pkg-summary
	@${PHASE_MSG} "Publishing ${PKGNAME} and any newly built dependencies to s3"
	@../../mk/publish/publish-s3.sh

download:
	@${PHASE_MSG} "Downloading packages"
	@../../mk/publish/download.sh

sync-s3:
	@${PHASE_MSG} "Syncing packages with S3"
	@../../mk/publish/sync-s3.sh

sync-old:
	@${PHASE_MSG} "Syncing Packages with pkgsrc.nanobox.io"
	@../../mk/publish/sync.sh

sync-s3-pkg-summary: sync-s3 generate-pkg-summary
	@${PHASE_MSG} "Syncing pkg_summary with S3"
	@../../mk/publish/sync-pkg-summary-s3.sh

sync-old-pkg-summary: sync-old generate-pkg-summary
	@${PHASE_MSG} "Synching pkg_summary with pkgsrc.nanobox.io"
	@../../mk/publish/sync-pkg-summary.sh

generate-pkg-summary:
	@${PHASE_MSG} "Generating pkg_summary"
	@../../mk/publish/generate-pkg-summary.sh
