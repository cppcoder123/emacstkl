#
#
#

TARGET=keymap-info.h
SOURCE=keymap.awk

all:
	make $(TARGET)

$(TARGET): $(SOURCE)
	awk -f $< > $@

clean:
	rm $(TARGET)
