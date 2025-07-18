#!/usr/bin/env python3

import os
import subprocess
import time
import fnmatch
from threading import Thread

class SystemEventMonitor:
    def __init__(self, log_file='/var/log/system_events.log'):
        """
        Initialize the system event monitor with comprehensive path coverage
        
        :param log_file: Path to log file for recording events (will be excluded from monitoring)
        """
        # Comprehensive list of paths to monitor
        self.watch_paths = [
            '/',  # Root directory - comprehensive monitoring
        ]
        
        # Exclusion patterns to prevent monitoring of log file and unnecessary paths
        self.exclusion_patterns = [
            log_file, # Explicitly exclude the log file# Exclude cache directories
        ]
        
        self.log_file = log_file
        self.monitoring_threads = []

    def _should_ignore_path(self, path):
        """
        Check if a path should be ignored based on exclusion patterns
        
        :param path: Path to check
        :return: Boolean indicating whether path should be ignored
        """
        for pattern in self.exclusion_patterns:
            if fnmatch.fnmatch(path, pattern):
                return True
        return False

    def _log_event(self, event_type, path):
        """
        Log system events to a file
        
        :param event_type: Type of event (create, modify, delete)
        :param path: Path where event occurred
        """
        # Ignore logging if the path is in exclusion patterns
        if self._should_ignore_path(path):
            return
        
        timestamp = time.strftime("%Y-%m-%d %H:%M:%S")
        try:
            with open(self.log_file, 'a') as log:
                log.write(f"{timestamp} - {event_type}: {path}\n")
        except Exception as e:
            print(f"Error logging event: {e}")
        
        # Console output for real-time monitoring
        print(f"Event detected: {event_type} at {path}")

    def monitor_path(self, path):
        """
        Monitor a specific path using inotifywait
        
        :param path: Path to monitor
        """
        try:
            # Comprehensive event types to monitor
            events = 'create,modify,delete,move,attrib'
            
            # Construct inotifywait command with exclusions
            exclusion_args = ' '.join([f"--exclude '{pattern}'" for pattern in self.exclusion_patterns])
            cmd = f"inotifywait -m -r -e {events} {exclusion_args} {path}"
            
            process = subprocess.Popen(
                cmd, 
                shell=True, 
                stdout=subprocess.PIPE, 
                stderr=subprocess.PIPE,
                universal_newlines=True
            )
            
            while True:
                line = process.stdout.readline().strip()
                if line:
                    # Parse inotify output
                    parts = line.split()
                    if len(parts) < 3:
                        continue
                    
                    watched_dir = parts[0].rstrip(':')
                    event_type = parts[1]
                    file_path = ' '.join(parts[2:]) if len(parts) > 2 else ''
                    
                    full_path = os.path.join(watched_dir, file_path)
                    
                    # Additional path filtering
                    if not self._should_ignore_path(full_path):
                        self._log_event(event_type, full_path)
        
        except Exception as e:
            print(f"Error monitoring {path}: {e}")

    def start_monitoring(self):
        """
        Start monitoring all specified paths
        """
        for path in self.watch_paths:
            if not os.path.exists(path):
                print(f"Warning: Path {path} does not exist. Skipping.")
                continue
            
            thread = Thread(target=self.monitor_path, args=(path,))
            thread.daemon = True
            thread.start()
            self.monitoring_threads.append(thread)

    def stop_monitoring(self):
        """
        Stop all monitoring threads
        """
        for thread in self.monitoring_threads:
            thread.join(timeout=1)

def main():
    # Initialize and start monitoring
    monitor = SystemEventMonitor()
    monitor.start_monitoring()
    
    try:
        # Keep main thread running
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        print("\nStopping event monitoring...")
        monitor.stop_monitoring()

if __name__ == "__main__":
    main()