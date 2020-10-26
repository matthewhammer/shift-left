#include <malloc.h>
#include <stdint.h>
#include <tommath.h>

#include "ic0.h"
#include "main.h"
#include "util.h"

void test() {

	mp_int * n = (mp_int *)(malloc(sizeof(mp_int)));
	if (n == NULL) {
		trap("Out of memory!");
	}

	mp_okay_or_trap(mp_init_u32(n, 1));
	mp_okay_or_trap(mp_lshd(n, 1));
	mp_print(n);
	mp_clear(n); 

	free(n);

	uint8_t data[6] = {0x44, 0x49, 0x44, 0x4C, 0x00, 0x00};
	ic0_msg_reply_data_append((uint32_t)(data), 6);
	ic0_msg_reply();
}
