#include<bits/stdc++.h>
using namespace std;

class CMyFile{
private:
	char ch;
	char *chStr;
	const char *filePath;
	FILE *file;
	int size;

public:
	bool openFile(const char *pathFile){                     
		file = fopen(pathFile, "t");
		if (file == NULL)
			return false;
		return true;
	}

	bool openFile(const char *pathFile, const char *way){   //打开文件，读写
		file = fopen(pathFile, way);
		if (file == NULL)
			return false;
		return true;
	}

	bool closeFile(){                                      //关闭文件
		if (EOF == fclose(file))
			return false;
		return true;
	}

	char readCharFromFile(){                              //从文件读取字符
		ch = fgetc(file);
		if (EOF == ch)
			return ' ';
		return ch;
	}

	bool writeCharToFile(char ch){                       //写字符到文件
		if (EOF == fputc(ch, file))
			return false;
		return true;
	}

	char *readStrFromFile(int n){                        //读字符串

		fgets(chStr, n + 1, file);
		return chStr;
	}

	bool writeStringToFile(const char *s){              //写字符串到文件
		if (EOF == fputs(s, file))
			return false;
		return true;
	}

	int sizeOfFile(){                                  //打开文件， 统计字数
		fseek(file, 0, SEEK_END);
		size = ftell(file);
		return size;
	}
};

int main()
{
	CMyFile file;
	file.openFile("F:\\aaa.txt", "a+");
	file.writeCharToFile('c');
	file.writeStringToFile("fsfgerger");
	printf("%d\n", file.sizeOfFile());
	file.closeFile();
}
