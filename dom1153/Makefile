.PHONY: all
all: clean build

.PHONY: clean
clean:
	rm -f result

.PHONY: flash
flash:
	qmk flash -kb keebio/nyquist/rev3 -km dom1153

.PHONY: build
build:
	qmk compile -kb keebio/nyquist/rev3 -km dom1153 --compiledb
