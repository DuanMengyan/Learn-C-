#pragma once

#ifndef MESSAGE_H
#define MESSAGE_H

#include "header_include.h"
#include "Folder.h"

using namespace std;

class Message
{
	friend class Folder;
	friend void swap(Message &, Message &);
public:
	
	explicit Message(const string &str = "") :contents(str) { };
	
	//拷贝构造函数
	Message(const Message&);

	//拷贝赋值运算符
	Message& operator= (const Message&);
	
	//析构函数
	~Message();

	//移动构造函数
	Message(Message &&m);

	//移动赋值运算符
	Message& operator=(Message &&m);


	//
	void save_to_Folder(Folder&);

	void remove_from_Folder(Folder&);

	//打印消息内容
	void print_m_contents();

	//打印包含当前消息的文件夹
	void print_folders();

private:
	string contents;				//实际消息文本
	set<Folder*> folders;			//包含本Message的Folder

	//拷贝构造函数、拷贝赋值运算符和析构函数所使用的工具函数
	
	//将本Message添加到指向参数的Folder中
	void save_to_Folders(const Message&);
	//从folders中的每个Folder中删除本Message
	void remove_from_Folders();

	//移动构造函数和移动赋值运算符所使用的工具函数
	//从本Message移动Folder指针
	void move_Folders(Message *m);



};


#endif // !MESSAGE_H
