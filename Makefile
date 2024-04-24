
all: sd64.z64
.PHONY: all

BUILD_DIR = build
include $(N64_INST)/include/n64.mk

OBJS = $(BUILD_DIR)/sd64.o

timers.z64: N64_ROM_TITLE = "Everdrive sd Test"

$(BUILD_DIR)/sd64.elf: $(OBJS)

clean:
	rm -rf $(BUILD_DIR) *.z64
.PHONY: clean

-include $(wildcard $(BUILD_DIR)/*.d))
