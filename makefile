all:
	-@mkdir lib
	$(MAKE) -C embUnit
	$(MAKE) -C tests
	$(MAKE) -C samples
	$(MAKE) -C tools

lib:
	-@mkdir lib
	$(MAKE) -C embUnit

test:
	$(MAKE) -C tests
	@./tests/embUnitTest

samples:
	-@./samples/samples

clean:
	-@cd ./embUnit		;$(MAKE) clean
	-@cd ./tests		;$(MAKE) clean
	-@cd ./samples		;$(MAKE) clean
	-@cd ./tools		;$(MAKE) clean

.PHONY: clean samples test all
