#include"types.h"
void i2c_start(void);
void i2c_stop(void);
void i2c_restart(void);
void i2c_byte_write(u8 );
u8 i2c_byte_read(void);
void slave_ack(void);
void master_noack(void);
void master_ack(void);