#ifndef tranDuongGiaBao_h
#define tranDuongGiaBao_h

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include <windows.h>
#include <ctype.h>



struct date
{
	int ngay;
	int thang;
	int nam;
	int gio;
	int phut;
};

struct xe
{
	char MX[11];
	char BSX[21];
	char LX[31];
	char TenChuXe[51];
	int giaGui;
	int veXemPhim;
	date gioVao;
	date gioRa;
};

typedef xe Itemtype;

struct nhanVien{
	char maNV[11];
	char tenNV[21];
	char chucVu[31];
	char matKhau[21];
};

typedef nhanVien NV;

struct SNode
{
	Itemtype Info;
	SNode* Next;
};

struct SList
{
	SNode* Head;
	SNode* Tail;
};

struct SNodeNV
{
	NV Info;
	SNodeNV* Next;
};

struct SListNV
{
	SNodeNV* Head;
	SNodeNV* Tail;
};

struct StackNode
{
	Itemtype Info;
	StackNode* Next;
};

struct Stack
{
	StackNode* Top;
};

void initSList(SList& sl);

int isEmpty(SList sl);

void initSListNV(SListNV& dsnv);

int isEmpty(SListNV dsnv);

int insertHead(SList& sl, SNode* p);

int insertTail(SList& sl, SNode* p);

int insertTailNV(SListNV& sl, SNodeNV* p);

int deleteHead(SList& sl, Itemtype& x);

int deleteTail(SList& sl, Itemtype& x);

int deleteBefore(SList& sl, Itemtype& x, SNode* q);

int deleteAfter(SList& sl, Itemtype& x, SNode* q);

SNode* createSNode(Itemtype x);

SNodeNV* createSNodeNV(NV x);

void swap(Itemtype& a, Itemtype& b);

void timeAuto(int *hour, int *minute, int *day, int *month, int *year);

int namNhuan(int nam);

int soNgayTrongThang(int thang, int nam);

int countAllXeTrongBai(SList sl);

int countXeTheoLoai(SList sl, char *loaiXe);

int countLoaiXeNhieuNhatTrongBai(SList sl);

StackNode* createStackNode(Itemtype x);

void initStack(Stack& st);

int isEmptyStack(Stack st);

int PUSH(Stack& st, StackNode* p);

int POP(Stack& st, Itemtype& x);

void getTop(Stack st);

int demNV(SListNV dsnv);

int saveTTNV(SListNV& dsnv, char FILENAME[]);

void nhapTTNV(nhanVien &x);

void xuatTTNV(NV x);

void showDSNV(SListNV dsnv);

void loadTTNV(FILE* fi, NV &x);

void createSListDSNV_FromTextFile(SListNV& dsnv, char inputFilename[]);

SNodeNV* findSNode_TheoMSNV(SListNV dsnv, NV nv);

void showTTNVTheoMa(SListNV dsnv, NV x);

int deleteHeadNV(SListNV& sl, NV& x);

int deleteAfterNV(SListNV& dsnv, SNodeNV* q, NV& x);

int deleteTailNV(SListNV& nv, NV& x);

int deleteNhanVienTheoMa(SListNV& dsnv, NV& nv);

#endif