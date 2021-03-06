
ARCH = linux-amd64

GCCBIN           = m68k-atari-mint-gcc
GCCOPT           = -Os -I . -I .. -I ../fat32 -DFATFS_IS_LITTLE_ENDIAN=0 -Wall
GCCOPT          += -m68000 -nostdlib -fno-builtin
GCLOPT           = $(GCCOPT) -Wl,-Map,symbols.map -Wl,--traditional-format

VASMBIN          = build-tools/vbcc/bin-$(ARCH)/vasmm68k_mot
VASMOPT          = -Faout -showopt -m68000 -spaces -quiet

# GCC : PRG size about 44054 bytes
C                = $(GCCBIN)
CFLAGS           = $(GCCOPT)

LFLAGS           = $(GCLOPT) -s    # STRIP SYMBOLS
#LFLAGS           = $(GCLOPT)  	    # KEEP SYMBOLS (debug)

EXEC             = HXCFEMNG.PRG

.PHONY: all clean push-mina push-gbo-dsi push-gbo-pc

all: AUTOBOOT.HFE

clean:
	rm -rf $(EXEC) *.o *.asm fat32/*.o fat32/*.asm libc/*.o libc/*.asm libc/snprintf/*.o symbols.map *.HFE
	$(MAKE) -C loader clean

AUTOBOOT.HFE: $(EXEC)
	$(MAKE) -C loader all
	mv loader/AUTOBOOT.HFE .

$(EXEC):        libc/mStartupAsmC.o libc/mStartup.o libc/snprintf/snprintf.o  fectrl.o errors_def.o menu.o menu_settings.o menu_selectdrive.o menu_commands.o gui_utils.o atari_st.o media_access.o config_file.o fat_access.o fat_filelib.o fat_misc.o fat_string.o fat_table.o fat_write.o fat_cache.o msg_txt.o
	$(C)          $(LFLAGS)          $^ -lc -o $@

atari_st.o:       atari_st.c
	$(C)          $(CFLAGS)        -c $< -o $@

gui_utils.o: ../gui_utils.c
	$(C)          $(CFLAGS)        -c $< -o $@

fectrl.o: ../fectrl.c
	$(C)          $(CFLAGS)        -c $< -o $@

errors_def.o: ../errors_def.c
	$(C)          $(CFLAGS)        -c $< -o $@

media_access.o: ../media_access.c
	$(C)          $(CFLAGS)        -c $< -o $@

config_file.o: ../config_file.c
	$(C)          $(CFLAGS)        -c $< -o $@

menu.o: ../menu.c
	$(C)          $(CFLAGS)        -c $< -o $@

menu_settings.o: ../menu_settings.c
	$(C)          $(CFLAGS)        -c $< -o $@

menu_selectdrive.o: ../menu_selectdrive.c
	$(C)          $(CFLAGS)        -c $< -o $@

menu_commands.o: ../menu_commands.c
	$(C)          $(CFLAGS)        -c $< -o $@

msg_txt.o: ../msg_txt.c
	$(C)          $(CFLAGS)        -c $< -o $@

fat_misc.o: ../fat32/fat_misc.c
	$(C)          $(CFLAGS)        -c $< -o $@

fat_filelib.o: ../fat32/fat_filelib.c
	$(C)          $(CFLAGS)        -c $< -o $@

fat_access.o: ../fat32/fat_access.c
	$(C)          $(CFLAGS)        -c $< -o $@

fat_string.o: ../fat32/fat_string.c
	$(C)          $(CFLAGS)        -c $< -o $@

fat_table.o: ../fat32/fat_table.c
	$(C)          $(CFLAGS)        -c $< -o $@

fat_write.o: ../fat32/fat_write.c
	$(C)          $(CFLAGS)        -c $< -o $@

fat_cache.o: ../fat32/fat_cache.c
	$(C)          $(CFLAGS)        -c $< -o $@

libc/mStartup.o: libc/mStartup.c
	$(C)          $(CFLAGS)        -c $< -o $@ -Wno-unused-value

libc/snprintf/snprintf.o: libc/snprintf/snprintf.c libc/snprintf/snprintf.h
	$(C)          $(CFLAGS)        -c $< -o $@

libc/mStartupAsmC.o: libc/mStartupAsmC.s
	$(VASMBIN)    $(VASMOPT)          $< -o $@
