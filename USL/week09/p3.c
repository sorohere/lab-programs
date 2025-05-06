#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <syslog.h>
#include <unistd.h>
#include <fcntl.h>

void create_daemon() {
    pid_t pid = fork();
    
    if (pid < 0) {
        // Fork failed
        exit(EXIT_FAILURE);
    }
    
    if (pid > 0) {
        // Parent process exits
        exit(EXIT_SUCCESS);
    }
    
    // Create a new session and set process group
    if (setsid() < 0) {
        exit(EXIT_FAILURE);
    }
    
    // Set file mode creation mask to 0
    umask(0);
    
    // Change the working directory to root
    if (chdir("/") < 0) {
        exit(EXIT_FAILURE);
    }
    
    // Redirect standard file descriptors to /dev/null
    open("/dev/null", O_RDONLY);  // stdin
    open("/dev/null", O_WRONLY);  // stdout
    open("/dev/null", O_RDWR);    // stderr
    
    // Close the file descriptors
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}

int main() {
    // Create the daemon process
    create_daemon();
    
    // Open syslog for logging
    openlog("daemon_ex", LOG_PID, LOG_DAEMON);
    
    // Main loop of the daemon
    while (1) {
        syslog(LOG_NOTICE, "Daemon is running...\n");
        sleep(30);  // Sleep for 30 seconds before logging again
    }
    
    // Close the syslog
    closelog();
    
    return EXIT_SUCCESS;
}

// ps aux (question mark depicts a daemon process)
// tail -f /var/log/syslog (optional to print log statement) 
