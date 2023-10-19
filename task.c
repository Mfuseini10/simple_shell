#include "farsh.h"

int far_num_builtins(void) {
    char *far_builtin_str[] = {"far_cd", "far_exit"};
    return (sizeof(far_builtin_str) / sizeof(char *));
}

int far_cd(char **far_args) {
    if (far_args[1] == NULL) {
        fprintf(stderr, "my_far_shell: expected argument for \"far_cd\"\n");
    } else {
        if (chdir(far_args[1]) != 0) {
            perror("my_far_shell");
        }
    }
    return 1;
}

int far_exit(char **far_args) {
    far_args = far_args;
    return 0;
}

int far_start_program(char **far_args) {
    pid_t far_pid;
    int far_status;
    far_pid = fork();
    if (far_pid == 0) {
        if (execvp(far_args[0], far_args) == -1) {
            perror("my_far_shell");
        }
        exit(EXIT_FAILURE);
    } else if (far_pid < 0) {
        perror("my_far_shell");
    } else {
        do {
            waitpid(far_pid, &far_status, WUNTRACED);
        } while (!WIFEXITED(far_status) && !WIFSIGNALED(far_status));
    }
    return 1;
}

int far_execute_command(char **far_args) {
    char *far_builtin_str[] = {"far_cd", "far_exit"};
    int (*far_builtin_func[])(char **) = {&far_cd, &far_exit};
    int i;
    if (far_args[0] == NULL) {
        return 1;
    }
    for (i = 0; i < far_num_builtins(); i++) {
        if (strcmp(far_args[0], far_builtin_str[i]) == 0) {
            return (*far_builtin_func[i])(far_args);
        }
    }
    return far_start_program(far_args);
}

