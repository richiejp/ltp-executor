// SPDX-License-Identifier: GPL-3.0-or-later
/*
 * Copyright (c) 2020 SUSE LLC
 */

void parser_init(void);
void parser_feed(struct actor *self, char *str, size_t len);
