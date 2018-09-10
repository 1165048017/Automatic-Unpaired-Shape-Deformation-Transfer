#include "fileSystemUtility.h"

#include <io.h>
#include <string>
#include <vector>
#include <iostream>
#include<algorithm>  

#include <windows.h>
#include <tchar.h>

#include <strsafe.h>


void FileSystemUtility::getAllFileRec(const std::string & path, const std::string & exd, std::vector<std::string> & files)
{
	_finddata_t fileinfo;//�ļ���Ϣ
	std::string p = path + "*" + exd;

	intptr_t hFile = _findfirst(p.c_str(), &fileinfo);//�ļ����
	if (hFile == -1L)
	{
		//LOG_ERROR << "can not match the folder path : " << path;
		std::cout << "can not match the folder path : " << path;
		return;
	}
	do
	{
		if (fileinfo.attrib & _A_SUBDIR) //������ҵ������ļ���
		{
			if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
			{
				//files.push_back(p.assign(path).append("\\").append(fileinfo.name) );
				getAllFile(p.assign(path).append("").append(fileinfo.name), exd, files);
			}
		}
		else
		{//������ҵ��Ĳ������ļ���
			files.push_back(p.assign(fileinfo.name));//���ļ�·�����棬Ҳ����ֻ�����ļ���:  p.assign(path).append("\\").append(fileinfo.name)  
		}
	} while (_findnext(hFile, &fileinfo) == 0);
	_findclose(hFile);
}

void FileSystemUtility::getAllFile(std::string path, std::string exd, std::vector<std::string> & files)
{
	_finddata_t fileinfo;//�ļ���Ϣ
	std::string p = path + "*" + exd;

	intptr_t hFile = _findfirst(p.c_str(), &fileinfo);//�ļ����
	if (hFile == -1L)
	{
		//LOG_ERROR << "can not match the folder path" << path;
		std::cout << "can not match the folder path" << path;
		return;
	}
	do
	{
		if (fileinfo.attrib & _A_SUBDIR) //������ҵ������ļ���
		{
			//if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
			//{
			//	//files.push_back(p.assign(path).append("\\").append(fileinfo.name) );
			//	getAllFile(p.assign(path).append("").append(fileinfo.name), exd, files);
			//}
		}
		else
		{//������ҵ��Ĳ������ļ���
			files.push_back(p.assign(fileinfo.name));//���ļ�·�����棬Ҳ����ֻ�����ļ���:  p.assign(path).append("\\").append(fileinfo.name)  
		}
	} while (_findnext(hFile, &fileinfo) == 0);
	_findclose(hFile);
}

std::string& FileSystemUtility::yj_replace_all_distinct(std::string& str, const std::string& old_value, const std::string& new_value)
{
	for (std::string::size_type pos(0); pos != std::string::npos; pos += new_value.length())
	{
		if ((pos = str.find(old_value, pos)) != std::string::npos)
			str.replace(pos, old_value.length(), new_value);
		else break;
	}
	return str;
}

bool cmp(std::string const &arg_a, std::string const &arg_b)
{
	return arg_a.size() < arg_b.size() || (arg_a.size() == arg_b.size() && arg_a < arg_b);
}

void FileSystemUtility::sortFileName(std::vector<std::string> & fileList)
{
	//std::cout << "��С����\n";
	std::sort(fileList.begin(), fileList.end());
	//for (int i = 0; i != fileList.size(); ++i) 
	//	std::cout << fileList[i] << "\n";
	//std::cout << "����+��С����\n";
	std::sort(fileList.begin(), fileList.end(), cmp);
	//for (int i = 0; i != fileList.size(); ++i) 
	//	std::cout << fileList[i] << "\n";
}
