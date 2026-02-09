#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ginitcompiler.h"

int main(int argc, char *argv[]) {
    // Check for windows users
    #ifdef _WIN32
    #error "This program only works on Unix (Linux/MacOS). Support might be added later."
    #endif


    if (strcmp(argv[1], "add") == 0) {
        // User wants to add a new template
        char copypaste_command[100];
        snprintf(copypaste_command, sizeof(copypaste_command), "cp %s $HOME/.ginit/templates", argv[2]);
        system(copypaste_command);
    }
    if (strcmp(argv[1], "pull") == 0) {
        char pull_command[100];
        snprintf(pull_command, sizeof(pull_command), "cp $HOME/.ginit/templates/%s ./", argv[2]);
        system(pull_command);
    }
    if (strcmp(argv[1], "remove") == 0) {
        // User wants to remove a template
        char remove_command[100];
        snprintf(remove_command, sizeof(remove_command), "rm $HOME/.ginit/templates/%s", argv[2]);
        system(remove_command);
    }
    if (strcmp(argv[1], "init") == 0) {
        char expanded_dir[64];
        char *home = getenv("HOME");

        snprintf(expanded_dir, sizeof(expanded_dir), "%s/.ginit/initcache/output.sh", home);

        system("touch $HOME/.ginit/initcache/output.sh");
        compile_ginit(argv[2], expanded_dir);
        system("chmod +x $HOME/.ginit/initcache/output.sh");
        system("$HOME/.ginit/initcache/output.sh");
        system("rm -r $HOME/.ginit/initcache/output.sh");

        //int rename_command[64];
        //snprintf(rename_command, sizeof(rename_command), "mv ")
    }
}