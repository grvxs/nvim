#ifndef NVELOX_H
#define NVELOX_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

void nv_set_option(const char* name,
                   const char* string,
                   long num,
                   int optflags);

void nv_do_autocmd(const char* event,
                   const char* pattern,
                   const char* command,
                   bool once,
                   int nested,
                   int forceit,
                   int group);

void nv_do_augroup(const char* name, int forceit);

void
nv_set_keymap (const char *mode, const char *key, const char *value, bool noremap, bool forceit);

void
nv_do_highlight (const char *cmd, bool forceit);

// Shorthand for unsigned variables. Many systems, but not all, have u_char
// already defined, so we use char_u to avoid trouble.
typedef unsigned char char_u;

typedef struct {
    char* data;
    size_t size;
} String;

/// Writes a message to the Vim error buffer. Does not append "\n", the
/// message is buffered (won't display) until a linefeed is written.
///
/// @param str Message
extern void nvim_err_write(String str);

#define OPT_BOTH 0
#define OPT_GLOBAL 2
#define OPT_LOCAL 4

// values for cmd_addr_type
typedef enum {
    ADDR_LINES,           // buffer line numbers
    ADDR_WINDOWS,         // window number
    ADDR_ARGUMENTS,       // argument number
    ADDR_LOADED_BUFFERS,  // buffer number of loaded buffer
    ADDR_BUFFERS,         // buffer number
    ADDR_TABS,            // tab page number
    ADDR_TABS_RELATIVE,   // Tab page that only relative
    ADDR_QUICKFIX_VALID,  // quickfix list valid entry number
    ADDR_QUICKFIX,        // quickfix list entry number
    ADDR_UNSIGNED,        // positive count or zero, defaults to 1
    ADDR_OTHER,           // something else, use line number for '$', '%', etc.
    ADDR_NONE             // no range used
} cmd_addr_T;

#define EX_RANGE 0x001   // allow a linespecs
#define EX_BANG 0x002    // allow a ! after the command name
#define EX_EXTRA 0x004   // allow extra args after command name
#define EX_XFILE 0x008   // expand wildcards in extra part
#define EX_NOSPC 0x010   // no spaces allowed in the extra part
#define EX_DFLALL 0x020  // default file range is 1,$
#define EX_WHOLEFOLD \
    0x040                  // extend range to include whole fold also
                           // when less than two numbers given
#define EX_NEEDARG 0x080   // argument required
#define EX_TRLBAR 0x100    // check for trailing vertical bar
#define EX_REGSTR 0x200    // allow "x for register designation
#define EX_COUNT 0x400     // allow count in argument, after command
#define EX_NOTRLCOM 0x800  // no trailing comment allowed
#define EX_ZEROR 0x1000    // zero line number allowed
#define EX_CTRLV 0x2000    // do not remove CTRL-V from argument
#define EX_CMDARG 0x4000   // allow "+command" argument
#define EX_BUFNAME 0x8000  // accepts buffer name
#define EX_BUFUNL 0x10000  // accepts unlisted buffer too
#define EX_ARGOPT 0x20000  // allow "++opt=val" argument
#define EX_SBOXOK 0x40000  // allowed in the sandbox
#define EX_CMDWIN \
    0x80000                 // allowed in cmdline window; when missing
                            // disallows editing another buffer when
                            // current buffer is locked
#define EX_MODIFY 0x100000  // forbidden in non-'modifiable' buffer
#define EX_FLAGS 0x200000   // allow flags after count in argument
#define EX_FILES (EX_XFILE | EX_EXTRA)  // multiple extra files allowed
#define EX_FILE1 (EX_FILES | EX_NOSPC)  // 1 file, defaults to current file
#define EX_WORD1 (EX_EXTRA | EX_NOSPC)  // one extra word allowed

int uc_add_command(char_u* name,
                   size_t name_len,
                   char_u* rep,
                   uint32_t argt,
                   long def,
                   int flags,
                   int compl,
                   char_u* compl_arg,
                   cmd_addr_T addr_type,
                   bool force);

#endif  // NVELOX_H
