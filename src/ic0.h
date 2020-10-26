#include <stdint.h>

#define WASM_IMPORT(module, name) \
	__attribute__((import_module(module))) \
	__attribute__((import_name(name)));

#define WASM_EXPORT(name) asm(name) \
	__attribute__((visibility("default")));

void ic0_debug_print(uint32_t src, uint32_t size) \
	WASM_IMPORT("ic0", "debug_print");

void ic0_msg_reply() \
	WASM_IMPORT("ic0", "msg_reply");

void ic0_msg_reply_data_append(uint32_t src, uint32_t size) \
	WASM_IMPORT("ic0", "msg_reply_data_append");

void ic0_trap(uint32_t src, uint32_t size) \
	WASM_IMPORT("ic0", "trap");
