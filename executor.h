// SPDX-License-Identifier: GPL-3.0-or-later
/*
 * Copyright (c) 2020 SUSE LLC
 */

#define DBG(...)							\
{									\
	fprintf(stderr, "%s:%s:%i ", __FILE__ + SOURCE_PATH_SIZE,	\
		__func__, __LINE__);					\
	fprintf(stderr, ##__VA_ARGS__);					\
	fprintf(stderr, "\n");						\
}

enum buf_len {
	LEN_8 = 8,
	LEN_64 = 64,
	LEN_1024 = 1024
};

/* TODO: see tester_hear */
struct cmds {
	char tid[LEN_64];
	char cmds[LEN_1024];
};

struct log {
	size_t len;
	char buf[LEN_1024];
};

enum static_actor_addresses {
	ADDR_READER = 1,
	ADDR_WRITER = 2,
	ADDR_LOGGER = 3,
	ADDR_DRIVER = 4,
	ADDR_PLANNER = 5,
};

enum msg_type {
	MSG_PING,
	MSG_PONG,
	MSG_ALLC,
	MSG_CMDS,
	MSG_EXEC,
	MSG_LOGD,
	MSG_EXIT,
	MSG_TRES,
	MSG_DONE,
	MSG_ERRO,
};

void tester_start(struct actor *self, addr_t id);
void shutdown(struct actor *self)
	__attribute__((nonnull));

/* Convert between tester ID and actor addresses */
static inline addr_t addr_to_id(addr_t addr)
{
	return addr - 100;
}

static inline addr_t id_to_addr(addr_t id)
{
	return id + 100;
}
