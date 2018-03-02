# name of source files
source_start=logger.cpp
source_end=stopper.cpp

# name of the executables
start_logger=start_logger
stop_logger=stop_logger

# log file names
log_file_decorated=LOG.txt
log_file_raw=LOG_raw.txt

# definitions to pass
definitions=\
 -Dlogfile_decorated=\"$(log_file_decorated)\"\
 -Dlogfile_raw=\"$(log_file_raw)\"\
 -Dlogger_executable=\"$(start_logger).exe\"


all: $(start_logger) $(stop_logger)

$(start_logger): $(source_start)
	g++ $(source_start) -o $(start_logger) $(definitions)

$(stop_logger): $(source_end)
	g++ $(source_end) -o $(stop_logger) $(definitions)

clean-all: clean clean-logs

clean:
	rm -rf $(start_logger).exe* $(stop_logger).exe*

clean-logs:
	rm -rf $(log_file_decorated) $(log_file_raw)