GENDATE=140219_2321
DEBUG_DIR=/tmp/cmake_w/Debug
RELEASE_DIR=/tmp/cmake_w/Release

main: release debug
 
release: check
	@ cd $(RELEASE_DIR); make -s 
	
verbose_release: check
	@ cd $(RELEASE_DIR); make VERBOSE=1
 
debug: check
	@ cd $(DEBUG_DIR); make -s 
	 
.PHONY: clean
clean:
	@ cd $(RELEASE_DIR); make -s clean
	@ cd $(DEBUG_DIR); make -s clean
check:
	@ [ -d $(RELEASE_DIR) ] || ./configure
	
