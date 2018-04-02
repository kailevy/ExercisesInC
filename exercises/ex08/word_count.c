#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <glib.h>
#include <glib/gstdio.h>

#define BUFLEN 160
#define MAXWORD 40

void print_pair(const char *key, const int val);

int main(int argc, char *argv[]) {
    GError *error = NULL;
    char *token;
    gint count;
    GIOChannel *f = g_io_channel_new_file(argv[1], "r", &error);
    GString *buffer = g_string_new_len(" ", BUFLEN);
    GString *wordbuf = g_string_new_len(" ", MAXWORD);
    GHashTable *table = g_hash_table_new(g_str_hash, g_str_equal);
    while (g_io_channel_read_line_string(f, buffer, NULL, &error) == G_IO_STATUS_NORMAL) {
        char *p = buffer->str;
        token = strtok(p, " ");
        while (token != NULL) {
            // g_string_assign(wordbuf, token);
            if (g_hash_table_lookup(table, token) != NULL) {
                // Word is in table, increment it
                count = GPOINTER_TO_INT(g_hash_table_lookup(table, token));
                printf("%d\n", count);
                g_hash_table_replace(table, g_strdup(token), GINT_TO_POINTER(count+1));
            } else {
                // Word not yet in table
                g_hash_table_insert(table, g_strdup(token), GINT_TO_POINTER(1));
            }   
            token = strtok(NULL, " ");
        }
    }
    g_hash_table_foreach(table, (GHFunc) print_pair, NULL);
}

void print_pair(const char *key, const int val) {
    g_print ("%d \t \t %s\n", val, key);
}