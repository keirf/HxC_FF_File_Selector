void init_fdc(unsigned char drive);
int jumptotrack(unsigned char t);
unsigned char readsector(unsigned char sectornum,unsigned char * data,unsigned char invalidate_cache);
unsigned char writesector(unsigned char sectornum,unsigned char * data);

unsigned char Keyboard();
unsigned char wait_function_key();
void wait_released_key();

void reboot();

int init_display();
unsigned short get_vid_mode();
void setvideomode(int mode);
void disablemousepointer();

void init_timer();

#define L_INDIAN(var) (((var&0x000000FF)<<24) |((var&0x0000FF00)<<8) |((var&0x00FF0000)>>8) |((var&0xFF000000)>>24))