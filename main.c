#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "ginitcompiler.h"
#include "returnnewtext.h"

int debug_mode = 0;

int valid_command_error() {
    printf("Error: Please use a valid command. Here are the valid ginit commands:\n");
    printf("add  | Adds a new template\n");
    printf("pull | Pulls (copy pastes) a template into your current directory\n");
    printf("init | Runs your git file and initializes your repository\n");
    printf("version | Version of ginit");
}

int debug_print(char text[]) {
  if (debug_mode != 0) {
    printf("Debug: %s", text);
  }
}

int main(int argc, char *argv[]) {
    // Check for windows users
    #ifdef _WIN32
    #error "This program only works on Unix (Linux/MacOS). Support might be added later."
    #endif


    if (strcmp(argv[1], "version") == 0) {
        printf("0.7.0\n");
        return 0;
    } 

    if (argv[3] == NULL) {
    } else {
        if (strcmp(argv[3], "--debug") == 0) {
            debug_mode = 1;
            printf("Entered Debug Mode.\n");
        }
    }


    if (argc < 2) {
        valid_command_error();
        return 1;
    }

    FILE *f = fopen(argv[2], "r");
    if (f) {
        debug_print("File exists and is readable.\n");
        fclose(f);
    } else {
        printf("Error: File does not exist\n");
        return 1;
    }

    if (strcmp(argv[1], "add") == 0) {
        debug_print("Adding a template..\n"); 
        //User wants to add a new template
        char copypaste_command[100];
        snprintf(copypaste_command, sizeof(copypaste_command), "cp %s $HOME/.ginit/templates", argv[2]);
        system(copypaste_command);
    }
    else if (strcmp(argv[1], "pull") == 0) {
        debug_print("Pulling a template..");
        char pull_command[100];
        snprintf(pull_command, sizeof(pull_command), "cp $HOME/.ginit/templates/%s ./", argv[2]);
        system(pull_command);
    }
    else if (strcmp(argv[1], "remove") == 0) {
        // User wants to remove a template
        debug_print("Removing template..");
        char remove_command[100];
        snprintf(remove_command, sizeof(remove_command), "rm $HOME/.ginit/templates/%s", argv[2]);
        system(remove_command);
    }
    else if (strcmp(argv[1], "init") == 0) {
        debug_print("Initilializing repository..");
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

    else {
        valid_command_error();
    }
}
