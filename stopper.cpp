#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

void AddNewEndSection(char * file){
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];

	time (&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer,sizeof(buffer),"%d-%m-%Y %I:%M:%S",timeinfo);


	FILE *OUTPUT_FILE;
	OUTPUT_FILE = fopen(file, "a+");
	fprintf(OUTPUT_FILE, "\n\n------------- end at %s-------------\n\n", buffer);
	fclose(OUTPUT_FILE);
}

int main(){
	char * file = logfile_decorated;
	char * file_raw = logfile_raw;
	AddNewEndSection(file);
	AddNewEndSection(file_raw);

	string s = "taskkill /F /IM "s + logger_executable;

	system(s.c_str());
}