enum buf_len {
	LEN_64 = 64,
	LEN_1024 = 1024
};

/* TODO: see tester_hear */
struct cmds {
	char tid[LEN_64];
	char cmds[LEN_1024];
};

enum static_actor_addresses {
	ADDR_READER = 1,
	ADDR_WRITER = 2,
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
	MSG_ERRO
};

void tester_start(addr_t id);
void shutdown(struct actor *self);

/* Convert between tester ID and actor addresses */
inline addr_t addr_to_id(addr_t addr)
{
	return addr - 100;
}

inline addr_t id_to_addr(addr_t id)
{
	return id + 100;
}
