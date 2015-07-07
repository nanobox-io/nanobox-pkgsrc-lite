
######################################################################
### publish (PUBLIC)
######################################################################
### publish will upload the newly built package and any dependencies
### that were built and don't already exist on the remote repository
###
.PHONY: publish
publish:
	@${PHASE_MSG} "Publishing ${PKGNAME} and any newly built dependencies"
	@../../mk/publish/publish.sh